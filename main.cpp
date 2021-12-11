#include <iostream>
#include <fstream>
#include "Token.hpp"
#include "Lexer.h"
using namespace std;
int main() {
    //ifstream is("file");
    Lexer lexer(cin);
    Token::cptr  e;
    while((e = lexer.read())!=Token::eof){
        std::string s = (*e).getText();
        cout<<s<<endl;
    }


}