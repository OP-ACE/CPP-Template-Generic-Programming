
// https://zhuanlan.zhihu.com/p/366736087

//! ---------------------------------------------------------------------------------------------------- 001 模板参数可以是模板
// template<class Type, template<class> class PatchField, class GeoMesh>
//! 共3个模板参数 (1) Type, (2) PatchField (3) GeoMesh, 第2个模板参数 PatchField 本身也是一个类模板
//  inline const typename Foam::GeometricField<Type, PatchField, GeoMesh>::Boundary& 
//! 内联函数, 返回值是const, typename 告诉编译器 Foam::GeometricField<Type, PatchField, GeoMesh>::Boundary 是个类型
//  Foam::GeometricField<Type, PatchField, GeoMesh>::boundaryField() const
//  {
//      return boundaryField_;
//  }

//! ----------------------------------------------------------------------------------------------------- 002 同时参数化(实例化)多个类模板
// template<class Type>
// ! 用 Type 同时参数化 两个类模板 : (1) Foam::SolverPerformance (2) Foam::fvMatrix<Type>::solveSegragated
// ! 参数(实例)化得到第一个模板类  Foam::SolverPerformance<Type> 用作 第二个模板类的返回值类型
// Foam::SolverPerformance<Type> Foam::fvMatrix<Type>::solveSegragated // ! 这是一个函数模板, 因为没有class关键字
// ! 如何这个函数模板? reuslt = Foam::fvMatrix<面1和面3上的点>::solveSegragated(求解控制字典文件)
// (
//     const dictionary& solverControls
// )





//! ----------------------------------------------------------------------------------------------------- 003 模板参数Type 更多地被用来 实例化要用到的类模板
template<class Type>
void Foam::fvMatrix<Type>::addBoundarySource 
//! fvMatrix<Type> 不是 fvMatrix<Type a, Type b> 模板参数的名字a,b,可能不会被用到，这时可以被省略掉. 见TemplateCompleteGuide的5.5节
(
    Field<Type>& source, //! 初学模板时,简单函数模板的定义, 模板形参Type 往往被用作 函数形参的类型 myadd(Type a, Type b)
    const bool couples   //! 这里模板参数Type 后无需形参 a, b, 这是由于OF高度的封装, 对a,b怎么计算不用用户管, 用户只需根据自己的需求来实例化其它多个类模板
) const                  //! 
{
    forAll(psi_.boundaryField(), patchi)
    {
        const fvPatchField<Type>& ptf = psi_.boundaryField()[patchi];
        const Field<Type>& pbc = boundaryCoeffs_[patchi];

        if (!ptf.coupled())
        {
            addToInternalField(lduAddr().patchAddr(patchi), pbc, source);
        }
        else if (couples)
        {
            const tmp<Field<Type>> tpnf = ptf.patchNeighbourField();
            const Field<Type>& pnf = tpnf();

            const labelUList& addr = lduAddr().patchAddr(patchi);

            forAll(addr, facei)
            {
                source[addr[facei]] += cmptMultiply(pbc[facei], pnf[facei]);
            }
        }
    }
}





//! ----------------------------------------------------------------------------------------------------- 004 模板参数Type 更多地被用来 实例化要用到的类模板
//! 首先一点, 和上面的例子相同, 模板参数名a,b都没有被使用
template<class Type>
template<class Type2>
void Foam::fvMatrix<Type>::addToInternalField //! 多层模板参数 (f<int>)<double> vs 多个模板参数 f(int, double)
(                                             //! 怎么举一个这样的例子呢? 外层模板参数限定函数模板名称addToInternalField的名称空间, 内存模板参数才是其形参
    const labelUList& addr,                   //! 所以我感觉,只要会多个名称空间就好了, 学会名称空间来试试.
    const Field<Type2>& pf,
    Field<Type2>& intf
) const
{
    if (addr.size() != pf.size())
    {
        FatalErrorInFunction
            << "addressing (" << addr.size()
            << ") and field (" << pf.size() << ") are different sizes" << endl
            << abort(FatalError);
    }

    forAll(addr, facei)
    {
        intf[addr[facei]] += pf[facei];//intf是diag
    }
}



