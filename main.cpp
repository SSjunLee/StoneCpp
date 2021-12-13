#include <iostream>
#include <fstream>
#include "Token.hpp"
#include "BasicParser.h"
#include "Lexer.h"
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
    ifstream in("D:\\code\\cpp\\Stone\\file");
    Lexer lexer(in);
    BasicParser parser;
    while(lexer.peek(0)!=Token::eof){
        auto bp= parser.parse(lexer);
        cout<<bp<<endl;
    }
}

int main() {
    system("chcp 65001");
    //testParser();
    testParser2();
}