//
// Created by 12206 on 2021/12/15.
//
#include "FuncParser.h"


FuncParser::FuncParser():BasicParser() {
    ListRule<AstList> *param = mFactory.rule<>()->identifier<>(mReserved);

    ListRule<ParamList> *params = mFactory.rule<ParamList>()->ast(param)->repeat(
            mFactory.rule<>()->sep({","})->ast(param));

    ListRule<AstList> *paramList = mFactory.rule<>()->sep({"("})->maybe(params)->sep({")"});

    def = mFactory.rule<DefStmt>()->sep({"def"})->identifier<>(mReserved)->ast(paramList)->ast(
            block);

    ListRule<Args> *args = mFactory.rule<Args>()->ast(expr)->repeat(mFactory.rule<>()->sep({","})->ast(expr));

    postfix = mFactory.orRule({mFactory.rule<>()->sep({"("})->maybe(args)->sep({")"})});

    primary->repeat(postfix);//用于支持表达式里有后缀符号的情况 如 1+2+sum(1)
    simple->option(args);//这条模式可以匹配这样的函数调用 sum 2
    programOr->push_front({ def });

    //添加闭包支持
    primaryOr->push_front({mFactory.rule<Fun>()->sep({"fun"})->ast(paramList)->ast(block)});
}
