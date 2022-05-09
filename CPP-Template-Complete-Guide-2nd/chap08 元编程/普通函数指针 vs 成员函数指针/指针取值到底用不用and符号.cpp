#include <iostream>
using namespace std;

int f(int a){return a;}

class A 
{
    string name;
public:
    A(string s) {name=s;}
    void print() { cout <<"name:" << name << endl; }
};

int main()
{
    //!--------------- 变量指针
    int i = 123;                 //! 普通指针: 初始化时需要取址符, 调用所指量时需解引用.
    int * ip = &i;
    cout << *ip << endl;   
    int (*fp1)(int) = f;
    cout << fp1(456) << endl;
    cout << (*fp1)(456) << endl;

    //!--------------- 普通函数指针
    typedef int (*FP)(int);      //! 函数指针: 初始化是可以不用 取址符& ? 调用所指函数时, 也不必 解引用 ? 怎么理解 函数名 = 函数的地址 ?
    FP fp2 =  f;                 //! 函数指针比较特殊，调用时候不解引用也行,取地址也是用不用都行,可以理解为编译器帮你做了这些
    FP fp3 = &f;
    cout <<    fp2(456) << endl;
    cout << (*fp3)(456) << endl;

    //!--------------- 成员函数指针
    A a("hello world");
    void (A::*memP)()=&A::print; //! 定义 类A的 成员函数指针 memP 并 赋初值 &A::print
    (a.*memP)(); //! 不用星号, 即, (a.memP)() 也可以

    return 0;
}

