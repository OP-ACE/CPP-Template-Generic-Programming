#include <iostream>
/*
C++ 中的 整型 （short、int、long、long long） 是有两种类型的，即有符号（signed）型与无符号（unsigned）型。

signed与unsigned区别
有符号（signed）也就是该整型可以表示正数也可以表示负数，而无符号（unsigned）则表示该整数只能表示正数，不能表示负数。

signed 存储符号是有代价的，代价就是存储空间中的一个比特位专门用来存储符号，这一位不能表示数值。一般来说，同类型的 signed 能够存储的数的绝对值大小要小于 undigned。

在我们定义变量时，如果没有显式声明是 signed 还是 unsigned，那么默认就是 signed。
*/

//!--------------------------- 类模板 DoIsPrime<p, d>, 没有偏特化
template<unsigned p, unsigned d> // p: 待检查数字, d: 当前除数
struct DoIsPrime {   // 用d到2依次去除p，对所有结果求余
  static constexpr bool value = (p % d != 0) && DoIsPrime<p, d-1>::value; 
}; 

//!--------------------------- 类模板 DoIsPrime<p, 2>, 部分偏特化
template<unsigned p> // 除数减到2为止
struct DoIsPrime<p, 2> {
  static constexpr bool value = (p % 2 != 0);
}; 

//!--------------------------- IsPrime 类模板, 调用DoIsPrime模板
template<unsigned p> // 主模板
struct IsPrime {     // 除数从p/2开始递归
  static constexpr bool value = DoIsPrime<p, p / 2>::value;
}; 

// 特殊情况 (避免模板实例化陷入无限递归):
template<>
struct IsPrime<0> { static constexpr bool value = false; }; 
template<>
struct IsPrime<1> { static constexpr bool value = false; }; 
template<>
struct IsPrime<2> { static constexpr bool value = true; }; 
template<>
struct IsPrime<3> { static constexpr bool value = true; }; 

int main()
{
    std::cout << IsPrime<9>::value;
}

/* 
IsPrime<9>
查看 IsPrime 模板定义, 调用了 DoIsPrime模板
value = DoIsPrime<9, 9 / 2>::value
value = DoIsPrime<9, 4    >::value
查看 DoIsPrime 模板的定义, 有两个定义, 一个无特化(两个参数可以是任意正整数), 一个部分特化(第二个参数必须是2), 显然这里匹配第一个
value = (9 % 4 != 0) && DoIsPrime<9, 4-1>::value, 其中, DoIsPrime<9, 3>::value 继续调用 无特化的 DoIsPrime模板, 得
value = (9 % 4 != 0) && (9 % 3 != 0) && DoIsPrime<9, 3-1>::value, 其中, DoIsPrime<9, 2>::value 继续调用 部分特化的 DoIsPrime模板, 得
value = (9 % 4 != 0) && (9 % 3 != 0) && DoIsPrime<9, 2>::value, 其中, DoIsPrime<9, 2>::value 为 true, 得
value = (9 % 4 != 0) && (9 % 3 != 0) && true
value =    true      &&   false      && true
value = false

*/
// 扩展为
DoIsPrime<9, 4>::value
// 扩展为
9 % 4 != 0 && DoIsPrime<9, 3>::value
// 扩展为
9 % 4 != 0 && 9 % 3 != 0 && DoIsPrime<9, 2>::value
// 扩展为
9 % 4!=0 && 9 % 3 != 0 && 9 % 2 != 0
// // 因为9%3为0，结果为false