//
// Created by 12206 on 2021/12/17.
//

#include "NaiveFunction.h"
const std::string NaiveFunction::TYPE ="NaiveFunction";



NaiveFunction::NaiveFunction(Method m, const std::string name, int argNum)
:Object(TYPE),method(m),name(name),argNum(argNum){

}

Object::ptr NaiveFunction::invoke(const std::vector<Object::ptr> &args, std::shared_ptr<const AstTree> tree) {
    try {
        return method(args);
    } catch (...) {
        throw StoneException("bad naive func call...\n");
    }

}

