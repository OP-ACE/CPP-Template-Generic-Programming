#include <iostream>
#include <string>
#include <memory>   //为调用 shared_ptr


int main()
{
    auto s = std::make_shared<std::string>("whatever");

    std::cout << s.use_count() << std::endl;

    auto &c = (*s)[0];
    
    s.reset();

    std::cout << c << std::endl; // run-time ERROR
    
    std::cout << s.use_count() << std::endl;
}
