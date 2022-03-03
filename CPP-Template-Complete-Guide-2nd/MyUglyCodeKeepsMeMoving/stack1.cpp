#include <iostream>
#include <vector>
#include <cassert>

template<typename T>
class Stack {                          // Stack<T> 类模板, 用了 标准库中的类模板 vector<T>
  private:
    std::vector<T> elems;              // 私有数据

  public:
    void push(T const& elem);          // 成员函数1 push  声明

    void pop();                        // 成员函数2 pop   声明

    T const& top() const;              // 成员函数3 top   声明

    bool empty() const                 // 成员函数4 empty 定义
    {      
        return elems.empty();
    }
};

template<typename T>           
void Stack<T> :: push (T const& elem)  // 在类外 定义 成员函数1 push
{
    elems.push_back(elem);     
}

template<typename T>
void Stack<T>::pop ()                  // 在类外 定义 成员函数2 pop
{
    assert(!elems.empty());
    elems.pop_back();                  
}

template<typename T>
T const& Stack<T>::top () const        // 在类外 定义 成员函数3 top
{
    assert(!elems.empty());
    return elems.back();
}

int main()
{
    using IntStack = Stack<int>;
    IntStack intStack;
    intStack.push(42);
    std::cout << intStack.top(); // 42
    Stack<std::string> stringStack;
    stringStack.push("hi");
    std::cout << stringStack.top(); // hi
    stringStack.pop();
}