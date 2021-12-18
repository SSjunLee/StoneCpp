//
// Created by 12206 on 2021/12/18.
//

#ifndef STONE_STONEOBJECT_H
#define STONE_STONEOBJECT_H

#include "Env.h"
#include "Object.h"
class StoneObject: public Object{
public:
    const static std::string TYPE;
    StoneObject(Env*env);
    ~StoneObject();
    Object::ptr read(const std::string&name);
    void write(const std::string&name,Object::ptr v);
    std::string toString() const noexcept override;

protected:
    Env* getEnv(const std::string&name);
private:
    Env* mEnv;
};


#endif //STONE_STONEOBJECT_H
