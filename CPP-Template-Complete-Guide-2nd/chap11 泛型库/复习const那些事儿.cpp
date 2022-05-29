#include <iostream>
#include <string>

int main()
{

    const int    ci        = 123 ;
    const int & cri        = ci  ; 
      //! int &  ri        = ci  ; // 
       
//! 总是 类型 + &/* , 没有 &/* + 类型, 不像 const + 类型 = 类型 + const
    

          int           j  = 456 ; 
    const int &       rcj  = j   ; //! 1. "所指对象是常量", const 在 & 左侧, primer 上 把 & 左侧的 const 叫做 : 底层 const
 // int const &       rcj  = j   ; //!    亦可

                   // rcj  = 789 ; //!    错误;所指对象是常量, 并不是真的说所指的对象 j 本身是个常量, 
                                   //!    而是说,   在这个引用看来, 所指对象 是个 常量, 
                                   //!    也就是说, 就是不能通过 我这个指针 rcj 来修改 所指对象的值. 
       // int & const crj  = j   ; //! 2. 错误, 引用本身就是常量 , 无需 不用const修饰. const 在 * 右侧, 指针本身必须在初始化时就绑定对象, 而且一旦绑定就不能再更换, 毕竟是别名啊,
                                   //!    所以, const 只能出现在 & 左侧
                                   //!    提示错误: 'const' qualifiers cannot be applied to 'int&'


    const int * pcj        = &j  ; //! 1. "所指对象是常量", const 在 * 左侧 
           // * pcj        = 654 ; //!     所指对象是常量, 并不是真的说所指的对象 j 是个常量, 而是说, 不能通过 pcj 修改所指对象的值.
          int * const cpj  = &j  ; //! 2.  指针本身是常量 , const 在 * 右侧
              * cpj        = 789 ;
    const int * const cpcj = &j  ; //! 

}


