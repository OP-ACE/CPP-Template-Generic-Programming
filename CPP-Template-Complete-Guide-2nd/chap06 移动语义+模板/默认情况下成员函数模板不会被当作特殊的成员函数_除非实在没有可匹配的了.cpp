#include <iostream>
#include <string>

// https://github.com/downdemo/Cpp-Templates-2ed/blob/master/content/Part1%20%E5%9F%BA%E7%A1%80/06%20%E7%A7%BB%E5%8A%A8%E8%AF%AD%E4%B9%89%E4%B8%8Eenable_if.md
//! 即使像下面这样定义类模板, 在需要 copy 构造函数的地方依然会使用 自动生成的 copy 构造函数：

class C {
  public:
  C(){
    std::cout << "Constructor!";
  };
  
  template<typename T>
  C(const T&) 
  {std::cout << "template want to be the copy constructor!";
  }
};

int main()
{
  C c1{};
  C c2{c1}; // 仍然使用预定义合成的拷贝构造函数，上面的模板被忽略
}
