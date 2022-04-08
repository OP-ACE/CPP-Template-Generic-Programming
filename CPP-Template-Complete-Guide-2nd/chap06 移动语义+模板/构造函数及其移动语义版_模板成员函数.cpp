//specialmemtmpl3
#include <utility>
#include <string>
#include <iostream>
#include <type_traits>

template<typename T>
using EnableIfString = std::enable_if_t<
                         std::is_convertible_v<T,std::string>>;

class Person
{
  private:
    std::string name;
  public:
    //! --------------------------------------------------------------------------------------------- 构造函数(泛型版)
    // template<typename STR, typename = EnableIfString<STR>>
    template<typename STR>
    explicit Person(STR&& n)     //! Person p2("tmp") 在构建 p2 的时候并不会创建一个临时的 std::string 对象
    : name(std::forward<STR>(n)) //! STR 被推断为 char const[4],成员 name 将由一个以null 结尾的字符串构造
    {                            //! 
        std::cout << "TMPL-CONSTR for '" << name << "'\n";
    }

    //! 模板参数 按值传递 : 参数会退化
    //! template<typename T> 
    //! void printV (T arg) { ... }
    //! std::string const c = "hi"; printV(c); // c decays so that arg has type std::string
    //! printV("hi"); // decays to pointer so that arg has type char const*
    //! int arr[4]; printV(arr); // decays to pointer so that arghas type char const*

    //! 模板参数 按(万能)引用传递 : 参数不会退化
    //! template<typename STR>
    //! Person(STR&& n) { ... }
    
    
    //! --------------------------------
    //! 完美转发 <什么类型的> (那个参数):
    //! std::forward<STR>(n)
    //! 完美转发 类型为STR的参数n
    //! --------------------------------

    

    // copy and move constructor:
    Person (Person const& p) : name(p.name) {
        std::cout << "COPY-CONSTR Person '" << name << "'\n";
    }
    Person (Person&& p) : name(std::move(p.name)) {
        std::cout << "MOVE-CONSTR Person '" << name << "'\n";
    }
};
//! -------------------------------------------------------------------------------------------------
//!   我忘记了!!! 函数模板和类模板不同: 
//!   函数模板可以自动推导, 这时函数模板的调用方式和普通(非模板)函数的调用方式相同.
//!   即, 如果你看到一个函数被调用了 f(s) , 那么 f 可能是一个普通函数, 也可能是一个模板函数用了自动推导模式
//! --------------------------------------------------------------------------------------------------

int main()
{
  std::cout << "\n-------------------------------- Construction with passed string works ﬁne\n";
  std::string s = "sname";
  Person p1(s);              // init with string object, calls TMPL-CONSTR
  Person p2("tmp");          // nit with string literal, calls TMPL-CONSTR

  std::cout << "\n-------------------------------- 拷贝构造函数 及其 移动语义版\n";
  // Person p3(p1);             // ERROR
  Person p4(std::move(p1));  // OK: move Person =>calls MOVE-CONST
  Person const p2c("ctmp");  // init constant object with string literal
  Person p3c(p2c);           // OK: copy constant Person =>calls COPY-CONSTR
}


