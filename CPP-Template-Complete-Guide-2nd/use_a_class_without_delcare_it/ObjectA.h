#ifndef __C_OBJECT_A_H_
#define __C_OBJECT_A_H_

#include "Object.h"

class CObjectA : public CObject
{
public:
    CObjectA(): className("CObjectA") {}
    ~CObjectA(){}
    const std::string GetClassName()
    {
        return className;
    }
private:
    std::string className;
};

REGISTER_CLASS(CObjectA);

#endif //__C_OBJECT_A_H_