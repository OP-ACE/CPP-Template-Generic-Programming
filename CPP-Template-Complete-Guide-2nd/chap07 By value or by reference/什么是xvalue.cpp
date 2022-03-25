#include <iostream>

void move_test(){
    std::string s = "I'm here!";
    std::string rv  =  std::move(s);  // move from <s> to <rv>
    std::string && rv_ref  =  std::move("Hello!!");  // move from <s> to <rv>
    // s is now in an undefined, but valid state; 
    std::cout << "s=" << s << "; &s=" << &s << std::endl;
    std::cout << "rv=" << rv << "; &rv=" << &rv << std::endl;
    std::cout << "rv_ref=" << rv_ref << "; &rv_ref=" << &rv_ref << std::endl;
}


//! ---- 001 左值及其引用 或 右值及其引用 和 int, double, string 不是平行的概念, string 可以是左值也可以是右值
std::string to_rval(std::string s){
    return std::move(s);
}

std::string&& to_rval_ref(std::string s){
    return std::move(s);
}

//! ---- 002 move() 返回的是 右值, 也是 xvalue, 心里: move() <====> xvalue, 看到move就想起xvalue, 看到 xvalue就想起 move
//! ---- 003 xvalue既有身份(像左值)又很快将消失(右值)



int main()
{
    std::cout << to_rval("hello") << std::endl;
    std::cout << to_rval_ref("hello") << std::endl;
}

//! 
//! (1) "std::move(s)" : move 把他接收到的东西s转换成右值
//! (2) 

//! By moving, we can convert a named value (an lvalue,here is s) to being an rvalue(that is std::move(s)). 
//! More specifically, since it can’t be a prvalue (it has a name! In other words, it has an identity), 
//! it ends up being an xvalue.
//! xvalue always serves C++ move semantics.

// https://stackoverflow.com/questions/11581903/what-expressions-create-xvalues/66439358#66439358