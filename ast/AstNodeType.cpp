//
// Created by 12206 on 2021/12/12.
//
#include <iostream>
#include <sstream>
#include "AstNodeType.h"
#include "NestEnv.hpp"
#include "ClassInfo.h"
#include "Function.h"
#include "StoneObject.h"
#include "NaiveFunction.h"
std::string IfStmt::toString() const noexcept {
    std::string ret;
    ret+="( if(" + condition()->toString()+")"+thenBlock()->toString();
    auto el = elseBlock();
    if(el){
        ret+=el->toString();
    }
    ret+=" )";
    return ret;
}

Object::ptr IfStmt::eval(Env &env) const {
    auto b = condition()->eval(env);
    if(b->check()){
        return thenBlock()->eval(env);
    }
    if(elseBlock()){
        return elseBlock()->eval(env);
    }
    return nullptr;
}

std::string WhileStmt::toString() const noexcept {
    std::string ret;
    ret+="( while (" + condition()->toString()+")"+body()->toString()+")";
    return ret;
}

Object::ptr WhileStmt::eval(Env &env) const {
    Object::ptr ret;
    while(condition()->eval(env)->check())ret = body()->eval(env);
    if(ret)return ret;
    return nullptr;
}

std::string BlockStmt::toString() const noexcept {
    std::string ret{"(block {"};
    for(auto c:mChildren){
        ret+=c->toString()+", ";
    }
    ret+="})";
    return ret;
}

Object::ptr BlockStmt::eval(Env &env) const {
    Object::ptr ret;
    for(auto e:mChildren)ret = e->eval(env);
    return ret;
}


bool PrimaryExpr::hasPostFix(int nest) const {
    return numChild() - nest > 1;
}

//nest 倒是第几个元素
Object::ptr PrimaryExpr::evalSub(Env &env, int nest) const {
    //如果存在前一个元素
    if(hasPostFix(nest)){
        //计算前一个元素的结果
        auto target= evalSub(env,nest+1);
        auto postfixPtr = std::dynamic_pointer_cast<const Postfix>(postFix(nest));
        //将前一个元素计算的结果作为这次运算的输入进行计算
        /**
         *  a.get().b.c.d.e = 1
         *  开始时，nest = 0 进行dfs,直到nest = 6
         *  此时,没有前一个元素，则 a.eval(env) ，即从上下文里取出对象a，回溯，nest = 5
         *  此时，取出计算当前元素.get  (.get).eval(env,a)  从对象a中读到get并返回  nest = 4
         *  此时 取出当前元素()  执行get()，返回函数结果 nest = 3
         */
        return postfixPtr->eval(env,target);
    }else
    return operand()->eval(env);
}

Object::ptr PrimaryExpr::eval(Env &env) const {
    /*
    //如果是函数调用，child(0)必然是函数的名字，是一个Name类型
    //name.eval 就是从env 里取出name关联的obj
    auto res = operand()->eval(env);
    //std::cout<<operand()->nodeType()<<std::endl;
    int n = numChild();
    for (int i = 1; i <n ; ++i) {
        auto args = std::dynamic_pointer_cast<const Args>(child(i));
        res= args->eval(env,res);
    }
    return res;*/
    /**
     * 从右往左进行计算
      对于函数 a(1,2,3,4),从4开始放入环境
      对于对象 a.get().next.x = 3
     */
    return evalSub(env,0);
};

Object::ptr BinaryExpr::eval(Env &env) const {
    const std::string& o = op();
    auto r = right()->eval(env);
    if(o == "="){
        auto p = std::dynamic_pointer_cast<const PrimaryExpr>(left());
        if(p&&p->hasPostFix(0)){
            //获取链式调用的最后一个元素
          auto member =   std::dynamic_pointer_cast<const Dot>(p->postFix(0));
          if(member){
            //如果链式调用最后一个元素是.
          auto obj =   std::dynamic_pointer_cast<StoneObject>(p->evalSub(env,1));
          if(obj){
              try {
                  obj->write(member->name(),r);
                  return r;
              } catch (std::exception&r) {
                  throw StoneException("bad member access " + location() + ": " + member->name());
              }
          }
          }
        }
        //赋值的情况
        //普通变量赋值
        auto l = std::dynamic_pointer_cast<const Name>(left());
        if(!l)throw StoneException("bad assign");
        env.put(l->name(),r);
        return r;
    }else{
        //运算符
        auto l = left()->eval(env);
        if(o == "+"){return l->add(r);}
        if(o == "-")return l->sub(r);
        if(o == "*")return l->mul(r);
        if(o == "/")return l->div(r);
        if(o == "%")return l->mod(r);
        if(o == "==")return std::make_shared<Bool>(l->eq(r));
        if(o == ">")return std::make_shared<Bool>(l->gt(r));
        if(o == "<")return std::make_shared<Bool>(l->lt(r));
        throw StoneException("bad op");
    }
}

