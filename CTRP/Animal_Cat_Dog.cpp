#include <iostream>

using namespace std;

// ! ---------- 类型 animal<子类类型形参specific_animal> 的定义, 这个类可以有其成员函数 -----------
template <typename specific_animal> // ! 形参是多个实参的统一名称, 形参的类型 typename就用了这一次
struct animal  // ! animal<specific_animal>的定义; 
{              // ! 这是一个类型, 用于子类的具体操作,即 f(类型 子类形参)
    void who() // ! animal<#>.who()的定义, 对形参#进行操作
    {
        static_cast<specific_animal*>(this) -> who();
        // 函数主体中不能出现 animal<specific_animal>
        // 只能出现 形参 specific_animal
    }
};

template <typename specific_animal> 
void who_am_i(animal<specific_animal>& some_animal) // ! who_am_i(输出参数的类型是animal<#>)
{         //! 这个函数就是要对形参操作
    some_animal.who();
};

// !  (1)接下来就子类可以用这个类型了,无论定义还是调用 只能 用做一种类型
// !  (2)定义时: template <typename 子类形参类型>; 
// !            class animal<子类形参类型> {对子类形参类型的操作}
// !  (3)调用时: animal<子类实参类型>, animal<子类实参类型> 



struct dog : animal<dog> // ! dog 是子类类型的实参
{
    void who()
    {
        cout << "dog" << endl;
    }
};

int main()
{
    dog d;
    who_am_i(d);
}