#include <iostream>

using namespace std;


class intItem
{
    int Dat;

    public:
    intItem() : Dat(0) //初始化 不需要参数
    {}

    void SetDat(int value)
    {
        Dat = value;
    }

    int GetDat() const
    {
        return Dat;
    }

    void PrintDat()
    {
        cout << Dat;
    }

};

int main()
{
    intItem item;
    item.SetDat(123);
    item.PrintDat();

}

