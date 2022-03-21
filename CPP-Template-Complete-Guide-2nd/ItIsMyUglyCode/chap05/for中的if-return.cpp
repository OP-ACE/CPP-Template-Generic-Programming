#include <iostream>

using namespace std;

string test_return_in_for(int a, int b)
{
    for (int i = 0; i < a && i < b; ++i)
    {
        if (a<b) return "- 1st return\n";
        if (b<a) return "- 2nd return\n";
    }
    return "- 3rd return";
}

template<typename T, int M, int N> //! 共3个模板参数: T 类型参数, N, M 非类型参数
bool less_array(T(&a) [M], T(&b) [N])
{
    for (int i = 0; i < M && i < N; ++i)
    {
        cout << "i =" << i << endl;
        if (a[i] < b[i]) return true;
        if (b[i] < a[i]) return false;
    }
    return M < N;
}

int main()
{
    cout << "\n**************\n";
    cout << test_return_in_for(1,2);

    cout << "\n**************\n";
    int x1[] = {0, 0, 1, 2};
    int y1[] = {0, 0, 2, 3};
    cout << less_array(x1, y1) << endl;
    //! 在较小的数组耗尽时, 若第一数组中有小于第二个数组的元素, 则说 M < N

    int x2[] = {0, 0, 0};
    int y2[] = {0, 0, 0, 0};
    cout << less_array(x2, y2) << endl;
    //! 小数组耗尽时, 两个数组的元素都是相等的, 则第一个是小数组, 则说 M < N
    

   

}