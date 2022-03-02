#include <iostream>

using namespace std;

// template<class T1, class T2>
// void PrintNumbers(const T1& t1Data, const T2& t2Data)
// {
//     cout << "-----------------\n";
//     cout << "First  number : " << t1Data << endl;
//     cout << "Second number : " << t2Data << endl;
// }

// int main()
// {
//     PrintNumbers(1, 2);
//     PrintNumbers(3, 4.5);
//     PrintNumbers(5.6, 7.8);
//     PrintNumbers<int,double>(12.34,9);
//     (nest_print<double>)<int>(12,34.56)
// }
template<class T1>
void print1(T1 a)
{
    cout << "print1 :" << a << endl;
}

template<class T1>
template<class T2>
void print1<T1>()
{   print1<T1>();
    cout << "print1 :" << typeid(T2).name() << endl;
}

template<class T1>
template<class T2>
void myprint<T1>(T1 t1)
{
    cout << "-----------------\n";
    cout << "First  number : " << t1 << endl;
    cout << "Second number : " << t2 << endl;
}

int main()
{
    myprint<int>();
}