//
// Created by 12206 on 2021/12/12.
//

#include "BasicParser.h"
#include "ast/AstNodeType.h"
std::unordered_set<std::string> BasicParser::mReserved{")","}","]",";"};

BasicParser::AstPtr BasicParser::parse(Lexer &lexer) {
    //return primaryOr->parse(lexer);
    return expr->parse(lexer);
}

BasicParser::BasicParser() {
    mReserved.insert(Token::eol);
    expr = mFactory.rule<>();
    primaryOr = mFactory.orRule({
        mFactory.rule<>()->sep({"("})->ast(expr)->sep({")"}),
        mFactory.rule<>()->number<NumLiteral>(),
        mFactory.rule<>()->identifier<Name>(mReserved),
        mFactory.rule<>()->string<StrLiteral>(),
    });
    primary = mFactory.rule<PrimaryExpr>(true)->ast(primaryOr);



    factor = mFactory.orRule({
                                     mFactory.rule<NegativeExpr>()->sep({"-"})->ast(primary),
                                     primaryOr
    });

    expr->expression<BinaryExpr>(factor,{
            {"=", {1, false}},
            {"==", {2, true}},
            {">", {2, true}},
            {"<", {2, true}},
            {"+", {3, true}},
            {"-", {3, true}},
            {"*", {4, true}},
            {"/", {4, true}},
            {"%", {4, true}}
    });

}


