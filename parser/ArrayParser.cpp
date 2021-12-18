//
// Created by 12206 on 2021/12/18.
//

#include "ArrayParser.h"
#include "AstNodeType.h"
ArrayParser::ArrayParser():FuncParser(){
    ListRule<ArrayLiteral> *elements = mFactory.rule<ArrayLiteral>()
            ->ast(expr)->repeat(mFactory.rule()
                                        ->sep({","})
                                        ->ast(expr));
    primaryOr->push_front({
        mFactory.rule()->sep({"["})->maybe(elements)->sep({"]"})
    });
    postfix->push_front({mFactory.rule<ArrayRef>()
            ->sep({"["})->ast(expr)->sep({"]"})});
}
