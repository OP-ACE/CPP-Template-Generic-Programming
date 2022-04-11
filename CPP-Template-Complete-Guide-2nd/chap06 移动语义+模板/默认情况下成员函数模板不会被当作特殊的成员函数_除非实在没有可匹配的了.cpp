#include <iostream>
#include <string>

//! Normally we can’t use enable_if<> to disable the predeﬁned copy/move constructors 
//! and/or assignment operators. The reason is that member function templates 
//! never count as special member functions and are ignored when, for example, 
//! a copy constructor is needed.
//! 即使像下面这样定义类模板, 在需要 copy 构造函数的地方依然会使用 自动生成的 copy 构造函数：

class B
{
public:
  B()
  {
    std::cout << "B Constructor!\n";
  };

  template <typename T>
  B(const T &)
  {
    std::cout << "template wanna be B's copy constructor!\n";
  }
};

//! 有一个tricky方案，可以为cv限定符修饰的实参声明一个拷贝构造函数，这样会禁止合成拷贝构造函数。
//! 再将自定义的拷贝构造函数声明为=delete，这样模板就会成为唯一选择

class C
{
public:
  C()
  {
    std::cout << "C Constructor!\n";
  };

  C(const volatile C &) = delete; // 显式声明将阻止默认合成拷贝构造函数
  //! volatile + const C & :
  //! (1)volatile: 易变的, 告诉编译器 代理（而不是变量所在的程序）可以改变该变量的值, 即 可能在 程序的控制/检测之外 被改变
  //!              告诉编译器 不要对该对象进行优化，并且总是从主内存而不是寄存器或缓存中检索
  //!              通常用const把硬件时钟 设置为程序不能更改的变量，但是可以通过代理改变，这时用 volatile。只能在声明中同时使用这两个限定符，它们的顺序不重要，如下所示：
  //!              volatile const int loc;
  //!              const volatile int * ploc;
  //! (2)编译器自动创建的复制构造函数的形参为 const C&

  template <typename T>
  C(const T &) 
  { 
    std::cout << "template wanna be C's copy constructor!\n";
  }
};


//! 接着用 enable_if 添加限制，比如 模板参数类型 为 整型时, 禁用 拷贝构造
template<typename T>
class D {
  public:
  D()
  {
    std::cout << "D Constructor!\n";
  };

  D(const volatile D &) = delete;
                                   //! 如果是整数,则忽略以下拷贝函数模板, 禁用 拷贝构造
  template < typename U, typename = std::enable_if_t< !std::is_integral_v<U> > >
  D(const D<U>&) 
  {
    std::cout << "template wanna be D's copy constructor, if not int!\n";
  }
};

int main()
{
  std::cout << "\n-------------------\n";
  B b1{};
  B b2{b1}; // 仍然使用预定义合成的拷贝构造函数，上面的模板被忽略

  C c1{};
  C c2{c1}; // 使用模板

  D<double> d1{};
  D<double> d2{d1}; // 使用模板
}



