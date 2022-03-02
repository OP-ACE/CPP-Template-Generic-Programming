#include <iostream>
#include <vector>
#include <cassert>

template<typename CT>
template<typename T>
class Stack {
  private:
    CT<T> elems;      // elements

  public:
    void push(T const& elem);  // push element
    void pop();                // pop element
    T const& top() const;      // return top element
    bool empty() const {       // return whether the stack is empty
        return elems.empty();
    }
};

template<typename T>
void Stack<T>::push (T const& elem)
{
    elems.push_back(elem);     // append copy of passed elem
}

template<typename T>
void Stack<T>::pop ()
{
    assert(!elems.empty());
    elems.pop_back();          // remove last element
}

template<typename T>
T const& Stack<T>::top () const
{
    assert(!elems.empty());
    return elems.back();       // return copy of last element
}

int main()
{
    using IntStack = Stack<int>; // typedef Stack<int> IntStack
    IntStack intStack;           // Stack<int> intStack
    intStack.push(42);
    std::cout << intStack.top(); // 42
    Stack<std::string> stringStack;
    stringStack.push("hi");
    std::cout << stringStack.top(); // hi
    stringStack.pop();
}