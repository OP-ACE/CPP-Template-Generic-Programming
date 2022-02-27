#include <iostream>

using namespace std;

template<class T>
void Show(T dat)
{
    cout << "----------" << endl;
    cout << dat << endl;
}

void ShowInt(int dat)
{
    Show<int>(dat);
}

int main()
{
    Show(1234);
    Show(12.34);
    Show<int>(12.34); //12
    ShowInt(12.34); //12
}