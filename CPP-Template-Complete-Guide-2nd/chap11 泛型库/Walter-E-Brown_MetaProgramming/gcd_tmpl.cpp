#include <iostream>
#include <assert.h>
using std::cout;
using std::endl;

//! 最大公约数（greatest common divisor，gcd）
//!     商  = 被除数  / 除数;
//!    余数 =  被除数 % 除数;

template <unsigned M, unsigned N>
struct gcd_tmpl
{
	static unsigned constexpr value = gcd_tmpl<N, M % N>::value;
};

//! ---- [新知] typename 后面的模板参数 只负责 把谁给参数化了,
//!            类模板的实例化 可能用到 这些模板参数, 模板参数的运算值入上面的M%N, 也可能完全不用, 也可能用个非模板 如 3.14
template <unsigned N>
struct gcd_tmpl< N, 0 >
{
	static_assert( N != 0);
	static unsigned constexpr value = N;
};

int main()
{
	cout << gcd_tmpl<5,3>::value << endl ;
	return 0;
}
