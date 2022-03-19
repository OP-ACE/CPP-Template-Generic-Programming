#include <iostream>

template <typename T>
class Base
{
public:
    void f()
    {
        std::cout << " Base f " << std::endl;
    }
};

template <typename T>
class Derived : public Base<T>
{
public:
    void f()
    {
        std::cout << " Derived f " << std::endl;
    }
    void g() 
    { 
        f();          //! 如果不加限定符, 子类的同名函数 用于不会被解释成 父类同名函数
        this->f();    //! 加上限定符 this->
        Base<T>::f(); //! Base<T>::
    }
};

int main()
{
    Derived<int> d;
    d.g();
}