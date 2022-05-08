//! 数组元素 是 函数指针 的数组 叫做 函数指针数组(或 转移表)

//! 初始化格式
//! 返回类型 (*函数指针数组名[])(参数列表) = {函数指针/函数名，…};
//! 如:  int (*fun_array[])(int,int) = {add,del,mul,div};





#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
 
int func1(int n)
{
    printf("func1: %d\n", n);
    return n;
}
 
int func2(int n)
{
    printf("func2: %d\n", n);
    return n;
}



int main()
{
    cout << "\n ---------------- arr \n";
    int (*arr[2])(int); //!定义一个2元素的数组 a : 保存了 两个函数指针

    arr[0] = func1;
    arr[1] = func2;
    arr[0](1);
    arr[1](2);

    cout << "\n ---------------- typedef: two_ele_func_ptr_arr \n";
    typedef int (*two_ele_func_ptr_arr[2])(int);
    two_ele_func_ptr_arr b = {func1, func2};
    b[0](1);
    b[1](2);

    cout << "\n ---------------- typedef: func_ptr_arr \n";
    typedef int (*func_ptr_arr[ ])(int);
    func_ptr_arr c = {func1, func2};
    c[0](1);
    c[1](2);
    
 
    return 0;
}