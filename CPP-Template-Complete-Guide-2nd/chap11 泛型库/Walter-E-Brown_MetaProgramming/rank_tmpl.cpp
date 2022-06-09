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