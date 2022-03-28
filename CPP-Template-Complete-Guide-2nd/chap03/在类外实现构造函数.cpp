#include <iostream>
#include <string>

using namespace std;

// class A
// {
// public:
//     A(int);
//     int a_ = 0;
// };

// A::A(int a)
// {
//     a_ = a;
//     cout << "ctor def outside class";
// };


class A
{
public:
    A(int);
    int a_ = 0;
};

A::A(int a)
{
    a_ = a;
    cout << "\nctor def outside class\n" << "a = " << a << endl;
};

int main()
{
    A a(1);
}