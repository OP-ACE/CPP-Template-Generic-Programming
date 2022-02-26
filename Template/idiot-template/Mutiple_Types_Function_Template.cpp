#include <iostream>

using namespace std;

template<class T1, class T2>
void PrintNumbers(const T1& t1Data, const T2& t2Data)
{
    cout << "-----------------\n";
    cout << "First  number : " << t1Data << endl;
    cout << "Second number : " << t2Data << endl;
}

int main()
{
    PrintNumbers(1, 2);
    PrintNumbers(3, 4.5);
    PrintNumbers(5.6, 7.8);
}