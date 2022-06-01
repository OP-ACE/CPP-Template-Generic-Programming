// remove_cv_0.cpp
#include <iostream>
#include <boost/type_index.hpp>
using boost::typeindex::type_id_with_cvr;
using std::cout;
using std::endl;

//! ------------------------------------------------------------------------------ remove const
// primary defination.
template<class T>
struct remove_const {
    using type = T;
};
// partial specialization
template<class T>
struct remove_const<T const> {
    using type = T;
};

//! ------------------------------------------------------------------------------ remove volatile
// primary defination
template<class T>
struct remove_volatile{
    using type = T;
};
// partial specialization
template<class T>
struct remove_volatile<T volatile> {
    using type = T;
};

//! ------------------------------------------------------------------------------ remove const + remove volatile
template<class T>
struct remove_cv { 
    using type = typename remove_const< typename remove_volatile<T>::type >::type;
};                                  //! typename remove_volatile<T>::type : 声明后面这一坨 remove_volatile<T>::type 是个类型
                                    //! 不要以为 所有出现在模板中的typename 就是 模板参数
                                    //! 不要一看到模板 就忘了 typename最原始的作用: 声明他后面的一坨为一种类型


int main(int argc, char *argv[])
{   //!   type_id_with_cvr<remove_cv 是个函数模板, 所以用法为  type_id_with_cvr<remove_cv<特化类型>()                           
    cout << "remove_cv<int> = " << type_id_with_cvr<remove_cv<int>::type >().pretty_name() << endl;
    cout << "remove_cv<const int> = " << type_id_with_cvr<remove_cv<int>::type >().pretty_name() << endl;
    cout << "remove_cv<int const> = " << type_id_with_cvr<remove_cv<int>::type >().pretty_name() << endl;
    cout << "remove_cv<int volatile> = " << type_id_with_cvr<remove_cv<int>::type >().pretty_name() << endl;
    cout << "remove_cv<int const volatile> = " << type_id_with_cvr<remove_cv<int>::type >().pretty_name() << endl;
    return 0;
}