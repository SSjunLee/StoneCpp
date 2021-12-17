#include <iostream>
#include <fstream>
#include "Token.hpp"
#include "BasicParser.h"
#include "Lexer.h"
#include "BasicEnv.hpp"
#include "NestEnv.hpp"
#include "FuncParser.h"
using namespace std;

void testLexer(){
    Lexer lexer(cin);
    while(lexer.peek(0)!=Token::eof){
        cout<<lexer.read()->getText()<<endl;
    }
}

void testParser(){
    Lexer lexer(cin);
    BasicParser parser;
    while(lexer.peek(0)!=Token::eof){
        /*
        if(lexer.peek(0)->getText()==Token::eol){
            lexer.read();
            continue;
        }*/
        auto e= parser.parse(lexer);
        if(!e){
            cout<<"无法解析"<<endl;
            break;
        }else cout<<e<<' ';
    }
}
void testParser2(){
    ifstream in("D:\\code\\cpp\\Stone\\testDemo\\f1");
    Lexer lexer(in);
    BasicParser parser;
    while(lexer.peek(0)!=Token::eof){
        auto bp= parser.parse(lexer);
        cout<<bp<<endl;
    }
}

void testBaseType(){
    Num::ptr n1(std::make_shared<Num>(1)),n2(std::make_shared<Str>("abc"));
    cout<<n1->add(n2);
}

void testEval(){
    ifstream in("D:\\code\\cpp\\Stone\\testDemo\\f0");
    Lexer lexer(in);
    BasicEnv env;
    BasicParser parser;
    while(lexer.peek(0)!=Token::eof){
        auto bp= parser.parse(lexer);
        cout<<"=>"<<bp->eval(env)<<endl;
    }
}

void testFuncParser(){
    ifstream in("D:\\code\\cpp\\Stone\\testDemo\\f2");
    Lexer lexer(in);
    BasicEnv env;
    FuncParser parser;
    while(lexer.peek(0)!=Token::eof){
        auto bp= parser.parse(lexer);
        cout<<bp<<endl;
    }
}

void testEval2(){
    ifstream in("D:\\code\\cpp\\Stone\\testDemo\\f2");
    Lexer lexer(in);
    NestEnv env;
    FuncParser parser;
    while(lexer.peek(0)!=Token::eof){
        auto bp= parser.parse(lexer);
        cout<<bp<<endl;
        cout<<"=>"<<bp->eval(env)<<endl;
    }
}



int main() {
    system("chcp 65001");
    //testParser();
    //testParser2();
    //testBaseType();
    //testEval();
    //testFuncParser();
    testEval2();
}