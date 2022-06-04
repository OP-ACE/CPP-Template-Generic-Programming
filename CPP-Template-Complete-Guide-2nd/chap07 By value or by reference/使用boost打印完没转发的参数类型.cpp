#include <iostream>
#include <utility>
#include <boost/type_index.hpp>

using namespace std;
using boost::typeindex::type_id_with_cvr;

template<typename T>
void PrintType(T&& param)
{
    // 利用Boost库打印模板推导出来的 T 类型
        cout << "T type：" << type_id_with_cvr<T>().pretty_name() << endl;

    // 利用Boost库打印形参的类型
        cout << "param type:" << type_id_with_cvr<decltype(param)>().pretty_name() << endl;
    cout<<"\n";
}


class BaseClassForTest{
    public:
        BaseClassForTest() = default;
        BaseClassForTest(const BaseClassForTest& t){
            cout<<"1\n";
        }


        BaseClassForTest(BaseClassForTest&& t){
            cout<<"2\n";
        }

};

int main(int argc, char *argv[])
{
    BaseClassForTest b1;
    BaseClassForTest& b2 = b1;
    BaseClassForTest&& b3 =  BaseClassForTest();
    PrintType(b1);
    PrintType(b2);
    PrintType(b3);
    PrintType(BaseClassForTest());


    return 0;
}
