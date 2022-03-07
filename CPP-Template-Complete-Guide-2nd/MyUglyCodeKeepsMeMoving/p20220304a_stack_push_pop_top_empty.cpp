#include <iostream>
#include <string>
#include <vector>

// 写一个类 叫 Stack<T> 
// 属性: std::vector<T> v
// 方法: void  push(T a); 
//       void  pop(); 
//       bool  empty();
//       T     top(); 




template<class T>
class Stack
{
    private:
    std::vector<T> v;

    public:
    void  push(T a);
    void  pop();
    bool  empty();
    T     top();
};

template<class T>
void Stack<T>::push(T a)
{                                 //* -------- 001 [忘记] 检查是否为空
    v.push_back(a);               //! -------- 002 [犯错] 调用函数,实参前无需类型 v.push_back(T a);  
}

template<class T>
void Stack<T>::pop()
{                                 //* -------- 003 [忘记] 检查是否为空
    v.pop_back();
}

template<class T>
bool Stack<T>::empty()
{
    return v.empty();            //! --------- 004 [犯错] : 有返回值, 却丢了 return
}

template<class T>
T Stack<T>::top()
{                                //* --------- 005 [忘记] 检查是否为空
    return v.back();
}

int main()
{
    //Stack<int> s1{12, 34, 56}; //! --------- 006 [犯错] 没有与参数列表匹配的构造函数 "Stack<T>::Stack [其中 T=int]" 参数类型为: (int, int, int)
    Stack<int> s1;
    std::cout << s1.empty() << std::endl;
    s1.push(12);
    s1.push(34);
    s1.push(56);
    std::cout << s1.top() << std::endl;
    s1.pop();
    std::cout << s1.top() << std::endl;
    std::cout << s1.empty() << std::endl;
}