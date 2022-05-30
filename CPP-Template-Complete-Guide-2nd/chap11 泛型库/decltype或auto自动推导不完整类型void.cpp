// auto with decltype for trailing return type (尾置返回类型) 
// don't work for a void return type 
// because void is an incomplete type.
// https://stackoverflow.com/questions/30315649/how-to-handle-void-decltype


//! 1.A  虽然 auto 可以用推导 前置的 void类型
auto nothingMuch()
{
    return;
}

//! 1.B  但是 auto 不能推导 后置的 void 类型
// auto noTrailing() -> decltype(void {})
// {

// }

//! 2. decltype 不能推导 void 类型
// decltype(void {}) nothingMuchEither()
// {
//  return;
// }



//! 3. decltype和auto的组合, 总是可以推导 void类型, 无论前置或后置. always works
decltype(auto) nothing()
{
    return;
}

auto main() -> decltype(int {})
{
    nothing();
    nothingMuch();
    return 0;
}