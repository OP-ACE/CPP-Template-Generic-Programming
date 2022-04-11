#include <iostream>
#include <string>

template<typename T>
void printV(T arg) {};

std::string returnString(){return "hello!";};

int main()
{
    std::string s = "hi";
    printV(s);                 // 拷贝构造
    printV(std::string("hi")); // 通常会优化拷贝，否则使用移动构造
    printV(returnString());    // 通常会优化拷贝，否则使用移动构造
    printV(std::move(s));      // 移动构造
}
