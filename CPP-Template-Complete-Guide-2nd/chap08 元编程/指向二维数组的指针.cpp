#include <iostream>
#include <string>

using namespace std;

int a[3][4] = {{0, 1,  2,  3},
               {4, 5,  6,  7},
               {8, 9, 10, 11}};

int main(){
    
    int (*p)[4] = a;

    cout << "p       = " << p << endl;
    cout << "a       = " << a << endl;
    cout << "a[0]    = " << a[0] << endl;
    cout << "*(a[0]) = " << *(a[0]) << endl;

    cout << "a[1]    = " << a[1] << endl;
    cout << "(p+1)   = " <<  *(p + 1) << endl;
    cout << "(a+1)   = " <<  *(a + 1) << endl;



} 