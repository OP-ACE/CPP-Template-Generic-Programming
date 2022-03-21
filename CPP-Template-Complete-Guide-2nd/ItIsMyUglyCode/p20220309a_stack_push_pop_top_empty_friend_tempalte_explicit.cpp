#include <iostream>
#include <string>
#include <vector>

template<typename T>
using DequeStack = Stack<T, std::deque<T>>;              //! ---- 001 [新知] 熟悉的例子, 模板 DequeStack<T> === 模板 Stack<T, std::deque<T>>

template <typename T>                                    //! ---- 002 [新知] 模板 iterator<T> === 模板 std::vector<T>::iterator
struct MyType
{
    using iterator = typename std::vector<T>::iterator;  //! ---- 003 [新知] 别丢了 typename, 不是typedef
};

                                                         //! ---- 004 [新知] 如果定义了如下模板别名 Iter<T> === MyType<T>::iterator
template <typename T>                                    //! ---- 005 [新知] 模板 Iter<T> === 模板 MyType<T>::iterator
using Iter = typename MyType<T>::iterator;               //! ---- 006 [新知] 别丢了 typename, 不是typedef
//! 既然MyType后面能跟<T>,说明它是个模板, 这需前置声明

Iter<int> pos;                                           //! ---- 007 [新知] Iter是个模板,同上面的004

//! 而不必使用
typename MyType<int>::iterator pos;
