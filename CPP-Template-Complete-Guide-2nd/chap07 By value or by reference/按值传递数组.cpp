#include <iostream>
#include <string>

int main()
{
    char buff[3] = {0, 0, 0};
    // char x[3] = buff; //error
    char *y = buff;                      // ok - pointer
    std::cout << "size of y : " << sizeof(y) << std::endl;
    
    char(&z)[3] = buff;                  // ok - reference
    std::cout << "size of z : " << sizeof(z) << std::endl;

    auto a = buff;                       // a is a pointer - a is same as y (above)
    std::cout << "size of a : " << sizeof(a) << std::endl; // sizeof(a) == sizeof(char*)
    //4 //size of the pointer


    auto &b = buff;                      // b is a reference to the array - b is same as z (above)
    std::cout << "size of b : " << sizeof(b) << std::endl; // sizeof(b) == sizeof(char[3])
    // 3 //size of the array of 3 chars

}