Object::ptr NegativeExpr::eval(Env &env) const {
    auto v= std::dynamic_pointer_cast<Num>(operand()->eval(env));
    if(v) return std::make_shared<Num>(v->value());
    throw StoneException("bad type for -");
}

Object::ptr DefStmt::eval(Env &env) const {
     env.putNew(name(),std::make_shared<Function>(params(),body(),&env));
     return std::make_shared<Str>(name());
}



//定义实参
void ParamList::eval(Env &env,int idx,Object::ptr value) const{
    env.putNew(name(idx),value);
}

Object::ptr Args::eval(Env &env, Object::ptr value) const {

    //处理naive函数
    auto naiveFunc = std::dynamic_pointer_cast<NaiveFunction>(value);
    if(naiveFunc){
            int n = naiveFunc->numArg();
            if(n!=-1 && size()!=n){
                throw StoneException("bad number of args"+ location());
            }
            std::vector<Object::ptr> args;
            args.reserve(size());
            for(auto&c:mChildren){
              args.push_back(c->eval(env));
            }
            return naiveFunc->invoke(args);
    }


    auto func = std::dynamic_pointer_cast<const Function>(value);
    if(!func)throw StoneException("bad function "+this->location());
    auto parms=  std::dynamic_pointer_cast<const ParamList>(func->parameters());
    if(!parms)throw StoneException("bad number of argments..."+ this->location());
    Env* newEv = func->makeEnv(); //创建一个临时的函数计算环境
    //TODO
    int id = 0;
    for(auto arg:mChildren){
        parms->eval(*newEv, id++, arg->eval(env));
    }
    auto ret = func->body()->eval(*newEv);
    delete newEv;
    return ret;
}

AstTree::cptr Fun::parameters() const {
    return child(0);
}

AstTree::cptr Fun::body() const{
    return child(1);
}

std::string Fun::toString() const noexcept {
    return "( fun"+parameters()->toString()+" "+body()->toString()+")";
}

Object::ptr Fun::eval(Env &env) const {
    return std::make_shared<Function>(parameters(),body(),&env);
}


std::string DefineStmt::toString() const noexcept {
    std::stringstream ss;
    ss<<"(var "<<name()<<" = "<<value()->toString()<<" )";
    return ss.str();
}

Object::ptr DefineStmt::eval(Env &env) const {
    auto r = value()->eval(env);
    env.putNew(name(),r);
    return r;
}

Object::ptr ClassStmt::eval(Env &env) const {
    auto classInfo =
    std::make_shared<ClassInfo>(shared_from_this(),&env);
    env.putNew(classInfo->name(),classInfo);
    return std::make_shared<Str>(name());
}

Object::ptr Dot::eval(Env &env, Object::ptr value) const {
    std::string member = name();
    //std::cout<<"dot eval"<<value<<" name = "<<name();
    auto ci = std::dynamic_pointer_cast<ClassInfo>(value);
    if(ci && member == "new"){
       NestEnv* ev = new NestEnv(&env);
       auto so = std::make_shared<StoneObject>(ev);
       initObject(ci,ev);
       ev->putNew("this",so);
       return so;
    }
    auto so = std::dynamic_pointer_cast<StoneObject>(value);
    if(so){
        return so->read(member);
    }
    throw StoneException("bad member access "+member +" "+location());
}

void Dot::initObject(Object::ptr c, NestEnv *pEnv) const {
    auto ci = std::dynamic_pointer_cast<ClassInfo>(c);
    auto superClass = ci->superClass();
    if(superClass)initObject(superClass,pEnv);
    ci->body()->eval(*pEnv);
}


Object::ptr ArrayLiteral::eval(Env &env) const {
    auto arr= std::make_shared<Array>(size());
    int i = 0;
    for(auto&c:mChildren){
        (*arr)[i++]= c->eval(env);
    }
    return arr;
}

Object::ptr ArrayRef::eval(Env &env, Object::ptr value) const {
    auto arr = std::dynamic_pointer_cast<Array>(value);
    if(arr){
        auto idx = std::dynamic_pointer_cast<Num>(index()->eval(env));
        if(idx)return (*arr)[static_cast<int>(idx->value())];
    }
    throw StoneException("bad array access "+location());
}
