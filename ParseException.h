//
// Created by 12206 on 2021/12/11.
//

#ifndef STONE_PARSEEXCEPTION_H
#define STONE_PARSEEXCEPTION_H

#include <string>
#include <exception>
#include "Token.hpp"
class ParseException:std::exception {
private:
    std::string msg;
public:
    explicit ParseException(const std::string &msg);
    explicit ParseException(Token::cptr token);
    ParseException(const std::string&msg,Token::cptr token);
    const char * what() const noexcept override;
};


#endif //STONE_PARSEEXCEPTION_H
