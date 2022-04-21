#include <iostream>
#include <utility>
#include <string>
#include <vector>

template <typename T>
class A
{
public:
    template <typename U>
    void af(T&& t, U&& u) // void af(U&& u)
    {
        T t2( std::move(t) ); // or should it be std::move(t)? is T&& forwarding or r-value reference
        U u2( std::forward<U>(u) ); // or should it be std::move(u)? I believe U&& is forwarding reference
    }
};


template <typename T>
class B
{
public:
    template <typename U>
    void bf(U&& u)
    {}
};

template<typename T>
void rval_ref(std::vector<T>&& par1)       //! 例1: par1是右值引用
{std::cout << "rvalue ref" << std::endl;}

template<typename T>
void fwd_ref(T&& par2)                     //! 例2: par2是转发型引用
{std::cout << "forward ref" << std::endl;}


template <class T>
class A
{
    template <class U>
    void foo(T&& t, U&& u);                //! 例3: T是右值引用, u 是转发型引用
};
//! only U&& is a forwarding reference, because U is the only template argument that's being deduced. 

int main()
{
    // A<std::string> strA;
    // A<B> bA;

    int i = 1;
    int j = 2;

    A<int> a_int;

    a_int.af<int>(std::move(i), std::move(j));

    std::vector<int> vec_int = {1,2,3};

    

    rval_ref(std::move(vec_int));
    rval_ref(std::forward<int>(vec_int));

    fwd_ref(std::move(vec_int));
    fwd_ref(std::forward<int>(i));


    // B<int> b_int;

    // b_int.bf<int>( std::move( i ) );
}