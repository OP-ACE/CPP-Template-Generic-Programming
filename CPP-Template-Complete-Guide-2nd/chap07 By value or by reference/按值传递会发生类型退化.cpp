#include <iostream>

using namespace std;


template <typename T>
void print_By_Value(T arg) //! 形参 arg 变成任意实参的一份拷贝，不管实参是一个对象，一个常量还是一个函数的返回值。
{
    cout << "\ntype : " << typeid(arg).name() << endl;
}

int main()
{   
    //! ------------------- 以 变量 的形式 塞入 字符串 1
    const string s = "hi";
    print_By_Value(s);    //! s 不退化

    //! ------------------- 以 变量 的形式 塞入 字符串 2
    const string cs = "hi";
    print_By_Value(cs);    //! s 退化 so that arg has type std::string

    //! ------------------- 以 字面量 的形式 塞入 字符串 3, 传生(raw)的数值和字符串要小心, 把它煮熟了放变量里会好很多
    print_By_Value("hi"); //! 退化 to pointer so that arg has type char const*
                          //! char const[3] 退化成 char const*  
                          //! void printV (char const[3] arg) {...} 退化成 void printV (char const* arg) {...}
    
    //! ------------------- 原始(raw)数组的声明, 关键是用括号 [] 来表示数组, 而非文字 arr, 下面 i_am_array 是数组名
    int i_am_array [4];
    print_By_Value(i_am_array);
}

