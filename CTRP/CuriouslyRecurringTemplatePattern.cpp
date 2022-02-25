// ! 奇异的递归模板模式，指的是子类继承一个模板类，模板的特化类型 是 子类本身.
//   本篇短文将简短的介绍奇异递归模板模式(Curiously Recurring Template Pattern，CRTP)，
//   CRTP是C++模板编程时的一种惯用法（idiom）：把派生类作为基类的模板参数。更一般地被称作F-bound polymorphism。
//   1980年代作为F-bound polymorphism被提出。Jim Coplien于1995年称之为CRTP。
//   CRTP在C++中主要有两种用途：
//   静态多态（static polymorphism）,静态多态比继承虚函数的动态多态要快
//   添加方法同时精简代码
//   1.静态多态
//   先看一个简单的例子：
// ! CRTP一般长什么样？
// template <typename Child> 
// class Base 
// {
//     ...
// };
// class Derived : public Base<Derived> 
// { // 派生类将自己的类型传给基类模板
//     ...
// };
// ! 相较于普通的公有继承, 这里的基类是通过编译期的Child类型来持有Derived派生类的类型信息的
// ! 派生类在继承自基类的时候, 需要将自己的类型信息给它.

#include <iostream>

using namespace std;

template <typename Child>     
struct Base                    // ! -------------------- 001 Base          是一个 class template
{
    void interface()
    {
        static_cast<Child*>(this) -> implementation();
    }
};

struct Derived : Base<Derived> // ! -------------------- 002 Base<Derived> 是一个 template class, 模板特化
{                              // !                          派生类在继承自基类的时候, 需要将自己的类型信息给它.
    void implementation()      // !                          CRTP, 中文翻译为奇异模板递归模式, 名字很怪, 但原理挺简单, 就是把传进来的模板类型的信息, 再通过继承还给这个类。
    {
        cout << "Derived implementation\n";
    }
};

int main()
{
    Derived d;
    d.interface();

    return 0;
}

// 这里基类Base为模板类,
// 子类Drived继承自Base同时模板参数为Drived,
// 基类中有接口interface而子类中则有接口对应实现implementation,
// 基类interface中将this通过static_cast转换为模板参数类型,并调用该类型的implemention方法.
// 由于Drived继承基类时的模板为Drived类型,所以在static_cast时会转换为Drived并调用Drived的implemention方法.
// 注意这里采用的时static_cast而不是dynamic_cast, 因为只有继承了Base的类型才能调用interface且这里是向下转型, 所以采用static_cast是安全的.



