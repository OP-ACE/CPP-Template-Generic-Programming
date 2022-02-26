#include <iostream>
using namespace std;

void PrintTwiceNaive(int data)
{
    cout << "Twice is : " << data * 2 << endl;
}



//! ---------------------------------- 0001. ostream 是一个类
//  (1) cout 对象都属于这个类
//  (2) 这个类为内置的基本数据类型重载了算符 <<, 
//      所以 cout << 5 和 cout 5.0 都可以直接用
//  (3) void 函数的 返回类型
//      void类型其实是一种用于语法性的类型,而不是数据类型，主要用于作为函数的参数或返回值，或者定义void指针，表示一种未知类型。



template <class T>
void PrintTwice_classT(T data){ cout << "Twice is : " << data * 2 << endl; }

// ! -------------------------------- 0002.  函数模板 vs 函数模板实例化
// 
// template <class T>
// void PrintTwice(T data){ ... }

//              ==

// void PrintTwice(int    data) { ... }
// void PrintTwice(double data) { ... }

// ! --------------------------------- 003. template<class T> vs template<typename T>
// You should have noticed that I used typename, instead of class. 
// No, it is not required to use typename keyword if 
// a function returning something. For template programming, 
// these two keywords are very much the same. 
// There is a historical reason for
// having two keywords for same purpose, and I hate history.
// However, there are instances where you can only use the newer keyword - typename.
// (When a particular type is defined in
// another type, and is dependent on some template parameter)
template <typename T>
T PrintTwice_typenameT(T data) { T r = data * 2; cout << r << endl; return r; }

int main()
{
    cout << "------------------------\n";
    PrintTwiceNaive(2.9);        // 输出结果为 4  ，不符合预期
    PrintTwice_classT(2.9);      // 输出结果为 5.8，  符合预期
    PrintTwice_typenameT(2.9);   // 输出结果为 5.8，  符合预期
}



