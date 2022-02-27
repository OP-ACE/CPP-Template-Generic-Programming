#include <iostream>

using namespace std;

template<class T>
void PrintSize()
{
    cout << "The size of this type, sizeof(type) = " << sizeof(T) << endl;
}

int main()
{
    PrintSize<float>();
}