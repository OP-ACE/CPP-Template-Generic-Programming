#include <iostream>
#include <string>

template <typename T, unsigned N>
std::size_t len(T(&)[N])
{
    return N;
};

template<typename T>
typename T::size_type len(const T& t)
{
    return t.size();
}

int main()
{
    int i = 1;
    int j = 2;
    int &int_ref = i; //! ---- 000 [误解] 我一直以为&的位置比较随便, 定义引用是 & 在 引用名 前面, 不能用 int int_ref& = i;
    std::cout << int_ref << std::endl;            //! ---- 005 [犯错] 别名无需解引用
    //! int &int_ref = j;                         //! ---- 004 [犯错] a 是 b 的别名: 是 a& = b, 非 a& = &b ; 
    //! std::cout << &(int_ref) << std::endl;
    //! ----- 003 [犯错] 引用不能被重新绑定

    int a[3] = {7, 8, 9};
    int (&a_ref)[3] = a; //! ---- 001 [犯错] int (&a_ref)[3] = &a ; 我混淆了指针, 指针的值才是地址

    std::cout << a[1];   //! ---- 002 [犯错] int (a_ref&)[3] = a  ;
}                        