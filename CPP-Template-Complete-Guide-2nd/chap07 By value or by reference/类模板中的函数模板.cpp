#include <iostream>
#include <utility>
#include <string>

template <typename T>
class A
{
public:
    template <typename U>
    void af(T&& t, U&& u) // void af(U&& u)
    {
        // T t2( std::forward(t) ); // or should it be std::move(t)? is T&& forwarding or r-value reference
        // U u2( std::move(u) ); // or should it be std::move(u)? I believe U&& is forwarding reference
    }
};

// struct B{};

template <typename T>
class B
{
public:
    template <typename U>
    void bf(U&& u)
    {}
};

int main()
{
    // A<std::string> strA;
    // A<B> bA;

    int i = 1;
    int j = 2;

    A<int> a_int;

    a_int.af<int>(std::move(i), std::move(j));


    // B<int> b_int;

    // b_int.bf<int>( std::move( i ) );
}