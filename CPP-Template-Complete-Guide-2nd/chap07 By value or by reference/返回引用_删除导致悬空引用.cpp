#include <iostream>
#include <string>

int main()
{
    std::string* s = new std::string("whatever");
    auto& c = (*s)[0];

    delete s;
    std::cout << c; //! 这里 为什么 c 成了一个悬空引用, 却不报错?
                    //! delete只是在内存里把那一段标记为可用，但是不会主动清空内容.
                    //! 你这两个操作(deelete和cout)很靠近, 所以字符串的内容还没被其他内容覆盖

}
