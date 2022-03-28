#include <iostream>
#include <deque>

template<typename T, typename Cont = std::deque<T>>
class Stack 
{
  private://! 任意类型的容器 Cont
    // Cont container;   
    std::deque<T> container;            

  public://! 任意类型的元素 T
    void push(T const& a)
    {
      container.push_back(a); //! queue, deque, vector 中均有 push_back() 成员方法
    }

    void pop()
    {
      container.pop_back();
    }

    T const& top() const
    {
      return container.back();
    }

    bool empty() const {
        return container.empty();
    }

    //! 不同堆模板是朋友
    template<typename T2, typename Cont2> // 在   template<typename, typename> 的前面加了1个限定词 friend
    friend class Stack;          //      class Stack;
   
    //! 不同堆模板可复制, 类外实现
    template<typename T2, typename Cont2>
  //Stack<T, Cont>& Stack<T, Cont>::operator= (Stack<T2,Cont2> const&); //! ----- 001 [犯错] 类内定义成员函数, 成员函数前无需限定词
    Stack<T, Cont>&                 operator= (Stack<T2,Cont2> const&); // 完整版
 // Stack&                          operator= (Stack<T2,Cont2> const&); // 简写版
    
};

template<typename T1, typename Cont1>  //! 第1套模板
template<typename T2, typename Cont2>  //! 第2套模板
Stack<T1, Cont1>& Stack<T1, Cont1>::operator= (Stack<T2, Cont2> const& source_stack)
{
  container.clear();                            // 容器需支持 clear() 方法
  container.insert(container.begin(),           // 容器需支持 begin() 方法
               source_stack.container.begin(),  // 容器需支持 begin() 方法
               source_stack.container.end()     // 容器需支持 end()   方法
              );

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