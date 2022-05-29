#include <utility>
#include <functional>

// template<typename Callable, typename... Args>
// decltype(auto) call(Callable&& op, Args&&... args)
// {
//   return std::invoke(std::forward<Callable>(op),
//                      std::forward<Args>(args)...);
// }

template<typename Callable, typename... Args>
decltype(auto) call(Callable&& op, Args&&... args)
{ //! 初始化局部变量 ret
  decltype(auto) ret{std::invoke(std::forward<Callable>(op),
                     std::forward<Args>(args)...)};
  return ret;
}