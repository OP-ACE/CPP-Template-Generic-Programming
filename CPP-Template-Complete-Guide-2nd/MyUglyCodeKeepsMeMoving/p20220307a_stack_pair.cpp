#include <iostream>
#include <string>
#include <vector>
#include <utility>

// 写一个类 叫 Stack<T1, T2>
// 属性: std::pair<T1, T2> m_p
// 方法:  void                push(T1 a, T2 b);
//        std::pair<T1, T2>   top();
//       不实现 printOn()

// template<class T1, class T2>
// class Stack
// {
//     public:
//     std::pair<T1, T2> m_p;

//     public:
//     void                push(T1 a, T2 b);
//     std::pair<T1, T2>   top();
//     // void  printOn(std::ostream & os);
// };

// template<class T1, class T2>
// void Stack<T1, T2>::push(T1 a, T2 b)
// {
//     m_p.push({a, b});
// };

// template<class T1, class T2>
// std::pair<T1, T2>  Stack<T1, T2>::top()
// {
//     return std::pair::(a, b);
// };

// typedef std::vector<Product> ProductList;

// class ProductList
// {
//     public:
//     std::vector<std::pair<std::string, double>> dat;

//     std::ostream & operator<<(std::ostream & os, const ProductList & pl )
//     {

//     }
// };



class Product
{
public:
    std::pair<std::string, double> item;
    
    Product(std::string name, double price)
    {
        item = std::make_pair(name, price);    
    }
};

std::ostream &operator<<(std::ostream &os, const Product &product) //! ---- 001 [错误] 非成员函数, 不能在类内定义
{
    os << product.item.first << " : " << product.item.second << " yuan \n";
    return os;
}

class ProductList
{
public:
    std::vector<Product> list;
    
    void push(Product product)
    {
        list.push_back(product);
    }

    Product top()
    {
        return list.back();
    }
};


int main()
{
    Product pd_apple("apple ", 6.50);
    Product pd_banana("banana", 9.00);

    ProductList pl1;
    pl1.push(pd_apple);
    pl1.push(pd_banana);
    std::cout << pl1.top() << std::endl;
}