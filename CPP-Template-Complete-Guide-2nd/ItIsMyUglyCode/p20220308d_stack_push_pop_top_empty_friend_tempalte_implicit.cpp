#include <iostream>
#include <string>
#include <vector>

template<class T>
class Stack
{
    private:
    std::vector<T> v;

    public:
    void  push(T a);
    void  printOn(std::ostream & os) const;

    template <typename U>
    friend std::ostream& operator<< (std::ostream& out, const Stack<U> & s);

};      

//! 如果在类外定义友元，因为类模板参数不可见，事情会复杂很多
//! 有两个解决方案: 
//! (1) 是隐式声明一个新的函数模板，并使用不同的模板参数, 本程序中的 operator<<
//! (2) 是将友元前置声明为模板，但是由于友元参数中包含类模板，这样就必须先前置声明类模板


//! 类外定义 非成员友元函数模板
template<typename T>
std::ostream& operator<< (std::ostream & out, const Stack<T> & s) //! ---- [错误] 丢了 &, 造成ambiguous You are just omitting the &, 
{                                                                //!       use of overloaded operator '<<' is ambiguous 
    s.printOn(out);                                              //!       (with operand types 'std::ostream' (aka 'basic_ostream<char>') and 'Stack<int>')
    return out;                                                  //!       which makes the operator<< inside and outside the class have different function signatures, 
}                                                                //!       they are both valid for std::cout << s1, hence the ambiguity

template<class T>
void Stack<T>::push(T a)
{                                
    v.push_back(a);               
}


template<class T>
void Stack<T>::printOn(std::ostream & out) const 
{                               
    for(T const & vi : v)
    {out << vi << " ";} 
}


int main()
{
    Stack<int> s1;
    s1.push(12);
    s1.push(34);
    s1.push(56);
    std::cout << s1;
}
