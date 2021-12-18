//
// Created by 12206 on 2021/12/12.
//

#ifndef STONE_ASTNODETYPE_H
#define STONE_ASTNODETYPE_H

#include <env/NestEnv.hpp>
#include "AstTree.h"
#include "BasicType.h"

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
    Object::ptr eval(Env &env) const override;
    std::string toString() const noexcept override{
        return "PrimaryExpr " + AstList::toString();
    }
    std::string nodeType() const override {return  "PrimaryExpr";}
    bool hasPostFix(int nest) const;
    AstList::cptr postFix(int nest) const{
        return child((size_t)numChild() - nest -1);
    }
    Object::ptr evalSub(Env &env,int nest) const;

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

class DefineStmt: public AstList{
public:
    using AstList::AstList;
    std::string nodeType() const override{return "DefineStmt";}
    std::string name() const {return child(0)->getToken()->getText();}
    AstList::cptr value() const {return child(1);}
    std::string toString() const noexcept override;

    Object::ptr eval(Env &env) const override;

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
    Object::ptr eval(Env &env) const override{return nullptr;}

};
class BlockStmt: public AstList{
public:
    using AstList::AstList;
    std::string toString() const noexcept override;
    std::string nodeType() const override {return  "BlockStmt";}
    Object::ptr eval(Env &env) const override;
};

//函数的支持
class ParamList: public AstList{
public:
    using AstList::AstList;
    std::string nodeType() const override {return  "ParamList";}
    //返回第i个参数的名字
    std::string name(int i) const{return child(i)->getToken()->getText();}
    size_t size() const noexcept {return numChild();}
    void eval(Env &env,int idx,Object::ptr value) const;

};
class DefStmt: public AstList{
public:
    using AstList::AstList;
    std::string nodeType() const override {return  "DefStmt";}
    std::string name() const{
        return child(0)->getToken()->getText();
    }

    AstTree::cptr params() const {
        return child(1);
    }
    AstTree::cptr body() const{
        return child(2);
    }
    std::string toString() const noexcept override{
        return "def ("+name()+params()->toString()+body()->toString()+")";
    }
    Object::ptr eval(Env &env) const override;
};


class ClassBody: public AstList{
public:
    using AstList::AstList;
    Object::ptr eval(Env &env) const override{
        for(auto&c:mChildren){
            c->eval(env);
        }
        return nullptr;
    }
};

class ClassStmt: public AstList, public std::enable_shared_from_this<ClassStmt>{
public:
    using AstList::AstList;
    std::string name() const {return child(0)->getToken()->getText();};
    std::string nodeType() const override{return "ClassStmt";}
    std::string superClass() const{
        if(numChild()<3)return "";
        return child(1)->getToken()->getText();
    }
    AstList::cptr body() const {return child(numChild()-1);}
    std::string toString() const noexcept override{
        std::string parent = superClass();
        if(parent=="")parent = "*";
        return "(class "+name()+" extends "+parent+" body: "+body()->toString() + ")";
    }
    Object::ptr eval(Env &env) const override;
};

class Postfix: public AstList{
public:
    using AstList::AstList;
    virtual Object::ptr eval(Env &env,Object::ptr target) const = 0;
    std::string nodeType() const override {return  "Postfix";}
    std::string toString() const noexcept override{
        return "postfix" + AstList::toString();
    }

};

class Args: public Postfix, public std::enable_shared_from_this<Args>{
public:
    using Postfix::Postfix;
    std::string nodeType() const override {return  "Args";}
    int size() const {return numChild();}
    Object::ptr eval(Env &env, Object::ptr value)const override;
    std::string toString() const noexcept override{
        return "args" + AstList::toString();
    }
};

class Dot: public Postfix {
public:
    using Postfix::Postfix;
    std::string nodeType() const override {return "dot";}
    Object::ptr eval(Env &env, Object::ptr value) const override;
    std::string name() const {return child(0)->getToken()->getText();}
    std::string toString() const noexcept override{
        return "."+name();
    }

private:
    void initObject(Object::ptr classInfo, NestEnv *pEnv) const;
};
class Fun: public AstList{
public:
    using AstList::AstList;
    AstTree::cptr parameters() const;
    AstTree::cptr body() const;
    std::string toString() const noexcept override;
    Object::ptr eval(Env &env) const override;

};

#endif //STONE_ASTNODETYPE_H
