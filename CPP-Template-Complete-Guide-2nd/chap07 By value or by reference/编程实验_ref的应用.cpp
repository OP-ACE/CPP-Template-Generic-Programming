#include <iostream>
#include <functional> //for std::cref/std::ref
#include <vector>
#include <list>
#include <numeric>      // std::iota
#include <random>

void f(int& n1, int& n2, const int& n3)
{
    std::cout << "In function:" << n1 << ' ' << n2 << ' ' << n3 << std::endl;
    ++n1; //函数对象的n1副本
    ++n2; //main()中的n2
    //++n3; //编译错误
}

void print_non_template(int x) //
{
    std::cout << "x = " << x << std::endl;
    ++x;
}

template<typename T>
void print_template(T x)
{
    std::cout << "x = " << x << std::endl;
    ++x;
}

template<typename T>
void printV(T s)
{
    std::cout << "s = " << s << std::endl;
}

int main()
{
    /* 1.std::ref的应用：向std::bind/std::thread按引用语义传参*/
    int n1 = 1, n2 = 2, n3 = 3;
    std::function<void()> bound_f = std::bind(f, n1, std::ref(n2), std::cref(n3));
    n1 = 10;
    n2 = 11;
    n3 = 12;

    std::cout << "Before function:" << n1 << ' ' << n2 << ' ' << n3 << std::endl;
    bound_f();
    std::cout << "After function: " << n1 << ' ' << n2 << ' ' << n3 << std::endl;
    
    /* 2. std::ref/std::cref只能用在模板函数中，在非模板函数中无法达到预期目的*/
    //2.1 非模板函数中使用std::ref传参，结果并不是预期的。无法达到模拟引用传递的目的
    int x = 0;
    print_non_template(std::ref(x)); //std::ref(x)被隐式转换为int&，再按值传入
    std::cout << "x = " << x << std::endl; //x = 0

    //2.2 在模板函数中使用std::ref传参，可以模板引用传递。
    x = 0;
    print_template(std::ref(x));
    std::cout << "x = " << x << std::endl; //x = 1

    std::string s = "hello";
    printV(s); //OK
    printV(std::ref(x)); //OK，在printV中，std::cout的重载版本:basic_ostream& operator<<( int value );
                         //会先尝试将std::reference_wrapper<int>隐式转换为int类型。因此，编译通过。
                         //即std::cout会提示std::reference_wrapper<int>隐式转换为int
    //printV(std::ref(s)); // ERROR: std::reference_wrapper<>类没有重载operator <<。而std::cout重载
                           //中并没有接受string&类型形参的版本，因此std::cout并不知如何转换
                           //std::reference_wrapper，因此编译失败。

    /* 3. std::reference_wrapper与vector */
    //vector是值语义，不支持元素为引用，可用std::reference_wrapper来解决
    std::list<int> ls(10);
    std::iota(ls.begin(), ls.end(), -4); //用连接填充ls，首元素为-4，之后元素依次自增1

    std::cout << "Contents of the list: ";
    for (int item : ls) std::cout << item << " "; std::cout << '\n';

    //vector保存着ls中元素的引用
    std::vector<std::reference_wrapper<int>> vec(ls.begin(), ls.end());

    //打乱vec列表(注意，无法打乱list，因为shuffle需要随机访问)
    std::shuffle(vec.begin(), vec.end(), std::mt19937{ std::random_device{}() });
    std::cout << "Contents of the vec: ";
    for (int item : vec) std::cout << item << " "; std::cout << '\n';

    //将vector中的元素*2；
    std::cout << "Doubling the values in the initial list...\n";
    for (int& item : vec) item *= 2;

    std::cout << "Contents of the list: ";
    for (int item : ls) std::cout << item << " "; std::cout << '\n';

    return 0;
}
/*输出结果
Before function:10 11 12
In function:1 11 12
After function: 10 12 12
x = 0
x = 0
x = 0
x = 1
Contents of the list: -4 -3 -2 -1 0 1 2 3 4 5
Contents of the vec: 4 -3 -2 2 1 3 0 -4 5 -1
Doubling the values in the initial list...
Contents of the list: -8 -6 -4 -2 0 2 4 6 8 10
*/