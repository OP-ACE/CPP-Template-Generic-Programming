#include <iostream>

template <typename T>
class A
{
    public:
    void get_dat()
    {
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
    }
    private:
    T x;
    T y{}; //! 成员变量原地初始化
};

template <typename T>
class B
{
    public:
    B():x(), y{}
    {}

    void get_dat()
    {
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
    }
    private:
    T x;
    T y; //! 成员变量原地初始化
};


template <typename T>
class C
{
    public:
    
    C(B<T> in = B<T>::B()) //! 不能这样初始化构造参数 : C(B<T> in{}) 
    {}

    void get_info()
    {
        dat.get_dat();
    }
    private:
    B<T> dat;
};


int main()
{
    std::cout << "\n-------------- A\n";
    A<int> a;
    a.get_dat();

    std::cout << "-------------- B\n";

    B<int> b;
    b.get_dat();

    std::cout << "-------------- C \n";

    C<int> c(b);
    c.get_info();

    return 0;
};

