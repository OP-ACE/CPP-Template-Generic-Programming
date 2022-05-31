#include <iostream>
#include <type_traits>

template <typename T>
struct Selector
{
    constexpr static const char* value = "default";
};

template <typename T>
struct Selector<T&>
{
    constexpr static const char* value = "reference";
};

template <typename T>
struct Selector<const T&>
{
    constexpr static const char* value = "constref";
};

int main()
{
    std::cout << Selector< std::remove_const<const int&>::type >::value << std::endl;

    return 0;
}

// int main()
// {
//     int a = 42;
//     std::remove_const<const int&>::type b(a);

//     // This assertion fails
//     static_assert(
//         !std::is_same<decltype(b), const int&>::value,
//         "Why did remove_const not remove const?"
//     );

//     return 0;
// }