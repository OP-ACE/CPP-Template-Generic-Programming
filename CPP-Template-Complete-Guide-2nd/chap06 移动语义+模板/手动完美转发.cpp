#include <utility>
#include <iostream>

class X {
  //...
};

void g (X&) {
  std::cout << "g() for variable\n";
}
void g (X const&) {
  std::cout << "g() for constant\n";
}
void g (X&&) {
  std::cout << "g() for movable object\n";
}

// let f() forward argument val to g():
//! ----------------------------------------------------------------------- 手动完美转发 (n个函数)
void f (X& val) {
  g(val);             // val is non-const lvalue => calls g(X\&)
}
void f (X const& val) {
  g(val);             // val is const lvalue => calls g(X const\&)
}
void f (X&& val) {
  g(std::move(val));  // val is non-const  lvalue => needs std::move() to call g(X\&\&)
}
//! -----------------------------------------------------------------------------------

int main()
{
  X x;              // create variable
  X const cx;        // create constant

  f(x);             // f() for nonconstant object calls f(X\&)  =>  calls g(X\&)
  f(cx);             // f() for constant object calls f(X const\&) =>  calls g(X const\&)
  f(X());           // f() for temporary calls f(X\&\&)  =>  calls g(X\&\&)
  f(std::move(x));  // f() for movable variable calls f(X\&\&)  => calls g(X\&\&)
}
