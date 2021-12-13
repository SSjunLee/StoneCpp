//
// Created by 12206 on 2021/12/11.
//

#ifndef STONE_TOKEN_HPP
#define STONE_TOKEN_HPP

#include <memory>
#include "StoneException.h"


class Token {
public:
    typedef std::shared_ptr<Token> ptr;
    typedef std::shared_ptr<const Token> cptr;
    //static ptr eof;
    explicit Token(int line):lineNumber(line){}
    virtual ~Token() = default;
    int getLineNumber() const {
        return lineNumber;
    }
    virtual bool isIdentifier() const noexcept {return false;}
    virtual bool isNumber() const noexcept {return false;}
    virtual bool isString() const noexcept {return false;}
    virtual int getNumber() const{throw StoneException("not number token");}
    virtual std::string getText() const noexcept {return "";}

    static ptr eof;
    static std::string eol; //表示行的结束
protected:
    int lineNumber;
};





#endif //STONE_TOKEN_HPP
