#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class my_vec_box
{
public:
    vector<T> content;
};



template <typename ET, typename CT> // ET : element type, CT : container type
class my_box_wrong
{
public:
    //CT<ET> content; //! error: 'CT' is not a template
};



template<typename CT >
class my_box_naive
{
public:
    CT    mContent;
};


// 容器类型 和 数据类型 分开指定



template<typename ET, 
         template<typename CT> class container >
class my_box
{
public:
    container<ET>    content;
  //std::vector<int>
};



int main()
{
    my_vec_box<int> box;
    vector<int> myvec = box.content;
    myvec.push_back(1);
    cout << "-----------" << endl;
    cout << myvec[0] << endl;

    
    // my_box_naive< std::vector<int> > vec_int_naivebox;

    cout << "-----------" << endl;
    my_box<int, std::vector> vec_int_box;
    // auto vec2 = vec_int_box.content.push_back(1);
    // cout << vec2[0] << endl;

}


// template<    typename DType,
//             template<typename T> class TContainer >
// class CData
// {
// public:
//     TContainer<DType>    mContent;
// };

// template<typename T>
// class CVector : public std::vector<T>
// {};

// CData<int, CVector> x;

// #include <iostream>
// template<template<typename T> class TFunc>
// void FuncTemp(int iMode)
// {
//     if (iMode == 0 )
//     {
//         TFunc<int>()();
//     }
//     else if ( iMode == 1 )
//     {
//         TFunc<float>()();
//     }
// }

// template<typename T>
// class CFunc1
// {
// public:
//     void operator()(){
//     }
// };

// template<typename T>
// class CFunc2
// {
// public:
//     void operator()(){
//     }
// };

// int main()
// {
//     FuncTemp<CFunc1>(1);
//     FuncTemp<CFunc2>(0);
// }
