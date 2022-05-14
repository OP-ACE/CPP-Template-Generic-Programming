#include <iostream>
    
using namespace std;
    
int main()
{
    int i = 1, j =2;
    int * p = &i; 
    int * q = &j;
    p++;
    p = q + 1;
    
    int arr1[3] = {1, 2, 3}; 
    int arr2[3] = {4, 5, 6};
    arr1 + 1;

    //! The array name is converted into a pointer to the first element of the array, 
    //! but that pointer is not an lvalue (it's a prvalue) 
    //! 怎么理解上面说的 arr1 指针是纯右值呢?
    //! and therefore cannot be used on the left side of an assignment statement.
    cout << &arr1;
    arr1 = arr2 + 1; // incompatible types in assignment of 'int*' to 'int [3]'

    
    // cin >> array2;
    
    return 0;
}

