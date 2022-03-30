#include <iostream>
#include <string>

using namespace std;

// class A
// {
// public:
//     A(int);
//     int a_ = 0;
// };

// A::A(int a)
// {
//     a_ = a;
//     cout << "ctor def outside class";
// };

class A
{
public:
    A() = default;   //! ---- [犯错] 无参构造函数
    A(int) ;         //! ---- [犯错] 有参构造函数, 必须先在类内声明原型,之后才能定义
    //int a_ = 123;  //! ---- [新知] 类内成员默认值可以用大括号或等号
    int a_{123};

    void show()
    {
        cout << "show : a_ = " << a_ << endl;
    }
};

A::A(int a)     //!------------------------------------------------------------- [新知] 普通类的构造函数: 类名(构造参数)
{
    a_ = a;
    show();    //! 构造函数中调用成员方法
};

template <typename T>
class B
{
public:
    T b_;
    B(T b); //! ---- [犯错] 必须现在类内定义构造函数的原型
};

template<typename T>
B<T>::B(T b)    //!------------------------------------------------------------- [新知] 模板的构造函数: 模板名<模板参数>(构造参数)
{
    //T b_ = b; //! ----- [犯错]
    b_ = b;
}


int main()
{
    cout << "\n----------------------\n";
    
    // A a1();//! ---- [犯错] 空圆括号有歧义, 最让人头痛的歧义，声明了一个名为 a1，不接受任何参数，返回A类型的函数！
    A a1{};   //! ---- [新知] 大括号无歧义
    cout << "a1.a_ = " << a1.a_ << endl;

    A a2;     //! ---- [新知] 调用无参构造函数 + 不初始化 的正确方式
    cout << "a2.a_ = " << a2.a_ << endl;

    A a3{789};   //! ---- [新知] 大括号无歧义
    cout << "a3.a_ = " << a3.a_ << endl;


    A a4(456);
    cout << "a4.a_ = " << a4.a_ << endl;

    B<string> b("Hello world!");
    cout << " b.b_ = " << b.b_ << endl;

    return 0;
}