#include <iostream>

#include <string>
/*
There are different levels of template specialization:

1) Template declaration (no specialization)

template <class Key, class Value>
struct Foo {};
2) Partial specialization

template <class Key>
struct Foo<Key, int> {};
3) Full/explicit specialization

template <>
struct Foo<std::string, int> {};
Then, when instantiating the templates, the compiler will choose the most specialized definition available:

Foo<std::string, std::string> f1; // Should match #1
Foo<int,         int>         f2; // Should match #2
Foo<std::string, int>         f3; // Should match #3
#1 and #3 work for template functions as well.
*/

//! ---- 错误 001 愚笨的我居然把下面的类模板当成了函数模板, 然后直接在类模板中写输出语句!
//! template <class Key, class Value>
//! struct A 
//! {
//!     cout << "no specialization" << endl;
//! };


using namespace std;

template <class Key, class Value>
struct A 
{ 
    A<Key, Value>()
    {
        cout << "no specialization" << endl;
    }
    
};

template <class Key>
struct A<Key, int> 
{
    A<Key, int>()
    {
        cout << "partial specialization" << endl;
    }

};

template <>
struct A<int, int> 
{
    A<int, int>()
    {
        cout << "full specialization" << endl;
    }
};

int main()
{
    cout << "\n----------------------------------\n";
    A<string, string> tml_no_spec;
    A<string, int>    tml_parial_spec;
    A<int, int>       tml_full_spec;
}


