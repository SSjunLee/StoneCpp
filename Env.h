//
// Created by 12206 on 2021/12/15.
//

#ifndef STONE_ENV_H
#define STONE_ENV_H

#include "stype/Object.h"
class Env {
public:
    virtual ~Env() = default;
    virtual void put(const std::string&name,Object::ptr v) = 0;
    virtual Object::ptr get(const std::string&name) = 0;
    //不考虑外层作用域是否存在变量
    virtual void putNew(const std::string&name,Object::ptr v){};
    //返回变量名所在的环境
    virtual Env* where(const std::string&name){return nullptr;};

};


#endif //STONE_ENV_H
