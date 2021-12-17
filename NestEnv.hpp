//
// Created by 12206 on 2021/12/17.
//

#ifndef STONE_NESTENV_HPP
#define STONE_NESTENV_HPP

#include "Env.h"
#include <unordered_map>
class NestEnv: public Env {
public:
    explicit NestEnv()=default;
    explicit NestEnv(Env*o):outer(o){}
    void put(const std::string &name, Object::ptr v) override{
        auto env= where(name);
        //if(!env)env = this;
        if(!env)throw StoneException(name+" not define");
        env->putNew(name,v);
    }
    Object::ptr get(const std::string &name) override{
        auto it = mValues.find(name);
        if(it!=mValues.end())
            return it->second;
        auto env= where(name);
        if(!env)return nullptr;
        return env->get(name);
    }
    void putNew(const std::string &name, Object::ptr v) override{
        mValues[name]=v;
    }
    Env * where(const std::string &name) override{
        auto it = mValues.find(name);
        if(it!=mValues.end())return this;
        if(!outer)return nullptr;
        return outer->where(name);
    }

protected:
    Env*outer = nullptr;
    std::unordered_map<std::string,Object::ptr> mValues;

};


#endif //STONE_NESTENV_HPP
