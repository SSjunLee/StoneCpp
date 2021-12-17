//
// Created by 12206 on 2021/12/12.
//
#include <iostream>
#include <sstream>
#include "AstNodeType.h"
#include "../stype/Function.h"
#include "../stype/BasicType.h"
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

//nest 表示从外层数的函数调用的次数
//写成递归是为了扩展闭包
Object::ptr PrimaryExpr::evalSub(Env &env, int nest) const {
    if(hasPostFix(nest)){
        auto target= evalSub(env,nest+1);
        auto postfixPtr = std::dynamic_pointer_cast<const Postfix>(postFix(nest));
        return postfixPtr->eval(env,target);
    }else
    return operand()->eval(env);
}

Object::ptr PrimaryExpr::eval(Env &env) const {
    //TODO 先暂时这样实现
    auto res = operand()->eval(env); //如果是函数调用，child(0)必然是函数的名字，是一个Name类型
    //std::cout<<operand()->nodeType()<<std::endl;
    int n = numChild();
    for (int i = 1; i <n ; ++i) {
        auto args = std::dynamic_pointer_cast<const Args>(child(i));
        res= args->eval(env,res);
    }


    return res;
    //return evalSub(env,0);

};

Object::ptr BinaryExpr::eval(Env &env) const {
    const std::string& o = op();
    auto r = right()->eval(env);
    if(o == "="){
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




void ParamList::eval(Env &env,int idx,Object::ptr value) const{
    env.putNew(name(idx),value);
}

Object::ptr Args::eval(Env &env, Object::ptr value) const {
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
    return nullptr;
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
