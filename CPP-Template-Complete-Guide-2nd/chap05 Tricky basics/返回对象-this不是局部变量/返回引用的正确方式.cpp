#include <iostream>

using namespace std;

int & good_return_ref(int a, int b, int &result)
{
    result = a + b;
    return result;
}


// int & bad_return_ref(int a, int b)
// {
//     int result = a + b;
//     return result;
// }

int main()
{
    int sum;
    good_return_ref(1, 2, sum);
    cout << sum;
}