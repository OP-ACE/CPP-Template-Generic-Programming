// 使用偏特化可以在编译期进行不同实现间的选择，比如根据模板实参是否为质数选择不同的实现
// 基本辅助模板
#include <iostream>
#include <string>
#include <array>

using namespace std;
constexpr bool isPrime(int n) //! ----- 005 [新知] constexpr函数 
{                             //!           丢了constexpr, non-type template argument is not a constant expression
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}

// 基本辅助模板
// template<int a_int, bool = isPrime(a_int)> //! ---- 001 [新知] 函数的返回值作为模板参数
template<int a_int, bool isprime = isPrime(a_int)> 
struct Helper;                       //! ---- 002 [新知]
                                     //!          模板参数之间可以有关联
                                     //!          第二个模板参数(非类型模板参数 true或false)的默认值 取决于 第一个模板参数
// 如果 a_int 不是质数的实现
template<int a_int>
struct Helper<a_int, false> 
{
  Helper(){
      cout << "Helper<a_int, false>" << endl;
  }
};

// 如果 a_int 是质数的实现
template<int a_int>
struct Helper<a_int, true> 
{
  Helper(){
      cout << "Helper<a_int, true>" << endl;
  }
};

template<typename T, std::size_t SZ>
long f(const std::array<T,SZ>& coll) //! ---- 006 [新知] 模板参数 未必 直接作为形参
{                                    //!          模板参数有两个:T和SZ, 但函数模板f只有一个形参 coll
  Helper<SZ> h; // 实现依赖于数组大小是否为质数
  cout << "f called" << endl;
}

int main()
{
    constexpr int i = 1;
    constexpr int j = 5;

    Helper<1> helper1 = Helper<i>();
    auto helper5 = Helper<j>();

    array<int,5> arr = array<int,5>({1,2,3,4,5});
    f(arr);
    //! ---- 003 [犯错] 非类型模板参数的参数的实参用了 int, auto helper1 = Helper<int>(); 
    //! ---- 004 helper1 = Helper<2>();
    //!          Helper<1> 和 Helper<2> 是两个类型
}

//! ---- 007 [新知] 
//!          函数模板不支持偏特化，必须使用其他机制改变函数实现，可选如下
//!          使用 带 static函数 的类
//!          使用 std::enable_if
//!          使用 SFINAE 特性
//!          使用 if constexpr（C++17）
