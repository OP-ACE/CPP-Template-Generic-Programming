#include <iostream>

#include <string>

using namespace std;

void f(int a, int b){
    cout << "\n f(int, int) \n";
}

int main(){
    f(1.2, 3.4);

    return 0;
}