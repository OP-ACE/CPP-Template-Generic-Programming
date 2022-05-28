#include <utility>
#include <iostream>

class X {};

void g (X&&) {std::cout << "g() for movable object\n";}

template<typename T> 
void f (T&& val) {           //! 我能理解了:
    g(std::forward<T>(val)); //! g接受了完美转发来的参数val
} 

struct Person
{   
    // std::string name;

    // template<typename STR>                         //! 我有点模糊和困惑的地方:
    // Person(STR&& n) : name(std::forward<STR>(n)){  //! 怎么就看出Person接受的是完美转发后的参数n呢? 
    //     std::cout << "TMPL-CONSTR \n";             //! 总感觉某个地方应该写类似 Person(std::forward<STR>(n)) 的代码,能吗?
    // }                                              //! 就因为转发后的n用于成员变量的初始化?
    
    //! 这个完美转发只和名字有关,只和从名字构造people有关. 与从people构造people无关.

    std::string name;

    //! 为什么要完美转发名字? n是万能引用，会保持n的左右值特性，但是如果直接传递给name，n就变成左值了，所以需要完美转发，保持n最初的左右值特性
    template<typename STR> 
    //Person(STR&& n){ //! n是个万能引用. 可以是指向任意类型的左值引用, 右值引用等. Person p3(p2);  
                       //! 按值传递就意味着调用复制构造, 即, 调用 Person(Person& p){}
    // Person(STR&& n) : name(std::forward<STR>(n)){
    Person(STR&& n) : name(n){ //! 直接传递参数, n 就是一个左值
        std::cout << "TMPL-CONSTR \n";
    }

    Person (Person&& p){std::cout << "MOVE-CONSTR Person \n";}
};

int main()
{
  std::cout << "\n-----------------------\n";
  f(X());

  Person p1("mike");          //! 调用 模板构造函数, 好理解
  std::cout << p1.name ;
  
  std::string s{"john"};
  Person p2(s); // 由于折叠原则, n 为左值引用

  Person p3(std::move(p1));   //! 调用 移动构造, 好理解
//   Person p4(p3);           //! 错误, 因为 对于 non-const 左值引用, 
                              //! 使用右值引用人名的构造函数 比 复制构造函数 匹配度更好
}




//  The problem is that, according to the overload resolution rules of C++ (see Section 16.2.4 on page 333), 
//! -------------------------------------------------------------------------------------------------------
//! For a nonconstant lvalue Person p, the member template
//!    template<typename STR>
//!    Person(STR&& n)
//! is a better match than the (usually predeﬁned) copy constructor:
//!    Person (Person const& p)
//! STR is just substituted with Person&, while for the copy constructor a conversion to constis neces-sary.
//! 一个人名字的类型 (STR), 被替换为, 一个人的引用 (Person&)

//! -------------------------------------------------------------------------------------------------------
//! You might think about solving this by also providing a nonconstant copy constructor:
//!     Person (Person& p)
//! However, that is only a partial solution because for objects of a derived class (子类), 
//! the member template is still a better match. 

//! -------------------------------------------------------------------------------------------------------

//! What you really want is to disable the member template for the case 
//! that the passed argument is a Person or an expression that can be converted to a Person. 
//! This can be done by using std::enable_if<>

//! -------------------------------------------------------------------------------------------------------
//  Person(Person("mike")) works already 
//  because you have also defined a move constructor (or since C++17 it doesn't even require that). 
//! Person(p1) doesn't work because 
//! overload resolution will erroneously prefer the constructor template over the implicit copy constructor. 
//  If your question is how to make the copy constructor usable despite the converting constructor template, 
//  you should have asked for that. It has nothing to do with perfect-forwarding.