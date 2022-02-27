#include <iostream>

using namespace std;

// ! 模板参数 仅仅用作 返回类型
template<class T>
T sum(double a, double b)
{
    T result = T();
    result = T(a) + b;

    return result;

}

int main()
{
    cout << "sum<int>(1.23,3.45) = " << sum<int>(1.23,3.45) << endl;
}