#ifndef __C_OBJECT_B_H_
#define __C_OBJECT_B_H_

#include "Object.h"

class CObjectB : public CObject
{
public:
    CObjectB(): className("CObjectB") {}
    ~CObjectB(){}
    const std::string GetClassName()
    {
        return className;
    }
private:
    std::string className;
};

REGISTER_CLASS(CObjectB);

#endif //__C_OBJECT_B_H_