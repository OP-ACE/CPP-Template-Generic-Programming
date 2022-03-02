#include <iostream>
using namespace std;


template<template<typename T> class TFunc>
void FuncTemp(int iMode) //! FuncTemp 是一个函数模板, 需要用一个模板来作为模板参数实例化
{                        //! 实例化后得到一个函数, 比如传入模板参数 CF1, 得到 TFunc<CF1>()() : 第一个括号表示类初始化 就像 array<int>(); 第二个括号表示函数形参
    if (iMode == 0 )     //! 模板参数T完全没有用到
    {
        // TFunc<int>()();
        cout << "iMode == 0 \n";
    }
    else if ( iMode == 1 )
    {
        // TFunc<float>()();
        cout << "iMode == 1 \n";
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