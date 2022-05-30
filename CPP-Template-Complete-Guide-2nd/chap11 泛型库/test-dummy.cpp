#include <iostream>
#include <utility>
#include <functional>

//! Confusions from C++ Templates the complete guide 2ed, section 11.1.3.
//! My ugly minimum code to show why dummy obj is necessary. 




// template <typename T>
// decltype(auto) void_tmpl_func(T arg)
// {
//   return 1;
// }

decltype(auto) a_int_func(int arg)
{
  return 1;
}

template <typename funcType, typename argType>
decltype(auto) deco_tmpl_func(funcType&& func, argType&& arg)
{
  struct DUMMY  
  {
    ~DUMMY(){std::cout << " DUMMY class and its object dummy exist only for print info before return \n";}
  } dummy; //! 去掉则出错, 为什么?

//   return temp=void_func();
//   return std::invoke(void_tmpl_func<T>,1);
// return std::invoke(func, arg);
    // decltype(auto) ret{std::invoke(std::forward<funcType>(func), std::forward<argType>(arg))};
    // return ret;
    return std::invoke(std::forward<funcType>(func), std::forward<argType>(arg)); // this works

}


auto main() -> decltype(int {})
{
    
    deco_tmpl_func(a_int_func,1);
    return 0;
}

//! =========================== 原来我完全误解了 C++ 模板一书中的意思:
//! 书中的意思是说: 返回为 void 时, 用户什么都看不到啊, 所以 用这个 dummy 来输出一些能看到(原文中的 observable)的信息
//! 比如说: 现在的输出是 void, 不是说程序没有运行, 是运行了, 但输出为 void 哦
//! 我之前错误地理解为: 要想自动推导出 void 类型, 必须得有生成一个 dummy 对象