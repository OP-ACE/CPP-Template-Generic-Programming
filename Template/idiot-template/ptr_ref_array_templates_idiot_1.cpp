#include <iostream>

using namespace std;

template <class T>                              //!---- 001  T[] == T*; 即, T tArray[] == T* tArray
// double GetAverage(T tArray[], int nElements) //!---- 002  T 是类型形参, nElement 是非类型参数
double GetAverage(T* tArray, int nElements)     //!---- 003  T 是类型形参, nElement 是非类型参数
{
    T tSum = T(); //! 就相当于 int a = int(), float a = float();
    cout << "tSum = " << tSum << endl;
    for (int nIndex = 0; nIndex < nElements; ++nIndex)
    {
        tSum += tArray[nIndex];
    }

    return double(tSum) / nElements;
}

int main()
{
    int IntArray[5] = {100, 200, 400, 500, 1000};
    float FloatArray[3] = {1.55f, 5.44f, 12.36f};

    cout << "----------------------\n";
    cout << GetAverage(IntArray,   5) << endl;
    cout << GetAverage(FloatArray, 3) << endl;
}



// array<int, 3> a = {1, 2, 3};    // a[0] ~ a[2] = 1, 2, 3;
// array<int, 100> b = {1, 2, 3};  // b[3] ~ b[99] = 0, 0, 0 ... 0;
// array<int, 3> c;                // c[0] ~ c[2] 未初始化，是垃圾值.