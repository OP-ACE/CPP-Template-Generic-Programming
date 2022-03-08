#include <iostream>
#include <string>
#include <vector>

// 写一个类 叫 Stack<T> 
// 属性: std::vector<T> v
// 方法: void  push(T a); 
//       void  pop(); 
//       bool  empty();
//       T     top(); 




template<class T>
class Stack
{
    private:
    std::vector<T> v;

    public:
    void  push(T a);
    void  pop();
    bool  empty();
    T     top();
    void  printOn(std::ostream & os) const;
                                                                           //! ---- 001 [错误] 这里 operator<< 就是一个随Stack特化的普通函数, 而非模板.
    friend std::ostream& operator<<(std::ostream& out, const Stack<T> & s) //! ---- 002 [错误] 如果 A和B都是模板, A和B的特化是独立的, 即 各自有各自的模板参数, 而非同一个模板参数
    {                                                                      //! ---- 003 [错误] operator要操作常量 s, 就只能用常函数来操作常量s, 即 printOn 必须得是常函数
        s.printOn(out);                                                    //!                 这个错误卡了我挺久, 因为 s 是常量, 但printOn 却不是常函数. 
        return out;                                                        //!                 常量对象上面不能执行 非 常量成员函数.    
    }    

};                                                                                 

template<class T>
void Stack<T>::push(T a)
{                                
    v.push_back(a);               
}

template<class T>
void Stack<T>::pop()
{                                
    v.pop_back();
}

template<class T>
bool Stack<T>::empty()
{
    return v.empty();            
}

template<class T>
T Stack<T>::top()
{                               
    return v.back();
}

template<class T>
void Stack<T>::printOn(std::ostream & out) const
{                               
    for(T const & vi : v)
    {out << vi << " ";} 
}


int main()
{
    //Stack<int> s1{12, 34, 56}; 
    Stack<int> s1;

    std::cout << "\n---------------- \n";
    std::cout << s1.empty();

    s1.push(12);
    s1.push(34);
    s1.push(56);
    std::cout << "\n---------------- \n";
    std::cout << s1.top();

    s1.pop();
    std::cout << "\n---------------- \n";
    std::cout << s1.top();
    std::cout << s1.empty();

    std::cout << "\n---------------- \n";
    s1.printOn(std::cout);

    std::cout << "\n---------------- \n";
    std::cout << s1;
}