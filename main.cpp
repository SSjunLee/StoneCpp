#include <iostream>
#include <fstream>
#include "Token.hpp"
#include "BasicParser.h"
#include "NestEnv.hpp"
#include "FuncParser.h"
#include "Naive.h"
using namespace std;


void inter_run(const std::string&path){
    ifstream in(path);
    Lexer lexer(in);
    NestEnv env;
    naive_env(env);
    FuncParser parser;
    while(lexer.peek(0)!=Token::eof){
        auto bp= parser.parse(lexer);
        cout<<bp->nodeType()<<endl;
        cout<<bp<<endl;
        cout<<"=>"<<bp->eval(env)<<endl;
    }
}



int main() {
    system("chcp 65001");
    inter_run("D:\\code\\cpp\\Stone\\tests\\f5");
}