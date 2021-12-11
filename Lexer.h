//
// Created by 12206 on 2021/12/11.
//

#ifndef STONE_LEXER_H
#define STONE_LEXER_H

#include <iostream>
#include <queue>
#include "Token.hpp"
#include "ParseException.h"
#include <regex>
class Lexer {
    using TokenPtr = Token::cptr;
public:
    explicit Lexer(std::istream &in);
    TokenPtr read();
    TokenPtr peek(int i);

private:
    bool fillQueue(int i);
    void readLine();
    void addToken(int line,std::smatch&matcher);
private:
    std::deque<TokenPtr> queue;
    bool hasMore{true};
    std::istream &reader;
    int lineNumber{0};


};


#endif //STONE_LEXER_H
