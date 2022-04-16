#include <functional>
#include <iostream>

using namespace std;

void f(int& n1, int& n2, const int& n3)
{
    cout << "\n---- In  : ----\n";
    cout << "n1 : " << n1 << endl;
    cout << "n2 : " << n2 << endl;
    cout << "n3 : " << n3 << endl;
    ++n1;     //  增加存储于函数对象的 n1 副本, n1是值传递，函数内部的修改对外面没有影响
    ++n2;     //  增加 main() 的 n2, n2是引用传递，函数内部的修改影响外面
    //++n3;   //! 编译错误, 不能改变 const量, n3是const引用传递，函数内部不能修改
    cout << "\n---- Out : ----\n";
    cout << "n1 : " << n1 << endl;
    cout << "n2 : " << n2 << endl;
    cout << "n3 : " << n3 << endl;
}

int main()
{
    int n1 = 1, n2 = 1, n3 = 1;
    cout << "\n==== Before f: ====\n";
    cout << "n1 : " << n1 << endl;
    cout << "n2 : " << n2 << endl;
    cout << "n3 : " << n3 << endl;

    //! bind(): (1)是一个函数模板，根据已有的模板，生成一个函数.
    //!         (2)但 bind()不知道 生成的函数 执行的时候，传递进来的参数是否还有效.
    //!            故 bind()选择参数值传递而不是引用传递.
    //!            若 想 引用传递，std::ref和std::cref就派上用场了.
    function<void()> bound_f = bind(f, n1, ref(n2), cref(n3));
    bound_f();

    cout << "\n==== After f: ====\n";
    cout << "n1 : " << n1 << endl;
    cout << "n2 : " << n2 << endl;
    cout << "n3 : " << n3 << endl;
}