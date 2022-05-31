#include <iostream>
using std::endl;
using std::cout;

template <typename TKey, typename TData>
class MyClass
{
public:
    using key_t = TKey;
    using data_t = TData;
    TKey key;
    TData data;
    MyClass(TKey _key, TData _data) : key(_key), data(_data) {  }
};

// int main() {
//     MyClass<int, float> mc{1, 1.0f};
//     using DataType = typename mc.data_t; //error: expected ';' after alias declaration
//     mc.data_t newData = 2.0f; //error: Cannot refer to type member in 'MyClass<int,float> with '.'

//     return 0;
// }

int main() {
    MyClass<int, float> mc{1234, 98.76f};
    using DataType = typename MyClass<int,float>::data_t;
    MyClass<int,float>::data_t newData = 2.0f;

    using my_class_t = decltype(mc);
    using data_t = my_class_t::data_t;
    data_t newData_2 = 2.0f;

    std::cout << mc.data << std::endl;
    std::cout << mc.key << std::endl;

    mc.key = 9876;
    cout << mc.data << endl;
    cout << mc.key  << endl;

    int i = 1;
    cout << i << endl;

    i = i + 1;
    cout << i << endl;

    return 0;
}

