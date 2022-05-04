#include <iostream>
#include <string>
#include <vector>

// number of elements in a raw array:
template<typename T, unsigned N>
std::size_t len(T(&)[N])
{
  return N;
}

// number of elements for a type having size_type:
template<typename T>
typename T::size_type len(const T& t)
{
  return t.size();
}

// fallback for all other types:
//! 对所有类型的应急选项, 此处额外提供了一个通用函数 len()，它总会匹配所有的调用，但是其匹配情况也总是所有 重载选项中最差的
std::size_t len(...) // 这个省略号是参数包, 变参函数
{
  return 0;
}

int main()
{
    int a[10];
    std::cout << len(a); // OK: len() for array is best match
    std::cout << len("tmp"); //OK: len() for array is best match
    std::vector<int> v;
    std::cout << len(v); // OK: len() for a type with size_type is best match
    int* p;
    std::cout << len(p); // OK: only fallback len() matches
    std::allocator<int> x;
    std::cout << len(x); // ERROR: 2nd len() function matches best, but can't call size() for x
}

//! ---- 001 [新知]
//!          (1) 对于裸数组和 vector，都有两个函数可以匹配上，应急匹配显然不是最佳匹配。
//!          (2) 对于指针，只有应急选项能够匹配上。
//!          (3) 对于 std::allocator<int>的调用，虽然第2个和第3个函数(即,应急选项)都能匹配上，
//!              第二个函数是最佳匹配项, 尽管在第2个函数主体中,调用size()成员函数会出错.


//! ---- 002 [新知] 利用 SFINAE, 故意 SFINAE out 某个函数模板, 不让该模板参与重载解析过程
//!          随着时间的推移，SFINAE 原理在模板开发者中变得越来越重要、越来越流行，以至于这个 缩写常常被当作一个动词使用。
//!          当我们说“我们 SFINAE 掉了 (SFINAE out)一个函数”时，
//!          意思是我们 故意 通过让模板在一些限制条件下产生无效代码，
//!          从而确保在这些条件下会忽略掉该模板。
//!          当你在 C++标准里读到 "除非在某些情况下，该模板不应该参与重载解析过程"时，
//!          它的意思就是 “在该情况下，使用 SFINAE 方法 SFINAE 掉了 (SFINAE out) 这个函数模板.