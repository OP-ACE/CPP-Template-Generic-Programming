#include <iostream>
#include <typeinfo>

using namespace std;

template <class T, class U>
class A
{
public:
    int x;
};

template <class U>
class A<int, U>
{
public:
    short x;
};

template< template<class T, class U>  class V > //! V是一个类模板 V<>
class B //! B是一个类模板, 模板参数本身也是一个类模板 V, 记住: B的实例化需要一个类模板
{
public:
    V<int, char> i;
    V<char, char> j;
};

B<A> c; //! 用 类模板A 实例化 类模板B

// template<class W>
// template< template<class T, class U>  class V > 
// class B 
// {
// public:
//     V<W, char> i;
//     V<char, char> j;
// };

// B<int><A> c; 

int main()
{
    cout << typeid(c.i.x).name() << endl;
    cout << typeid(c.j.x).name() << endl;
}