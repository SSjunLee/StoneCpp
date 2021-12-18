//
// Created by 12206 on 2021/12/15.
//

#ifndef STONE_BASICENV_HPP
#define STONE_BASICENV_HPP

#include <unordered_map>
#include "Env.h"

class BasicEnv : public Env {
public:
    void put(const std::string &name, Object::ptr v) override {
        mValues[name] = v;
    }

    Object::ptr get(const std::string &name) {
        auto i = mValues.find(name);
        if (i == mValues.end())return nullptr;
        return i->second;
    };

private:
    std::unordered_map<std::string, Object::ptr> mValues;
};


#endif //STONE_BASICENV_HPP
