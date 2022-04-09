#include <utility>
#include <iostream>

class X {
  //...
};

void g (X&) 
{
  std::cout << "g() for variable\n";
}

void g (X const&) 
{
  std::cout << "g() for constant\n";
}

void g (X&&) 
{
  std::cout << "g() for movable object\n";
}

// let f() perfect forward argument val to g():
//! ----------------------------------------------------------------------------- 自动完美转发 (一个函数)
template<typename T>
void f (T&& val) {
  g(std::forward<T>(val));   // call the right g() for any passed argument val
}
//! -----------------------------------------------------------------------------------------

int main()
{
  std::cout << "\n-----------------------\n";
  X x;              // create variable
  X const cx;       // create constant

  f(x);             // f() for variable              calls f(X\&)        =>  calls g(X\&)
  f(cx);            // f() for constant              calls f(X const\&)  =>  calls g(X const\&)
  f(X());           // f() for temporary             calls f(X\&\&)      =>  calls g(X\&\&)
  f(std::move(x));  // f() for move-enabled variable calls f(X\&\&)      =>  calls g(X\&\&)
}
