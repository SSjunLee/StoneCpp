//
// Created by 12206 on 2021/12/12.
//

#ifndef STONE_ASTTREE_H
#define STONE_ASTTREE_H

#include <memory>
#include <vector>
#include "Token.hpp"
#include "Object.h"
#include "Env.h"
class AstTree {
public:
    typedef std::shared_ptr<AstTree> ptr;
    typedef std::shared_ptr<const AstTree> cptr;
    virtual cptr child(size_t i) const noexcept = 0;
    virtual int numChild() const noexcept = 0;
    virtual std::string location() const noexcept = 0;
    virtual std::string toString() const noexcept = 0;
    virtual Object::ptr eval(Env&env) const = 0;
    virtual Token::cptr getToken() const = 0;
    virtual ~AstTree() = default;
    virtual std::string nodeType() const = 0;
};

class AstLeaf: public AstTree{
protected:
    Token::cptr token;
public:
    AstLeaf(Token::cptr p):token(p){}
    Token::cptr getToken() const override{
        return token;
    }
    cptr child(size_t i) const noexcept override;

    int numChild() const noexcept override;

    std::string location() const noexcept override;

    std::string toString() const noexcept override;

    Object::ptr eval(Env &env) const override;

    std::string nodeType() const override {return "AstLeaf";}
};
class AstList: public AstTree{
protected:
    std::vector<AstTree::cptr> mChildren;
public:
     AstList(const std::vector<AstTree::cptr>&children):mChildren(children){}
public:
    cptr child(size_t i) const noexcept override;

    int numChild() const noexcept override;

    Token::cptr getToken() const override{
        throw StoneException("this ast node can't get token");
    }
    std::string location() const noexcept override;

    std::string toString() const noexcept override;

     Object::ptr eval(Env &env) const override;

    std::string nodeType() const override{return "AstList";}
};

std::ostream& operator<<(std::ostream&,const AstTree::cptr&);

#endif //STONE_ASTTREE_H
