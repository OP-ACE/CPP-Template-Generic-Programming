#include <iostream>

int i = 1;

struct R {
  int i;
  R(): i(2) { }
};

template<typename T>          //! 模板参数 T (1) 用作 S的父类 (2) 参数化了S类, 即 自定义类 T 参数化了 S类的父类
struct S: T {
  void f() {
    std::cout << i << ' '     // selects  ::i
              << this->i      // selects R::i; //! 父类 R 的属性i有默认值 2
              << std::endl;
  }
};

int main() {
  S<R>().f();
}