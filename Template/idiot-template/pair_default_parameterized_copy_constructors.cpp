
#include <iostream>

using namespace std;

template<class T1, class T2>
struct Pair
{
    T1 first;
    T2 second;

    Pair():first(T1()), second(T2())
    {}; //! 默认构造函数

    Pair(const T1& a, const T2& b) : first(a), second(b){}; 
    //! 参数化构造函数
    //! 
    //!            这里的const 均值 被引对象是常量
    //! ------ 001 没有常引用,即,没有引用自身是常量
    //!            Why no const reference in C++ just like const pointer?
    //!            References cannot be modified. 
    //!            Adding const qualification to non-modifiable entity would be meaningless and confusing.
    
    Pair(const Pair<T1, T2>& OtherPair) : first(OtherPair.first), second(OtherPair.second)
    {};
    //! 注意上面初始化列表的格式:标点符号
    //! 形参OtherPair的类型为 Pair<T1,T2>
    //! 拷贝构造函数

    

};

int main()
{
    Pair<int, int>  p1;
    p1.first = 12;
    p1.second = 34;

    Pair<int, double>  p2;
    p2.first = 12;
    p2.second = 34.56;

}