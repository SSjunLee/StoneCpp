//
// Created by 12206 on 2021/12/12.
//

#ifndef STONE_BASICPARSER_H
#define STONE_BASICPARSER_H
#include "ParseException.h"
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

    ListRule<> *expr;

    OrRule *primaryOr;
    OrRule *factor;
    ListRule<PrimaryExpr> *primary;
};


#endif //STONE_BASICPARSER_H
