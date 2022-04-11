#include <iostream>
#include <string>
#include <type_traits>

template<typename T>                                                              //! std::enable_if_t< >
using EnableIfString = std::enable_if_t< std::is_convertible_v<T, std::string> >; //! 内置类型萃取模板用法 std::is_convertible_v<FROM,TO>

//! ---- 001 [错误] 普通类的成员函数也可以是模板
class Person //! Person是个普通类, 但其成员函数是个模板
{
    public:

    //! 构造函数 是 一个模板

    template<typename STR, typename = EnableIfString<STR>>
    explicit Person(STR&& n) : name(std::forward<STR>(n))
    {std::cout << "Constructor (tempalte version)\n";}

    //! 复制构造 (const版)
    Person(const Person& p): name(p.name)
    {std::cout << "Copy Constructor\n";}
    //! 移动构造
    Person(Person && p) : name(std::move(p.name))
    {std::cout << "Move Constructor\n";}

    private:
    std::string name;

};

int main()
{
    std::cout << "\n----------------------\n";
    std::string s = "mike";
    Person p1(s);
    Person p2("tem");

    Person p3(p1);
    Person p4(std::move(p1));
    // Person p5(Person("tem_people"));

}