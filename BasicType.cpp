//
// Created by 12206 on 2021/12/15.
//

#include "BasicType.h"

std::ostream &operator<<(std::ostream &o, Object::ptr obj) {
    if (obj)
        o << obj->toString();
    else o << "null";
    return o;
}

const std::string Num::TYPE = "Num";
const std::string Str::TYPE = "Str";
const std::string Bool::TYPE = "Bool";

