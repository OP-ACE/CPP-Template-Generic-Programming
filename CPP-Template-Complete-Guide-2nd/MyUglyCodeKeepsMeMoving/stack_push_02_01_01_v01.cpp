//! 1. 借助于vector写一个类模板 stack<T>
//!    (1) 私有成员     : vector<T> v
//!    (2) 共有成员方法 : 压入      void = push(T a) , 类外实现


#include <iostream>
#include<string>
#include<vector>



template<class T>
class Stack               //! 这里区别于函数 没有 argument, 就光秃秃一个类名
{
    //private:            //! ----- 犯错 这里设置成员数据为私有, 后面  std::cout << v2[0] 出错
    std::vector<T> v;     //! ----- 犯错 001 丢了 std::, 写成 vector<T> v

    public:
    void push(T a);       //! ----- 犯错 002 void push(T a){};
};

template<class T>         //! ----- 犯错 001 第一遍写的时候 丢了 class 关键字, 写成了 template<T>
void Stack<T>::push(T a)
{
    v.push_back(a);       //! ----- 模糊 002 是 (this->v).push_back(a) 还是 v.push_back(a)
}

int main()
{
    std::vector<int> v1;
    v1.push_back(123);
    std::cout << v1[0];
    
    Stack<int> v2;
    v2.push(3);
    std::cout << v2[0] << std::endl; //! 犯错 ---- no match for 'operator[]' (operand types are 'Stack<int>' and 'int')
}