//
// Created by 12206 on 2021/12/15.
//

#include "BasicType.h"
#include "AstNodeType.h"
#include "ClassInfo.h"
#include <sstream>

const std::string Num::TYPE = "Num";
const std::string Str::TYPE = "Str";
const std::string Bool::TYPE = "Bool";
const std::string ClassInfo::TYPE = "Class";
const std::string Array::TYPE = "Array";


ClassInfo::ClassInfo(AstTree::cptr df, Env *ev)
:Object(TYPE),definition(df),env(ev){
   auto  mdf = std::dynamic_pointer_cast<const ClassStmt>(df);
   if(!mdf)throw StoneException("bad class defination");
   std::string superName = mdf->superClass();
   auto super = env->get(superName);
   if(super){
       auto p = std::dynamic_pointer_cast<const ClassInfo>(super);
       if(!p)throw StoneException("unkown supper class "+ superName);
       mSuperClass = super;
   }
}

std::string ClassInfo::name() const {
    auto p = std::dynamic_pointer_cast<const ClassStmt>(definition);
    return p->name();
}

AstTree::cptr ClassInfo::body() const {
    auto p = std::dynamic_pointer_cast<const ClassStmt>(definition);
    return p->body();
}

std::string ClassInfo::toString() const noexcept {
    return "<class "+name()+">";
}

Str::Str(std::string str) : Object(TYPE), mStr(std::move(str)) {}
Num::Num(double v) : Object(TYPE), v(v) {}
Bool::Bool(bool v) : Object(TYPE), v(v) {}


Array::Array(int size):Object(TYPE),mElements(size){}

Object::ptr &Array::operator[](int i) {
    if(static_cast<size_t>(i)<0 || static_cast<size_t>(i)>=mElements.size())
        throw StoneException(i + " out of index");
    return mElements.at(i);
}

std::string Array::toString() const noexcept {
    std::stringstream ss;
    ss<<"< array"<<this<<" : ";
    for(auto &c:mElements){
        ss<<c->toString()<<' ';
    }
    ss<<" >";
    return ss.str();
}
