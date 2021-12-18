//
// Created by 12206 on 2021/12/17.
//
#include "StoneException.h"
#include "AstTree.h"
StoneException::StoneException(const std::string &msg, std::shared_ptr<const AstTree> tree)
:std::runtime_error(msg+" "+tree->location()){}
