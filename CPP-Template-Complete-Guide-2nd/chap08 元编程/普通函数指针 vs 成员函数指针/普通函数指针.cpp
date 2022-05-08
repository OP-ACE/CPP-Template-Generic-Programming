#include <iostream>

using namespace std;

int test(int a)
{
    return a;
}

int plus1(int n)
{
    return n + 1;
}

int apply_plus1_to_a_int(int (*plus1_ptr)(int), int n)
{
    cout << "apply_plus1_to_a_int :" << plus1_ptr(n) << endl;
    return plus1_ptr(n);
    
}

void t1(){cout<<"t1"<<endl;}
void t2(){cout<<"t2"<<endl;}
void t3(){cout<<"t3"<<endl;}
 
int main(int argc, const char * argv[])
{

    //! ---- 001 [新知] typedef
    //!          (1) typedef 简化 函数指针的定义
    //!          (2) typedef int INTEGER ; 我还傻傻地以为都是这么个用法
    //!          (3) typedef int arr6[6] ; 用 arr6 代替 int [6], 即：arr6 six_elem_arr; 等于 int six_elem_arr[6];
    //!          (4) 对比: int (*fp)(int) 与 int (*fp_arr[5])(int)
    //!                    fp       :一个函数(输入一个int, 输出一个int)的指针
    //!                    fp_array :一个包含5个元素的数组, 每个元素均为函数(输入一个int, 输出一个int)的指针
    
    //! ---- 002 [新知] 定义一个函数(输入int,输出int)指针 fp
    typedef int (*fp)(int);

    //! ---- 003 [新知] 函数(test)的地址就是其函数名(test)
    fp f = &test; //! 也可以用 
    cout << f(2) << endl;

    //! ---- 004 [新知] 传递 函数指针, 即, 函数指针 作 形参
    typedef int (*PLUS1_PTR) (int);

    PLUS1_PTR plus1_ptr = plus1;
    apply_plus1_to_a_int(plus1_ptr,10);


    //! ---- 005 [新知] 函数指针数组

    typedef void (*vfp)(void); // void func pointer
    vfp b[] = {t1,t2,t3}; // b[] 为一个指向函数的指针数组
    b[0](); // 利用指向函数的指针数组进行下标操作就可以进行函数的间接调用了
    
    return 0;

}