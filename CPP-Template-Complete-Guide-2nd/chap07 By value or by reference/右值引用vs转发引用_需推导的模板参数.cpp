#include <iostream>
#include <string>

class A
{
// public:
//     A(){};
//     A(const A& rhs)
//     {
//         std::cout << "calling 'const A&' l-value" << std::endl;
//     }

//     A(A&& rhs)
//     {
//         std::cout << "calling ' A&&' r-value" << std::endl;
//     }
};

template <class T>
class Test
{
public:
    void test1(T&& t)
    {
        T t2(std::forward<T>(t));
    }

    template <typename U>
    void test2(U&& u)
    {
        T t2( std::forward<T>( u ) );
    }
};

int main()
{
    A a;
    Test<A> test;
    test.test1(A());
    test.test1(std::move(a));
    //test.test1(a); // this doesn't compile. error: cannot convert argument 1 from 'A' to 'A &&', You cannot bind an lvalue to an rvalue reference

    test.test2<A>(A());
    test.test2<A>( std::move( a ) );
    //test.test2<A>( a ); // this doesn't compile. error: cannot convert argument 1 from 'A' to 'A &&', You cannot bind an lvalue to an rvalue reference

}