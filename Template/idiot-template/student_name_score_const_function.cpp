#include <iostream>
#include <string>
using namespace std; 

class Student { 
public: 
  Student() {} 
  Student( const string& nm, int sc = 0 ) 
    : name( nm ), score( sc ) {} 

  void set_student( const string& nm, int sc = 0 ) 
  { 
    name = nm; 
    score = sc; 
  } 
// ! ////////////  const 可被施加于任何作用域内的对象、函数参数、函数返回类型、成员函数本体 ////////////////////
// ! 第一个const, const在&左侧, 被引对象是常量, 否则, get_name() 返回的是对私有数据成员 name 的引用，就通过这个引用可以改变私有成员 name 的值
// ! 第二个const, 是指常函数, 只读不写成员数据. 
// !             如果没有 const 修饰的话可不可以呢？回答是可以！
// !             但是这样做的代价是：const对象 将不能再 调用 这两个非const成员函数了
string const & get_name() const 
  { 
    return name; 
  } 

  int get_score() const 
  { 
    return score; 
  } 

private: 
  string name; 
  int score; 
}; 

// output student's name and score 
void output_student( const Student& student ) 
{ 
  cout << student.get_name() << endl; 
  cout << student.get_score() << endl; 
} 

int main() 
{ 
  Student stu( "Wang", 85 ); 
  output_student( stu ); 
}