#include <iostream>
#include <assert.h>
#include <climits>

using std::cout;
using std::endl;

template <int N>
struct abs_tmpl
{
	static_assert (N != INT_MIN);
	//! 静态变量 value
	static int constexpr value = N > 0 ? N : -N;
};

int main()
{
	cout << abs_tmpl<5>::value << endl;
	return 0;
}