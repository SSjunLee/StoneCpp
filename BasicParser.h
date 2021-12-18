//
// Created by 12206 on 2021/12/12.
//

#ifndef STONE_BASICPARSER_H
#define STONE_BASICPARSER_H
#include "exception/ParseException.h"
#include "ast/AstTree.h"
#include "ast/AstNodeType.h"
#include "Lexer.h"
#include "Parse.hpp"
#include <unordered_set>



class BasicParser {
    typedef AstTree::cptr AstPtr;
protected:
    static std::unordered_set<std::string> mReserved;
    ParseFactory mFactory;
public:
    BasicParser();
    AstPtr parse(Lexer&lexer);

protected:
    ListRule<> *expr;
    OrRule *primaryOr;
    OrRule *factor;
    ListRule<PrimaryExpr> *primary;// "(" expr ")" | NUMBER | IDENTIFIER | STRING
    ListRule<PrimaryExpr> *simple; // expr
    OrRule *statement;
    ListRule<BlockStmt> *block;
    ListRule<NullStmt> *nullTmp;
    OrRule *programOr;
    ListRule<> *program;
};


#endif //STONE_BASICPARSER_H
