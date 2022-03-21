//! 1. 借助于vector写一个类模板 stack<T>
//!    (1) 私有成员     : vector<T> v
//!    (2) 共有成员方法 : 压入      void = push(T a) , 类外实现
//!                      弹出      void = pop()     , 类外实现
//!                      取顶元    T    = top()     , 类外实现
//!                      查询空否  bool = empty()   , 类内实现


#include <iostream>
#include<string>
#include<vector>



template<class T>
class Stack //! 这里区别于函数 没有 argument, 就光秃秃一个类名
{
    private:
    vector<T> v;

    public:
    void push(T a){};

    void pop(){};

    T top(){};

    bool empty()
    {
        v.empty();
    }
};

template<T>
void Stack<T>::push(T a)
{
    v.push_back(a);
}

int main()
{

}