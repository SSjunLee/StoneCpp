#include <iostream>
#include <fstream>
#include "Token.hpp"
#include "BasicParser.h"
#include "Lexer.h"
using namespace std;
int main() {
    //ifstream is("file");
   Lexer lexer(cin);
   BasicParser parser;
   while(lexer.peek(0)!=Token::eof){
       if(lexer.peek(0)->getText()==Token::eol){
           lexer.read();
           continue;
       }
       auto e= parser.parse(lexer);
       cout<<e<<' ';
   }

}