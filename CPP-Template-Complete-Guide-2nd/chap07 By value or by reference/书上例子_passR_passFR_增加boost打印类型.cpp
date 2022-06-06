#include <iostream>
#include <string>
#include <typeinfo>
#include <boost/type_index.hpp>
using boost::typeindex::type_id_with_cvr;
//! ---- [犯错] 001. 要么 using namespace std; 要么使用 using std::cout
//!                  namespace后面只能跟空间名称,如 std; 而不能跟函数名称 如 std::cout.
using std::cout; 
using std::endl;

template <typename T>
void printR(T & arg)
{
    cout << type_id_with_cvr< decltype(arg)>().pretty_name() << endl;
    // cout << typeid(T).name();
    cout << type_id_with_cvr< T            >().pretty_name() << endl ;
}

template <typename T>
void printCR(T const & arg)
{
    cout << type_id_with_cvr< decltype(arg)>().pretty_name() << endl;
    // cout << typeid(T).name();
    cout << type_id_with_cvr< T            >().pretty_name() << endl ;
}

int main()
{
    std::string returnString();
    std::string s = "hi";
    int i = 1;

    printR(s);
    //! printR(std::move(s));      //error 按左值引用传递, 却给了右值
    //! printR(std::string("hi")); //error 按左值引用传递, 却给了右值
    //! printR(returnString());    //error 按左值引用传递, 却给了右值
    printR(i);

    printCR(s);
    // printCR(std::move(s));
    // printCR(std::string("hi"));
    // printCR(returnString());
    // printCR(i);

    return 0;

}


