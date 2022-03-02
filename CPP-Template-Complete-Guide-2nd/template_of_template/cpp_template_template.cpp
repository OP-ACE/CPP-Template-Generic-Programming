

template<typename DType>
class CData
{
public:
    std::vector<DType>    mContent;
};


CData<int> x;

template<typename DType, typename TContainer >
class CData
{
public:
    TContainer<DType>    mContent;
};

CData<int,std::vector> x;

template<typename TContainer >
class CData
{
public:
    TContainer    mContent;
};

CData< std::vector<int> > x;


template<    typename DType,
            template<typename T> class TContainer >
class CData
{
public:
    TContainer<DType>    mContent;
};

template<typename T>
class CVector : public std::vector<T>
{};

CData<int, CVector> x;

#include <iostream>
template<template<typename T> class TFunc>
void FuncTemp(int iMode)
{
    if (iMode == 0 )
    {
        TFunc<int>()();
    }
    else if ( iMode == 1 )
    {
        TFunc<float>()();
    }
}

template<typename T>
class CFunc1
{
public:
    void operator()(){
    }
};

template<typename T>
class CFunc2
{
public:
    void operator()(){
    }
};

int main()
{
    FuncTemp<CFunc1>(1);
    FuncTemp<CFunc2>(0);
}

