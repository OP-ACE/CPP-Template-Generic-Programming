#include <iostream>
#include <string>
#include <vector>
#include <utility>

template <class T1, class T2>
class Stack
{
    public:
    std::vector<std::pair<T1, T2>> v;


    void push(T1 a, T2 b) //! ---- [错误] 没有返回值, 写void
    {
        std::pair<T1, T2> pair = std::make_pair(a, b);
        v.push_back(pair);
    }

    std::pair<T1, T2> top()
    {
        return v.back();

    }

};




int main()
{
    Stack<int,int> ps1;
    ps1.push(1,2);
    std::cout << ps1.top().first << std::endl;
}