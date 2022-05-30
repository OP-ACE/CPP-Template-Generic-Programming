#include <iostream>
#include <utility>
#include <functional>


template<typename Callable, typename... Args>
decltype(auto) decorator(Callable&& func, Args&&... args)
//! 1. decorator 是个函数模板, 参数1: 任意一个函数(可调用对象), 参数2: 这个函数的arguments, 用decltype(auto)自动推导函数模板的返回值类型
{ 
  //! 2. 在装饰器函数模板中 定义并生成一个 dummy对象: 是为了 decltype(auto) 不能推导 void 类型
  //!    initialization of ret as decltype(auto) is not allowed, because void is an incomplete type
  //!    "The void type is an incomplete type that cannot be completed", that's what makes it different than any other incomplete type. 
  //!    You cannot declare a variable of type void because variables must have object type or be references, 
  //!    extern void x doesn't declare a reference, and void is not an object type.
  //!    int x 可以; 但不能 void x;
  struct cleanup {
  ~cleanup()
  {
    std::cout << "to fix decltype(auto) for void type" << "\n";
    std::cout << "code to perform on return" << "\n";
  }
  } dummy; 
  
  //! 3. 这里 通过 invoke 调用了 被修饰的函数func 及其 arguments 并 获得 func(arguments) 的值
  decltype(auto) resutl_of_func{std::invoke(std::forward<Callable>(func),
                                std::forward<Args>(args)...)};
  return resutl_of_func;

}


std::string print_func(int i) {
    std::cout << i << '\n';
    return "call print_func";
}

struct NomalClass {
    NomalClass(int num) : num_(num) {}
    int   int_mem_print(int i)  { std::cout << num_+i << '\n'; return i;}
    void void_mem_print(int i)  { std::cout << num_+i << '\n'; return;}
    int num_;
};

int main()
{
  //void x; //! error: 不允许使用不完整的类型
  NomalClass normal_class_obj(314159);

  std::invoke(&NomalClass::int_mem_print , normal_class_obj, 1); //!
  std::invoke(&NomalClass::void_mem_print, normal_class_obj, 1); //! 
  
    decorator(&NomalClass::int_mem_print , normal_class_obj, 1);
  //decorator(&NomalClass::void_mem_print, normal_class_obj, 1); //! error
    decorator(print_func,1);
}