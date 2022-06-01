#include <iostream>
#include <boost/type_index.hpp>
using boost::typeindex::type_id_with_cvr;
using std::cout;
using std::endl;

//! -------------------------------------------- type_is
template <class T> 
struct type_is { 
 using type = T; //!名字是type，因为是惯例 ; 但这个类型别名 type 到底是个啥 ?
}; 

template <class T> 
using type_is_t = typename type_is<T>::type; 

//! -------------------------------------------- conditional
template <bool, class T, class> 
struct conditional : type_is<T> {}; 

template <class T, class F> 
struct conditional<false, T, F> : type_is<F> {}; 

//!
int main()
{
    using myInt = conditional<true, int, double>;
    myInt x;
    cout << type_id_with_cvr<myInt::type>().pretty_name() << endl;

}