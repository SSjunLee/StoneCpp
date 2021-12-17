//
// Created by 12206 on 2021/12/17.
//

#include "Naive.h"
#include "stype/Object.h"
#include "stype/BasicType.h"
#include "stype/NaiveFunction.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <functional>
Object::ptr naive_print(const std::vector<Object::ptr>& args){
    for(auto&arg:args){
        std::cout<<arg<<' ';
    }
    std::endl(std::cout);
    return nullptr;
}

static const clock_t startTime = clock();


Object::ptr naive_current_time(const std::vector<Object::ptr>& args){
    clock_t now = clock();
    return std::make_shared<Num>(static_cast<double>(now-startTime));
}

#define PUT(name,func,argNum)  env.putNew(name,std::make_shared<NaiveFunction>(func,name,argNum))

Env &naive_env(Env &env) {
    PUT("print",naive_print,-1);
    PUT("currentTime",naive_current_time,0);
    //env.putNew("print",std::make_shared<NaiveFunction>(naive_print,"print",-1));
    return env;
}


