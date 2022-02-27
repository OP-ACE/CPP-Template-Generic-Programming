#include <iostream>

using namespace std;

template<class T>
class Item
{
    T Dat;
    
    public:
    Item() : Dat( T() ) //! 0 == int() == double()
    {}

    void SetDat(T value)
    {
        Dat = value;
    }

    T GetDat()
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
    Item<int> intItem;
    intItem.SetDat(123);
    intItem.PrintDat();
}