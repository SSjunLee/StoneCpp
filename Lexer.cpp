//
// Created by 12206 on 2021/12/11.
//
#include "Token.hpp"
#include "Lexer.h"
#include <regex>

class NumToken : public Token {
private:
    int v;
public:
    NumToken(int line, int v) : Token(line), v(v) {}

    bool isNumber() const noexcept override {
        return true;
    }

    int getNumber() override {
        return v;
    }
    std::string getText() const noexcept override {
        return std::to_string(v);
    }
};

class IdToken : public Token {
private:
    std::string text;
public:
    IdToken(int line, std::string text) : Token(line), text(text) {}

    bool isIdentifier() const noexcept override { return true; }

    std::string getText() const noexcept override {
        return text;
    }
};

class StrToken : public Token {
private:
    std::string literal;
public:
    StrToken(int line, std::string text) : Token(line), literal(text) {}

    bool isString() const noexcept override { return true; }

    std::string getText() const noexcept override {
        return literal;
    }
};


Token::ptr Token::eof = Token::ptr(new Token(-1));
std::string Token::eol{"\\n"};



static std::string regexPat{
        R"(\s*((//.*)|([0-9]+)|("(?:\\"|\\\\|\\n|[^"])*")|[A-Z_a-z][A-Z_a-z0-9]*|==|<=|>=|&&|\|\||[[:punct:]])?)"};
static std::regex pattern{regexPat};


Lexer::Lexer(std::istream &in) :
        reader(in) {}

//读入一行，将该行的token缓存，放回该行的第一个token，并将第一个token删除
Lexer::TokenPtr Lexer::read() {
    if (fillQueue(0)) {
        auto ret = queue.front();
        queue.pop_front();
        return ret;
    } else
        return Token::eof;
}

//预取i行，返回第一个token
Lexer::TokenPtr Lexer::peek(int i) {
    if (fillQueue(i)) {
        return queue.front();
    }
    return Token::eof;
}


bool Lexer::fillQueue(int i) {
    while (i >= queue.size()) {
        if (hasMore)
            readLine();
        else return false;
    }
    return true;
}

void Lexer::readLine() {
    std::string line;
    try {
        while (line.empty() && reader.good()) {
            std::getline(reader, line);
            //std::cout << line;
            lineNumber++;
        }
    } catch (std::ios_base::failure e) {
        throw ParseException(e.what());
    }
    if (reader.eof()) {
        hasMore = false;
    } else if (!reader.good()) {
        hasMore = false;
        throw ParseException("input stream error at line" + std::to_string(lineNumber));
    }
    std::smatch mather;
    while (line.size() && std::regex_search(line, mather, pattern)) {
        //std::cout<<line<<std::endl;
        addToken(lineNumber, mather);
        line = mather.suffix();
    }
    if (line.size()) {
        throw ParseException("bad token at line" + std::to_string(lineNumber));
    }
    //放入行结束标记
    queue.push_back(std::make_shared<const IdToken>(lineNumber, Token::eol));
}

void Lexer::addToken(int line, std::smatch &matcher) {
    std::string m = matcher[1];//1号匹配除空格外的完整匹配串
    if (m.empty() || matcher[2].matched)return; //2号匹配注释
    TokenPtr token;
    if (matcher[3].matched) {
        token = std::make_shared<const NumToken>(line, std::stoi(m));
    } else if (matcher[4].matched) {
        token = std::make_shared<const StrToken>(line, m);
    } else token = std::make_shared<const IdToken>(line, m);
    queue.push_back(token);
    /**
     * int id = 0;
    for (auto e:matcher)
        std::cout << std::to_string(id++) + " : " << e.str() << std::endl;
     */
}



