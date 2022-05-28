// basics/foreachinvoke.hpp

#include <utility>
#include <functional>
#include <iostream>
#include <vector>
#include <string>

template<typename Iter, typename Callable, typename... Args>
void foreach (Iter current, Iter end, Callable op, const Args&... args)
{
  while (current != end)
  {
    std::invoke(op, args..., *current);
    ++current;
  }
}


class A {
 public:
  void mem_func(int i) const
  {
    std::cout << i << '\n';
  }
};

int main()
{
  std::vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 };
  foreach(primes.begin(), primes.end(), // 范围内的元素是lambda的第二个参数
    [](std::string const& prefix, int i) {
      std::cout << prefix << i << '\n';
    },
    "value: "); // lambda的第一个参数
  
  A obj;
  foreach(primes.begin(), primes.end(), &A::mem_func, obj);
}