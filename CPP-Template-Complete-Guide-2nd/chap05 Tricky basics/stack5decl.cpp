#include <iostream>
#include <deque>

template <typename T>
class Stack {
  private:
    std::deque<T> elems;       // elements

  public:

  // 类内实现
    void push(T const& a)       // push element
    {
      elems.push_back(a);
    }

  // 类内实现
    void pop()                // pop element
    {
      elems.pop_back();
    }

  //! 类外实现
    T const& top() const;      // return top element

    bool empty() const {       // return whether the stack is empty
        return elems.empty();
    }

  //! 类外实现 assign stack of el!ements of type T2
  //! 本类是 参数化 为 T 模板, 等号右侧的类是另一套模板 T2
    template <typename T2>
    Stack& operator= (Stack<T2> const&);
};


//! 类外实现 ------------------
template<typename T>            //! ---- 001 [犯错] 丢了这行, 这样的话, top函数返回的类型为 T 引用
T const& Stack<T>::top() const  //!          类模板的成员函数, 由于返回或接收的往往也是任意类型T的入参.             
{                               //!          即, 类模板的成员函数也是模板函数, 只不过和整个类是一套模板参数
  return elems.back();
}


int main()
{
  std::cout << "\n---------------------stack string\n";
  Stack<std::string> stack_string;
  stack_string.push("Hello");
  stack_string.push("world");
  std::cout << stack_string.top() << std::endl;


  std::cout << "\n---------------------stack int\n";
  Stack<int> stack_int;
  stack_int.push(1);
  stack_int.push(2);
  stack_int.push(3);
  std::cout << stack_int.top() << std::endl;



  return 0;
  

}

