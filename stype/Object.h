//
// Created by 12206 on 2021/12/17.
//

#ifndef STONE_OBJECT_H
#define STONE_OBJECT_H

#include <memory>
#include "StoneException.h"
class Object {
public:
    typedef std::shared_ptr<Object> ptr;
    typedef std::shared_ptr<const Object> cPtr;
    const std::string name; // 类型的名字
    explicit Object(std::string name) : name(std::move(name)) {}

    virtual bool lt(ptr &o) const {
        throw StoneException(name + "type can't <");
    }

    virtual bool gt(ptr &o) const {
        throw StoneException(name + "type can't >");
    }

    virtual bool eq(ptr &o) const {
        throw StoneException(name + "type can't ==");
    }

    virtual bool check() const noexcept {
        return true;
    }

    virtual ptr add(ptr &o) const {
        throw StoneException(name + "type can't +");
    }

    virtual ptr sub(ptr &o) const {
        throw StoneException(name + "type can't -");
    }

    virtual ptr mul(ptr &o) const {
        throw StoneException(name + "type can't *");
    }

    virtual ptr div(ptr &o) const {
        throw StoneException(name + "type can't /");
    }

    virtual ptr mod(ptr &o) const {
        throw StoneException(name + "type can't %");
    }

    virtual std::string toString() const noexcept {
        return "";
    }
};

std::ostream &operator<<(std::ostream &, Object::ptr);


#endif //STONE_OBJECT_H
