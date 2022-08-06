#include <iostream>
#include <string>

//! ---------------------------------------- CTRP 的样子
// template<typename T>
// class Base
// { };

// class Derived : public Base<Derived>
// {};

// int main()
// {
//     Derived d;
// }

template<typename T>
class Tool
{
    public:
    void PlotImpl()
    {
        puts("Default Tool plotting");
    }

    void Plot()
    {
        static_cast<T*>(this) -> PlotImpl(); //! CTRP 多态的关键
    }

    private:
    Tool();
    friend T;
    // 子类初始化时一定会先调用基类的构造函数
    // 这里把基类的构造函数封装成私有 + 但其友元(其参数化的类)可以访问构造函数
    // 其它类想调用这个私有构造函数会再编译期报错
};

class Pen : public Tool<Pen> //! 如何防止手滑写成 class Pen : public Tool<Brush> 
{                            //!                 Brush是特化后的T, 所以可以访问Tool的私有构造函数, 但Pen不能访问
    public:
    void PlotImpl() 
    { 
        puts("Pen plotting"); 
    }
};

class Pencil : public Tool<Pencil>
{};

class Brush : public Tool<Brush> 
{
    public:
    void PlotImpl()
    {
        puts("Brush plotting");
    }
};

template<typename T>
void PlotUse(Tool<T> &tool) //! 也可以使用对实参类型更宽松

{
    tool.Plot();
};

int main()
{
    Pen pen;
    Pencil pencil;
    Brush brush;

    PlotUse(pen);
    PlotUse(pencil);
    PlotUse(brush);

}