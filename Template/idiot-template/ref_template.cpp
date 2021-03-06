#include <iostream>

using namespace std;

template <class T>                              //!---- 001  T[] == T*; 即, T tArray[] == T* tArray
T& GetMax(T& t1, T& t2)
{
    if (t1 > t2)
    {
        return t1;
    }
    return t2;
}

template <class T>                              //!---- 001  T[] == T*; 即, T tArray[] == T* tArray
const T& GetMaxSafe(const T& t1, const T& t2)
{
    if (t1 > t2)
    {
        return t1;
    }
    return t2;
}

int main()
{
    int x = 90;
    int y = 84;

    cout << "----------------------\n";
    cout << GetMax(x,y) << endl;
    GetMax(x,y) = 80;
    cout << GetMax(x,y) << endl;

    cout << "----------------------\n";
    cout << GetMaxSafe(x,y) << endl;
    
    // GetMaxSafe(x,y) = 80;
    // error: cannot assign to return value 
    // because function 'GetMaxSafe<int>' returns a const value


}


