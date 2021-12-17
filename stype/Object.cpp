//
// Created by 12206 on 2021/12/17.
//

#include "Object.h"
#include <ostream>
std::ostream &operator<<(std::ostream &o, Object::ptr obj) {
    if (obj)
        o << obj->toString();
    else o << "null";
    return o;
}


