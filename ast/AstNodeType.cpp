//
// Created by 12206 on 2021/12/12.
//

#include "AstNodeType.h"

std::string IfStmt::toString() const noexcept {
    std::string ret;
    ret+="( if(" + condition()->toString()+")"+thenBlock()->toString();
    auto el = elseBlock();
    if(el){
        ret+=el->toString();
    }
    ret+=" )";
    return ret;
}

std::string WhileStmt::toString() const noexcept {
    std::string ret;
    ret+="( while (" + condition()->toString()+")"+body()->toString()+")";
    return ret;
}

std::string BlockStmt::toString() const noexcept {
    std::string ret{"(block {"};
    for(auto c:mChildren){
        ret+=c->toString()+", ";
    }
    ret+="})";
    return ret;
}
