#include <iostream>
#include <utility>
#include <functional>

// template<typename Callable, typename... Args>
// decltype(auto) call(Callable&& op, Args&&... args)
// {
//   return std::invoke(std::forward<Callable>(op),
//                      std::forward<Args>(args)...);
// }

template<typename Callable, typename... Args>
decltype(auto) call(Callable&& op, Args&&... args)
{ //! 初始化局部变量 ret
  //! 
  struct cleanup {
  ~cleanup()
  {
    std::cout << "to fix decltype(auto) for void type" << "\n";
  }
  } dummy;
  decltype(auto) ret{std::invoke(std::forward<Callable>(op),
                                 std::forward<Args>(args)...)};
  return ret;
}


//! 1. 不能 通过把ret声明为auto&& 来返回 临时对象, 因为 
//!    右值引用 Auto&& 仅仅能将 临时变量的生命周期 扩展到作用域的末尾, 
//!    但是不会扩展到 超出 return 的地方, return 结束, 临时变量消亡

//! 2. 即使使用 decltype(auto) 返回临时对象, 也有一个问题: 
//!    如果函数对象返回void类型, 因为 void 是一个不完整的类型, 
//!    所以 把 ret 初始化为 decltype(auto) 是不允许的

//! 3. 解决方法 (1) 
//!    一个解决方法是在那条语句之前声明一个 dummy 对象，该对象的析构函数执行希望实现的可观察的行为


//! 4. 解决方法 (2) 
//!    使用 if constexpr 分别实现 void 和非 void 的情况



//! Std::invoke()的常规用法:
//! 包裹/封装 单个函数调用 ((如:记录相关调用, 测量所耗时长)) , 
//! 为了支持返回引用（如std::ostream&）, 使用decltype(auto)替代auto 
//! 此时, 可以通过 完美转发 可调用对象以及被传递的参数 来支持 移动语义.


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
  NomalClass normal_class_obj(314159);

  std::invoke(&NomalClass::int_mem_print , normal_class_obj, 1); //!
  std::invoke(&NomalClass::void_mem_print, normal_class_obj, 1); //! 
  
         call(&NomalClass::int_mem_print , normal_class_obj, 1);
       //call(&NomalClass::void_mem_print, normal_class_obj, 1); //! error
         call(print_func,1);
}