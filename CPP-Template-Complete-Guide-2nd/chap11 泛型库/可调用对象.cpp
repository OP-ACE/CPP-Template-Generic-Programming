#include <iostream>
#include <vector>

template < typename Iter, typename Callable >
void foreach(Iter current, Iter end, Callable op)
{
    while (current != end )
    {
        op(*current);
        ++current;
    }
}

void func(int i)
{
    std::cout << i << "\n";
}

struct FuncObj
{
    void operator()(int i) const   //! 调用 一个对象的""函数调用运算符()", 可能改变该对象的成员数据, 所以要用 const
    {
        std::cout << i << "\n";
    }

};

int main()
{
    int i = 1;
    int* pi = &i;
    std::cout << "*pi = " << *pi << ", pi = " << pi << "\n";

    std::vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 }; 
    //! 按值传递时, 数组退化成指针, 函数退化成指针.
    //! 函数名作为函数实参, 则实际传递的是 函数指针, 
    //! 就像数组一样, 按值传递时, 函数名 退化为 函数指针
    //! 如果不想退化成指针, 可以用 按引用传递, 但函数的引用要用 non const 的引用, 而不能是const型的引用. 
    //! 即, 如果你的函数想以 按const引用调用我的函数, 即, your_func(callable const &) 调用 your_func(my_func_name) 时, 形参中的const会被忽略 或 叫退化
    //! 应该  your_func(callable const), 就可以调用了: your_func(my_func_name)
    //! 
    //! function as callable (decays to pointer)
    //!   When we pass the name of a function as a function argument, 
    //!   we don’t really pass the function itself but a pointer or reference to it. 
    //!   As with arrays, function arguments decay to a pointer when passed by value
    foreach(primes.begin(), primes.end(), func);              
                                                              
                                                              
                                                              

    foreach(primes.begin(), primes.end(), &func);             //! function pointer as callable; 对整型变量取值就得到该变量的指针, 对函数取址就得到该函数的指针
    foreach(primes.begin(), primes.end(), FuncObj());         //! 调用一个类 [ FuncObj ]的对象 [ FuncObej() ]的 "函数调用运算符()", 即, FuncObj()().
                                                              //! 

    foreach(primes.begin(), primes.end(), [] (int i) {        //! lambda as callable
                             std::cout << i << '\n'; });
}