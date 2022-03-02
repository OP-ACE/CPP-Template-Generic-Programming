#ifndef __C_OBJECT_FACTORY_H_
#define __C_OBJECT_FACTORY_H_

#include <map>
#include <string>

typedef void* (*NewInstancePt)();

class CObjectFactory
{
public:
    static void* CreateObject(const char *className)
    {
        std::map<std::string, NewInstancePt>::const_iterator it;
        it = dynCreateMap.find(className);
        if(it == dynCreateMap.end())
            return NULL;
        else
        {
            NewInstancePt np = it->second;
            return np();
        }
    }

    static void RegisterClass(const char *className, NewInstancePt np)
    {
        dynCreateMap[className] = np;
    }
private:
    static std::map<std::string, NewInstancePt> dynCreateMap;
};

std::map<std::string, NewInstancePt> CObjectFactory::dynCreateMap;

class Register
{
public:
    Register(const char *className, NewInstancePt np)
    {
        CObjectFactory::RegisterClass(className, np);
    }
};

#define REGISTER_CLASS(class_name) \
class class_name##Register \
{ \
public: \
    static void* NewInstance() \
    { \
        return new class_name(); \
    } \
private: \
    static Register reg; \
}; \
Register class_name##Register::reg(#class_name, class_name##Register::NewInstance)

#endif //__C_OBJECT_FACTORY_H_