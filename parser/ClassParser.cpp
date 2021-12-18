//
// Created by 12206 on 2021/12/18.
//

#include "ClassParser.h"
#include "AstNodeType.h"

ClassParser::ClassParser() : ArrayParser() {

    OrRule *member = mFactory.orRule({def, defVariable});

    ListRule<ClassBody> *classBody = mFactory.rule<ClassBody>()
            ->sep({"{"})->option(member)
            ->repeat(mFactory.rule()->sep({";", Token::eol})
                             ->option(member))
            ->sep({"}"});

    ListRule<ClassStmt> *defClass = mFactory.rule<ClassStmt>()->sep({"class"})
            ->identifier(mReserved)
            ->option(
                    mFactory.rule()
                            ->sep({"extends"})
                            ->identifier(mReserved)
            )->ast(classBody);
    postfix->push_front({mFactory.rule<Dot>()->sep({"."})->identifier(mReserved)});
    programOr->push_front({defClass});
}
