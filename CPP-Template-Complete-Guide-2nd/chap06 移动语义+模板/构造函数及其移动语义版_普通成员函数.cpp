//specialmemtmpl1.cpp
#include <utility>
#include <string>
#include <iostream>

class Person
{
  private:
    std::string name;
  public:
    //! ------------- 构造函数
    explicit Person(std::string const& n) : name(n) {
        std::cout << "copying string-CONSTR for '" << name << "'\n";
    }
    //! ------------ 构造函数 (移动语义版)
    explicit Person(std::string&& n) : name(std::move(n)) {
        std::cout << "moving string-CONSTR for '" << name << "'\n";
    }
    //! ------------- 拷贝构造
    Person (Person const& p) : name(p.name) {
        std::cout << "COPY-CONSTR Person '" << name << "'\n";
    }
    //! ------------- 拷贝构造 (移动语义版)
    Person (Person&& p) : name(std::move(p.name)) {
        std::cout << "MOVE-CONSTR Person '" << name << "'\n";
    }
};

int main()
{
  std::cout << "\n--------------------------------     构造函数 及其 移动语义版\n";
  std::string s = "sname";
  Person p1(s);              // init with string object => calls copying string-CONSTR
  Person p2("tmp");          // init with string literal => calls moving string-CONSTR

  std::cout << "\n-------------------------------- 拷贝构造函数 及其 移动语义版\n";
  Person p3(p1);             // copy Person => calls COPY-CONSTR
  Person p4(std::move(p1));  // move Person => calls MOVE-CONST
}
