//
// Created by 12206 on 2021/12/17.
//

#ifndef STONE_FUNCTION_H
#define STONE_FUNCTION_H

#include "../ast/AstTree.h"
#include "Object.h"
class Function: public Object{
public:
    const static std::string TYPE;
    explicit Function(AstTree::cptr parameters,AstTree::cptr body,Env*ev);
    AstTree::cptr parameters() const;
    AstTree::cptr  body() const;
    Env* makeEnv() const;
    std::string toString() const noexcept override;
protected:
    AstTree::cptr mParameters;
    AstTree::cptr mBody;
    Env* env;



};


#endif //STONE_FUNCTION_H
