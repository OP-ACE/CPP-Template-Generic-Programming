#include <cstddef>  // size_t
#include <iostream>
using std::cout;
using std::endl;

template< typename T >
struct rank 
{ 
  static constexpr size_t value = 0u; 
};


template< typename U, size_t N >
struct rank< U[N] > 
{ 
  static constexpr size_t value = 1u + rank< U >::value; 
};
//! rank<int[10][20]> matches rank<U[N]> with U=int[10] and N=20, 
//! resulting to rank<int[10][20]>::value == 1u + rank<int[10]>::value

//! At first rank<U[N]> is compiled with U = int[10][20] and N=30, 
//! then rank<int[10],20> 
//! and then rank<U[]> is compiled increasing value one more time. 



template< typename U >
struct rank< U[] > 
{ 
  static constexpr size_t value = 1u + rank< U >::value; 
};


int main() {
  using array_t1 = int[10][20][30];

  static_assert(rank< array_t1 >::value == 3);

  cout << rank< array_t1 >::value << endl;

  using array_t2 = int[][20];
  static_assert(rank< array_t2 >::value == 2);
}



