//
// Created by 12206 on 2021/12/12.
//

#include "AstNodeType.h"

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
