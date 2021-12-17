//
// Created by 12206 on 2021/12/17.
//

#ifndef STONE_NAIVEFUNCTION_H
#define STONE_NAIVEFUNCTION_H

#include "Object.h"
#include <vector>
#include <memory>
#include <functional>

class AstTree;


typedef std::function<Object::ptr(const std::vector<Object::ptr>& args)> Method;

class NaiveFunction: public Object {
public:
    const static std::string TYPE;
    NaiveFunction(Method m,const std::string name,int argNum);
    Object::ptr invoke(const std::vector<Object::ptr>& args,std::shared_ptr<const AstTree> tree);
    Object::ptr  invoke(const std::vector<Object::ptr>& args){
        return method(args);
    }
    int numArg() const{ return argNum;}
private:
    Method method;
    std::string  name;
    int argNum;
};


#endif //STONE_NAIVEFUNCTION_H
