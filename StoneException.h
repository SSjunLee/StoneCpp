//
// Created by 12206 on 2021/12/11.
//

#ifndef STONE_STONEEXCEPTION_H
#define STONE_STONEEXCEPTION_H

#include <stdexcept>
#include <string>

class StoneException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};



#endif //STONE_STONEEXCEPTION_H
