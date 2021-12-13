//
// Created by 12206 on 2021/12/12.
//

#include "AstTree.h"


int AstLeaf::numChild() const noexcept {
    return 0;
}

std::string AstLeaf::location() const noexcept {
    return "at line" + std::to_string(token->getLineNumber());
}

std::string AstLeaf::toString() const noexcept {
    return token->getText();
}

AstTree::cptr AstLeaf::child(size_t i) const noexcept {
    throw std::out_of_range("leaf don't have child");
}


int AstList::numChild() const noexcept {
    return mChildren.size();
}

std::string AstList::location() const noexcept {
    for (auto &c:mChildren) {
        auto s = c->location();
        if (s.size())return s;
    }
    return "";
}

std::string AstList::toString() const noexcept {
    std::string ret = "(";
    std::string sep;
    for(auto&c:mChildren){
        ret+=sep;
        sep=" ";
        ret+=c->toString();
    }
    ret+=")";
    return ret;
}

AstTree::cptr AstList::child(size_t i) const noexcept {
    return mChildren[i];
}

std::ostream &operator<<(std::ostream &o, const AstTree::cptr &p) {
    return o << p->toString();
}
