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
    // Stack& operator= (Stack<T2> const&);
    Stack<T>& operator= (Stack<T2> const&);
  
  //! 声明谁是我的朋友
  template<typename T3>
  // friend class Stack<T3>; //! ---- [错误]
  friend class Stack;  


  //! 从来就只有这么一种格式: 注意 模板名 Stack 后没有尖括号哦
  // template <typename T>
  // class Stack
  // {}

  //! Stack<T> 要么是用于在类外定义成员, 要么用于 Stack<T> 的特化使用

};


//! 类外实现 ------------------
template<typename T>            //! ---- 001 [犯错] 丢了这行, 这样的话, top函数返回的类型为 T 引用
T const& Stack<T>::top() const  //!          类模板的成员函数, 由于返回或接收的往往也是任意类型T的入参.             
{                               //!          即, 类模板的成员函数也是模板函数, 只不过和整个类是一套模板参数
  return elems.back();
}

//! *************************** 不再是返回一个数或字符串, 这里是返回一个对象! ************************
template<typename T> //! ---- 001 [犯错] 丢了这行, 关于 T 的声明
template<typename T2>
Stack<T>& Stack<T>::operator=(Stack<T2> const& op2) //! ---- [错误] 返回类型 Stack<T2>&
{ 

  //! -------------------------- 通过公共接口访问私有数据
  // Stack<T2> copy_of_op2(op2);
  
  // this->elems.clear();
  // while (!copy_of_op2.empty())
  // {
  //   this->elems.push_front(copy_of_op2.top()); 
  //   copy_of_op2.pop();
  // }
  //! -------------------------- 友元访问私有数据
  
  this->elems.clear();
  elems.insert(elems.begin(),    //! 元素类型检查和可能的转换在这里进行
              op2.elems.begin(), //! Stack<T2> 类 (当前对象所属类型, 谁的等号, destination stack) 是 Stack<T> (source stack 等号后面的对象的类型) 的朋友
              op2.elems.end());  //! Stack<T2> 类 (当前对象所属类型, 谁的等号, destination stack) 是 Stack<T> (source stack 等号后面的对象的类型) 的朋友
  return *this;
}



int main()
{
  std::cout << "\n--------------------- stack string\n";
  Stack<std::string> stack_string;
  stack_string.push("Hello");
  stack_string.push("world");
  std::cout << stack_string.top() << std::endl;


  std::cout << "\n--------------------- stack int\n";
  Stack<int> stack_int;
  stack_int.push(1);
  stack_int.push(2);
  stack_int.push(3);
  std::cout << stack_int.top() << std::endl;

  std::cout << "\n--------------------- stack double\n";
  Stack<int> stack_double;
  stack_double = stack_int;
  std::cout << stack_double.top() << std::endl;
  stack_double.pop();
  std::cout << stack_double.top() << std::endl;
  // stack_double.push(1);
  // stack_double.push(2);
  // stack_double.push(3);
  // std::cout << stack_double.top() << std::endl;




  return 0;
  

}

