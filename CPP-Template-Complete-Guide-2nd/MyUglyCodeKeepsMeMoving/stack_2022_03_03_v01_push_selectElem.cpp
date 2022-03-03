//! 1. 借助于vector写一个类模板 stack<T>
//!    (1) 私有成员     : vector<T> v
//!    (2) 共有成员方法 : 压入      void = push(T a) , 类外实现


#include <iostream>
#include<string>
#include<vector>



template<class T>
class Stack                           //* ----- 001 这里区别于函数 没有 argument, 就光秃秃一个类名
{     
    //private:                        //! ----- 002 犯错 这里设置成员数据为私有, 后面  std::cout << v2[0] 出错
    std::vector<T> v;                 //! ----- 003 犯错 丢了 std::, 写成 vector<T> v; 犯错 
    // std::vector<T> this->v;        //! ----- 004 犯错 类内定义数据成员时, 写上this是错误的, 但是类内成员函数调用时是必须的
    public:     
    void push(T a);                   //! ----- 004 犯错 void push(T a){}; 函数声明不需函数体,仅要函数名
     
    T operator[](int i);              //! ----- 005 犯错 Stack类并没有实现 [] 算符, 虽然内部是用 std::vector, 见 009
};     
     
template<class T>                     //! ----- 006 犯错 001 第一遍写的时候 丢了 class 关键字, 写成了 template<T>
void Stack<T>::push(T a)              //* ----- 007 类内直接写函数名即可, 类外需要写上类名::函数名
{     
    this->v.push_back(a);             //* ----- 008 模糊 002 是 (this->v).push_back(a) 还是 v.push_back(a)
}

template<class T>
T Stack<T>::operator[](int i)
{
    return v[i];
}

int main()
{
    std::vector<int> v1;
    v1.push_back(123);
    std::cout << v1[0];
    
    Stack<int> v2;                   //! ---- 009 这里说 v2 是一个 Stack<int> 的对象, 而非 std::vector<int>, 程序会沿着 Stack<int>类中找 []算子 的成员方法
    v2.push(3);
    std::cout << v2[0] << std::endl; //! ---- 010 犯错 no match for 'operator[]' (operand types are 'Stack<int>' and 'int')
}