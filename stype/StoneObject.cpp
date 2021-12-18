//
// Created by 12206 on 2021/12/18.
//

#include "StoneObject.h"
#include <sstream>
const std::string StoneObject::TYPE = "StoneObject";



StoneObject::StoneObject(Env*env):Object(TYPE),mEnv(env) {}

StoneObject::~StoneObject() {delete mEnv;}

Object::ptr StoneObject::read(const std::string &name) {
    auto ev = getEnv(name);
    return ev->get(name);
}

void StoneObject::write(const std::string &name, Object::ptr v) {
    getEnv(name)->putNew(name,v);
}

std::string StoneObject::toString() const noexcept {
    std::stringstream  ss;
    ss<<"< object "<<this<<" >";
    return ss.str();
}

Env *StoneObject::getEnv(const std::string &name) {
    auto e= mEnv->where(name);
    if(!e||e!=mEnv)throw StoneException(name + " can't be accessed...");
    return e;
}

