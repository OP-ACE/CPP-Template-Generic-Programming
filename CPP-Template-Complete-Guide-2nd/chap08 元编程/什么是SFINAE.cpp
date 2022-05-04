#include <iostream>
#include <string>
#include <vector>

template <typename T, unsigned N>  //! ---- [新知] 参数T必须是一个具有N个元素、类型为T的数组
std::size_t len(T(&)[N])
{
    return N;
};

template<typename T>                  //! ---- [新知] 对参数 T 进入时 没有限制, 但返回时必须有size_type成员
typename T::size_type len(const T& t) //! ---- [犯错] 001 注意这里 typename的用法: 它不是用于模板参数的关键字, 而是用于类型定义的关键字
{
    return t.size();
}

// The C++ grammar is horrendous, and as such it is not possible, 
// when given a template class, 
// to know whether the ::node you refer to is a variable/constant or a type.
// The Standard therefore mandates that you use typename before types to remove this ambiguity, 
// and treats all other usages as if it was a variable.
// Thus  
// template <typename T, int degree> 
// typename btree<T,degree>::node* btree<T,degree>::findLead(T const& value) 
// ^~~~~~~~ 
// is the correct signature for the definition.


int main()
{
    int a[10];                            // OK：a 是个数组, 第1个模板匹配; 
    std::cout << len(a) << std::endl;     // 但第2个模板匹配时会发生错误, T = int[10], 但 T 没有size_type成员, int[10]::size_t 出错
                                          // 实际调用过程中, 我们也没有收到错误信息, 这就是 SFINAE

    std::cout << len("tmp") << std::endl; // OK：只有第1个模板匹配, 道理同上

    std::vector<int> v;                   // OK：只有第2个模板匹配
    std::cout << len(v); 
} 