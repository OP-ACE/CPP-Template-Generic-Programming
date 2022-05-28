#include <functional>
#include <iostream>

//! 用 成员函数  来打印
struct NomalClass {
    NomalClass(int num) : num_(num) {}
    void mem_print(int i) const { std::cout << num_+i << '\n'; }
    int num_;
};

//! 用 普通函数 来打印
void print_func(int i) {
    std::cout << i << '\n';
}

//! 用 仿函数类 来打印
struct FunctorClass {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};

int main() {
    //! 可调用对象 为 函数或函数指针
    auto *ptr_print_func = print_func;
    std::invoke(print_func, -9);
    std::invoke(ptr_print_func, -9);

    //! 可调用对象 为 lambda表达式
    std::invoke([]() { print_func(42); });

    //! 可调用对象 为 普通类的成员函数
    const NomalClass normal_class_obj(314159);

    //! 第一个实参 &NomalClass::mem_print 是指向成员函数的指针, 第二个实参用作成员函数的实参
    std::invoke(&NomalClass::mem_print, normal_class_obj, 1); //! 314160

    //! invoke 不光可以调用成员函数, 而且可以 调用 成员变量
    //! 第一个参数 &NomalClass::num_ 是 指向成员数据的指针, 调用成员数据的值. 
    std::cout << "num_: " << std::invoke(&NomalClass::num_, normal_class_obj) << std::endl; //! num_: 314159

    
    //! 可调用对象 为 仿函数类
    std::invoke(FunctorClass(), 18);
}