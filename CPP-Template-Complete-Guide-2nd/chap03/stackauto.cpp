#include <array>
#include <cassert>
#include <iostream>
#include <string>

template<typename T, auto Maxsize>
class Stack {
  public:
    using size_type = decltype(Maxsize);
  private:
    std::array<T,Maxsize> elems; // elements
    size_type numElems;          // current number of elements
  public:
    Stack();                   // constructor
    void push(T const& elem);  // push element
    void pop();                // pop element
    T const& top() const;      // return top element
    bool empty() const {       // return whether the stack is empty
        return numElems == 0;
    }
    size_type size() const {   // return current number of elements
        return numElems;
    }
};

// constructor
template<typename T, auto Maxsize>
Stack<T,Maxsize>::Stack ()
 : numElems(0)                 // start with no elements
{
    // nothing else to do
}

template<typename T, auto Maxsize>
void Stack<T,Maxsize>::push (T const& elem)
{
    assert(numElems < Maxsize);
    elems[numElems] = elem;    // append element
    ++numElems;                // increment number of elements
}

template<typename T, auto Maxsize>
void Stack<T,Maxsize>::pop ()
{
    assert(!elems.empty());
    --numElems;                // decrement number of elements
}

template<typename T, auto Maxsize>
T const& Stack<T,Maxsize>::top () const
{
    assert(!elems.empty());
    return elems[numElems-1];  // return last element
}


int main()
{
  Stack<int,20u>        int20Stack;     // stack of up to 20 ints
  Stack<std::string,40> stringStack;    // stack of up to 40 strings

  // manipulate stack of up to 20 ints
  int20Stack.push(7);
  std::cout << int20Stack.top() << '\n';
  auto size1 = int20Stack.size();

  // manipulate stack of up to 40 strings
  stringStack.push("hello");
  std::cout << stringStack.top() << '\n';
  auto size2 = stringStack.size();

  if (!std::is_same_v<decltype(size1), decltype(size2)>) {
    std::cout << "size types differ" << '\n';
  }
}
