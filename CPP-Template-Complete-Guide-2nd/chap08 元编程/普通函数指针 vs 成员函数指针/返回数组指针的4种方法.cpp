#include<iostream>
 
using namespace std;

//! ---------------------- 方法1 类型别名. 这是返回数组指针最直接的一种方法了
typedef int arrT[10];//类型别名，表示含有10个整形的数组
//using arrT = int[10]; //arrT的等价声明,c++11版本新加的
 
int arry[10] = {1,3,5,4,5,11,7,13,9,20};
arrT* func_1()
{
	return &arry;
}

//! ---------------------- 方法2 后接数组维度
//! Type (*function(parameter_list))[dimension]
//! 类似于其他数组的声明，Type表示元素的类型，dimension表示数组的大小。

//! (*function(parameter_list))两端的括号必须存在, 
//! 就像下面定义p2时两端必须有括号一样, 如果没有这对括号, 返回的是指针的数组.
//! 
//! int arr[10];           // arr是一个含有10个整数的数组
//! 
//! int *p1[10];           // p1是一个含有10个指针的数组
//! 
//! int (*p2)[10] = &arr;  // p2是一个指针, 指向含有10个整数的数组
//!                        int 是数组元素的类型, 非指针类型, 
//!                        指针的类型是  int (*)[10]


//! 务必注意: int 是数组元素的类型
//! 函数的返回值是指针 vs 指针变量 *****************************
//! 函数 func_2() 返回的类型是 int (*func_2())[10] 去掉 func_2()
//! 类似                      int (*p2      )[10] 去掉 p2
int (*func_2())[10]
{
	return &arry;
}

//! -------------------- 方法3 使用尾置返回类型
//!                            用于返回类型较复杂(如数组的指针或者是数组的引用)
//!                            尾置返回类型 跟在 形参列表后面, 
//!                            以一个 -> 符开头, 后跟真正的返回类型
//!                            在本应该出现返回类型的地方放置一个auto。

auto func_3() -> int(*)[10]
{
	return &arry;
}

//! -------------------- 方法4 使用decltype
decltype(arry) *func_4()
{
	return &arry;
}

 
int main()
{
    cout << "\n-------------------- method 1 \n";

    cout << "\n-- basic test  \n";
    int (*p1)[10] = func_1();
    cout << **p1 << endl;        //! p 是数组指针, 解引用后 *p 就是所指数组 arry
                                //! 若指针变量p已指向数组中的一个元素，则p+1指向同一数组中的下一个元素，p+i和array+i就是array[i]的地址，即，指向array数组的第i个元素。
    cout << *(*p1 + 1) << endl;    //! 在p所指的数组 (*p 即 arry) 上 +1, 表示 移动指针, 指向 arry[1]


    cout << "\n-- loop print  \n";
	for(int i=0;i<10;i++)
	{
		cout << *(*p1 + i) << " " << endl;
    }

    cout << "\n-------------------- method 2 \n";
    int (*p2)[10] = func_2();
	for(int i=0;i<10;i++)
	{
		cout << (**p2)++ << " ";
	}

    cout << "\n-------------------- method 3 \n";
    int (*p3)[10] = func_3();
	for(int i=0;i<10;i++)
	{
		cout << (**p3)++ << " ";
	}

    cout << "\n-------------------- method 4 \n";
    int (*p4)[10] = func_4();
	for(int i=0;i<10;i++)
	{
		cout << (**p4)++ << " ";
	}	
	return 0;
}

// 指向数组元素的指针 vs 指向数组的指针