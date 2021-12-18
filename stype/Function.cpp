//
// Created by 12206 on 2021/12/17.
//
#include <sstream>
#include "Function.h"
#include "NestEnv.hpp"
const std::string Function::TYPE = "function";

Function::Function(AstTree::cptr parameters, AstTree::cptr body, Env *ev) :
        Object(TYPE), mParameters(parameters), mBody(body), env(ev) {

}

std::string Function::toString() const noexcept {
    std::stringstream  ss;
    ss<<"func ("<<this<<")";
    return ss.str();
}

AstTree::cptr Function::parameters() const {
    return mParameters;
}

AstTree::cptr Function::body() const {
    return mBody;
}

Env *Function::makeEnv() const {
    return new NestEnv(env);
}

