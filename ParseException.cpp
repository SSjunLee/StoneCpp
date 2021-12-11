//
// Created by 12206 on 2021/12/11.
//

#include "ParseException.h"

ParseException::ParseException(const std::string &msg):msg(msg) {}

ParseException::ParseException(const std::string &msg, Token::cptr token) {

}

ParseException::ParseException(Token::cptr token) {

}

const char *ParseException::what() const noexcept {
    return msg.c_str();
}
