#include <iostream>
#include <iostream>
#include <boost/type_index.hpp>
using std::cout;
using std::endl;
using boost::typeindex::type_id_with_cvr;
//! ------------------ type_is 模板元函数, 你给我什么类型，我就给你什么类型
template <class T> 
struct type_is { 
 using type = T; //名字是type，因为是惯例 
 int two = 2;
}; 

template <class T> 
using type_is_t = typename type_is<T>::type; 

//! ------------------- enable_if 
//! 主模板 接收一个bool变量和一种类型，然后我将该类型返回给你。T的缺省参数为void，这不是必要的，但实践证明这很有用。 
template <bool , class T = void>
struct enable_if : type_is<T> {}; //! 继承了type_is<T>的 : 表示继承, 类主体为空

//! 偏特模板, 如果bool变量是false，那么我什么也不给你！！！
template <class T>
struct enable_if<false, T>{}; 

int main()
{
    //! --------------------------------------- 你不能直接就把 类型 ( 如 int ) 放到 cout << 后面 -----------
    //! cout << int << endl; // error
    //! cout << enable_if<true, int>::type << endl; // error
    cout << typeid(enable_if<true, int>::type).name() << endl;
    cout << type_id_with_cvr< enable_if<true, int>::type >().pretty_name() << endl;
    //! --------------------------------------------------------------------------------------------------


    //! --------------------------------------- using type = .. 是模板类的共有数据, 是静态的 ---------------
    //!                                         而 int two 是模板类 的 对象 实体 的数据, 是动态的
    //! cout << enable_if<true, int>::two << endl; // 错误提示: 非静态成员引用必须与特定对象相对
    cout << enable_if<true, int>().two << endl;
    //! --------------------------------------------------------------------------------------------------

}