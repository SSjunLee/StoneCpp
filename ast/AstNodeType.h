//
// Created by 12206 on 2021/12/12.
//

#ifndef STONE_ASTNODETYPE_H
#define STONE_ASTNODETYPE_H

#include "AstTree.h"

class NumLiteral: public AstLeaf{
public:
    using AstLeaf::AstLeaf;
    int value() const{return token->getNumber();};
    Object::ptr eval(Env &env) const override{
        return std::make_shared<Num>(value());
    }
    std::string nodeType() const override {return "NumLiteral";}
};
class Name: public AstLeaf{
public:
    using AstLeaf::AstLeaf;
    std::string name() const{return token->getText();};
    Object::ptr eval(Env &env) const override{
        auto v = env.get(name());
        if(v== nullptr)throw StoneException("undefined name "+name());
        return v;
    }
    std::string nodeType() const override {return "Name";}
};
class StrLiteral: public AstLeaf{
public:
    using AstLeaf::AstLeaf;
    std::string value() const{return token->getText();};
    Object::ptr eval(Env &env) const override{
        return std::make_shared<Str>(value());
    }
    std::string nodeType() const override {return "StrLiteral";}
};

class PrimaryExpr: public AstList{
public:
    using AstList::AstList;
    AstTree::cptr operand() const {return child(0);}
    Object::ptr eval(Env &env) const override{
        //TODO 先暂时这样实现
        return operand()->eval(env);
    };
    std::string toString() const noexcept override{
        return "PrimaryExpr " + AstList::toString();
    }
    std::string nodeType() const override {return  "PrimaryExpr";}
private:
    bool hasPostFix(int nest) const;
    AstList::cptr postFix(int nest) const{
        return child((size_t)numChild() - nest -1);
    }
    //Object::ptr evalSub(Env &env,int nest) const;

};

class NegativeExpr: public AstList{
public:
    using AstList::AstList;
    AstTree::cptr operand() const{
        return child(0);
    }
    Object::ptr eval(Env &env) const override;
    std::string toString() const noexcept override{
        return "-"+operand()->toString();
    }
    std::string nodeType() const override {return "NegativeExpr";}
};
class BinaryExpr: public AstList{
public:
    using AstList::AstList;
    cptr left() const{ return mChildren[0];};
    cptr right() const{return mChildren[2];};
    std::string op() const{return mChildren[1]->toString();};
    Object::ptr eval(Env &env) const override;
    std::string toString() const noexcept override{
        return "BinaryExpr "+AstList::toString();
    }
    std::string nodeType() const override {return "BinaryExpr";}
};

class IfStmt: public AstList{
public:
    using AstList::AstList;
    std::string toString() const noexcept override;
    AstTree::cptr condition() const{return child(0);};
    AstTree::cptr thenBlock() const{return child(1);};
    AstTree::cptr elseBlock() const{
        return numChild()>2?child(2): nullptr;
    };
    std::string nodeType() const override {return "IfStmt";}
    Object::ptr eval(Env &env) const override;
};
class WhileStmt: public AstList{
public:
    using AstList::AstList;
    AstTree::cptr condition() const{return child(0);}
    AstTree::cptr body() const {return child(1);}
    std::string toString() const noexcept override;
    std::string nodeType() const override {return "WhileStmt";}
    Object::ptr eval(Env &env) const override;
};
class NullStmt: public AstList{
public:
    using AstList::AstList;
    std::string nodeType() const override {return "NullStmt";}

};
class BlockStmt: public AstList{
public:
    using AstList::AstList;
    std::string toString() const noexcept override;
    std::string nodeType() const override {return  "BlockStmt";}
    Object::ptr eval(Env &env) const override;
};
#endif //STONE_ASTNODETYPE_H
