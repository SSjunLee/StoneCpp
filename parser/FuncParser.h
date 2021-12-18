//
// Created by 12206 on 2021/12/15.
//

#ifndef STONE_FUNCPARSER_H
#define STONE_FUNCPARSER_H


#include "BasicParser.h"
class FuncParser: public BasicParser{
public:
    FuncParser();

protected:
    OrRule *postfix;
    ListRule<DefStmt> *def;
};


#endif //STONE_FUNCPARSER_H
