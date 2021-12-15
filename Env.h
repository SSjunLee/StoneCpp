//
// Created by 12206 on 2021/12/15.
//

#ifndef STONE_ENV_H
#define STONE_ENV_H

#include "BasicType.h"
class Env {
public:
    virtual ~Env() = default;
    virtual void put(const std::string&name,Object::ptr v) = 0;
    virtual Object::ptr get(const std::string&name) = 0;

};


#endif //STONE_ENV_H
