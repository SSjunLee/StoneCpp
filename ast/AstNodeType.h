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

};
class Name: public AstLeaf{
public:
    using AstLeaf::AstLeaf;
    std::string name() const{return token->getText();};
};
class StrLiteral: public AstLeaf{
public:
    using AstLeaf::AstLeaf;
    std::string value() const{return token->getText();};
};

class PrimaryExpr: public AstList{
public:
    using AstList::AstList;
};

class NegativeExpr: public AstList{
public:
    using AstList::AstList;
    AstTree::cptr operand() const{
        return child(0);
    }

    std::string toString() const noexcept override{
        return "-"+operand()->toString();
    }
};
class BinaryExpr: public AstList{
public:
    using AstList::AstList;
    cptr left() const{ return mChildren[0];};
    cptr right() const{return mChildren[2];};
    std::string op() const{return mChildren[1]->toString();};
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

};
class WhileStmt: public AstList{
public:
    using AstList::AstList;
    AstTree::cptr condition() const{return child(0);}
    AstTree::cptr body() const {return child(1);}
    std::string toString() const noexcept override;
};
class NullStmt: public AstList{
public:
    using AstList::AstList;
};
class BlockStmt: public AstList{
public:
    using AstList::AstList;
    std::string toString() const noexcept override;
};
#endif //STONE_ASTNODETYPE_H
