#include <iostream>

using namespace std;

// ! 函数模板的 类型参数 可以不是 形参
template<class T>
void PrintSize()
{
    cout << "The size of this type, sizeof(type) = " << sizeof(T) << endl;
}

int main()
{
    PrintSize<float>();
}