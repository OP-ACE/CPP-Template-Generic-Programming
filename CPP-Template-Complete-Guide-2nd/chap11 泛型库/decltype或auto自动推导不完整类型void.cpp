// auto with decltype for trailing return type (尾置返回类型) 
// don't work for a void return type 
// because void is an incomplete type.
// https://stackoverflow.com/questions/30315649/how-to-handle-void-decltype
#include <iostream>
#include <utility>
#include <functional>

//! 1.A  虽然 auto 可以用推导 前置的 void类型
auto nothingMuch()
{
    return;
}

//! 1.B  但是 auto 不能推导 后置的 void 类型
// auto noTrailing() -> decltype(void {})
// {

// }

//! 2. decltype 不能推导 void 类型
// decltype(void {}) nothingMuchEither()
// {
//  return;
// }



//! 3. decltype和auto的组合, 总是可以推导 void类型, 无论前置或后置. always works

decltype(auto) void_func()
{
  return;
}

template <typename T>
decltype(auto) void_tmpl_func(T arg)
{
  // struct DUMMY 
  // {
  //   ~DUMMY(){}
  // } dummy_obj; //! 去掉则出错, 为什么?

  return void_func();
}


auto main() -> decltype(int {})
{
    void_func();
    void_tmpl_func(1);
    return 0;
}

// template <typename T>
// decltype(auto) notingTmplFunc(T arg)
// {
//   std::cout << "notingTmplFunc called \n";

//   // decltype(auto) temp_obj{nothing()}; // error: variable or field 'temp_obj' declared void
//   // return temp_obj;
// }

// notingTmplFunc(1);


// template <typename T>
// decltype(auto) somethingTmplFunc(T arg)
// {
//   decltype(auto) temp_obj{nothing()}; // error: variable or field 'temp_obj' declared void
//   return arg;
// }