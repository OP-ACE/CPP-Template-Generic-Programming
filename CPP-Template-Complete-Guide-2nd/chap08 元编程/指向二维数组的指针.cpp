#include <iostream>
#include <string>

using namespace std;

int a[2][3] = {{0, 1,  2},   // p     指向第 1行 矢量(子矩阵)
               {3, 4,  5} }; // p + 1 指向第 2行 矢量(子矩阵)

int main(){
    
    int (*p)[3] = a;

    cout << "\n---- p points to a[0] (a[0][0])\n";
    cout << " p         =  " <<  p           << endl;
    cout << " a         =  " <<  a           << endl;
    cout << " &a[0]     =  " <<  &a[0]       << endl;
    cout << " &a[0][0]  =  " <<  &a[0][0]    << endl;

    cout << "\n---- p+1 points to a[1] (a[1][0])\n";
    cout << " **(p + 1)         =  " <<  **(p + 1)          << endl;
    cout << " a + 1         =  " <<  a + 1         << endl;
    cout << " &a[0]     =  " <<  &a[0]       << endl;
    cout << " &a[0][0]  =  " <<  &a[0][0]    << endl;



} 