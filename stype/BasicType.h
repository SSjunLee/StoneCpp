//
// Created by 12206 on 2021/12/15.
//

#ifndef STONE_BASICTYPE_H
#define STONE_BASICTYPE_H

#include <memory>
#include <utility>
#include <ostream>
#include "StoneException.h"
#include "AstTree.h"
#include "Object.h"


class Str : public Object {
public:
    const static std::string TYPE;

    Str(std::string str);// : Object(TYPE), mStr(std::move(str)) {}
    bool eq(ptr &o) const override {
        if (o->name != TYPE)throw StoneException(o->name + " type error");
        auto other = std::dynamic_pointer_cast<const Str>(o);
        return mStr == other->mStr;
    }

    bool check() const noexcept override {
        return mStr.size();
    }

    ptr add(ptr &o) const override {
        return std::make_shared<Str>(mStr + o->toString());
    }

    std::string toString() const noexcept override {
        return mStr;
    }

private:
    std::string mStr;
};


class Num : public Object {
public:
    const static std::string TYPE;

    Num(double v);// : Object(TYPE), v(v) {}

    bool lt(ptr &o) const override {
        if (o->name != TYPE) throw StoneException("error type for" + o->name);
        auto oo = std::dynamic_pointer_cast<const Num>(o);
        return v < oo->v;
    };

    bool gt(ptr &o) const override {
        if (o->name != TYPE) throw StoneException("error type for" + o->name);
        auto oo = std::dynamic_pointer_cast<const Num>(o);
        return v > oo->v;
    };

    bool eq(ptr &o) const override {
        if (o->name != TYPE) throw StoneException("error type for" + o->name);
        auto oo = std::dynamic_pointer_cast<const Num>(o);
        return v == oo->v;
    };

    bool check() const noexcept override {
        return v != 0;
    }

    ptr add(ptr &o) const override {
        if (o->name == Str::TYPE)return std::make_shared<Str>(toString() + o->toString());
        if (o->name != TYPE)throw StoneException(o->name + "type error");
        auto other = std::dynamic_pointer_cast<const Num>(o);
        return std::make_shared<Num>(other->v + v);
    }

    ptr sub(ptr &o) const override {
        if (o->name != TYPE)throw StoneException(o->name + "type error");
        auto other = std::dynamic_pointer_cast<const Num>(o);
        return std::make_shared<Num>(v - other->v);
    }

    ptr mul(ptr &o) const override {
        if (o->name != TYPE)throw StoneException(o->name + "type error");
        auto other = std::dynamic_pointer_cast<const Num>(o);
        return std::make_shared<Num>(v * other->v);
    }

    ptr div(ptr &o) const override {
        if (o->name != TYPE)throw StoneException(o->name + "type error");
        auto other = std::dynamic_pointer_cast<const Num>(o);
        return std::make_shared<Num>(v / other->v);
    }

    ptr mod(ptr &o) const override {
        if (o->name != TYPE)throw StoneException(o->name + "type error");
        auto other = std::dynamic_pointer_cast<const Num>(o);
        return std::make_shared<Num>((int) v % (int) (other->v));
    }

    std::string toString() const noexcept override {
        return std::to_string(v);
    }

    double value() const { return v; }

private:
    double v;
};

class Bool : public Object {
private:
    bool v;
public:
    Bool(bool v);// : Object(TYPE), v(v) {}

    const static std::string TYPE;

    bool eq(ptr &o) const override {
        if (o->name != TYPE)throw StoneException(o->name + "type error");
        auto other = std::dynamic_pointer_cast<const Bool>(o);
        return other->v == v;
    }

    bool check() const noexcept override {
        return v;
    }

    std::string toString() const noexcept override {
        return v ? "true" : "false";
    }
};


class Array: public Object{
public:
    const static std::string TYPE;
    explicit Array(int size);
    Object::ptr& operator[](int i);
    std::string toString() const noexcept override;
protected:
    std::vector<Object::ptr> mElements;
};


#endif //STONE_BASICTYPE_H
