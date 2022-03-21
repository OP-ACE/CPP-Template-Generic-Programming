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
    void  printOn(std::ostream & os);
    friend std::ostream & operator<<(std::ostream out, const Stack<T> & s);                       //! ----- [不会] 不知道friend应该在返回值左侧
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
void Stack<T>::printOn(std::ostream & os)
{                               
    for(T const & vi : v)
    {os << vi << " ";} 
}

template<class T>
std::ostream & operator<<(std::ostream & out, Stack<T> s) //! ---- [错误] 输出类型虽然知道是 std::ostream, 但是忘记了 &
{                               
    s.printOn(out);
    return out;
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
    s1.printOn(std::cout);
    std::cout << s1;
}