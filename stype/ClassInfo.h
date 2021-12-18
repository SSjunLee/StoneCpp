//
// Created by 12206 on 2021/12/18.
//

#ifndef STONE_CLASSINFO_H
#define STONE_CLASSINFO_H
#include "AstTree.h"
#include "Object.h"

class ClassInfo: public Object{
public:
    const static std::string TYPE;
    ClassInfo(AstTree::cptr df,Env*ev);

    std::string name() const;
    Object::ptr superClass(){return mSuperClass;};
    AstTree::cptr body() const;

    std::string toString() const noexcept;
protected:
    AstTree::cptr definition;
    Object::ptr mSuperClass;
    Env* env;
};


#endif //STONE_CLASSINFO_H
