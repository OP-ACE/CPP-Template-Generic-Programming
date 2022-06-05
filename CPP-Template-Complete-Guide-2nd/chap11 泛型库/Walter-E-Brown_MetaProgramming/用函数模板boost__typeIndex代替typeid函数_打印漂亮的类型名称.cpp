#include <iostream>
#include <typeinfo>
#include <boost/type_index.hpp>


using namespace std;

template<typename T>
static void PrintType_typeid(const T &t)
{
    std::cout << "T: " << typeid(T).name() << std::endl;
    std::cout << "t: " << typeid(t).name() << std::endl;
}

template<typename T>
static void PrintType(const T &t)
{    
    cout << "T: " << boost::typeindex::type_id_with_cvr<T>().pretty_name() << endl;
    cout << "t: " << boost::typeindex::type_id_with_cvr<decltype(t)>().pretty_name() << endl;
    cout << "typeid: " << boost::typeindex::type_id_with_cvr<decltype(typeid(int))>().pretty_name() << endl;
}


class Foo {};

int main()
{
    cout << "1: " << typeid(1).name() << endl;
    cout << "int: " << typeid(int).name() << endl; // 和 sizeof 操作符类似，typeid 也可以直接对数据类型（比如 int）进行操作

    cout << "typeid: " << typeid(typeid(int)).name() << endl;
    cout << "typeid: " << typeid(const type_info &).name() << endl;

    const Foo *foo = new Foo();
    cout << "foo: "  << typeid(foo).name() << endl;
    cout << "*foo: " << typeid(*foo).name() << endl;
    cout << "Foo: "  << typeid(Foo).name() << endl;

    const int *p_1;
    PrintType_typeid(p_1);

    const int *p_2{ nullptr };
    PrintType(p_2);
}

