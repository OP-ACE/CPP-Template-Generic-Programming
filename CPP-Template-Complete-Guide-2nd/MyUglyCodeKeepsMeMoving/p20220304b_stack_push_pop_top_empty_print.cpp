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
    void  printOn(std::ostream & os);       //! -------- 001 [错误] 丢了&, 忘记了 传 stream 只能 按引用传
};

template<class T>
void Stack<T>::push(T a)
{                                
    v.push_back(a);               
}

template<class T>
void Stack<T>::pop()
{                                
    v.pop_back();
}

template<class T>
bool Stack<T>::empty()
{
    return v.empty();            
}

template<class T>
T Stack<T>::top()
{                               
    return v.back();
}

template<class T>
void Stack<T>::printOn(std::ostream & os)  //! -------- 002 [重点] 这里只是定义打印函数, 并没有重载输出运算符 <<
{                               
    for(T const & vi : v)
    {os << vi << " ";}                      //* std::ostream 就像是显示器一样
}

int main()
{
    //Stack<int> s1{12, 34, 56}; 
    Stack<int> s1;
    std::cout << s1.empty() << std::endl;
    s1.push(12);
    s1.push(34);
    s1.push(56);
    std::cout << s1.top() << std::endl;
    s1.pop();
    std::cout << s1.top() << std::endl;
    std::cout << s1.empty() << std::endl;
    s1.printOn(std::cout);                 //! --------- 003 [错误] 不知该传什么东东给printOn
}