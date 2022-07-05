




















typedef __char16_t char16_t;
typedef __char32_t char32_t;

namespace std { inline namespace __1 { } }

































typedef long int ptrdiff_t;

typedef long unsigned int size_t;










namespace std { inline namespace __1 {

struct __attribute__ ((__type_visibility__("default"))) nullptr_t
{
    void* __lx;

    struct __nat {int __for_bool_;};

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) nullptr_t() : __lx(0) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) nullptr_t(int __nat::*) : __lx(0) {}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) operator int __nat::*() const {return 0;}

    template <class _Tp>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        operator _Tp* () const {return 0;}

    template <class _Tp, class _Up>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        operator _Tp _Up::* () const {return 0;}

    friend __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) bool operator==(nullptr_t, nullptr_t) {return true;}
    friend __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) bool operator!=(nullptr_t, nullptr_t) {return false;}
};

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) nullptr_t __get_nullptr_t() {return nullptr_t(0);}



} }


namespace std { inline namespace __1 {

using ::ptrdiff_t;
using ::size_t;






typedef long double max_align_t;


} }




namespace std
{

}








namespace std { inline namespace __1 {

template <class _T1, class _T2> struct __attribute__ ((__type_visibility__("default"))) pair;
template <class _Tp> class __attribute__ ((__type_visibility__("default"))) reference_wrapper;
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) hash;

template <class _Tp, _Tp __v>
struct __attribute__ ((__type_visibility__("default"))) integral_constant
{
  static const _Tp value = __v;
  typedef _Tp value_type;
  typedef integral_constant type;
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
                    operator value_type() const throw() {return value;}




};

template <class _Tp, _Tp __v>
                  const _Tp integral_constant<_Tp, __v>::value;

typedef integral_constant<bool,(true)> true_type;
typedef integral_constant<bool,(false)> false_type;

template <bool _Val>
using _BoolConstant = integral_constant<bool, _Val>;

template <bool> struct _MetaBase;
template <>
struct _MetaBase<true> {
  template <class _Tp, class _Up>
  using _SelectImpl = _Tp;
  template <template <class...> class _FirstFn, template <class...> class, class ..._Args>
  using _SelectApplyImpl = _FirstFn<_Args...>;
  template <class _First, class...>
  using _FirstImpl = _First;
  template <class, class _Second, class...>
  using _SecondImpl = _Second;
  template <class _Tp = void>
  using _EnableIfImpl = _Tp;
  template <class _Result, class _First, class ..._Rest>
  using _OrImpl = typename _MetaBase<_First::value != true && sizeof...(_Rest) != 0>::template _OrImpl<_First, _Rest...>;
  template <class _Result, class _First, class ..._Rest>
  using _AndImpl = typename _MetaBase<_First::value == true && sizeof...(_Rest) != 0>::template _AndImpl<_First, _Rest...>;
};

template <>
struct _MetaBase<false> {
  template <class _Tp, class _Up>
  using _SelectImpl = _Up;
  template <template <class...> class, template <class...> class _SecondFn, class ..._Args>
  using _SelectApplyImpl = _SecondFn<_Args...>;
  template <class _Result, class ...>
  using _OrImpl = _Result;
  template <class _Result, class ...>
  using _AndImpl = _Result;
};
template <bool _Cond, class _Ret = void>
using _EnableIf = typename _MetaBase<_Cond>::template _EnableIfImpl<_Ret>;
template <bool _Cond, class _IfRes, class _ElseRes>
using _If = typename _MetaBase<_Cond>::template _SelectImpl<_IfRes, _ElseRes>;
template <class ..._Rest>
using _Or = typename _MetaBase< sizeof...(_Rest) != 0 >::template _OrImpl<false_type, _Rest...>;
template <class ..._Rest>
using _And = typename _MetaBase< sizeof...(_Rest) != 0 >::template _AndImpl<true_type, _Rest...>;
template <class _Pred>
struct _Not : _BoolConstant<!_Pred::value> {};
template <class ..._Args>
using _FirstType = typename _MetaBase<(sizeof...(_Args) >= 1)>::template _FirstImpl<_Args...>;
template <class ..._Args>
using _SecondType = typename _MetaBase<(sizeof...(_Args) >= 2)>::template _SecondImpl<_Args...>;

template <template <class...> class _Func, class ..._Args>
struct _Lazy : _Func<_Args...> {};



template <template <class...> class _Templ, class ..._Args, class = _Templ<_Args...> >
true_type __sfinae_test_impl(int);
template <template <class...> class, class ...>
false_type __sfinae_test_impl(...);

template <template <class ...> class _Templ, class ..._Args>
using _IsValidExpansion = __decltype(std::__sfinae_test_impl<_Templ, _Args...>(0));

template <class>
struct __void_t { typedef void type; };

template <class _Tp>
struct __identity { typedef _Tp type; };

template <class _Tp, bool>
struct __attribute__ ((__type_visibility__("default"))) __dependent_type : public _Tp {};


template <bool _Bp, class _If, class _Then>
    struct __attribute__ ((__type_visibility__("default"))) conditional {typedef _If type;};
template <class _If, class _Then>
    struct __attribute__ ((__type_visibility__("default"))) conditional<false, _If, _Then> {typedef _Then type;};





template <bool, class _Tp = void> struct __attribute__ ((__type_visibility__("default"))) enable_if {};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) enable_if<true, _Tp> {typedef _Tp type;};







template <class _Tp, class _Up> struct __attribute__ ((__type_visibility__("default"))) is_same : public false_type {};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_same<_Tp, _Tp> : public true_type {};







template <class _Tp, class _Up>
using _IsSame = _BoolConstant<

    __is_same(_Tp, _Up)



>;

template <class _Tp, class _Up>
using _IsNotSame = _BoolConstant<

    !__is_same(_Tp, _Up)



>;


template <class _Tp>
using __test_for_primary_template = _EnableIf<
    _IsSame<_Tp, typename _Tp::__primary_template>::value
  >;
template <class _Tp>
using __is_primary_template = _IsValidExpansion<
    __test_for_primary_template, _Tp
  >;




template <class _Tp>
inline
__attribute__((__no_sanitize__("cfi"))) __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp*
addressof(_Tp& __x) throw()
{
    return __builtin_addressof(__x);
}

struct __two {char __lx[2];};





template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_const : public false_type {};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_const<_Tp const> : public true_type {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_volatile : public false_type {};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_volatile<_Tp volatile> : public true_type {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) remove_const {typedef _Tp type;};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) remove_const<const _Tp> {typedef _Tp type;};






template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) remove_volatile {typedef _Tp type;};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) remove_volatile<volatile _Tp> {typedef _Tp type;};






template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) remove_cv
{typedef typename remove_volatile<typename remove_const<_Tp>::type>::type type;};






template <class _Tp> struct __libcpp_is_void : public false_type {};
template <> struct __libcpp_is_void<void> : public true_type {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_void
    : public __libcpp_is_void<typename remove_cv<_Tp>::type> {};

template <class _Tp> struct __is_nullptr_t_impl : public false_type {};
template <> struct __is_nullptr_t_impl<nullptr_t> : public true_type {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) __is_nullptr_t
    : public __is_nullptr_t_impl<typename remove_cv<_Tp>::type> {};

template <class _Tp> struct __libcpp_is_integral : public false_type {};
template <> struct __libcpp_is_integral<bool> : public true_type {};
template <> struct __libcpp_is_integral<char> : public true_type {};
template <> struct __libcpp_is_integral<signed char> : public true_type {};
template <> struct __libcpp_is_integral<unsigned char> : public true_type {};
template <> struct __libcpp_is_integral<wchar_t> : public true_type {};




template <> struct __libcpp_is_integral<char16_t> : public true_type {};
template <> struct __libcpp_is_integral<char32_t> : public true_type {};

template <> struct __libcpp_is_integral<short> : public true_type {};
template <> struct __libcpp_is_integral<unsigned short> : public true_type {};
template <> struct __libcpp_is_integral<int> : public true_type {};
template <> struct __libcpp_is_integral<unsigned int> : public true_type {};
template <> struct __libcpp_is_integral<long> : public true_type {};
template <> struct __libcpp_is_integral<unsigned long> : public true_type {};
template <> struct __libcpp_is_integral<long long> : public true_type {};
template <> struct __libcpp_is_integral<unsigned long long> : public true_type {};

template <> struct __libcpp_is_integral<__int128_t> : public true_type {};
template <> struct __libcpp_is_integral<__uint128_t> : public true_type {};


template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_integral
    : public __libcpp_is_integral<typename remove_cv<_Tp>::type> {};

template <class _Tp> struct __libcpp_is_floating_point : public false_type {};
template <> struct __libcpp_is_floating_point<float> : public true_type {};
template <> struct __libcpp_is_floating_point<double> : public true_type {};
template <> struct __libcpp_is_floating_point<long double> : public true_type {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_floating_point
    : public __libcpp_is_floating_point<typename remove_cv<_Tp>::type> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_array
    : public false_type {};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_array<_Tp[]>
    : public true_type {};
template <class _Tp, size_t _Np> struct __attribute__ ((__type_visibility__("default"))) is_array<_Tp[_Np]>
    : public true_type {};

template <class _Tp> struct __libcpp_is_pointer : public false_type {};
template <class _Tp> struct __libcpp_is_pointer<_Tp*> : public true_type {};

template <class _Tp> struct __libcpp_remove_objc_qualifiers { typedef _Tp type; };







template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_pointer
    : public __libcpp_is_pointer<typename __libcpp_remove_objc_qualifiers<typename remove_cv<_Tp>::type>::type> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_lvalue_reference : public false_type {};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_lvalue_reference<_Tp&> : public true_type {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_rvalue_reference : public false_type {};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_rvalue_reference<_Tp&&> : public true_type {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_reference : public false_type {};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_reference<_Tp&> : public true_type {};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_reference<_Tp&&> : public true_type {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_union
    : public integral_constant<bool, __is_union(_Tp)> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_class
    : public integral_constant<bool, __is_class(_Tp)> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_function
    : public _BoolConstant<

    __is_function(_Tp)



    > {};

template <class _Tp> struct __libcpp_is_member_pointer {
  enum {
    __is_member = false,
    __is_func = false,
    __is_obj = false
  };
};
template <class _Tp, class _Up> struct __libcpp_is_member_pointer<_Tp _Up::*> {
  enum {
    __is_member = true,
    __is_func = is_function<_Tp>::value,
    __is_obj = !__is_func,
  };
};


template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_member_function_pointer
    : public _BoolConstant< __libcpp_is_member_pointer<typename remove_cv<_Tp>::type>::__is_func > {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_member_pointer
 : public _BoolConstant< __libcpp_is_member_pointer<typename remove_cv<_Tp>::type>::__is_member > {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_member_object_pointer
    : public _BoolConstant< __libcpp_is_member_pointer<typename remove_cv<_Tp>::type>::__is_obj > {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_enum
    : public integral_constant<bool, __is_enum(_Tp)> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_arithmetic
    : public integral_constant<bool, is_integral<_Tp>::value ||
                                     is_floating_point<_Tp>::value> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_fundamental
    : public integral_constant<bool, is_void<_Tp>::value ||
                                     __is_nullptr_t<_Tp>::value ||
                                     is_arithmetic<_Tp>::value> {};

template <class _Tp> struct __is_block : false_type {};

template <class _Rp, class ..._Args> struct __is_block<_Rp (^)(_Args...)> : true_type {};


template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_scalar
    : public integral_constant<bool, is_arithmetic<_Tp>::value ||
                                     is_member_pointer<_Tp>::value ||
                                     is_pointer<_Tp>::value ||
                                     __is_nullptr_t<_Tp>::value ||
                                     __is_block<_Tp>::value ||
                                     is_enum<_Tp>::value > {};

template <> struct __attribute__ ((__type_visibility__("default"))) is_scalar<nullptr_t> : public true_type {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_object
    : public integral_constant<bool, is_scalar<_Tp>::value ||
                                     is_array<_Tp>::value ||
                                     is_union<_Tp>::value ||
                                     is_class<_Tp>::value > {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_compound
    : public integral_constant<bool, !is_fundamental<_Tp>::value> {};

struct __is_referenceable_impl {
    template <class _Tp> static _Tp& __test(int);
    template <class _Tp> static __two __test(...);
};

template <class _Tp>
struct __is_referenceable : integral_constant<bool,
    _IsNotSame<__decltype(__is_referenceable_impl::__test<_Tp>(0)), __two>::value> {};




template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) add_const {
  typedef const _Tp type;
};







template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) add_volatile {
  typedef volatile _Tp type;
};






template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) add_cv {
  typedef const volatile _Tp type;
};







template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) remove_reference {typedef _Tp type;};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) remove_reference<_Tp&> {typedef _Tp type;};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) remove_reference<_Tp&&> {typedef _Tp type;};







template <class _Tp, bool = __is_referenceable<_Tp>::value> struct __add_lvalue_reference_impl { typedef _Tp type; };
template <class _Tp > struct __add_lvalue_reference_impl<_Tp, true> { typedef _Tp& type; };

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) add_lvalue_reference
{typedef typename __add_lvalue_reference_impl<_Tp>::type type;};





template <class _Tp, bool = __is_referenceable<_Tp>::value> struct __add_rvalue_reference_impl { typedef _Tp type; };
template <class _Tp > struct __add_rvalue_reference_impl<_Tp, true> { typedef _Tp&& type; };

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) add_rvalue_reference
{typedef typename __add_rvalue_reference_impl<_Tp>::type type;};










template <class _Tp> _Tp&& __declval(int);
template <class _Tp> _Tp __declval(long);


template <class _Tp>
__decltype(std::__1::__declval<_Tp>(0))
declval() throw();



template <class _Tp>
struct __uncvref {
    typedef typename remove_cv<typename remove_reference<_Tp>::type>::type type;
};

template <class _Tp>
struct __unconstref {
    typedef typename remove_const<typename remove_reference<_Tp>::type>::type type;
};

template <class _Tp, class _Up>
struct __is_same_uncvref : _IsSame<typename __uncvref<_Tp>::type,
                                   typename __uncvref<_Up>::type> {};

struct __any
{
    __any(...);
};



template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) remove_pointer {typedef _Tp type;};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) remove_pointer<_Tp*> {typedef _Tp type;};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) remove_pointer<_Tp* const> {typedef _Tp type;};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) remove_pointer<_Tp* volatile> {typedef _Tp type;};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) remove_pointer<_Tp* const volatile> {typedef _Tp type;};







template <class _Tp,
        bool = __is_referenceable<_Tp>::value ||
                _IsSame<typename remove_cv<_Tp>::type, void>::value>
struct __add_pointer_impl
    {typedef typename remove_reference<_Tp>::type* type;};
template <class _Tp> struct __add_pointer_impl<_Tp, false>
    {typedef _Tp type;};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) add_pointer
    {typedef typename __add_pointer_impl<_Tp>::type type;};

template <class _Tp, bool = is_integral<_Tp>::value>
struct __libcpp_is_signed_impl : public integral_constant<bool,(_Tp(-1) < _Tp(0))> {};

template <class _Tp>
struct __libcpp_is_signed_impl<_Tp, false> : public true_type {};

template <class _Tp, bool = is_arithmetic<_Tp>::value>
struct __libcpp_is_signed : public __libcpp_is_signed_impl<_Tp> {};

template <class _Tp> struct __libcpp_is_signed<_Tp, false> : public false_type {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_signed : public __libcpp_is_signed<_Tp> {};

template <class _Tp, bool = is_integral<_Tp>::value>
struct __libcpp_is_unsigned_impl : public integral_constant<bool,(_Tp(0) < _Tp(-1))> {};

template <class _Tp>
struct __libcpp_is_unsigned_impl<_Tp, false> : public false_type {};

template <class _Tp, bool = is_arithmetic<_Tp>::value>
struct __libcpp_is_unsigned : public __libcpp_is_unsigned_impl<_Tp> {};

template <class _Tp> struct __libcpp_is_unsigned<_Tp, false> : public false_type {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_unsigned : public __libcpp_is_unsigned<_Tp> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) rank
    : public integral_constant<size_t, 0> {};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) rank<_Tp[]>
    : public integral_constant<size_t, rank<_Tp>::value + 1> {};
template <class _Tp, size_t _Np> struct __attribute__ ((__type_visibility__("default"))) rank<_Tp[_Np]>
    : public integral_constant<size_t, rank<_Tp>::value + 1> {};

template <class _Tp, unsigned _Ip = 0> struct __attribute__ ((__type_visibility__("default"))) extent
    : public integral_constant<size_t, 0> {};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) extent<_Tp[], 0>
    : public integral_constant<size_t, 0> {};
template <class _Tp, unsigned _Ip> struct __attribute__ ((__type_visibility__("default"))) extent<_Tp[], _Ip>
    : public integral_constant<size_t, extent<_Tp, _Ip-1>::value> {};
template <class _Tp, size_t _Np> struct __attribute__ ((__type_visibility__("default"))) extent<_Tp[_Np], 0>
    : public integral_constant<size_t, _Np> {};
template <class _Tp, size_t _Np, unsigned _Ip> struct __attribute__ ((__type_visibility__("default"))) extent<_Tp[_Np], _Ip>
    : public integral_constant<size_t, extent<_Tp, _Ip-1>::value> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) remove_extent
    {typedef _Tp type;};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) remove_extent<_Tp[]>
    {typedef _Tp type;};
template <class _Tp, size_t _Np> struct __attribute__ ((__type_visibility__("default"))) remove_extent<_Tp[_Np]>
    {typedef _Tp type;};







template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) remove_all_extents
    {typedef _Tp type;};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) remove_all_extents<_Tp[]>
    {typedef typename remove_all_extents<_Tp>::type type;};
template <class _Tp, size_t _Np> struct __attribute__ ((__type_visibility__("default"))) remove_all_extents<_Tp[_Np]>
    {typedef typename remove_all_extents<_Tp>::type type;};

template <class _Up, bool>
struct __decay {
    typedef typename remove_cv<_Up>::type type;
};

template <class _Up>
struct __decay<_Up, true> {
public:
    typedef typename conditional
                     <
                         is_array<_Up>::value,
                         typename remove_extent<_Up>::type*,
                         typename conditional
                         <
                              is_function<_Up>::value,
                              typename add_pointer<_Up>::type,
                              typename remove_cv<_Up>::type
                         >::type
                     >::type type;
};

template <class _Tp>
struct __attribute__ ((__type_visibility__("default"))) decay
{
private:
    typedef typename remove_reference<_Tp>::type _Up;
public:
    typedef typename __decay<_Up, __is_referenceable<_Up>::value>::type type;
};







template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_abstract
    : public integral_constant<bool, __is_abstract(_Tp)> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default")))
__libcpp_is_final : public integral_constant<bool, __is_final(_Tp)> {};

template <class _Bp, class _Dp>
struct __attribute__ ((__type_visibility__("default"))) is_base_of
    : public integral_constant<bool, __is_base_of(_Bp, _Dp)> {};

template <class _T1, class _T2> struct __attribute__ ((__type_visibility__("default"))) is_convertible
    : public integral_constant<bool, __is_convertible_to(_T1, _T2)> {};

template <class _Tp>
struct __attribute__ ((__type_visibility__("default"))) is_empty
    : public integral_constant<bool, __is_empty(_Tp)> {};

template <class _Tp>
struct __attribute__ ((__type_visibility__("default"))) is_polymorphic
    : public integral_constant<bool, __is_polymorphic(_Tp)> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) has_virtual_destructor
    : public integral_constant<bool, __has_virtual_destructor(_Tp)> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) alignment_of
    : public integral_constant<size_t, _Alignof(_Tp)> {};

template <class _Hp, class _Tp>
struct __type_list
{
    typedef _Hp _Head;
    typedef _Tp _Tail;
};

struct __nat
{






};

template <class _Tp>
struct __align_type
{
    static const size_t value = __alignof(_Tp);
    typedef _Tp type;
};

struct __struct_double {long double __lx;};
struct __struct_double4 {double __lx[4];};

typedef
    __type_list<__align_type<unsigned char>,
    __type_list<__align_type<unsigned short>,
    __type_list<__align_type<unsigned int>,
    __type_list<__align_type<unsigned long>,
    __type_list<__align_type<unsigned long long>,
    __type_list<__align_type<double>,
    __type_list<__align_type<long double>,
    __type_list<__align_type<__struct_double>,
    __type_list<__align_type<__struct_double4>,
    __type_list<__align_type<int*>,
    __nat
    > > > > > > > > > > __all_types;

template <size_t _Align>
struct __attribute__((__aligned__(_Align))) __fallback_overaligned {};

template <class _TL, size_t _Align> struct __find_pod;

template <class _Hp, size_t _Align>
struct __find_pod<__type_list<_Hp, __nat>, _Align>
{
    typedef typename conditional<
                             _Align == _Hp::value,
                             typename _Hp::type,
                             __fallback_overaligned<_Align>
                         >::type type;
};

template <class _Hp, class _Tp, size_t _Align>
struct __find_pod<__type_list<_Hp, _Tp>, _Align>
{
    typedef typename conditional<
                             _Align == _Hp::value,
                             typename _Hp::type,
                             typename __find_pod<_Tp, _Align>::type
                         >::type type;
};

template <class _TL, size_t _Len> struct __find_max_align;

template <class _Hp, size_t _Len>
struct __find_max_align<__type_list<_Hp, __nat>, _Len> : public integral_constant<size_t, _Hp::value> {};

template <size_t _Len, size_t _A1, size_t _A2>
struct __select_align
{
private:
    static const size_t __min = _A2 < _A1 ? _A2 : _A1;
    static const size_t __max = _A1 < _A2 ? _A2 : _A1;
public:
    static const size_t value = _Len < __max ? __min : __max;
};

template <class _Hp, class _Tp, size_t _Len>
struct __find_max_align<__type_list<_Hp, _Tp>, _Len>
    : public integral_constant<size_t, __select_align<_Len, _Hp::value, __find_max_align<_Tp, _Len>::value>::value> {};

template <size_t _Len, size_t _Align = __find_max_align<__all_types, _Len>::value>
struct __attribute__ ((__type_visibility__("default"))) aligned_storage
{
    typedef typename __find_pod<__all_types, _Align>::type _Aligner;
    union type
    {
        _Aligner __align;
        unsigned char __data[(_Len + _Align - 1)/_Align * _Align];
    };
};

template <size_t _Len>struct __attribute__ ((__type_visibility__("default"))) aligned_storage<_Len, 0x1>{ struct __attribute__((__aligned__(0x1))) type { unsigned char __lx[(_Len + 0x1 - 1)/0x1 * 0x1]; };};
template <size_t _Len>struct __attribute__ ((__type_visibility__("default"))) aligned_storage<_Len, 0x2>{ struct __attribute__((__aligned__(0x2))) type { unsigned char __lx[(_Len + 0x2 - 1)/0x2 * 0x2]; };};
template <size_t _Len>struct __attribute__ ((__type_visibility__("default"))) aligned_storage<_Len, 0x4>{ struct __attribute__((__aligned__(0x4))) type { unsigned char __lx[(_Len + 0x4 - 1)/0x4 * 0x4]; };};
template <size_t _Len>struct __attribute__ ((__type_visibility__("default"))) aligned_storage<_Len, 0x8>{ struct __attribute__((__aligned__(0x8))) type { unsigned char __lx[(_Len + 0x8 - 1)/0x8 * 0x8]; };};
template <size_t _Len>struct __attribute__ ((__type_visibility__("default"))) aligned_storage<_Len, 0x10>{ struct __attribute__((__aligned__(0x10))) type { unsigned char __lx[(_Len + 0x10 - 1)/0x10 * 0x10]; };};
template <size_t _Len>struct __attribute__ ((__type_visibility__("default"))) aligned_storage<_Len, 0x20>{ struct __attribute__((__aligned__(0x20))) type { unsigned char __lx[(_Len + 0x20 - 1)/0x20 * 0x20]; };};
template <size_t _Len>struct __attribute__ ((__type_visibility__("default"))) aligned_storage<_Len, 0x40>{ struct __attribute__((__aligned__(0x40))) type { unsigned char __lx[(_Len + 0x40 - 1)/0x40 * 0x40]; };};
template <size_t _Len>struct __attribute__ ((__type_visibility__("default"))) aligned_storage<_Len, 0x80>{ struct __attribute__((__aligned__(0x80))) type { unsigned char __lx[(_Len + 0x80 - 1)/0x80 * 0x80]; };};
template <size_t _Len>struct __attribute__ ((__type_visibility__("default"))) aligned_storage<_Len, 0x100>{ struct __attribute__((__aligned__(0x100))) type { unsigned char __lx[(_Len + 0x100 - 1)/0x100 * 0x100]; };};
template <size_t _Len>struct __attribute__ ((__type_visibility__("default"))) aligned_storage<_Len, 0x200>{ struct __attribute__((__aligned__(0x200))) type { unsigned char __lx[(_Len + 0x200 - 1)/0x200 * 0x200]; };};
template <size_t _Len>struct __attribute__ ((__type_visibility__("default"))) aligned_storage<_Len, 0x400>{ struct __attribute__((__aligned__(0x400))) type { unsigned char __lx[(_Len + 0x400 - 1)/0x400 * 0x400]; };};
template <size_t _Len>struct __attribute__ ((__type_visibility__("default"))) aligned_storage<_Len, 0x800>{ struct __attribute__((__aligned__(0x800))) type { unsigned char __lx[(_Len + 0x800 - 1)/0x800 * 0x800]; };};
template <size_t _Len>struct __attribute__ ((__type_visibility__("default"))) aligned_storage<_Len, 0x1000>{ struct __attribute__((__aligned__(0x1000))) type { unsigned char __lx[(_Len + 0x1000 - 1)/0x1000 * 0x1000]; };};
template <size_t _Len>struct __attribute__ ((__type_visibility__("default"))) aligned_storage<_Len, 0x2000>{ struct __attribute__((__aligned__(0x2000))) type { unsigned char __lx[(_Len + 0x2000 - 1)/0x2000 * 0x2000]; };};


template <size_t _Len>struct __attribute__ ((__type_visibility__("default"))) aligned_storage<_Len, 0x4000>{ struct __attribute__((__aligned__(0x4000))) type { unsigned char __lx[(_Len + 0x4000 - 1)/0x4000 * 0x4000]; };};







template <size_t _I0, size_t ..._In>
struct __static_max;

template <size_t _I0>
struct __static_max<_I0>
{
    static const size_t value = _I0;
};

template <size_t _I0, size_t _I1, size_t ..._In>
struct __static_max<_I0, _I1, _In...>
{
    static const size_t value = _I0 >= _I1 ? __static_max<_I0, _In...>::value :
                                             __static_max<_I1, _In...>::value;
};

template <size_t _Len, class _Type0, class ..._Types>
struct aligned_union
{
    static const size_t alignment_value = __static_max<__alignof(_Type0),
                                                       __alignof(_Types)...>::value;
    static const size_t __len = __static_max<_Len, sizeof(_Type0),
                                             sizeof(_Types)...>::value;
    typedef typename aligned_storage<__len, alignment_value>::type type;
};





template <class _Tp>
struct __numeric_type
{
   static void __test(...);
   static float __test(float);
   static double __test(char);
   static double __test(int);
   static double __test(unsigned);
   static double __test(long);
   static double __test(unsigned long);
   static double __test(long long);
   static double __test(unsigned long long);
   static double __test(double);
   static long double __test(long double);

   typedef __decltype(__test(declval<_Tp>())) type;
   static const bool value = _IsNotSame<type, void>::value;
};

template <>
struct __numeric_type<void>
{
   static const bool value = true;
};



template <class _A1, class _A2 = void, class _A3 = void,
          bool = __numeric_type<_A1>::value &&
                 __numeric_type<_A2>::value &&
                 __numeric_type<_A3>::value>
class __promote_imp
{
public:
    static const bool value = false;
};

template <class _A1, class _A2, class _A3>
class __promote_imp<_A1, _A2, _A3, true>
{
private:
    typedef typename __promote_imp<_A1>::type __type1;
    typedef typename __promote_imp<_A2>::type __type2;
    typedef typename __promote_imp<_A3>::type __type3;
public:
    typedef __decltype(__type1() + __type2() + __type3()) type;
    static const bool value = true;
};

template <class _A1, class _A2>
class __promote_imp<_A1, _A2, void, true>
{
private:
    typedef typename __promote_imp<_A1>::type __type1;
    typedef typename __promote_imp<_A2>::type __type2;
public:
    typedef __decltype(__type1() + __type2()) type;
    static const bool value = true;
};

template <class _A1>
class __promote_imp<_A1, void, void, true>
{
public:
    typedef typename __numeric_type<_A1>::type type;
    static const bool value = true;
};

template <class _A1, class _A2 = void, class _A3 = void>
class __promote : public __promote_imp<_A1, _A2, _A3> {};



typedef
    __type_list<signed char,
    __type_list<signed short,
    __type_list<signed int,
    __type_list<signed long,
    __type_list<signed long long,

    __type_list<__int128_t,

    __nat

    >

    > > > > > __signed_types;

typedef
    __type_list<unsigned char,
    __type_list<unsigned short,
    __type_list<unsigned int,
    __type_list<unsigned long,
    __type_list<unsigned long long,

    __type_list<__uint128_t,

    __nat

    >

    > > > > > __unsigned_types;

template <class _TypeList, size_t _Size, bool = _Size <= sizeof(typename _TypeList::_Head)> struct __find_first;

template <class _Hp, class _Tp, size_t _Size>
struct __find_first<__type_list<_Hp, _Tp>, _Size, true>
{
    typedef _Hp type;
};

template <class _Hp, class _Tp, size_t _Size>
struct __find_first<__type_list<_Hp, _Tp>, _Size, false>
{
    typedef typename __find_first<_Tp, _Size>::type type;
};

template <class _Tp, class _Up, bool = is_const<typename remove_reference<_Tp>::type>::value,
                             bool = is_volatile<typename remove_reference<_Tp>::type>::value>
struct __apply_cv
{
    typedef _Up type;
};

template <class _Tp, class _Up>
struct __apply_cv<_Tp, _Up, true, false>
{
    typedef const _Up type;
};

template <class _Tp, class _Up>
struct __apply_cv<_Tp, _Up, false, true>
{
    typedef volatile _Up type;
};

template <class _Tp, class _Up>
struct __apply_cv<_Tp, _Up, true, true>
{
    typedef const volatile _Up type;
};

template <class _Tp, class _Up>
struct __apply_cv<_Tp&, _Up, false, false>
{
    typedef _Up& type;
};

template <class _Tp, class _Up>
struct __apply_cv<_Tp&, _Up, true, false>
{
    typedef const _Up& type;
};

template <class _Tp, class _Up>
struct __apply_cv<_Tp&, _Up, false, true>
{
    typedef volatile _Up& type;
};

template <class _Tp, class _Up>
struct __apply_cv<_Tp&, _Up, true, true>
{
    typedef const volatile _Up& type;
};

template <class _Tp, bool = is_integral<_Tp>::value || is_enum<_Tp>::value>
struct __make_signed {};

template <class _Tp>
struct __make_signed<_Tp, true>
{
    typedef typename __find_first<__signed_types, sizeof(_Tp)>::type type;
};

template <> struct __make_signed<bool, true> {};
template <> struct __make_signed< signed short, true> {typedef short type;};
template <> struct __make_signed<unsigned short, true> {typedef short type;};
template <> struct __make_signed< signed int, true> {typedef int type;};
template <> struct __make_signed<unsigned int, true> {typedef int type;};
template <> struct __make_signed< signed long, true> {typedef long type;};
template <> struct __make_signed<unsigned long, true> {typedef long type;};
template <> struct __make_signed< signed long long, true> {typedef long long type;};
template <> struct __make_signed<unsigned long long, true> {typedef long long type;};

template <> struct __make_signed<__int128_t, true> {typedef __int128_t type;};
template <> struct __make_signed<__uint128_t, true> {typedef __int128_t type;};


template <class _Tp>
struct __attribute__ ((__type_visibility__("default"))) make_signed
{
    typedef typename __apply_cv<_Tp, typename __make_signed<typename remove_cv<_Tp>::type>::type>::type type;
};





template <class _Tp, bool = is_integral<_Tp>::value || is_enum<_Tp>::value>
struct __make_unsigned {};

template <class _Tp>
struct __make_unsigned<_Tp, true>
{
    typedef typename __find_first<__unsigned_types, sizeof(_Tp)>::type type;
};

template <> struct __make_unsigned<bool, true> {};
template <> struct __make_unsigned< signed short, true> {typedef unsigned short type;};
template <> struct __make_unsigned<unsigned short, true> {typedef unsigned short type;};
template <> struct __make_unsigned< signed int, true> {typedef unsigned int type;};
template <> struct __make_unsigned<unsigned int, true> {typedef unsigned int type;};
template <> struct __make_unsigned< signed long, true> {typedef unsigned long type;};
template <> struct __make_unsigned<unsigned long, true> {typedef unsigned long type;};
template <> struct __make_unsigned< signed long long, true> {typedef unsigned long long type;};
template <> struct __make_unsigned<unsigned long long, true> {typedef unsigned long long type;};

template <> struct __make_unsigned<__int128_t, true> {typedef __uint128_t type;};
template <> struct __make_unsigned<__uint128_t, true> {typedef __uint128_t type;};


template <class _Tp>
struct __attribute__ ((__type_visibility__("default"))) make_unsigned
{
    typedef typename __apply_cv<_Tp, typename __make_unsigned<typename remove_cv<_Tp>::type>::type>::type type;
};





template <class _Tp, class _Up, class = void>
struct __common_type2_imp {};

template <class _Tp, class _Up>
struct __common_type2_imp<_Tp, _Up,
                          typename __void_t<__decltype(true ? std::__1::declval<_Tp>() : std::__1::declval<_Up>())>::type>


{
  typedef typename decay<__decltype(true ? std::__1::declval<_Tp>() : std::__1::declval<_Up>())>::type type;


};

template <class, class = void>
struct __common_type_impl {};




template <class... Tp>
struct __common_types;
template <class... _Tp>
struct __attribute__ ((__type_visibility__("default"))) common_type;

template <class _Tp, class _Up>
struct __common_type_impl<
    __common_types<_Tp, _Up>,
    typename __void_t<typename common_type<_Tp, _Up>::type>::type>
{
  typedef typename common_type<_Tp, _Up>::type type;
};

template <class _Tp, class _Up, class _Vp , class... _Rest>
struct __common_type_impl<
    __common_types<_Tp, _Up, _Vp , _Rest...>,
    typename __void_t<typename common_type<_Tp, _Up>::type>::type>
    : __common_type_impl<__common_types<typename common_type<_Tp, _Up>::type,
                                        _Vp , _Rest...> > {
};



template <>
struct __attribute__ ((__type_visibility__("default"))) common_type<> {};



template <class _Tp>
struct __attribute__ ((__type_visibility__("default"))) common_type<_Tp>
    : public common_type<_Tp, _Tp> {};



template <class _Tp, class _Up>
struct __attribute__ ((__type_visibility__("default"))) common_type<_Tp, _Up>
    : conditional<
        _IsSame<_Tp, typename decay<_Tp>::type>::value && _IsSame<_Up, typename decay<_Up>::type>::value,
        __common_type2_imp<_Tp, _Up>,
        common_type<typename decay<_Tp>::type, typename decay<_Up>::type>
    >::type
{};



template <class _Tp, class _Up, class _Vp , class... _Rest>
struct __attribute__ ((__type_visibility__("default")))
    common_type<_Tp, _Up, _Vp , _Rest...>
    : __common_type_impl<
          __common_types<_Tp, _Up, _Vp , _Rest...> > {};

template<typename, typename _Tp> struct __select_2nd { typedef _Tp type; };

template <class _Tp, class _Arg>
typename __select_2nd<__decltype((std::__1::declval<_Tp>() = std::__1::declval<_Arg>())), true_type>::type
__is_assignable_test(int);

template <class, class>
false_type __is_assignable_test(...);


template <class _Tp, class _Arg, bool = is_void<_Tp>::value || is_void<_Arg>::value>
struct __is_assignable_imp
    : public __decltype((std::__1::__is_assignable_test<_Tp, _Arg>(0))) {};

template <class _Tp, class _Arg>
struct __is_assignable_imp<_Tp, _Arg, true>
    : public false_type
{
};

template <class _Tp, class _Arg>
struct is_assignable
    : public __is_assignable_imp<_Tp, _Arg> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_copy_assignable
    : public is_assignable<typename add_lvalue_reference<_Tp>::type,
                  typename add_lvalue_reference<typename add_const<_Tp>::type>::type> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_move_assignable
    : public is_assignable<typename add_lvalue_reference<_Tp>::type,
                           typename add_rvalue_reference<_Tp>::type> {};

template <class>
struct __is_destructible_apply { typedef int type; };

template <typename _Tp>
struct __is_destructor_wellformed {
    template <typename _Tp1>
    static char __test (
        typename __is_destructible_apply<__decltype(std::__1::declval<_Tp1&>().~_Tp1())>::type
    );

    template <typename _Tp1>
    static __two __test (...);

    static const bool value = sizeof(__test<_Tp>(12)) == sizeof(char);
};

template <class _Tp, bool>
struct __destructible_imp;

template <class _Tp>
struct __destructible_imp<_Tp, false>
   : public std::__1::integral_constant<bool,
        __is_destructor_wellformed<typename std::__1::remove_all_extents<_Tp>::type>::value> {};

template <class _Tp>
struct __destructible_imp<_Tp, true>
    : public std::__1::true_type {};

template <class _Tp, bool>
struct __destructible_false;

template <class _Tp>
struct __destructible_false<_Tp, false> : public __destructible_imp<_Tp, std::__1::is_reference<_Tp>::value> {};

template <class _Tp>
struct __destructible_false<_Tp, true> : public std::__1::false_type {};

template <class _Tp>
struct is_destructible
    : public __destructible_false<_Tp, std::__1::is_function<_Tp>::value> {};

template <class _Tp>
struct is_destructible<_Tp[]>
    : public std::__1::false_type {};

template <>
struct is_destructible<void>
    : public std::__1::false_type {};

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename remove_reference<_Tp>::type&&
move(_Tp&& __t) throw()
{
    typedef typename remove_reference<_Tp>::type _Up;
    return static_cast<_Up&&>(__t);
}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp&&
forward(typename remove_reference<_Tp>::type& __t) throw()
{
    return static_cast<_Tp&&>(__t);
}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp&&
forward(typename remove_reference<_Tp>::type&& __t) throw()
{
    _Static_assert(!is_lvalue_reference<_Tp>::value, "can not forward an rvalue as an lvalue");

    return static_cast<_Tp&&>(__t);
}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename decay<_Tp>::type
__decay_copy(_Tp&& __t)
{
    return std::__1::forward<_Tp>(__t);
}

template <class _MP, bool _IsMemberFunctionPtr, bool _IsMemberObjectPtr>
struct __member_pointer_traits_imp
{
};

template <class _Rp, class _Class, class ..._Param>
struct __member_pointer_traits_imp<_Rp (_Class::*)(_Param...), true, false>
{
    typedef _Class _ClassType;
    typedef _Rp _ReturnType;
    typedef _Rp (_FnType) (_Param...);
};

template <class _Rp, class _Class, class ..._Param>
struct __member_pointer_traits_imp<_Rp (_Class::*)(_Param..., ...), true, false>
{
    typedef _Class _ClassType;
    typedef _Rp _ReturnType;
    typedef _Rp (_FnType) (_Param..., ...);
};

template <class _Rp, class _Class, class ..._Param>
struct __member_pointer_traits_imp<_Rp (_Class::*)(_Param...) const, true, false>
{
    typedef _Class const _ClassType;
    typedef _Rp _ReturnType;
    typedef _Rp (_FnType) (_Param...);
};

template <class _Rp, class _Class, class ..._Param>
struct __member_pointer_traits_imp<_Rp (_Class::*)(_Param..., ...) const, true, false>
{
    typedef _Class const _ClassType;
    typedef _Rp _ReturnType;
    typedef _Rp (_FnType) (_Param..., ...);
};

template <class _Rp, class _Class, class ..._Param>
struct __member_pointer_traits_imp<_Rp (_Class::*)(_Param...) volatile, true, false>
{
    typedef _Class volatile _ClassType;
    typedef _Rp _ReturnType;
    typedef _Rp (_FnType) (_Param...);
};

template <class _Rp, class _Class, class ..._Param>
struct __member_pointer_traits_imp<_Rp (_Class::*)(_Param..., ...) volatile, true, false>
{
    typedef _Class volatile _ClassType;
    typedef _Rp _ReturnType;
    typedef _Rp (_FnType) (_Param..., ...);
};

template <class _Rp, class _Class, class ..._Param>
struct __member_pointer_traits_imp<_Rp (_Class::*)(_Param...) const volatile, true, false>
{
    typedef _Class const volatile _ClassType;
    typedef _Rp _ReturnType;
    typedef _Rp (_FnType) (_Param...);
};

template <class _Rp, class _Class, class ..._Param>
struct __member_pointer_traits_imp<_Rp (_Class::*)(_Param..., ...) const volatile, true, false>
{
    typedef _Class const volatile _ClassType;
    typedef _Rp _ReturnType;
    typedef _Rp (_FnType) (_Param..., ...);
};

template <class _Rp, class _Class>
struct __member_pointer_traits_imp<_Rp _Class::*, false, true>
{
    typedef _Class _ClassType;
    typedef _Rp _ReturnType;
};

template <class _MP>
struct __member_pointer_traits
    : public __member_pointer_traits_imp<typename remove_cv<_MP>::type,
                    is_member_function_pointer<_MP>::value,
                    is_member_object_pointer<_MP>::value>
{



};


template <class _DecayedFp>
struct __member_pointer_class_type {};

template <class _Ret, class _ClassType>
struct __member_pointer_class_type<_Ret _ClassType::*> {
  typedef _ClassType type;
};



template <class _Callable> class result_of;



template <class _Fn, bool, bool>
class __result_of
{
};

template <class _Fn>
class __result_of<_Fn(), true, false>
{
public:
    typedef __decltype(declval<_Fn>()()) type;
};

template <class _Fn, class _A0>
class __result_of<_Fn(_A0), true, false>
{
public:
    typedef __decltype(declval<_Fn>()(declval<_A0>())) type;
};

template <class _Fn, class _A0, class _A1>
class __result_of<_Fn(_A0, _A1), true, false>
{
public:
    typedef __decltype(declval<_Fn>()(declval<_A0>(), declval<_A1>())) type;
};

template <class _Fn, class _A0, class _A1, class _A2>
class __result_of<_Fn(_A0, _A1, _A2), true, false>
{
public:
    typedef __decltype(declval<_Fn>()(declval<_A0>(), declval<_A1>(), declval<_A2>())) type;
};

template <class _MP, class _Tp, bool _IsMemberFunctionPtr>
struct __result_of_mp;



template <class _MP, class _Tp>
struct __result_of_mp<_MP, _Tp, true>
    : public __identity<typename __member_pointer_traits<_MP>::_ReturnType>
{
};



template <class _MP, class _Tp, bool>
struct __result_of_mdp;

template <class _Rp, class _Class, class _Tp>
struct __result_of_mdp<_Rp _Class::*, _Tp, false>
{
    typedef typename __apply_cv<__decltype(*std::__1::declval<_Tp>()), _Rp>::type& type;
};

template <class _Rp, class _Class, class _Tp>
struct __result_of_mdp<_Rp _Class::*, _Tp, true>
{
    typedef typename __apply_cv<_Tp, _Rp>::type& type;
};

template <class _Rp, class _Class, class _Tp>
struct __result_of_mp<_Rp _Class::*, _Tp, false>
    : public __result_of_mdp<_Rp _Class::*, _Tp,
            is_base_of<_Class, typename remove_reference<_Tp>::type>::value>
{
};



template <class _Fn, class _Tp>
class __result_of<_Fn(_Tp), false, true>
    : public __result_of_mp<typename remove_reference<_Fn>::type,
                            _Tp,
                            is_member_function_pointer<typename remove_reference<_Fn>::type>::value>
{
};

template <class _Fn, class _Tp, class _A0>
class __result_of<_Fn(_Tp, _A0), false, true>
    : public __result_of_mp<typename remove_reference<_Fn>::type,
                            _Tp,
                            is_member_function_pointer<typename remove_reference<_Fn>::type>::value>
{
};

template <class _Fn, class _Tp, class _A0, class _A1>
class __result_of<_Fn(_Tp, _A0, _A1), false, true>
    : public __result_of_mp<typename remove_reference<_Fn>::type,
                            _Tp,
                            is_member_function_pointer<typename remove_reference<_Fn>::type>::value>
{
};

template <class _Fn, class _Tp, class _A0, class _A1, class _A2>
class __result_of<_Fn(_Tp, _A0, _A1, _A2), false, true>
    : public __result_of_mp<typename remove_reference<_Fn>::type,
                            _Tp,
                            is_member_function_pointer<typename remove_reference<_Fn>::type>::value>
{
};



template <class _Fn>
class __attribute__ ((__type_visibility__("default"))) result_of<_Fn()>
    : public __result_of<_Fn(),
                         is_class<typename remove_reference<_Fn>::type>::value ||
                         is_function<typename remove_pointer<typename remove_reference<_Fn>::type>::type>::value,
                         is_member_pointer<typename remove_reference<_Fn>::type>::value
                        >
{
};

template <class _Fn, class _A0>
class __attribute__ ((__type_visibility__("default"))) result_of<_Fn(_A0)>
    : public __result_of<_Fn(_A0),
                         is_class<typename remove_reference<_Fn>::type>::value ||
                         is_function<typename remove_pointer<typename remove_reference<_Fn>::type>::type>::value,
                         is_member_pointer<typename remove_reference<_Fn>::type>::value
                        >
{
};

template <class _Fn, class _A0, class _A1>
class __attribute__ ((__type_visibility__("default"))) result_of<_Fn(_A0, _A1)>
    : public __result_of<_Fn(_A0, _A1),
                         is_class<typename remove_reference<_Fn>::type>::value ||
                         is_function<typename remove_pointer<typename remove_reference<_Fn>::type>::type>::value,
                         is_member_pointer<typename remove_reference<_Fn>::type>::value
                        >
{
};

template <class _Fn, class _A0, class _A1, class _A2>
class __attribute__ ((__type_visibility__("default"))) result_of<_Fn(_A0, _A1, _A2)>
    : public __result_of<_Fn(_A0, _A1, _A2),
                         is_class<typename remove_reference<_Fn>::type>::value ||
                         is_function<typename remove_pointer<typename remove_reference<_Fn>::type>::type>::value,
                         is_member_pointer<typename remove_reference<_Fn>::type>::value
                        >
{
};





namespace __is_construct
{
struct __nat {};
}

template <class _Tp, class ..._Args>
struct __attribute__ ((__type_visibility__("default"))) is_constructible
    : public integral_constant<bool, __is_constructible(_Tp, _Args...)>
    {};

template <class _Tp>
struct __attribute__ ((__type_visibility__("default"))) is_default_constructible
    : public is_constructible<_Tp>
    {};

template <class _Tp>
struct __attribute__ ((__type_visibility__("default"))) is_copy_constructible
    : public is_constructible<_Tp,
                  typename add_lvalue_reference<typename add_const<_Tp>::type>::type> {};

template <class _Tp>
struct __attribute__ ((__type_visibility__("default"))) is_move_constructible
    : public is_constructible<_Tp, typename add_rvalue_reference<_Tp>::type>
    {};

template <class _Tp, class... _Args>
struct __attribute__ ((__type_visibility__("default"))) is_trivially_constructible
    : integral_constant<bool, __is_trivially_constructible(_Tp, _Args...)>
{
};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_trivially_default_constructible
    : public is_trivially_constructible<_Tp>
    {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_trivially_copy_constructible
    : public is_trivially_constructible<_Tp, typename add_lvalue_reference<const _Tp>::type>
    {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_trivially_move_constructible
    : public is_trivially_constructible<_Tp, typename add_rvalue_reference<_Tp>::type>
    {};

template <class _Tp, class _Arg>
struct is_trivially_assignable
    : integral_constant<bool, __is_trivially_assignable(_Tp, _Arg)>
{
};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_trivially_copy_assignable
    : public is_trivially_assignable<typename add_lvalue_reference<_Tp>::type,
                  typename add_lvalue_reference<typename add_const<_Tp>::type>::type> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_trivially_move_assignable
    : public is_trivially_assignable<typename add_lvalue_reference<_Tp>::type,
                                     typename add_rvalue_reference<_Tp>::type>
    {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_trivially_destructible
    : public integral_constant<bool, __is_trivially_destructible(_Tp)> {};

template <class _Tp, class... _Args>
struct __attribute__ ((__type_visibility__("default"))) is_nothrow_constructible
    : public integral_constant<bool, __is_nothrow_constructible(_Tp, _Args...)> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_nothrow_default_constructible
    : public is_nothrow_constructible<_Tp>
    {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_nothrow_copy_constructible
    : public is_nothrow_constructible<_Tp,
                  typename add_lvalue_reference<typename add_const<_Tp>::type>::type> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_nothrow_move_constructible
    : public is_nothrow_constructible<_Tp, typename add_rvalue_reference<_Tp>::type>
    {};

template <class _Tp, class _Arg>
struct __attribute__ ((__type_visibility__("default"))) is_nothrow_assignable
    : public integral_constant<bool, __is_nothrow_assignable(_Tp, _Arg)> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_nothrow_copy_assignable
    : public is_nothrow_assignable<typename add_lvalue_reference<_Tp>::type,
                  typename add_lvalue_reference<typename add_const<_Tp>::type>::type> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_nothrow_move_assignable
    : public is_nothrow_assignable<typename add_lvalue_reference<_Tp>::type,
                                     typename add_rvalue_reference<_Tp>::type>
    {};

template <class _Tp> struct __libcpp_nothrow_destructor
    : public integral_constant<bool, is_scalar<_Tp>::value ||
                                     is_reference<_Tp>::value> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_nothrow_destructible
    : public __libcpp_nothrow_destructor<typename remove_all_extents<_Tp>::type> {};

template <class _Tp>
struct __attribute__ ((__type_visibility__("default"))) is_nothrow_destructible<_Tp[]>
    : public false_type {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_pod
    : public integral_constant<bool, __is_pod(_Tp)> {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_literal_type
    : public integral_constant<bool, __is_literal_type(_Tp)>
    {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_standard_layout

    : public integral_constant<bool, __is_standard_layout(_Tp)>



    {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_trivially_copyable

    : public integral_constant<bool, __is_trivially_copyable(_Tp)>





    {};

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_trivial

    : public integral_constant<bool, __is_trivial(_Tp)>




    {};







template <class _Tp> struct __is_reference_wrapper_impl : public false_type {};
template <class _Tp> struct __is_reference_wrapper_impl<reference_wrapper<_Tp> > : public true_type {};
template <class _Tp> struct __is_reference_wrapper
    : public __is_reference_wrapper_impl<typename remove_cv<_Tp>::type> {};

template <class _Tp> struct __is_swappable;
template <class _Tp> struct __is_nothrow_swappable;



template <class _ForwardIterator1, class _ForwardIterator2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator2
swap_ranges(_ForwardIterator1 __first1, _ForwardIterator1 __last1, _ForwardIterator2 __first2);

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))







void


swap(_Tp& __x, _Tp& __y)

{
    _Tp __t(std::__1::move(__x));
    __x = std::__1::move(__y);
    __y = std::__1::move(__t);
}

template<class _Tp, size_t _Np>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if<
    __is_swappable<_Tp>::value
>::type
swap(_Tp (&__a)[_Np], _Tp (&__b)[_Np])
{
    std::__1::swap_ranges(__a, __a + _Np, __b);
}

template <class _ForwardIterator1, class _ForwardIterator2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator2
swap_ranges(_ForwardIterator1 __first1, _ForwardIterator1 __last1, _ForwardIterator2 __first2)
{
    for(; __first1 != __last1; ++__first1, (void) ++__first2)
        swap(*__first1, *__first2);
    return __first2;
}



template <class _ForwardIterator1, class _ForwardIterator2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b)



{
    swap(*__a, *__b);
}



namespace __detail
{


template <class _Tp, class _Up = _Tp,
          bool _NotVoid = !is_void<_Tp>::value && !is_void<_Up>::value>
struct __swappable_with
{
    template <class _LHS, class _RHS>
    static __decltype(swap(std::__1::declval<_LHS>(), std::__1::declval<_RHS>()))
    __test_swap(int);
    template <class, class>
    static __nat __test_swap(long);


    typedef __decltype((__test_swap<_Tp, _Up>(0))) __swap1;
    typedef __decltype((__test_swap<_Up, _Tp>(0))) __swap2;

    static const bool value = _IsNotSame<__swap1, __nat>::value
                           && _IsNotSame<__swap2, __nat>::value;
};

template <class _Tp, class _Up>
struct __swappable_with<_Tp, _Up, false> : false_type {};

template <class _Tp, class _Up = _Tp, bool _Swappable = __swappable_with<_Tp, _Up>::value>
struct __nothrow_swappable_with {
  static const bool value =




      false;

};

template <class _Tp, class _Up>
struct __nothrow_swappable_with<_Tp, _Up, false> : false_type {};

}

template <class _Tp>
struct __is_swappable
    : public integral_constant<bool, __detail::__swappable_with<_Tp&>::value>
{
};

template <class _Tp>
struct __is_nothrow_swappable
    : public integral_constant<bool, __detail::__nothrow_swappable_with<_Tp&>::value>
{
};

template <class _Tp, bool = is_enum<_Tp>::value> struct __underlying_type_impl;

template <class _Tp>
struct __underlying_type_impl<_Tp, false> {};

template <class _Tp>
struct __underlying_type_impl<_Tp, true>
{
    typedef __underlying_type(_Tp) type;
};

template <class _Tp>
struct underlying_type : __underlying_type_impl<_Tp, is_enum<_Tp>::value> {};






template <class _Tp, bool = is_enum<_Tp>::value>
struct __sfinae_underlying_type
{
    typedef typename underlying_type<_Tp>::type type;
    typedef __decltype(((type)1) + 0) __promoted_type;
};

template <class _Tp>
struct __sfinae_underlying_type<_Tp, false> {};

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
int __convert_to_integral(int __val) { return __val; }

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
unsigned __convert_to_integral(unsigned __val) { return __val; }

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
long __convert_to_integral(long __val) { return __val; }

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
unsigned long __convert_to_integral(unsigned long __val) { return __val; }

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
long long __convert_to_integral(long long __val) { return __val; }

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
unsigned long long __convert_to_integral(unsigned long long __val) {return __val; }

template<typename _Fp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if<is_floating_point<_Fp>::value, long long>::type
 __convert_to_integral(_Fp __val) { return __val; }


inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__int128_t __convert_to_integral(__int128_t __val) { return __val; }

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__uint128_t __convert_to_integral(__uint128_t __val) { return __val; }


template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename __sfinae_underlying_type<_Tp>::__promoted_type
__convert_to_integral(_Tp __val) { return __val; }

inline
bool __libcpp_is_constant_evaluated() throw() { return __builtin_is_constant_evaluated(); }





template <class _CharT>
using _IsCharLikeType = _And<is_standard_layout<_CharT>, is_trivial<_CharT> >;

} }






























typedef signed char __int8_t;



typedef unsigned char __uint8_t;
typedef short __int16_t;
typedef unsigned short __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long long __int64_t;
typedef unsigned long long __uint64_t;

typedef long __darwin_intptr_t;
typedef unsigned int __darwin_natural_t;

typedef int __darwin_ct_rune_t;





typedef union {
 char __mbstate8[128];
 long long _mbstateL;
} __mbstate_t;

typedef __mbstate_t __darwin_mbstate_t;


typedef long int __darwin_ptrdiff_t;







typedef long unsigned int __darwin_size_t;





typedef __builtin_va_list __darwin_va_list;





typedef int __darwin_wchar_t;




typedef __darwin_wchar_t __darwin_rune_t;


typedef int __darwin_wint_t;




typedef unsigned long __darwin_clock_t;
typedef __uint32_t __darwin_socklen_t;
typedef long __darwin_ssize_t;
typedef long __darwin_time_t;



typedef __int64_t __darwin_blkcnt_t;
typedef __int32_t __darwin_blksize_t;
typedef __int32_t __darwin_dev_t;
typedef unsigned int __darwin_fsblkcnt_t;
typedef unsigned int __darwin_fsfilcnt_t;
typedef __uint32_t __darwin_gid_t;
typedef __uint32_t __darwin_id_t;
typedef __uint64_t __darwin_ino64_t;

typedef __darwin_ino64_t __darwin_ino_t;



typedef __darwin_natural_t __darwin_mach_port_name_t;
typedef __darwin_mach_port_name_t __darwin_mach_port_t;
typedef __uint16_t __darwin_mode_t;
typedef __int64_t __darwin_off_t;
typedef __int32_t __darwin_pid_t;
typedef __uint32_t __darwin_sigset_t;
typedef __int32_t __darwin_suseconds_t;
typedef __uint32_t __darwin_uid_t;
typedef __uint32_t __darwin_useconds_t;
typedef unsigned char __darwin_uuid_t[16];
typedef char __darwin_uuid_string_t[37];




struct __darwin_pthread_handler_rec {
 void (*__routine)(void *);
 void *__arg;
 struct __darwin_pthread_handler_rec *__next;
};

struct _opaque_pthread_attr_t {
 long __sig;
 char __opaque[56];
};

struct _opaque_pthread_cond_t {
 long __sig;
 char __opaque[40];
};

struct _opaque_pthread_condattr_t {
 long __sig;
 char __opaque[8];
};

struct _opaque_pthread_mutex_t {
 long __sig;
 char __opaque[56];
};

struct _opaque_pthread_mutexattr_t {
 long __sig;
 char __opaque[8];
};

struct _opaque_pthread_once_t {
 long __sig;
 char __opaque[8];
};

struct _opaque_pthread_rwlock_t {
 long __sig;
 char __opaque[192];
};

struct _opaque_pthread_rwlockattr_t {
 long __sig;
 char __opaque[16];
};

struct _opaque_pthread_t {
 long __sig;
 struct __darwin_pthread_handler_rec *__cleanup_stack;
 char __opaque[8176];
};

typedef struct _opaque_pthread_attr_t __darwin_pthread_attr_t;
typedef struct _opaque_pthread_cond_t __darwin_pthread_cond_t;
typedef struct _opaque_pthread_condattr_t __darwin_pthread_condattr_t;
typedef unsigned long __darwin_pthread_key_t;
typedef struct _opaque_pthread_mutex_t __darwin_pthread_mutex_t;
typedef struct _opaque_pthread_mutexattr_t __darwin_pthread_mutexattr_t;
typedef struct _opaque_pthread_once_t __darwin_pthread_once_t;
typedef struct _opaque_pthread_rwlock_t __darwin_pthread_rwlock_t;
typedef struct _opaque_pthread_rwlockattr_t __darwin_pthread_rwlockattr_t;
typedef struct _opaque_pthread_t *__darwin_pthread_t;



typedef int __darwin_nl_item;
typedef int __darwin_wctrans_t;

typedef __uint32_t __darwin_wctype_t;














extern "C" {
void *memchr(const void *__s, int __c, size_t __n);
int memcmp(const void *__s1, const void *__s2, size_t __n);
void *memcpy(void *__dst, const void *__src, size_t __n);
void *memmove(void *__dst, const void *__src, size_t __len);
void *memset(void *__b, int __c, size_t __len);
char *strcat(char *__s1, const char *__s2);
char *strchr(const char *__s, int __c);
int strcmp(const char *__s1, const char *__s2);
int strcoll(const char *__s1, const char *__s2);
char *strcpy(char *__dst, const char *__src);
size_t strcspn(const char *__s, const char *__charset);
char *strerror(int __errnum) __asm("_" "strerror" );
size_t strlen(const char *__s);
char *strncat(char *__s1, const char *__s2, size_t __n);
int strncmp(const char *__s1, const char *__s2, size_t __n);
char *strncpy(char *__dst, const char *__src, size_t __n);
char *strpbrk(const char *__s, const char *__charset);
char *strrchr(const char *__s, int __c);
size_t strspn(const char *__s, const char *__charset);
char *strstr(const char *__big, const char *__little);
char *strtok(char *__str, const char *__sep);
size_t strxfrm(char *__s1, const char *__s2, size_t __n);
}

extern "C" {
char *strtok_r(char *__str, const char *__sep, char **__lasts);
}

extern "C" {
int strerror_r(int __errnum, char *__strerrbuf, size_t __buflen);
char *strdup(const char *__s1);
void *memccpy(void *__dst, const void *__src, int __c, size_t __n);
}

extern "C" {
char *stpcpy(char *__dst, const char *__src);
char *stpncpy(char *__dst, const char *__src, size_t __n) __attribute__((availability(macosx,introduced=10.7)));
char *strndup(const char *__s1, size_t __n) __attribute__((availability(macosx,introduced=10.7)));
size_t strnlen(const char *__s1, size_t __n) __attribute__((availability(macosx,introduced=10.7)));
char *strsignal(int __sig);
}














typedef signed char int8_t;



typedef short int16_t;



typedef int int32_t;



typedef long long int64_t;




typedef unsigned char u_int8_t;



typedef unsigned short u_int16_t;



typedef unsigned int u_int32_t;



typedef unsigned long long u_int64_t;



typedef int64_t register_t;










typedef __darwin_intptr_t intptr_t;



typedef unsigned long uintptr_t;




typedef u_int64_t user_addr_t;
typedef u_int64_t user_size_t;
typedef int64_t user_ssize_t;
typedef int64_t user_long_t;
typedef u_int64_t user_ulong_t;
typedef int64_t user_time_t;
typedef int64_t user_off_t;







typedef u_int64_t syscall_arg_t;


typedef __darwin_size_t rsize_t;



typedef int errno_t;


extern "C" {
errno_t memset_s(void *__s, rsize_t __smax, int __c, rsize_t __n) __attribute__((availability(macosx,introduced=10.9)));
}








typedef __darwin_ssize_t ssize_t;


extern "C" {
void *memmem(const void *__big, size_t __big_len, const void *__little, size_t __little_len) __attribute__((availability(macosx,introduced=10.7)));
void memset_pattern4(void *__b, const void *__pattern4, size_t __len) __attribute__((availability(macosx,introduced=10.5)));
void memset_pattern8(void *__b, const void *__pattern8, size_t __len) __attribute__((availability(macosx,introduced=10.5)));
void memset_pattern16(void *__b, const void *__pattern16, size_t __len) __attribute__((availability(macosx,introduced=10.5)));

char *strcasestr(const char *__big, const char *__little);
char *strnstr(const char *__big, const char *__little, size_t __len);
size_t strlcat(char *__dst, const char *__source, size_t __size);
size_t strlcpy(char *__dst, const char *__source, size_t __size);
void strmode(int __mode, char *__bp);
char *strsep(char **__stringp, const char *__delim);


void swab(const void * , void * , ssize_t);

__attribute__((availability(macosx,introduced=10.12.1))) __attribute__((availability(ios,introduced=10.1)))
__attribute__((availability(tvos,introduced=10.0.1))) __attribute__((availability(watchos,introduced=3.1)))
int timingsafe_bcmp(const void *__b1, const void *__b2, size_t __len);
}












extern "C" {


int bcmp(const void *, const void *, size_t) ;
void bcopy(const void *, void *, size_t) ;
void bzero(void *, size_t) ;
char *index(const char *, int) ;
char *rindex(const char *, int) ;


int ffs(int);
int strcasecmp(const char *, const char *);
int strncasecmp(const char *, const char *, size_t);
}



extern "C" {
int ffsl(long) __attribute__((availability(macosx,introduced=10.5)));
int ffsll(long long) __attribute__((availability(macosx,introduced=10.9)));
int fls(int) __attribute__((availability(macosx,introduced=10.5)));
int flsl(long) __attribute__((availability(macosx,introduced=10.5)));
int flsll(long long) __attribute__((availability(macosx,introduced=10.9)));
}







extern "C++" {
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
char* __libcpp_strchr(const char* __s, int __c) {return (char*)strchr(__s, __c);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
const char* strchr(const char* __s, int __c) {return __libcpp_strchr(__s, __c);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
      char* strchr( char* __s, int __c) {return __libcpp_strchr(__s, __c);}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
char* __libcpp_strpbrk(const char* __s1, const char* __s2) {return (char*)strpbrk(__s1, __s2);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
const char* strpbrk(const char* __s1, const char* __s2) {return __libcpp_strpbrk(__s1, __s2);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
      char* strpbrk( char* __s1, const char* __s2) {return __libcpp_strpbrk(__s1, __s2);}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
char* __libcpp_strrchr(const char* __s, int __c) {return (char*)strrchr(__s, __c);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
const char* strrchr(const char* __s, int __c) {return __libcpp_strrchr(__s, __c);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
      char* strrchr( char* __s, int __c) {return __libcpp_strrchr(__s, __c);}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void* __libcpp_memchr(const void* __s, int __c, size_t __n) {return (void*)memchr(__s, __c, __n);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
const void* memchr(const void* __s, int __c, size_t __n) {return __libcpp_memchr(__s, __c, __n);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
      void* memchr( void* __s, int __c, size_t __n) {return __libcpp_memchr(__s, __c, __n);}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
char* __libcpp_strstr(const char* __s1, const char* __s2) {return (char*)strstr(__s1, __s2);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
const char* strstr(const char* __s1, const char* __s2) {return __libcpp_strstr(__s1, __s2);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
      char* strstr( char* __s1, const char* __s2) {return __libcpp_strstr(__s1, __s2);}
}




namespace std { inline namespace __1 {

using ::size_t;
using ::memcpy;
using ::memmove;
using ::strcpy;
using ::strncpy;
using ::strcat;
using ::strncat;
using ::memcmp;
using ::strcmp;
using ::strncmp;
using ::strcoll;
using ::strxfrm;
using ::memchr;
using ::strchr;
using ::strcspn;
using ::strpbrk;
using ::strrchr;
using ::strspn;
using ::strstr;

using ::strtok;

using ::memset;
using ::strerror;
using ::strlen;

} }













namespace std { inline namespace __1 {

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) tuple_size;

template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) tuple_size<const _Tp> : public tuple_size<_Tp> {};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) tuple_size<volatile _Tp> : public tuple_size<_Tp> {};
template <class _Tp> struct __attribute__ ((__type_visibility__("default"))) tuple_size<const volatile _Tp> : public tuple_size<_Tp> {};


template <size_t _Ip, class _Tp> struct __attribute__ ((__type_visibility__("default"))) tuple_element;

template <size_t _Ip, class _Tp>
struct __attribute__ ((__type_visibility__("default"))) tuple_element<_Ip, const _Tp>
{
    typedef typename add_const<typename tuple_element<_Ip, _Tp>::type>::type type;
};

template <size_t _Ip, class _Tp>
struct __attribute__ ((__type_visibility__("default"))) tuple_element<_Ip, volatile _Tp>
{
    typedef typename add_volatile<typename tuple_element<_Ip, _Tp>::type>::type type;
};

template <size_t _Ip, class _Tp>
struct __attribute__ ((__type_visibility__("default"))) tuple_element<_Ip, const volatile _Tp>
{
    typedef typename add_cv<typename tuple_element<_Ip, _Tp>::type>::type type;
};

template <class _Tp> struct __tuple_like : false_type {};

template <class _Tp> struct __tuple_like<const _Tp> : public __tuple_like<_Tp> {};
template <class _Tp> struct __tuple_like<volatile _Tp> : public __tuple_like<_Tp> {};
template <class _Tp> struct __tuple_like<const volatile _Tp> : public __tuple_like<_Tp> {};

template <class _T1, class _T2> struct __tuple_like<pair<_T1, _T2> > : true_type {};

template <size_t _Ip, class _T1, class _T2>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename tuple_element<_Ip, pair<_T1, _T2> >::type&
get(pair<_T1, _T2>&) throw();

template <size_t _Ip, class _T1, class _T2>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
const typename tuple_element<_Ip, pair<_T1, _T2> >::type&
get(const pair<_T1, _T2>&) throw();

template <class _Tp, size_t _Size> struct __attribute__ ((__type_visibility__("default"))) array;

template <class _Tp, size_t _Size> struct __tuple_like<array<_Tp, _Size> > : true_type {};

template <size_t _Ip, class _Tp, size_t _Size>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp&
get(array<_Tp, _Size>&) throw();

template <size_t _Ip, class _Tp, size_t _Size>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
const _Tp&
get(const array<_Tp, _Size>&) throw();

} }





















typedef unsigned char uint8_t;



typedef unsigned short uint16_t;



typedef unsigned int uint32_t;



typedef unsigned long long uint64_t;



typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;



typedef int8_t int_fast8_t;
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;
typedef uint8_t uint_fast8_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;



typedef long int intmax_t;



typedef long unsigned int uintmax_t;







namespace std { inline namespace __1 {

using::int8_t;
using::int16_t;
using::int32_t;
using::int64_t;

using::uint8_t;
using::uint16_t;
using::uint32_t;
using::uint64_t;

using::int_least8_t;
using::int_least16_t;
using::int_least32_t;
using::int_least64_t;

using::uint_least8_t;
using::uint_least16_t;
using::uint_least32_t;
using::uint_least64_t;

using::int_fast8_t;
using::int_fast16_t;
using::int_fast32_t;
using::int_fast64_t;

using::uint_fast8_t;
using::uint_fast16_t;
using::uint_fast32_t;
using::uint_fast64_t;

using::intptr_t;
using::uintptr_t;

using::intmax_t;
using::uintmax_t;

} }





























typedef __darwin_mbstate_t mbstate_t;



typedef __darwin_ct_rune_t ct_rune_t;



typedef __darwin_rune_t rune_t;






typedef __builtin_va_list va_list;

typedef __builtin_va_list __gnuc_va_list;














typedef __darwin_va_list va_list;








extern "C" {

int renameat(int, const char *, int, const char *) __attribute__((availability(macosx,introduced=10.10)));






int renamex_np(const char *, const char *, unsigned int) __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));
int renameatx_np(int, const char *, int, const char *, unsigned int) __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));



}


typedef __darwin_off_t fpos_t;

struct __sbuf {
 unsigned char *_base;
 int _size;
};


struct __sFILEX;

typedef struct __sFILE {
 unsigned char *_p;
 int _r;
 int _w;
 short _flags;
 short _file;
 struct __sbuf _bf;
 int _lbfsize;


 void *_cookie;
 int (* _Nullable _close)(void *);
 int (* _Nullable _read) (void *, char *, int);
 fpos_t (* _Nullable _seek) (void *, fpos_t, int);
 int (* _Nullable _write)(void *, const char *, int);


 struct __sbuf _ub;
 struct __sFILEX *_extra;
 int _ur;


 unsigned char _ubuf[3];
 unsigned char _nbuf[1];


 struct __sbuf _lb;


 int _blksize;
 fpos_t _offset;
} FILE;


extern "C" {
extern FILE *__stdinp;
extern FILE *__stdoutp;
extern FILE *__stderrp;
}

extern "C" {
void clearerr(FILE *);
int fclose(FILE *);
int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
int fgetc(FILE *);
int fgetpos(FILE * , fpos_t *);
char *fgets(char * , int, FILE *);



FILE *fopen(const char * __filename, const char * __mode) __asm("_" "fopen" );

int fprintf(FILE * , const char * , ...) __attribute__((__format__ (__printf__, 2, 3)));
int fputc(int, FILE *);
int fputs(const char * , FILE * ) __asm("_" "fputs" );
size_t fread(void * __ptr, size_t __size, size_t __nitems, FILE * __stream);
FILE *freopen(const char * , const char * ,
                 FILE * ) __asm("_" "freopen" );
int fscanf(FILE * , const char * , ...) __attribute__((__format__ (__scanf__, 2, 3)));
int fseek(FILE *, long, int);
int fsetpos(FILE *, const fpos_t *);
long ftell(FILE *);
size_t fwrite(const void * __ptr, size_t __size, size_t __nitems, FILE * __stream) __asm("_" "fwrite" );
int getc(FILE *);
int getchar(void);
char *gets(char *);
void perror(const char *) __attribute__((__cold__));
int printf(const char * , ...) __attribute__((__format__ (__printf__, 1, 2)));
int putc(int, FILE *);
int putchar(int);
int puts(const char *);
int remove(const char *);
int rename (const char *__old, const char *__new);
void rewind(FILE *);
int scanf(const char * , ...) __attribute__((__format__ (__scanf__, 1, 2)));
void setbuf(FILE * , char * );
int setvbuf(FILE * , char * , int, size_t);
int sprintf(char * , const char * , ...) __attribute__((__format__ (__printf__, 2, 3))) __attribute__((__availability__(swift, unavailable, message="Use snprintf instead.")));
int sscanf(const char * , const char * , ...) __attribute__((__format__ (__scanf__, 2, 3)));
FILE *tmpfile(void);

__attribute__((__availability__(swift, unavailable, message="Use mkstemp(3) instead.")))

__attribute__((__deprecated__("This function is provided for compatibility reasons only.  Due to security concerns inherent in the design of tmpnam(3), it is highly recommended that you use mkstemp(3) instead.")))

char *tmpnam(char *);
int ungetc(int, FILE *);
int vfprintf(FILE * , const char * , va_list) __attribute__((__format__ (__printf__, 2, 0)));
int vprintf(const char * , va_list) __attribute__((__format__ (__printf__, 1, 0)));
int vsprintf(char * , const char * , va_list) __attribute__((__format__ (__printf__, 2, 0))) __attribute__((__availability__(swift, unavailable, message="Use vsnprintf instead.")));
}

extern "C" {



char *ctermid(char *);





FILE *fdopen(int, const char *) __asm("_" "fdopen" );

int fileno(FILE *);
}

extern "C" {
int pclose(FILE *) __attribute__((__availability__(swift, unavailable, message="Use posix_spawn APIs or NSTask instead.")));



FILE *popen(const char *, const char *) __asm("_" "popen" ) __attribute__((__availability__(swift, unavailable, message="Use posix_spawn APIs or NSTask instead.")));

}

extern "C" {
int __srget(FILE *);
int __svfscanf(FILE *, const char *, va_list) __attribute__((__format__ (__scanf__, 2, 0)));
int __swbuf(int, FILE *);
}







inline __attribute__ ((__always_inline__)) int __sputc(int _c, FILE *_p) {
 if (--_p->_w >= 0 || (_p->_w >= _p->_lbfsize && (char)_c != '\n'))
  return (*_p->_p++ = _c);
 else
  return (__swbuf(_c, _p));
}

extern "C" {
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);



int getw(FILE *);
int putw(int, FILE *);


__attribute__((__availability__(swift, unavailable, message="Use mkstemp(3) instead.")))

__attribute__((__deprecated__("This function is provided for compatibility reasons only.  Due to security concerns inherent in the design of tempnam(3), it is highly recommended that you use mkstemp(3) instead.")))

char *tempnam(const char *__dir, const char *__prefix) __asm("_" "tempnam" );
}



typedef __darwin_off_t off_t;


extern "C" {
int fseeko(FILE * __stream, off_t __offset, int __whence);
off_t ftello(FILE * __stream);
}



extern "C" {
int snprintf(char * __str, size_t __size, const char * __format, ...) __attribute__((__format__ (__printf__, 3, 4)));
int vfscanf(FILE * __stream, const char * __format, va_list) __attribute__((__format__ (__scanf__, 2, 0)));
int vscanf(const char * __format, va_list) __attribute__((__format__ (__scanf__, 1, 0)));
int vsnprintf(char * __str, size_t __size, const char * __format, va_list) __attribute__((__format__ (__printf__, 3, 0)));
int vsscanf(const char * __str, const char * __format, va_list) __attribute__((__format__ (__scanf__, 2, 0)));
}

extern "C" {
int dprintf(int, const char * , ...) __attribute__((__format__ (__printf__, 2, 3))) __attribute__((availability(macosx,introduced=10.7)));
int vdprintf(int, const char * , va_list) __attribute__((__format__ (__printf__, 2, 0))) __attribute__((availability(macosx,introduced=10.7)));
ssize_t getdelim(char ** __linep, size_t * __linecapp, int __delimiter, FILE * __stream) __attribute__((availability(macosx,introduced=10.7)));
ssize_t getline(char ** __linep, size_t * __linecapp, FILE * __stream) __attribute__((availability(macosx,introduced=10.7)));
FILE *fmemopen(void * __buf, size_t __size, const char * __mode) __attribute__((availability(macos,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
FILE *open_memstream(char **__bufp, size_t *__sizep) __attribute__((availability(macos,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
}







extern "C" {
extern const int sys_nerr;
extern const char *const sys_errlist[];

int asprintf(char ** , const char * , ...) __attribute__((__format__ (__printf__, 2, 3)));
char *ctermid_r(char *);
char *fgetln(FILE *, size_t *);
const char *fmtcheck(const char *, const char *);
int fpurge(FILE *);
void setbuffer(FILE *, char *, int);
int setlinebuf(FILE *);
int vasprintf(char ** , const char * , va_list) __attribute__((__format__ (__printf__, 2, 0)));
FILE *zopen(const char *, const char *, int);





FILE *funopen(const void *,
                 int (* _Nullable)(void *, char *, int),
                 int (* _Nullable)(void *, const char *, int),
                 fpos_t (* _Nullable)(void *, fpos_t, int),
                 int (* _Nullable)(void *));
}






typedef __darwin_clock_t clock_t;







typedef __darwin_time_t time_t;



struct timespec
{
 __darwin_time_t tv_sec;
 long tv_nsec;
};


struct tm {
 int tm_sec;
 int tm_min;
 int tm_hour;
 int tm_mday;
 int tm_mon;
 int tm_year;
 int tm_wday;
 int tm_yday;
 int tm_isdst;
 long tm_gmtoff;
 char *tm_zone;
};

extern char *tzname[];


extern int getdate_err;

extern long timezone __asm("_" "timezone" );

extern int daylight;

extern "C" {
char *asctime(const struct tm *);
clock_t clock(void) __asm("_" "clock" );
char *ctime(const time_t *);
double difftime(time_t, time_t);
struct tm *getdate(const char *);
struct tm *gmtime(const time_t *);
struct tm *localtime(const time_t *);
time_t mktime(struct tm *) __asm("_" "mktime" );
size_t strftime(char * , size_t, const char * , const struct tm * ) __asm("_" "strftime" );
char *strptime(const char * , const char * , struct tm * ) __asm("_" "strptime" );
time_t time(time_t *);


void tzset(void);



char *asctime_r(const struct tm * , char * );
char *ctime_r(const time_t *, char *);
struct tm *gmtime_r(const time_t * , struct tm * );
struct tm *localtime_r(const time_t * , struct tm * );


time_t posix2time(time_t);



void tzsetwall(void);
time_t time2posix(time_t);
time_t timelocal(struct tm * const);
time_t timegm(struct tm * const);



int nanosleep(const struct timespec *__rqtp, struct timespec *__rmtp) __asm("_" "nanosleep" );

typedef enum {
_CLOCK_REALTIME __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 0,

_CLOCK_MONOTONIC __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 6,


_CLOCK_MONOTONIC_RAW __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 4,

_CLOCK_MONOTONIC_RAW_APPROX __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 5,

_CLOCK_UPTIME_RAW __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 8,

_CLOCK_UPTIME_RAW_APPROX __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 9,


_CLOCK_PROCESS_CPUTIME_ID __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 12,

_CLOCK_THREAD_CPUTIME_ID __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 16

} clockid_t;

__attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
int clock_getres(clockid_t __clock_id, struct timespec *__res);

__attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
int clock_gettime(clockid_t __clock_id, struct timespec *__tp);


__attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
__uint64_t clock_gettime_nsec_np(clockid_t __clock_id);


__attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,unavailable)))
__attribute__((availability(tvos,unavailable))) __attribute__((availability(watchos,unavailable)))
int clock_settime(clockid_t __clock_id, const struct timespec *__tp);

}







typedef __darwin_wint_t wint_t;




typedef __darwin_wctype_t wctype_t;






















typedef struct {
 __darwin_rune_t __min;
 __darwin_rune_t __max;
 __darwin_rune_t __map;
 __uint32_t *__types;
} _RuneEntry;

typedef struct {
 int __nranges;
 _RuneEntry *__ranges;
} _RuneRange;

typedef struct {
 char __name[14];
 __uint32_t __mask;
} _RuneCharClass;

typedef struct {
 char __magic[8];
 char __encoding[32];

 __darwin_rune_t (*__sgetrune)(const char *, __darwin_size_t, char const **);
 int (*__sputrune)(__darwin_rune_t, char *, __darwin_size_t, char **);
 __darwin_rune_t __invalid_rune;

 __uint32_t __runetype[(1 <<8 )];
 __darwin_rune_t __maplower[(1 <<8 )];
 __darwin_rune_t __mapupper[(1 <<8 )];






 _RuneRange __runetype_ext;
 _RuneRange __maplower_ext;
 _RuneRange __mapupper_ext;

 void *__variable;
 int __variable_len;




 int __ncharclasses;
 _RuneCharClass *__charclasses;
} _RuneLocale;



extern "C" {
extern _RuneLocale _DefaultRuneLocale;
extern _RuneLocale *_CurrentRuneLocale;
}


extern "C" {
unsigned long ___runetype(__darwin_ct_rune_t);
__darwin_ct_rune_t ___tolower(__darwin_ct_rune_t);
__darwin_ct_rune_t ___toupper(__darwin_ct_rune_t);
}

inline int
isascii(int _c)
{
 return ((_c & ~0x7F) == 0);
}

extern "C" {
int __maskrune(__darwin_ct_rune_t, unsigned long);
}


inline int
__istype(__darwin_ct_rune_t _c, unsigned long _f)
{



 return (isascii(_c) ? !!(_DefaultRuneLocale.__runetype[_c] & _f)
  : !!__maskrune(_c, _f));

}

inline __darwin_ct_rune_t
__isctype(__darwin_ct_rune_t _c, unsigned long _f)
{



 return (_c < 0 || _c >= (1 <<8 )) ? 0 :
  !!(_DefaultRuneLocale.__runetype[_c] & _f);

}

extern "C" {
__darwin_ct_rune_t __toupper(__darwin_ct_rune_t);
__darwin_ct_rune_t __tolower(__darwin_ct_rune_t);
}


inline int
__wcwidth(__darwin_ct_rune_t _c)
{
 unsigned int _x;

 if (_c == 0)
  return (0);
 _x = (unsigned int)__maskrune(_c, 0xe0000000L|0x00040000L);
 if ((_x & 0xe0000000L) != 0)
  return ((_x & 0xe0000000L) >> 30);
 return ((_x & 0x00040000L) != 0 ? 1 : -1);
}






inline int
isalnum(int _c)
{
 return (__istype(_c, 0x00000100L|0x00000400L));
}

inline int
isalpha(int _c)
{
 return (__istype(_c, 0x00000100L));
}

inline int
isblank(int _c)
{
 return (__istype(_c, 0x00020000L));
}

inline int
iscntrl(int _c)
{
 return (__istype(_c, 0x00000200L));
}


inline int
isdigit(int _c)
{
 return (__isctype(_c, 0x00000400L));
}

inline int
isgraph(int _c)
{
 return (__istype(_c, 0x00000800L));
}

inline int
islower(int _c)
{
 return (__istype(_c, 0x00001000L));
}

inline int
isprint(int _c)
{
 return (__istype(_c, 0x00040000L));
}

inline int
ispunct(int _c)
{
 return (__istype(_c, 0x00002000L));
}

inline int
isspace(int _c)
{
 return (__istype(_c, 0x00004000L));
}

inline int
isupper(int _c)
{
 return (__istype(_c, 0x00008000L));
}


inline int
isxdigit(int _c)
{
 return (__isctype(_c, 0x00010000L));
}

inline int
toascii(int _c)
{
 return (_c & 0x7F);
}

inline int
tolower(int _c)
{
        return (__tolower(_c));
}

inline int
toupper(int _c)
{
        return (__toupper(_c));
}


inline int
digittoint(int _c)
{
 return (__maskrune(_c, 0x0F));
}

inline int
ishexnumber(int _c)
{
 return (__istype(_c, 0x00010000L));
}

inline int
isideogram(int _c)
{
 return (__istype(_c, 0x00080000L));
}

inline int
isnumber(int _c)
{
 return (__istype(_c, 0x00000400L));
}

inline int
isphonogram(int _c)
{
 return (__istype(_c, 0x00200000L));
}

inline int
isrune(int _c)
{
 return (__istype(_c, 0xFFFFFFF0L));
}

inline int
isspecial(int _c)
{
 return (__istype(_c, 0x00100000L));
}











inline int
iswalnum(wint_t _wc)
{
 return (__istype(_wc, 0x00000100L|0x00000400L));
}

inline int
iswalpha(wint_t _wc)
{
 return (__istype(_wc, 0x00000100L));
}

inline int
iswcntrl(wint_t _wc)
{
 return (__istype(_wc, 0x00000200L));
}

inline int
iswctype(wint_t _wc, wctype_t _charclass)
{
 return (__istype(_wc, _charclass));
}

inline int
iswdigit(wint_t _wc)
{
 return (__isctype(_wc, 0x00000400L));
}

inline int
iswgraph(wint_t _wc)
{
 return (__istype(_wc, 0x00000800L));
}

inline int
iswlower(wint_t _wc)
{
 return (__istype(_wc, 0x00001000L));
}

inline int
iswprint(wint_t _wc)
{
 return (__istype(_wc, 0x00040000L));
}

inline int
iswpunct(wint_t _wc)
{
 return (__istype(_wc, 0x00002000L));
}

inline int
iswspace(wint_t _wc)
{
 return (__istype(_wc, 0x00004000L));
}

inline int
iswupper(wint_t _wc)
{
 return (__istype(_wc, 0x00008000L));
}

inline int
iswxdigit(wint_t _wc)
{
 return (__isctype(_wc, 0x00010000L));
}

inline wint_t
towlower(wint_t _wc)
{
        return (__tolower(_wc));
}

inline wint_t
towupper(wint_t _wc)
{
        return (__toupper(_wc));
}

extern "C" {
wctype_t
 wctype(const char *);
}




extern "C" {
wint_t btowc(int);
wint_t fgetwc(FILE *);
wchar_t *fgetws(wchar_t * , int, FILE * );
wint_t fputwc(wchar_t, FILE *);
int fputws(const wchar_t * , FILE * );
int fwide(FILE *, int);
int fwprintf(FILE * , const wchar_t * , ...);
int fwscanf(FILE * , const wchar_t * , ...);
wint_t getwc(FILE *);
wint_t getwchar(void);
size_t mbrlen(const char * , size_t, mbstate_t * );
size_t mbrtowc(wchar_t * , const char * , size_t,
     mbstate_t * );
int mbsinit(const mbstate_t *);
size_t mbsrtowcs(wchar_t * , const char ** , size_t,
     mbstate_t * );
wint_t putwc(wchar_t, FILE *);
wint_t putwchar(wchar_t);
int swprintf(wchar_t * , size_t, const wchar_t * , ...);
int swscanf(const wchar_t * , const wchar_t * , ...);
wint_t ungetwc(wint_t, FILE *);
int vfwprintf(FILE * , const wchar_t * ,
     __darwin_va_list);
int vswprintf(wchar_t * , size_t, const wchar_t * ,
     __darwin_va_list);
int vwprintf(const wchar_t * , __darwin_va_list);
size_t wcrtomb(char * , wchar_t, mbstate_t * );
wchar_t *wcscat(wchar_t * , const wchar_t * );
wchar_t *wcschr(const wchar_t *, wchar_t);
int wcscmp(const wchar_t *, const wchar_t *);
int wcscoll(const wchar_t *, const wchar_t *);
wchar_t *wcscpy(wchar_t * , const wchar_t * );
size_t wcscspn(const wchar_t *, const wchar_t *);
size_t wcsftime(wchar_t * , size_t, const wchar_t * ,
     const struct tm * ) __asm("_" "wcsftime" );
size_t wcslen(const wchar_t *);
wchar_t *wcsncat(wchar_t * , const wchar_t * , size_t);
int wcsncmp(const wchar_t *, const wchar_t *, size_t);
wchar_t *wcsncpy(wchar_t * , const wchar_t * , size_t);
wchar_t *wcspbrk(const wchar_t *, const wchar_t *);
wchar_t *wcsrchr(const wchar_t *, wchar_t);
size_t wcsrtombs(char * , const wchar_t ** , size_t,
     mbstate_t * );
size_t wcsspn(const wchar_t *, const wchar_t *);
wchar_t *wcsstr(const wchar_t * , const wchar_t * );
size_t wcsxfrm(wchar_t * , const wchar_t * , size_t);
int wctob(wint_t);
double wcstod(const wchar_t * , wchar_t ** );
wchar_t *wcstok(wchar_t * , const wchar_t * ,
     wchar_t ** );
long wcstol(const wchar_t * , wchar_t ** , int);
unsigned long
  wcstoul(const wchar_t * , wchar_t ** , int);
wchar_t *wmemchr(const wchar_t *, wchar_t, size_t);
int wmemcmp(const wchar_t *, const wchar_t *, size_t);
wchar_t *wmemcpy(wchar_t * , const wchar_t * , size_t);
wchar_t *wmemmove(wchar_t *, const wchar_t *, size_t);
wchar_t *wmemset(wchar_t *, wchar_t, size_t);
int wprintf(const wchar_t * , ...);
int wscanf(const wchar_t * , ...);
int wcswidth(const wchar_t *, size_t);
int wcwidth(wchar_t);
}

extern "C" {
int vfwscanf(FILE * , const wchar_t * ,
     __darwin_va_list);
int vswscanf(const wchar_t * , const wchar_t * ,
     __darwin_va_list);
int vwscanf(const wchar_t * , __darwin_va_list);
float wcstof(const wchar_t * , wchar_t ** );
long double
 wcstold(const wchar_t * , wchar_t ** );

long long
 wcstoll(const wchar_t * , wchar_t ** , int);
unsigned long long
 wcstoull(const wchar_t * , wchar_t ** , int);

}

extern "C" {
size_t mbsnrtowcs(wchar_t * , const char ** , size_t,
            size_t, mbstate_t * );
wchar_t *wcpcpy(wchar_t * , const wchar_t * ) __attribute__((availability(macosx,introduced=10.7)));
wchar_t *wcpncpy(wchar_t * , const wchar_t * , size_t) __attribute__((availability(macosx,introduced=10.7)));
wchar_t *wcsdup(const wchar_t *) __attribute__((availability(macosx,introduced=10.7)));
int wcscasecmp(const wchar_t *, const wchar_t *) __attribute__((availability(macosx,introduced=10.7)));
int wcsncasecmp(const wchar_t *, const wchar_t *, size_t n) __attribute__((availability(macosx,introduced=10.7)));
size_t wcsnlen(const wchar_t *, size_t) __attribute__((availability(macosx,introduced=10.7)));
size_t wcsnrtombs(char * , const wchar_t ** , size_t,
            size_t, mbstate_t * );
FILE *open_wmemstream(wchar_t ** __bufp, size_t * __sizep) __attribute__((availability(macos,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
}







extern "C" {
wchar_t *fgetwln(FILE * , size_t *) __attribute__((availability(macosx,introduced=10.7)));
size_t wcslcat(wchar_t *, const wchar_t *, size_t);
size_t wcslcpy(wchar_t *, const wchar_t *, size_t);
}


extern "C++" {
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
wchar_t* __libcpp_wcschr(const wchar_t* __s, wchar_t __c) {return (wchar_t*)wcschr(__s, __c);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
const wchar_t* wcschr(const wchar_t* __s, wchar_t __c) {return __libcpp_wcschr(__s, __c);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
      wchar_t* wcschr( wchar_t* __s, wchar_t __c) {return __libcpp_wcschr(__s, __c);}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
wchar_t* __libcpp_wcspbrk(const wchar_t* __s1, const wchar_t* __s2) {return (wchar_t*)wcspbrk(__s1, __s2);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
const wchar_t* wcspbrk(const wchar_t* __s1, const wchar_t* __s2) {return __libcpp_wcspbrk(__s1, __s2);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
      wchar_t* wcspbrk( wchar_t* __s1, const wchar_t* __s2) {return __libcpp_wcspbrk(__s1, __s2);}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
wchar_t* __libcpp_wcsrchr(const wchar_t* __s, wchar_t __c) {return (wchar_t*)wcsrchr(__s, __c);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
const wchar_t* wcsrchr(const wchar_t* __s, wchar_t __c) {return __libcpp_wcsrchr(__s, __c);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
      wchar_t* wcsrchr( wchar_t* __s, wchar_t __c) {return __libcpp_wcsrchr(__s, __c);}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
wchar_t* __libcpp_wcsstr(const wchar_t* __s1, const wchar_t* __s2) {return (wchar_t*)wcsstr(__s1, __s2);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
const wchar_t* wcsstr(const wchar_t* __s1, const wchar_t* __s2) {return __libcpp_wcsstr(__s1, __s2);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
      wchar_t* wcsstr( wchar_t* __s1, const wchar_t* __s2) {return __libcpp_wcsstr(__s1, __s2);}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
wchar_t* __libcpp_wmemchr(const wchar_t* __s, wchar_t __c, size_t __n) {return (wchar_t*)wmemchr(__s, __c, __n);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
const wchar_t* wmemchr(const wchar_t* __s, wchar_t __c, size_t __n) {return __libcpp_wmemchr(__s, __c, __n);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
      wchar_t* wmemchr( wchar_t* __s, wchar_t __c, size_t __n) {return __libcpp_wmemchr(__s, __c, __n);}
}




namespace std { inline namespace __1 {

class __attribute__ ((__visibility__("default"))) ios_base;

template<class _CharT> struct __attribute__ ((__type_visibility__("default"))) char_traits;
template<> struct char_traits<char>;



template<> struct char_traits<char16_t>;
template<> struct char_traits<char32_t>;
template<> struct char_traits<wchar_t>;

template<class _Tp> class __attribute__ ((__type_visibility__("default"))) allocator;

template <class _CharT, class _Traits = char_traits<_CharT> >
    class __attribute__ ((__type_visibility__("default"))) basic_ios;

template <class _CharT, class _Traits = char_traits<_CharT> >
    class __attribute__ ((__type_visibility__("default"))) basic_streambuf;
template <class _CharT, class _Traits = char_traits<_CharT> >
    class __attribute__ ((__type_visibility__("default"))) basic_istream;
template <class _CharT, class _Traits = char_traits<_CharT> >
    class __attribute__ ((__type_visibility__("default"))) basic_ostream;
template <class _CharT, class _Traits = char_traits<_CharT> >
    class __attribute__ ((__type_visibility__("default"))) basic_iostream;

template <class _CharT, class _Traits = char_traits<_CharT>,
          class _Allocator = allocator<_CharT> >
    class __attribute__ ((__type_visibility__("default"))) basic_stringbuf;
template <class _CharT, class _Traits = char_traits<_CharT>,
          class _Allocator = allocator<_CharT> >
    class __attribute__ ((__type_visibility__("default"))) basic_istringstream;
template <class _CharT, class _Traits = char_traits<_CharT>,
          class _Allocator = allocator<_CharT> >
    class __attribute__ ((__type_visibility__("default"))) basic_ostringstream;
template <class _CharT, class _Traits = char_traits<_CharT>,
          class _Allocator = allocator<_CharT> >
    class __attribute__ ((__type_visibility__("default"))) basic_stringstream;

template <class _CharT, class _Traits = char_traits<_CharT> >
    class __attribute__ ((__type_visibility__("default"))) basic_filebuf;
template <class _CharT, class _Traits = char_traits<_CharT> >
    class __attribute__ ((__type_visibility__("default"))) basic_ifstream;
template <class _CharT, class _Traits = char_traits<_CharT> >
    class __attribute__ ((__type_visibility__("default"))) basic_ofstream;
template <class _CharT, class _Traits = char_traits<_CharT> >
    class __attribute__ ((__type_visibility__("default"))) basic_fstream;

template <class _CharT, class _Traits = char_traits<_CharT> >
    class __attribute__ ((__type_visibility__("default"))) istreambuf_iterator;
template <class _CharT, class _Traits = char_traits<_CharT> >
    class __attribute__ ((__type_visibility__("default"))) ostreambuf_iterator;

typedef basic_ios<char> ios;
typedef basic_ios<wchar_t> wios;

typedef basic_streambuf<char> streambuf;
typedef basic_istream<char> istream;
typedef basic_ostream<char> ostream;
typedef basic_iostream<char> iostream;

typedef basic_stringbuf<char> stringbuf;
typedef basic_istringstream<char> istringstream;
typedef basic_ostringstream<char> ostringstream;
typedef basic_stringstream<char> stringstream;

typedef basic_filebuf<char> filebuf;
typedef basic_ifstream<char> ifstream;
typedef basic_ofstream<char> ofstream;
typedef basic_fstream<char> fstream;

typedef basic_streambuf<wchar_t> wstreambuf;
typedef basic_istream<wchar_t> wistream;
typedef basic_ostream<wchar_t> wostream;
typedef basic_iostream<wchar_t> wiostream;

typedef basic_stringbuf<wchar_t> wstringbuf;
typedef basic_istringstream<wchar_t> wistringstream;
typedef basic_ostringstream<wchar_t> wostringstream;
typedef basic_stringstream<wchar_t> wstringstream;

typedef basic_filebuf<wchar_t> wfilebuf;
typedef basic_ifstream<wchar_t> wifstream;
typedef basic_ofstream<wchar_t> wofstream;
typedef basic_fstream<wchar_t> wfstream;

template <class _State> class __attribute__ ((__type_visibility__("default"))) fpos;
typedef fpos<mbstate_t> streampos;
typedef fpos<mbstate_t> wstreampos;




typedef fpos<mbstate_t> u16streampos;
typedef fpos<mbstate_t> u32streampos;






typedef long long streamoff;


template <class _CharT,
          class _Traits = char_traits<_CharT>,
          class _Allocator = allocator<_CharT> >
    class __attribute__ ((__type_visibility__("default"))) basic_string;
typedef basic_string<char, char_traits<char>, allocator<char> > string;
typedef basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t> > wstring;



template <class _Tp, class _Alloc = allocator<_Tp> >
class __attribute__ ((__type_visibility__("default"))) vector;

} }



namespace std { inline namespace __1 {

struct __attribute__ ((__type_visibility__("default"))) __libcpp_debug_info {
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  __libcpp_debug_info()
      : __file_(std::__1::__get_nullptr_t()), __line_(-1), __pred_(std::__1::__get_nullptr_t()), __msg_(std::__1::__get_nullptr_t()) {}
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  __libcpp_debug_info(const char* __f, int __l, const char* __p, const char* __m)
    : __file_(__f), __line_(__l), __pred_(__p), __msg_(__m) {}

  __attribute__ ((__visibility__("default"))) std::string what() const;

  const char* __file_;
  int __line_;
  const char* __pred_;
  const char* __msg_;
};


typedef void(*__libcpp_debug_function_type)(__libcpp_debug_info const&);



extern __attribute__((__visibility__("default"))) __libcpp_debug_function_type __libcpp_debug_function;


__attribute__ ((noreturn)) __attribute__ ((__visibility__("default")))
void __libcpp_abort_debug_function(__libcpp_debug_info const&);



__attribute__ ((__visibility__("default")))
bool __libcpp_set_debug_function(__libcpp_debug_function_type __func);

} }




namespace std { inline namespace __1 {

namespace rel_ops
{

template<class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(const _Tp& __x, const _Tp& __y)
{
    return !(__x == __y);
}

template<class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator> (const _Tp& __x, const _Tp& __y)
{
    return __y < __x;
}

template<class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<=(const _Tp& __x, const _Tp& __y)
{
    return !(__y < __x);
}

template<class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>=(const _Tp& __x, const _Tp& __y)
{
    return !(__x < __y);
}

}







template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))

const _Tp&

move_if_noexcept(_Tp& __x) throw()
{
    return std::__1::move(__x);
}






struct __attribute__ ((__type_visibility__("default"))) piecewise_construct_t { explicit piecewise_construct_t() = default; };

extern __attribute__((__visibility__("default"))) const piecewise_construct_t piecewise_construct;

template <class _T1, class _T2>
struct __attribute__ ((__type_visibility__("default"))) pair



{
    typedef _T1 first_type;
    typedef _T2 second_type;

    _T1 first;
    _T2 second;

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    pair() : first(), second() {}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    pair(_T1 const& __t1, _T2 const& __t2) : first(__t1), second(__t2) {}

    template <class _U1, class _U2>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    pair(const pair<_U1, _U2>& __p) : first(__p.first), second(__p.second) {}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    pair& operator=(pair const& __p) {
        first = __p.first;
        second = __p.second;
        return *this;
    }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void
    swap(pair& __p)

    {
        using std::__1::swap;
        swap(first, __p.first);
        swap(second, __p.second);
    }
private:

};






template <class _T1, class _T2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator==(const pair<_T1,_T2>& __x, const pair<_T1,_T2>& __y)
{
    return __x.first == __y.first && __x.second == __y.second;
}

template <class _T1, class _T2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(const pair<_T1,_T2>& __x, const pair<_T1,_T2>& __y)
{
    return !(__x == __y);
}

template <class _T1, class _T2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator< (const pair<_T1,_T2>& __x, const pair<_T1,_T2>& __y)
{
    return __x.first < __y.first || (!(__y.first < __x.first) && __x.second < __y.second);
}

template <class _T1, class _T2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator> (const pair<_T1,_T2>& __x, const pair<_T1,_T2>& __y)
{
    return __y < __x;
}

template <class _T1, class _T2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>=(const pair<_T1,_T2>& __x, const pair<_T1,_T2>& __y)
{
    return !(__x < __y);
}

template <class _T1, class _T2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<=(const pair<_T1,_T2>& __x, const pair<_T1,_T2>& __y)
{
    return !(__y < __x);
}

template <class _T1, class _T2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    __is_swappable<_T1>::value &&
    __is_swappable<_T2>::value,
    void
>::type
swap(pair<_T1, _T2>& __x, pair<_T1, _T2>& __y)


{
    __x.swap(__y);
}

template <class _Tp>
struct __unwrap_reference { typedef _Tp type; };

template <class _Tp>
struct __unwrap_reference<reference_wrapper<_Tp> > { typedef _Tp& type; };

template <class _Tp>
struct __unwrap_ref_decay



    : __unwrap_reference<typename decay<_Tp>::type>

{ };

template <class _T1, class _T2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
pair<_T1,_T2>
make_pair(_T1 __x, _T2 __y)
{
    return pair<_T1, _T2>(__x, __y);
}



template <class _T1, class _T2>
  struct __attribute__ ((__type_visibility__("default"))) tuple_size<pair<_T1, _T2> >
    : public integral_constant<size_t, 2> {};

template <size_t _Ip, class _T1, class _T2>
struct __attribute__ ((__type_visibility__("default"))) tuple_element<_Ip, pair<_T1, _T2> >
{
    _Static_assert(_Ip < 2, "Index out of bounds in std::tuple_element<std::pair<T1, T2>>");
};

template <class _T1, class _T2>
struct __attribute__ ((__type_visibility__("default"))) tuple_element<0, pair<_T1, _T2> >
{
    typedef _T1 type;
};

template <class _T1, class _T2>
struct __attribute__ ((__type_visibility__("default"))) tuple_element<1, pair<_T1, _T2> >
{
    typedef _T2 type;
};

template <size_t _Ip> struct __get_pair;

template <>
struct __get_pair<0>
{
    template <class _T1, class _T2>
    static
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _T1&
    get(pair<_T1, _T2>& __p) throw() {return __p.first;}

    template <class _T1, class _T2>
    static
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const _T1&
    get(const pair<_T1, _T2>& __p) throw() {return __p.first;}

};

template <>
struct __get_pair<1>
{
    template <class _T1, class _T2>
    static
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _T2&
    get(pair<_T1, _T2>& __p) throw() {return __p.second;}

    template <class _T1, class _T2>
    static
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const _T2&
    get(const pair<_T1, _T2>& __p) throw() {return __p.second;}

};

template <size_t _Ip, class _T1, class _T2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename tuple_element<_Ip, pair<_T1, _T2> >::type&
get(pair<_T1, _T2>& __p) throw()
{
    return __get_pair<_Ip>::get(__p);
}

template <size_t _Ip, class _T1, class _T2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
const typename tuple_element<_Ip, pair<_T1, _T2> >::type&
get(const pair<_T1, _T2>& __p) throw()
{
    return __get_pair<_Ip>::get(__p);
}

template <class _Arg, class _Result>
struct __attribute__ ((__type_visibility__("default"))) unary_function
{
    typedef _Arg argument_type;
    typedef _Result result_type;
};

template <class _Size>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Size
__loadword(const void* __p)
{
    _Size __r;
    std::memcpy(&__r, __p, sizeof(__r));
    return __r;
}




template <class _Size, size_t = sizeof(_Size)*8>
struct __murmur2_or_cityhash;

template <class _Size>
struct __murmur2_or_cityhash<_Size, 32>
{
    inline _Size operator()(const void* __key, _Size __len)
         __attribute__((__no_sanitize__("unsigned-integer-overflow")));
};


template <class _Size>
_Size
__murmur2_or_cityhash<_Size, 32>::operator()(const void* __key, _Size __len)
{
    const _Size __m = 0x5bd1e995;
    const _Size __r = 24;
    _Size __h = __len;
    const unsigned char* __data = static_cast<const unsigned char*>(__key);
    for (; __len >= 4; __data += 4, __len -= 4)
    {
        _Size __k = __loadword<_Size>(__data);
        __k *= __m;
        __k ^= __k >> __r;
        __k *= __m;
        __h *= __m;
        __h ^= __k;
    }
    switch (__len)
    {
    case 3:
        __h ^= __data[2] << 16;
        __attribute__((__fallthrough__));
    case 2:
        __h ^= __data[1] << 8;
        __attribute__((__fallthrough__));
    case 1:
        __h ^= __data[0];
        __h *= __m;
    }
    __h ^= __h >> 13;
    __h *= __m;
    __h ^= __h >> 15;
    return __h;
}

template <class _Size>
struct __murmur2_or_cityhash<_Size, 64>
{
    inline _Size operator()(const void* __key, _Size __len) __attribute__((__no_sanitize__("unsigned-integer-overflow")));

 private:

  static const _Size __k0 = 0xc3a5c85c97cb3127ULL;
  static const _Size __k1 = 0xb492b66fbe98f273ULL;
  static const _Size __k2 = 0x9ae16a3b2f90404fULL;
  static const _Size __k3 = 0xc949d7c7509e6557ULL;

  static _Size __rotate(_Size __val, int __shift) {
    return __shift == 0 ? __val : ((__val >> __shift) | (__val << (64 - __shift)));
  }

  static _Size __rotate_by_at_least_1(_Size __val, int __shift) {
    return (__val >> __shift) | (__val << (64 - __shift));
  }

  static _Size __shift_mix(_Size __val) {
    return __val ^ (__val >> 47);
  }

  static _Size __hash_len_16(_Size __u, _Size __v)
     __attribute__((__no_sanitize__("unsigned-integer-overflow")))
  {
    const _Size __mul = 0x9ddfea08eb382d69ULL;
    _Size __a = (__u ^ __v) * __mul;
    __a ^= (__a >> 47);
    _Size __b = (__v ^ __a) * __mul;
    __b ^= (__b >> 47);
    __b *= __mul;
    return __b;
  }

  static _Size __hash_len_0_to_16(const char* __s, _Size __len)
     __attribute__((__no_sanitize__("unsigned-integer-overflow")))
  {
    if (__len > 8) {
      const _Size __a = __loadword<_Size>(__s);
      const _Size __b = __loadword<_Size>(__s + __len - 8);
      return __hash_len_16(__a, __rotate_by_at_least_1(__b + __len, __len)) ^ __b;
    }
    if (__len >= 4) {
      const uint32_t __a = __loadword<uint32_t>(__s);
      const uint32_t __b = __loadword<uint32_t>(__s + __len - 4);
      return __hash_len_16(__len + (__a << 3), __b);
    }
    if (__len > 0) {
      const unsigned char __a = __s[0];
      const unsigned char __b = __s[__len >> 1];
      const unsigned char __c = __s[__len - 1];
      const uint32_t __y = static_cast<uint32_t>(__a) +
                           (static_cast<uint32_t>(__b) << 8);
      const uint32_t __z = __len + (static_cast<uint32_t>(__c) << 2);
      return __shift_mix(__y * __k2 ^ __z * __k3) * __k2;
    }
    return __k2;
  }

  static _Size __hash_len_17_to_32(const char *__s, _Size __len)
     __attribute__((__no_sanitize__("unsigned-integer-overflow")))
  {
    const _Size __a = __loadword<_Size>(__s) * __k1;
    const _Size __b = __loadword<_Size>(__s + 8);
    const _Size __c = __loadword<_Size>(__s + __len - 8) * __k2;
    const _Size __d = __loadword<_Size>(__s + __len - 16) * __k0;
    return __hash_len_16(__rotate(__a - __b, 43) + __rotate(__c, 30) + __d,
                         __a + __rotate(__b ^ __k3, 20) - __c + __len);
  }



  static pair<_Size, _Size> __weak_hash_len_32_with_seeds(
      _Size __w, _Size __x, _Size __y, _Size __z, _Size __a, _Size __b)
        __attribute__((__no_sanitize__("unsigned-integer-overflow")))
  {
    __a += __w;
    __b = __rotate(__b + __a + __z, 21);
    const _Size __c = __a;
    __a += __x;
    __a += __y;
    __b += __rotate(__a, 44);
    return pair<_Size, _Size>(__a + __z, __b + __c);
  }


  static pair<_Size, _Size> __weak_hash_len_32_with_seeds(
      const char* __s, _Size __a, _Size __b)
    __attribute__((__no_sanitize__("unsigned-integer-overflow")))
  {
    return __weak_hash_len_32_with_seeds(__loadword<_Size>(__s),
                                         __loadword<_Size>(__s + 8),
                                         __loadword<_Size>(__s + 16),
                                         __loadword<_Size>(__s + 24),
                                         __a,
                                         __b);
  }


  static _Size __hash_len_33_to_64(const char *__s, size_t __len)
    __attribute__((__no_sanitize__("unsigned-integer-overflow")))
  {
    _Size __z = __loadword<_Size>(__s + 24);
    _Size __a = __loadword<_Size>(__s) +
                (__len + __loadword<_Size>(__s + __len - 16)) * __k0;
    _Size __b = __rotate(__a + __z, 52);
    _Size __c = __rotate(__a, 37);
    __a += __loadword<_Size>(__s + 8);
    __c += __rotate(__a, 7);
    __a += __loadword<_Size>(__s + 16);
    _Size __vf = __a + __z;
    _Size __vs = __b + __rotate(__a, 31) + __c;
    __a = __loadword<_Size>(__s + 16) + __loadword<_Size>(__s + __len - 32);
    __z += __loadword<_Size>(__s + __len - 8);
    __b = __rotate(__a + __z, 52);
    __c = __rotate(__a, 37);
    __a += __loadword<_Size>(__s + __len - 24);
    __c += __rotate(__a, 7);
    __a += __loadword<_Size>(__s + __len - 16);
    _Size __wf = __a + __z;
    _Size __ws = __b + __rotate(__a, 31) + __c;
    _Size __r = __shift_mix((__vf + __ws) * __k2 + (__wf + __vs) * __k0);
    return __shift_mix(__r * __k0 + __vs) * __k2;
  }
};


template <class _Size>
_Size
__murmur2_or_cityhash<_Size, 64>::operator()(const void* __key, _Size __len)
{
  const char* __s = static_cast<const char*>(__key);
  if (__len <= 32) {
    if (__len <= 16) {
      return __hash_len_0_to_16(__s, __len);
    } else {
      return __hash_len_17_to_32(__s, __len);
    }
  } else if (__len <= 64) {
    return __hash_len_33_to_64(__s, __len);
  }



  _Size __x = __loadword<_Size>(__s + __len - 40);
  _Size __y = __loadword<_Size>(__s + __len - 16) +
              __loadword<_Size>(__s + __len - 56);
  _Size __z = __hash_len_16(__loadword<_Size>(__s + __len - 48) + __len,
                          __loadword<_Size>(__s + __len - 24));
  pair<_Size, _Size> __v = __weak_hash_len_32_with_seeds(__s + __len - 64, __len, __z);
  pair<_Size, _Size> __w = __weak_hash_len_32_with_seeds(__s + __len - 32, __y + __k1, __x);
  __x = __x * __k1 + __loadword<_Size>(__s);


  __len = (__len - 1) & ~static_cast<_Size>(63);
  do {
    __x = __rotate(__x + __y + __v.first + __loadword<_Size>(__s + 8), 37) * __k1;
    __y = __rotate(__y + __v.second + __loadword<_Size>(__s + 48), 42) * __k1;
    __x ^= __w.second;
    __y += __v.first + __loadword<_Size>(__s + 40);
    __z = __rotate(__z + __w.first, 33) * __k1;
    __v = __weak_hash_len_32_with_seeds(__s, __v.second * __k1, __x + __w.first);
    __w = __weak_hash_len_32_with_seeds(__s + 32, __z + __w.second,
                                        __y + __loadword<_Size>(__s + 16));
    std::swap(__z, __x);
    __s += 64;
    __len -= 64;
  } while (__len != 0);
  return __hash_len_16(
      __hash_len_16(__v.first, __w.first) + __shift_mix(__y) * __k1 + __z,
      __hash_len_16(__v.second, __w.second) + __x);
}

template <class _Tp, size_t = sizeof(_Tp) / sizeof(size_t)>
struct __scalar_hash;

template <class _Tp>
struct __scalar_hash<_Tp, 0>
    : public unary_function<_Tp, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(_Tp __v) const throw()
    {
        union
        {
            _Tp __t;
            size_t __a;
        } __u;
        __u.__a = 0;
        __u.__t = __v;
        return __u.__a;
    }
};

template <class _Tp>
struct __scalar_hash<_Tp, 1>
    : public unary_function<_Tp, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(_Tp __v) const throw()
    {
        union
        {
            _Tp __t;
            size_t __a;
        } __u;
        __u.__t = __v;
        return __u.__a;
    }
};

template <class _Tp>
struct __scalar_hash<_Tp, 2>
    : public unary_function<_Tp, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(_Tp __v) const throw()
    {
        union
        {
            _Tp __t;
            struct
            {
                size_t __a;
                size_t __b;
            } __s;
        } __u;
        __u.__t = __v;
        return __murmur2_or_cityhash<size_t>()(&__u, sizeof(__u));
    }
};

template <class _Tp>
struct __scalar_hash<_Tp, 3>
    : public unary_function<_Tp, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(_Tp __v) const throw()
    {
        union
        {
            _Tp __t;
            struct
            {
                size_t __a;
                size_t __b;
                size_t __c;
            } __s;
        } __u;
        __u.__t = __v;
        return __murmur2_or_cityhash<size_t>()(&__u, sizeof(__u));
    }
};

template <class _Tp>
struct __scalar_hash<_Tp, 4>
    : public unary_function<_Tp, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(_Tp __v) const throw()
    {
        union
        {
            _Tp __t;
            struct
            {
                size_t __a;
                size_t __b;
                size_t __c;
                size_t __d;
            } __s;
        } __u;
        __u.__t = __v;
        return __murmur2_or_cityhash<size_t>()(&__u, sizeof(__u));
    }
};

struct _PairT {
  size_t first;
  size_t second;
};

__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
inline size_t __hash_combine(size_t __lhs, size_t __rhs) throw() {
    typedef __scalar_hash<_PairT> _HashT;
    const _PairT __p = {__lhs, __rhs};
    return _HashT()(__p);
}

template<class _Tp>
struct __attribute__ ((__type_visibility__("default"))) hash<_Tp*>
    : public unary_function<_Tp*, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(_Tp* __v) const throw()
    {
        union
        {
            _Tp* __t;
            size_t __a;
        } __u;
        __u.__t = __v;
        return __murmur2_or_cityhash<size_t>()(&__u, sizeof(__u));
    }
};


template <>
struct __attribute__ ((__type_visibility__("default"))) hash<bool>
    : public unary_function<bool, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(bool __v) const throw() {return static_cast<size_t>(__v);}
};

template <>
struct __attribute__ ((__type_visibility__("default"))) hash<char>
    : public unary_function<char, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(char __v) const throw() {return static_cast<size_t>(__v);}
};

template <>
struct __attribute__ ((__type_visibility__("default"))) hash<signed char>
    : public unary_function<signed char, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(signed char __v) const throw() {return static_cast<size_t>(__v);}
};

template <>
struct __attribute__ ((__type_visibility__("default"))) hash<unsigned char>
    : public unary_function<unsigned char, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(unsigned char __v) const throw() {return static_cast<size_t>(__v);}
};



template <>
struct __attribute__ ((__type_visibility__("default"))) hash<char16_t>
    : public unary_function<char16_t, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(char16_t __v) const throw() {return static_cast<size_t>(__v);}
};

template <>
struct __attribute__ ((__type_visibility__("default"))) hash<char32_t>
    : public unary_function<char32_t, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(char32_t __v) const throw() {return static_cast<size_t>(__v);}
};



template <>
struct __attribute__ ((__type_visibility__("default"))) hash<wchar_t>
    : public unary_function<wchar_t, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(wchar_t __v) const throw() {return static_cast<size_t>(__v);}
};

template <>
struct __attribute__ ((__type_visibility__("default"))) hash<short>
    : public unary_function<short, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(short __v) const throw() {return static_cast<size_t>(__v);}
};

template <>
struct __attribute__ ((__type_visibility__("default"))) hash<unsigned short>
    : public unary_function<unsigned short, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(unsigned short __v) const throw() {return static_cast<size_t>(__v);}
};

template <>
struct __attribute__ ((__type_visibility__("default"))) hash<int>
    : public unary_function<int, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(int __v) const throw() {return static_cast<size_t>(__v);}
};

template <>
struct __attribute__ ((__type_visibility__("default"))) hash<unsigned int>
    : public unary_function<unsigned int, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(unsigned int __v) const throw() {return static_cast<size_t>(__v);}
};

template <>
struct __attribute__ ((__type_visibility__("default"))) hash<long>
    : public unary_function<long, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(long __v) const throw() {return static_cast<size_t>(__v);}
};

template <>
struct __attribute__ ((__type_visibility__("default"))) hash<unsigned long>
    : public unary_function<unsigned long, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(unsigned long __v) const throw() {return static_cast<size_t>(__v);}
};

template <>
struct __attribute__ ((__type_visibility__("default"))) hash<long long>
    : public __scalar_hash<long long>
{
};

template <>
struct __attribute__ ((__type_visibility__("default"))) hash<unsigned long long>
    : public __scalar_hash<unsigned long long>
{
};



template <>
struct __attribute__ ((__type_visibility__("default"))) hash<__int128_t>
    : public __scalar_hash<__int128_t>
{
};

template <>
struct __attribute__ ((__type_visibility__("default"))) hash<__uint128_t>
    : public __scalar_hash<__uint128_t>
{
};



template <>
struct __attribute__ ((__type_visibility__("default"))) hash<float>
    : public __scalar_hash<float>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(float __v) const throw()
    {

       if (__v == 0.0f)
           return 0;
        return __scalar_hash<float>::operator()(__v);
    }
};

template <>
struct __attribute__ ((__type_visibility__("default"))) hash<double>
    : public __scalar_hash<double>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(double __v) const throw()
    {

       if (__v == 0.0)
           return 0;
        return __scalar_hash<double>::operator()(__v);
    }
};

template <>
struct __attribute__ ((__type_visibility__("default"))) hash<long double>
    : public __scalar_hash<long double>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(long double __v) const throw()
    {

        if (__v == 0.0L)
            return 0;

        union
        {
            long double __t;
            struct
            {
                size_t __a;
                size_t __b;
            } __s;
        } __u;
        __u.__s.__a = 0;
        __u.__s.__b = 0;
        __u.__t = __v;
        return __u.__s.__a ^ __u.__s.__b;



    }
};

} }






























typedef enum {
 P_ALL,
 P_PID,
 P_PGID
} idtype_t;








typedef __darwin_pid_t pid_t;



typedef __darwin_id_t id_t;


















typedef int sig_atomic_t;











struct __darwin_i386_thread_state
{
    unsigned int __eax;
    unsigned int __ebx;
    unsigned int __ecx;
    unsigned int __edx;
    unsigned int __edi;
    unsigned int __esi;
    unsigned int __ebp;
    unsigned int __esp;
    unsigned int __ss;
    unsigned int __eflags;
    unsigned int __eip;
    unsigned int __cs;
    unsigned int __ds;
    unsigned int __es;
    unsigned int __fs;
    unsigned int __gs;
};

struct __darwin_fp_control
{
    unsigned short __invalid :1,
        __denorm :1,
    __zdiv :1,
    __ovrfl :1,
    __undfl :1,
    __precis :1,
      :2,
    __pc :2,





    __rc :2,






             :1,
      :3;
};
typedef struct __darwin_fp_control __darwin_fp_control_t;

struct __darwin_fp_status
{
    unsigned short __invalid :1,
        __denorm :1,
    __zdiv :1,
    __ovrfl :1,
    __undfl :1,
    __precis :1,
    __stkflt :1,
    __errsumm :1,
    __c0 :1,
    __c1 :1,
    __c2 :1,
    __tos :3,
    __c3 :1,
    __busy :1;
};
typedef struct __darwin_fp_status __darwin_fp_status_t;

struct __darwin_mmst_reg
{
 char __mmst_reg[10];
 char __mmst_rsrv[6];
};

struct __darwin_xmm_reg
{
 char __xmm_reg[16];
};

struct __darwin_ymm_reg
{
 char __ymm_reg[32];
};

struct __darwin_zmm_reg
{
 char __zmm_reg[64];
};

struct __darwin_opmask_reg
{
 char __opmask_reg[8];
};

struct __darwin_i386_float_state
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;
 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;
 __uint16_t __fpu_rsrv2;
 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;
 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 char __fpu_rsrv4[14*16];
 int __fpu_reserved1;
};


struct __darwin_i386_avx_state
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;
 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;
 __uint16_t __fpu_rsrv2;
 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;
 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 char __fpu_rsrv4[14*16];
 int __fpu_reserved1;
 char __avx_reserved1[64];
 struct __darwin_xmm_reg __fpu_ymmh0;
 struct __darwin_xmm_reg __fpu_ymmh1;
 struct __darwin_xmm_reg __fpu_ymmh2;
 struct __darwin_xmm_reg __fpu_ymmh3;
 struct __darwin_xmm_reg __fpu_ymmh4;
 struct __darwin_xmm_reg __fpu_ymmh5;
 struct __darwin_xmm_reg __fpu_ymmh6;
 struct __darwin_xmm_reg __fpu_ymmh7;
};


struct __darwin_i386_avx512_state
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;
 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;
 __uint16_t __fpu_rsrv2;
 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;
 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 char __fpu_rsrv4[14*16];
 int __fpu_reserved1;
 char __avx_reserved1[64];
 struct __darwin_xmm_reg __fpu_ymmh0;
 struct __darwin_xmm_reg __fpu_ymmh1;
 struct __darwin_xmm_reg __fpu_ymmh2;
 struct __darwin_xmm_reg __fpu_ymmh3;
 struct __darwin_xmm_reg __fpu_ymmh4;
 struct __darwin_xmm_reg __fpu_ymmh5;
 struct __darwin_xmm_reg __fpu_ymmh6;
 struct __darwin_xmm_reg __fpu_ymmh7;
 struct __darwin_opmask_reg __fpu_k0;
 struct __darwin_opmask_reg __fpu_k1;
 struct __darwin_opmask_reg __fpu_k2;
 struct __darwin_opmask_reg __fpu_k3;
 struct __darwin_opmask_reg __fpu_k4;
 struct __darwin_opmask_reg __fpu_k5;
 struct __darwin_opmask_reg __fpu_k6;
 struct __darwin_opmask_reg __fpu_k7;
 struct __darwin_ymm_reg __fpu_zmmh0;
 struct __darwin_ymm_reg __fpu_zmmh1;
 struct __darwin_ymm_reg __fpu_zmmh2;
 struct __darwin_ymm_reg __fpu_zmmh3;
 struct __darwin_ymm_reg __fpu_zmmh4;
 struct __darwin_ymm_reg __fpu_zmmh5;
 struct __darwin_ymm_reg __fpu_zmmh6;
 struct __darwin_ymm_reg __fpu_zmmh7;
};

struct __darwin_i386_exception_state
{
 __uint16_t __trapno;
 __uint16_t __cpu;
 __uint32_t __err;
 __uint32_t __faultvaddr;
};

struct __darwin_x86_debug_state32
{
 unsigned int __dr0;
 unsigned int __dr1;
 unsigned int __dr2;
 unsigned int __dr3;
 unsigned int __dr4;
 unsigned int __dr5;
 unsigned int __dr6;
 unsigned int __dr7;
};

struct __x86_pagein_state
{
 int __pagein_error;
};







struct __darwin_x86_thread_state64
{
 __uint64_t __rax;
 __uint64_t __rbx;
 __uint64_t __rcx;
 __uint64_t __rdx;
 __uint64_t __rdi;
 __uint64_t __rsi;
 __uint64_t __rbp;
 __uint64_t __rsp;
 __uint64_t __r8;
 __uint64_t __r9;
 __uint64_t __r10;
 __uint64_t __r11;
 __uint64_t __r12;
 __uint64_t __r13;
 __uint64_t __r14;
 __uint64_t __r15;
 __uint64_t __rip;
 __uint64_t __rflags;
 __uint64_t __cs;
 __uint64_t __fs;
 __uint64_t __gs;
};

struct __darwin_x86_thread_full_state64
{
 struct __darwin_x86_thread_state64 __ss64;
 __uint64_t __ds;
 __uint64_t __es;
 __uint64_t __ss;
 __uint64_t __gsbase;
};

struct __darwin_x86_float_state64
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;


 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;

 __uint16_t __fpu_rsrv2;


 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;

 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 struct __darwin_xmm_reg __fpu_xmm8;
 struct __darwin_xmm_reg __fpu_xmm9;
 struct __darwin_xmm_reg __fpu_xmm10;
 struct __darwin_xmm_reg __fpu_xmm11;
 struct __darwin_xmm_reg __fpu_xmm12;
 struct __darwin_xmm_reg __fpu_xmm13;
 struct __darwin_xmm_reg __fpu_xmm14;
 struct __darwin_xmm_reg __fpu_xmm15;
 char __fpu_rsrv4[6*16];
 int __fpu_reserved1;
};


struct __darwin_x86_avx_state64
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;


 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;

 __uint16_t __fpu_rsrv2;


 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;

 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 struct __darwin_xmm_reg __fpu_xmm8;
 struct __darwin_xmm_reg __fpu_xmm9;
 struct __darwin_xmm_reg __fpu_xmm10;
 struct __darwin_xmm_reg __fpu_xmm11;
 struct __darwin_xmm_reg __fpu_xmm12;
 struct __darwin_xmm_reg __fpu_xmm13;
 struct __darwin_xmm_reg __fpu_xmm14;
 struct __darwin_xmm_reg __fpu_xmm15;
 char __fpu_rsrv4[6*16];
 int __fpu_reserved1;
 char __avx_reserved1[64];
 struct __darwin_xmm_reg __fpu_ymmh0;
 struct __darwin_xmm_reg __fpu_ymmh1;
 struct __darwin_xmm_reg __fpu_ymmh2;
 struct __darwin_xmm_reg __fpu_ymmh3;
 struct __darwin_xmm_reg __fpu_ymmh4;
 struct __darwin_xmm_reg __fpu_ymmh5;
 struct __darwin_xmm_reg __fpu_ymmh6;
 struct __darwin_xmm_reg __fpu_ymmh7;
 struct __darwin_xmm_reg __fpu_ymmh8;
 struct __darwin_xmm_reg __fpu_ymmh9;
 struct __darwin_xmm_reg __fpu_ymmh10;
 struct __darwin_xmm_reg __fpu_ymmh11;
 struct __darwin_xmm_reg __fpu_ymmh12;
 struct __darwin_xmm_reg __fpu_ymmh13;
 struct __darwin_xmm_reg __fpu_ymmh14;
 struct __darwin_xmm_reg __fpu_ymmh15;
};


struct __darwin_x86_avx512_state64
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;


 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;

 __uint16_t __fpu_rsrv2;


 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;

 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 struct __darwin_xmm_reg __fpu_xmm8;
 struct __darwin_xmm_reg __fpu_xmm9;
 struct __darwin_xmm_reg __fpu_xmm10;
 struct __darwin_xmm_reg __fpu_xmm11;
 struct __darwin_xmm_reg __fpu_xmm12;
 struct __darwin_xmm_reg __fpu_xmm13;
 struct __darwin_xmm_reg __fpu_xmm14;
 struct __darwin_xmm_reg __fpu_xmm15;
 char __fpu_rsrv4[6*16];
 int __fpu_reserved1;
 char __avx_reserved1[64];
 struct __darwin_xmm_reg __fpu_ymmh0;
 struct __darwin_xmm_reg __fpu_ymmh1;
 struct __darwin_xmm_reg __fpu_ymmh2;
 struct __darwin_xmm_reg __fpu_ymmh3;
 struct __darwin_xmm_reg __fpu_ymmh4;
 struct __darwin_xmm_reg __fpu_ymmh5;
 struct __darwin_xmm_reg __fpu_ymmh6;
 struct __darwin_xmm_reg __fpu_ymmh7;
 struct __darwin_xmm_reg __fpu_ymmh8;
 struct __darwin_xmm_reg __fpu_ymmh9;
 struct __darwin_xmm_reg __fpu_ymmh10;
 struct __darwin_xmm_reg __fpu_ymmh11;
 struct __darwin_xmm_reg __fpu_ymmh12;
 struct __darwin_xmm_reg __fpu_ymmh13;
 struct __darwin_xmm_reg __fpu_ymmh14;
 struct __darwin_xmm_reg __fpu_ymmh15;
 struct __darwin_opmask_reg __fpu_k0;
 struct __darwin_opmask_reg __fpu_k1;
 struct __darwin_opmask_reg __fpu_k2;
 struct __darwin_opmask_reg __fpu_k3;
 struct __darwin_opmask_reg __fpu_k4;
 struct __darwin_opmask_reg __fpu_k5;
 struct __darwin_opmask_reg __fpu_k6;
 struct __darwin_opmask_reg __fpu_k7;
 struct __darwin_ymm_reg __fpu_zmmh0;
 struct __darwin_ymm_reg __fpu_zmmh1;
 struct __darwin_ymm_reg __fpu_zmmh2;
 struct __darwin_ymm_reg __fpu_zmmh3;
 struct __darwin_ymm_reg __fpu_zmmh4;
 struct __darwin_ymm_reg __fpu_zmmh5;
 struct __darwin_ymm_reg __fpu_zmmh6;
 struct __darwin_ymm_reg __fpu_zmmh7;
 struct __darwin_ymm_reg __fpu_zmmh8;
 struct __darwin_ymm_reg __fpu_zmmh9;
 struct __darwin_ymm_reg __fpu_zmmh10;
 struct __darwin_ymm_reg __fpu_zmmh11;
 struct __darwin_ymm_reg __fpu_zmmh12;
 struct __darwin_ymm_reg __fpu_zmmh13;
 struct __darwin_ymm_reg __fpu_zmmh14;
 struct __darwin_ymm_reg __fpu_zmmh15;
 struct __darwin_zmm_reg __fpu_zmm16;
 struct __darwin_zmm_reg __fpu_zmm17;
 struct __darwin_zmm_reg __fpu_zmm18;
 struct __darwin_zmm_reg __fpu_zmm19;
 struct __darwin_zmm_reg __fpu_zmm20;
 struct __darwin_zmm_reg __fpu_zmm21;
 struct __darwin_zmm_reg __fpu_zmm22;
 struct __darwin_zmm_reg __fpu_zmm23;
 struct __darwin_zmm_reg __fpu_zmm24;
 struct __darwin_zmm_reg __fpu_zmm25;
 struct __darwin_zmm_reg __fpu_zmm26;
 struct __darwin_zmm_reg __fpu_zmm27;
 struct __darwin_zmm_reg __fpu_zmm28;
 struct __darwin_zmm_reg __fpu_zmm29;
 struct __darwin_zmm_reg __fpu_zmm30;
 struct __darwin_zmm_reg __fpu_zmm31;
};

struct __darwin_x86_exception_state64
{
    __uint16_t __trapno;
    __uint16_t __cpu;
    __uint32_t __err;
    __uint64_t __faultvaddr;
};

struct __darwin_x86_debug_state64
{
 __uint64_t __dr0;
 __uint64_t __dr1;
 __uint64_t __dr2;
 __uint64_t __dr3;
 __uint64_t __dr4;
 __uint64_t __dr5;
 __uint64_t __dr6;
 __uint64_t __dr7;
};

struct __darwin_x86_cpmu_state64
{
 __uint64_t __ctrs[16];
};






struct __darwin_mcontext32
{
 struct __darwin_i386_exception_state __es;
 struct __darwin_i386_thread_state __ss;
 struct __darwin_i386_float_state __fs;
};


struct __darwin_mcontext_avx32
{
 struct __darwin_i386_exception_state __es;
 struct __darwin_i386_thread_state __ss;
 struct __darwin_i386_avx_state __fs;
};



struct __darwin_mcontext_avx512_32
{
 struct __darwin_i386_exception_state __es;
 struct __darwin_i386_thread_state __ss;
 struct __darwin_i386_avx512_state __fs;
};

struct __darwin_mcontext64
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_state64 __ss;
 struct __darwin_x86_float_state64 __fs;
};


struct __darwin_mcontext64_full
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_full_state64 __ss;
 struct __darwin_x86_float_state64 __fs;
};


struct __darwin_mcontext_avx64
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_state64 __ss;
 struct __darwin_x86_avx_state64 __fs;
};


struct __darwin_mcontext_avx64_full
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_full_state64 __ss;
 struct __darwin_x86_avx_state64 __fs;
};



struct __darwin_mcontext_avx512_64
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_state64 __ss;
 struct __darwin_x86_avx512_state64 __fs;
};


struct __darwin_mcontext_avx512_64_full
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_full_state64 __ss;
 struct __darwin_x86_avx512_state64 __fs;
};

typedef struct __darwin_mcontext64 *mcontext_t;





typedef __darwin_pthread_attr_t pthread_attr_t;




struct __darwin_sigaltstack
{
 void *ss_sp;
 __darwin_size_t ss_size;
 int ss_flags;
};
typedef struct __darwin_sigaltstack stack_t;







struct __darwin_ucontext
{
 int uc_onstack;
 __darwin_sigset_t uc_sigmask;
 struct __darwin_sigaltstack uc_stack;
 struct __darwin_ucontext *uc_link;
 __darwin_size_t uc_mcsize;
 struct __darwin_mcontext64 *uc_mcontext;



};


typedef struct __darwin_ucontext ucontext_t;





typedef __darwin_sigset_t sigset_t;





typedef __darwin_uid_t uid_t;


union sigval {

 int sival_int;
 void *sival_ptr;
};





struct sigevent {
 int sigev_notify;
 int sigev_signo;
 union sigval sigev_value;
 void (*sigev_notify_function)(union sigval);
 pthread_attr_t *sigev_notify_attributes;
};


typedef struct __siginfo {
 int si_signo;
 int si_errno;
 int si_code;
 pid_t si_pid;
 uid_t si_uid;
 int si_status;
 void *si_addr;
 union sigval si_value;
 long si_band;
 unsigned long __pad[7];
} siginfo_t;

union __sigaction_u {
 void (*__sa_handler)(int);
 void (*__sa_sigaction)(int, struct __siginfo *,
     void *);
};


struct __sigaction {
 union __sigaction_u __sigaction_u;
 void (*sa_tramp)(void *, int, int, siginfo_t *, void *);
 sigset_t sa_mask;
 int sa_flags;
};




struct sigaction {
 union __sigaction_u __sigaction_u;
 sigset_t sa_mask;
 int sa_flags;
};

typedef void (*sig_t)(int);

struct sigvec {
 void (*sv_handler)(int);
 int sv_mask;
 int sv_flags;
};

struct sigstack {
 char *ss_sp;
 int ss_onstack;
};

extern "C" {
    void(*signal(int, void (*)(int)))(int);
}





struct timeval
{
 __darwin_time_t tv_sec;
 __darwin_suseconds_t tv_usec;
};









typedef __uint64_t rlim_t;

struct rusage {
 struct timeval ru_utime;
 struct timeval ru_stime;

 long ru_maxrss;

 long ru_ixrss;
 long ru_idrss;
 long ru_isrss;
 long ru_minflt;
 long ru_majflt;
 long ru_nswap;
 long ru_inblock;
 long ru_oublock;
 long ru_msgsnd;
 long ru_msgrcv;
 long ru_nsignals;
 long ru_nvcsw;
 long ru_nivcsw;


};

typedef void *rusage_info_t;

struct rusage_info_v0 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
};

struct rusage_info_v1 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
};

struct rusage_info_v2 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
 uint64_t ri_diskio_bytesread;
 uint64_t ri_diskio_byteswritten;
};

struct rusage_info_v3 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
 uint64_t ri_diskio_bytesread;
 uint64_t ri_diskio_byteswritten;
 uint64_t ri_cpu_time_qos_default;
 uint64_t ri_cpu_time_qos_maintenance;
 uint64_t ri_cpu_time_qos_background;
 uint64_t ri_cpu_time_qos_utility;
 uint64_t ri_cpu_time_qos_legacy;
 uint64_t ri_cpu_time_qos_user_initiated;
 uint64_t ri_cpu_time_qos_user_interactive;
 uint64_t ri_billed_system_time;
 uint64_t ri_serviced_system_time;
};

struct rusage_info_v4 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
 uint64_t ri_diskio_bytesread;
 uint64_t ri_diskio_byteswritten;
 uint64_t ri_cpu_time_qos_default;
 uint64_t ri_cpu_time_qos_maintenance;
 uint64_t ri_cpu_time_qos_background;
 uint64_t ri_cpu_time_qos_utility;
 uint64_t ri_cpu_time_qos_legacy;
 uint64_t ri_cpu_time_qos_user_initiated;
 uint64_t ri_cpu_time_qos_user_interactive;
 uint64_t ri_billed_system_time;
 uint64_t ri_serviced_system_time;
 uint64_t ri_logical_writes;
 uint64_t ri_lifetime_max_phys_footprint;
 uint64_t ri_instructions;
 uint64_t ri_cycles;
 uint64_t ri_billed_energy;
 uint64_t ri_serviced_energy;
 uint64_t ri_interval_max_phys_footprint;
 uint64_t ri_runnable_time;
};

typedef struct rusage_info_v4 rusage_info_current;

struct rlimit {
 rlim_t rlim_cur;
 rlim_t rlim_max;
};

struct proc_rlimit_control_wakeupmon {
 uint32_t wm_flags;
 int32_t wm_rate;
};

extern "C" {
int getpriority(int, id_t);

int getiopolicy_np(int, int) __attribute__((availability(macosx,introduced=10.5)));

int getrlimit(int, struct rlimit *) __asm("_" "getrlimit" );
int getrusage(int, struct rusage *);
int setpriority(int, id_t, int);

int setiopolicy_np(int, int, int) __attribute__((availability(macosx,introduced=10.5)));

int setrlimit(int, const struct rlimit *) __asm("_" "setrlimit" );
}












static inline
__uint16_t
_OSSwapInt16(
 __uint16_t _data
 )
{
 return (__uint16_t)((_data << 8) | (_data >> 8));
}

static inline
__uint32_t
_OSSwapInt32(
 __uint32_t _data
 )
{

 return __builtin_bswap32(_data);




}


static inline
__uint64_t
_OSSwapInt64(
 __uint64_t _data
 )
{
 return __builtin_bswap64(_data);
}












union wait {
 int w_status;



 struct {

  unsigned int w_Termsig:7,
      w_Coredump:1,
      w_Retcode:8,
      w_Filler:16;







 } w_T;





 struct {

  unsigned int w_Stopval:8,
      w_Stopsig:8,
      w_Filler:16;






 } w_S;
};

extern "C" {
pid_t wait(int *) __asm("_" "wait" );
pid_t waitpid(pid_t, int *, int) __asm("_" "waitpid" );

int waitid(idtype_t, id_t, siginfo_t *, int) __asm("_" "waitid" );


pid_t wait3(int *, int, struct rusage *);
pid_t wait4(pid_t, int *, int, struct rusage *);

}







extern "C" {
void *alloca(size_t);
}

















typedef struct {
 int quot;
 int rem;
} div_t;

typedef struct {
 long quot;
 long rem;
} ldiv_t;


typedef struct {
 long long quot;
 long long rem;
} lldiv_t;






extern int __mb_cur_max;






extern "C" {

void *malloc(size_t __size) __attribute__((__warn_unused_result__)) __attribute__((alloc_size(1)));
void *calloc(size_t __count, size_t __size) __attribute__((__warn_unused_result__)) __attribute__((alloc_size(1,2)));
void free(void *);
void *realloc(void *__ptr, size_t __size) __attribute__((__warn_unused_result__)) __attribute__((alloc_size(2)));

void *valloc(size_t) __attribute__((alloc_size(1)));






int posix_memalign(void **__memptr, size_t __alignment, size_t __size) __attribute__((availability(macosx,introduced=10.6)));

}


extern "C" {
void abort(void) __attribute__((__cold__)) __attribute__((__noreturn__));
int abs(int) __attribute__((__const__));
int atexit(void (* _Nonnull)(void));
double atof(const char *);
int atoi(const char *);
long atol(const char *);

long long
  atoll(const char *);

void *bsearch(const void *__key, const void *__base, size_t __nel,
     size_t __width, int (* _Nonnull __compar)(const void *, const void *));

div_t div(int, int) __attribute__((__const__));
void exit(int) __attribute__((__noreturn__));

char *getenv(const char *);
long labs(long) __attribute__((__const__));
ldiv_t ldiv(long, long) __attribute__((__const__));

long long
  llabs(long long);
lldiv_t lldiv(long long, long long);


int mblen(const char *__s, size_t __n);
size_t mbstowcs(wchar_t * , const char * , size_t);
int mbtowc(wchar_t * , const char * , size_t);

void qsort(void *__base, size_t __nel, size_t __width,
     int (* _Nonnull __compar)(const void *, const void *));
int rand(void) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));

void srand(unsigned) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
double strtod(const char *, char **) __asm("_" "strtod" );
float strtof(const char *, char **) __asm("_" "strtof" );
long strtol(const char *__str, char **__endptr, int __base);
long double
  strtold(const char *, char **);

long long
  strtoll(const char *__str, char **__endptr, int __base);

unsigned long
  strtoul(const char *__str, char **__endptr, int __base);

unsigned long long
  strtoull(const char *__str, char **__endptr, int __base);

__attribute__((__availability__(swift, unavailable, message="Use posix_spawn APIs or NSTask instead.")))
__attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable)))
__attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))
int system(const char *) __asm("_" "system" );



size_t wcstombs(char * , const wchar_t * , size_t);
int wctomb(char *, wchar_t);


void _Exit(int) __attribute__((__noreturn__));
long a64l(const char *);
double drand48(void);
char *ecvt(double, int, int *, int *);
double erand48(unsigned short[3]);
char *fcvt(double, int, int *, int *);
char *gcvt(double, int, char *);
int getsubopt(char **, char * const *, char **);
int grantpt(int);

char *initstate(unsigned, char *, size_t);



long jrand48(unsigned short[3]) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
char *l64a(long);
void lcong48(unsigned short[7]);
long lrand48(void) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
char *mktemp(char *);
int mkstemp(char *);
long mrand48(void) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
long nrand48(unsigned short[3]) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
int posix_openpt(int);
char *ptsname(int);


int ptsname_r(int fildes, char *buffer, size_t buflen) __attribute__((availability(macos,introduced=10.13.4))) __attribute__((availability(ios,introduced=11.3))) __attribute__((availability(tvos,introduced=11.3))) __attribute__((availability(watchos,introduced=4.3)));


int putenv(char *) __asm("_" "putenv" );
long random(void) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
int rand_r(unsigned *) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));

char *realpath(const char * , char * ) __asm("_" "realpath" "$DARWIN_EXTSN");



unsigned short
 *seed48(unsigned short[3]);
int setenv(const char * __name, const char * __value, int __overwrite) __asm("_" "setenv" );

void setkey(const char *) __asm("_" "setkey" );



char *setstate(const char *);
void srand48(long);

void srandom(unsigned);



int unlockpt(int);

int unsetenv(const char *) __asm("_" "unsetenv" );










typedef __darwin_dev_t dev_t;



typedef __darwin_mode_t mode_t;



uint32_t arc4random(void);
void arc4random_addrandom(unsigned char * , int )
    __attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(macosx,deprecated=10.12,message="use arc4random_stir")))
    __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(ios,deprecated=10.0,message="use arc4random_stir")))
    __attribute__((availability(tvos,introduced=2.0))) __attribute__((availability(tvos,deprecated=10.0,message="use arc4random_stir")))
    __attribute__((availability(watchos,introduced=1.0))) __attribute__((availability(watchos,deprecated=3.0,message="use arc4random_stir")));
void arc4random_buf(void * __buf, size_t __nbytes) __attribute__((availability(macosx,introduced=10.7)));
void arc4random_stir(void);
uint32_t
  arc4random_uniform(uint32_t __upper_bound) __attribute__((availability(macosx,introduced=10.7)));

int atexit_b(void (^ _Nonnull)(void)) __attribute__((availability(macosx,introduced=10.6)));
void *bsearch_b(const void *__key, const void *__base, size_t __nel,
     size_t __width, int (^ _Nonnull __compar)(const void *, const void *)) __attribute__((availability(macosx,introduced=10.6)));



char *cgetcap(char *, const char *, int);
int cgetclose(void);
int cgetent(char **, char **, const char *);
int cgetfirst(char **, char **);
int cgetmatch(const char *, const char *);
int cgetnext(char **, char **);
int cgetnum(char *, const char *, long *);
int cgetset(const char *);
int cgetstr(char *, const char *, char **);
int cgetustr(char *, const char *, char **);

int daemon(int, int) __asm("_" "daemon" "$1050") __attribute__((availability(macosx,introduced=10.0,deprecated=10.5,message="Use posix_spawn APIs instead."))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
char *devname(dev_t, mode_t);
char *devname_r(dev_t, mode_t, char *buf, int len);
char *getbsize(int *, long *);
int getloadavg(double [], int);
const char
 *getprogname(void);
void setprogname(const char *);

int heapsort(void *__base, size_t __nel, size_t __width,
     int (* _Nonnull __compar)(const void *, const void *));

int heapsort_b(void *__base, size_t __nel, size_t __width,
     int (^ _Nonnull __compar)(const void *, const void *) __attribute__((__noescape__)))
     __attribute__((availability(macosx,introduced=10.6)));

int mergesort(void *__base, size_t __nel, size_t __width,
     int (* _Nonnull __compar)(const void *, const void *));

int mergesort_b(void *__base, size_t __nel, size_t __width,
     int (^ _Nonnull __compar)(const void *, const void *) __attribute__((__noescape__)))
     __attribute__((availability(macosx,introduced=10.6)));

void psort(void *__base, size_t __nel, size_t __width,
     int (* _Nonnull __compar)(const void *, const void *))
     __attribute__((availability(macosx,introduced=10.6)));

void psort_b(void *__base, size_t __nel, size_t __width,
     int (^ _Nonnull __compar)(const void *, const void *) __attribute__((__noescape__)))
     __attribute__((availability(macosx,introduced=10.6)));

void psort_r(void *__base, size_t __nel, size_t __width, void *,
     int (* _Nonnull __compar)(void *, const void *, const void *))
     __attribute__((availability(macosx,introduced=10.6)));

void qsort_b(void *__base, size_t __nel, size_t __width,
     int (^ _Nonnull __compar)(const void *, const void *) __attribute__((__noescape__)))
     __attribute__((availability(macosx,introduced=10.6)));

void qsort_r(void *__base, size_t __nel, size_t __width, void *,
     int (* _Nonnull __compar)(void *, const void *, const void *));
int radixsort(const unsigned char **__base, int __nel, const unsigned char *__table,
     unsigned __endbyte);
int rpmatch(const char *)
 __attribute__((availability(macos,introduced=10.15))) __attribute__((availability(ios,introduced=13.0))) __attribute__((availability(tvos,introduced=13.0))) __attribute__((availability(watchos,introduced=6.0)));
int sradixsort(const unsigned char **__base, int __nel, const unsigned char *__table,
     unsigned __endbyte);
void sranddev(void);
void srandomdev(void);
void *reallocf(void *__ptr, size_t __size) __attribute__((alloc_size(2)));

long long
  strtoq(const char *__str, char **__endptr, int __base);
unsigned long long
  strtouq(const char *__str, char **__endptr, int __base);

extern char *suboptarg;







}

















extern "C" {

    typedef float float_t;
    typedef double double_t;

extern int __math_errhandling(void);

extern int __fpclassifyf(float);
extern int __fpclassifyd(double);
extern int __fpclassifyl(long double);

inline __attribute__ ((__always_inline__)) int __inline_isfinitef(float);
inline __attribute__ ((__always_inline__)) int __inline_isfinited(double);
inline __attribute__ ((__always_inline__)) int __inline_isfinitel(long double);
inline __attribute__ ((__always_inline__)) int __inline_isinff(float);
inline __attribute__ ((__always_inline__)) int __inline_isinfd(double);
inline __attribute__ ((__always_inline__)) int __inline_isinfl(long double);
inline __attribute__ ((__always_inline__)) int __inline_isnanf(float);
inline __attribute__ ((__always_inline__)) int __inline_isnand(double);
inline __attribute__ ((__always_inline__)) int __inline_isnanl(long double);
inline __attribute__ ((__always_inline__)) int __inline_isnormalf(float);
inline __attribute__ ((__always_inline__)) int __inline_isnormald(double);
inline __attribute__ ((__always_inline__)) int __inline_isnormall(long double);
inline __attribute__ ((__always_inline__)) int __inline_signbitf(float);
inline __attribute__ ((__always_inline__)) int __inline_signbitd(double);
inline __attribute__ ((__always_inline__)) int __inline_signbitl(long double);

inline __attribute__ ((__always_inline__)) int __inline_isfinitef(float __x) {
    return __x == __x && __builtin_fabsf(__x) != __builtin_inff();
}
inline __attribute__ ((__always_inline__)) int __inline_isfinited(double __x) {
    return __x == __x && __builtin_fabs(__x) != __builtin_inf();
}
inline __attribute__ ((__always_inline__)) int __inline_isfinitel(long double __x) {
    return __x == __x && __builtin_fabsl(__x) != __builtin_infl();
}
inline __attribute__ ((__always_inline__)) int __inline_isinff(float __x) {
    return __builtin_fabsf(__x) == __builtin_inff();
}
inline __attribute__ ((__always_inline__)) int __inline_isinfd(double __x) {
    return __builtin_fabs(__x) == __builtin_inf();
}
inline __attribute__ ((__always_inline__)) int __inline_isinfl(long double __x) {
    return __builtin_fabsl(__x) == __builtin_infl();
}
inline __attribute__ ((__always_inline__)) int __inline_isnanf(float __x) {
    return __x != __x;
}
inline __attribute__ ((__always_inline__)) int __inline_isnand(double __x) {
    return __x != __x;
}
inline __attribute__ ((__always_inline__)) int __inline_isnanl(long double __x) {
    return __x != __x;
}
inline __attribute__ ((__always_inline__)) int __inline_signbitf(float __x) {
    union { float __f; unsigned int __u; } __u;
    __u.__f = __x;
    return (int)(__u.__u >> 31);
}
inline __attribute__ ((__always_inline__)) int __inline_signbitd(double __x) {
    union { double __f; unsigned long long __u; } __u;
    __u.__f = __x;
    return (int)(__u.__u >> 63);
}

inline __attribute__ ((__always_inline__)) int __inline_signbitl(long double __x) {
    union {
        long double __ld;
        struct{ unsigned long long __m; unsigned short __sexp; } __p;
    } __u;
    __u.__ld = __x;
    return (int)(__u.__p.__sexp >> 15);
}







inline __attribute__ ((__always_inline__)) int __inline_isnormalf(float __x) {
    return __inline_isfinitef(__x) && __builtin_fabsf(__x) >= 1.17549435e-38F;
}
inline __attribute__ ((__always_inline__)) int __inline_isnormald(double __x) {
    return __inline_isfinited(__x) && __builtin_fabs(__x) >= 2.2250738585072014e-308;
}
inline __attribute__ ((__always_inline__)) int __inline_isnormall(long double __x) {
    return __inline_isfinitel(__x) && __builtin_fabsl(__x) >= 3.36210314311209350626e-4932L;
}

extern float acosf(float);
extern double acos(double);
extern long double acosl(long double);

extern float asinf(float);
extern double asin(double);
extern long double asinl(long double);

extern float atanf(float);
extern double atan(double);
extern long double atanl(long double);

extern float atan2f(float, float);
extern double atan2(double, double);
extern long double atan2l(long double, long double);

extern float cosf(float);
extern double cos(double);
extern long double cosl(long double);

extern float sinf(float);
extern double sin(double);
extern long double sinl(long double);

extern float tanf(float);
extern double tan(double);
extern long double tanl(long double);

extern float acoshf(float);
extern double acosh(double);
extern long double acoshl(long double);

extern float asinhf(float);
extern double asinh(double);
extern long double asinhl(long double);

extern float atanhf(float);
extern double atanh(double);
extern long double atanhl(long double);

extern float coshf(float);
extern double cosh(double);
extern long double coshl(long double);

extern float sinhf(float);
extern double sinh(double);
extern long double sinhl(long double);

extern float tanhf(float);
extern double tanh(double);
extern long double tanhl(long double);

extern float expf(float);
extern double exp(double);
extern long double expl(long double);

extern float exp2f(float);
extern double exp2(double);
extern long double exp2l(long double);

extern float expm1f(float);
extern double expm1(double);
extern long double expm1l(long double);

extern float logf(float);
extern double log(double);
extern long double logl(long double);

extern float log10f(float);
extern double log10(double);
extern long double log10l(long double);

extern float log2f(float);
extern double log2(double);
extern long double log2l(long double);

extern float log1pf(float);
extern double log1p(double);
extern long double log1pl(long double);

extern float logbf(float);
extern double logb(double);
extern long double logbl(long double);

extern float modff(float, float *);
extern double modf(double, double *);
extern long double modfl(long double, long double *);

extern float ldexpf(float, int);
extern double ldexp(double, int);
extern long double ldexpl(long double, int);

extern float frexpf(float, int *);
extern double frexp(double, int *);
extern long double frexpl(long double, int *);

extern int ilogbf(float);
extern int ilogb(double);
extern int ilogbl(long double);

extern float scalbnf(float, int);
extern double scalbn(double, int);
extern long double scalbnl(long double, int);

extern float scalblnf(float, long int);
extern double scalbln(double, long int);
extern long double scalblnl(long double, long int);

extern float fabsf(float);
extern double fabs(double);
extern long double fabsl(long double);

extern float cbrtf(float);
extern double cbrt(double);
extern long double cbrtl(long double);

extern float hypotf(float, float);
extern double hypot(double, double);
extern long double hypotl(long double, long double);

extern float powf(float, float);
extern double pow(double, double);
extern long double powl(long double, long double);

extern float sqrtf(float);
extern double sqrt(double);
extern long double sqrtl(long double);

extern float erff(float);
extern double erf(double);
extern long double erfl(long double);

extern float erfcf(float);
extern double erfc(double);
extern long double erfcl(long double);




extern float lgammaf(float);
extern double lgamma(double);
extern long double lgammal(long double);

extern float tgammaf(float);
extern double tgamma(double);
extern long double tgammal(long double);

extern float ceilf(float);
extern double ceil(double);
extern long double ceill(long double);

extern float floorf(float);
extern double floor(double);
extern long double floorl(long double);

extern float nearbyintf(float);
extern double nearbyint(double);
extern long double nearbyintl(long double);

extern float rintf(float);
extern double rint(double);
extern long double rintl(long double);

extern long int lrintf(float);
extern long int lrint(double);
extern long int lrintl(long double);

extern float roundf(float);
extern double round(double);
extern long double roundl(long double);

extern long int lroundf(float);
extern long int lround(double);
extern long int lroundl(long double);




extern long long int llrintf(float);
extern long long int llrint(double);
extern long long int llrintl(long double);

extern long long int llroundf(float);
extern long long int llround(double);
extern long long int llroundl(long double);


extern float truncf(float);
extern double trunc(double);
extern long double truncl(long double);

extern float fmodf(float, float);
extern double fmod(double, double);
extern long double fmodl(long double, long double);

extern float remainderf(float, float);
extern double remainder(double, double);
extern long double remainderl(long double, long double);

extern float remquof(float, float, int *);
extern double remquo(double, double, int *);
extern long double remquol(long double, long double, int *);

extern float copysignf(float, float);
extern double copysign(double, double);
extern long double copysignl(long double, long double);

extern float nanf(const char *);
extern double nan(const char *);
extern long double nanl(const char *);

extern float nextafterf(float, float);
extern double nextafter(double, double);
extern long double nextafterl(long double, long double);

extern double nexttoward(double, long double);
extern float nexttowardf(float, long double);
extern long double nexttowardl(long double, long double);

extern float fdimf(float, float);
extern double fdim(double, double);
extern long double fdiml(long double, long double);

extern float fmaxf(float, float);
extern double fmax(double, double);
extern long double fmaxl(long double, long double);

extern float fminf(float, float);
extern double fmin(double, double);
extern long double fminl(long double, long double);

extern float fmaf(float, float, float);
extern double fma(double, double, double);
extern long double fmal(long double, long double, long double);

extern float __inff(void)
__attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="use `(float)INFINITY` instead"))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
extern double __inf(void)
__attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="use `INFINITY` instead"))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
extern long double __infl(void)
__attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="use `(long double)INFINITY` instead"))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
extern float __nan(void)
__attribute__((availability(macos,introduced=10.0,deprecated=10.14,message="use `NAN` instead"))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern float __exp10f(float) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
extern double __exp10(double) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));





inline __attribute__ ((__always_inline__)) void __sincosf(float __x, float *__sinp, float *__cosp);
inline __attribute__ ((__always_inline__)) void __sincos(double __x, double *__sinp, double *__cosp);

extern float __cospif(float) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
extern double __cospi(double) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
extern float __sinpif(float) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
extern double __sinpi(double) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
extern float __tanpif(float) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
extern double __tanpi(double) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));

inline __attribute__ ((__always_inline__)) void __sincospif(float __x, float *__sinp, float *__cosp);
inline __attribute__ ((__always_inline__)) void __sincospi(double __x, double *__sinp, double *__cosp);






struct __float2 { float __sinval; float __cosval; };
struct __double2 { double __sinval; double __cosval; };

extern struct __float2 __sincosf_stret(float);
extern struct __double2 __sincos_stret(double);
extern struct __float2 __sincospif_stret(float);
extern struct __double2 __sincospi_stret(double);

inline __attribute__ ((__always_inline__)) void __sincosf(float __x, float *__sinp, float *__cosp) {
    const struct __float2 __stret = __sincosf_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}

inline __attribute__ ((__always_inline__)) void __sincos(double __x, double *__sinp, double *__cosp) {
    const struct __double2 __stret = __sincos_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}

inline __attribute__ ((__always_inline__)) void __sincospif(float __x, float *__sinp, float *__cosp) {
    const struct __float2 __stret = __sincospif_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}

inline __attribute__ ((__always_inline__)) void __sincospi(double __x, double *__sinp, double *__cosp) {
    const struct __double2 __stret = __sincospi_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}







extern double j0(double) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,introduced=3.2)));
extern double j1(double) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,introduced=3.2)));
extern double jn(int, double) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,introduced=3.2)));
extern double y0(double) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,introduced=3.2)));
extern double y1(double) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,introduced=3.2)));
extern double yn(int, double) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,introduced=3.2)));
extern double scalb(double, double);
extern int signgam;

extern long int rinttol(double)
__attribute__((availability(macos,introduced=10.0,deprecated=10.9,replacement="lrint"))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern long int roundtol(double)
__attribute__((availability(macos,introduced=10.0,deprecated=10.9,replacement="lround"))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern double drem(double, double)
__attribute__((availability(macos,introduced=10.0,deprecated=10.9,replacement="remainder"))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern int finite(double)
__attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="Use `isfinite((double)x)` instead."))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern double gamma(double)
__attribute__((availability(macos,introduced=10.0,deprecated=10.9,replacement="tgamma"))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern double significand(double)
__attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="Use `2*frexp( )` or `scalbn(x, -ilogb(x))` instead."))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

}






extern "C++" {
















namespace std { inline namespace __1 {

enum float_round_style
{
    round_indeterminate = -1,
    round_toward_zero = 0,
    round_to_nearest = 1,
    round_toward_infinity = 2,
    round_toward_neg_infinity = 3
};

enum float_denorm_style
{
    denorm_indeterminate = -1,
    denorm_absent = 0,
    denorm_present = 1
};

template <class _Tp, bool = is_arithmetic<_Tp>::value>
class __libcpp_numeric_limits
{
protected:
    typedef _Tp type;

    static const bool is_specialized = false;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type min() throw() {return type();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type max() throw() {return type();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type lowest() throw() {return type();}

    static const int digits = 0;
    static const int digits10 = 0;
    static const int max_digits10 = 0;
    static const bool is_signed = false;
    static const bool is_integer = false;
    static const bool is_exact = false;
    static const int radix = 0;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type epsilon() throw() {return type();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type round_error() throw() {return type();}

    static const int min_exponent = 0;
    static const int min_exponent10 = 0;
    static const int max_exponent = 0;
    static const int max_exponent10 = 0;

    static const bool has_infinity = false;
    static const bool has_quiet_NaN = false;
    static const bool has_signaling_NaN = false;
    static const float_denorm_style has_denorm = denorm_absent;
    static const bool has_denorm_loss = false;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type infinity() throw() {return type();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type quiet_NaN() throw() {return type();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type signaling_NaN() throw() {return type();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type denorm_min() throw() {return type();}

    static const bool is_iec559 = false;
    static const bool is_bounded = false;
    static const bool is_modulo = false;

    static const bool traps = false;
    static const bool tinyness_before = false;
    static const float_round_style round_style = round_toward_zero;
};

template <class _Tp, int __digits, bool _IsSigned>
struct __libcpp_compute_min
{
    static const _Tp value = _Tp(_Tp(1) << __digits);
};

template <class _Tp, int __digits>
struct __libcpp_compute_min<_Tp, __digits, false>
{
    static const _Tp value = _Tp(0);
};

template <class _Tp>
class __libcpp_numeric_limits<_Tp, true>
{
protected:
    typedef _Tp type;

    static const bool is_specialized = true;

    static const bool is_signed = type(-1) < type(0);
    static const int digits = static_cast<int>(sizeof(type) * 8 - is_signed);
    static const int digits10 = digits * 3 / 10;
    static const int max_digits10 = 0;
    static const type __min = __libcpp_compute_min<type, digits, is_signed>::value;
    static const type __max = is_signed ? type(type(~0) ^ __min) : type(~0);
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type min() throw() {return __min;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type max() throw() {return __max;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type lowest() throw() {return min();}

    static const bool is_integer = true;
    static const bool is_exact = true;
    static const int radix = 2;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type epsilon() throw() {return type(0);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type round_error() throw() {return type(0);}

    static const int min_exponent = 0;
    static const int min_exponent10 = 0;
    static const int max_exponent = 0;
    static const int max_exponent10 = 0;

    static const bool has_infinity = false;
    static const bool has_quiet_NaN = false;
    static const bool has_signaling_NaN = false;
    static const float_denorm_style has_denorm = denorm_absent;
    static const bool has_denorm_loss = false;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type infinity() throw() {return type(0);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type quiet_NaN() throw() {return type(0);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type signaling_NaN() throw() {return type(0);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type denorm_min() throw() {return type(0);}

    static const bool is_iec559 = false;
    static const bool is_bounded = true;
    static const bool is_modulo = !std::__1::is_signed<_Tp>::value;



    static const bool traps = true;



    static const bool tinyness_before = false;
    static const float_round_style round_style = round_toward_zero;
};

template <>
class __libcpp_numeric_limits<bool, true>
{
protected:
    typedef bool type;

    static const bool is_specialized = true;

    static const bool is_signed = false;
    static const int digits = 1;
    static const int digits10 = 0;
    static const int max_digits10 = 0;
    static const type __min = false;
    static const type __max = true;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type min() throw() {return __min;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type max() throw() {return __max;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type lowest() throw() {return min();}

    static const bool is_integer = true;
    static const bool is_exact = true;
    static const int radix = 2;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type epsilon() throw() {return type(0);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type round_error() throw() {return type(0);}

    static const int min_exponent = 0;
    static const int min_exponent10 = 0;
    static const int max_exponent = 0;
    static const int max_exponent10 = 0;

    static const bool has_infinity = false;
    static const bool has_quiet_NaN = false;
    static const bool has_signaling_NaN = false;
    static const float_denorm_style has_denorm = denorm_absent;
    static const bool has_denorm_loss = false;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type infinity() throw() {return type(0);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type quiet_NaN() throw() {return type(0);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type signaling_NaN() throw() {return type(0);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type denorm_min() throw() {return type(0);}

    static const bool is_iec559 = false;
    static const bool is_bounded = true;
    static const bool is_modulo = false;

    static const bool traps = false;
    static const bool tinyness_before = false;
    static const float_round_style round_style = round_toward_zero;
};

template <>
class __libcpp_numeric_limits<float, true>
{
protected:
    typedef float type;

    static const bool is_specialized = true;

    static const bool is_signed = true;
    static const int digits = 24;
    static const int digits10 = 6;
    static const int max_digits10 = 2+(digits * 30103l)/100000l;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type min() throw() {return 1.17549435e-38F;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type max() throw() {return 3.40282347e+38F;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type lowest() throw() {return -max();}

    static const bool is_integer = false;
    static const bool is_exact = false;
    static const int radix = 2;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type epsilon() throw() {return 1.19209290e-7F;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type round_error() throw() {return 0.5F;}

    static const int min_exponent = (-125);
    static const int min_exponent10 = (-37);
    static const int max_exponent = 128;
    static const int max_exponent10 = 38;

    static const bool has_infinity = true;
    static const bool has_quiet_NaN = true;
    static const bool has_signaling_NaN = true;
    static const float_denorm_style has_denorm = denorm_present;
    static const bool has_denorm_loss = false;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type infinity() throw() {return __builtin_huge_valf();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type quiet_NaN() throw() {return __builtin_nanf("");}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type signaling_NaN() throw() {return __builtin_nansf("");}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type denorm_min() throw() {return 1.40129846e-45F;}

    static const bool is_iec559 = true;
    static const bool is_bounded = true;
    static const bool is_modulo = false;

    static const bool traps = false;
    static const bool tinyness_before = false;
    static const float_round_style round_style = round_to_nearest;
};

template <>
class __libcpp_numeric_limits<double, true>
{
protected:
    typedef double type;

    static const bool is_specialized = true;

    static const bool is_signed = true;
    static const int digits = 53;
    static const int digits10 = 15;
    static const int max_digits10 = 2+(digits * 30103l)/100000l;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type min() throw() {return 2.2250738585072014e-308;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type max() throw() {return 1.7976931348623157e+308;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type lowest() throw() {return -max();}

    static const bool is_integer = false;
    static const bool is_exact = false;
    static const int radix = 2;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type epsilon() throw() {return 2.2204460492503131e-16;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type round_error() throw() {return 0.5;}

    static const int min_exponent = (-1021);
    static const int min_exponent10 = (-307);
    static const int max_exponent = 1024;
    static const int max_exponent10 = 308;

    static const bool has_infinity = true;
    static const bool has_quiet_NaN = true;
    static const bool has_signaling_NaN = true;
    static const float_denorm_style has_denorm = denorm_present;
    static const bool has_denorm_loss = false;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type infinity() throw() {return __builtin_huge_val();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type quiet_NaN() throw() {return __builtin_nan("");}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type signaling_NaN() throw() {return __builtin_nans("");}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type denorm_min() throw() {return 4.9406564584124654e-324;}

    static const bool is_iec559 = true;
    static const bool is_bounded = true;
    static const bool is_modulo = false;

    static const bool traps = false;
    static const bool tinyness_before = false;
    static const float_round_style round_style = round_to_nearest;
};

template <>
class __libcpp_numeric_limits<long double, true>
{
protected:
    typedef long double type;

    static const bool is_specialized = true;

    static const bool is_signed = true;
    static const int digits = 64;
    static const int digits10 = 18;
    static const int max_digits10 = 2+(digits * 30103l)/100000l;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type min() throw() {return 3.36210314311209350626e-4932L;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type max() throw() {return 1.18973149535723176502e+4932L;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type lowest() throw() {return -max();}

    static const bool is_integer = false;
    static const bool is_exact = false;
    static const int radix = 2;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type epsilon() throw() {return 1.08420217248550443401e-19L;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type round_error() throw() {return 0.5L;}

    static const int min_exponent = (-16381);
    static const int min_exponent10 = (-4931);
    static const int max_exponent = 16384;
    static const int max_exponent10 = 4932;

    static const bool has_infinity = true;
    static const bool has_quiet_NaN = true;
    static const bool has_signaling_NaN = true;
    static const float_denorm_style has_denorm = denorm_present;
    static const bool has_denorm_loss = false;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type infinity() throw() {return __builtin_huge_vall();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type quiet_NaN() throw() {return __builtin_nanl("");}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type signaling_NaN() throw() {return __builtin_nansl("");}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type denorm_min() throw() {return 3.64519953188247460253e-4951L;}




    static const bool is_iec559 = true;

    static const bool is_bounded = true;
    static const bool is_modulo = false;

    static const bool traps = false;
    static const bool tinyness_before = false;
    static const float_round_style round_style = round_to_nearest;
};

template <class _Tp>
class __attribute__ ((__type_visibility__("default"))) numeric_limits
    : private __libcpp_numeric_limits<typename remove_cv<_Tp>::type>
{
    typedef __libcpp_numeric_limits<typename remove_cv<_Tp>::type> __base;
    typedef typename __base::type type;
public:
    static const bool is_specialized = __base::is_specialized;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type min() throw() {return __base::min();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type max() throw() {return __base::max();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type lowest() throw() {return __base::lowest();}

    static const int digits = __base::digits;
    static const int digits10 = __base::digits10;
    static const int max_digits10 = __base::max_digits10;
    static const bool is_signed = __base::is_signed;
    static const bool is_integer = __base::is_integer;
    static const bool is_exact = __base::is_exact;
    static const int radix = __base::radix;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type epsilon() throw() {return __base::epsilon();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type round_error() throw() {return __base::round_error();}

    static const int min_exponent = __base::min_exponent;
    static const int min_exponent10 = __base::min_exponent10;
    static const int max_exponent = __base::max_exponent;
    static const int max_exponent10 = __base::max_exponent10;

    static const bool has_infinity = __base::has_infinity;
    static const bool has_quiet_NaN = __base::has_quiet_NaN;
    static const bool has_signaling_NaN = __base::has_signaling_NaN;
    static const float_denorm_style has_denorm = __base::has_denorm;
    static const bool has_denorm_loss = __base::has_denorm_loss;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type infinity() throw() {return __base::infinity();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type quiet_NaN() throw() {return __base::quiet_NaN();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type signaling_NaN() throw() {return __base::signaling_NaN();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type denorm_min() throw() {return __base::denorm_min();}

    static const bool is_iec559 = __base::is_iec559;
    static const bool is_bounded = __base::is_bounded;
    static const bool is_modulo = __base::is_modulo;

    static const bool traps = __base::traps;
    static const bool tinyness_before = __base::tinyness_before;
    static const float_round_style round_style = __base::round_style;
};

template <class _Tp>
                      const bool numeric_limits<_Tp>::is_specialized;
template <class _Tp>
                      const int numeric_limits<_Tp>::digits;
template <class _Tp>
                      const int numeric_limits<_Tp>::digits10;
template <class _Tp>
                      const int numeric_limits<_Tp>::max_digits10;
template <class _Tp>
                      const bool numeric_limits<_Tp>::is_signed;
template <class _Tp>
                      const bool numeric_limits<_Tp>::is_integer;
template <class _Tp>
                      const bool numeric_limits<_Tp>::is_exact;
template <class _Tp>
                      const int numeric_limits<_Tp>::radix;
template <class _Tp>
                      const int numeric_limits<_Tp>::min_exponent;
template <class _Tp>
                      const int numeric_limits<_Tp>::min_exponent10;
template <class _Tp>
                      const int numeric_limits<_Tp>::max_exponent;
template <class _Tp>
                      const int numeric_limits<_Tp>::max_exponent10;
template <class _Tp>
                      const bool numeric_limits<_Tp>::has_infinity;
template <class _Tp>
                      const bool numeric_limits<_Tp>::has_quiet_NaN;
template <class _Tp>
                      const bool numeric_limits<_Tp>::has_signaling_NaN;
template <class _Tp>
                      const float_denorm_style numeric_limits<_Tp>::has_denorm;
template <class _Tp>
                      const bool numeric_limits<_Tp>::has_denorm_loss;
template <class _Tp>
                      const bool numeric_limits<_Tp>::is_iec559;
template <class _Tp>
                      const bool numeric_limits<_Tp>::is_bounded;
template <class _Tp>
                      const bool numeric_limits<_Tp>::is_modulo;
template <class _Tp>
                      const bool numeric_limits<_Tp>::traps;
template <class _Tp>
                      const bool numeric_limits<_Tp>::tinyness_before;
template <class _Tp>
                      const float_round_style numeric_limits<_Tp>::round_style;

template <class _Tp>
class __attribute__ ((__type_visibility__("default"))) numeric_limits<const _Tp>
    : private numeric_limits<_Tp>
{
    typedef numeric_limits<_Tp> __base;
    typedef _Tp type;
public:
    static const bool is_specialized = __base::is_specialized;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type min() throw() {return __base::min();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type max() throw() {return __base::max();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type lowest() throw() {return __base::lowest();}

    static const int digits = __base::digits;
    static const int digits10 = __base::digits10;
    static const int max_digits10 = __base::max_digits10;
    static const bool is_signed = __base::is_signed;
    static const bool is_integer = __base::is_integer;
    static const bool is_exact = __base::is_exact;
    static const int radix = __base::radix;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type epsilon() throw() {return __base::epsilon();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type round_error() throw() {return __base::round_error();}

    static const int min_exponent = __base::min_exponent;
    static const int min_exponent10 = __base::min_exponent10;
    static const int max_exponent = __base::max_exponent;
    static const int max_exponent10 = __base::max_exponent10;

    static const bool has_infinity = __base::has_infinity;
    static const bool has_quiet_NaN = __base::has_quiet_NaN;
    static const bool has_signaling_NaN = __base::has_signaling_NaN;
    static const float_denorm_style has_denorm = __base::has_denorm;
    static const bool has_denorm_loss = __base::has_denorm_loss;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type infinity() throw() {return __base::infinity();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type quiet_NaN() throw() {return __base::quiet_NaN();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type signaling_NaN() throw() {return __base::signaling_NaN();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type denorm_min() throw() {return __base::denorm_min();}

    static const bool is_iec559 = __base::is_iec559;
    static const bool is_bounded = __base::is_bounded;
    static const bool is_modulo = __base::is_modulo;

    static const bool traps = __base::traps;
    static const bool tinyness_before = __base::tinyness_before;
    static const float_round_style round_style = __base::round_style;
};

template <class _Tp>
                      const bool numeric_limits<const _Tp>::is_specialized;
template <class _Tp>
                      const int numeric_limits<const _Tp>::digits;
template <class _Tp>
                      const int numeric_limits<const _Tp>::digits10;
template <class _Tp>
                      const int numeric_limits<const _Tp>::max_digits10;
template <class _Tp>
                      const bool numeric_limits<const _Tp>::is_signed;
template <class _Tp>
                      const bool numeric_limits<const _Tp>::is_integer;
template <class _Tp>
                      const bool numeric_limits<const _Tp>::is_exact;
template <class _Tp>
                      const int numeric_limits<const _Tp>::radix;
template <class _Tp>
                      const int numeric_limits<const _Tp>::min_exponent;
template <class _Tp>
                      const int numeric_limits<const _Tp>::min_exponent10;
template <class _Tp>
                      const int numeric_limits<const _Tp>::max_exponent;
template <class _Tp>
                      const int numeric_limits<const _Tp>::max_exponent10;
template <class _Tp>
                      const bool numeric_limits<const _Tp>::has_infinity;
template <class _Tp>
                      const bool numeric_limits<const _Tp>::has_quiet_NaN;
template <class _Tp>
                      const bool numeric_limits<const _Tp>::has_signaling_NaN;
template <class _Tp>
                      const float_denorm_style numeric_limits<const _Tp>::has_denorm;
template <class _Tp>
                      const bool numeric_limits<const _Tp>::has_denorm_loss;
template <class _Tp>
                      const bool numeric_limits<const _Tp>::is_iec559;
template <class _Tp>
                      const bool numeric_limits<const _Tp>::is_bounded;
template <class _Tp>
                      const bool numeric_limits<const _Tp>::is_modulo;
template <class _Tp>
                      const bool numeric_limits<const _Tp>::traps;
template <class _Tp>
                      const bool numeric_limits<const _Tp>::tinyness_before;
template <class _Tp>
                      const float_round_style numeric_limits<const _Tp>::round_style;

template <class _Tp>
class __attribute__ ((__type_visibility__("default"))) numeric_limits<volatile _Tp>
    : private numeric_limits<_Tp>
{
    typedef numeric_limits<_Tp> __base;
    typedef _Tp type;
public:
    static const bool is_specialized = __base::is_specialized;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type min() throw() {return __base::min();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type max() throw() {return __base::max();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type lowest() throw() {return __base::lowest();}

    static const int digits = __base::digits;
    static const int digits10 = __base::digits10;
    static const int max_digits10 = __base::max_digits10;
    static const bool is_signed = __base::is_signed;
    static const bool is_integer = __base::is_integer;
    static const bool is_exact = __base::is_exact;
    static const int radix = __base::radix;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type epsilon() throw() {return __base::epsilon();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type round_error() throw() {return __base::round_error();}

    static const int min_exponent = __base::min_exponent;
    static const int min_exponent10 = __base::min_exponent10;
    static const int max_exponent = __base::max_exponent;
    static const int max_exponent10 = __base::max_exponent10;

    static const bool has_infinity = __base::has_infinity;
    static const bool has_quiet_NaN = __base::has_quiet_NaN;
    static const bool has_signaling_NaN = __base::has_signaling_NaN;
    static const float_denorm_style has_denorm = __base::has_denorm;
    static const bool has_denorm_loss = __base::has_denorm_loss;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type infinity() throw() {return __base::infinity();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type quiet_NaN() throw() {return __base::quiet_NaN();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type signaling_NaN() throw() {return __base::signaling_NaN();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type denorm_min() throw() {return __base::denorm_min();}

    static const bool is_iec559 = __base::is_iec559;
    static const bool is_bounded = __base::is_bounded;
    static const bool is_modulo = __base::is_modulo;

    static const bool traps = __base::traps;
    static const bool tinyness_before = __base::tinyness_before;
    static const float_round_style round_style = __base::round_style;
};

template <class _Tp>
                      const bool numeric_limits<volatile _Tp>::is_specialized;
template <class _Tp>
                      const int numeric_limits<volatile _Tp>::digits;
template <class _Tp>
                      const int numeric_limits<volatile _Tp>::digits10;
template <class _Tp>
                      const int numeric_limits<volatile _Tp>::max_digits10;
template <class _Tp>
                      const bool numeric_limits<volatile _Tp>::is_signed;
template <class _Tp>
                      const bool numeric_limits<volatile _Tp>::is_integer;
template <class _Tp>
                      const bool numeric_limits<volatile _Tp>::is_exact;
template <class _Tp>
                      const int numeric_limits<volatile _Tp>::radix;
template <class _Tp>
                      const int numeric_limits<volatile _Tp>::min_exponent;
template <class _Tp>
                      const int numeric_limits<volatile _Tp>::min_exponent10;
template <class _Tp>
                      const int numeric_limits<volatile _Tp>::max_exponent;
template <class _Tp>
                      const int numeric_limits<volatile _Tp>::max_exponent10;
template <class _Tp>
                      const bool numeric_limits<volatile _Tp>::has_infinity;
template <class _Tp>
                      const bool numeric_limits<volatile _Tp>::has_quiet_NaN;
template <class _Tp>
                      const bool numeric_limits<volatile _Tp>::has_signaling_NaN;
template <class _Tp>
                      const float_denorm_style numeric_limits<volatile _Tp>::has_denorm;
template <class _Tp>
                      const bool numeric_limits<volatile _Tp>::has_denorm_loss;
template <class _Tp>
                      const bool numeric_limits<volatile _Tp>::is_iec559;
template <class _Tp>
                      const bool numeric_limits<volatile _Tp>::is_bounded;
template <class _Tp>
                      const bool numeric_limits<volatile _Tp>::is_modulo;
template <class _Tp>
                      const bool numeric_limits<volatile _Tp>::traps;
template <class _Tp>
                      const bool numeric_limits<volatile _Tp>::tinyness_before;
template <class _Tp>
                      const float_round_style numeric_limits<volatile _Tp>::round_style;

template <class _Tp>
class __attribute__ ((__type_visibility__("default"))) numeric_limits<const volatile _Tp>
    : private numeric_limits<_Tp>
{
    typedef numeric_limits<_Tp> __base;
    typedef _Tp type;
public:
    static const bool is_specialized = __base::is_specialized;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type min() throw() {return __base::min();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type max() throw() {return __base::max();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type lowest() throw() {return __base::lowest();}

    static const int digits = __base::digits;
    static const int digits10 = __base::digits10;
    static const int max_digits10 = __base::max_digits10;
    static const bool is_signed = __base::is_signed;
    static const bool is_integer = __base::is_integer;
    static const bool is_exact = __base::is_exact;
    static const int radix = __base::radix;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type epsilon() throw() {return __base::epsilon();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type round_error() throw() {return __base::round_error();}

    static const int min_exponent = __base::min_exponent;
    static const int min_exponent10 = __base::min_exponent10;
    static const int max_exponent = __base::max_exponent;
    static const int max_exponent10 = __base::max_exponent10;

    static const bool has_infinity = __base::has_infinity;
    static const bool has_quiet_NaN = __base::has_quiet_NaN;
    static const bool has_signaling_NaN = __base::has_signaling_NaN;
    static const float_denorm_style has_denorm = __base::has_denorm;
    static const bool has_denorm_loss = __base::has_denorm_loss;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type infinity() throw() {return __base::infinity();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type quiet_NaN() throw() {return __base::quiet_NaN();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type signaling_NaN() throw() {return __base::signaling_NaN();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static type denorm_min() throw() {return __base::denorm_min();}

    static const bool is_iec559 = __base::is_iec559;
    static const bool is_bounded = __base::is_bounded;
    static const bool is_modulo = __base::is_modulo;

    static const bool traps = __base::traps;
    static const bool tinyness_before = __base::tinyness_before;
    static const float_round_style round_style = __base::round_style;
};

template <class _Tp>
                      const bool numeric_limits<const volatile _Tp>::is_specialized;
template <class _Tp>
                      const int numeric_limits<const volatile _Tp>::digits;
template <class _Tp>
                      const int numeric_limits<const volatile _Tp>::digits10;
template <class _Tp>
                      const int numeric_limits<const volatile _Tp>::max_digits10;
template <class _Tp>
                      const bool numeric_limits<const volatile _Tp>::is_signed;
template <class _Tp>
                      const bool numeric_limits<const volatile _Tp>::is_integer;
template <class _Tp>
                      const bool numeric_limits<const volatile _Tp>::is_exact;
template <class _Tp>
                      const int numeric_limits<const volatile _Tp>::radix;
template <class _Tp>
                      const int numeric_limits<const volatile _Tp>::min_exponent;
template <class _Tp>
                      const int numeric_limits<const volatile _Tp>::min_exponent10;
template <class _Tp>
                      const int numeric_limits<const volatile _Tp>::max_exponent;
template <class _Tp>
                      const int numeric_limits<const volatile _Tp>::max_exponent10;
template <class _Tp>
                      const bool numeric_limits<const volatile _Tp>::has_infinity;
template <class _Tp>
                      const bool numeric_limits<const volatile _Tp>::has_quiet_NaN;
template <class _Tp>
                      const bool numeric_limits<const volatile _Tp>::has_signaling_NaN;
template <class _Tp>
                      const float_denorm_style numeric_limits<const volatile _Tp>::has_denorm;
template <class _Tp>
                      const bool numeric_limits<const volatile _Tp>::has_denorm_loss;
template <class _Tp>
                      const bool numeric_limits<const volatile _Tp>::is_iec559;
template <class _Tp>
                      const bool numeric_limits<const volatile _Tp>::is_bounded;
template <class _Tp>
                      const bool numeric_limits<const volatile _Tp>::is_modulo;
template <class _Tp>
                      const bool numeric_limits<const volatile _Tp>::traps;
template <class _Tp>
                      const bool numeric_limits<const volatile _Tp>::tinyness_before;
template <class _Tp>
                      const float_round_style numeric_limits<const volatile _Tp>::round_style;

} }






template <class _A1>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
__libcpp_signbit(_A1 __lcpp_x) throw()
{
    return ( sizeof(__lcpp_x) == sizeof(float) ? __inline_signbitf((float)(__lcpp_x)) : sizeof(__lcpp_x) == sizeof(double) ? __inline_signbitd((double)(__lcpp_x)) : __inline_signbitl((long double)(__lcpp_x)));
}



template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_floating_point<_A1>::value, bool>::type
signbit(_A1 __lcpp_x) throw()
{
    return __libcpp_signbit((typename std::__promote<_A1>::type)__lcpp_x);
}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<
    std::is_integral<_A1>::value && std::is_signed<_A1>::value, bool>::type
signbit(_A1 __lcpp_x) throw()
{ return __lcpp_x < 0; }

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<
    std::is_integral<_A1>::value && !std::is_signed<_A1>::value, bool>::type
signbit(_A1) throw()
{ return false; }

template <class _A1>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
int
__libcpp_fpclassify(_A1 __lcpp_x) throw()
{
    return ( sizeof(__lcpp_x) == sizeof(float) ? __fpclassifyf((float)(__lcpp_x)) : sizeof(__lcpp_x) == sizeof(double) ? __fpclassifyd((double)(__lcpp_x)) : __fpclassifyl((long double)(__lcpp_x)));
}



template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_floating_point<_A1>::value, int>::type
fpclassify(_A1 __lcpp_x) throw()
{
    return __libcpp_fpclassify((typename std::__promote<_A1>::type)__lcpp_x);
}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, int>::type
fpclassify(_A1 __lcpp_x) throw()
{ return __lcpp_x == 0 ? 3 : 4; }

template <class _A1>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
__libcpp_isfinite(_A1 __lcpp_x) throw()
{
    return ( sizeof(__lcpp_x) == sizeof(float) ? __inline_isfinitef((float)(__lcpp_x)) : sizeof(__lcpp_x) == sizeof(double) ? __inline_isfinited((double)(__lcpp_x)) : __inline_isfinitel((long double)(__lcpp_x)));
}



template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<
    std::is_arithmetic<_A1>::value && std::numeric_limits<_A1>::has_infinity,
    bool>::type
isfinite(_A1 __lcpp_x) throw()
{
    return __libcpp_isfinite((typename std::__promote<_A1>::type)__lcpp_x);
}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<
    std::is_arithmetic<_A1>::value && !std::numeric_limits<_A1>::has_infinity,
    bool>::type
isfinite(_A1) throw()
{ return true; }







template <class _A1>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
__libcpp_isinf(_A1 __lcpp_x) throw()
{
    return ( sizeof(__lcpp_x) == sizeof(float) ? __inline_isinff((float)(__lcpp_x)) : sizeof(__lcpp_x) == sizeof(double) ? __inline_isinfd((double)(__lcpp_x)) : __inline_isinfl((long double)(__lcpp_x)));
}



template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<
    std::is_arithmetic<_A1>::value && std::numeric_limits<_A1>::has_infinity,
    bool>::type
isinf(_A1 __lcpp_x) throw()
{
    return __libcpp_isinf((typename std::__promote<_A1>::type)__lcpp_x);
}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<
    std::is_arithmetic<_A1>::value && !std::numeric_limits<_A1>::has_infinity,
    bool>::type
isinf(_A1) throw()
{ return false; }


inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
isinf(float __lcpp_x) throw() { return __libcpp_isinf(__lcpp_x); }

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
bool
isinf(double __lcpp_x) throw() { return __libcpp_isinf(__lcpp_x); }

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
isinf(long double __lcpp_x) throw() { return __libcpp_isinf(__lcpp_x); }

template <class _A1>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
__libcpp_isnan(_A1 __lcpp_x) throw()
{
    return ( sizeof(__lcpp_x) == sizeof(float) ? __inline_isnanf((float)(__lcpp_x)) : sizeof(__lcpp_x) == sizeof(double) ? __inline_isnand((double)(__lcpp_x)) : __inline_isnanl((long double)(__lcpp_x)));
}



template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_floating_point<_A1>::value, bool>::type
isnan(_A1 __lcpp_x) throw()
{
    return __libcpp_isnan((typename std::__promote<_A1>::type)__lcpp_x);
}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, bool>::type
isnan(_A1) throw()
{ return false; }


inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
isnan(float __lcpp_x) throw() { return __libcpp_isnan(__lcpp_x); }

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__enable_if__(true, "")))
bool
isnan(double __lcpp_x) throw() { return __libcpp_isnan(__lcpp_x); }

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
isnan(long double __lcpp_x) throw() { return __libcpp_isnan(__lcpp_x); }

template <class _A1>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
__libcpp_isnormal(_A1 __lcpp_x) throw()
{
    return ( sizeof(__lcpp_x) == sizeof(float) ? __inline_isnormalf((float)(__lcpp_x)) : sizeof(__lcpp_x) == sizeof(double) ? __inline_isnormald((double)(__lcpp_x)) : __inline_isnormall((long double)(__lcpp_x)));
}



template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_floating_point<_A1>::value, bool>::type
isnormal(_A1 __lcpp_x) throw()
{
    return __libcpp_isnormal((typename std::__promote<_A1>::type)__lcpp_x);
}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, bool>::type
isnormal(_A1 __lcpp_x) throw()
{ return __lcpp_x != 0; }







template <class _A1, class _A2>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
__libcpp_isgreater(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    return __builtin_isgreater((__lcpp_x),(__lcpp_y));
}



template <class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if
<
    std::is_arithmetic<_A1>::value &&
    std::is_arithmetic<_A2>::value,
    bool
>::type
isgreater(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    typedef typename std::__promote<_A1, _A2>::type type;
    return __libcpp_isgreater((type)__lcpp_x, (type)__lcpp_y);
}







template <class _A1, class _A2>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
__libcpp_isgreaterequal(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    return __builtin_isgreaterequal((__lcpp_x),(__lcpp_y));
}



template <class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if
<
    std::is_arithmetic<_A1>::value &&
    std::is_arithmetic<_A2>::value,
    bool
>::type
isgreaterequal(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    typedef typename std::__promote<_A1, _A2>::type type;
    return __libcpp_isgreaterequal((type)__lcpp_x, (type)__lcpp_y);
}







template <class _A1, class _A2>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
__libcpp_isless(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    return __builtin_isless((__lcpp_x),(__lcpp_y));
}



template <class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if
<
    std::is_arithmetic<_A1>::value &&
    std::is_arithmetic<_A2>::value,
    bool
>::type
isless(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    typedef typename std::__promote<_A1, _A2>::type type;
    return __libcpp_isless((type)__lcpp_x, (type)__lcpp_y);
}







template <class _A1, class _A2>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
__libcpp_islessequal(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    return __builtin_islessequal((__lcpp_x),(__lcpp_y));
}



template <class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if
<
    std::is_arithmetic<_A1>::value &&
    std::is_arithmetic<_A2>::value,
    bool
>::type
islessequal(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    typedef typename std::__promote<_A1, _A2>::type type;
    return __libcpp_islessequal((type)__lcpp_x, (type)__lcpp_y);
}







template <class _A1, class _A2>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
__libcpp_islessgreater(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    return __builtin_islessgreater((__lcpp_x),(__lcpp_y));
}



template <class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if
<
    std::is_arithmetic<_A1>::value &&
    std::is_arithmetic<_A2>::value,
    bool
>::type
islessgreater(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    typedef typename std::__promote<_A1, _A2>::type type;
    return __libcpp_islessgreater((type)__lcpp_x, (type)__lcpp_y);
}







template <class _A1, class _A2>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
__libcpp_isunordered(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    return __builtin_isunordered((__lcpp_x),(__lcpp_y));
}



template <class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if
<
    std::is_arithmetic<_A1>::value &&
    std::is_arithmetic<_A2>::value,
    bool
>::type
isunordered(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    typedef typename std::__promote<_A1, _A2>::type type;
    return __libcpp_isunordered((type)__lcpp_x, (type)__lcpp_y);
}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long abs(long __x) throw() {
  return ::labs(__x);
}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long long abs(long long __x) throw() {
  return ::llabs(__x);
}





inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float abs(float __lcpp_x) throw() {
  return ::fabsf(__lcpp_x);
}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) double abs(double __lcpp_x) throw() {
  return ::fabs(__lcpp_x);
}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double
abs(long double __lcpp_x) throw() {
  return ::fabsl(__lcpp_x);
}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) ldiv_t div(long __x, long __y) throw() {
  return ::ldiv(__x, __y);
}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) lldiv_t div(long long __x,
                                             long long __y) throw() {
  return ::lldiv(__x, __y);
}






inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float acos(float __lcpp_x) throw() {return ::acosf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double acos(long double __lcpp_x) throw() {return ::acosl(__lcpp_x);}


template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
acos(_A1 __lcpp_x) throw() {return ::acos((double)__lcpp_x);}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float asin(float __lcpp_x) throw() {return ::asinf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double asin(long double __lcpp_x) throw() {return ::asinl(__lcpp_x);}


template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
asin(_A1 __lcpp_x) throw() {return ::asin((double)__lcpp_x);}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float atan(float __lcpp_x) throw() {return ::atanf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double atan(long double __lcpp_x) throw() {return ::atanl(__lcpp_x);}


template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
atan(_A1 __lcpp_x) throw() {return ::atan((double)__lcpp_x);}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float atan2(float __lcpp_y, float __lcpp_x) throw() {return ::atan2f(__lcpp_y, __lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double atan2(long double __lcpp_y, long double __lcpp_x) throw() {return ::atan2l(__lcpp_y, __lcpp_x);}


template <class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::_EnableIf
<
    std::is_arithmetic<_A1>::value &&
    std::is_arithmetic<_A2>::value,
    std::__promote<_A1, _A2>
>::type
atan2(_A1 __lcpp_y, _A2 __lcpp_x) throw()
{
    typedef typename std::__promote<_A1, _A2>::type __result_type;
    _Static_assert((!(std::_IsSame<_A1, __result_type>::value && std::_IsSame<_A2, __result_type>::value)), "");

    return ::atan2((__result_type)__lcpp_y, (__result_type)__lcpp_x);
}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float ceil(float __lcpp_x) throw() {return ::ceilf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double ceil(long double __lcpp_x) throw() {return ::ceill(__lcpp_x);}


template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
ceil(_A1 __lcpp_x) throw() {return ::ceil((double)__lcpp_x);}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float cos(float __lcpp_x) throw() {return ::cosf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double cos(long double __lcpp_x) throw() {return ::cosl(__lcpp_x);}


template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
cos(_A1 __lcpp_x) throw() {return ::cos((double)__lcpp_x);}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float cosh(float __lcpp_x) throw() {return ::coshf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double cosh(long double __lcpp_x) throw() {return ::coshl(__lcpp_x);}


template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
cosh(_A1 __lcpp_x) throw() {return ::cosh((double)__lcpp_x);}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float exp(float __lcpp_x) throw() {return ::expf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double exp(long double __lcpp_x) throw() {return ::expl(__lcpp_x);}


template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
exp(_A1 __lcpp_x) throw() {return ::exp((double)__lcpp_x);}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float fabs(float __lcpp_x) throw() {return ::fabsf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double fabs(long double __lcpp_x) throw() {return ::fabsl(__lcpp_x);}


template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
fabs(_A1 __lcpp_x) throw() {return ::fabs((double)__lcpp_x);}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float floor(float __lcpp_x) throw() {return ::floorf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double floor(long double __lcpp_x) throw() {return ::floorl(__lcpp_x);}


template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
floor(_A1 __lcpp_x) throw() {return ::floor((double)__lcpp_x);}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float fmod(float __lcpp_x, float __lcpp_y) throw() {return ::fmodf(__lcpp_x, __lcpp_y);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double fmod(long double __lcpp_x, long double __lcpp_y) throw() {return ::fmodl(__lcpp_x, __lcpp_y);}


template <class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::_EnableIf
<
    std::is_arithmetic<_A1>::value &&
    std::is_arithmetic<_A2>::value,
    std::__promote<_A1, _A2>
>::type
fmod(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    typedef typename std::__promote<_A1, _A2>::type __result_type;
    _Static_assert((!(std::_IsSame<_A1, __result_type>::value && std::_IsSame<_A2, __result_type>::value)), "");

    return ::fmod((__result_type)__lcpp_x, (__result_type)__lcpp_y);
}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float frexp(float __lcpp_x, int* __lcpp_e) throw() {return ::frexpf(__lcpp_x, __lcpp_e);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double frexp(long double __lcpp_x, int* __lcpp_e) throw() {return ::frexpl(__lcpp_x, __lcpp_e);}


template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
frexp(_A1 __lcpp_x, int* __lcpp_e) throw() {return ::frexp((double)__lcpp_x, __lcpp_e);}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float ldexp(float __lcpp_x, int __lcpp_e) throw() {return ::ldexpf(__lcpp_x, __lcpp_e);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double ldexp(long double __lcpp_x, int __lcpp_e) throw() {return ::ldexpl(__lcpp_x, __lcpp_e);}


template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
ldexp(_A1 __lcpp_x, int __lcpp_e) throw() {return ::ldexp((double)__lcpp_x, __lcpp_e);}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float log(float __lcpp_x) throw() {return ::logf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double log(long double __lcpp_x) throw() {return ::logl(__lcpp_x);}


template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
log(_A1 __lcpp_x) throw() {return ::log((double)__lcpp_x);}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float log10(float __lcpp_x) throw() {return ::log10f(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double log10(long double __lcpp_x) throw() {return ::log10l(__lcpp_x);}


template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
log10(_A1 __lcpp_x) throw() {return ::log10((double)__lcpp_x);}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float modf(float __lcpp_x, float* __lcpp_y) throw() {return ::modff(__lcpp_x, __lcpp_y);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double modf(long double __lcpp_x, long double* __lcpp_y) throw() {return ::modfl(__lcpp_x, __lcpp_y);}





inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float pow(float __lcpp_x, float __lcpp_y) throw() {return ::powf(__lcpp_x, __lcpp_y);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double pow(long double __lcpp_x, long double __lcpp_y) throw() {return ::powl(__lcpp_x, __lcpp_y);}


template <class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::_EnableIf
<
    std::is_arithmetic<_A1>::value &&
    std::is_arithmetic<_A2>::value,
    std::__promote<_A1, _A2>
>::type
pow(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    typedef typename std::__promote<_A1, _A2>::type __result_type;
    _Static_assert((!(std::_IsSame<_A1, __result_type>::value && std::_IsSame<_A2, __result_type>::value)), "");

    return ::pow((__result_type)__lcpp_x, (__result_type)__lcpp_y);
}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float sin(float __lcpp_x) throw() {return ::sinf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double sin(long double __lcpp_x) throw() {return ::sinl(__lcpp_x);}


template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
sin(_A1 __lcpp_x) throw() {return ::sin((double)__lcpp_x);}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float sinh(float __lcpp_x) throw() {return ::sinhf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double sinh(long double __lcpp_x) throw() {return ::sinhl(__lcpp_x);}


template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
sinh(_A1 __lcpp_x) throw() {return ::sinh((double)__lcpp_x);}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float sqrt(float __lcpp_x) throw() {return ::sqrtf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double sqrt(long double __lcpp_x) throw() {return ::sqrtl(__lcpp_x);}


template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
sqrt(_A1 __lcpp_x) throw() {return ::sqrt((double)__lcpp_x);}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float tan(float __lcpp_x) throw() {return ::tanf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double tan(long double __lcpp_x) throw() {return ::tanl(__lcpp_x);}


template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
tan(_A1 __lcpp_x) throw() {return ::tan((double)__lcpp_x);}




inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float tanh(float __lcpp_x) throw() {return ::tanhf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double tanh(long double __lcpp_x) throw() {return ::tanhl(__lcpp_x);}


template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
tanh(_A1 __lcpp_x) throw() {return ::tanh((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float acosh(float __lcpp_x) throw() {return ::acoshf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double acosh(long double __lcpp_x) throw() {return ::acoshl(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
acosh(_A1 __lcpp_x) throw() {return ::acosh((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float asinh(float __lcpp_x) throw() {return ::asinhf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double asinh(long double __lcpp_x) throw() {return ::asinhl(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
asinh(_A1 __lcpp_x) throw() {return ::asinh((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float atanh(float __lcpp_x) throw() {return ::atanhf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double atanh(long double __lcpp_x) throw() {return ::atanhl(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
atanh(_A1 __lcpp_x) throw() {return ::atanh((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float cbrt(float __lcpp_x) throw() {return ::cbrtf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double cbrt(long double __lcpp_x) throw() {return ::cbrtl(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
cbrt(_A1 __lcpp_x) throw() {return ::cbrt((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float copysign(float __lcpp_x,
                                                float __lcpp_y) throw() {
  return ::copysignf(__lcpp_x, __lcpp_y);
}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double
copysign(long double __lcpp_x, long double __lcpp_y) throw() {
  return ::copysignl(__lcpp_x, __lcpp_y);
}

template <class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::_EnableIf
<
    std::is_arithmetic<_A1>::value &&
    std::is_arithmetic<_A2>::value,
    std::__promote<_A1, _A2>
>::type
copysign(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    typedef typename std::__promote<_A1, _A2>::type __result_type;
    _Static_assert((!(std::_IsSame<_A1, __result_type>::value && std::_IsSame<_A2, __result_type>::value)), "");

    return ::copysign((__result_type)__lcpp_x, (__result_type)__lcpp_y);
}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float erf(float __lcpp_x) throw() {return ::erff(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double erf(long double __lcpp_x) throw() {return ::erfl(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
erf(_A1 __lcpp_x) throw() {return ::erf((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float erfc(float __lcpp_x) throw() {return ::erfcf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double erfc(long double __lcpp_x) throw() {return ::erfcl(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
erfc(_A1 __lcpp_x) throw() {return ::erfc((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float exp2(float __lcpp_x) throw() {return ::exp2f(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double exp2(long double __lcpp_x) throw() {return ::exp2l(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
exp2(_A1 __lcpp_x) throw() {return ::exp2((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float expm1(float __lcpp_x) throw() {return ::expm1f(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double expm1(long double __lcpp_x) throw() {return ::expm1l(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
expm1(_A1 __lcpp_x) throw() {return ::expm1((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float fdim(float __lcpp_x, float __lcpp_y) throw() {return ::fdimf(__lcpp_x, __lcpp_y);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double fdim(long double __lcpp_x, long double __lcpp_y) throw() {return ::fdiml(__lcpp_x, __lcpp_y);}

template <class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::_EnableIf
<
    std::is_arithmetic<_A1>::value &&
    std::is_arithmetic<_A2>::value,
    std::__promote<_A1, _A2>
>::type
fdim(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    typedef typename std::__promote<_A1, _A2>::type __result_type;
    _Static_assert((!(std::_IsSame<_A1, __result_type>::value && std::_IsSame<_A2, __result_type>::value)), "");

    return ::fdim((__result_type)__lcpp_x, (__result_type)__lcpp_y);
}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float fma(float __lcpp_x, float __lcpp_y, float __lcpp_z) throw() {return ::fmaf(__lcpp_x, __lcpp_y, __lcpp_z);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double fma(long double __lcpp_x, long double __lcpp_y, long double __lcpp_z) throw() {return ::fmal(__lcpp_x, __lcpp_y, __lcpp_z);}

template <class _A1, class _A2, class _A3>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::_EnableIf
<
    std::is_arithmetic<_A1>::value &&
    std::is_arithmetic<_A2>::value &&
    std::is_arithmetic<_A3>::value,
    std::__promote<_A1, _A2, _A3>
>::type
fma(_A1 __lcpp_x, _A2 __lcpp_y, _A3 __lcpp_z) throw()
{
    typedef typename std::__promote<_A1, _A2, _A3>::type __result_type;
    _Static_assert((!(std::_IsSame<_A1, __result_type>::value && std::_IsSame<_A2, __result_type>::value && std::_IsSame<_A3, __result_type>::value)), "");


    return ::fma((__result_type)__lcpp_x, (__result_type)__lcpp_y, (__result_type)__lcpp_z);
}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float fmax(float __lcpp_x, float __lcpp_y) throw() {return ::fmaxf(__lcpp_x, __lcpp_y);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double fmax(long double __lcpp_x, long double __lcpp_y) throw() {return ::fmaxl(__lcpp_x, __lcpp_y);}

template <class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::_EnableIf
<
    std::is_arithmetic<_A1>::value &&
    std::is_arithmetic<_A2>::value,
    std::__promote<_A1, _A2>
>::type
fmax(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    typedef typename std::__promote<_A1, _A2>::type __result_type;
    _Static_assert((!(std::_IsSame<_A1, __result_type>::value && std::_IsSame<_A2, __result_type>::value)), "");

    return ::fmax((__result_type)__lcpp_x, (__result_type)__lcpp_y);
}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float fmin(float __lcpp_x, float __lcpp_y) throw() {return ::fminf(__lcpp_x, __lcpp_y);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double fmin(long double __lcpp_x, long double __lcpp_y) throw() {return ::fminl(__lcpp_x, __lcpp_y);}

template <class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::_EnableIf
<
    std::is_arithmetic<_A1>::value &&
    std::is_arithmetic<_A2>::value,
    std::__promote<_A1, _A2>
>::type
fmin(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    typedef typename std::__promote<_A1, _A2>::type __result_type;
    _Static_assert((!(std::_IsSame<_A1, __result_type>::value && std::_IsSame<_A2, __result_type>::value)), "");

    return ::fmin((__result_type)__lcpp_x, (__result_type)__lcpp_y);
}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float hypot(float __lcpp_x, float __lcpp_y) throw() {return ::hypotf(__lcpp_x, __lcpp_y);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double hypot(long double __lcpp_x, long double __lcpp_y) throw() {return ::hypotl(__lcpp_x, __lcpp_y);}

template <class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::_EnableIf
<
    std::is_arithmetic<_A1>::value &&
    std::is_arithmetic<_A2>::value,
    std::__promote<_A1, _A2>
>::type
hypot(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    typedef typename std::__promote<_A1, _A2>::type __result_type;
    _Static_assert((!(std::_IsSame<_A1, __result_type>::value && std::_IsSame<_A2, __result_type>::value)), "");

    return ::hypot((__result_type)__lcpp_x, (__result_type)__lcpp_y);
}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) int ilogb(float __lcpp_x) throw() {return ::ilogbf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) int ilogb(long double __lcpp_x) throw() {return ::ilogbl(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, int>::type
ilogb(_A1 __lcpp_x) throw() {return ::ilogb((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float lgamma(float __lcpp_x) throw() {return ::lgammaf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double lgamma(long double __lcpp_x) throw() {return ::lgammal(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
lgamma(_A1 __lcpp_x) throw() {return ::lgamma((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long long llrint(float __lcpp_x) throw() {return ::llrintf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long long llrint(long double __lcpp_x) throw() {return ::llrintl(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, long long>::type
llrint(_A1 __lcpp_x) throw() {return ::llrint((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long long llround(float __lcpp_x) throw() {return ::llroundf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long long llround(long double __lcpp_x) throw() {return ::llroundl(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, long long>::type
llround(_A1 __lcpp_x) throw() {return ::llround((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float log1p(float __lcpp_x) throw() {return ::log1pf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double log1p(long double __lcpp_x) throw() {return ::log1pl(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
log1p(_A1 __lcpp_x) throw() {return ::log1p((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float log2(float __lcpp_x) throw() {return ::log2f(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double log2(long double __lcpp_x) throw() {return ::log2l(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
log2(_A1 __lcpp_x) throw() {return ::log2((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float logb(float __lcpp_x) throw() {return ::logbf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double logb(long double __lcpp_x) throw() {return ::logbl(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
logb(_A1 __lcpp_x) throw() {return ::logb((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long lrint(float __lcpp_x) throw() {return ::lrintf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long lrint(long double __lcpp_x) throw() {return ::lrintl(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, long>::type
lrint(_A1 __lcpp_x) throw() {return ::lrint((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long lround(float __lcpp_x) throw() {return ::lroundf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long lround(long double __lcpp_x) throw() {return ::lroundl(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, long>::type
lround(_A1 __lcpp_x) throw() {return ::lround((double)__lcpp_x);}





inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float nearbyint(float __lcpp_x) throw() {return ::nearbyintf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double nearbyint(long double __lcpp_x) throw() {return ::nearbyintl(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
nearbyint(_A1 __lcpp_x) throw() {return ::nearbyint((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float nextafter(float __lcpp_x, float __lcpp_y) throw() {return ::nextafterf(__lcpp_x, __lcpp_y);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double nextafter(long double __lcpp_x, long double __lcpp_y) throw() {return ::nextafterl(__lcpp_x, __lcpp_y);}

template <class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::_EnableIf
<
    std::is_arithmetic<_A1>::value &&
    std::is_arithmetic<_A2>::value,
    std::__promote<_A1, _A2>
>::type
nextafter(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    typedef typename std::__promote<_A1, _A2>::type __result_type;
    _Static_assert((!(std::_IsSame<_A1, __result_type>::value && std::_IsSame<_A2, __result_type>::value)), "");

    return ::nextafter((__result_type)__lcpp_x, (__result_type)__lcpp_y);
}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float nexttoward(float __lcpp_x, long double __lcpp_y) throw() {return ::nexttowardf(__lcpp_x, __lcpp_y);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double nexttoward(long double __lcpp_x, long double __lcpp_y) throw() {return ::nexttowardl(__lcpp_x, __lcpp_y);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
nexttoward(_A1 __lcpp_x, long double __lcpp_y) throw() {return ::nexttoward((double)__lcpp_x, __lcpp_y);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float remainder(float __lcpp_x, float __lcpp_y) throw() {return ::remainderf(__lcpp_x, __lcpp_y);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double remainder(long double __lcpp_x, long double __lcpp_y) throw() {return ::remainderl(__lcpp_x, __lcpp_y);}

template <class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::_EnableIf
<
    std::is_arithmetic<_A1>::value &&
    std::is_arithmetic<_A2>::value,
    std::__promote<_A1, _A2>
>::type
remainder(_A1 __lcpp_x, _A2 __lcpp_y) throw()
{
    typedef typename std::__promote<_A1, _A2>::type __result_type;
    _Static_assert((!(std::_IsSame<_A1, __result_type>::value && std::_IsSame<_A2, __result_type>::value)), "");

    return ::remainder((__result_type)__lcpp_x, (__result_type)__lcpp_y);
}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float remquo(float __lcpp_x, float __lcpp_y, int* __lcpp_z) throw() {return ::remquof(__lcpp_x, __lcpp_y, __lcpp_z);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double remquo(long double __lcpp_x, long double __lcpp_y, int* __lcpp_z) throw() {return ::remquol(__lcpp_x, __lcpp_y, __lcpp_z);}

template <class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::_EnableIf
<
    std::is_arithmetic<_A1>::value &&
    std::is_arithmetic<_A2>::value,
    std::__promote<_A1, _A2>
>::type
remquo(_A1 __lcpp_x, _A2 __lcpp_y, int* __lcpp_z) throw()
{
    typedef typename std::__promote<_A1, _A2>::type __result_type;
    _Static_assert((!(std::_IsSame<_A1, __result_type>::value && std::_IsSame<_A2, __result_type>::value)), "");

    return ::remquo((__result_type)__lcpp_x, (__result_type)__lcpp_y, __lcpp_z);
}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float rint(float __lcpp_x) throw() {return ::rintf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double rint(long double __lcpp_x) throw() {return ::rintl(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
rint(_A1 __lcpp_x) throw() {return ::rint((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float round(float __lcpp_x) throw() {return ::roundf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double round(long double __lcpp_x) throw() {return ::roundl(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
round(_A1 __lcpp_x) throw() {return ::round((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float scalbln(float __lcpp_x, long __lcpp_y) throw() {return ::scalblnf(__lcpp_x, __lcpp_y);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double scalbln(long double __lcpp_x, long __lcpp_y) throw() {return ::scalblnl(__lcpp_x, __lcpp_y);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
scalbln(_A1 __lcpp_x, long __lcpp_y) throw() {return ::scalbln((double)__lcpp_x, __lcpp_y);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float scalbn(float __lcpp_x, int __lcpp_y) throw() {return ::scalbnf(__lcpp_x, __lcpp_y);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double scalbn(long double __lcpp_x, int __lcpp_y) throw() {return ::scalbnl(__lcpp_x, __lcpp_y);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
scalbn(_A1 __lcpp_x, int __lcpp_y) throw() {return ::scalbn((double)__lcpp_x, __lcpp_y);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float tgamma(float __lcpp_x) throw() {return ::tgammaf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double tgamma(long double __lcpp_x) throw() {return ::tgammal(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
tgamma(_A1 __lcpp_x) throw() {return ::tgamma((double)__lcpp_x);}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) float trunc(float __lcpp_x) throw() {return ::truncf(__lcpp_x);}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) long double trunc(long double __lcpp_x) throw() {return ::truncl(__lcpp_x);}

template <class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename std::enable_if<std::is_integral<_A1>::value, double>::type
trunc(_A1 __lcpp_x) throw() {return ::trunc((double)__lcpp_x);}

}











namespace std { inline namespace __1 {

using ::size_t;
using ::div_t;
using ::ldiv_t;

using ::lldiv_t;

using ::atof;
using ::atoi;
using ::atol;

using ::atoll;

using ::strtod;
using ::strtof;
using ::strtold;
using ::strtol;

using ::strtoll;

using ::strtoul;

using ::strtoull;




using ::rand;
using ::srand;
using ::calloc;
using ::free;
using ::malloc;
using ::realloc;



using ::abort;



using ::atexit;
using ::exit;
using ::_Exit;

using ::getenv;
using ::system;




using ::bsearch;
using ::qsort;
using ::abs;
using ::labs;

using ::llabs;

using ::div;
using ::ldiv;

using ::lldiv;

using ::mblen;
using ::mbtowc;
using ::wctomb;
using ::mbstowcs;
using ::wcstombs;

} }




namespace std
{


class __attribute__ ((__visibility__("default"))) exception
{
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) exception() throw() {}
    virtual ~exception() throw();
    virtual const char* what() const throw();
};

class __attribute__ ((__visibility__("default"))) bad_exception
    : public exception
{
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) bad_exception() throw() {}
    virtual ~bad_exception() throw();
    virtual const char* what() const throw();
};





typedef void (*unexpected_handler)();
__attribute__ ((__visibility__("default"))) unexpected_handler set_unexpected(unexpected_handler) throw();
__attribute__ ((__visibility__("default"))) unexpected_handler get_unexpected() throw();
__attribute__ ((noreturn)) __attribute__ ((__visibility__("default"))) void unexpected();


typedef void (*terminate_handler)();
__attribute__ ((__visibility__("default"))) terminate_handler set_terminate(terminate_handler) throw();
__attribute__ ((__visibility__("default"))) terminate_handler get_terminate() throw();
__attribute__ ((noreturn)) __attribute__ ((__visibility__("default"))) void terminate() throw();

__attribute__ ((__visibility__("default"))) bool uncaught_exception() throw();
__attribute__ ((__visibility__("default"))) __attribute__((availability(macosx,strict,introduced=10.12))) __attribute__((availability(ios,strict,introduced=10.0))) __attribute__((availability(tvos,strict,introduced=10.0))) __attribute__((availability(watchos,strict,introduced=3.0))) int uncaught_exceptions() throw();

class __attribute__ ((__visibility__("default"))) exception_ptr;

__attribute__ ((__visibility__("default"))) exception_ptr current_exception() throw();
__attribute__ ((noreturn)) __attribute__ ((__visibility__("default"))) void rethrow_exception(exception_ptr);



class __attribute__ ((__visibility__("default"))) exception_ptr
{
    void* __ptr_;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) exception_ptr() throw() : __ptr_() {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) exception_ptr(nullptr_t) throw() : __ptr_() {}

    exception_ptr(const exception_ptr&) throw();
    exception_ptr& operator=(const exception_ptr&) throw();
    ~exception_ptr() throw();

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) operator bool() const throw()
    {return __ptr_ != std::__1::__get_nullptr_t();}

    friend __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator==(const exception_ptr& __x, const exception_ptr& __y) throw()
        {return __x.__ptr_ == __y.__ptr_;}

    friend __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator!=(const exception_ptr& __x, const exception_ptr& __y) throw()
        {return !(__x == __y);}

    friend __attribute__ ((__visibility__("default"))) exception_ptr current_exception() throw();
    friend __attribute__ ((__visibility__("default"))) void rethrow_exception(exception_ptr);
};

template<class _Ep>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) exception_ptr
make_exception_ptr(_Ep __e) throw()
{

    try
    {
        throw __e;
    }
    catch (...)
    {
        return current_exception();
    }




}

class __attribute__ ((__visibility__("default"))) nested_exception
{
    exception_ptr __ptr_;
public:
    nested_exception() throw();


    virtual ~nested_exception() throw();


    __attribute__ ((noreturn)) void rethrow_nested() const;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) exception_ptr nested_ptr() const throw() {return __ptr_;}
};

template <class _Tp>
struct __nested
    : public _Tp,
      public nested_exception
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit __nested(const _Tp& __t) : _Tp(__t) {}
};


template <class _Tp, class _Up, bool>
struct __throw_with_nested;

template <class _Tp, class _Up>
struct __throw_with_nested<_Tp, _Up, true> {
    __attribute__ ((noreturn)) static inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void
    __do_throw(_Tp&& __t)
    {
        throw __nested<_Up>(std::__1::forward<_Tp>(__t));
    }
};

template <class _Tp, class _Up>
struct __throw_with_nested<_Tp, _Up, false> {
    __attribute__ ((noreturn)) static inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void



    __do_throw (_Tp& __t)

    {
        throw std::__1::forward<_Tp>(__t);
    }
};


template <class _Tp>
__attribute__ ((noreturn))
void
throw_with_nested(_Tp&& __t)
{

    typedef typename decay<_Tp>::type _Up;
    _Static_assert(is_copy_constructible<_Up>::value, "type thrown must be CopyConstructible");
    __throw_with_nested<_Tp, _Up,
        is_class<_Up>::value &&
        !is_base_of<nested_exception, _Up>::value &&
        !__libcpp_is_final<_Up>::value>::
            __do_throw(std::__1::forward<_Tp>(__t));




}

template <class _From, class _To>
struct __can_dynamic_cast : public integral_constant<bool,(is_polymorphic<_From>::value && (!is_base_of<_To, _From>::value || is_convertible<const _From*, const _To*>::value))> {};




template <class _Ep>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
rethrow_if_nested(const _Ep& __e,
                  typename enable_if< __can_dynamic_cast<_Ep, nested_exception>::value>::type* = 0)
{
    const nested_exception* __nep = dynamic_cast<const nested_exception*>(std::__1::addressof(__e));
    if (__nep)
        __nep->rethrow_nested();
}

template <class _Ep>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
rethrow_if_nested(const _Ep&,
                  typename enable_if<!__can_dynamic_cast<_Ep, nested_exception>::value>::type* = 0)
{
}

}








namespace std
{

struct __type_info_implementations {
  struct __string_impl_base {
    typedef const char* __type_name_t;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__always_inline__))
                      static const char* __type_name_to_string(__type_name_t __v) throw() {
      return __v;
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__always_inline__))
                      static __type_name_t __string_to_type_name(const char* __v) throw() {
      return __v;
    }
  };

  struct __unique_impl : __string_impl_base {
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__always_inline__))
    static size_t __hash(__type_name_t __v) throw() {
      return reinterpret_cast<size_t>(__v);
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__always_inline__))
    static bool __eq(__type_name_t __lhs, __type_name_t __rhs) throw() {
      return __lhs == __rhs;
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__always_inline__))
    static bool __lt(__type_name_t __lhs, __type_name_t __rhs) throw() {
      return __lhs < __rhs;
    }
  };

  struct __non_unique_impl : __string_impl_base {
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__always_inline__))
    static size_t __hash(__type_name_t __ptr) throw() {
      size_t __hash = 5381;
      while (unsigned char __c = static_cast<unsigned char>(*__ptr++))
        __hash = (__hash * 33) ^ __c;
      return __hash;
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__always_inline__))
    static bool __eq(__type_name_t __lhs, __type_name_t __rhs) throw() {
      return __lhs == __rhs || __builtin_strcmp(__lhs, __rhs) == 0;
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__always_inline__))
    static bool __lt(__type_name_t __lhs, __type_name_t __rhs) throw() {
      return __builtin_strcmp(__lhs, __rhs) < 0;
    }
  };

  struct __non_unique_arm_rtti_bit_impl {
    typedef uintptr_t __type_name_t;

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__always_inline__))
    static const char* __type_name_to_string(__type_name_t __v) throw() {
      return reinterpret_cast<const char*>(__v &
          ~__non_unique_rtti_bit::value);
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__always_inline__))
    static __type_name_t __string_to_type_name(const char* __v) throw() {
      return reinterpret_cast<__type_name_t>(__v);
    }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__always_inline__))
    static size_t __hash(__type_name_t __v) throw() {
      if (__is_type_name_unique(__v))
        return reinterpret_cast<size_t>(__v);
      return __non_unique_impl::__hash(__type_name_to_string(__v));
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__always_inline__))
    static bool __eq(__type_name_t __lhs, __type_name_t __rhs) throw() {
      if (__lhs == __rhs)
        return true;
      if (__is_type_name_unique(__lhs, __rhs))
        return false;
      return __builtin_strcmp(__type_name_to_string(__lhs), __type_name_to_string(__rhs)) == 0;
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __attribute__ ((__always_inline__))
    static bool __lt(__type_name_t __lhs, __type_name_t __rhs) throw() {
      if (__is_type_name_unique(__lhs, __rhs))
        return __lhs < __rhs;
      return __builtin_strcmp(__type_name_to_string(__lhs), __type_name_to_string(__rhs)) < 0;
    }

   private:


    typedef std::integral_constant<__type_name_t,
      (1ULL << ((8 * sizeof(__type_name_t)) - 1))> __non_unique_rtti_bit;

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static bool __is_type_name_unique(__type_name_t __lhs) throw() {
      return !(__lhs & __non_unique_rtti_bit::value);
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static bool __is_type_name_unique(__type_name_t __lhs, __type_name_t __rhs) throw() {
      return !((__lhs & __rhs) & __non_unique_rtti_bit::value);
    }
  };

  typedef





    __unique_impl



     __impl;
};

class __attribute__ ((__visibility__("default"))) type_info
{
  type_info& operator=(const type_info&);
  type_info(const type_info&);

 protected:
    typedef __type_info_implementations::__impl __impl;

    __impl::__type_name_t __type_name;

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    explicit type_info(const char* __n)
      : __type_name(__impl::__string_to_type_name(__n)) {}

public:
    __attribute__((availability(macosx,strict,introduced=10.9))) __attribute__((availability(ios,strict,introduced=7.0)))
    virtual ~type_info();

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const char* name() const throw()
    {
      return __impl::__type_name_to_string(__type_name);
    }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool before(const type_info& __arg) const throw()
    {
      return __impl::__lt(__type_name, __arg.__type_name);
    }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t hash_code() const throw()
    {
      return __impl::__hash(__type_name);
    }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator==(const type_info& __arg) const throw()
    {
      return __impl::__eq(__type_name, __arg.__type_name);
    }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator!=(const type_info& __arg) const throw()
    { return !operator==(__arg); }
};


class __attribute__ ((__visibility__("default"))) bad_cast
    : public exception
{
 public:
  bad_cast() throw();
  virtual ~bad_cast() throw();
  virtual const char* what() const throw();
};

class __attribute__ ((__visibility__("default"))) bad_typeid
    : public exception
{
 public:
  bad_typeid() throw();
  virtual ~bad_typeid() throw();
  virtual const char* what() const throw();
};

}



namespace std { inline namespace __1 {
__attribute__ ((noreturn)) inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __throw_bad_cast()
{

    throw bad_cast();



}
} }









namespace std
{


struct __attribute__ ((__visibility__("default"))) nothrow_t { explicit nothrow_t() = default; };
extern __attribute__ ((__visibility__("default"))) const nothrow_t nothrow;

class __attribute__ ((__visibility__("default"))) bad_alloc
    : public exception
{
public:
    bad_alloc() throw();
    virtual ~bad_alloc() throw();
    virtual const char* what() const throw();
};

class __attribute__ ((__visibility__("default"))) bad_array_new_length
    : public bad_alloc
{
public:
    bad_array_new_length() throw();
    virtual ~bad_array_new_length() throw();
    virtual const char* what() const throw();
};

typedef void (*new_handler)();
__attribute__ ((__visibility__("default"))) new_handler set_new_handler(new_handler) throw();
__attribute__ ((__visibility__("default"))) new_handler get_new_handler() throw();



__attribute__ ((noreturn)) __attribute__ ((__visibility__("default"))) void __throw_bad_alloc();






enum align_val_t { __zero = 0, __max = (size_t)-1 };

}

                              __attribute__ ((__visibility__("default"))) void* operator new(std::size_t __sz) throw(std::bad_alloc);
                              __attribute__ ((__visibility__("default"))) void* operator new(std::size_t __sz, const std::nothrow_t&) throw() __attribute__((__malloc__));
__attribute__ ((__visibility__("default"))) void operator delete(void* __p) throw();
__attribute__ ((__visibility__("default"))) void operator delete(void* __p, const std::nothrow_t&) throw();




                              __attribute__ ((__visibility__("default"))) void* operator new[](std::size_t __sz) throw(std::bad_alloc);
                              __attribute__ ((__visibility__("default"))) void* operator new[](std::size_t __sz, const std::nothrow_t&) throw() __attribute__((__malloc__));
__attribute__ ((__visibility__("default"))) void operator delete[](void* __p) throw();
__attribute__ ((__visibility__("default"))) void operator delete[](void* __p, const std::nothrow_t&) throw();





                              __attribute__ ((__visibility__("default"))) void* operator new(std::size_t __sz, std::align_val_t) throw(std::bad_alloc);
                              __attribute__ ((__visibility__("default"))) void* operator new(std::size_t __sz, std::align_val_t, const std::nothrow_t&) throw() __attribute__((__malloc__));
__attribute__ ((__visibility__("default"))) void operator delete(void* __p, std::align_val_t) throw();
__attribute__ ((__visibility__("default"))) void operator delete(void* __p, std::align_val_t, const std::nothrow_t&) throw();




                              __attribute__ ((__visibility__("default"))) void* operator new[](std::size_t __sz, std::align_val_t) throw(std::bad_alloc);
                              __attribute__ ((__visibility__("default"))) void* operator new[](std::size_t __sz, std::align_val_t, const std::nothrow_t&) throw() __attribute__((__malloc__));
__attribute__ ((__visibility__("default"))) void operator delete[](void* __p, std::align_val_t) throw();
__attribute__ ((__visibility__("default"))) void operator delete[](void* __p, std::align_val_t, const std::nothrow_t&) throw();





                              inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void* operator new (std::size_t, void* __p) throw() {return __p;}
                              inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void* operator new[](std::size_t, void* __p) throw() {return __p;}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void operator delete (void*, void*) throw() {}
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void operator delete[](void*, void*) throw() {}



namespace std { inline namespace __1 {

                  inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) bool __is_overaligned_for_new(size_t __align) throw() {

  return __align > 16UL;



}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void *__libcpp_allocate(size_t __size, size_t __align) {

  ((void)__align);




  return __builtin_operator_new(__size);

}

struct _DeallocateCaller {
  static inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  void __do_deallocate_handle_size_align(void *__ptr, size_t __size, size_t __align) {

    ((void)__align);
    return __do_deallocate_handle_size(__ptr, __size);

  }

  static inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  void __do_deallocate_handle_align(void *__ptr, size_t __align) {

    ((void)__align);
    return __do_call(__ptr);

  }

 private:
  static inline void __do_deallocate_handle_size(void *__ptr, size_t __size) {

    ((void)__size);
    return __do_call(__ptr);



  }

private:
  template <class _A1, class _A2>
  static inline void __do_call(void *__ptr, _A1 __a1, _A2 __a2) {




    return __builtin_operator_delete(__ptr, __a1, __a2);

  }

  template <class _A1>
  static inline void __do_call(void *__ptr, _A1 __a1) {




    return __builtin_operator_delete(__ptr, __a1);

  }

  static inline void __do_call(void *__ptr) {



    return __builtin_operator_delete(__ptr);

  }
};

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void __libcpp_deallocate(void* __ptr, size_t __size, size_t __align) {
  _DeallocateCaller::__do_deallocate_handle_size_align(__ptr, __size, __align);
}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void __libcpp_deallocate_unsized(void* __ptr, size_t __align) {
  _DeallocateCaller::__do_deallocate_handle_align(__ptr, __align);
}

template <class _Tp>
                              inline
                  _Tp* __launder(_Tp* __p) throw()
{
    _Static_assert(!(is_function<_Tp>::value), "can't launder functions");
    _Static_assert(!(is_same<void, typename remove_cv<_Tp>::type>::value), "can't launder cv-void");

    return __builtin_launder(__p);



}

} }















namespace std { inline namespace __1 {

template <class _Arg1, class _Arg2, class _Result>
struct __attribute__ ((__type_visibility__("default"))) binary_function
{
    typedef _Arg1 first_argument_type;
    typedef _Arg2 second_argument_type;
    typedef _Result result_type;
};

template <class _Tp>
struct __has_result_type
{
private:
    struct __two {char __lx; char __lxx;};
    template <class _Up> static __two __test(...);
    template <class _Up> static char __test(typename _Up::result_type* = 0);
public:
    static const bool value = sizeof(__test<_Tp>(0)) == 1;
};




template <class _Tp>

struct __attribute__ ((__type_visibility__("default"))) less : binary_function<_Tp, _Tp, bool>
{
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _Tp& __x, const _Tp& __y) const
        {return __x < __y;}
};

template <class _Tp>
struct __derives_from_unary_function
{
private:
    struct __two {char __lx; char __lxx;};
    static __two __test(...);
    template <class _Ap, class _Rp>
        static unary_function<_Ap, _Rp>
        __test(const volatile unary_function<_Ap, _Rp>*);
public:
    static const bool value = !is_same<__decltype(__test((_Tp*)0)), __two>::value;
    typedef __decltype(__test((_Tp*)0)) type;
};

template <class _Tp>
struct __derives_from_binary_function
{
private:
    struct __two {char __lx; char __lxx;};
    static __two __test(...);
    template <class _A1, class _A2, class _Rp>
        static binary_function<_A1, _A2, _Rp>
        __test(const volatile binary_function<_A1, _A2, _Rp>*);
public:
    static const bool value = !is_same<__decltype(__test((_Tp*)0)), __two>::value;
    typedef __decltype(__test((_Tp*)0)) type;
};

template <class _Tp, bool = __derives_from_unary_function<_Tp>::value>
struct __maybe_derive_from_unary_function
    : public __derives_from_unary_function<_Tp>::type
{
};

template <class _Tp>
struct __maybe_derive_from_unary_function<_Tp, false>
{
};

template <class _Tp, bool = __derives_from_binary_function<_Tp>::value>
struct __maybe_derive_from_binary_function
    : public __derives_from_binary_function<_Tp>::type
{
};

template <class _Tp>
struct __maybe_derive_from_binary_function<_Tp, false>
{
};

template <class _Tp, bool = __has_result_type<_Tp>::value>
struct __weak_result_type_imp
    : public __maybe_derive_from_unary_function<_Tp>,
      public __maybe_derive_from_binary_function<_Tp>
{
    typedef typename _Tp::result_type result_type;
};

template <class _Tp>
struct __weak_result_type_imp<_Tp, false>
    : public __maybe_derive_from_unary_function<_Tp>,
      public __maybe_derive_from_binary_function<_Tp>
{
};

template <class _Tp>
struct __weak_result_type
    : public __weak_result_type_imp<_Tp>
{
};



template <class _Rp>
struct __weak_result_type<_Rp ()>
{
    typedef _Rp result_type;
};

template <class _Rp>
struct __weak_result_type<_Rp (&)()>
{
    typedef _Rp result_type;
};

template <class _Rp>
struct __weak_result_type<_Rp (*)()>
{
    typedef _Rp result_type;
};



template <class _Rp, class _A1>
struct __weak_result_type<_Rp (_A1)>
    : public unary_function<_A1, _Rp>
{
};

template <class _Rp, class _A1>
struct __weak_result_type<_Rp (&)(_A1)>
    : public unary_function<_A1, _Rp>
{
};

template <class _Rp, class _A1>
struct __weak_result_type<_Rp (*)(_A1)>
    : public unary_function<_A1, _Rp>
{
};

template <class _Rp, class _Cp>
struct __weak_result_type<_Rp (_Cp::*)()>
    : public unary_function<_Cp*, _Rp>
{
};

template <class _Rp, class _Cp>
struct __weak_result_type<_Rp (_Cp::*)() const>
    : public unary_function<const _Cp*, _Rp>
{
};

template <class _Rp, class _Cp>
struct __weak_result_type<_Rp (_Cp::*)() volatile>
    : public unary_function<volatile _Cp*, _Rp>
{
};

template <class _Rp, class _Cp>
struct __weak_result_type<_Rp (_Cp::*)() const volatile>
    : public unary_function<const volatile _Cp*, _Rp>
{
};



template <class _Rp, class _A1, class _A2>
struct __weak_result_type<_Rp (_A1, _A2)>
    : public binary_function<_A1, _A2, _Rp>
{
};

template <class _Rp, class _A1, class _A2>
struct __weak_result_type<_Rp (*)(_A1, _A2)>
    : public binary_function<_A1, _A2, _Rp>
{
};

template <class _Rp, class _A1, class _A2>
struct __weak_result_type<_Rp (&)(_A1, _A2)>
    : public binary_function<_A1, _A2, _Rp>
{
};

template <class _Rp, class _Cp, class _A1>
struct __weak_result_type<_Rp (_Cp::*)(_A1)>
    : public binary_function<_Cp*, _A1, _Rp>
{
};

template <class _Rp, class _Cp, class _A1>
struct __weak_result_type<_Rp (_Cp::*)(_A1) const>
    : public binary_function<const _Cp*, _A1, _Rp>
{
};

template <class _Rp, class _Cp, class _A1>
struct __weak_result_type<_Rp (_Cp::*)(_A1) volatile>
    : public binary_function<volatile _Cp*, _A1, _Rp>
{
};

template <class _Rp, class _Cp, class _A1>
struct __weak_result_type<_Rp (_Cp::*)(_A1) const volatile>
    : public binary_function<const volatile _Cp*, _A1, _Rp>
{
};



template <class _Ret, class _T1, bool _IsFunc, bool _IsBase>
struct __enable_invoke_imp;

template <class _Ret, class _T1>
struct __enable_invoke_imp<_Ret, _T1, true, true> {
    typedef _Ret _Bullet1;
    typedef _Bullet1 type;
};

template <class _Ret, class _T1>
struct __enable_invoke_imp<_Ret, _T1, true, false> {
    typedef _Ret _Bullet2;
    typedef _Bullet2 type;
};

template <class _Ret, class _T1>
struct __enable_invoke_imp<_Ret, _T1, false, true> {
    typedef typename add_lvalue_reference<
                typename __apply_cv<_T1, _Ret>::type
            >::type _Bullet3;
    typedef _Bullet3 type;
};

template <class _Ret, class _T1>
struct __enable_invoke_imp<_Ret, _T1, false, false> {
    typedef typename add_lvalue_reference<
                typename __apply_cv<__decltype(*std::__1::declval<_T1>()), _Ret>::type
            >::type _Bullet4;
    typedef _Bullet4 type;
};

template <class _Ret, class _T1>
struct __enable_invoke_imp<_Ret, _T1*, false, false> {
    typedef typename add_lvalue_reference<
                typename __apply_cv<_T1, _Ret>::type
            >::type _Bullet4;
    typedef _Bullet4 type;
};

template <class _Fn, class _T1,
          class _Traits = __member_pointer_traits<_Fn>,
          class _Ret = typename _Traits::_ReturnType,
          class _Class = typename _Traits::_ClassType>
struct __enable_invoke : __enable_invoke_imp<
    _Ret, _T1,
    is_member_function_pointer<_Fn>::value,
    is_base_of<_Class, typename remove_reference<_T1>::type>::value>
{
};

__nat __invoke(__any, ...);



template <class _Fn, class _T1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename __enable_invoke<_Fn, _T1>::_Bullet1
__invoke(_Fn __f, _T1& __t1) {
    return (__t1.*__f)();
}

template <class _Fn, class _T1, class _A0>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename __enable_invoke<_Fn, _T1>::_Bullet1
__invoke(_Fn __f, _T1& __t1, _A0& __a0) {
    return (__t1.*__f)(__a0);
}

template <class _Fn, class _T1, class _A0, class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename __enable_invoke<_Fn, _T1>::_Bullet1
__invoke(_Fn __f, _T1& __t1, _A0& __a0, _A1& __a1) {
    return (__t1.*__f)(__a0, __a1);
}

template <class _Fn, class _T1, class _A0, class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename __enable_invoke<_Fn, _T1>::_Bullet1
__invoke(_Fn __f, _T1& __t1, _A0& __a0, _A1& __a1, _A2& __a2) {
    return (__t1.*__f)(__a0, __a1, __a2);
}

template <class _Fn, class _T1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename __enable_invoke<_Fn, _T1>::_Bullet2
__invoke(_Fn __f, _T1& __t1) {
    return ((*__t1).*__f)();
}

template <class _Fn, class _T1, class _A0>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename __enable_invoke<_Fn, _T1>::_Bullet2
__invoke(_Fn __f, _T1& __t1, _A0& __a0) {
    return ((*__t1).*__f)(__a0);
}

template <class _Fn, class _T1, class _A0, class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename __enable_invoke<_Fn, _T1>::_Bullet2
__invoke(_Fn __f, _T1& __t1, _A0& __a0, _A1& __a1) {
    return ((*__t1).*__f)(__a0, __a1);
}

template <class _Fn, class _T1, class _A0, class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename __enable_invoke<_Fn, _T1>::_Bullet2
__invoke(_Fn __f, _T1& __t1, _A0& __a0, _A1& __a1, _A2& __a2) {
    return ((*__t1).*__f)(__a0, __a1, __a2);
}

template <class _Fn, class _T1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename __enable_invoke<_Fn, _T1>::_Bullet3
__invoke(_Fn __f, _T1& __t1) {
    return __t1.*__f;
}

template <class _Fn, class _T1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename __enable_invoke<_Fn, _T1>::_Bullet4
__invoke(_Fn __f, _T1& __t1) {
    return (*__t1).*__f;
}



template <class _Fp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__decltype(std::__1::declval<_Fp&>()())
__invoke(_Fp& __f)
{
    return __f();
}

template <class _Fp, class _A0>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__decltype(std::__1::declval<_Fp&>()(std::__1::declval<_A0&>()))
__invoke(_Fp& __f, _A0& __a0)
{
    return __f(__a0);
}

template <class _Fp, class _A0, class _A1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__decltype(std::__1::declval<_Fp&>()(std::__1::declval<_A0&>(), std::__1::declval<_A1&>()))
__invoke(_Fp& __f, _A0& __a0, _A1& __a1)
{
    return __f(__a0, __a1);
}

template <class _Fp, class _A0, class _A1, class _A2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__decltype(std::__1::declval<_Fp&>()(std::__1::declval<_A0&>(), std::__1::declval<_A1&>(), std::__1::declval<_A2&>()))
__invoke(_Fp& __f, _A0& __a0, _A1& __a1, _A2& __a2)
{
    return __f(__a0, __a1, __a2);
}

template <class _Fp, bool = __has_result_type<__weak_result_type<_Fp> >::value>
struct __invoke_return
{
    typedef typename __weak_result_type<_Fp>::result_type type;
};

template <class _Fp>
struct __invoke_return<_Fp, false>
{
    typedef __decltype(__invoke(std::__1::declval<_Fp&>())) type;
};

template <class _Tp, class _A0>
struct __invoke_return0
{
    typedef __decltype(__invoke(std::__1::declval<_Tp&>(), std::__1::declval<_A0&>())) type;
};

template <class _Rp, class _Tp, class _A0>
struct __invoke_return0<_Rp _Tp::*, _A0>
{
    typedef typename __enable_invoke<_Rp _Tp::*, _A0>::type type;
};

template <class _Tp, class _A0, class _A1>
struct __invoke_return1
{
    typedef __decltype(__invoke(std::__1::declval<_Tp&>(), std::__1::declval<_A0&>(), std::__1::declval<_A1&>())) type;

};

template <class _Rp, class _Class, class _A0, class _A1>
struct __invoke_return1<_Rp _Class::*, _A0, _A1> {
    typedef typename __enable_invoke<_Rp _Class::*, _A0>::type type;
};

template <class _Tp, class _A0, class _A1, class _A2>
struct __invoke_return2
{
    typedef __decltype(__invoke(std::__1::declval<_Tp&>(), std::__1::declval<_A0&>(), std::__1::declval<_A1&>(), std::__1::declval<_A2&>())) type;


};

template <class _Ret, class _Class, class _A0, class _A1, class _A2>
struct __invoke_return2<_Ret _Class::*, _A0, _A1, _A2> {
    typedef typename __enable_invoke<_Ret _Class::*, _A0>::type type;
};





template <class _Ret>
struct __invoke_void_return_wrapper
{






    template <class _Fn>
    static _Ret __call(_Fn __f) {
        return __invoke(__f);
    }

    template <class _Fn, class _A0>
    static _Ret __call(_Fn __f, _A0& __a0) {
        return __invoke(__f, __a0);
    }

    template <class _Fn, class _A0, class _A1>
    static _Ret __call(_Fn __f, _A0& __a0, _A1& __a1) {
        return __invoke(__f, __a0, __a1);
    }

    template <class _Fn, class _A0, class _A1, class _A2>
    static _Ret __call(_Fn __f, _A0& __a0, _A1& __a1, _A2& __a2){
        return __invoke(__f, __a0, __a1, __a2);
    }

};

template <>
struct __invoke_void_return_wrapper<void>
{






    template <class _Fn>
    static void __call(_Fn __f) {
        __invoke(__f);
    }

    template <class _Fn, class _A0>
    static void __call(_Fn __f, _A0& __a0) {
        __invoke(__f, __a0);
    }

    template <class _Fn, class _A0, class _A1>
    static void __call(_Fn __f, _A0& __a0, _A1& __a1) {
        __invoke(__f, __a0, __a1);
    }

    template <class _Fn, class _A0, class _A1, class _A2>
    static void __call(_Fn __f, _A0& __a0, _A1& __a1, _A2& __a2) {
        __invoke(__f, __a0, __a1, __a2);
    }

};

template <class _Tp>
class __attribute__ ((__type_visibility__("default"))) reference_wrapper
    : public __weak_result_type<_Tp>
{
public:

    typedef _Tp type;
private:
    type* __f_;

public:

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) reference_wrapper(type& __f) throw()
        : __f_(std::__1::addressof(__f)) {}





    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) operator type& () const throw() {return *__f_;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) type& get() const throw() {return *__f_;}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return<type>::type
    operator() () const {
        return __invoke(get());
    }

    template <class _A0>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return0<type, _A0>::type
    operator() (_A0& __a0) const {
        return __invoke(get(), __a0);
    }

    template <class _A0>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return0<type, _A0 const>::type
    operator() (_A0 const& __a0) const {
        return __invoke(get(), __a0);
    }

    template <class _A0, class _A1>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return1<type, _A0, _A1>::type
    operator() (_A0& __a0, _A1& __a1) const {
        return __invoke(get(), __a0, __a1);
    }

    template <class _A0, class _A1>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return1<type, _A0 const, _A1>::type
    operator() (_A0 const& __a0, _A1& __a1) const {
        return __invoke(get(), __a0, __a1);
    }

    template <class _A0, class _A1>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return1<type, _A0, _A1 const>::type
    operator() (_A0& __a0, _A1 const& __a1) const {
        return __invoke(get(), __a0, __a1);
    }

    template <class _A0, class _A1>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return1<type, _A0 const, _A1 const>::type
    operator() (_A0 const& __a0, _A1 const& __a1) const {
        return __invoke(get(), __a0, __a1);
    }

    template <class _A0, class _A1, class _A2>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return2<type, _A0, _A1, _A2>::type
    operator() (_A0& __a0, _A1& __a1, _A2& __a2) const {
        return __invoke(get(), __a0, __a1, __a2);
    }

    template <class _A0, class _A1, class _A2>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return2<type, _A0 const, _A1, _A2>::type
    operator() (_A0 const& __a0, _A1& __a1, _A2& __a2) const {
        return __invoke(get(), __a0, __a1, __a2);
    }

    template <class _A0, class _A1, class _A2>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return2<type, _A0, _A1 const, _A2>::type
    operator() (_A0& __a0, _A1 const& __a1, _A2& __a2) const {
        return __invoke(get(), __a0, __a1, __a2);
    }

    template <class _A0, class _A1, class _A2>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return2<type, _A0, _A1, _A2 const>::type
    operator() (_A0& __a0, _A1& __a1, _A2 const& __a2) const {
        return __invoke(get(), __a0, __a1, __a2);
    }

    template <class _A0, class _A1, class _A2>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return2<type, _A0 const, _A1 const, _A2>::type
    operator() (_A0 const& __a0, _A1 const& __a1, _A2& __a2) const {
        return __invoke(get(), __a0, __a1, __a2);
    }

    template <class _A0, class _A1, class _A2>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return2<type, _A0 const, _A1, _A2 const>::type
    operator() (_A0 const& __a0, _A1& __a1, _A2 const& __a2) const {
        return __invoke(get(), __a0, __a1, __a2);
    }

    template <class _A0, class _A1, class _A2>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return2<type, _A0, _A1 const, _A2 const>::type
    operator() (_A0& __a0, _A1 const& __a1, _A2 const& __a2) const {
        return __invoke(get(), __a0, __a1, __a2);
    }

    template <class _A0, class _A1, class _A2>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return2<type, _A0 const, _A1 const, _A2 const>::type
    operator() (_A0 const& __a0, _A1 const& __a1, _A2 const& __a2) const {
        return __invoke(get(), __a0, __a1, __a2);
    }

};


template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
reference_wrapper<_Tp>
ref(_Tp& __t) throw()
{
    return reference_wrapper<_Tp>(__t);
}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
reference_wrapper<_Tp>
ref(reference_wrapper<_Tp> __t) throw()
{
    return ref(__t.get());
}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
reference_wrapper<const _Tp>
cref(const _Tp& __t) throw()
{
    return reference_wrapper<const _Tp>(__t);
}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
reference_wrapper<const _Tp>
cref(reference_wrapper<_Tp> __t) throw()
{
    return cref(__t.get());
}

struct __attribute__ ((__type_visibility__("default"))) allocator_arg_t { explicit allocator_arg_t() = default; };


extern __attribute__((__visibility__("default"))) const allocator_arg_t allocator_arg;






template <class _Tp>
struct __has_allocator_type
{
private:
    struct __two {char __lx; char __lxx;};
    template <class _Up> static __two __test(...);
    template <class _Up> static char __test(typename _Up::allocator_type* = 0);
public:
    static const bool value = sizeof(__test<_Tp>(0)) == 1;
};

template <class _Tp, class _Alloc, bool = __has_allocator_type<_Tp>::value>
struct __uses_allocator
    : public integral_constant<bool,
        is_convertible<_Alloc, typename _Tp::allocator_type>::value>
{
};

template <class _Tp, class _Alloc>
struct __uses_allocator<_Tp, _Alloc, false>
    : public false_type
{
};

template <class _Tp, class _Alloc>
struct __attribute__ ((__type_visibility__("default"))) uses_allocator
    : public __uses_allocator<_Tp, _Alloc>
{
};

} }




namespace std { inline namespace __1 {
template <class _Iter>
struct __attribute__ ((__type_visibility__("default"))) iterator_traits;

struct __attribute__ ((__type_visibility__("default"))) input_iterator_tag {};
struct __attribute__ ((__type_visibility__("default"))) output_iterator_tag {};
struct __attribute__ ((__type_visibility__("default"))) forward_iterator_tag : public input_iterator_tag {};
struct __attribute__ ((__type_visibility__("default"))) bidirectional_iterator_tag : public forward_iterator_tag {};
struct __attribute__ ((__type_visibility__("default"))) random_access_iterator_tag : public bidirectional_iterator_tag {};






template <class _Iter>
struct __iter_traits_cache {
  using type = _If<
    __is_primary_template<iterator_traits<_Iter> >::value,
    _Iter,
    iterator_traits<_Iter>
  >;
};
template <class _Iter>
using _ITER_TRAITS = typename __iter_traits_cache<_Iter>::type;

struct __iter_concept_concept_test {
  template <class _Iter>
  using _Apply = typename _ITER_TRAITS<_Iter>::iterator_concept;
};
struct __iter_concept_category_test {
  template <class _Iter>
  using _Apply = typename _ITER_TRAITS<_Iter>::iterator_category;
};
struct __iter_concept_random_fallback {
  template <class _Iter>
  using _Apply = _EnableIf<
                          __is_primary_template<iterator_traits<_Iter> >::value,
                          random_access_iterator_tag
                        >;
};

template <class _Iter, class _Tester> struct __test_iter_concept
    : _IsValidExpansion<_Tester::template _Apply, _Iter>,
      _Tester
{
};

template <class _Iter>
struct __iter_concept_cache {
  using type = _Or<
    __test_iter_concept<_Iter, __iter_concept_concept_test>,
    __test_iter_concept<_Iter, __iter_concept_category_test>,
    __test_iter_concept<_Iter, __iter_concept_random_fallback>
  >;
};

template <class _Iter>
using _ITER_CONCEPT = typename __iter_concept_cache<_Iter>::type::template _Apply<_Iter>;


template <class _Tp>
struct __has_iterator_typedefs
{
private:
    struct __two {char __lx; char __lxx;};
    template <class _Up> static __two __test(...);
    template <class _Up> static char __test(typename std::__void_t<typename _Up::iterator_category>::type* = 0,
              typename std::__void_t<typename _Up::difference_type>::type* = 0,
              typename std::__void_t<typename _Up::value_type>::type* = 0,
              typename std::__void_t<typename _Up::reference>::type* = 0,
              typename std::__void_t<typename _Up::pointer>::type* = 0
              );
public:
    static const bool value = sizeof(__test<_Tp>(0,0,0,0,0)) == 1;
};


template <class _Tp>
struct __has_iterator_category
{
private:
    struct __two {char __lx; char __lxx;};
    template <class _Up> static __two __test(...);
    template <class _Up> static char __test(typename _Up::iterator_category* = 0);
public:
    static const bool value = sizeof(__test<_Tp>(0)) == 1;
};

template <class _Iter, bool> struct __iterator_traits_impl {};

template <class _Iter>
struct __iterator_traits_impl<_Iter, true>
{
    typedef typename _Iter::difference_type difference_type;
    typedef typename _Iter::value_type value_type;
    typedef typename _Iter::pointer pointer;
    typedef typename _Iter::reference reference;
    typedef typename _Iter::iterator_category iterator_category;
};

template <class _Iter, bool> struct __iterator_traits {};

template <class _Iter>
struct __iterator_traits<_Iter, true>
    : __iterator_traits_impl
      <
        _Iter,
        is_convertible<typename _Iter::iterator_category, input_iterator_tag>::value ||
        is_convertible<typename _Iter::iterator_category, output_iterator_tag>::value
      >
{};






template <class _Iter>
struct __attribute__ ((__type_visibility__("default"))) iterator_traits
    : __iterator_traits<_Iter, __has_iterator_typedefs<_Iter>::value> {

  using __primary_template = iterator_traits;
};

template<class _Tp>
struct __attribute__ ((__type_visibility__("default"))) iterator_traits<_Tp*>
{
    typedef ptrdiff_t difference_type;
    typedef typename remove_cv<_Tp>::type value_type;
    typedef _Tp* pointer;
    typedef _Tp& reference;
    typedef random_access_iterator_tag iterator_category;



};

template <class _Tp, class _Up, bool = __has_iterator_category<iterator_traits<_Tp> >::value>
struct __has_iterator_category_convertible_to
    : public integral_constant<bool, is_convertible<typename iterator_traits<_Tp>::iterator_category, _Up>::value>
{};

template <class _Tp, class _Up>
struct __has_iterator_category_convertible_to<_Tp, _Up, false> : public false_type {};

template <class _Tp>
struct __is_cpp17_input_iterator : public __has_iterator_category_convertible_to<_Tp, input_iterator_tag> {};

template <class _Tp>
struct __is_cpp17_forward_iterator : public __has_iterator_category_convertible_to<_Tp, forward_iterator_tag> {};

template <class _Tp>
struct __is_cpp17_bidirectional_iterator : public __has_iterator_category_convertible_to<_Tp, bidirectional_iterator_tag> {};

template <class _Tp>
struct __is_cpp17_random_access_iterator : public __has_iterator_category_convertible_to<_Tp, random_access_iterator_tag> {};





template <class _Tp>
struct __is_cpp17_contiguous_iterator : public false_type {};



template <class _Tp>
struct __is_exactly_cpp17_input_iterator
    : public integral_constant<bool,
         __has_iterator_category_convertible_to<_Tp, input_iterator_tag>::value &&
        !__has_iterator_category_convertible_to<_Tp, forward_iterator_tag>::value> {};

template<class _Category, class _Tp, class _Distance = ptrdiff_t,
         class _Pointer = _Tp*, class _Reference = _Tp&>
struct __attribute__ ((__type_visibility__("default"))) iterator
{
    typedef _Tp value_type;
    typedef _Distance difference_type;
    typedef _Pointer pointer;
    typedef _Reference reference;
    typedef _Category iterator_category;
};

template <class _InputIter>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __advance(_InputIter& __i,
             typename iterator_traits<_InputIter>::difference_type __n, input_iterator_tag)
{
    for (; __n > 0; --__n)
        ++__i;
}

template <class _BiDirIter>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __advance(_BiDirIter& __i,
             typename iterator_traits<_BiDirIter>::difference_type __n, bidirectional_iterator_tag)
{
    if (__n >= 0)
        for (; __n > 0; --__n)
            ++__i;
    else
        for (; __n < 0; ++__n)
            --__i;
}

template <class _RandIter>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __advance(_RandIter& __i,
             typename iterator_traits<_RandIter>::difference_type __n, random_access_iterator_tag)
{
   __i += __n;
}

template <class _InputIter>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void advance(_InputIter& __i,
             typename iterator_traits<_InputIter>::difference_type __n)
{
    ((void)0);

    __advance(__i, __n, typename iterator_traits<_InputIter>::iterator_category());
}

template <class _InputIter>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename iterator_traits<_InputIter>::difference_type
__distance(_InputIter __first, _InputIter __last, input_iterator_tag)
{
    typename iterator_traits<_InputIter>::difference_type __r(0);
    for (; __first != __last; ++__first)
        ++__r;
    return __r;
}

template <class _RandIter>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename iterator_traits<_RandIter>::difference_type
__distance(_RandIter __first, _RandIter __last, random_access_iterator_tag)
{
    return __last - __first;
}

template <class _InputIter>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename iterator_traits<_InputIter>::difference_type
distance(_InputIter __first, _InputIter __last)
{
    return __distance(__first, __last, typename iterator_traits<_InputIter>::iterator_category());
}

template <class _InputIter>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    __is_cpp17_input_iterator<_InputIter>::value,
    _InputIter
>::type
next(_InputIter __x,
     typename iterator_traits<_InputIter>::difference_type __n = 1)
{
    ((void)0);


    std::__1::advance(__x, __n);
    return __x;
}

template <class _InputIter>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    __is_cpp17_input_iterator<_InputIter>::value,
    _InputIter
>::type
prev(_InputIter __x,
     typename iterator_traits<_InputIter>::difference_type __n = 1)
{
    ((void)0);

    std::__1::advance(__x, -__n);
    return __x;
}


template <class _Tp, class = void>
struct __is_stashing_iterator : false_type {};

template <class _Tp>
struct __is_stashing_iterator<_Tp, typename __void_t<typename _Tp::__stashing_iterator_tag>::type>
  : true_type {};

template <class _Iter>
class __attribute__ ((__type_visibility__("default"))) reverse_iterator
    : public iterator<typename iterator_traits<_Iter>::iterator_category,
                      typename iterator_traits<_Iter>::value_type,
                      typename iterator_traits<_Iter>::difference_type,
                      typename iterator_traits<_Iter>::pointer,
                      typename iterator_traits<_Iter>::reference>
{
private:
                _Iter __t;

    _Static_assert(!__is_stashing_iterator<_Iter>::value, "The specified iterator type cannot be used with reverse_iterator; " "Using stashing iterators with reverse_iterator causes undefined behavior");



protected:
    _Iter current;
public:
    typedef _Iter iterator_type;
    typedef typename iterator_traits<_Iter>::difference_type difference_type;
    typedef typename iterator_traits<_Iter>::reference reference;
    typedef typename iterator_traits<_Iter>::pointer pointer;

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    reverse_iterator() : __t(), current() {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    explicit reverse_iterator(_Iter __x) : __t(__x), current(__x) {}
    template <class _Up>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        reverse_iterator(const reverse_iterator<_Up>& __u) : __t(__u.base()), current(__u.base()) {}
    template <class _Up>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        reverse_iterator& operator=(const reverse_iterator<_Up>& __u)
            { __t = current = __u.base(); return *this; }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Iter base() const {return current;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    reference operator*() const {_Iter __tmp = current; return *--__tmp;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    pointer operator->() const {return std::__1::addressof(operator*());}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    reverse_iterator& operator++() {--current; return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    reverse_iterator operator++(int) {reverse_iterator __tmp(*this); --current; return __tmp;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    reverse_iterator& operator--() {++current; return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    reverse_iterator operator--(int) {reverse_iterator __tmp(*this); ++current; return __tmp;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    reverse_iterator operator+ (difference_type __n) const {return reverse_iterator(current - __n);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    reverse_iterator& operator+=(difference_type __n) {current -= __n; return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    reverse_iterator operator- (difference_type __n) const {return reverse_iterator(current + __n);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    reverse_iterator& operator-=(difference_type __n) {current += __n; return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    reference operator[](difference_type __n) const {return *(*this + __n);}
};

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator==(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __x.base() == __y.base();
}

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __x.base() > __y.base();
}

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __x.base() != __y.base();
}

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __x.base() < __y.base();
}

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __x.base() <= __y.base();
}

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __x.base() >= __y.base();
}

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename reverse_iterator<_Iter1>::difference_type
operator-(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __y.base() - __x.base();
}


template <class _Iter>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
reverse_iterator<_Iter>
operator+(typename reverse_iterator<_Iter>::difference_type __n, const reverse_iterator<_Iter>& __x)
{
    return reverse_iterator<_Iter>(__x.base() - __n);
}

template <class _Container>
class __attribute__ ((__type_visibility__("default"))) back_insert_iterator
    : public iterator<output_iterator_tag,
                      void,
                      void,
                      void,
                      void>
{
protected:
    _Container* container;
public:
    typedef _Container container_type;

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit back_insert_iterator(_Container& __x) : container(std::__1::addressof(__x)) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) back_insert_iterator& operator=(const typename _Container::value_type& __value_)
        {container->push_back(__value_); return *this;}




    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) back_insert_iterator& operator*() {return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) back_insert_iterator& operator++() {return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) back_insert_iterator operator++(int) {return *this;}
};

template <class _Container>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
back_insert_iterator<_Container>
back_inserter(_Container& __x)
{
    return back_insert_iterator<_Container>(__x);
}

template <class _Container>
class __attribute__ ((__type_visibility__("default"))) front_insert_iterator
    : public iterator<output_iterator_tag,
                      void,
                      void,
                      void,
                      void>
{
protected:
    _Container* container;
public:
    typedef _Container container_type;

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit front_insert_iterator(_Container& __x) : container(std::__1::addressof(__x)) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) front_insert_iterator& operator=(const typename _Container::value_type& __value_)
        {container->push_front(__value_); return *this;}




    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) front_insert_iterator& operator*() {return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) front_insert_iterator& operator++() {return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) front_insert_iterator operator++(int) {return *this;}
};

template <class _Container>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
front_insert_iterator<_Container>
front_inserter(_Container& __x)
{
    return front_insert_iterator<_Container>(__x);
}

template <class _Container>
class __attribute__ ((__type_visibility__("default"))) insert_iterator
    : public iterator<output_iterator_tag,
                      void,
                      void,
                      void,
                      void>
{
protected:
    _Container* container;
    typename _Container::iterator iter;
public:
    typedef _Container container_type;

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) insert_iterator(_Container& __x, typename _Container::iterator __i)
        : container(std::__1::addressof(__x)), iter(__i) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) insert_iterator& operator=(const typename _Container::value_type& __value_)
        {iter = container->insert(iter, __value_); ++iter; return *this;}




    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) insert_iterator& operator*() {return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) insert_iterator& operator++() {return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) insert_iterator& operator++(int) {return *this;}
};

template <class _Container>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
insert_iterator<_Container>
inserter(_Container& __x, typename _Container::iterator __i)
{
    return insert_iterator<_Container>(__x, __i);
}

template <class _Tp, class _CharT = char,
          class _Traits = char_traits<_CharT>, class _Distance = ptrdiff_t>
class __attribute__ ((__type_visibility__("default"))) istream_iterator
    : public iterator<input_iterator_tag, _Tp, _Distance, const _Tp*, const _Tp&>
{
public:
    typedef _CharT char_type;
    typedef _Traits traits_type;
    typedef basic_istream<_CharT,_Traits> istream_type;
private:
    istream_type* __in_stream_;
    _Tp __value_;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) istream_iterator() : __in_stream_(0), __value_() {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) istream_iterator(istream_type& __s) : __in_stream_(std::__1::addressof(__s))
        {
            if (!(*__in_stream_ >> __value_))
                __in_stream_ = 0;
        }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) const _Tp& operator*() const {return __value_;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) const _Tp* operator->() const {return std::__1::addressof((operator*()));}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) istream_iterator& operator++()
        {
            if (!(*__in_stream_ >> __value_))
                __in_stream_ = 0;
            return *this;
        }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) istream_iterator operator++(int)
        {istream_iterator __t(*this); ++(*this); return __t;}

    template <class _Up, class _CharU, class _TraitsU, class _DistanceU>
    friend __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool
    operator==(const istream_iterator<_Up, _CharU, _TraitsU, _DistanceU>& __x,
               const istream_iterator<_Up, _CharU, _TraitsU, _DistanceU>& __y);

    template <class _Up, class _CharU, class _TraitsU, class _DistanceU>
    friend __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool
    operator==(const istream_iterator<_Up, _CharU, _TraitsU, _DistanceU>& __x,
               const istream_iterator<_Up, _CharU, _TraitsU, _DistanceU>& __y);
};

template <class _Tp, class _CharT, class _Traits, class _Distance>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator==(const istream_iterator<_Tp, _CharT, _Traits, _Distance>& __x,
           const istream_iterator<_Tp, _CharT, _Traits, _Distance>& __y)
{
    return __x.__in_stream_ == __y.__in_stream_;
}

template <class _Tp, class _CharT, class _Traits, class _Distance>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(const istream_iterator<_Tp, _CharT, _Traits, _Distance>& __x,
           const istream_iterator<_Tp, _CharT, _Traits, _Distance>& __y)
{
    return !(__x == __y);
}

template <class _Tp, class _CharT = char, class _Traits = char_traits<_CharT> >
class __attribute__ ((__type_visibility__("default"))) ostream_iterator
    : public iterator<output_iterator_tag, void, void, void, void>
{
public:
    typedef _CharT char_type;
    typedef _Traits traits_type;
    typedef basic_ostream<_CharT,_Traits> ostream_type;
private:
    ostream_type* __out_stream_;
    const char_type* __delim_;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) ostream_iterator(ostream_type& __s) throw()
        : __out_stream_(std::__1::addressof(__s)), __delim_(0) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) ostream_iterator(ostream_type& __s, const _CharT* __delimiter) throw()
        : __out_stream_(std::__1::addressof(__s)), __delim_(__delimiter) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) ostream_iterator& operator=(const _Tp& __value_)
        {
            *__out_stream_ << __value_;
            if (__delim_)
                *__out_stream_ << __delim_;
            return *this;
        }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) ostream_iterator& operator*() {return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) ostream_iterator& operator++() {return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) ostream_iterator& operator++(int) {return *this;}
};

template<class _CharT, class _Traits>
class __attribute__ ((__type_visibility__("default"))) istreambuf_iterator
    : public iterator<input_iterator_tag, _CharT,
                      typename _Traits::off_type, _CharT*,
                      _CharT>
{
public:
    typedef _CharT char_type;
    typedef _Traits traits_type;
    typedef typename _Traits::int_type int_type;
    typedef basic_streambuf<_CharT,_Traits> streambuf_type;
    typedef basic_istream<_CharT,_Traits> istream_type;
private:
    mutable streambuf_type* __sbuf_;

    class __proxy
    {
        char_type __keep_;
        streambuf_type* __sbuf_;
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __proxy(char_type __c, streambuf_type* __s)
            : __keep_(__c), __sbuf_(__s) {}
        friend class istreambuf_iterator;
    public:
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) char_type operator*() const {return __keep_;}
    };

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool __test_for_eof() const
    {
        if (__sbuf_ && traits_type::eq_int_type(__sbuf_->sgetc(), traits_type::eof()))
            __sbuf_ = 0;
        return __sbuf_ == 0;
    }
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) istreambuf_iterator() throw() : __sbuf_(0) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) istreambuf_iterator(istream_type& __s) throw()
        : __sbuf_(__s.rdbuf()) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) istreambuf_iterator(streambuf_type* __s) throw()
        : __sbuf_(__s) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) istreambuf_iterator(const __proxy& __p) throw()
        : __sbuf_(__p.__sbuf_) {}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) char_type operator*() const
        {return static_cast<char_type>(__sbuf_->sgetc());}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) istreambuf_iterator& operator++()
        {
            __sbuf_->sbumpc();
            return *this;
        }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __proxy operator++(int)
        {
            return __proxy(__sbuf_->sbumpc(), __sbuf_);
        }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) bool equal(const istreambuf_iterator& __b) const
        {return __test_for_eof() == __b.__test_for_eof();}
};

template <class _CharT, class _Traits>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator==(const istreambuf_iterator<_CharT,_Traits>& __a,
                const istreambuf_iterator<_CharT,_Traits>& __b)
                {return __a.equal(__b);}

template <class _CharT, class _Traits>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator!=(const istreambuf_iterator<_CharT,_Traits>& __a,
                const istreambuf_iterator<_CharT,_Traits>& __b)
                {return !__a.equal(__b);}

template <class _CharT, class _Traits>
class __attribute__ ((__type_visibility__("default"))) ostreambuf_iterator
    : public iterator<output_iterator_tag, void, void, void, void>
{
public:
    typedef _CharT char_type;
    typedef _Traits traits_type;
    typedef basic_streambuf<_CharT,_Traits> streambuf_type;
    typedef basic_ostream<_CharT,_Traits> ostream_type;
private:
    streambuf_type* __sbuf_;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) ostreambuf_iterator(ostream_type& __s) throw()
        : __sbuf_(__s.rdbuf()) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) ostreambuf_iterator(streambuf_type* __s) throw()
        : __sbuf_(__s) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) ostreambuf_iterator& operator=(_CharT __c)
        {
            if (__sbuf_ && traits_type::eq_int_type(__sbuf_->sputc(__c), traits_type::eof()))
                __sbuf_ = 0;
            return *this;
        }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) ostreambuf_iterator& operator*() {return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) ostreambuf_iterator& operator++() {return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) ostreambuf_iterator& operator++(int) {return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) bool failed() const throw() {return __sbuf_ == 0;}

    template <class _Ch, class _Tr>
    friend
    __attribute__ ((__visibility__("hidden")))
    ostreambuf_iterator<_Ch, _Tr>
    __pad_and_output(ostreambuf_iterator<_Ch, _Tr> __s,
                     const _Ch* __ob, const _Ch* __op, const _Ch* __oe,
                     ios_base& __iob, _Ch __fl);
};

template <class _Iter>
class __attribute__ ((__type_visibility__("default"))) move_iterator
{
private:
    _Iter __i;
public:
    typedef _Iter iterator_type;
    typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
    typedef typename iterator_traits<iterator_type>::value_type value_type;
    typedef typename iterator_traits<iterator_type>::difference_type difference_type;
    typedef iterator_type pointer;

    typedef typename iterator_traits<iterator_type>::reference reference;


    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    move_iterator() : __i() {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    explicit move_iterator(_Iter __x) : __i(__x) {}
    template <class _Up>
      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
      move_iterator(const move_iterator<_Up>& __u) : __i(__u.base()) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) _Iter base() const {return __i;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    reference operator*() const { return static_cast<reference>(*__i); }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    pointer operator->() const { return __i;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    move_iterator& operator++() {++__i; return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    move_iterator operator++(int) {move_iterator __tmp(*this); ++__i; return __tmp;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    move_iterator& operator--() {--__i; return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    move_iterator operator--(int) {move_iterator __tmp(*this); --__i; return __tmp;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    move_iterator operator+ (difference_type __n) const {return move_iterator(__i + __n);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    move_iterator& operator+=(difference_type __n) {__i += __n; return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    move_iterator operator- (difference_type __n) const {return move_iterator(__i - __n);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    move_iterator& operator-=(difference_type __n) {__i -= __n; return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    reference operator[](difference_type __n) const { return static_cast<reference>(__i[__n]); }
};

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator==(const move_iterator<_Iter1>& __x, const move_iterator<_Iter2>& __y)
{
    return __x.base() == __y.base();
}

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<(const move_iterator<_Iter1>& __x, const move_iterator<_Iter2>& __y)
{
    return __x.base() < __y.base();
}

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(const move_iterator<_Iter1>& __x, const move_iterator<_Iter2>& __y)
{
    return __x.base() != __y.base();
}

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>(const move_iterator<_Iter1>& __x, const move_iterator<_Iter2>& __y)
{
    return __x.base() > __y.base();
}

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>=(const move_iterator<_Iter1>& __x, const move_iterator<_Iter2>& __y)
{
    return __x.base() >= __y.base();
}

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<=(const move_iterator<_Iter1>& __x, const move_iterator<_Iter2>& __y)
{
    return __x.base() <= __y.base();
}

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename move_iterator<_Iter1>::difference_type
operator-(const move_iterator<_Iter1>& __x, const move_iterator<_Iter2>& __y)
{
    return __x.base() - __y.base();
}


template <class _Iter>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
move_iterator<_Iter>
operator+(typename move_iterator<_Iter>::difference_type __n, const move_iterator<_Iter>& __x)
{
    return move_iterator<_Iter>(__x.base() + __n);
}

template <class _Iter>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
move_iterator<_Iter>
make_move_iterator(_Iter __i)
{
    return move_iterator<_Iter>(__i);
}



template <class _Iter> class __wrap_iter;

template <class _Iter1, class _Iter2>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator==(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&) throw();

template <class _Iter1, class _Iter2>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&) throw();

template <class _Iter1, class _Iter2>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&) throw();

template <class _Iter1, class _Iter2>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&) throw();

template <class _Iter1, class _Iter2>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>=(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&) throw();

template <class _Iter1, class _Iter2>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<=(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&) throw();

template <class _Iter1, class _Iter2>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename __wrap_iter<_Iter1>::difference_type
operator-(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&) throw();


template <class _Iter>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__wrap_iter<_Iter>
operator+(typename __wrap_iter<_Iter>::difference_type, __wrap_iter<_Iter>) throw();

template <class _Ip, class _Op> _Op __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) copy(_Ip, _Ip, _Op);
template <class _B1, class _B2> _B2 __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) copy_backward(_B1, _B1, _B2);
template <class _Ip, class _Op> _Op __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) move(_Ip, _Ip, _Op);
template <class _B1, class _B2> _B2 __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) move_backward(_B1, _B1, _B2);



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_trivially_copy_assignable<_Tp>::value,
    _Tp*
>::type
__unwrap_iter(__wrap_iter<_Tp*>);

template <class _Iter>
class __wrap_iter
{
public:
    typedef _Iter iterator_type;
    typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
    typedef typename iterator_traits<iterator_type>::value_type value_type;
    typedef typename iterator_traits<iterator_type>::difference_type difference_type;
    typedef typename iterator_traits<iterator_type>::pointer pointer;
    typedef typename iterator_traits<iterator_type>::reference reference;
private:
    iterator_type __i;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __wrap_iter() throw()



    {



    }
    template <class _Up> __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        __wrap_iter(const __wrap_iter<_Up>& __u,
            typename enable_if<is_convertible<_Up, iterator_type>::value>::type* = 0) throw()
            : __i(__u.base())
    {



    }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) reference operator*() const throw()
    {




        return *__i;
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) pointer operator->() const throw()
    {




        return (pointer)std::__1::addressof(*__i);
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __wrap_iter& operator++() throw()
    {




        ++__i;
        return *this;
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __wrap_iter operator++(int) throw()
        {__wrap_iter __tmp(*this); ++(*this); return __tmp;}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __wrap_iter& operator--() throw()
    {




        --__i;
        return *this;
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __wrap_iter operator--(int) throw()
        {__wrap_iter __tmp(*this); --(*this); return __tmp;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __wrap_iter operator+ (difference_type __n) const throw()
        {__wrap_iter __w(*this); __w += __n; return __w;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __wrap_iter& operator+=(difference_type __n) throw()
    {




        __i += __n;
        return *this;
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __wrap_iter operator- (difference_type __n) const throw()
        {return *this + (-__n);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __wrap_iter& operator-=(difference_type __n) throw()
        {*this += -__n; return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) reference operator[](difference_type __n) const throw()
    {




        return __i[__n];
    }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) iterator_type base() const throw() {return __i;}

private:






    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __wrap_iter(iterator_type __x) throw() : __i(__x) {}


    template <class _Up> friend class __wrap_iter;
    template <class _CharT, class _Traits, class _Alloc> friend class basic_string;
    template <class _Tp, class _Alloc> friend class __attribute__ ((__type_visibility__("default"))) vector;
    template <class _Tp, size_t> friend class __attribute__ ((__type_visibility__("default"))) span;

    template <class _Iter1, class _Iter2>
                                 friend
    bool
    operator==(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&) throw();

    template <class _Iter1, class _Iter2>
                                 friend
    bool
    operator<(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&) throw();

    template <class _Iter1, class _Iter2>
                                 friend
    bool
    operator!=(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&) throw();

    template <class _Iter1, class _Iter2>
                                 friend
    bool
    operator>(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&) throw();

    template <class _Iter1, class _Iter2>
                                 friend
    bool
    operator>=(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&) throw();

    template <class _Iter1, class _Iter2>
                                 friend
    bool
    operator<=(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&) throw();

    template <class _Iter1, class _Iter2>
                                 friend
    typename __wrap_iter<_Iter1>::difference_type
    operator-(const __wrap_iter<_Iter1>&, const __wrap_iter<_Iter2>&) throw();


    template <class _Iter1>
                                 friend
    __wrap_iter<_Iter1>
    operator+(typename __wrap_iter<_Iter1>::difference_type, __wrap_iter<_Iter1>) throw();

    template <class _Ip, class _Op> friend _Op copy(_Ip, _Ip, _Op);
    template <class _B1, class _B2> friend _B2 copy_backward(_B1, _B1, _B2);
    template <class _Ip, class _Op> friend _Op move(_Ip, _Ip, _Op);
    template <class _B1, class _B2> friend _B2 move_backward(_B1, _B1, _B2);


    template <class _Tp>
                                 friend
    typename enable_if
    <
        is_trivially_copy_assignable<_Tp>::value,
        _Tp*
    >::type
    __unwrap_iter(__wrap_iter<_Tp*>);

};

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator==(const __wrap_iter<_Iter1>& __x, const __wrap_iter<_Iter2>& __y) throw()
{
    return __x.base() == __y.base();
}

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<(const __wrap_iter<_Iter1>& __x, const __wrap_iter<_Iter2>& __y) throw()
{




    return __x.base() < __y.base();
}

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(const __wrap_iter<_Iter1>& __x, const __wrap_iter<_Iter2>& __y) throw()
{
    return !(__x == __y);
}

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>(const __wrap_iter<_Iter1>& __x, const __wrap_iter<_Iter2>& __y) throw()
{
    return __y < __x;
}

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>=(const __wrap_iter<_Iter1>& __x, const __wrap_iter<_Iter2>& __y) throw()
{
    return !(__x < __y);
}

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<=(const __wrap_iter<_Iter1>& __x, const __wrap_iter<_Iter2>& __y) throw()
{
    return !(__y < __x);
}

template <class _Iter1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(const __wrap_iter<_Iter1>& __x, const __wrap_iter<_Iter1>& __y) throw()
{
    return !(__x == __y);
}

template <class _Iter1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>(const __wrap_iter<_Iter1>& __x, const __wrap_iter<_Iter1>& __y) throw()
{
    return __y < __x;
}

template <class _Iter1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>=(const __wrap_iter<_Iter1>& __x, const __wrap_iter<_Iter1>& __y) throw()
{
    return !(__x < __y);
}

template <class _Iter1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<=(const __wrap_iter<_Iter1>& __x, const __wrap_iter<_Iter1>& __y) throw()
{
    return !(__y < __x);
}

template <class _Iter1, class _Iter2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename __wrap_iter<_Iter1>::difference_type
operator-(const __wrap_iter<_Iter1>& __x, const __wrap_iter<_Iter2>& __y) throw()
{




    return __x.base() - __y.base();
}


template <class _Iter>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__wrap_iter<_Iter>
operator+(typename __wrap_iter<_Iter>::difference_type __n,
          __wrap_iter<_Iter> __x) throw()
{
    __x += __n;
    return __x;
}

template <class _Iter>
struct __libcpp_is_trivial_iterator
    : public integral_constant<bool,(is_pointer<_Iter>::value)> {};

template <class _Iter>
struct __libcpp_is_trivial_iterator<move_iterator<_Iter> >
    : public integral_constant<bool,(__libcpp_is_trivial_iterator<_Iter>::value)> {};

template <class _Iter>
struct __libcpp_is_trivial_iterator<reverse_iterator<_Iter> >
    : public integral_constant<bool,(__libcpp_is_trivial_iterator<_Iter>::value)> {};

template <class _Iter>
struct __libcpp_is_trivial_iterator<__wrap_iter<_Iter> >
    : public integral_constant<bool,(__libcpp_is_trivial_iterator<_Iter>::value)> {};


template <class _Tp, size_t _Np>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp*
begin(_Tp (&__array)[_Np])
{
    return __array;
}

template <class _Tp, size_t _Np>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp*
end(_Tp (&__array)[_Np])
{
    return __array + _Np;
}

template <class _Cp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename _Cp::iterator
begin(_Cp& __c)
{
    return __c.begin();
}

template <class _Cp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename _Cp::const_iterator
begin(const _Cp& __c)
{
    return __c.begin();
}

template <class _Cp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename _Cp::iterator
end(_Cp& __c)
{
    return __c.end();
}

template <class _Cp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename _Cp::const_iterator
end(const _Cp& __c)
{
    return __c.end();
}

} }










namespace std { inline namespace __1 {

} }








namespace std { inline namespace __1 {


class __attribute__ ((__visibility__("hidden"))) __libcpp_refstring
{
    const char* __imp_;

    bool __uses_refcount() const;
public:
    explicit __libcpp_refstring(const char* __msg);
    __libcpp_refstring(const __libcpp_refstring& __s) throw();
    __libcpp_refstring& operator=(const __libcpp_refstring& __s) throw();
    ~__libcpp_refstring();

    const char* c_str() const throw() {return __imp_;}
};


} }

namespace std
{

class __attribute__ ((__visibility__("default"))) logic_error
    : public exception
{

private:
    std::__1::__libcpp_refstring __imp_;
public:
    explicit logic_error(const string&);
    explicit logic_error(const char*);

    logic_error(const logic_error&) throw();
    logic_error& operator=(const logic_error&) throw();

    virtual ~logic_error() throw();

    virtual const char* what() const throw();





};

class __attribute__ ((__visibility__("default"))) runtime_error
    : public exception
{

private:
    std::__1::__libcpp_refstring __imp_;
public:
    explicit runtime_error(const string&);
    explicit runtime_error(const char*);

    runtime_error(const runtime_error&) throw();
    runtime_error& operator=(const runtime_error&) throw();

    virtual ~runtime_error() throw();

    virtual const char* what() const throw();





};

class __attribute__ ((__visibility__("default"))) domain_error
    : public logic_error
{
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit domain_error(const string& __s) : logic_error(__s) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit domain_error(const char* __s) : logic_error(__s) {}


    virtual ~domain_error() throw();

};

class __attribute__ ((__visibility__("default"))) invalid_argument
    : public logic_error
{
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit invalid_argument(const string& __s) : logic_error(__s) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit invalid_argument(const char* __s) : logic_error(__s) {}


    virtual ~invalid_argument() throw();

};

class __attribute__ ((__visibility__("default"))) length_error
    : public logic_error
{
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit length_error(const string& __s) : logic_error(__s) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit length_error(const char* __s) : logic_error(__s) {}

    virtual ~length_error() throw();

};

class __attribute__ ((__visibility__("default"))) out_of_range
    : public logic_error
{
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit out_of_range(const string& __s) : logic_error(__s) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit out_of_range(const char* __s) : logic_error(__s) {}


    virtual ~out_of_range() throw();

};

class __attribute__ ((__visibility__("default"))) range_error
    : public runtime_error
{
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit range_error(const string& __s) : runtime_error(__s) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit range_error(const char* __s) : runtime_error(__s) {}


    virtual ~range_error() throw();

};

class __attribute__ ((__visibility__("default"))) overflow_error
    : public runtime_error
{
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit overflow_error(const string& __s) : runtime_error(__s) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit overflow_error(const char* __s) : runtime_error(__s) {}


    virtual ~overflow_error() throw();

};

class __attribute__ ((__visibility__("default"))) underflow_error
    : public runtime_error
{
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit underflow_error(const string& __s) : runtime_error(__s) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit underflow_error(const char* __s) : runtime_error(__s) {}


    virtual ~underflow_error() throw();

};

}

namespace std { inline namespace __1 {


__attribute__ ((noreturn)) __attribute__ ((__visibility__("default"))) void __throw_runtime_error(const char*);

__attribute__ ((noreturn)) inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __throw_logic_error(const char*__msg)
{

    throw logic_error(__msg);




}

__attribute__ ((noreturn)) inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __throw_domain_error(const char*__msg)
{

    throw domain_error(__msg);




}

__attribute__ ((noreturn)) inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __throw_invalid_argument(const char*__msg)
{

    throw invalid_argument(__msg);




}

__attribute__ ((noreturn)) inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __throw_length_error(const char*__msg)
{

    throw length_error(__msg);




}

__attribute__ ((noreturn)) inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __throw_out_of_range(const char*__msg)
{

    throw out_of_range(__msg);




}

__attribute__ ((noreturn)) inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __throw_range_error(const char*__msg)
{

    throw range_error(__msg);




}

__attribute__ ((noreturn)) inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __throw_overflow_error(const char*__msg)
{

    throw overflow_error(__msg);




}

__attribute__ ((noreturn)) inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __throw_underflow_error(const char*__msg)
{

    throw underflow_error(__msg);




}

} }









namespace std { inline namespace __1 {




enum __legacy_memory_order {
    __mo_relaxed,
    __mo_consume,
    __mo_acquire,
    __mo_release,
    __mo_acq_rel,
    __mo_seq_cst
};

typedef underlying_type<__legacy_memory_order>::type __memory_order_underlying_t;

typedef enum memory_order {
  memory_order_relaxed = __mo_relaxed,
  memory_order_consume = __mo_consume,
  memory_order_acquire = __mo_acquire,
  memory_order_release = __mo_release,
  memory_order_acq_rel = __mo_acq_rel,
  memory_order_seq_cst = __mo_seq_cst,
} memory_order;



_Static_assert((is_same<underlying_type<memory_order>::type, __memory_order_underlying_t>::value), "unexpected underlying type for std::memory_order");

template <typename _Tp>
struct __cxx_atomic_base_impl {

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))



    __cxx_atomic_base_impl() throw() : __a_value() {}

                    explicit __cxx_atomic_base_impl(_Tp value) throw()
    : __a_value(value) {}
  __extension__ _Atomic(_Tp) __a_value;
};



__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) inline
void __cxx_atomic_thread_fence(memory_order __order) throw() {
    __c11_atomic_thread_fence(static_cast<__memory_order_underlying_t>(__order));
}

__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) inline
void __cxx_atomic_signal_fence(memory_order __order) throw() {
    __c11_atomic_signal_fence(static_cast<__memory_order_underlying_t>(__order));
}

template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __cxx_atomic_init(__cxx_atomic_base_impl<_Tp> volatile* __a, _Tp __val) throw() {
    __c11_atomic_init(&__a->__a_value, __val);
}
template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __cxx_atomic_init(__cxx_atomic_base_impl<_Tp> * __a, _Tp __val) throw() {
    __c11_atomic_init(&__a->__a_value, __val);
}

template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __cxx_atomic_store(__cxx_atomic_base_impl<_Tp> volatile* __a, _Tp __val, memory_order __order) throw() {
    __c11_atomic_store(&__a->__a_value, __val, static_cast<__memory_order_underlying_t>(__order));
}
template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __cxx_atomic_store(__cxx_atomic_base_impl<_Tp> * __a, _Tp __val, memory_order __order) throw() {
    __c11_atomic_store(&__a->__a_value, __val, static_cast<__memory_order_underlying_t>(__order));
}

template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp __cxx_atomic_load(__cxx_atomic_base_impl<_Tp> const volatile* __a, memory_order __order) throw() {
    using __ptr_type = typename remove_const<__decltype(__a->__a_value)>::type*;
    return __c11_atomic_load(const_cast<__ptr_type>(&__a->__a_value), static_cast<__memory_order_underlying_t>(__order));
}
template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp __cxx_atomic_load(__cxx_atomic_base_impl<_Tp> const* __a, memory_order __order) throw() {
    using __ptr_type = typename remove_const<__decltype(__a->__a_value)>::type*;
    return __c11_atomic_load(const_cast<__ptr_type>(&__a->__a_value), static_cast<__memory_order_underlying_t>(__order));
}

template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp __cxx_atomic_exchange(__cxx_atomic_base_impl<_Tp> volatile* __a, _Tp __value, memory_order __order) throw() {
    return __c11_atomic_exchange(&__a->__a_value, __value, static_cast<__memory_order_underlying_t>(__order));
}
template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp __cxx_atomic_exchange(__cxx_atomic_base_impl<_Tp> * __a, _Tp __value, memory_order __order) throw() {
    return __c11_atomic_exchange(&__a->__a_value, __value, static_cast<__memory_order_underlying_t>(__order));
}

template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool __cxx_atomic_compare_exchange_strong(__cxx_atomic_base_impl<_Tp> volatile* __a, _Tp* __expected, _Tp __value, memory_order __success, memory_order __failure) throw() {
    return __c11_atomic_compare_exchange_strong(&__a->__a_value, __expected, __value, static_cast<__memory_order_underlying_t>(__success), static_cast<__memory_order_underlying_t>(__failure));
}
template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool __cxx_atomic_compare_exchange_strong(__cxx_atomic_base_impl<_Tp> * __a, _Tp* __expected, _Tp __value, memory_order __success, memory_order __failure) throw() {
    return __c11_atomic_compare_exchange_strong(&__a->__a_value, __expected, __value, static_cast<__memory_order_underlying_t>(__success), static_cast<__memory_order_underlying_t>(__failure));
}

template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool __cxx_atomic_compare_exchange_weak(__cxx_atomic_base_impl<_Tp> volatile* __a, _Tp* __expected, _Tp __value, memory_order __success, memory_order __failure) throw() {
    return __c11_atomic_compare_exchange_weak(&__a->__a_value, __expected, __value, static_cast<__memory_order_underlying_t>(__success), static_cast<__memory_order_underlying_t>(__failure));
}
template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool __cxx_atomic_compare_exchange_weak(__cxx_atomic_base_impl<_Tp> * __a, _Tp* __expected, _Tp __value, memory_order __success, memory_order __failure) throw() {
    return __c11_atomic_compare_exchange_weak(&__a->__a_value, __expected, __value, static_cast<__memory_order_underlying_t>(__success), static_cast<__memory_order_underlying_t>(__failure));
}

template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp __cxx_atomic_fetch_add(__cxx_atomic_base_impl<_Tp> volatile* __a, _Tp __delta, memory_order __order) throw() {
    return __c11_atomic_fetch_add(&__a->__a_value, __delta, static_cast<__memory_order_underlying_t>(__order));
}
template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp __cxx_atomic_fetch_add(__cxx_atomic_base_impl<_Tp> * __a, _Tp __delta, memory_order __order) throw() {
    return __c11_atomic_fetch_add(&__a->__a_value, __delta, static_cast<__memory_order_underlying_t>(__order));
}

template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp* __cxx_atomic_fetch_add(__cxx_atomic_base_impl<_Tp*> volatile* __a, ptrdiff_t __delta, memory_order __order) throw() {
    return __c11_atomic_fetch_add(&__a->__a_value, __delta, static_cast<__memory_order_underlying_t>(__order));
}
template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp* __cxx_atomic_fetch_add(__cxx_atomic_base_impl<_Tp*> * __a, ptrdiff_t __delta, memory_order __order) throw() {
    return __c11_atomic_fetch_add(&__a->__a_value, __delta, static_cast<__memory_order_underlying_t>(__order));
}

template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp __cxx_atomic_fetch_sub(__cxx_atomic_base_impl<_Tp> volatile* __a, _Tp __delta, memory_order __order) throw() {
    return __c11_atomic_fetch_sub(&__a->__a_value, __delta, static_cast<__memory_order_underlying_t>(__order));
}
template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp __cxx_atomic_fetch_sub(__cxx_atomic_base_impl<_Tp> * __a, _Tp __delta, memory_order __order) throw() {
    return __c11_atomic_fetch_sub(&__a->__a_value, __delta, static_cast<__memory_order_underlying_t>(__order));
}
template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp* __cxx_atomic_fetch_sub(__cxx_atomic_base_impl<_Tp*> volatile* __a, ptrdiff_t __delta, memory_order __order) throw() {
    return __c11_atomic_fetch_sub(&__a->__a_value, __delta, static_cast<__memory_order_underlying_t>(__order));
}
template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp* __cxx_atomic_fetch_sub(__cxx_atomic_base_impl<_Tp*> * __a, ptrdiff_t __delta, memory_order __order) throw() {
    return __c11_atomic_fetch_sub(&__a->__a_value, __delta, static_cast<__memory_order_underlying_t>(__order));
}

template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp __cxx_atomic_fetch_and(__cxx_atomic_base_impl<_Tp> volatile* __a, _Tp __pattern, memory_order __order) throw() {
    return __c11_atomic_fetch_and(&__a->__a_value, __pattern, static_cast<__memory_order_underlying_t>(__order));
}
template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp __cxx_atomic_fetch_and(__cxx_atomic_base_impl<_Tp> * __a, _Tp __pattern, memory_order __order) throw() {
    return __c11_atomic_fetch_and(&__a->__a_value, __pattern, static_cast<__memory_order_underlying_t>(__order));
}

template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp __cxx_atomic_fetch_or(__cxx_atomic_base_impl<_Tp> volatile* __a, _Tp __pattern, memory_order __order) throw() {
    return __c11_atomic_fetch_or(&__a->__a_value, __pattern, static_cast<__memory_order_underlying_t>(__order));
}
template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp __cxx_atomic_fetch_or(__cxx_atomic_base_impl<_Tp> * __a, _Tp __pattern, memory_order __order) throw() {
    return __c11_atomic_fetch_or(&__a->__a_value, __pattern, static_cast<__memory_order_underlying_t>(__order));
}

template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp __cxx_atomic_fetch_xor(__cxx_atomic_base_impl<_Tp> volatile* __a, _Tp __pattern, memory_order __order) throw() {
    return __c11_atomic_fetch_xor(&__a->__a_value, __pattern, static_cast<__memory_order_underlying_t>(__order));
}
template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp __cxx_atomic_fetch_xor(__cxx_atomic_base_impl<_Tp> * __a, _Tp __pattern, memory_order __order) throw() {
    return __c11_atomic_fetch_xor(&__a->__a_value, __pattern, static_cast<__memory_order_underlying_t>(__order));
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp kill_dependency(_Tp __y) throw()
{
    return __y;
}

template <typename _Tp,
          typename _Base = __cxx_atomic_base_impl<_Tp> >

struct __cxx_atomic_impl : public _Base {






  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __cxx_atomic_impl() throw() {}
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit __cxx_atomic_impl(_Tp value) throw()
    : _Base(value) {}
};



template <class _Tp, bool = is_integral<_Tp>::value && !is_same<_Tp, bool>::value>
struct __atomic_base
{
    mutable __cxx_atomic_impl<_Tp> __a_;





    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool is_lock_free() const volatile throw()
        {return __c11_atomic_is_lock_free(sizeof(_Tp));}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool is_lock_free() const throw()
        {return static_cast<__atomic_base const volatile*>(this)->is_lock_free();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void store(_Tp __d, memory_order __m = memory_order_seq_cst) volatile throw()
      __attribute__((diagnose_if(__m == memory_order_consume || __m == memory_order_acquire || __m == memory_order_acq_rel, "memory order argument to atomic operation is invalid", "warning")))
        {__cxx_atomic_store(&__a_, __d, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void store(_Tp __d, memory_order __m = memory_order_seq_cst) throw()
      __attribute__((diagnose_if(__m == memory_order_consume || __m == memory_order_acquire || __m == memory_order_acq_rel, "memory order argument to atomic operation is invalid", "warning")))
        {__cxx_atomic_store(&__a_, __d, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp load(memory_order __m = memory_order_seq_cst) const volatile throw()
      __attribute__((diagnose_if(__m == memory_order_release || __m == memory_order_acq_rel, "memory order argument to atomic operation is invalid", "warning")))
        {return __cxx_atomic_load(&__a_, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp load(memory_order __m = memory_order_seq_cst) const throw()
      __attribute__((diagnose_if(__m == memory_order_release || __m == memory_order_acq_rel, "memory order argument to atomic operation is invalid", "warning")))
        {return __cxx_atomic_load(&__a_, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    operator _Tp() const volatile throw() {return load();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    operator _Tp() const throw() {return load();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp exchange(_Tp __d, memory_order __m = memory_order_seq_cst) volatile throw()
        {return __cxx_atomic_exchange(&__a_, __d, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp exchange(_Tp __d, memory_order __m = memory_order_seq_cst) throw()
        {return __cxx_atomic_exchange(&__a_, __d, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool compare_exchange_weak(_Tp& __e, _Tp __d,
                               memory_order __s, memory_order __f) volatile throw()
      __attribute__((diagnose_if(__f == memory_order_release || __f == memory_order_acq_rel, "memory order argument to atomic operation is invalid", "warning")))
        {return __cxx_atomic_compare_exchange_weak(&__a_, &__e, __d, __s, __f);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool compare_exchange_weak(_Tp& __e, _Tp __d,
                               memory_order __s, memory_order __f) throw()
      __attribute__((diagnose_if(__f == memory_order_release || __f == memory_order_acq_rel, "memory order argument to atomic operation is invalid", "warning")))
        {return __cxx_atomic_compare_exchange_weak(&__a_, &__e, __d, __s, __f);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool compare_exchange_strong(_Tp& __e, _Tp __d,
                                 memory_order __s, memory_order __f) volatile throw()
      __attribute__((diagnose_if(__f == memory_order_release || __f == memory_order_acq_rel, "memory order argument to atomic operation is invalid", "warning")))
        {return __cxx_atomic_compare_exchange_strong(&__a_, &__e, __d, __s, __f);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool compare_exchange_strong(_Tp& __e, _Tp __d,
                                 memory_order __s, memory_order __f) throw()
      __attribute__((diagnose_if(__f == memory_order_release || __f == memory_order_acq_rel, "memory order argument to atomic operation is invalid", "warning")))
        {return __cxx_atomic_compare_exchange_strong(&__a_, &__e, __d, __s, __f);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool compare_exchange_weak(_Tp& __e, _Tp __d,
                              memory_order __m = memory_order_seq_cst) volatile throw()
        {return __cxx_atomic_compare_exchange_weak(&__a_, &__e, __d, __m, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool compare_exchange_weak(_Tp& __e, _Tp __d,
                               memory_order __m = memory_order_seq_cst) throw()
        {return __cxx_atomic_compare_exchange_weak(&__a_, &__e, __d, __m, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool compare_exchange_strong(_Tp& __e, _Tp __d,
                              memory_order __m = memory_order_seq_cst) volatile throw()
        {return __cxx_atomic_compare_exchange_strong(&__a_, &__e, __d, __m, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool compare_exchange_strong(_Tp& __e, _Tp __d,
                                 memory_order __m = memory_order_seq_cst) throw()
        {return __cxx_atomic_compare_exchange_strong(&__a_, &__e, __d, __m, __m);}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    __atomic_base() throw() {}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    __atomic_base(_Tp __d) throw() : __a_(__d) {}






private:
    __atomic_base(const __atomic_base&);
    __atomic_base& operator=(const __atomic_base&);
    __atomic_base& operator=(const __atomic_base&) volatile;

};

template <class _Tp>
struct __atomic_base<_Tp, true>
    : public __atomic_base<_Tp, false>
{
    typedef __atomic_base<_Tp, false> __base;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    __atomic_base() throw() {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
                      __atomic_base(_Tp __d) throw() : __base(__d) {}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp fetch_add(_Tp __op, memory_order __m = memory_order_seq_cst) volatile throw()
        {return __cxx_atomic_fetch_add(&this->__a_, __op, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp fetch_add(_Tp __op, memory_order __m = memory_order_seq_cst) throw()
        {return __cxx_atomic_fetch_add(&this->__a_, __op, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp fetch_sub(_Tp __op, memory_order __m = memory_order_seq_cst) volatile throw()
        {return __cxx_atomic_fetch_sub(&this->__a_, __op, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp fetch_sub(_Tp __op, memory_order __m = memory_order_seq_cst) throw()
        {return __cxx_atomic_fetch_sub(&this->__a_, __op, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp fetch_and(_Tp __op, memory_order __m = memory_order_seq_cst) volatile throw()
        {return __cxx_atomic_fetch_and(&this->__a_, __op, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp fetch_and(_Tp __op, memory_order __m = memory_order_seq_cst) throw()
        {return __cxx_atomic_fetch_and(&this->__a_, __op, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp fetch_or(_Tp __op, memory_order __m = memory_order_seq_cst) volatile throw()
        {return __cxx_atomic_fetch_or(&this->__a_, __op, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp fetch_or(_Tp __op, memory_order __m = memory_order_seq_cst) throw()
        {return __cxx_atomic_fetch_or(&this->__a_, __op, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp fetch_xor(_Tp __op, memory_order __m = memory_order_seq_cst) volatile throw()
        {return __cxx_atomic_fetch_xor(&this->__a_, __op, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp fetch_xor(_Tp __op, memory_order __m = memory_order_seq_cst) throw()
        {return __cxx_atomic_fetch_xor(&this->__a_, __op, __m);}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator++(int) volatile throw() {return fetch_add(_Tp(1));}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator++(int) throw() {return fetch_add(_Tp(1));}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator--(int) volatile throw() {return fetch_sub(_Tp(1));}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator--(int) throw() {return fetch_sub(_Tp(1));}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator++() volatile throw() {return fetch_add(_Tp(1)) + _Tp(1);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator++() throw() {return fetch_add(_Tp(1)) + _Tp(1);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator--() volatile throw() {return fetch_sub(_Tp(1)) - _Tp(1);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator--() throw() {return fetch_sub(_Tp(1)) - _Tp(1);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator+=(_Tp __op) volatile throw() {return fetch_add(__op) + __op;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator+=(_Tp __op) throw() {return fetch_add(__op) + __op;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator-=(_Tp __op) volatile throw() {return fetch_sub(__op) - __op;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator-=(_Tp __op) throw() {return fetch_sub(__op) - __op;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator&=(_Tp __op) volatile throw() {return fetch_and(__op) & __op;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator&=(_Tp __op) throw() {return fetch_and(__op) & __op;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator|=(_Tp __op) volatile throw() {return fetch_or(__op) | __op;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator|=(_Tp __op) throw() {return fetch_or(__op) | __op;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator^=(_Tp __op) volatile throw() {return fetch_xor(__op) ^ __op;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator^=(_Tp __op) throw() {return fetch_xor(__op) ^ __op;}
};



template <class _Tp>
struct atomic
    : public __atomic_base<_Tp>
{
    typedef __atomic_base<_Tp> __base;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    atomic() throw() {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
                      atomic(_Tp __d) throw() : __base(__d) {}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator=(_Tp __d) volatile throw()
        {__base::store(__d); return __d;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator=(_Tp __d) throw()
        {__base::store(__d); return __d;}
};



template <class _Tp>
struct atomic<_Tp*>
    : public __atomic_base<_Tp*>
{
    typedef __atomic_base<_Tp*> __base;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    atomic() throw() {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
                      atomic(_Tp* __d) throw() : __base(__d) {}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* operator=(_Tp* __d) volatile throw()
        {__base::store(__d); return __d;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* operator=(_Tp* __d) throw()
        {__base::store(__d); return __d;}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* fetch_add(ptrdiff_t __op, memory_order __m = memory_order_seq_cst)
                                                                        volatile throw()
        {return __cxx_atomic_fetch_add(&this->__a_, __op, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* fetch_add(ptrdiff_t __op, memory_order __m = memory_order_seq_cst) throw()
        {return __cxx_atomic_fetch_add(&this->__a_, __op, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* fetch_sub(ptrdiff_t __op, memory_order __m = memory_order_seq_cst)
                                                                        volatile throw()
        {return __cxx_atomic_fetch_sub(&this->__a_, __op, __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* fetch_sub(ptrdiff_t __op, memory_order __m = memory_order_seq_cst) throw()
        {return __cxx_atomic_fetch_sub(&this->__a_, __op, __m);}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* operator++(int) volatile throw() {return fetch_add(1);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* operator++(int) throw() {return fetch_add(1);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* operator--(int) volatile throw() {return fetch_sub(1);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* operator--(int) throw() {return fetch_sub(1);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* operator++() volatile throw() {return fetch_add(1) + 1;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* operator++() throw() {return fetch_add(1) + 1;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* operator--() volatile throw() {return fetch_sub(1) - 1;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* operator--() throw() {return fetch_sub(1) - 1;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* operator+=(ptrdiff_t __op) volatile throw() {return fetch_add(__op) + __op;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* operator+=(ptrdiff_t __op) throw() {return fetch_add(__op) + __op;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* operator-=(ptrdiff_t __op) volatile throw() {return fetch_sub(__op) - __op;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* operator-=(ptrdiff_t __op) throw() {return fetch_sub(__op) - __op;}
};



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
atomic_is_lock_free(const volatile atomic<_Tp>* __o) throw()
{
    return __o->is_lock_free();
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
atomic_is_lock_free(const atomic<_Tp>* __o) throw()
{
    return __o->is_lock_free();
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
atomic_init(volatile atomic<_Tp>* __o, _Tp __d) throw()
{
    __cxx_atomic_init(&__o->__a_, __d);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
atomic_init(atomic<_Tp>* __o, _Tp __d) throw()
{
    __cxx_atomic_init(&__o->__a_, __d);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
atomic_store(volatile atomic<_Tp>* __o, _Tp __d) throw()
{
    __o->store(__d);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
atomic_store(atomic<_Tp>* __o, _Tp __d) throw()
{
    __o->store(__d);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
atomic_store_explicit(volatile atomic<_Tp>* __o, _Tp __d, memory_order __m) throw()
  __attribute__((diagnose_if(__m == memory_order_consume || __m == memory_order_acquire || __m == memory_order_acq_rel, "memory order argument to atomic operation is invalid", "warning")))
{
    __o->store(__d, __m);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
atomic_store_explicit(atomic<_Tp>* __o, _Tp __d, memory_order __m) throw()
  __attribute__((diagnose_if(__m == memory_order_consume || __m == memory_order_acquire || __m == memory_order_acq_rel, "memory order argument to atomic operation is invalid", "warning")))
{
    __o->store(__d, __m);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp
atomic_load(const volatile atomic<_Tp>* __o) throw()
{
    return __o->load();
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp
atomic_load(const atomic<_Tp>* __o) throw()
{
    return __o->load();
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp
atomic_load_explicit(const volatile atomic<_Tp>* __o, memory_order __m) throw()
  __attribute__((diagnose_if(__m == memory_order_release || __m == memory_order_acq_rel, "memory order argument to atomic operation is invalid", "warning")))
{
    return __o->load(__m);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp
atomic_load_explicit(const atomic<_Tp>* __o, memory_order __m) throw()
  __attribute__((diagnose_if(__m == memory_order_release || __m == memory_order_acq_rel, "memory order argument to atomic operation is invalid", "warning")))
{
    return __o->load(__m);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp
atomic_exchange(volatile atomic<_Tp>* __o, _Tp __d) throw()
{
    return __o->exchange(__d);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp
atomic_exchange(atomic<_Tp>* __o, _Tp __d) throw()
{
    return __o->exchange(__d);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp
atomic_exchange_explicit(volatile atomic<_Tp>* __o, _Tp __d, memory_order __m) throw()
{
    return __o->exchange(__d, __m);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp
atomic_exchange_explicit(atomic<_Tp>* __o, _Tp __d, memory_order __m) throw()
{
    return __o->exchange(__d, __m);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
atomic_compare_exchange_weak(volatile atomic<_Tp>* __o, _Tp* __e, _Tp __d) throw()
{
    return __o->compare_exchange_weak(*__e, __d);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
atomic_compare_exchange_weak(atomic<_Tp>* __o, _Tp* __e, _Tp __d) throw()
{
    return __o->compare_exchange_weak(*__e, __d);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
atomic_compare_exchange_strong(volatile atomic<_Tp>* __o, _Tp* __e, _Tp __d) throw()
{
    return __o->compare_exchange_strong(*__e, __d);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
atomic_compare_exchange_strong(atomic<_Tp>* __o, _Tp* __e, _Tp __d) throw()
{
    return __o->compare_exchange_strong(*__e, __d);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
atomic_compare_exchange_weak_explicit(volatile atomic<_Tp>* __o, _Tp* __e,
                                      _Tp __d,
                                      memory_order __s, memory_order __f) throw()
  __attribute__((diagnose_if(__f == memory_order_release || __f == memory_order_acq_rel, "memory order argument to atomic operation is invalid", "warning")))
{
    return __o->compare_exchange_weak(*__e, __d, __s, __f);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
atomic_compare_exchange_weak_explicit(atomic<_Tp>* __o, _Tp* __e, _Tp __d,
                                      memory_order __s, memory_order __f) throw()
  __attribute__((diagnose_if(__f == memory_order_release || __f == memory_order_acq_rel, "memory order argument to atomic operation is invalid", "warning")))
{
    return __o->compare_exchange_weak(*__e, __d, __s, __f);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
atomic_compare_exchange_strong_explicit(volatile atomic<_Tp>* __o,
                                        _Tp* __e, _Tp __d,
                                        memory_order __s, memory_order __f) throw()
  __attribute__((diagnose_if(__f == memory_order_release || __f == memory_order_acq_rel, "memory order argument to atomic operation is invalid", "warning")))
{
    return __o->compare_exchange_strong(*__e, __d, __s, __f);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
atomic_compare_exchange_strong_explicit(atomic<_Tp>* __o, _Tp* __e,
                                        _Tp __d,
                                        memory_order __s, memory_order __f) throw()
  __attribute__((diagnose_if(__f == memory_order_release || __f == memory_order_acq_rel, "memory order argument to atomic operation is invalid", "warning")))
{
    return __o->compare_exchange_strong(*__e, __d, __s, __f);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_add(volatile atomic<_Tp>* __o, _Tp __op) throw()
{
    return __o->fetch_add(__op);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_add(atomic<_Tp>* __o, _Tp __op) throw()
{
    return __o->fetch_add(__op);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp*
atomic_fetch_add(volatile atomic<_Tp*>* __o, ptrdiff_t __op) throw()
{
    return __o->fetch_add(__op);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp*
atomic_fetch_add(atomic<_Tp*>* __o, ptrdiff_t __op) throw()
{
    return __o->fetch_add(__op);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_add_explicit(volatile atomic<_Tp>* __o, _Tp __op, memory_order __m) throw()
{
    return __o->fetch_add(__op, __m);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_add_explicit(atomic<_Tp>* __o, _Tp __op, memory_order __m) throw()
{
    return __o->fetch_add(__op, __m);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp*
atomic_fetch_add_explicit(volatile atomic<_Tp*>* __o, ptrdiff_t __op,
                          memory_order __m) throw()
{
    return __o->fetch_add(__op, __m);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp*
atomic_fetch_add_explicit(atomic<_Tp*>* __o, ptrdiff_t __op, memory_order __m) throw()
{
    return __o->fetch_add(__op, __m);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_sub(volatile atomic<_Tp>* __o, _Tp __op) throw()
{
    return __o->fetch_sub(__op);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_sub(atomic<_Tp>* __o, _Tp __op) throw()
{
    return __o->fetch_sub(__op);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp*
atomic_fetch_sub(volatile atomic<_Tp*>* __o, ptrdiff_t __op) throw()
{
    return __o->fetch_sub(__op);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp*
atomic_fetch_sub(atomic<_Tp*>* __o, ptrdiff_t __op) throw()
{
    return __o->fetch_sub(__op);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_sub_explicit(volatile atomic<_Tp>* __o, _Tp __op, memory_order __m) throw()
{
    return __o->fetch_sub(__op, __m);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_sub_explicit(atomic<_Tp>* __o, _Tp __op, memory_order __m) throw()
{
    return __o->fetch_sub(__op, __m);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp*
atomic_fetch_sub_explicit(volatile atomic<_Tp*>* __o, ptrdiff_t __op,
                          memory_order __m) throw()
{
    return __o->fetch_sub(__op, __m);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp*
atomic_fetch_sub_explicit(atomic<_Tp*>* __o, ptrdiff_t __op, memory_order __m) throw()
{
    return __o->fetch_sub(__op, __m);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_and(volatile atomic<_Tp>* __o, _Tp __op) throw()
{
    return __o->fetch_and(__op);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_and(atomic<_Tp>* __o, _Tp __op) throw()
{
    return __o->fetch_and(__op);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_and_explicit(volatile atomic<_Tp>* __o, _Tp __op, memory_order __m) throw()
{
    return __o->fetch_and(__op, __m);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_and_explicit(atomic<_Tp>* __o, _Tp __op, memory_order __m) throw()
{
    return __o->fetch_and(__op, __m);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_or(volatile atomic<_Tp>* __o, _Tp __op) throw()
{
    return __o->fetch_or(__op);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_or(atomic<_Tp>* __o, _Tp __op) throw()
{
    return __o->fetch_or(__op);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_or_explicit(volatile atomic<_Tp>* __o, _Tp __op, memory_order __m) throw()
{
    return __o->fetch_or(__op, __m);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_or_explicit(atomic<_Tp>* __o, _Tp __op, memory_order __m) throw()
{
    return __o->fetch_or(__op, __m);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_xor(volatile atomic<_Tp>* __o, _Tp __op) throw()
{
    return __o->fetch_xor(__op);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_xor(atomic<_Tp>* __o, _Tp __op) throw()
{
    return __o->fetch_xor(__op);
}



template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_xor_explicit(volatile atomic<_Tp>* __o, _Tp __op, memory_order __m) throw()
{
    return __o->fetch_xor(__op, __m);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Tp>::value && !is_same<_Tp, bool>::value,
    _Tp
>::type
atomic_fetch_xor_explicit(atomic<_Tp>* __o, _Tp __op, memory_order __m) throw()
{
    return __o->fetch_xor(__op, __m);
}



typedef struct atomic_flag
{
    __cxx_atomic_impl<bool> __a_;

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool test_and_set(memory_order __m = memory_order_seq_cst) volatile throw()
        {return __cxx_atomic_exchange(&__a_, bool(true), __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool test_and_set(memory_order __m = memory_order_seq_cst) throw()
        {return __cxx_atomic_exchange(&__a_, bool(true), __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void clear(memory_order __m = memory_order_seq_cst) volatile throw()
        {__cxx_atomic_store(&__a_, bool(false), __m);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void clear(memory_order __m = memory_order_seq_cst) throw()
        {__cxx_atomic_store(&__a_, bool(false), __m);}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    atomic_flag() throw() {}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    atomic_flag(bool __b) throw() : __a_(__b) {}






private:
    atomic_flag(const atomic_flag&);
    atomic_flag& operator=(const atomic_flag&);
    atomic_flag& operator=(const atomic_flag&) volatile;

} atomic_flag;

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
atomic_flag_test_and_set(volatile atomic_flag* __o) throw()
{
    return __o->test_and_set();
}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
atomic_flag_test_and_set(atomic_flag* __o) throw()
{
    return __o->test_and_set();
}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
atomic_flag_test_and_set_explicit(volatile atomic_flag* __o, memory_order __m) throw()
{
    return __o->test_and_set(__m);
}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
atomic_flag_test_and_set_explicit(atomic_flag* __o, memory_order __m) throw()
{
    return __o->test_and_set(__m);
}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
atomic_flag_clear(volatile atomic_flag* __o) throw()
{
    __o->clear();
}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
atomic_flag_clear(atomic_flag* __o) throw()
{
    __o->clear();
}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
atomic_flag_clear_explicit(volatile atomic_flag* __o, memory_order __m) throw()
{
    __o->clear(__m);
}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
atomic_flag_clear_explicit(atomic_flag* __o, memory_order __m) throw()
{
    __o->clear(__m);
}



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
atomic_thread_fence(memory_order __m) throw()
{
    __cxx_atomic_thread_fence(__m);
}

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
atomic_signal_fence(memory_order __m) throw()
{
    __cxx_atomic_signal_fence(__m);
}



typedef atomic<bool> atomic_bool;
typedef atomic<char> atomic_char;
typedef atomic<signed char> atomic_schar;
typedef atomic<unsigned char> atomic_uchar;
typedef atomic<short> atomic_short;
typedef atomic<unsigned short> atomic_ushort;
typedef atomic<int> atomic_int;
typedef atomic<unsigned int> atomic_uint;
typedef atomic<long> atomic_long;
typedef atomic<unsigned long> atomic_ulong;
typedef atomic<long long> atomic_llong;
typedef atomic<unsigned long long> atomic_ullong;
typedef atomic<char16_t> atomic_char16_t;
typedef atomic<char32_t> atomic_char32_t;
typedef atomic<wchar_t> atomic_wchar_t;

typedef atomic<int_least8_t> atomic_int_least8_t;
typedef atomic<uint_least8_t> atomic_uint_least8_t;
typedef atomic<int_least16_t> atomic_int_least16_t;
typedef atomic<uint_least16_t> atomic_uint_least16_t;
typedef atomic<int_least32_t> atomic_int_least32_t;
typedef atomic<uint_least32_t> atomic_uint_least32_t;
typedef atomic<int_least64_t> atomic_int_least64_t;
typedef atomic<uint_least64_t> atomic_uint_least64_t;

typedef atomic<int_fast8_t> atomic_int_fast8_t;
typedef atomic<uint_fast8_t> atomic_uint_fast8_t;
typedef atomic<int_fast16_t> atomic_int_fast16_t;
typedef atomic<uint_fast16_t> atomic_uint_fast16_t;
typedef atomic<int_fast32_t> atomic_int_fast32_t;
typedef atomic<uint_fast32_t> atomic_uint_fast32_t;
typedef atomic<int_fast64_t> atomic_int_fast64_t;
typedef atomic<uint_fast64_t> atomic_uint_fast64_t;

typedef atomic< int8_t> atomic_int8_t;
typedef atomic<uint8_t> atomic_uint8_t;
typedef atomic< int16_t> atomic_int16_t;
typedef atomic<uint16_t> atomic_uint16_t;
typedef atomic< int32_t> atomic_int32_t;
typedef atomic<uint32_t> atomic_uint32_t;
typedef atomic< int64_t> atomic_int64_t;
typedef atomic<uint64_t> atomic_uint64_t;

typedef atomic<intptr_t> atomic_intptr_t;
typedef atomic<uintptr_t> atomic_uintptr_t;
typedef atomic<size_t> atomic_size_t;
typedef atomic<ptrdiff_t> atomic_ptrdiff_t;
typedef atomic<intmax_t> atomic_intmax_t;
typedef atomic<uintmax_t> atomic_uintmax_t;




} }
















extern "C" {
void __assert_rtn(const char *, const char *, int, const char *) __attribute__((__noreturn__)) __attribute__((__cold__)) __attribute__((__disable_tail_calls__));



}











namespace std { inline namespace __1 {

template <class _ValueType>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ValueType __libcpp_relaxed_load(_ValueType const* __value) {



    return __atomic_load_n(__value, 0);



}

template <class _ValueType>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ValueType __libcpp_acquire_load(_ValueType const* __value) {



    return __atomic_load_n(__value, 2);



}



template <class _Tp> class allocator;

template <>
class __attribute__ ((__type_visibility__("default"))) allocator<void>
{
public:
    typedef void* pointer;
    typedef const void* const_pointer;
    typedef void value_type;

    template <class _Up> struct rebind {typedef allocator<_Up> other;};
};

template <>
class __attribute__ ((__type_visibility__("default"))) allocator<const void>
{
public:
    typedef const void* pointer;
    typedef const void* const_pointer;
    typedef const void value_type;

    template <class _Up> struct rebind {typedef allocator<_Up> other;};
};



template <class _Tp, class = void>
struct __has_element_type : false_type {};

template <class _Tp>
struct __has_element_type<_Tp,
              typename __void_t<typename _Tp::element_type>::type> : true_type {};

template <class _Ptr, bool = __has_element_type<_Ptr>::value>
struct __pointer_traits_element_type;

template <class _Ptr>
struct __pointer_traits_element_type<_Ptr, true>
{
    typedef typename _Ptr::element_type type;
};

template <template <class> class _Sp, class _Tp>
struct __pointer_traits_element_type<_Sp<_Tp>, true>
{
    typedef typename _Sp<_Tp>::element_type type;
};

template <template <class> class _Sp, class _Tp>
struct __pointer_traits_element_type<_Sp<_Tp>, false>
{
    typedef _Tp type;
};

template <template <class, class> class _Sp, class _Tp, class _A0>
struct __pointer_traits_element_type<_Sp<_Tp, _A0>, true>
{
    typedef typename _Sp<_Tp, _A0>::element_type type;
};

template <template <class, class> class _Sp, class _Tp, class _A0>
struct __pointer_traits_element_type<_Sp<_Tp, _A0>, false>
{
    typedef _Tp type;
};

template <template <class, class, class> class _Sp, class _Tp, class _A0, class _A1>
struct __pointer_traits_element_type<_Sp<_Tp, _A0, _A1>, true>
{
    typedef typename _Sp<_Tp, _A0, _A1>::element_type type;
};

template <template <class, class, class> class _Sp, class _Tp, class _A0, class _A1>
struct __pointer_traits_element_type<_Sp<_Tp, _A0, _A1>, false>
{
    typedef _Tp type;
};

template <template <class, class, class, class> class _Sp, class _Tp, class _A0,
                                                           class _A1, class _A2>
struct __pointer_traits_element_type<_Sp<_Tp, _A0, _A1, _A2>, true>
{
    typedef typename _Sp<_Tp, _A0, _A1, _A2>::element_type type;
};

template <template <class, class, class, class> class _Sp, class _Tp, class _A0,
                                                           class _A1, class _A2>
struct __pointer_traits_element_type<_Sp<_Tp, _A0, _A1, _A2>, false>
{
    typedef _Tp type;
};



template <class _Tp, class = void>
struct __has_difference_type : false_type {};

template <class _Tp>
struct __has_difference_type<_Tp,
            typename __void_t<typename _Tp::difference_type>::type> : true_type {};

template <class _Ptr, bool = __has_difference_type<_Ptr>::value>
struct __pointer_traits_difference_type
{
    typedef ptrdiff_t type;
};

template <class _Ptr>
struct __pointer_traits_difference_type<_Ptr, true>
{
    typedef typename _Ptr::difference_type type;
};

template <class _Tp, class _Up>
struct __has_rebind
{
private:
    struct __two {char __lx; char __lxx;};
    template <class _Xp> static __two __test(...);
    template <class _Xp> static char __test(typename _Xp::template rebind<_Up>* = 0);
public:
    static const bool value = sizeof(__test<_Tp>(0)) == 1;
};

template <class _Tp, class _Up, bool = __has_rebind<_Tp, _Up>::value>
struct __pointer_traits_rebind
{



    typedef typename _Tp::template rebind<_Up>::other type;

};

template <template <class> class _Sp, class _Tp, class _Up>
struct __pointer_traits_rebind<_Sp<_Tp>, _Up, true>
{



    typedef typename _Sp<_Tp>::template rebind<_Up>::other type;

};

template <template <class> class _Sp, class _Tp, class _Up>
struct __pointer_traits_rebind<_Sp<_Tp>, _Up, false>
{
    typedef _Sp<_Up> type;
};

template <template <class, class> class _Sp, class _Tp, class _A0, class _Up>
struct __pointer_traits_rebind<_Sp<_Tp, _A0>, _Up, true>
{



    typedef typename _Sp<_Tp, _A0>::template rebind<_Up>::other type;

};

template <template <class, class> class _Sp, class _Tp, class _A0, class _Up>
struct __pointer_traits_rebind<_Sp<_Tp, _A0>, _Up, false>
{
    typedef _Sp<_Up, _A0> type;
};

template <template <class, class, class> class _Sp, class _Tp, class _A0,
                                         class _A1, class _Up>
struct __pointer_traits_rebind<_Sp<_Tp, _A0, _A1>, _Up, true>
{



    typedef typename _Sp<_Tp, _A0, _A1>::template rebind<_Up>::other type;

};

template <template <class, class, class> class _Sp, class _Tp, class _A0,
                                         class _A1, class _Up>
struct __pointer_traits_rebind<_Sp<_Tp, _A0, _A1>, _Up, false>
{
    typedef _Sp<_Up, _A0, _A1> type;
};

template <template <class, class, class, class> class _Sp, class _Tp, class _A0,
                                                class _A1, class _A2, class _Up>
struct __pointer_traits_rebind<_Sp<_Tp, _A0, _A1, _A2>, _Up, true>
{



    typedef typename _Sp<_Tp, _A0, _A1, _A2>::template rebind<_Up>::other type;

};

template <template <class, class, class, class> class _Sp, class _Tp, class _A0,
                                                class _A1, class _A2, class _Up>
struct __pointer_traits_rebind<_Sp<_Tp, _A0, _A1, _A2>, _Up, false>
{
    typedef _Sp<_Up, _A0, _A1, _A2> type;
};



template <class _Ptr>
struct __attribute__ ((__type_visibility__("default"))) pointer_traits
{
    typedef _Ptr pointer;
    typedef typename __pointer_traits_element_type<pointer>::type element_type;
    typedef typename __pointer_traits_difference_type<pointer>::type difference_type;




    template <class _Up> struct rebind
        {typedef typename __pointer_traits_rebind<pointer, _Up>::type other;};


private:
    struct __nat {};
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static pointer pointer_to(typename conditional<is_void<element_type>::value,
                                           __nat, element_type>::type& __r)
        {return pointer::pointer_to(__r);}
};

template <class _Tp>
struct __attribute__ ((__type_visibility__("default"))) pointer_traits<_Tp*>
{
    typedef _Tp* pointer;
    typedef _Tp element_type;
    typedef ptrdiff_t difference_type;




    template <class _Up> struct rebind {typedef _Up* other;};


private:
    struct __nat {};
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static pointer pointer_to(typename conditional<is_void<element_type>::value,
                                      __nat, element_type>::type& __r) throw()
        {return std::__1::addressof(__r);}
};

template <class _From, class _To>
struct __rebind_pointer {



    typedef typename pointer_traits<_From>::template rebind<_To>::other type;

};



template <class _Tp, class = void>
struct __has_pointer_type : false_type {};

template <class _Tp>
struct __has_pointer_type<_Tp,
          typename __void_t<typename _Tp::pointer>::type> : true_type {};

namespace __pointer_type_imp
{

template <class _Tp, class _Dp, bool = __has_pointer_type<_Dp>::value>
struct __pointer_type
{
    typedef typename _Dp::pointer type;
};

template <class _Tp, class _Dp>
struct __pointer_type<_Tp, _Dp, false>
{
    typedef _Tp* type;
};

}

template <class _Tp, class _Dp>
struct __pointer_type
{
    typedef typename __pointer_type_imp::__pointer_type<_Tp, typename remove_reference<_Dp>::type>::type type;
};

template <class _Tp, class = void>
struct __has_const_pointer : false_type {};

template <class _Tp>
struct __has_const_pointer<_Tp,
            typename __void_t<typename _Tp::const_pointer>::type> : true_type {};

template <class _Tp, class _Ptr, class _Alloc, bool = __has_const_pointer<_Alloc>::value>
struct __const_pointer
{
    typedef typename _Alloc::const_pointer type;
};

template <class _Tp, class _Ptr, class _Alloc>
struct __const_pointer<_Tp, _Ptr, _Alloc, false>
{



    typedef typename pointer_traits<_Ptr>::template rebind<const _Tp>::other type;

};

template <class _Tp, class = void>
struct __has_void_pointer : false_type {};

template <class _Tp>
struct __has_void_pointer<_Tp,
               typename __void_t<typename _Tp::void_pointer>::type> : true_type {};

template <class _Ptr, class _Alloc, bool = __has_void_pointer<_Alloc>::value>
struct __void_pointer
{
    typedef typename _Alloc::void_pointer type;
};

template <class _Ptr, class _Alloc>
struct __void_pointer<_Ptr, _Alloc, false>
{



    typedef typename pointer_traits<_Ptr>::template rebind<void>::other type;

};

template <class _Tp, class = void>
struct __has_const_void_pointer : false_type {};

template <class _Tp>
struct __has_const_void_pointer<_Tp,
            typename __void_t<typename _Tp::const_void_pointer>::type> : true_type {};

template <class _Ptr, class _Alloc, bool = __has_const_void_pointer<_Alloc>::value>
struct __const_void_pointer
{
    typedef typename _Alloc::const_void_pointer type;
};

template <class _Ptr, class _Alloc>
struct __const_void_pointer<_Ptr, _Alloc, false>
{



    typedef typename pointer_traits<_Ptr>::template rebind<const void>::other type;

};


template <bool _UsePointerTraits> struct __to_address_helper;

template <> struct __to_address_helper<true> {
    template <class _Pointer>
    using __return_type = __decltype(pointer_traits<_Pointer>::to_address(std::declval<const _Pointer&>()));

    template <class _Pointer>

    static __return_type<_Pointer>
    __do_it(const _Pointer &__p) throw() { return pointer_traits<_Pointer>::to_address(__p); }
};

template <class _Pointer, bool _Dummy = true>
using __choose_to_address = __to_address_helper<_IsValidExpansion<__to_address_helper<_Dummy>::template __return_type, _Pointer>::value>;


template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp*
__to_address(_Tp* __p) throw()
{
    _Static_assert(!is_function<_Tp>::value, "_Tp is a function type");
    return __p;
}

template <class _Pointer>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename __choose_to_address<_Pointer>::template __return_type<_Pointer>
__to_address(const _Pointer& __p) throw() {
  return __choose_to_address<_Pointer>::__do_it(__p);
}

template <> struct __to_address_helper<false> {
    template <class _Pointer>
    using __return_type = typename pointer_traits<_Pointer>::element_type*;

    template <class _Pointer>

    static __return_type<_Pointer>
    __do_it(const _Pointer &__p) throw() { return std::__to_address(__p.operator->()); }
};

template <class _Tp, class = void>
struct __has_size_type : false_type {};

template <class _Tp>
struct __has_size_type<_Tp,
               typename __void_t<typename _Tp::size_type>::type> : true_type {};

template <class _Alloc, class _DiffType, bool = __has_size_type<_Alloc>::value>
struct __size_type
{
    typedef typename make_unsigned<_DiffType>::type type;
};

template <class _Alloc, class _DiffType>
struct __size_type<_Alloc, _DiffType, true>
{
    typedef typename _Alloc::size_type type;
};

template <class _Tp, class = void>
struct __has_propagate_on_container_copy_assignment : false_type {};

template <class _Tp>
struct __has_propagate_on_container_copy_assignment<_Tp,
    typename __void_t<typename _Tp::propagate_on_container_copy_assignment>::type>
        : true_type {};

template <class _Alloc, bool = __has_propagate_on_container_copy_assignment<_Alloc>::value>
struct __propagate_on_container_copy_assignment
{
    typedef false_type type;
};

template <class _Alloc>
struct __propagate_on_container_copy_assignment<_Alloc, true>
{
    typedef typename _Alloc::propagate_on_container_copy_assignment type;
};

template <class _Tp, class = void>
struct __has_propagate_on_container_move_assignment : false_type {};

template <class _Tp>
struct __has_propagate_on_container_move_assignment<_Tp,
           typename __void_t<typename _Tp::propagate_on_container_move_assignment>::type>
               : true_type {};

template <class _Alloc, bool = __has_propagate_on_container_move_assignment<_Alloc>::value>
struct __propagate_on_container_move_assignment
{
    typedef false_type type;
};

template <class _Alloc>
struct __propagate_on_container_move_assignment<_Alloc, true>
{
    typedef typename _Alloc::propagate_on_container_move_assignment type;
};

template <class _Tp, class = void>
struct __has_propagate_on_container_swap : false_type {};

template <class _Tp>
struct __has_propagate_on_container_swap<_Tp,
           typename __void_t<typename _Tp::propagate_on_container_swap>::type>
               : true_type {};

template <class _Alloc, bool = __has_propagate_on_container_swap<_Alloc>::value>
struct __propagate_on_container_swap
{
    typedef false_type type;
};

template <class _Alloc>
struct __propagate_on_container_swap<_Alloc, true>
{
    typedef typename _Alloc::propagate_on_container_swap type;
};

template <class _Tp, class = void>
struct __has_is_always_equal : false_type {};

template <class _Tp>
struct __has_is_always_equal<_Tp,
           typename __void_t<typename _Tp::is_always_equal>::type>
               : true_type {};

template <class _Alloc, bool = __has_is_always_equal<_Alloc>::value>
struct __is_always_equal
{
    typedef typename std::__1::is_empty<_Alloc>::type type;
};

template <class _Alloc>
struct __is_always_equal<_Alloc, true>
{
    typedef typename _Alloc::is_always_equal type;
};

template <class _Tp, class _Up, bool = __has_rebind<_Tp, _Up>::value>
struct __has_rebind_other
{
private:
    struct __two {char __lx; char __lxx;};
    template <class _Xp> static __two __test(...);
    template <class _Xp> static char __test(typename _Xp::template rebind<_Up>::other* = 0);
public:
    static const bool value = sizeof(__test<_Tp>(0)) == 1;
};

template <class _Tp, class _Up>
struct __has_rebind_other<_Tp, _Up, false>
{
    static const bool value = false;
};

template <class _Tp, class _Up, bool = __has_rebind_other<_Tp, _Up>::value>
struct __allocator_traits_rebind
{
    typedef typename _Tp::template rebind<_Up>::other type;
};

template <template <class> class _Alloc, class _Tp, class _Up>
struct __allocator_traits_rebind<_Alloc<_Tp>, _Up, true>
{
    typedef typename _Alloc<_Tp>::template rebind<_Up>::other type;
};

template <template <class> class _Alloc, class _Tp, class _Up>
struct __allocator_traits_rebind<_Alloc<_Tp>, _Up, false>
{
    typedef _Alloc<_Up> type;
};

template <template <class, class> class _Alloc, class _Tp, class _A0, class _Up>
struct __allocator_traits_rebind<_Alloc<_Tp, _A0>, _Up, true>
{
    typedef typename _Alloc<_Tp, _A0>::template rebind<_Up>::other type;
};

template <template <class, class> class _Alloc, class _Tp, class _A0, class _Up>
struct __allocator_traits_rebind<_Alloc<_Tp, _A0>, _Up, false>
{
    typedef _Alloc<_Up, _A0> type;
};

template <template <class, class, class> class _Alloc, class _Tp, class _A0,
                                         class _A1, class _Up>
struct __allocator_traits_rebind<_Alloc<_Tp, _A0, _A1>, _Up, true>
{
    typedef typename _Alloc<_Tp, _A0, _A1>::template rebind<_Up>::other type;
};

template <template <class, class, class> class _Alloc, class _Tp, class _A0,
                                         class _A1, class _Up>
struct __allocator_traits_rebind<_Alloc<_Tp, _A0, _A1>, _Up, false>
{
    typedef _Alloc<_Up, _A0, _A1> type;
};

template <template <class, class, class, class> class _Alloc, class _Tp, class _A0,
                                                class _A1, class _A2, class _Up>
struct __allocator_traits_rebind<_Alloc<_Tp, _A0, _A1, _A2>, _Up, true>
{
    typedef typename _Alloc<_Tp, _A0, _A1, _A2>::template rebind<_Up>::other type;
};

template <template <class, class, class, class> class _Alloc, class _Tp, class _A0,
                                                class _A1, class _A2, class _Up>
struct __allocator_traits_rebind<_Alloc<_Tp, _A0, _A1, _A2>, _Up, false>
{
    typedef _Alloc<_Up, _A0, _A1, _A2> type;
};

template <class _Alloc, class _SizeType, class _ConstVoidPtr>
struct __has_allocate_hint
    : true_type
{
};

template <class _Alloc, class _Pointer, class _Tp, class = void>
struct __has_construct : std::false_type {};

template <class _Alloc, class _Pointer, class _Tp>
struct __has_construct<_Alloc, _Pointer, _Tp, typename __void_t<
    __decltype(std::__1::declval<_Alloc>().construct(std::__1::declval<_Pointer>(), std::__1::declval<_Tp>()))
>::type> : std::true_type {};

template <class _Alloc, class _Pointer, class = void>
struct __has_destroy : false_type {};

template <class _Alloc, class _Pointer>
struct __has_destroy<_Alloc, _Pointer, typename __void_t<
    __decltype(std::__1::declval<_Alloc>().destroy(std::__1::declval<_Pointer>()))
>::type> : std::true_type {};

template <class _Alloc>
struct __has_max_size
    : true_type
{
};

template <class _Alloc>
struct __has_select_on_container_copy_construction
    : false_type
{
};



template <class _Alloc, class _Ptr, bool = __has_difference_type<_Alloc>::value>
struct __alloc_traits_difference_type
{
    typedef typename pointer_traits<_Ptr>::difference_type type;
};

template <class _Alloc, class _Ptr>
struct __alloc_traits_difference_type<_Alloc, _Ptr, true>
{
    typedef typename _Alloc::difference_type type;
};

template <class _Tp>
struct __is_default_allocator : false_type {};

template <class _Tp>
struct __is_default_allocator<std::__1::allocator<_Tp> > : true_type {};



template <class _Alloc,
    bool = __has_construct<_Alloc, typename _Alloc::value_type*, typename _Alloc::value_type&&>::value && !__is_default_allocator<_Alloc>::value
    >
struct __is_cpp17_move_insertable;
template <class _Alloc>
struct __is_cpp17_move_insertable<_Alloc, true> : std::true_type {};
template <class _Alloc>
struct __is_cpp17_move_insertable<_Alloc, false> : std::is_move_constructible<typename _Alloc::value_type> {};

template <class _Alloc,
    bool = __has_construct<_Alloc, typename _Alloc::value_type*, const typename _Alloc::value_type&>::value && !__is_default_allocator<_Alloc>::value
    >
struct __is_cpp17_copy_insertable;
template <class _Alloc>
struct __is_cpp17_copy_insertable<_Alloc, true> : __is_cpp17_move_insertable<_Alloc> {};
template <class _Alloc>
struct __is_cpp17_copy_insertable<_Alloc, false> : integral_constant<bool,
    std::is_copy_constructible<typename _Alloc::value_type>::value &&
    __is_cpp17_move_insertable<_Alloc>::value>
  {};



template <class _Alloc>
struct __attribute__ ((__type_visibility__("default"))) allocator_traits
{
    typedef _Alloc allocator_type;
    typedef typename allocator_type::value_type value_type;

    typedef typename __pointer_type<value_type, allocator_type>::type pointer;
    typedef typename __const_pointer<value_type, pointer, allocator_type>::type const_pointer;
    typedef typename __void_pointer<pointer, allocator_type>::type void_pointer;
    typedef typename __const_void_pointer<pointer, allocator_type>::type const_void_pointer;

    typedef typename __alloc_traits_difference_type<allocator_type, pointer>::type difference_type;
    typedef typename __size_type<allocator_type, difference_type>::type size_type;

    typedef typename __propagate_on_container_copy_assignment<allocator_type>::type
                     propagate_on_container_copy_assignment;
    typedef typename __propagate_on_container_move_assignment<allocator_type>::type
                     propagate_on_container_move_assignment;
    typedef typename __propagate_on_container_swap<allocator_type>::type
                     propagate_on_container_swap;
    typedef typename __is_always_equal<allocator_type>::type
                     is_always_equal;






    template <class _Tp> struct rebind_alloc
        {typedef typename __allocator_traits_rebind<allocator_type, _Tp>::type other;};
    template <class _Tp> struct rebind_traits
        {typedef allocator_traits<typename rebind_alloc<_Tp>::other> other;};


                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static pointer allocate(allocator_type& __a, size_type __n)
        {return __a.allocate(__n);}
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static pointer allocate(allocator_type& __a, size_type __n, const_void_pointer __hint)
        {return __allocate(__a, __n, __hint,
            __has_allocate_hint<allocator_type, size_type, const_void_pointer>());}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static void deallocate(allocator_type& __a, pointer __p, size_type __n) throw()
        {__a.deallocate(__p, __n);}

    template <class _Tp>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        static void construct(allocator_type&, _Tp* __p)
            {
                ::new ((void*)__p) _Tp();
            }
    template <class _Tp, class _A0>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        static void construct(allocator_type& __a, _Tp* __p, const _A0& __a0)
            {
                __construct(__has_construct<allocator_type, _Tp*, const _A0&>(),
                            __a, __p, __a0);
            }
    template <class _Tp, class _A0, class _A1>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        static void construct(allocator_type&, _Tp* __p, const _A0& __a0,
                              const _A1& __a1)
            {
                ::new ((void*)__p) _Tp(__a0, __a1);
            }
    template <class _Tp, class _A0, class _A1, class _A2>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        static void construct(allocator_type&, _Tp* __p, const _A0& __a0,
                              const _A1& __a1, const _A2& __a2)
            {
                ::new ((void*)__p) _Tp(__a0, __a1, __a2);
            }


    template <class _Tp>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        static void destroy(allocator_type& __a, _Tp* __p)
            {__destroy(__has_destroy<allocator_type, _Tp*>(), __a, __p);}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static size_type max_size(const allocator_type& __a) throw()
        {return __max_size(__has_max_size<const allocator_type>(), __a);}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static allocator_type
        select_on_container_copy_construction(const allocator_type& __a)
            {return __select_on_container_copy_construction(
                __has_select_on_container_copy_construction<const allocator_type>(),
                __a);}

    template <class _Ptr>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        static
        void
        __construct_forward_with_exception_guarantees(allocator_type& __a, _Ptr __begin1, _Ptr __end1, _Ptr& __begin2)
        {
            _Static_assert(__is_cpp17_move_insertable<allocator_type>::value, "The specified type does not meet the requirements of Cpp17MoveInsertible");

            for (; __begin1 != __end1; ++__begin1, (void) ++__begin2)
              construct(__a, std::__1::__to_address(__begin2),



                        std::__1::move_if_noexcept(*__begin1)

                        );
        }

    template <class _Tp>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        static
        typename enable_if
        <
            (__is_default_allocator<allocator_type>::value
                || !__has_construct<allocator_type, _Tp*, _Tp>::value) &&
             is_trivially_move_constructible<_Tp>::value,
            void
        >::type
        __construct_forward_with_exception_guarantees(allocator_type&, _Tp* __begin1, _Tp* __end1, _Tp*& __begin2)
        {
            ptrdiff_t _Np = __end1 - __begin1;
            if (_Np > 0)
            {
                std::__1::memcpy(__begin2, __begin1, _Np * sizeof(_Tp));
                __begin2 += _Np;
            }
        }

    template <class _Iter, class _Ptr>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        static
        void
        __construct_range_forward(allocator_type& __a, _Iter __begin1, _Iter __end1, _Ptr& __begin2)
        {
            for (; __begin1 != __end1; ++__begin1, (void) ++__begin2)
                construct(__a, std::__1::__to_address(__begin2), *__begin1);
        }

    template <class _SourceTp, class _DestTp,
              class _RawSourceTp = typename remove_const<_SourceTp>::type,
              class _RawDestTp = typename remove_const<_DestTp>::type>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        static
        typename enable_if
        <
            is_trivially_copy_constructible<_DestTp>::value &&
            is_same<_RawSourceTp, _RawDestTp>::value &&
            (__is_default_allocator<allocator_type>::value ||
             !__has_construct<allocator_type, _DestTp*, _SourceTp&>::value),
            void
        >::type
        __construct_range_forward(allocator_type&, _SourceTp* __begin1, _SourceTp* __end1, _DestTp*& __begin2)
        {
            ptrdiff_t _Np = __end1 - __begin1;
            if (_Np > 0)
            {
                std::__1::memcpy(const_cast<_RawDestTp*>(__begin2), __begin1, _Np * sizeof(_DestTp));
                __begin2 += _Np;
            }
        }

    template <class _Ptr>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        static
        void
        __construct_backward_with_exception_guarantees(allocator_type& __a, _Ptr __begin1, _Ptr __end1, _Ptr& __end2)
        {
            _Static_assert(__is_cpp17_move_insertable<allocator_type>::value, "The specified type does not meet the requirements of Cpp17MoveInsertable");

            while (__end1 != __begin1)
            {
              construct(__a, std::__1::__to_address(__end2 - 1),



                        std::__1::move_if_noexcept(*--__end1)

                        );
              --__end2;
            }
        }

    template <class _Tp>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        static
        typename enable_if
        <
            (__is_default_allocator<allocator_type>::value
                || !__has_construct<allocator_type, _Tp*, _Tp>::value) &&
             is_trivially_move_constructible<_Tp>::value,
            void
        >::type
        __construct_backward_with_exception_guarantees(allocator_type&, _Tp* __begin1, _Tp* __end1, _Tp*& __end2)
        {
            ptrdiff_t _Np = __end1 - __begin1;
            __end2 -= _Np;
            if (_Np > 0)
                std::__1::memcpy(__end2, __begin1, _Np * sizeof(_Tp));
        }

private:

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static pointer __allocate(allocator_type& __a, size_type __n,
        const_void_pointer __hint, true_type)
        {return __a.allocate(__n, __hint);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static pointer __allocate(allocator_type& __a, size_type __n,
        const_void_pointer, false_type)
        {return __a.allocate(__n);}

    template <class _Tp, class _A0>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        static void __construct(true_type, allocator_type& __a, _Tp* __p,
                                const _A0& __a0)
            {__a.construct(__p, __a0);}
    template <class _Tp, class _A0>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        static void __construct(false_type, allocator_type&, _Tp* __p,
                                const _A0& __a0)
            {
                ::new ((void*)__p) _Tp(__a0);
            }


    template <class _Tp>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        static void __destroy(true_type, allocator_type& __a, _Tp* __p)
            {__a.destroy(__p);}
    template <class _Tp>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        static void __destroy(false_type, allocator_type&, _Tp* __p)
            {
                __p->~_Tp();
            }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static size_type __max_size(true_type, const allocator_type& __a) throw()
            {return __a.max_size();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static size_type __max_size(false_type, const allocator_type&) throw()
            {return numeric_limits<size_type>::max() / sizeof(value_type);}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static allocator_type
        __select_on_container_copy_construction(true_type, const allocator_type& __a)
            {return __a.select_on_container_copy_construction();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static allocator_type
        __select_on_container_copy_construction(false_type, const allocator_type& __a)
            {return __a;}
};

template <class _Traits, class _Tp>
struct __rebind_alloc_helper
{



    typedef typename _Traits::template rebind_alloc<_Tp>::other type;

};



template <class _Tp>
class __attribute__ ((__type_visibility__("default"))) allocator
{
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef _Tp* pointer;
    typedef const _Tp* const_pointer;
    typedef _Tp& reference;
    typedef const _Tp& const_reference;
    typedef _Tp value_type;

    typedef true_type propagate_on_container_move_assignment;
    typedef true_type is_always_equal;

    template <class _Up> struct rebind {typedef allocator<_Up> other;};

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    allocator() throw() {}

    template <class _Up>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    allocator(const allocator<_Up>&) throw() {}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) pointer address(reference __x) const throw()
        {return std::__1::addressof(__x);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) const_pointer address(const_reference __x) const throw()
        {return std::__1::addressof(__x);}
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    pointer allocate(size_type __n, allocator<void>::const_pointer = 0)
        {
        if (__n > max_size())
            __throw_length_error("allocator<T>::allocate(size_t n)"
                                 " 'n' exceeds maximum supported size");
        return static_cast<pointer>(std::__1::__libcpp_allocate(__n * sizeof(_Tp), _Alignof(_Tp)));
        }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void deallocate(pointer __p, size_type __n) throw()
        {std::__1::__libcpp_deallocate((void*)__p, __n * sizeof(_Tp), _Alignof(_Tp));}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) size_type max_size() const throw()
        {return size_type(~0) / sizeof(_Tp);}

        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        void
        construct(pointer __p)
        {
            ::new((void*)__p) _Tp();
        }


    template <class _A0>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        void
        construct(pointer __p, _A0& __a0)
        {
            ::new((void*)__p) _Tp(__a0);
        }
    template <class _A0>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        void
        construct(pointer __p, const _A0& __a0)
        {
            ::new((void*)__p) _Tp(__a0);
        }

    template <class _A0, class _A1>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        void
        construct(pointer __p, _A0& __a0, _A1& __a1)
        {
            ::new((void*)__p) _Tp(__a0, __a1);
        }
    template <class _A0, class _A1>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        void
        construct(pointer __p, const _A0& __a0, _A1& __a1)
        {
            ::new((void*)__p) _Tp(__a0, __a1);
        }
    template <class _A0, class _A1>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        void
        construct(pointer __p, _A0& __a0, const _A1& __a1)
        {
            ::new((void*)__p) _Tp(__a0, __a1);
        }
    template <class _A0, class _A1>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        void
        construct(pointer __p, const _A0& __a0, const _A1& __a1)
        {
            ::new((void*)__p) _Tp(__a0, __a1);
        }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void destroy(pointer __p) {__p->~_Tp();}
};

template <class _Tp>
class __attribute__ ((__type_visibility__("default"))) allocator<const _Tp>
{
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef const _Tp* pointer;
    typedef const _Tp* const_pointer;
    typedef const _Tp& reference;
    typedef const _Tp& const_reference;
    typedef const _Tp value_type;

    typedef true_type propagate_on_container_move_assignment;
    typedef true_type is_always_equal;

    template <class _Up> struct rebind {typedef allocator<_Up> other;};

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    allocator() throw() {}

    template <class _Up>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    allocator(const allocator<_Up>&) throw() {}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) const_pointer address(const_reference __x) const throw()
        {return std::__1::addressof(__x);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) pointer allocate(size_type __n, allocator<void>::const_pointer = 0)
    {
        if (__n > max_size())
            __throw_length_error("allocator<const T>::allocate(size_t n)"
                                 " 'n' exceeds maximum supported size");
        return static_cast<pointer>(std::__1::__libcpp_allocate(__n * sizeof(_Tp), _Alignof(_Tp)));
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void deallocate(pointer __p, size_type __n) throw()
        {std::__1::__libcpp_deallocate((void*) const_cast<_Tp *>(__p), __n * sizeof(_Tp), _Alignof(_Tp));}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) size_type max_size() const throw()
        {return size_type(~0) / sizeof(_Tp);}

        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        void
        construct(pointer __p)
        {
            ::new((void*) const_cast<_Tp *>(__p)) _Tp();
        }


    template <class _A0>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        void
        construct(pointer __p, _A0& __a0)
        {
            ::new((void*) const_cast<_Tp *>(__p)) _Tp(__a0);
        }
    template <class _A0>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        void
        construct(pointer __p, const _A0& __a0)
        {
            ::new((void*) const_cast<_Tp *>(__p)) _Tp(__a0);
        }

    template <class _A0, class _A1>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        void
        construct(pointer __p, _A0& __a0, _A1& __a1)
        {
            ::new((void*) const_cast<_Tp *>(__p)) _Tp(__a0, __a1);
        }
    template <class _A0, class _A1>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        void
        construct(pointer __p, const _A0& __a0, _A1& __a1)
        {
            ::new((void*) const_cast<_Tp *>(__p)) _Tp(__a0, __a1);
        }
    template <class _A0, class _A1>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        void
        construct(pointer __p, _A0& __a0, const _A1& __a1)
        {
            ::new((void*) const_cast<_Tp *>(__p)) _Tp(__a0, __a1);
        }
    template <class _A0, class _A1>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        void
        construct(pointer __p, const _A0& __a0, const _A1& __a1)
        {
            ::new((void*) const_cast<_Tp *>(__p)) _Tp(__a0, __a1);
        }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void destroy(pointer __p) {__p->~_Tp();}
};

template <class _Tp, class _Up>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator==(const allocator<_Tp>&, const allocator<_Up>&) throw() {return true;}

template <class _Tp, class _Up>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator!=(const allocator<_Tp>&, const allocator<_Up>&) throw() {return false;}

template <class _OutputIterator, class _Tp>
class __attribute__ ((__type_visibility__("default"))) raw_storage_iterator
    : public iterator<output_iterator_tag,
                      _Tp,
                      ptrdiff_t,
                      _Tp*,
                      raw_storage_iterator<_OutputIterator, _Tp>&>
{
private:
    _OutputIterator __x_;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit raw_storage_iterator(_OutputIterator __x) : __x_(__x) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) raw_storage_iterator& operator*() {return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) raw_storage_iterator& operator=(const _Tp& __element)
        {::new(std::__1::addressof(*__x_)) _Tp(__element); return *this;}




    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) raw_storage_iterator& operator++() {++__x_; return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) raw_storage_iterator operator++(int)
        {raw_storage_iterator __t(*this); ++__x_; return __t;}



};

template <class _Tp>
                      __attribute__((__no_sanitize__("cfi")))
pair<_Tp*, ptrdiff_t>
get_temporary_buffer(ptrdiff_t __n) throw()
{
    pair<_Tp*, ptrdiff_t> __r(0, 0);
    const ptrdiff_t __m = (~ptrdiff_t(0) ^
                           ptrdiff_t(ptrdiff_t(1) << (sizeof(ptrdiff_t) * 8 - 1)))
                           / sizeof(_Tp);
    if (__n > __m)
        __n = __m;
    while (__n > 0)
    {

    if (__is_overaligned_for_new(_Alignof(_Tp)))
        {


            return __r;
        }

        __r.first = static_cast<_Tp*>(::operator new(__n * sizeof(_Tp), nothrow));


        if (__r.first)
        {
            __r.second = __n;
            break;
        }
        __n /= 2;
    }
    return __r;
}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void return_temporary_buffer(_Tp* __p) throw()
{
  std::__1::__libcpp_deallocate_unsized((void*)__p, _Alignof(_Tp));
}


template <class _Tp>
struct auto_ptr_ref
{
    _Tp* __ptr_;
};

template<class _Tp>
class __attribute__ ((__type_visibility__("default"))) auto_ptr
{
private:
    _Tp* __ptr_;
public:
    typedef _Tp element_type;

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit auto_ptr(_Tp* __p = 0) throw() : __ptr_(__p) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) auto_ptr(auto_ptr& __p) throw() : __ptr_(__p.release()) {}
    template<class _Up> __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) auto_ptr(auto_ptr<_Up>& __p) throw()
        : __ptr_(__p.release()) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) auto_ptr& operator=(auto_ptr& __p) throw()
        {reset(__p.release()); return *this;}
    template<class _Up> __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) auto_ptr& operator=(auto_ptr<_Up>& __p) throw()
        {reset(__p.release()); return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) auto_ptr& operator=(auto_ptr_ref<_Tp> __p) throw()
        {reset(__p.__ptr_); return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) ~auto_ptr() throw() {delete __ptr_;}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) _Tp& operator*() const throw()
        {return *__ptr_;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) _Tp* operator->() const throw() {return __ptr_;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) _Tp* get() const throw() {return __ptr_;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) _Tp* release() throw()
    {
        _Tp* __t = __ptr_;
        __ptr_ = 0;
        return __t;
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void reset(_Tp* __p = 0) throw()
    {
        if (__ptr_ != __p)
            delete __ptr_;
        __ptr_ = __p;
    }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) auto_ptr(auto_ptr_ref<_Tp> __p) throw() : __ptr_(__p.__ptr_) {}
    template<class _Up> __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) operator auto_ptr_ref<_Up>() throw()
        {auto_ptr_ref<_Up> __t; __t.__ptr_ = release(); return __t;}
    template<class _Up> __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) operator auto_ptr<_Up>() throw()
        {return auto_ptr<_Up>(release());}
};

template <>
class __attribute__ ((__type_visibility__("default"))) auto_ptr<void>
{
public:
    typedef void element_type;
};



struct __default_init_tag {};
struct __value_init_tag {};

template <class _Tp, int _Idx,
          bool _CanBeEmptyBase =
              is_empty<_Tp>::value && !__libcpp_is_final<_Tp>::value>
struct __compressed_pair_elem {
  typedef _Tp _ParamT;
  typedef _Tp& reference;
  typedef const _Tp& const_reference;

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  __compressed_pair_elem(__default_init_tag) {}
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  __compressed_pair_elem(__value_init_tag) : __value_() {}

  template <class _Up, class = typename enable_if<
      !is_same<__compressed_pair_elem, typename decay<_Up>::type>::value
  >::type>
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
                    explicit
  __compressed_pair_elem(_Up&& __u)
      : __value_(std::__1::forward<_Up>(__u))
    {
    }

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) reference __get() throw() { return __value_; }
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  const_reference __get() const throw() { return __value_; }

private:
  _Tp __value_;
};

template <class _Tp, int _Idx>
struct __compressed_pair_elem<_Tp, _Idx, true> : private _Tp {
  typedef _Tp _ParamT;
  typedef _Tp& reference;
  typedef const _Tp& const_reference;
  typedef _Tp __value_type;

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __compressed_pair_elem() = default;
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  __compressed_pair_elem(__default_init_tag) {}
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  __compressed_pair_elem(__value_init_tag) : __value_type() {}

  template <class _Up, class = typename enable_if<
        !is_same<__compressed_pair_elem, typename decay<_Up>::type>::value
  >::type>
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
                    explicit
  __compressed_pair_elem(_Up&& __u)
      : __value_type(std::__1::forward<_Up>(__u))
  {}

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) reference __get() throw() { return *this; }
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  const_reference __get() const throw() { return *this; }
};

template <class _T1, class _T2>
class __compressed_pair : private __compressed_pair_elem<_T1, 0>,
                          private __compressed_pair_elem<_T2, 1> {
  typedef __compressed_pair_elem<_T1, 0> _Base1;
  typedef __compressed_pair_elem<_T2, 1> _Base2;





  _Static_assert((!is_same<_T1, _T2>::value), "__compressed_pair cannot be instantated when T1 and T2 are the same type; " "The current implementation is NOT ABI-compatible with the previous " "implementation for this configuration");




public:
    template <bool _Dummy = true,
      class = typename enable_if<
          __dependent_type<is_default_constructible<_T1>, _Dummy>::value &&
          __dependent_type<is_default_constructible<_T2>, _Dummy>::value
      >::type
  >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
                    __compressed_pair() : _Base1(__value_init_tag()), _Base2(__value_init_tag()) {}

  template <class _U1, class _U2>
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  __compressed_pair(_U1&& __t1, _U2&& __t2)
      : _Base1(std::forward<_U1>(__t1)), _Base2(std::forward<_U2>(__t2)) {}

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  typename _Base1::reference first() throw() {
    return static_cast<_Base1&>(*this).__get();
  }

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  typename _Base1::const_reference first() const throw() {
    return static_cast<_Base1 const&>(*this).__get();
  }

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  typename _Base2::reference second() throw() {
    return static_cast<_Base2&>(*this).__get();
  }

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  typename _Base2::const_reference second() const throw() {
    return static_cast<_Base2 const&>(*this).__get();
  }

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  void swap(__compressed_pair& __x)


  {
    using std::swap;
    swap(first(), __x.first());
    swap(second(), __x.second());
  }
};

template <class _T1, class _T2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void swap(__compressed_pair<_T1, _T2>& __x, __compressed_pair<_T1, _T2>& __y)

                                                   {
  __x.swap(__y);
}



template <class _Tp>
struct __attribute__ ((__type_visibility__("default"))) default_delete {
    _Static_assert(!is_function<_Tp>::value, "default_delete cannot be instantiated for function types");




  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) default_delete() {}

  template <class _Up>
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  default_delete(const default_delete<_Up>&,
                 typename enable_if<is_convertible<_Up*, _Tp*>::value>::type* =
                     0) throw() {}

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void operator()(_Tp* __ptr) const throw() {
    _Static_assert(sizeof(_Tp) > 0, "default_delete can not delete incomplete type");

    _Static_assert(!is_void<_Tp>::value, "default_delete can not delete incomplete type");

    delete __ptr;
  }
};

template <class _Tp>
struct __attribute__ ((__type_visibility__("default"))) default_delete<_Tp[]> {
private:
  template <class _Up>
  struct _EnableIfConvertible
      : enable_if<is_convertible<_Up(*)[], _Tp(*)[]>::value> {};

public:



  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) default_delete() {}


  template <class _Up>
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  default_delete(const default_delete<_Up[]>&,
                 typename _EnableIfConvertible<_Up>::type* = 0) throw() {}

  template <class _Up>
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  typename _EnableIfConvertible<_Up>::type
  operator()(_Up* __ptr) const throw() {
    _Static_assert(sizeof(_Tp) > 0, "default_delete can not delete incomplete type");

    _Static_assert(!is_void<_Tp>::value, "default_delete can not delete void type");

    delete[] __ptr;
  }
};

template <class _Deleter>
struct __unique_ptr_deleter_sfinae {
  _Static_assert(!is_reference<_Deleter>::value, "incorrect specialization");
  typedef const _Deleter& __lval_ref_type;
  typedef _Deleter&& __good_rval_ref_type;
  typedef true_type __enable_rval_overload;
};

template <class _Deleter>
struct __unique_ptr_deleter_sfinae<_Deleter const&> {
  typedef const _Deleter& __lval_ref_type;
  typedef const _Deleter&& __bad_rval_ref_type;
  typedef false_type __enable_rval_overload;
};

template <class _Deleter>
struct __unique_ptr_deleter_sfinae<_Deleter&> {
  typedef _Deleter& __lval_ref_type;
  typedef _Deleter&& __bad_rval_ref_type;
  typedef false_type __enable_rval_overload;
};

template <class _Tp, class _Dp = default_delete<_Tp> >
class __attribute__ ((__type_visibility__("default"))) unique_ptr {
public:
  typedef _Tp element_type;
  typedef _Dp deleter_type;
  typedef typename __pointer_type<_Tp, deleter_type>::type pointer;

  _Static_assert(!is_rvalue_reference<deleter_type>::value, "the specified deleter type cannot be an rvalue reference");


private:
  __compressed_pair<pointer, deleter_type> __ptr_;

  struct __nat { int __for_bool_; };

  typedef __unique_ptr_deleter_sfinae<_Dp> _DeleterSFINAE;

  template <bool _Dummy>
  using _LValRefType =
      typename __dependent_type<_DeleterSFINAE, _Dummy>::__lval_ref_type;

  template <bool _Dummy>
  using _GoodRValRefType =
      typename __dependent_type<_DeleterSFINAE, _Dummy>::__good_rval_ref_type;

  template <bool _Dummy>
  using _BadRValRefType =
      typename __dependent_type<_DeleterSFINAE, _Dummy>::__bad_rval_ref_type;

  template <bool _Dummy, class _Deleter = typename __dependent_type<
                             __identity<deleter_type>, _Dummy>::type>
  using _EnableIfDeleterDefaultConstructible =
      typename enable_if<is_default_constructible<_Deleter>::value &&
                         !is_pointer<_Deleter>::value>::type;

  template <class _ArgType>
  using _EnableIfDeleterConstructible =
      typename enable_if<is_constructible<deleter_type, _ArgType>::value>::type;

  template <class _UPtr, class _Up>
  using _EnableIfMoveConvertible = typename enable_if<
      is_convertible<typename _UPtr::pointer, pointer>::value &&
      !is_array<_Up>::value
  >::type;

  template <class _UDel>
  using _EnableIfDeleterConvertible = typename enable_if<
      (is_reference<_Dp>::value && is_same<_Dp, _UDel>::value) ||
      (!is_reference<_Dp>::value && is_convertible<_UDel, _Dp>::value)
    >::type;

  template <class _UDel>
  using _EnableIfDeleterAssignable = typename enable_if<
      is_assignable<_Dp&, _UDel&&>::value
    >::type;

public:
  template <bool _Dummy = true,
            class = _EnableIfDeleterDefaultConstructible<_Dummy> >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
                    unique_ptr() throw() : __ptr_(pointer(), __default_init_tag()) {}

  template <bool _Dummy = true,
            class = _EnableIfDeleterDefaultConstructible<_Dummy> >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
                    unique_ptr(nullptr_t) throw() : __ptr_(pointer(), __default_init_tag()) {}

  template <bool _Dummy = true,
            class = _EnableIfDeleterDefaultConstructible<_Dummy> >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  explicit unique_ptr(pointer __p) throw() : __ptr_(__p, __default_init_tag()) {}

  template <bool _Dummy = true,
            class = _EnableIfDeleterConstructible<_LValRefType<_Dummy> > >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr(pointer __p, _LValRefType<_Dummy> __d) throw()
      : __ptr_(__p, __d) {}

  template <bool _Dummy = true,
            class = _EnableIfDeleterConstructible<_GoodRValRefType<_Dummy> > >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr(pointer __p, _GoodRValRefType<_Dummy> __d) throw()
      : __ptr_(__p, std::__1::move(__d)) {
    _Static_assert(!is_reference<deleter_type>::value, "rvalue deleter bound to reference");

  }

  template <bool _Dummy = true,
            class = _EnableIfDeleterConstructible<_BadRValRefType<_Dummy> > >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr(pointer __p, _BadRValRefType<_Dummy> __d) = delete;

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr(unique_ptr&& __u) throw()
      : __ptr_(__u.release(), std::__1::forward<deleter_type>(__u.get_deleter())) {
  }

  template <class _Up, class _Ep,
      class = _EnableIfMoveConvertible<unique_ptr<_Up, _Ep>, _Up>,
      class = _EnableIfDeleterConvertible<_Ep>
  >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr(unique_ptr<_Up, _Ep>&& __u) throw()
      : __ptr_(__u.release(), std::__1::forward<_Ep>(__u.get_deleter())) {}


  template <class _Up>
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr(auto_ptr<_Up>&& __p,
             typename enable_if<is_convertible<_Up*, _Tp*>::value &&
                                    is_same<_Dp, default_delete<_Tp> >::value,
                                __nat>::type = __nat()) throw()
      : __ptr_(__p.release(), __default_init_tag()) {}


  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr& operator=(unique_ptr&& __u) throw() {
    reset(__u.release());
    __ptr_.second() = std::__1::forward<deleter_type>(__u.get_deleter());
    return *this;
  }

  template <class _Up, class _Ep,
      class = _EnableIfMoveConvertible<unique_ptr<_Up, _Ep>, _Up>,
      class = _EnableIfDeleterAssignable<_Ep>
  >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr& operator=(unique_ptr<_Up, _Ep>&& __u) throw() {
    reset(__u.release());
    __ptr_.second() = std::__1::forward<_Ep>(__u.get_deleter());
    return *this;
  }


  template <class _Up>
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
      typename enable_if<is_convertible<_Up*, _Tp*>::value &&
                             is_same<_Dp, default_delete<_Tp> >::value,
                         unique_ptr&>::type
      operator=(auto_ptr<_Up> __p) {
    reset(__p.release());
    return *this;
  }



  unique_ptr(unique_ptr const&) = delete;
  unique_ptr& operator=(unique_ptr const&) = delete;



  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  ~unique_ptr() { reset(); }

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr& operator=(nullptr_t) throw() {
    reset();
    return *this;
  }

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  typename add_lvalue_reference<_Tp>::type
  operator*() const {
    return *__ptr_.first();
  }
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  pointer operator->() const throw() {
    return __ptr_.first();
  }
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  pointer get() const throw() {
    return __ptr_.first();
  }
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  deleter_type& get_deleter() throw() {
    return __ptr_.second();
  }
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  const deleter_type& get_deleter() const throw() {
    return __ptr_.second();
  }
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
                   operator bool() const throw() {
    return __ptr_.first() != std::__1::__get_nullptr_t();
  }

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  pointer release() throw() {
    pointer __t = __ptr_.first();
    __ptr_.first() = pointer();
    return __t;
  }

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  void reset(pointer __p = pointer()) throw() {
    pointer __tmp = __ptr_.first();
    __ptr_.first() = __p;
    if (__tmp)
      __ptr_.second()(__tmp);
  }

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  void swap(unique_ptr& __u) throw() {
    __ptr_.swap(__u.__ptr_);
  }
};


template <class _Tp, class _Dp>
class __attribute__ ((__type_visibility__("default"))) unique_ptr<_Tp[], _Dp> {
public:
  typedef _Tp element_type;
  typedef _Dp deleter_type;
  typedef typename __pointer_type<_Tp, deleter_type>::type pointer;

private:
  __compressed_pair<pointer, deleter_type> __ptr_;

  template <class _From>
  struct _CheckArrayPointerConversion : is_same<_From, pointer> {};

  template <class _FromElem>
  struct _CheckArrayPointerConversion<_FromElem*>
      : integral_constant<bool,
          is_same<_FromElem*, pointer>::value ||
            (is_same<pointer, element_type*>::value &&
             is_convertible<_FromElem(*)[], element_type(*)[]>::value)
      >
  {};

  typedef __unique_ptr_deleter_sfinae<_Dp> _DeleterSFINAE;

  template <bool _Dummy>
  using _LValRefType =
      typename __dependent_type<_DeleterSFINAE, _Dummy>::__lval_ref_type;

  template <bool _Dummy>
  using _GoodRValRefType =
      typename __dependent_type<_DeleterSFINAE, _Dummy>::__good_rval_ref_type;

  template <bool _Dummy>
  using _BadRValRefType =
      typename __dependent_type<_DeleterSFINAE, _Dummy>::__bad_rval_ref_type;

  template <bool _Dummy, class _Deleter = typename __dependent_type<
                             __identity<deleter_type>, _Dummy>::type>
  using _EnableIfDeleterDefaultConstructible =
      typename enable_if<is_default_constructible<_Deleter>::value &&
                         !is_pointer<_Deleter>::value>::type;

  template <class _ArgType>
  using _EnableIfDeleterConstructible =
      typename enable_if<is_constructible<deleter_type, _ArgType>::value>::type;

  template <class _Pp>
  using _EnableIfPointerConvertible = typename enable_if<
      _CheckArrayPointerConversion<_Pp>::value
  >::type;

  template <class _UPtr, class _Up,
        class _ElemT = typename _UPtr::element_type>
  using _EnableIfMoveConvertible = typename enable_if<
      is_array<_Up>::value &&
      is_same<pointer, element_type*>::value &&
      is_same<typename _UPtr::pointer, _ElemT*>::value &&
      is_convertible<_ElemT(*)[], element_type(*)[]>::value
    >::type;

  template <class _UDel>
  using _EnableIfDeleterConvertible = typename enable_if<
      (is_reference<_Dp>::value && is_same<_Dp, _UDel>::value) ||
      (!is_reference<_Dp>::value && is_convertible<_UDel, _Dp>::value)
    >::type;

  template <class _UDel>
  using _EnableIfDeleterAssignable = typename enable_if<
      is_assignable<_Dp&, _UDel&&>::value
    >::type;

public:
  template <bool _Dummy = true,
            class = _EnableIfDeleterDefaultConstructible<_Dummy> >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
                    unique_ptr() throw() : __ptr_(pointer(), __default_init_tag()) {}

  template <bool _Dummy = true,
            class = _EnableIfDeleterDefaultConstructible<_Dummy> >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
                    unique_ptr(nullptr_t) throw() : __ptr_(pointer(), __default_init_tag()) {}

  template <class _Pp, bool _Dummy = true,
            class = _EnableIfDeleterDefaultConstructible<_Dummy>,
            class = _EnableIfPointerConvertible<_Pp> >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  explicit unique_ptr(_Pp __p) throw()
      : __ptr_(__p, __default_init_tag()) {}

  template <class _Pp, bool _Dummy = true,
            class = _EnableIfDeleterConstructible<_LValRefType<_Dummy> >,
            class = _EnableIfPointerConvertible<_Pp> >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr(_Pp __p, _LValRefType<_Dummy> __d) throw()
      : __ptr_(__p, __d) {}

  template <bool _Dummy = true,
            class = _EnableIfDeleterConstructible<_LValRefType<_Dummy> > >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr(nullptr_t, _LValRefType<_Dummy> __d) throw()
      : __ptr_(std::__1::__get_nullptr_t(), __d) {}

  template <class _Pp, bool _Dummy = true,
            class = _EnableIfDeleterConstructible<_GoodRValRefType<_Dummy> >,
            class = _EnableIfPointerConvertible<_Pp> >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr(_Pp __p, _GoodRValRefType<_Dummy> __d) throw()
      : __ptr_(__p, std::__1::move(__d)) {
    _Static_assert(!is_reference<deleter_type>::value, "rvalue deleter bound to reference");

  }

  template <bool _Dummy = true,
            class = _EnableIfDeleterConstructible<_GoodRValRefType<_Dummy> > >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr(nullptr_t, _GoodRValRefType<_Dummy> __d) throw()
      : __ptr_(std::__1::__get_nullptr_t(), std::__1::move(__d)) {
    _Static_assert(!is_reference<deleter_type>::value, "rvalue deleter bound to reference");

  }

  template <class _Pp, bool _Dummy = true,
            class = _EnableIfDeleterConstructible<_BadRValRefType<_Dummy> >,
            class = _EnableIfPointerConvertible<_Pp> >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr(_Pp __p, _BadRValRefType<_Dummy> __d) = delete;

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr(unique_ptr&& __u) throw()
      : __ptr_(__u.release(), std::__1::forward<deleter_type>(__u.get_deleter())) {
  }

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr& operator=(unique_ptr&& __u) throw() {
    reset(__u.release());
    __ptr_.second() = std::__1::forward<deleter_type>(__u.get_deleter());
    return *this;
  }

  template <class _Up, class _Ep,
      class = _EnableIfMoveConvertible<unique_ptr<_Up, _Ep>, _Up>,
      class = _EnableIfDeleterConvertible<_Ep>
  >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr(unique_ptr<_Up, _Ep>&& __u) throw()
      : __ptr_(__u.release(), std::__1::forward<_Ep>(__u.get_deleter())) {
  }

  template <class _Up, class _Ep,
      class = _EnableIfMoveConvertible<unique_ptr<_Up, _Ep>, _Up>,
      class = _EnableIfDeleterAssignable<_Ep>
  >
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr&
  operator=(unique_ptr<_Up, _Ep>&& __u) throw() {
    reset(__u.release());
    __ptr_.second() = std::__1::forward<_Ep>(__u.get_deleter());
    return *this;
  }


  unique_ptr(unique_ptr const&) = delete;
  unique_ptr& operator=(unique_ptr const&) = delete;


public:
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  ~unique_ptr() { reset(); }

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  unique_ptr& operator=(nullptr_t) throw() {
    reset();
    return *this;
  }

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  typename add_lvalue_reference<_Tp>::type
  operator[](size_t __i) const {
    return __ptr_.first()[__i];
  }
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  pointer get() const throw() {
    return __ptr_.first();
  }

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  deleter_type& get_deleter() throw() {
    return __ptr_.second();
  }

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  const deleter_type& get_deleter() const throw() {
    return __ptr_.second();
  }
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
                   operator bool() const throw() {
    return __ptr_.first() != std::__1::__get_nullptr_t();
  }

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  pointer release() throw() {
    pointer __t = __ptr_.first();
    __ptr_.first() = pointer();
    return __t;
  }

  template <class _Pp>
  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  typename enable_if<
      _CheckArrayPointerConversion<_Pp>::value
  >::type
  reset(_Pp __p) throw() {
    pointer __tmp = __ptr_.first();
    __ptr_.first() = __p;
    if (__tmp)
      __ptr_.second()(__tmp);
  }

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  void reset(nullptr_t = std::__1::__get_nullptr_t()) throw() {
    pointer __tmp = __ptr_.first();
    __ptr_.first() = std::__1::__get_nullptr_t();
    if (__tmp)
      __ptr_.second()(__tmp);
  }

  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
  void swap(unique_ptr& __u) throw() {
    __ptr_.swap(__u.__ptr_);
  }

};

template <class _Tp, class _Dp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if<
    __is_swappable<_Dp>::value,
    void
>::type
swap(unique_ptr<_Tp, _Dp>& __x, unique_ptr<_Tp, _Dp>& __y) throw() {__x.swap(__y);}

template <class _T1, class _D1, class _T2, class _D2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator==(const unique_ptr<_T1, _D1>& __x, const unique_ptr<_T2, _D2>& __y) {return __x.get() == __y.get();}

template <class _T1, class _D1, class _T2, class _D2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(const unique_ptr<_T1, _D1>& __x, const unique_ptr<_T2, _D2>& __y) {return !(__x == __y);}

template <class _T1, class _D1, class _T2, class _D2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator< (const unique_ptr<_T1, _D1>& __x, const unique_ptr<_T2, _D2>& __y)
{
    typedef typename unique_ptr<_T1, _D1>::pointer _P1;
    typedef typename unique_ptr<_T2, _D2>::pointer _P2;
    typedef typename common_type<_P1, _P2>::type _Vp;
    return less<_Vp>()(__x.get(), __y.get());
}

template <class _T1, class _D1, class _T2, class _D2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator> (const unique_ptr<_T1, _D1>& __x, const unique_ptr<_T2, _D2>& __y) {return __y < __x;}

template <class _T1, class _D1, class _T2, class _D2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<=(const unique_ptr<_T1, _D1>& __x, const unique_ptr<_T2, _D2>& __y) {return !(__y < __x);}

template <class _T1, class _D1, class _T2, class _D2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>=(const unique_ptr<_T1, _D1>& __x, const unique_ptr<_T2, _D2>& __y) {return !(__x < __y);}

template <class _T1, class _D1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator==(const unique_ptr<_T1, _D1>& __x, nullptr_t) throw()
{
    return !__x;
}

template <class _T1, class _D1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator==(nullptr_t, const unique_ptr<_T1, _D1>& __x) throw()
{
    return !__x;
}

template <class _T1, class _D1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(const unique_ptr<_T1, _D1>& __x, nullptr_t) throw()
{
    return static_cast<bool>(__x);
}

template <class _T1, class _D1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(nullptr_t, const unique_ptr<_T1, _D1>& __x) throw()
{
    return static_cast<bool>(__x);
}

template <class _T1, class _D1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<(const unique_ptr<_T1, _D1>& __x, nullptr_t)
{
    typedef typename unique_ptr<_T1, _D1>::pointer _P1;
    return less<_P1>()(__x.get(), std::__1::__get_nullptr_t());
}

template <class _T1, class _D1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<(nullptr_t, const unique_ptr<_T1, _D1>& __x)
{
    typedef typename unique_ptr<_T1, _D1>::pointer _P1;
    return less<_P1>()(std::__1::__get_nullptr_t(), __x.get());
}

template <class _T1, class _D1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>(const unique_ptr<_T1, _D1>& __x, nullptr_t)
{
    return std::__1::__get_nullptr_t() < __x;
}

template <class _T1, class _D1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>(nullptr_t, const unique_ptr<_T1, _D1>& __x)
{
    return __x < std::__1::__get_nullptr_t();
}

template <class _T1, class _D1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<=(const unique_ptr<_T1, _D1>& __x, nullptr_t)
{
    return !(std::__1::__get_nullptr_t() < __x);
}

template <class _T1, class _D1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<=(nullptr_t, const unique_ptr<_T1, _D1>& __x)
{
    return !(__x < std::__1::__get_nullptr_t());
}

template <class _T1, class _D1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>=(const unique_ptr<_T1, _D1>& __x, nullptr_t)
{
    return !(__x < std::__1::__get_nullptr_t());
}

template <class _T1, class _D1>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>=(nullptr_t, const unique_ptr<_T1, _D1>& __x)
{
    return !(std::__1::__get_nullptr_t() < __x);
}

template <class _Tp, class _Dp>

struct __attribute__ ((__type_visibility__("default"))) hash<unique_ptr<_Tp, _Dp> >




{
    typedef unique_ptr<_Tp, _Dp> argument_type;
    typedef size_t result_type;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    result_type operator()(const argument_type& __ptr) const
    {
        typedef typename argument_type::pointer pointer;
        return hash<pointer>()(__ptr.get());
    }
};

struct __destruct_n
{
private:
    size_t __size_;

    template <class _Tp>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void __process(_Tp* __p, false_type) throw()
        {for (size_t __i = 0; __i < __size_; ++__i, ++__p) __p->~_Tp();}

    template <class _Tp>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void __process(_Tp*, true_type) throw()
        {}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void __incr(false_type) throw()
        {++__size_;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void __incr(true_type) throw()
        {}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void __set(size_t __s, false_type) throw()
        {__size_ = __s;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void __set(size_t, true_type) throw()
        {}
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit __destruct_n(size_t __s) throw()
        : __size_(__s) {}

    template <class _Tp>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void __incr(_Tp*) throw()
        {__incr(integral_constant<bool, is_trivially_destructible<_Tp>::value>());}

    template <class _Tp>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void __set(size_t __s, _Tp*) throw()
        {__set(__s, integral_constant<bool, is_trivially_destructible<_Tp>::value>());}

    template <class _Tp>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void operator()(_Tp* __p) throw()
        {__process(__p, integral_constant<bool, is_trivially_destructible<_Tp>::value>());}
};

template <class _Alloc>
class __allocator_destructor
{
    typedef allocator_traits<_Alloc> __alloc_traits;
public:
    typedef typename __alloc_traits::pointer pointer;
    typedef typename __alloc_traits::size_type size_type;
private:
    _Alloc& __alloc_;
    size_type __s_;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __allocator_destructor(_Alloc& __a, size_type __s)
             throw()
        : __alloc_(__a), __s_(__s) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void operator()(pointer __p) throw()
        {__alloc_traits::deallocate(__alloc_, __p, __s_);}
};

template <class _InputIterator, class _ForwardIterator>
_ForwardIterator
uninitialized_copy(_InputIterator __f, _InputIterator __l, _ForwardIterator __r)
{
    typedef typename iterator_traits<_ForwardIterator>::value_type value_type;

    _ForwardIterator __s = __r;
    try
    {

        for (; __f != __l; ++__f, (void) ++__r)
            ::new (static_cast<void*>(std::__1::addressof(*__r))) value_type(*__f);

    }
    catch (...)
    {
        for (; __s != __r; ++__s)
            __s->~value_type();
        throw;
    }

    return __r;
}

template <class _InputIterator, class _Size, class _ForwardIterator>
_ForwardIterator
uninitialized_copy_n(_InputIterator __f, _Size __n, _ForwardIterator __r)
{
    typedef typename iterator_traits<_ForwardIterator>::value_type value_type;

    _ForwardIterator __s = __r;
    try
    {

        for (; __n > 0; ++__f, (void) ++__r, (void) --__n)
            ::new (static_cast<void*>(std::__1::addressof(*__r))) value_type(*__f);

    }
    catch (...)
    {
        for (; __s != __r; ++__s)
            __s->~value_type();
        throw;
    }

    return __r;
}

template <class _ForwardIterator, class _Tp>
void
uninitialized_fill(_ForwardIterator __f, _ForwardIterator __l, const _Tp& __x)
{
    typedef typename iterator_traits<_ForwardIterator>::value_type value_type;

    _ForwardIterator __s = __f;
    try
    {

        for (; __f != __l; ++__f)
            ::new (static_cast<void*>(std::__1::addressof(*__f))) value_type(__x);

    }
    catch (...)
    {
        for (; __s != __f; ++__s)
            __s->~value_type();
        throw;
    }

}

template <class _ForwardIterator, class _Size, class _Tp>
_ForwardIterator
uninitialized_fill_n(_ForwardIterator __f, _Size __n, const _Tp& __x)
{
    typedef typename iterator_traits<_ForwardIterator>::value_type value_type;

    _ForwardIterator __s = __f;
    try
    {

        for (; __n > 0; ++__f, (void) --__n)
            ::new (static_cast<void*>(std::__1::addressof(*__f))) value_type(__x);

    }
    catch (...)
    {
        for (; __s != __f; ++__s)
            __s->~value_type();
        throw;
    }

    return __f;
}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) _Tp
__libcpp_atomic_refcount_increment(_Tp& __t) throw()
{

    return __atomic_add_fetch(&__t, 1, 0);



}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) _Tp
__libcpp_atomic_refcount_decrement(_Tp& __t) throw()
{

    return __atomic_add_fetch(&__t, -1, 4);



}

class __attribute__ ((__visibility__("default"))) bad_weak_ptr
    : public std::exception
{
public:
    virtual ~bad_weak_ptr() throw();
    virtual const char* what() const throw();
};

__attribute__ ((noreturn)) inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __throw_bad_weak_ptr()
{

    throw bad_weak_ptr();



}

template<class _Tp> class __attribute__ ((__type_visibility__("default"))) weak_ptr;

class __attribute__ ((__visibility__("default"))) __shared_count
{
    __shared_count(const __shared_count&);
    __shared_count& operator=(const __shared_count&);

protected:
    long __shared_owners_;
    virtual ~__shared_count();
private:
    virtual void __on_zero_shared() throw() = 0;

public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    explicit __shared_count(long __refs = 0) throw()
        : __shared_owners_(__refs) {}






    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void __add_shared() throw() {
      __libcpp_atomic_refcount_increment(__shared_owners_);
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool __release_shared() throw() {
      if (__libcpp_atomic_refcount_decrement(__shared_owners_) == -1) {
        __on_zero_shared();
        return true;
      }
      return false;
    }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    long use_count() const throw() {
        return __libcpp_relaxed_load(&__shared_owners_) + 1;
    }
};

class __attribute__ ((__visibility__("default"))) __shared_weak_count
    : private __shared_count
{
    long __shared_weak_owners_;

public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    explicit __shared_weak_count(long __refs = 0) throw()
        : __shared_count(__refs),
          __shared_weak_owners_(__refs) {}
protected:
    virtual ~__shared_weak_count();

public:






    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void __add_shared() throw() {
      __shared_count::__add_shared();
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void __add_weak() throw() {
      __libcpp_atomic_refcount_increment(__shared_weak_owners_);
    }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void __release_shared() throw() {
      if (__shared_count::__release_shared())
        __release_weak();
    }

    void __release_weak() throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    long use_count() const throw() {return __shared_count::use_count();}
    __shared_weak_count* lock() throw();






    virtual const void* __get_deleter(const type_info&) const throw();

private:
    virtual void __on_zero_shared_weak() throw() = 0;
};

template <class _Tp, class _Dp, class _Alloc>
class __shared_ptr_pointer
    : public __shared_weak_count
{
    __compressed_pair<__compressed_pair<_Tp, _Dp>, _Alloc> __data_;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    __shared_ptr_pointer(_Tp __p, _Dp __d, _Alloc __a)
        : __data_(__compressed_pair<_Tp, _Dp>(__p, std::__1::move(__d)), std::__1::move(__a)) {}


    virtual const void* __get_deleter(const type_info&) const throw();


private:
    virtual void __on_zero_shared() throw();
    virtual void __on_zero_shared_weak() throw();
};



template <class _Tp, class _Dp, class _Alloc>
const void*
__shared_ptr_pointer<_Tp, _Dp, _Alloc>::__get_deleter(const type_info& __t) const throw()
{
    return __t == typeid(_Dp) ? std::__1::addressof(__data_.first().second()) : std::__1::__get_nullptr_t();
}



template <class _Tp, class _Dp, class _Alloc>
void
__shared_ptr_pointer<_Tp, _Dp, _Alloc>::__on_zero_shared() throw()
{
    __data_.first().second()(__data_.first().first());
    __data_.first().second().~_Dp();
}

template <class _Tp, class _Dp, class _Alloc>
void
__shared_ptr_pointer<_Tp, _Dp, _Alloc>::__on_zero_shared_weak() throw()
{
    typedef typename __allocator_traits_rebind<_Alloc, __shared_ptr_pointer>::type _Al;
    typedef allocator_traits<_Al> _ATraits;
    typedef pointer_traits<typename _ATraits::pointer> _PTraits;

    _Al __a(__data_.second());
    __data_.second().~_Alloc();
    __a.deallocate(_PTraits::pointer_to(*this), 1);
}

template <class _Tp, class _Alloc>
class __shared_ptr_emplace
    : public __shared_weak_count
{
    __compressed_pair<_Alloc, _Tp> __data_;
public:

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    __shared_ptr_emplace(_Alloc __a)
        : __data_(std::__1::move(__a), __value_init_tag()) {}

    template <class _A0>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        __shared_ptr_emplace(_Alloc __a, _A0& __a0)
            : __data_(__a, _Tp(__a0)) {}

    template <class _A0, class _A1>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        __shared_ptr_emplace(_Alloc __a, _A0& __a0, _A1& __a1)
            : __data_(__a, _Tp(__a0, __a1)) {}

    template <class _A0, class _A1, class _A2>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        __shared_ptr_emplace(_Alloc __a, _A0& __a0, _A1& __a1, _A2& __a2)
            : __data_(__a, _Tp(__a0, __a1, __a2)) {}



private:
    virtual void __on_zero_shared() throw();
    virtual void __on_zero_shared_weak() throw();
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp* get() throw() {return std::__1::addressof(__data_.second());}
};

template <class _Tp, class _Alloc>
void
__shared_ptr_emplace<_Tp, _Alloc>::__on_zero_shared() throw()
{
    __data_.second().~_Tp();
}

template <class _Tp, class _Alloc>
void
__shared_ptr_emplace<_Tp, _Alloc>::__on_zero_shared_weak() throw()
{
    typedef typename __allocator_traits_rebind<_Alloc, __shared_ptr_emplace>::type _Al;
    typedef allocator_traits<_Al> _ATraits;
    typedef pointer_traits<typename _ATraits::pointer> _PTraits;
    _Al __a(__data_.first());
    __data_.first().~_Alloc();
    __a.deallocate(_PTraits::pointer_to(*this), 1);
}

struct __shared_ptr_dummy_rebind_allocator_type;
template <>
class __attribute__ ((__type_visibility__("default"))) allocator<__shared_ptr_dummy_rebind_allocator_type>
{
public:
    template <class _Other>
    struct rebind
    {
        typedef allocator<_Other> other;
    };
};

template<class _Tp> class __attribute__ ((__type_visibility__("default"))) enable_shared_from_this;

template<class _Tp>
class __attribute__ ((__type_visibility__("default"))) shared_ptr
{
public:
    typedef _Tp element_type;




private:
    element_type* __ptr_;
    __shared_weak_count* __cntrl_;

    struct __nat {int __for_bool_;};
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
                      shared_ptr() throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
                      shared_ptr(nullptr_t) throw();
    template<class _Yp>
        explicit shared_ptr(_Yp* __p,
                            typename enable_if<is_convertible<_Yp*, element_type*>::value, __nat>::type = __nat());
    template<class _Yp, class _Dp>
        shared_ptr(_Yp* __p, _Dp __d,
                   typename enable_if<is_convertible<_Yp*, element_type*>::value, __nat>::type = __nat());
    template<class _Yp, class _Dp, class _Alloc>
        shared_ptr(_Yp* __p, _Dp __d, _Alloc __a,
                   typename enable_if<is_convertible<_Yp*, element_type*>::value, __nat>::type = __nat());
    template <class _Dp> shared_ptr(nullptr_t __p, _Dp __d);
    template <class _Dp, class _Alloc> shared_ptr(nullptr_t __p, _Dp __d, _Alloc __a);
    template<class _Yp> __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) shared_ptr(const shared_ptr<_Yp>& __r, element_type* __p) throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    shared_ptr(const shared_ptr& __r) throw();
    template<class _Yp>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        shared_ptr(const shared_ptr<_Yp>& __r,
                   typename enable_if<is_convertible<_Yp*, element_type*>::value, __nat>::type = __nat())
                       throw();







    template<class _Yp> explicit shared_ptr(const weak_ptr<_Yp>& __r,
                   typename enable_if<is_convertible<_Yp*, element_type*>::value, __nat>::type= __nat());






    template<class _Yp>
        shared_ptr(auto_ptr<_Yp> __r,
                   typename enable_if<is_convertible<_Yp*, element_type*>::value, __nat>::type = __nat());

    template <class _Yp, class _Dp>
        shared_ptr(unique_ptr<_Yp, _Dp>,
                   typename enable_if
                   <
                       !is_lvalue_reference<_Dp>::value &&
                       !is_array<_Yp>::value &&
                       is_convertible<typename unique_ptr<_Yp, _Dp>::pointer, element_type*>::value,
                       __nat
                   >::type = __nat());
    template <class _Yp, class _Dp>
        shared_ptr(unique_ptr<_Yp, _Dp>,
                   typename enable_if
                   <
                       is_lvalue_reference<_Dp>::value &&
                       !is_array<_Yp>::value &&
                       is_convertible<typename unique_ptr<_Yp, _Dp>::pointer, element_type*>::value,
                       __nat
                   >::type = __nat());


    ~shared_ptr();

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    shared_ptr& operator=(const shared_ptr& __r) throw();
    template<class _Yp>
        typename enable_if
        <
            is_convertible<_Yp*, element_type*>::value,
            shared_ptr&
        >::type
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        operator=(const shared_ptr<_Yp>& __r) throw();

    template<class _Yp>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        typename enable_if
        <
            !is_array<_Yp>::value &&
            is_convertible<_Yp*, element_type*>::value,
            shared_ptr&
        >::type
        operator=(auto_ptr<_Yp> __r);


    template <class _Yp, class _Dp>
        typename enable_if
        <
            !is_array<_Yp>::value &&
            is_convertible<typename unique_ptr<_Yp, _Dp>::pointer, element_type*>::value,
            shared_ptr&
        >::type




        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        operator=(unique_ptr<_Yp, _Dp> __r);


    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void swap(shared_ptr& __r) throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void reset() throw();
    template<class _Yp>
        typename enable_if
        <
            is_convertible<_Yp*, element_type*>::value,
            void
        >::type
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        reset(_Yp* __p);
    template<class _Yp, class _Dp>
        typename enable_if
        <
            is_convertible<_Yp*, element_type*>::value,
            void
        >::type
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        reset(_Yp* __p, _Dp __d);
    template<class _Yp, class _Dp, class _Alloc>
        typename enable_if
        <
            is_convertible<_Yp*, element_type*>::value,
            void
        >::type
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        reset(_Yp* __p, _Dp __d, _Alloc __a);

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    element_type* get() const throw() {return __ptr_;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename add_lvalue_reference<element_type>::type operator*() const throw()
        {return *__ptr_;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    element_type* operator->() const throw() {return __ptr_;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    long use_count() const throw() {return __cntrl_ ? __cntrl_->use_count() : 0;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool unique() const throw() {return use_count() == 1;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
                     operator bool() const throw() {return get() != 0;}
    template <class _Up>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        bool owner_before(shared_ptr<_Up> const& __p) const throw()
        {return __cntrl_ < __p.__cntrl_;}
    template <class _Up>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        bool owner_before(weak_ptr<_Up> const& __p) const throw()
        {return __cntrl_ < __p.__cntrl_;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool
    __owner_equivalent(const shared_ptr& __p) const
        {return __cntrl_ == __p.__cntrl_;}


    template <class _Dp>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        _Dp* __get_deleter() const throw()
            {return static_cast<_Dp*>(__cntrl_
                    ? const_cast<void *>(__cntrl_->__get_deleter(typeid(_Dp)))
                      : std::__1::__get_nullptr_t());}


    template<class _Yp, class _CntrlBlk>
    static shared_ptr<_Tp>
    __create_with_control_block(_Yp* __p, _CntrlBlk* __cntrl)
    {
        shared_ptr<_Tp> __r;
        __r.__ptr_ = __p;
        __r.__cntrl_ = __cntrl;
        __r.__enable_weak_this(__r.__ptr_, __r.__ptr_);
        return __r;
    }

    template<class _Alloc, class ..._Args>
        static
        shared_ptr<_Tp>
        allocate_shared(const _Alloc& __a, _Args&& ...__args);

private:
    template <class _Yp, bool = is_function<_Yp>::value>
        struct __shared_ptr_default_allocator
        {
            typedef allocator<_Yp> type;
        };

    template <class _Yp>
        struct __shared_ptr_default_allocator<_Yp, true>
        {
            typedef allocator<__shared_ptr_dummy_rebind_allocator_type> type;
        };

    template <class _Yp, class _OrigPtr>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        typename enable_if<is_convertible<_OrigPtr*,
                                          const enable_shared_from_this<_Yp>*
        >::value,
            void>::type
        __enable_weak_this(const enable_shared_from_this<_Yp>* __e,
                           _OrigPtr* __ptr) throw()
        {
            typedef typename remove_cv<_Yp>::type _RawYp;
            if (__e && __e->__weak_this_.expired())
            {
                __e->__weak_this_ = shared_ptr<_RawYp>(*this,
                    const_cast<_RawYp*>(static_cast<const _Yp*>(__ptr)));
            }
        }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void __enable_weak_this(...) throw() {}

    template <class _Up> friend class __attribute__ ((__type_visibility__("default"))) shared_ptr;
    template <class _Up> friend class __attribute__ ((__type_visibility__("default"))) weak_ptr;
};


template<class _Tp>
inline

shared_ptr<_Tp>::shared_ptr() throw()
    : __ptr_(0),
      __cntrl_(0)
{
}

template<class _Tp>
inline

shared_ptr<_Tp>::shared_ptr(nullptr_t) throw()
    : __ptr_(0),
      __cntrl_(0)
{
}

template<class _Tp>
template<class _Yp>
shared_ptr<_Tp>::shared_ptr(_Yp* __p,
                            typename enable_if<is_convertible<_Yp*, element_type*>::value, __nat>::type)
    : __ptr_(__p)
{
    unique_ptr<_Yp> __hold(__p);
    typedef typename __shared_ptr_default_allocator<_Yp>::type _AllocT;
    typedef __shared_ptr_pointer<_Yp*, default_delete<_Yp>, _AllocT > _CntrlBlk;
    __cntrl_ = new _CntrlBlk(__p, default_delete<_Yp>(), _AllocT());
    __hold.release();
    __enable_weak_this(__p, __p);
}

template<class _Tp>
template<class _Yp, class _Dp>
shared_ptr<_Tp>::shared_ptr(_Yp* __p, _Dp __d,
                            typename enable_if<is_convertible<_Yp*, element_type*>::value, __nat>::type)
    : __ptr_(__p)
{

    try
    {

        typedef typename __shared_ptr_default_allocator<_Yp>::type _AllocT;
        typedef __shared_ptr_pointer<_Yp*, _Dp, _AllocT > _CntrlBlk;
        __cntrl_ = new _CntrlBlk(__p, __d, _AllocT());
        __enable_weak_this(__p, __p);

    }
    catch (...)
    {
        __d(__p);
        throw;
    }

}

template<class _Tp>
template<class _Dp>
shared_ptr<_Tp>::shared_ptr(nullptr_t __p, _Dp __d)
    : __ptr_(0)
{

    try
    {

        typedef typename __shared_ptr_default_allocator<_Tp>::type _AllocT;
        typedef __shared_ptr_pointer<nullptr_t, _Dp, _AllocT > _CntrlBlk;
        __cntrl_ = new _CntrlBlk(__p, __d, _AllocT());

    }
    catch (...)
    {
        __d(__p);
        throw;
    }

}

template<class _Tp>
template<class _Yp, class _Dp, class _Alloc>
shared_ptr<_Tp>::shared_ptr(_Yp* __p, _Dp __d, _Alloc __a,
                            typename enable_if<is_convertible<_Yp*, element_type*>::value, __nat>::type)
    : __ptr_(__p)
{

    try
    {

        typedef __shared_ptr_pointer<_Yp*, _Dp, _Alloc> _CntrlBlk;
        typedef typename __allocator_traits_rebind<_Alloc, _CntrlBlk>::type _A2;
        typedef __allocator_destructor<_A2> _D2;
        _A2 __a2(__a);
        unique_ptr<_CntrlBlk, _D2> __hold2(__a2.allocate(1), _D2(__a2, 1));
        ::new(static_cast<void*>(std::__1::addressof(*__hold2.get())))
            _CntrlBlk(__p, __d, __a);
        __cntrl_ = std::__1::addressof(*__hold2.release());
        __enable_weak_this(__p, __p);

    }
    catch (...)
    {
        __d(__p);
        throw;
    }

}

template<class _Tp>
template<class _Dp, class _Alloc>
shared_ptr<_Tp>::shared_ptr(nullptr_t __p, _Dp __d, _Alloc __a)
    : __ptr_(0)
{

    try
    {

        typedef __shared_ptr_pointer<nullptr_t, _Dp, _Alloc> _CntrlBlk;
        typedef typename __allocator_traits_rebind<_Alloc, _CntrlBlk>::type _A2;
        typedef __allocator_destructor<_A2> _D2;
        _A2 __a2(__a);
        unique_ptr<_CntrlBlk, _D2> __hold2(__a2.allocate(1), _D2(__a2, 1));
        ::new(static_cast<void*>(std::__1::addressof(*__hold2.get())))
            _CntrlBlk(__p, __d, __a);
        __cntrl_ = std::__1::addressof(*__hold2.release());

    }
    catch (...)
    {
        __d(__p);
        throw;
    }

}

template<class _Tp>
template<class _Yp>
inline
shared_ptr<_Tp>::shared_ptr(const shared_ptr<_Yp>& __r, element_type *__p) throw()
    : __ptr_(__p),
      __cntrl_(__r.__cntrl_)
{
    if (__cntrl_)
        __cntrl_->__add_shared();
}

template<class _Tp>
inline
shared_ptr<_Tp>::shared_ptr(const shared_ptr& __r) throw()
    : __ptr_(__r.__ptr_),
      __cntrl_(__r.__cntrl_)
{
    if (__cntrl_)
        __cntrl_->__add_shared();
}

template<class _Tp>
template<class _Yp>
inline
shared_ptr<_Tp>::shared_ptr(const shared_ptr<_Yp>& __r,
                            typename enable_if<is_convertible<_Yp*, element_type*>::value, __nat>::type)
         throw()
    : __ptr_(__r.__ptr_),
      __cntrl_(__r.__cntrl_)
{
    if (__cntrl_)
        __cntrl_->__add_shared();
}

template<class _Tp>
template<class _Yp>



shared_ptr<_Tp>::shared_ptr(auto_ptr<_Yp> __r,

                            typename enable_if<is_convertible<_Yp*, element_type*>::value, __nat>::type)
    : __ptr_(__r.get())
{
    typedef __shared_ptr_pointer<_Yp*, default_delete<_Yp>, allocator<_Yp> > _CntrlBlk;
    __cntrl_ = new _CntrlBlk(__r.get(), default_delete<_Yp>(), allocator<_Yp>());
    __enable_weak_this(__r.get(), __r.get());
    __r.release();
}


template<class _Tp>
template <class _Yp, class _Dp>



shared_ptr<_Tp>::shared_ptr(unique_ptr<_Yp, _Dp> __r,

                            typename enable_if
                            <
                                !is_lvalue_reference<_Dp>::value &&
                                !is_array<_Yp>::value &&
                                is_convertible<typename unique_ptr<_Yp, _Dp>::pointer, element_type*>::value,
                                __nat
                            >::type)
    : __ptr_(__r.get())
{





    {
        typedef typename __shared_ptr_default_allocator<_Yp>::type _AllocT;
        typedef __shared_ptr_pointer<_Yp*, _Dp, _AllocT > _CntrlBlk;
        __cntrl_ = new _CntrlBlk(__r.get(), __r.get_deleter(), _AllocT());
        __enable_weak_this(__r.get(), __r.get());
    }
    __r.release();
}

template<class _Tp>
template <class _Yp, class _Dp>



shared_ptr<_Tp>::shared_ptr(unique_ptr<_Yp, _Dp> __r,

                            typename enable_if
                            <
                                is_lvalue_reference<_Dp>::value &&
                                !is_array<_Yp>::value &&
                                is_convertible<typename unique_ptr<_Yp, _Dp>::pointer, element_type*>::value,
                                __nat
                            >::type)
    : __ptr_(__r.get())
{





    {
        typedef typename __shared_ptr_default_allocator<_Yp>::type _AllocT;
        typedef __shared_ptr_pointer<_Yp*,
                                     reference_wrapper<typename remove_reference<_Dp>::type>,
                                     _AllocT > _CntrlBlk;
        __cntrl_ = new _CntrlBlk(__r.get(), ref(__r.get_deleter()), _AllocT());
        __enable_weak_this(__r.get(), __r.get());
    }
    __r.release();
}

template<class _Tp>
template<class _Alloc, class ..._Args>
shared_ptr<_Tp>
shared_ptr<_Tp>::allocate_shared(const _Alloc& __a, _Args&& ...__args)
{
    _Static_assert(is_constructible<_Tp, _Args...>::value, "Can't construct object in allocate_shared");
    typedef __shared_ptr_emplace<_Tp, _Alloc> _CntrlBlk;
    typedef typename __allocator_traits_rebind<_Alloc, _CntrlBlk>::type _A2;
    typedef __allocator_destructor<_A2> _D2;
    _A2 __a2(__a);
    unique_ptr<_CntrlBlk, _D2> __hold2(__a2.allocate(1), _D2(__a2, 1));
    ::new(static_cast<void*>(std::__1::addressof(*__hold2.get())))
        _CntrlBlk(__a, std::__1::forward<_Args>(__args)...);
    shared_ptr<_Tp> __r;
    __r.__ptr_ = __hold2.get()->get();
    __r.__cntrl_ = std::__1::addressof(*__hold2.release());
    __r.__enable_weak_this(__r.__ptr_, __r.__ptr_);
    return __r;
}

template<class _Tp>
shared_ptr<_Tp>::~shared_ptr()
{
    if (__cntrl_)
        __cntrl_->__release_shared();
}

template<class _Tp>
inline
shared_ptr<_Tp>&
shared_ptr<_Tp>::operator=(const shared_ptr& __r) throw()
{
    shared_ptr(__r).swap(*this);
    return *this;
}

template<class _Tp>
template<class _Yp>
inline
typename enable_if
<
    is_convertible<_Yp*, typename shared_ptr<_Tp>::element_type*>::value,
    shared_ptr<_Tp>&
>::type
shared_ptr<_Tp>::operator=(const shared_ptr<_Yp>& __r) throw()
{
    shared_ptr(__r).swap(*this);
    return *this;
}

template<class _Tp>
template<class _Yp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    !is_array<_Yp>::value &&
    is_convertible<_Yp*, typename shared_ptr<_Tp>::element_type*>::value,
    shared_ptr<_Tp>&
>::type
shared_ptr<_Tp>::operator=(auto_ptr<_Yp> __r)
{
    shared_ptr(__r).swap(*this);
    return *this;
}


template<class _Tp>
template <class _Yp, class _Dp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    !is_array<_Yp>::value &&
    is_convertible<typename unique_ptr<_Yp, _Dp>::pointer,
                   typename shared_ptr<_Tp>::element_type*>::value,
    shared_ptr<_Tp>&
>::type
shared_ptr<_Tp>::operator=(unique_ptr<_Yp, _Dp> __r)
{
    shared_ptr(std::__1::move(__r)).swap(*this);
    return *this;
}



template<class _Tp>
inline
void
shared_ptr<_Tp>::swap(shared_ptr& __r) throw()
{
    std::__1::swap(__ptr_, __r.__ptr_);
    std::__1::swap(__cntrl_, __r.__cntrl_);
}

template<class _Tp>
inline
void
shared_ptr<_Tp>::reset() throw()
{
    shared_ptr().swap(*this);
}

template<class _Tp>
template<class _Yp>
inline
typename enable_if
<
    is_convertible<_Yp*, typename shared_ptr<_Tp>::element_type*>::value,
    void
>::type
shared_ptr<_Tp>::reset(_Yp* __p)
{
    shared_ptr(__p).swap(*this);
}

template<class _Tp>
template<class _Yp, class _Dp>
inline
typename enable_if
<
    is_convertible<_Yp*, typename shared_ptr<_Tp>::element_type*>::value,
    void
>::type
shared_ptr<_Tp>::reset(_Yp* __p, _Dp __d)
{
    shared_ptr(__p, __d).swap(*this);
}

template<class _Tp>
template<class _Yp, class _Dp, class _Alloc>
inline
typename enable_if
<
    is_convertible<_Yp*, typename shared_ptr<_Tp>::element_type*>::value,
    void
>::type
shared_ptr<_Tp>::reset(_Yp* __p, _Dp __d, _Alloc __a)
{
    shared_ptr(__p, __d, __a).swap(*this);
}

template<class _Tp, class ..._Args>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    !is_array<_Tp>::value,
    shared_ptr<_Tp>
>::type
make_shared(_Args&& ...__args)
{
    _Static_assert(is_constructible<_Tp, _Args...>::value, "Can't construct object in make_shared");
    typedef __shared_ptr_emplace<_Tp, allocator<_Tp> > _CntrlBlk;
    typedef allocator<_CntrlBlk> _A2;
    typedef __allocator_destructor<_A2> _D2;

    _A2 __a2;
    unique_ptr<_CntrlBlk, _D2> __hold2(__a2.allocate(1), _D2(__a2, 1));
    ::new(__hold2.get()) _CntrlBlk(__a2, std::__1::forward<_Args>(__args)...);

    _Tp *__ptr = __hold2.get()->get();
    return shared_ptr<_Tp>::__create_with_control_block(__ptr, __hold2.release());
}

template<class _Tp, class _Alloc, class ..._Args>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    !is_array<_Tp>::value,
    shared_ptr<_Tp>
>::type
allocate_shared(const _Alloc& __a, _Args&& ...__args)
{
    return shared_ptr<_Tp>::allocate_shared(__a, std::__1::forward<_Args>(__args)...);
}

template<class _Tp, class _Up>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator==(const shared_ptr<_Tp>& __x, const shared_ptr<_Up>& __y) throw()
{
    return __x.get() == __y.get();
}

template<class _Tp, class _Up>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(const shared_ptr<_Tp>& __x, const shared_ptr<_Up>& __y) throw()
{
    return !(__x == __y);
}

template<class _Tp, class _Up>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<(const shared_ptr<_Tp>& __x, const shared_ptr<_Up>& __y) throw()
{

    typedef typename common_type<_Tp*, _Up*>::type _Vp;
    return less<_Vp>()(__x.get(), __y.get());




}

template<class _Tp, class _Up>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>(const shared_ptr<_Tp>& __x, const shared_ptr<_Up>& __y) throw()
{
    return __y < __x;
}

template<class _Tp, class _Up>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<=(const shared_ptr<_Tp>& __x, const shared_ptr<_Up>& __y) throw()
{
    return !(__y < __x);
}

template<class _Tp, class _Up>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>=(const shared_ptr<_Tp>& __x, const shared_ptr<_Up>& __y) throw()
{
    return !(__x < __y);
}

template<class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator==(const shared_ptr<_Tp>& __x, nullptr_t) throw()
{
    return !__x;
}

template<class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator==(nullptr_t, const shared_ptr<_Tp>& __x) throw()
{
    return !__x;
}

template<class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(const shared_ptr<_Tp>& __x, nullptr_t) throw()
{
    return static_cast<bool>(__x);
}

template<class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(nullptr_t, const shared_ptr<_Tp>& __x) throw()
{
    return static_cast<bool>(__x);
}

template<class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<(const shared_ptr<_Tp>& __x, nullptr_t) throw()
{
    return less<_Tp*>()(__x.get(), std::__1::__get_nullptr_t());
}

template<class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<(nullptr_t, const shared_ptr<_Tp>& __x) throw()
{
    return less<_Tp*>()(std::__1::__get_nullptr_t(), __x.get());
}

template<class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>(const shared_ptr<_Tp>& __x, nullptr_t) throw()
{
    return std::__1::__get_nullptr_t() < __x;
}

template<class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>(nullptr_t, const shared_ptr<_Tp>& __x) throw()
{
    return __x < std::__1::__get_nullptr_t();
}

template<class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<=(const shared_ptr<_Tp>& __x, nullptr_t) throw()
{
    return !(std::__1::__get_nullptr_t() < __x);
}

template<class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<=(nullptr_t, const shared_ptr<_Tp>& __x) throw()
{
    return !(__x < std::__1::__get_nullptr_t());
}

template<class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>=(const shared_ptr<_Tp>& __x, nullptr_t) throw()
{
    return !(__x < std::__1::__get_nullptr_t());
}

template<class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>=(nullptr_t, const shared_ptr<_Tp>& __x) throw()
{
    return !(std::__1::__get_nullptr_t() < __x);
}

template<class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
swap(shared_ptr<_Tp>& __x, shared_ptr<_Tp>& __y) throw()
{
    __x.swap(__y);
}

template<class _Tp, class _Up>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    !is_array<_Tp>::value && !is_array<_Up>::value,
    shared_ptr<_Tp>
>::type
static_pointer_cast(const shared_ptr<_Up>& __r) throw()
{
    return shared_ptr<_Tp>(__r, static_cast<_Tp*>(__r.get()));
}

template<class _Tp, class _Up>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    !is_array<_Tp>::value && !is_array<_Up>::value,
    shared_ptr<_Tp>
>::type
dynamic_pointer_cast(const shared_ptr<_Up>& __r) throw()
{
    _Tp* __p = dynamic_cast<_Tp*>(__r.get());
    return __p ? shared_ptr<_Tp>(__r, __p) : shared_ptr<_Tp>();
}

template<class _Tp, class _Up>
typename enable_if
<
    is_array<_Tp>::value == is_array<_Up>::value,
    shared_ptr<_Tp>
>::type
const_pointer_cast(const shared_ptr<_Up>& __r) throw()
{
    typedef typename remove_extent<_Tp>::type _RTp;
    return shared_ptr<_Tp>(__r, const_cast<_RTp*>(__r.get()));
}



template<class _Dp, class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Dp*
get_deleter(const shared_ptr<_Tp>& __p) throw()
{
    return __p.template __get_deleter<_Dp>();
}



template<class _Tp>
class __attribute__ ((__type_visibility__("default"))) weak_ptr
{
public:
    typedef _Tp element_type;
private:
    element_type* __ptr_;
    __shared_weak_count* __cntrl_;

public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
                      weak_ptr() throw();
    template<class _Yp> __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) weak_ptr(shared_ptr<_Yp> const& __r,
                   typename enable_if<is_convertible<_Yp*, _Tp*>::value, __nat*>::type = 0)
                        throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    weak_ptr(weak_ptr const& __r) throw();
    template<class _Yp> __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) weak_ptr(weak_ptr<_Yp> const& __r,
                   typename enable_if<is_convertible<_Yp*, _Tp*>::value, __nat*>::type = 0)
                         throw();

    ~weak_ptr();

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    weak_ptr& operator=(weak_ptr const& __r) throw();
    template<class _Yp>
        typename enable_if
        <
            is_convertible<_Yp*, element_type*>::value,
            weak_ptr&
        >::type
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        operator=(weak_ptr<_Yp> const& __r) throw();

    template<class _Yp>
        typename enable_if
        <
            is_convertible<_Yp*, element_type*>::value,
            weak_ptr&
        >::type
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        operator=(shared_ptr<_Yp> const& __r) throw();

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void swap(weak_ptr& __r) throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void reset() throw();

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    long use_count() const throw()
        {return __cntrl_ ? __cntrl_->use_count() : 0;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool expired() const throw()
        {return __cntrl_ == 0 || __cntrl_->use_count() == 0;}
    shared_ptr<_Tp> lock() const throw();
    template<class _Up>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        bool owner_before(const shared_ptr<_Up>& __r) const throw()
        {return __cntrl_ < __r.__cntrl_;}
    template<class _Up>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        bool owner_before(const weak_ptr<_Up>& __r) const throw()
        {return __cntrl_ < __r.__cntrl_;}

    template <class _Up> friend class __attribute__ ((__type_visibility__("default"))) weak_ptr;
    template <class _Up> friend class __attribute__ ((__type_visibility__("default"))) shared_ptr;
};

template<class _Tp>
inline

weak_ptr<_Tp>::weak_ptr() throw()
    : __ptr_(0),
      __cntrl_(0)
{
}

template<class _Tp>
inline
weak_ptr<_Tp>::weak_ptr(weak_ptr const& __r) throw()
    : __ptr_(__r.__ptr_),
      __cntrl_(__r.__cntrl_)
{
    if (__cntrl_)
        __cntrl_->__add_weak();
}

template<class _Tp>
template<class _Yp>
inline
weak_ptr<_Tp>::weak_ptr(shared_ptr<_Yp> const& __r,
                        typename enable_if<is_convertible<_Yp*, _Tp*>::value, __nat*>::type)
                         throw()
    : __ptr_(__r.__ptr_),
      __cntrl_(__r.__cntrl_)
{
    if (__cntrl_)
        __cntrl_->__add_weak();
}

template<class _Tp>
template<class _Yp>
inline
weak_ptr<_Tp>::weak_ptr(weak_ptr<_Yp> const& __r,
                        typename enable_if<is_convertible<_Yp*, _Tp*>::value, __nat*>::type)
         throw()
    : __ptr_(__r.__ptr_),
      __cntrl_(__r.__cntrl_)
{
    if (__cntrl_)
        __cntrl_->__add_weak();
}

template<class _Tp>
weak_ptr<_Tp>::~weak_ptr()
{
    if (__cntrl_)
        __cntrl_->__release_weak();
}

template<class _Tp>
inline
weak_ptr<_Tp>&
weak_ptr<_Tp>::operator=(weak_ptr const& __r) throw()
{
    weak_ptr(__r).swap(*this);
    return *this;
}

template<class _Tp>
template<class _Yp>
inline
typename enable_if
<
    is_convertible<_Yp*, _Tp*>::value,
    weak_ptr<_Tp>&
>::type
weak_ptr<_Tp>::operator=(weak_ptr<_Yp> const& __r) throw()
{
    weak_ptr(__r).swap(*this);
    return *this;
}

template<class _Tp>
template<class _Yp>
inline
typename enable_if
<
    is_convertible<_Yp*, _Tp*>::value,
    weak_ptr<_Tp>&
>::type
weak_ptr<_Tp>::operator=(shared_ptr<_Yp> const& __r) throw()
{
    weak_ptr(__r).swap(*this);
    return *this;
}

template<class _Tp>
inline
void
weak_ptr<_Tp>::swap(weak_ptr& __r) throw()
{
    std::__1::swap(__ptr_, __r.__ptr_);
    std::__1::swap(__cntrl_, __r.__cntrl_);
}

template<class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
swap(weak_ptr<_Tp>& __x, weak_ptr<_Tp>& __y) throw()
{
    __x.swap(__y);
}

template<class _Tp>
inline
void
weak_ptr<_Tp>::reset() throw()
{
    weak_ptr().swap(*this);
}

template<class _Tp>
template<class _Yp>
shared_ptr<_Tp>::shared_ptr(const weak_ptr<_Yp>& __r,
                            typename enable_if<is_convertible<_Yp*, element_type*>::value, __nat>::type)
    : __ptr_(__r.__ptr_),
      __cntrl_(__r.__cntrl_ ? __r.__cntrl_->lock() : __r.__cntrl_)
{
    if (__cntrl_ == 0)
        __throw_bad_weak_ptr();
}

template<class _Tp>
shared_ptr<_Tp>
weak_ptr<_Tp>::lock() const throw()
{
    shared_ptr<_Tp> __r;
    __r.__cntrl_ = __cntrl_ ? __cntrl_->lock() : __cntrl_;
    if (__r.__cntrl_)
        __r.__ptr_ = __ptr_;
    return __r;
}




template <class _Tp> struct owner_less;


template <class _Tp>
struct __attribute__ ((__type_visibility__("default"))) owner_less<shared_ptr<_Tp> >
    : binary_function<shared_ptr<_Tp>, shared_ptr<_Tp>, bool>
{
    typedef bool result_type;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(shared_ptr<_Tp> const& __x, shared_ptr<_Tp> const& __y) const throw()
        {return __x.owner_before(__y);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(shared_ptr<_Tp> const& __x, weak_ptr<_Tp> const& __y) const throw()
        {return __x.owner_before(__y);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()( weak_ptr<_Tp> const& __x, shared_ptr<_Tp> const& __y) const throw()
        {return __x.owner_before(__y);}
};

template <class _Tp>
struct __attribute__ ((__type_visibility__("default"))) owner_less<weak_ptr<_Tp> >
    : binary_function<weak_ptr<_Tp>, weak_ptr<_Tp>, bool>
{
    typedef bool result_type;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()( weak_ptr<_Tp> const& __x, weak_ptr<_Tp> const& __y) const throw()
        {return __x.owner_before(__y);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(shared_ptr<_Tp> const& __x, weak_ptr<_Tp> const& __y) const throw()
        {return __x.owner_before(__y);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()( weak_ptr<_Tp> const& __x, shared_ptr<_Tp> const& __y) const throw()
        {return __x.owner_before(__y);}
};

template<class _Tp>
class __attribute__ ((__type_visibility__("default"))) enable_shared_from_this
{
    mutable weak_ptr<_Tp> __weak_this_;
protected:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    enable_shared_from_this() throw() {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    enable_shared_from_this(enable_shared_from_this const&) throw() {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    enable_shared_from_this& operator=(enable_shared_from_this const&) throw()
        {return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    ~enable_shared_from_this() {}
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    shared_ptr<_Tp> shared_from_this()
        {return shared_ptr<_Tp>(__weak_this_);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    shared_ptr<_Tp const> shared_from_this() const
        {return shared_ptr<const _Tp>(__weak_this_);}

    template <class _Up> friend class shared_ptr;
};

template <class _Tp>
struct __attribute__ ((__type_visibility__("default"))) hash<shared_ptr<_Tp> >
{
    typedef shared_ptr<_Tp> argument_type;
    typedef size_t result_type;

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    result_type operator()(const argument_type& __ptr) const throw()
    {
        return hash<_Tp*>()(__ptr.get());
    }
};

template<class _CharT, class _Traits, class _Yp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
basic_ostream<_CharT, _Traits>&
operator<<(basic_ostream<_CharT, _Traits>& __os, shared_ptr<_Yp> const& __p);




class __attribute__ ((__visibility__("default"))) __sp_mut
{
    void* __lx;
public:
    void lock() throw();
    void unlock() throw();

private:
                      __sp_mut(void*) throw();
    __sp_mut(const __sp_mut&);
    __sp_mut& operator=(const __sp_mut&);

    friend __attribute__ ((__visibility__("default"))) __sp_mut& __get_sp_mut(const void*);
};

__attribute__ ((__visibility__("default"))) __attribute__((availability(macosx,strict,introduced=10.9))) __attribute__((availability(ios,strict,introduced=7.0)))
__sp_mut& __get_sp_mut(const void*);

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
atomic_is_lock_free(const shared_ptr<_Tp>*)
{
    return false;
}

template <class _Tp>
__attribute__((availability(macosx,strict,introduced=10.9))) __attribute__((availability(ios,strict,introduced=7.0)))
shared_ptr<_Tp>
atomic_load(const shared_ptr<_Tp>* __p)
{
    __sp_mut& __m = __get_sp_mut(__p);
    __m.lock();
    shared_ptr<_Tp> __q = *__p;
    __m.unlock();
    return __q;
}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__attribute__((availability(macosx,strict,introduced=10.9))) __attribute__((availability(ios,strict,introduced=7.0)))
shared_ptr<_Tp>
atomic_load_explicit(const shared_ptr<_Tp>* __p, memory_order)
{
    return atomic_load(__p);
}

template <class _Tp>
__attribute__((availability(macosx,strict,introduced=10.9))) __attribute__((availability(ios,strict,introduced=7.0)))
void
atomic_store(shared_ptr<_Tp>* __p, shared_ptr<_Tp> __r)
{
    __sp_mut& __m = __get_sp_mut(__p);
    __m.lock();
    __p->swap(__r);
    __m.unlock();
}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__attribute__((availability(macosx,strict,introduced=10.9))) __attribute__((availability(ios,strict,introduced=7.0)))
void
atomic_store_explicit(shared_ptr<_Tp>* __p, shared_ptr<_Tp> __r, memory_order)
{
    atomic_store(__p, __r);
}

template <class _Tp>
__attribute__((availability(macosx,strict,introduced=10.9))) __attribute__((availability(ios,strict,introduced=7.0)))
shared_ptr<_Tp>
atomic_exchange(shared_ptr<_Tp>* __p, shared_ptr<_Tp> __r)
{
    __sp_mut& __m = __get_sp_mut(__p);
    __m.lock();
    __p->swap(__r);
    __m.unlock();
    return __r;
}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__attribute__((availability(macosx,strict,introduced=10.9))) __attribute__((availability(ios,strict,introduced=7.0)))
shared_ptr<_Tp>
atomic_exchange_explicit(shared_ptr<_Tp>* __p, shared_ptr<_Tp> __r, memory_order)
{
    return atomic_exchange(__p, __r);
}

template <class _Tp>
__attribute__((availability(macosx,strict,introduced=10.9))) __attribute__((availability(ios,strict,introduced=7.0)))
bool
atomic_compare_exchange_strong(shared_ptr<_Tp>* __p, shared_ptr<_Tp>* __v, shared_ptr<_Tp> __w)
{
    shared_ptr<_Tp> __temp;
    __sp_mut& __m = __get_sp_mut(__p);
    __m.lock();
    if (__p->__owner_equivalent(*__v))
    {
        std::__1::swap(__temp, *__p);
        *__p = __w;
        __m.unlock();
        return true;
    }
    std::__1::swap(__temp, *__v);
    *__v = *__p;
    __m.unlock();
    return false;
}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__attribute__((availability(macosx,strict,introduced=10.9))) __attribute__((availability(ios,strict,introduced=7.0)))
bool
atomic_compare_exchange_weak(shared_ptr<_Tp>* __p, shared_ptr<_Tp>* __v, shared_ptr<_Tp> __w)
{
    return atomic_compare_exchange_strong(__p, __v, __w);
}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__attribute__((availability(macosx,strict,introduced=10.9))) __attribute__((availability(ios,strict,introduced=7.0)))
bool
atomic_compare_exchange_strong_explicit(shared_ptr<_Tp>* __p, shared_ptr<_Tp>* __v,
                                        shared_ptr<_Tp> __w, memory_order, memory_order)
{
    return atomic_compare_exchange_strong(__p, __v, __w);
}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__attribute__((availability(macosx,strict,introduced=10.9))) __attribute__((availability(ios,strict,introduced=7.0)))
bool
atomic_compare_exchange_weak_explicit(shared_ptr<_Tp>* __p, shared_ptr<_Tp>* __v,
                                      shared_ptr<_Tp> __w, memory_order, memory_order)
{
    return atomic_compare_exchange_weak(__p, __v, __w);
}

struct __attribute__ ((__visibility__("default"))) pointer_safety
{
    enum __lx
    {
        relaxed,
        preferred,
        strict
    };

    __lx __v_;

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    pointer_safety() : __v_() {}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    pointer_safety(__lx __v) : __v_(__v) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    operator int() const {return __v_;}
};

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
pointer_safety get_pointer_safety() throw() {
  return pointer_safety::relaxed;
}




__attribute__ ((__visibility__("default"))) void declare_reachable(void* __p);
__attribute__ ((__visibility__("default"))) void declare_no_pointers(char* __p, size_t __n);
__attribute__ ((__visibility__("default"))) void undeclare_no_pointers(char* __p, size_t __n);
__attribute__ ((__visibility__("default"))) void* __undeclare_reachable(void* __p);

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp*
undeclare_reachable(_Tp* __p)
{
    return static_cast<_Tp*>(__undeclare_reachable(__p));
}

__attribute__ ((__visibility__("default"))) void* align(size_t __align, size_t __sz, void*& __ptr, size_t& __space);


template <typename _Alloc>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __swap_allocator(_Alloc & __a1, _Alloc & __a2)





{
    __swap_allocator(__a1, __a2,
      integral_constant<bool, std::__1::allocator_traits<_Alloc>::propagate_on_container_swap::value>());
}

template <typename _Alloc>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __swap_allocator(_Alloc & __a1, _Alloc & __a2, true_type)





{
    using std::__1::swap;
    swap(__a1, __a2);
}

template <typename _Alloc>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __swap_allocator(_Alloc &, _Alloc &, false_type) throw() {}

template <typename _Alloc, typename _Traits=allocator_traits<_Alloc> >
struct __noexcept_move_assign_container : public integral_constant<bool,
    _Traits::propagate_on_container_move_assignment::value



        && is_nothrow_move_assignable<_Alloc>::value

    > {};

template<typename _Alloc, typename = void, typename = void>
struct __is_allocator : false_type {};

template<typename _Alloc>
struct __is_allocator<_Alloc,
       typename __void_t<typename _Alloc::value_type>::type,
       typename __void_t<__decltype(std::__1::declval<_Alloc&>().allocate(size_t(0)))>::type
     >
   : true_type {};





struct __builtin_new_allocator {
  struct __builtin_new_deleter {
    typedef void* pointer_type;

                      explicit __builtin_new_deleter(size_t __size, size_t __align)
        : __size_(__size), __align_(__align) {}

    void operator()(void* p) const throw() {
        std::__libcpp_deallocate(p, __size_, __align_);
    }

   private:
    size_t __size_;
    size_t __align_;
  };

  typedef unique_ptr<void, __builtin_new_deleter> __holder_t;

  static __holder_t __allocate_bytes(size_t __s, size_t __align) {
      return __holder_t(std::__libcpp_allocate(__s, __align),
                     __builtin_new_deleter(__s, __align));
  }

  static void __deallocate_bytes(void* __p, size_t __s,
                                 size_t __align) throw() {
      std::__libcpp_deallocate(__p, __s, __align);
  }

  template <class _Tp>
  __attribute__((__nodebug__)) __attribute__ ((__always_inline__))
  static __holder_t __allocate_type(size_t __n) {
      return __allocate_bytes(__n * sizeof(_Tp), _Alignof(_Tp));
  }

  template <class _Tp>
  __attribute__((__nodebug__)) __attribute__ ((__always_inline__))
  static void __deallocate_type(void* __p, size_t __n) throw() {
      __deallocate_bytes(__p, __n * sizeof(_Tp), _Alignof(_Tp));
  }
};


} }








namespace std { inline namespace __1 {




template <class _Tp>

struct __attribute__ ((__type_visibility__("default"))) plus : binary_function<_Tp, _Tp, _Tp>
{
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator()(const _Tp& __x, const _Tp& __y) const
        {return __x + __y;}
};

template <class _Tp>

struct __attribute__ ((__type_visibility__("default"))) minus : binary_function<_Tp, _Tp, _Tp>
{
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator()(const _Tp& __x, const _Tp& __y) const
        {return __x - __y;}
};

template <class _Tp>

struct __attribute__ ((__type_visibility__("default"))) multiplies : binary_function<_Tp, _Tp, _Tp>
{
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator()(const _Tp& __x, const _Tp& __y) const
        {return __x * __y;}
};

template <class _Tp>

struct __attribute__ ((__type_visibility__("default"))) divides : binary_function<_Tp, _Tp, _Tp>
{
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator()(const _Tp& __x, const _Tp& __y) const
        {return __x / __y;}
};

template <class _Tp>

struct __attribute__ ((__type_visibility__("default"))) modulus : binary_function<_Tp, _Tp, _Tp>
{
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator()(const _Tp& __x, const _Tp& __y) const
        {return __x % __y;}
};

template <class _Tp>

struct __attribute__ ((__type_visibility__("default"))) negate : unary_function<_Tp, _Tp>
{
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator()(const _Tp& __x) const
        {return -__x;}
};

template <class _Tp>

struct __attribute__ ((__type_visibility__("default"))) equal_to : binary_function<_Tp, _Tp, bool>
{
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _Tp& __x, const _Tp& __y) const
        {return __x == __y;}
};

template <class _Tp>

struct __attribute__ ((__type_visibility__("default"))) not_equal_to : binary_function<_Tp, _Tp, bool>
{
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _Tp& __x, const _Tp& __y) const
        {return __x != __y;}
};

template <class _Tp>

struct __attribute__ ((__type_visibility__("default"))) greater : binary_function<_Tp, _Tp, bool>
{
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _Tp& __x, const _Tp& __y) const
        {return __x > __y;}
};

template <class _Tp>

struct __attribute__ ((__type_visibility__("default"))) greater_equal : binary_function<_Tp, _Tp, bool>
{
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _Tp& __x, const _Tp& __y) const
        {return __x >= __y;}
};

template <class _Tp>

struct __attribute__ ((__type_visibility__("default"))) less_equal : binary_function<_Tp, _Tp, bool>
{
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _Tp& __x, const _Tp& __y) const
        {return __x <= __y;}
};

template <class _Tp>

struct __attribute__ ((__type_visibility__("default"))) logical_and : binary_function<_Tp, _Tp, bool>
{
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _Tp& __x, const _Tp& __y) const
        {return __x && __y;}
};

template <class _Tp>

struct __attribute__ ((__type_visibility__("default"))) logical_or : binary_function<_Tp, _Tp, bool>
{
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _Tp& __x, const _Tp& __y) const
        {return __x || __y;}
};

template <class _Tp>

struct __attribute__ ((__type_visibility__("default"))) logical_not : unary_function<_Tp, bool>
{
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _Tp& __x) const
        {return !__x;}
};

template <class _Tp>

struct __attribute__ ((__type_visibility__("default"))) bit_and : binary_function<_Tp, _Tp, _Tp>
{
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator()(const _Tp& __x, const _Tp& __y) const
        {return __x & __y;}
};

template <class _Tp>

struct __attribute__ ((__type_visibility__("default"))) bit_or : binary_function<_Tp, _Tp, _Tp>
{
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator()(const _Tp& __x, const _Tp& __y) const
        {return __x | __y;}
};

template <class _Tp>

struct __attribute__ ((__type_visibility__("default"))) bit_xor : binary_function<_Tp, _Tp, _Tp>
{
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    _Tp operator()(const _Tp& __x, const _Tp& __y) const
        {return __x ^ __y;}
};

template <class _Predicate>
class __attribute__ ((__type_visibility__("default"))) unary_negate
    : public unary_function<typename _Predicate::argument_type, bool>
{
    _Predicate __pred_;
public:
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    explicit unary_negate(const _Predicate& __pred)
        : __pred_(__pred) {}
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const typename _Predicate::argument_type& __x) const
        {return !__pred_(__x);}
};

template <class _Predicate>
                            inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
unary_negate<_Predicate>
not1(const _Predicate& __pred) {return unary_negate<_Predicate>(__pred);}

template <class _Predicate>
class __attribute__ ((__type_visibility__("default"))) binary_negate
    : public binary_function<typename _Predicate::first_argument_type,
                             typename _Predicate::second_argument_type,
                             bool>
{
    _Predicate __pred_;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit
    binary_negate(const _Predicate& __pred) : __pred_(__pred) {}

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const typename _Predicate::first_argument_type& __x,
                    const typename _Predicate::second_argument_type& __y) const
        {return !__pred_(__x, __y);}
};

template <class _Predicate>
                            inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
binary_negate<_Predicate>
not2(const _Predicate& __pred) {return binary_negate<_Predicate>(__pred);}


template <class __Operation>
class __attribute__ ((__type_visibility__("default"))) binder1st
    : public unary_function<typename __Operation::second_argument_type,
                            typename __Operation::result_type>
{
protected:
    __Operation op;
    typename __Operation::first_argument_type value;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) binder1st(const __Operation& __x,
                               const typename __Operation::first_argument_type __y)
        : op(__x), value(__y) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) typename __Operation::result_type operator()
        (typename __Operation::second_argument_type& __x) const
            {return op(value, __x);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) typename __Operation::result_type operator()
        (const typename __Operation::second_argument_type& __x) const
            {return op(value, __x);}
};

template <class __Operation, class _Tp>
                            inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
binder1st<__Operation>
bind1st(const __Operation& __op, const _Tp& __x)
    {return binder1st<__Operation>(__op, __x);}

template <class __Operation>
class __attribute__ ((__type_visibility__("default"))) binder2nd
    : public unary_function<typename __Operation::first_argument_type,
                            typename __Operation::result_type>
{
protected:
    __Operation op;
    typename __Operation::second_argument_type value;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    binder2nd(const __Operation& __x, const typename __Operation::second_argument_type __y)
        : op(__x), value(__y) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) typename __Operation::result_type operator()
        ( typename __Operation::first_argument_type& __x) const
            {return op(__x, value);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) typename __Operation::result_type operator()
        (const typename __Operation::first_argument_type& __x) const
            {return op(__x, value);}
};

template <class __Operation, class _Tp>
                            inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
binder2nd<__Operation>
bind2nd(const __Operation& __op, const _Tp& __x)
    {return binder2nd<__Operation>(__op, __x);}

template <class _Arg, class _Result>
class __attribute__ ((__type_visibility__("default"))) pointer_to_unary_function
    : public unary_function<_Arg, _Result>
{
    _Result (*__f_)(_Arg);
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit pointer_to_unary_function(_Result (*__f)(_Arg))
        : __f_(__f) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) _Result operator()(_Arg __x) const
        {return __f_(__x);}
};

template <class _Arg, class _Result>
                            inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
pointer_to_unary_function<_Arg,_Result>
ptr_fun(_Result (*__f)(_Arg))
    {return pointer_to_unary_function<_Arg,_Result>(__f);}

template <class _Arg1, class _Arg2, class _Result>
class __attribute__ ((__type_visibility__("default"))) pointer_to_binary_function
    : public binary_function<_Arg1, _Arg2, _Result>
{
    _Result (*__f_)(_Arg1, _Arg2);
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit pointer_to_binary_function(_Result (*__f)(_Arg1, _Arg2))
        : __f_(__f) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) _Result operator()(_Arg1 __x, _Arg2 __y) const
        {return __f_(__x, __y);}
};

template <class _Arg1, class _Arg2, class _Result>
                            inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
pointer_to_binary_function<_Arg1,_Arg2,_Result>
ptr_fun(_Result (*__f)(_Arg1,_Arg2))
    {return pointer_to_binary_function<_Arg1,_Arg2,_Result>(__f);}

template<class _Sp, class _Tp>
class __attribute__ ((__type_visibility__("default"))) mem_fun_t
    : public unary_function<_Tp*, _Sp>
{
    _Sp (_Tp::*__p_)();
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit mem_fun_t(_Sp (_Tp::*__p)())
        : __p_(__p) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) _Sp operator()(_Tp* __p) const
        {return (__p->*__p_)();}
};

template<class _Sp, class _Tp, class _Ap>
class __attribute__ ((__type_visibility__("default"))) mem_fun1_t
    : public binary_function<_Tp*, _Ap, _Sp>
{
    _Sp (_Tp::*__p_)(_Ap);
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit mem_fun1_t(_Sp (_Tp::*__p)(_Ap))
        : __p_(__p) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) _Sp operator()(_Tp* __p, _Ap __x) const
        {return (__p->*__p_)(__x);}
};

template<class _Sp, class _Tp>
                            inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
mem_fun_t<_Sp,_Tp>
mem_fun(_Sp (_Tp::*__f)())
    {return mem_fun_t<_Sp,_Tp>(__f);}

template<class _Sp, class _Tp, class _Ap>
                            inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
mem_fun1_t<_Sp,_Tp,_Ap>
mem_fun(_Sp (_Tp::*__f)(_Ap))
    {return mem_fun1_t<_Sp,_Tp,_Ap>(__f);}

template<class _Sp, class _Tp>
class __attribute__ ((__type_visibility__("default"))) mem_fun_ref_t
    : public unary_function<_Tp, _Sp>
{
    _Sp (_Tp::*__p_)();
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit mem_fun_ref_t(_Sp (_Tp::*__p)())
        : __p_(__p) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) _Sp operator()(_Tp& __p) const
        {return (__p.*__p_)();}
};

template<class _Sp, class _Tp, class _Ap>
class __attribute__ ((__type_visibility__("default"))) mem_fun1_ref_t
    : public binary_function<_Tp, _Ap, _Sp>
{
    _Sp (_Tp::*__p_)(_Ap);
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit mem_fun1_ref_t(_Sp (_Tp::*__p)(_Ap))
        : __p_(__p) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) _Sp operator()(_Tp& __p, _Ap __x) const
        {return (__p.*__p_)(__x);}
};

template<class _Sp, class _Tp>
                            inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
mem_fun_ref_t<_Sp,_Tp>
mem_fun_ref(_Sp (_Tp::*__f)())
    {return mem_fun_ref_t<_Sp,_Tp>(__f);}

template<class _Sp, class _Tp, class _Ap>
                            inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
mem_fun1_ref_t<_Sp,_Tp,_Ap>
mem_fun_ref(_Sp (_Tp::*__f)(_Ap))
    {return mem_fun1_ref_t<_Sp,_Tp,_Ap>(__f);}

template <class _Sp, class _Tp>
class __attribute__ ((__type_visibility__("default"))) const_mem_fun_t
    : public unary_function<const _Tp*, _Sp>
{
    _Sp (_Tp::*__p_)() const;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit const_mem_fun_t(_Sp (_Tp::*__p)() const)
        : __p_(__p) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) _Sp operator()(const _Tp* __p) const
        {return (__p->*__p_)();}
};

template <class _Sp, class _Tp, class _Ap>
class __attribute__ ((__type_visibility__("default"))) const_mem_fun1_t
    : public binary_function<const _Tp*, _Ap, _Sp>
{
    _Sp (_Tp::*__p_)(_Ap) const;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit const_mem_fun1_t(_Sp (_Tp::*__p)(_Ap) const)
        : __p_(__p) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) _Sp operator()(const _Tp* __p, _Ap __x) const
        {return (__p->*__p_)(__x);}
};

template <class _Sp, class _Tp>
                            inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
const_mem_fun_t<_Sp,_Tp>
mem_fun(_Sp (_Tp::*__f)() const)
    {return const_mem_fun_t<_Sp,_Tp>(__f);}

template <class _Sp, class _Tp, class _Ap>
                            inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
const_mem_fun1_t<_Sp,_Tp,_Ap>
mem_fun(_Sp (_Tp::*__f)(_Ap) const)
    {return const_mem_fun1_t<_Sp,_Tp,_Ap>(__f);}

template <class _Sp, class _Tp>
class __attribute__ ((__type_visibility__("default"))) const_mem_fun_ref_t
    : public unary_function<_Tp, _Sp>
{
    _Sp (_Tp::*__p_)() const;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit const_mem_fun_ref_t(_Sp (_Tp::*__p)() const)
        : __p_(__p) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) _Sp operator()(const _Tp& __p) const
        {return (__p.*__p_)();}
};

template <class _Sp, class _Tp, class _Ap>
class __attribute__ ((__type_visibility__("default"))) const_mem_fun1_ref_t
    : public binary_function<_Tp, _Ap, _Sp>
{
    _Sp (_Tp::*__p_)(_Ap) const;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit const_mem_fun1_ref_t(_Sp (_Tp::*__p)(_Ap) const)
        : __p_(__p) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) _Sp operator()(const _Tp& __p, _Ap __x) const
        {return (__p.*__p_)(__x);}
};

template <class _Sp, class _Tp>
                            inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
const_mem_fun_ref_t<_Sp,_Tp>
mem_fun_ref(_Sp (_Tp::*__f)() const)
    {return const_mem_fun_ref_t<_Sp,_Tp>(__f);}

template <class _Sp, class _Tp, class _Ap>
                            inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
const_mem_fun1_ref_t<_Sp,_Tp,_Ap>
mem_fun_ref(_Sp (_Tp::*__f)(_Ap) const)
    {return const_mem_fun1_ref_t<_Sp,_Tp,_Ap>(__f);}






template <class _Tp>
class __mem_fn
    : public __weak_result_type<_Tp>
{
public:

    typedef _Tp type;
private:
    type __f_;

public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __mem_fn(type __f) throw() : __f_(__f) {}

    template <class _A0>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return0<type, _A0>::type
    operator() (_A0& __a0) const {
        return __invoke(__f_, __a0);
    }

    template <class _A0>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return0<type, _A0 const>::type
    operator() (_A0 const& __a0) const {
        return __invoke(__f_, __a0);
    }

    template <class _A0, class _A1>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return1<type, _A0, _A1>::type
    operator() (_A0& __a0, _A1& __a1) const {
        return __invoke(__f_, __a0, __a1);
    }

    template <class _A0, class _A1>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return1<type, _A0 const, _A1>::type
    operator() (_A0 const& __a0, _A1& __a1) const {
        return __invoke(__f_, __a0, __a1);
    }

    template <class _A0, class _A1>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return1<type, _A0, _A1 const>::type
    operator() (_A0& __a0, _A1 const& __a1) const {
        return __invoke(__f_, __a0, __a1);
    }

    template <class _A0, class _A1>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return1<type, _A0 const, _A1 const>::type
    operator() (_A0 const& __a0, _A1 const& __a1) const {
        return __invoke(__f_, __a0, __a1);
    }

    template <class _A0, class _A1, class _A2>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return2<type, _A0, _A1, _A2>::type
    operator() (_A0& __a0, _A1& __a1, _A2& __a2) const {
        return __invoke(__f_, __a0, __a1, __a2);
    }

    template <class _A0, class _A1, class _A2>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return2<type, _A0 const, _A1, _A2>::type
    operator() (_A0 const& __a0, _A1& __a1, _A2& __a2) const {
        return __invoke(__f_, __a0, __a1, __a2);
    }

    template <class _A0, class _A1, class _A2>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return2<type, _A0, _A1 const, _A2>::type
    operator() (_A0& __a0, _A1 const& __a1, _A2& __a2) const {
        return __invoke(__f_, __a0, __a1, __a2);
    }

    template <class _A0, class _A1, class _A2>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return2<type, _A0, _A1, _A2 const>::type
    operator() (_A0& __a0, _A1& __a1, _A2 const& __a2) const {
        return __invoke(__f_, __a0, __a1, __a2);
    }

    template <class _A0, class _A1, class _A2>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return2<type, _A0 const, _A1 const, _A2>::type
    operator() (_A0 const& __a0, _A1 const& __a1, _A2& __a2) const {
        return __invoke(__f_, __a0, __a1, __a2);
    }

    template <class _A0, class _A1, class _A2>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return2<type, _A0 const, _A1, _A2 const>::type
    operator() (_A0 const& __a0, _A1& __a1, _A2 const& __a2) const {
        return __invoke(__f_, __a0, __a1, __a2);
    }

    template <class _A0, class _A1, class _A2>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return2<type, _A0, _A1 const, _A2 const>::type
    operator() (_A0& __a0, _A1 const& __a1, _A2 const& __a2) const {
        return __invoke(__f_, __a0, __a1, __a2);
    }

    template <class _A0, class _A1, class _A2>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    typename __invoke_return2<type, _A0 const, _A1 const, _A2 const>::type
    operator() (_A0 const& __a0, _A1 const& __a1, _A2 const& __a2) const {
        return __invoke(__f_, __a0, __a1, __a2);
    }

};

template<class _Rp, class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__mem_fn<_Rp _Tp::*>
mem_fn(_Rp _Tp::* __pm) throw()
{
    return __mem_fn<_Rp _Tp::*>(__pm);
}







class __attribute__ ((__visibility__("default"))) bad_function_call
    : public exception
{






};

__attribute__ ((noreturn)) inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void __throw_bad_function_call()
{

    throw bad_function_call();



}

template<class _Fp> class __attribute__ ((__type_visibility__("default"))) function;

namespace __function
{

template<class _Rp>
struct __maybe_derive_from_unary_function
{
};

template<class _Rp, class _A1>
struct __maybe_derive_from_unary_function<_Rp(_A1)>
    : public unary_function<_A1, _Rp>
{
};

template<class _Rp>
struct __maybe_derive_from_binary_function
{
};

template<class _Rp, class _A1, class _A2>
struct __maybe_derive_from_binary_function<_Rp(_A1, _A2)>
    : public binary_function<_A1, _A2, _Rp>
{
};

template <class _Fp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool __not_null(_Fp const&) { return true; }

template <class _Fp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool __not_null(_Fp* __ptr) { return __ptr; }

template <class _Ret, class _Class>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool __not_null(_Ret _Class::*__ptr) { return __ptr; }

template <class _Fp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool __not_null(function<_Fp> const& __f) { return !!__f; }


template <class _Rp, class ..._Args>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool __not_null(_Rp (^__p)(_Args...)) { return __p; }


}





namespace __function {

template<class _Fp> class __base;

template<class _Rp>
class __base<_Rp()>
{
    __base(const __base&);
    __base& operator=(const __base&);
public:
    __base() {}
    virtual ~__base() {}
    virtual __base* __clone() const = 0;
    virtual void __clone(__base*) const = 0;
    virtual void destroy() = 0;
    virtual void destroy_deallocate() = 0;
    virtual _Rp operator()() = 0;

    virtual const void* target(const type_info&) const = 0;
    virtual const std::type_info& target_type() const = 0;

};

template<class _Rp, class _A0>
class __base<_Rp(_A0)>
{
    __base(const __base&);
    __base& operator=(const __base&);
public:
    __base() {}
    virtual ~__base() {}
    virtual __base* __clone() const = 0;
    virtual void __clone(__base*) const = 0;
    virtual void destroy() = 0;
    virtual void destroy_deallocate() = 0;
    virtual _Rp operator()(_A0) = 0;

    virtual const void* target(const type_info&) const = 0;
    virtual const std::type_info& target_type() const = 0;

};

template<class _Rp, class _A0, class _A1>
class __base<_Rp(_A0, _A1)>
{
    __base(const __base&);
    __base& operator=(const __base&);
public:
    __base() {}
    virtual ~__base() {}
    virtual __base* __clone() const = 0;
    virtual void __clone(__base*) const = 0;
    virtual void destroy() = 0;
    virtual void destroy_deallocate() = 0;
    virtual _Rp operator()(_A0, _A1) = 0;

    virtual const void* target(const type_info&) const = 0;
    virtual const std::type_info& target_type() const = 0;

};

template<class _Rp, class _A0, class _A1, class _A2>
class __base<_Rp(_A0, _A1, _A2)>
{
    __base(const __base&);
    __base& operator=(const __base&);
public:
    __base() {}
    virtual ~__base() {}
    virtual __base* __clone() const = 0;
    virtual void __clone(__base*) const = 0;
    virtual void destroy() = 0;
    virtual void destroy_deallocate() = 0;
    virtual _Rp operator()(_A0, _A1, _A2) = 0;

    virtual const void* target(const type_info&) const = 0;
    virtual const std::type_info& target_type() const = 0;

};

template<class _FD, class _Alloc, class _FB> class __func;

template<class _Fp, class _Alloc, class _Rp>
class __func<_Fp, _Alloc, _Rp()>
    : public __base<_Rp()>
{
    __compressed_pair<_Fp, _Alloc> __f_;
public:
    explicit __func(_Fp __f) : __f_(std::__1::move(__f), __default_init_tag()) {}
    explicit __func(_Fp __f, _Alloc __a) : __f_(std::__1::move(__f), std::__1::move(__a)) {}
    virtual __base<_Rp()>* __clone() const;
    virtual void __clone(__base<_Rp()>*) const;
    virtual void destroy();
    virtual void destroy_deallocate();
    virtual _Rp operator()();

    virtual const void* target(const type_info&) const;
    virtual const std::type_info& target_type() const;

};

template<class _Fp, class _Alloc, class _Rp>
__base<_Rp()>*
__func<_Fp, _Alloc, _Rp()>::__clone() const
{
    typedef allocator_traits<_Alloc> __alloc_traits;
    typedef typename __rebind_alloc_helper<__alloc_traits, __func>::type _Ap;
    _Ap __a(__f_.second());
    typedef __allocator_destructor<_Ap> _Dp;
    unique_ptr<__func, _Dp> __hold(__a.allocate(1), _Dp(__a, 1));
    ::new (__hold.get()) __func(__f_.first(), _Alloc(__a));
    return __hold.release();
}

template<class _Fp, class _Alloc, class _Rp>
void
__func<_Fp, _Alloc, _Rp()>::__clone(__base<_Rp()>* __p) const
{
    ::new (__p) __func(__f_.first(), __f_.second());
}

template<class _Fp, class _Alloc, class _Rp>
void
__func<_Fp, _Alloc, _Rp()>::destroy()
{
    __f_.~__compressed_pair<_Fp, _Alloc>();
}

template<class _Fp, class _Alloc, class _Rp>
void
__func<_Fp, _Alloc, _Rp()>::destroy_deallocate()
{
    typedef allocator_traits<_Alloc> __alloc_traits;
    typedef typename __rebind_alloc_helper<__alloc_traits, __func>::type _Ap;
    _Ap __a(__f_.second());
    __f_.~__compressed_pair<_Fp, _Alloc>();
    __a.deallocate(this, 1);
}

template<class _Fp, class _Alloc, class _Rp>
_Rp
__func<_Fp, _Alloc, _Rp()>::operator()()
{
    typedef __invoke_void_return_wrapper<_Rp> _Invoker;
    return _Invoker::__call(__f_.first());
}



template<class _Fp, class _Alloc, class _Rp>
const void*
__func<_Fp, _Alloc, _Rp()>::target(const type_info& __ti) const
{
    if (__ti == typeid(_Fp))
        return &__f_.first();
    return (const void*)0;
}

template<class _Fp, class _Alloc, class _Rp>
const std::type_info&
__func<_Fp, _Alloc, _Rp()>::target_type() const
{
    return typeid(_Fp);
}



template<class _Fp, class _Alloc, class _Rp, class _A0>
class __func<_Fp, _Alloc, _Rp(_A0)>
    : public __base<_Rp(_A0)>
{
    __compressed_pair<_Fp, _Alloc> __f_;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit __func(_Fp __f) : __f_(std::__1::move(__f), __default_init_tag()) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit __func(_Fp __f, _Alloc __a)
        : __f_(std::__1::move(__f), std::__1::move(__a)) {}
    virtual __base<_Rp(_A0)>* __clone() const;
    virtual void __clone(__base<_Rp(_A0)>*) const;
    virtual void destroy();
    virtual void destroy_deallocate();
    virtual _Rp operator()(_A0);

    virtual const void* target(const type_info&) const;
    virtual const std::type_info& target_type() const;

};

template<class _Fp, class _Alloc, class _Rp, class _A0>
__base<_Rp(_A0)>*
__func<_Fp, _Alloc, _Rp(_A0)>::__clone() const
{
    typedef allocator_traits<_Alloc> __alloc_traits;
    typedef typename __rebind_alloc_helper<__alloc_traits, __func>::type _Ap;
    _Ap __a(__f_.second());
    typedef __allocator_destructor<_Ap> _Dp;
    unique_ptr<__func, _Dp> __hold(__a.allocate(1), _Dp(__a, 1));
    ::new (__hold.get()) __func(__f_.first(), _Alloc(__a));
    return __hold.release();
}

template<class _Fp, class _Alloc, class _Rp, class _A0>
void
__func<_Fp, _Alloc, _Rp(_A0)>::__clone(__base<_Rp(_A0)>* __p) const
{
    ::new (__p) __func(__f_.first(), __f_.second());
}

template<class _Fp, class _Alloc, class _Rp, class _A0>
void
__func<_Fp, _Alloc, _Rp(_A0)>::destroy()
{
    __f_.~__compressed_pair<_Fp, _Alloc>();
}

template<class _Fp, class _Alloc, class _Rp, class _A0>
void
__func<_Fp, _Alloc, _Rp(_A0)>::destroy_deallocate()
{
    typedef allocator_traits<_Alloc> __alloc_traits;
    typedef typename __rebind_alloc_helper<__alloc_traits, __func>::type _Ap;
    _Ap __a(__f_.second());
    __f_.~__compressed_pair<_Fp, _Alloc>();
    __a.deallocate(this, 1);
}

template<class _Fp, class _Alloc, class _Rp, class _A0>
_Rp
__func<_Fp, _Alloc, _Rp(_A0)>::operator()(_A0 __a0)
{
    typedef __invoke_void_return_wrapper<_Rp> _Invoker;
    return _Invoker::__call(__f_.first(), __a0);
}



template<class _Fp, class _Alloc, class _Rp, class _A0>
const void*
__func<_Fp, _Alloc, _Rp(_A0)>::target(const type_info& __ti) const
{
    if (__ti == typeid(_Fp))
        return &__f_.first();
    return (const void*)0;
}

template<class _Fp, class _Alloc, class _Rp, class _A0>
const std::type_info&
__func<_Fp, _Alloc, _Rp(_A0)>::target_type() const
{
    return typeid(_Fp);
}



template<class _Fp, class _Alloc, class _Rp, class _A0, class _A1>
class __func<_Fp, _Alloc, _Rp(_A0, _A1)>
    : public __base<_Rp(_A0, _A1)>
{
    __compressed_pair<_Fp, _Alloc> __f_;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit __func(_Fp __f) : __f_(std::__1::move(__f), __default_init_tag()) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit __func(_Fp __f, _Alloc __a)
        : __f_(std::__1::move(__f), std::__1::move(__a)) {}
    virtual __base<_Rp(_A0, _A1)>* __clone() const;
    virtual void __clone(__base<_Rp(_A0, _A1)>*) const;
    virtual void destroy();
    virtual void destroy_deallocate();
    virtual _Rp operator()(_A0, _A1);

    virtual const void* target(const type_info&) const;
    virtual const std::type_info& target_type() const;

};

template<class _Fp, class _Alloc, class _Rp, class _A0, class _A1>
__base<_Rp(_A0, _A1)>*
__func<_Fp, _Alloc, _Rp(_A0, _A1)>::__clone() const
{
    typedef allocator_traits<_Alloc> __alloc_traits;
    typedef typename __rebind_alloc_helper<__alloc_traits, __func>::type _Ap;
    _Ap __a(__f_.second());
    typedef __allocator_destructor<_Ap> _Dp;
    unique_ptr<__func, _Dp> __hold(__a.allocate(1), _Dp(__a, 1));
    ::new (__hold.get()) __func(__f_.first(), _Alloc(__a));
    return __hold.release();
}

template<class _Fp, class _Alloc, class _Rp, class _A0, class _A1>
void
__func<_Fp, _Alloc, _Rp(_A0, _A1)>::__clone(__base<_Rp(_A0, _A1)>* __p) const
{
    ::new (__p) __func(__f_.first(), __f_.second());
}

template<class _Fp, class _Alloc, class _Rp, class _A0, class _A1>
void
__func<_Fp, _Alloc, _Rp(_A0, _A1)>::destroy()
{
    __f_.~__compressed_pair<_Fp, _Alloc>();
}

template<class _Fp, class _Alloc, class _Rp, class _A0, class _A1>
void
__func<_Fp, _Alloc, _Rp(_A0, _A1)>::destroy_deallocate()
{
    typedef allocator_traits<_Alloc> __alloc_traits;
    typedef typename __rebind_alloc_helper<__alloc_traits, __func>::type _Ap;
    _Ap __a(__f_.second());
    __f_.~__compressed_pair<_Fp, _Alloc>();
    __a.deallocate(this, 1);
}

template<class _Fp, class _Alloc, class _Rp, class _A0, class _A1>
_Rp
__func<_Fp, _Alloc, _Rp(_A0, _A1)>::operator()(_A0 __a0, _A1 __a1)
{
    typedef __invoke_void_return_wrapper<_Rp> _Invoker;
    return _Invoker::__call(__f_.first(), __a0, __a1);
}



template<class _Fp, class _Alloc, class _Rp, class _A0, class _A1>
const void*
__func<_Fp, _Alloc, _Rp(_A0, _A1)>::target(const type_info& __ti) const
{
    if (__ti == typeid(_Fp))
        return &__f_.first();
    return (const void*)0;
}

template<class _Fp, class _Alloc, class _Rp, class _A0, class _A1>
const std::type_info&
__func<_Fp, _Alloc, _Rp(_A0, _A1)>::target_type() const
{
    return typeid(_Fp);
}



template<class _Fp, class _Alloc, class _Rp, class _A0, class _A1, class _A2>
class __func<_Fp, _Alloc, _Rp(_A0, _A1, _A2)>
    : public __base<_Rp(_A0, _A1, _A2)>
{
    __compressed_pair<_Fp, _Alloc> __f_;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit __func(_Fp __f) : __f_(std::__1::move(__f), __default_init_tag()) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit __func(_Fp __f, _Alloc __a)
        : __f_(std::__1::move(__f), std::__1::move(__a)) {}
    virtual __base<_Rp(_A0, _A1, _A2)>* __clone() const;
    virtual void __clone(__base<_Rp(_A0, _A1, _A2)>*) const;
    virtual void destroy();
    virtual void destroy_deallocate();
    virtual _Rp operator()(_A0, _A1, _A2);

    virtual const void* target(const type_info&) const;
    virtual const std::type_info& target_type() const;

};

template<class _Fp, class _Alloc, class _Rp, class _A0, class _A1, class _A2>
__base<_Rp(_A0, _A1, _A2)>*
__func<_Fp, _Alloc, _Rp(_A0, _A1, _A2)>::__clone() const
{
    typedef allocator_traits<_Alloc> __alloc_traits;
    typedef typename __rebind_alloc_helper<__alloc_traits, __func>::type _Ap;
    _Ap __a(__f_.second());
    typedef __allocator_destructor<_Ap> _Dp;
    unique_ptr<__func, _Dp> __hold(__a.allocate(1), _Dp(__a, 1));
    ::new (__hold.get()) __func(__f_.first(), _Alloc(__a));
    return __hold.release();
}

template<class _Fp, class _Alloc, class _Rp, class _A0, class _A1, class _A2>
void
__func<_Fp, _Alloc, _Rp(_A0, _A1, _A2)>::__clone(__base<_Rp(_A0, _A1, _A2)>* __p) const
{
    ::new (__p) __func(__f_.first(), __f_.second());
}

template<class _Fp, class _Alloc, class _Rp, class _A0, class _A1, class _A2>
void
__func<_Fp, _Alloc, _Rp(_A0, _A1, _A2)>::destroy()
{
    __f_.~__compressed_pair<_Fp, _Alloc>();
}

template<class _Fp, class _Alloc, class _Rp, class _A0, class _A1, class _A2>
void
__func<_Fp, _Alloc, _Rp(_A0, _A1, _A2)>::destroy_deallocate()
{
    typedef allocator_traits<_Alloc> __alloc_traits;
    typedef typename __rebind_alloc_helper<__alloc_traits, __func>::type _Ap;
    _Ap __a(__f_.second());
    __f_.~__compressed_pair<_Fp, _Alloc>();
    __a.deallocate(this, 1);
}

template<class _Fp, class _Alloc, class _Rp, class _A0, class _A1, class _A2>
_Rp
__func<_Fp, _Alloc, _Rp(_A0, _A1, _A2)>::operator()(_A0 __a0, _A1 __a1, _A2 __a2)
{
    typedef __invoke_void_return_wrapper<_Rp> _Invoker;
    return _Invoker::__call(__f_.first(), __a0, __a1, __a2);
}



template<class _Fp, class _Alloc, class _Rp, class _A0, class _A1, class _A2>
const void*
__func<_Fp, _Alloc, _Rp(_A0, _A1, _A2)>::target(const type_info& __ti) const
{
    if (__ti == typeid(_Fp))
        return &__f_.first();
    return (const void*)0;
}

template<class _Fp, class _Alloc, class _Rp, class _A0, class _A1, class _A2>
const std::type_info&
__func<_Fp, _Alloc, _Rp(_A0, _A1, _A2)>::target_type() const
{
    return typeid(_Fp);
}



}

template<class _Rp>
class __attribute__ ((__type_visibility__("default"))) function<_Rp()>
{
    typedef __function::__base<_Rp()> __base;
    aligned_storage<3*sizeof(void*)>::type __buf_;
    __base* __f_;

public:
    typedef _Rp result_type;


    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit function() : __f_(0) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) function(nullptr_t) : __f_(0) {}
    function(const function&);
    template<class _Fp>
      function(_Fp,
               typename enable_if<!is_integral<_Fp>::value>::type* = 0);

    template<class _Alloc>
      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
      function(allocator_arg_t, const _Alloc&) : __f_(0) {}
    template<class _Alloc>
      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
      function(allocator_arg_t, const _Alloc&, nullptr_t) : __f_(0) {}
    template<class _Alloc>
      function(allocator_arg_t, const _Alloc&, const function&);
    template<class _Fp, class _Alloc>
      function(allocator_arg_t, const _Alloc& __a, _Fp __f,
               typename enable_if<!is_integral<_Fp>::value>::type* = 0);

    function& operator=(const function&);
    function& operator=(nullptr_t);
    template<class _Fp>
      typename enable_if
      <
        !is_integral<_Fp>::value,
        function&
      >::type
      operator=(_Fp);

    ~function();


    void swap(function&);
    template<class _Fp, class _Alloc>
      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
      void assign(_Fp __f, const _Alloc& __a)
        {function(allocator_arg, __a, __f).swap(*this);}


    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) operator bool() const {return __f_;}

private:

    template<class _R2>
      bool operator==(const function<_R2()>&) const;
    template<class _R2>
      bool operator!=(const function<_R2()>&) const;
public:

    _Rp operator()() const;



    const std::type_info& target_type() const;
    template <typename _Tp> _Tp* target();
    template <typename _Tp> const _Tp* target() const;

};

template<class _Rp>
function<_Rp()>::function(const function& __f)
{
    if (__f.__f_ == 0)
        __f_ = 0;
    else if (__f.__f_ == (const __base*)&__f.__buf_)
    {
        __f_ = (__base*)&__buf_;
        __f.__f_->__clone(__f_);
    }
    else
        __f_ = __f.__f_->__clone();
}

template<class _Rp>
template<class _Alloc>
function<_Rp()>::function(allocator_arg_t, const _Alloc&, const function& __f)
{
    if (__f.__f_ == 0)
        __f_ = 0;
    else if (__f.__f_ == (const __base*)&__f.__buf_)
    {
        __f_ = (__base*)&__buf_;
        __f.__f_->__clone(__f_);
    }
    else
        __f_ = __f.__f_->__clone();
}

template<class _Rp>
template <class _Fp>
function<_Rp()>::function(_Fp __f,
                                     typename enable_if<!is_integral<_Fp>::value>::type*)
    : __f_(0)
{
    if (__function::__not_null(__f))
    {
        typedef __function::__func<_Fp, allocator<_Fp>, _Rp()> _FF;
        if (sizeof(_FF) <= sizeof(__buf_))
        {
            __f_ = (__base*)&__buf_;
            ::new (__f_) _FF(__f);
        }
        else
        {
            typedef allocator<_FF> _Ap;
            _Ap __a;
            typedef __allocator_destructor<_Ap> _Dp;
            unique_ptr<__base, _Dp> __hold(__a.allocate(1), _Dp(__a, 1));
            ::new (__hold.get()) _FF(__f, allocator<_Fp>(__a));
            __f_ = __hold.release();
        }
    }
}

template<class _Rp>
template <class _Fp, class _Alloc>
function<_Rp()>::function(allocator_arg_t, const _Alloc& __a0, _Fp __f,
                                     typename enable_if<!is_integral<_Fp>::value>::type*)
    : __f_(0)
{
    typedef allocator_traits<_Alloc> __alloc_traits;
    if (__function::__not_null(__f))
    {
        typedef __function::__func<_Fp, _Alloc, _Rp()> _FF;
        if (sizeof(_FF) <= sizeof(__buf_))
        {
            __f_ = (__base*)&__buf_;
            ::new (__f_) _FF(__f, __a0);
        }
        else
        {
            typedef typename __rebind_alloc_helper<__alloc_traits, _FF>::type _Ap;
            _Ap __a(__a0);
            typedef __allocator_destructor<_Ap> _Dp;
            unique_ptr<__base, _Dp> __hold(__a.allocate(1), _Dp(__a, 1));
            ::new (__hold.get()) _FF(__f, _Alloc(__a));
            __f_ = __hold.release();
        }
    }
}

template<class _Rp>
function<_Rp()>&
function<_Rp()>::operator=(const function& __f)
{
    if (__f)
        function(__f).swap(*this);
    else
        *this = std::__1::__get_nullptr_t();
    return *this;
}

template<class _Rp>
function<_Rp()>&
function<_Rp()>::operator=(nullptr_t)
{
    __base* __t = __f_;
    __f_ = 0;
    if (__t == (__base*)&__buf_)
        __t->destroy();
    else if (__t)
        __t->destroy_deallocate();
    return *this;
}

template<class _Rp>
template <class _Fp>
typename enable_if
<
    !is_integral<_Fp>::value,
    function<_Rp()>&
>::type
function<_Rp()>::operator=(_Fp __f)
{
    function(std::__1::move(__f)).swap(*this);
    return *this;
}

template<class _Rp>
function<_Rp()>::~function()
{
    if (__f_ == (__base*)&__buf_)
        __f_->destroy();
    else if (__f_)
        __f_->destroy_deallocate();
}

template<class _Rp>
void
function<_Rp()>::swap(function& __f)
{
    if (std::__1::addressof(__f) == this)
      return;
    if (__f_ == (__base*)&__buf_ && __f.__f_ == (__base*)&__f.__buf_)
    {
        typename aligned_storage<sizeof(__buf_)>::type __tempbuf;
        __base* __t = (__base*)&__tempbuf;
        __f_->__clone(__t);
        __f_->destroy();
        __f_ = 0;
        __f.__f_->__clone((__base*)&__buf_);
        __f.__f_->destroy();
        __f.__f_ = 0;
        __f_ = (__base*)&__buf_;
        __t->__clone((__base*)&__f.__buf_);
        __t->destroy();
        __f.__f_ = (__base*)&__f.__buf_;
    }
    else if (__f_ == (__base*)&__buf_)
    {
        __f_->__clone((__base*)&__f.__buf_);
        __f_->destroy();
        __f_ = __f.__f_;
        __f.__f_ = (__base*)&__f.__buf_;
    }
    else if (__f.__f_ == (__base*)&__f.__buf_)
    {
        __f.__f_->__clone((__base*)&__buf_);
        __f.__f_->destroy();
        __f.__f_ = __f_;
        __f_ = (__base*)&__buf_;
    }
    else
        std::__1::swap(__f_, __f.__f_);
}

template<class _Rp>
_Rp
function<_Rp()>::operator()() const
{
    if (__f_ == 0)
        __throw_bad_function_call();
    return (*__f_)();
}



template<class _Rp>
const std::type_info&
function<_Rp()>::target_type() const
{
    if (__f_ == 0)
        return typeid(void);
    return __f_->target_type();
}

template<class _Rp>
template <typename _Tp>
_Tp*
function<_Rp()>::target()
{
    if (__f_ == 0)
        return (_Tp*)0;
    return (_Tp*) const_cast<void *>(__f_->target(typeid(_Tp)));
}

template<class _Rp>
template <typename _Tp>
const _Tp*
function<_Rp()>::target() const
{
    if (__f_ == 0)
        return (const _Tp*)0;
    return (const _Tp*)__f_->target(typeid(_Tp));
}



template<class _Rp, class _A0>
class __attribute__ ((__type_visibility__("default"))) function<_Rp(_A0)>
    : public unary_function<_A0, _Rp>
{
    typedef __function::__base<_Rp(_A0)> __base;
    aligned_storage<3*sizeof(void*)>::type __buf_;
    __base* __f_;

public:
    typedef _Rp result_type;


    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit function() : __f_(0) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) function(nullptr_t) : __f_(0) {}
    function(const function&);
    template<class _Fp>
      function(_Fp,
               typename enable_if<!is_integral<_Fp>::value>::type* = 0);

    template<class _Alloc>
      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
      function(allocator_arg_t, const _Alloc&) : __f_(0) {}
    template<class _Alloc>
      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
      function(allocator_arg_t, const _Alloc&, nullptr_t) : __f_(0) {}
    template<class _Alloc>
      function(allocator_arg_t, const _Alloc&, const function&);
    template<class _Fp, class _Alloc>
      function(allocator_arg_t, const _Alloc& __a, _Fp __f,
               typename enable_if<!is_integral<_Fp>::value>::type* = 0);

    function& operator=(const function&);
    function& operator=(nullptr_t);
    template<class _Fp>
      typename enable_if
      <
        !is_integral<_Fp>::value,
        function&
      >::type
      operator=(_Fp);

    ~function();


    void swap(function&);
    template<class _Fp, class _Alloc>
      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
      void assign(_Fp __f, const _Alloc& __a)
        {function(allocator_arg, __a, __f).swap(*this);}


    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) operator bool() const {return __f_;}

private:

    template<class _R2, class _B0>
      bool operator==(const function<_R2(_B0)>&) const;
    template<class _R2, class _B0>
      bool operator!=(const function<_R2(_B0)>&) const;
public:

    _Rp operator()(_A0) const;



    const std::type_info& target_type() const;
    template <typename _Tp> _Tp* target();
    template <typename _Tp> const _Tp* target() const;

};

template<class _Rp, class _A0>
function<_Rp(_A0)>::function(const function& __f)
{
    if (__f.__f_ == 0)
        __f_ = 0;
    else if (__f.__f_ == (const __base*)&__f.__buf_)
    {
        __f_ = (__base*)&__buf_;
        __f.__f_->__clone(__f_);
    }
    else
        __f_ = __f.__f_->__clone();
}

template<class _Rp, class _A0>
template<class _Alloc>
function<_Rp(_A0)>::function(allocator_arg_t, const _Alloc&, const function& __f)
{
    if (__f.__f_ == 0)
        __f_ = 0;
    else if (__f.__f_ == (const __base*)&__f.__buf_)
    {
        __f_ = (__base*)&__buf_;
        __f.__f_->__clone(__f_);
    }
    else
        __f_ = __f.__f_->__clone();
}

template<class _Rp, class _A0>
template <class _Fp>
function<_Rp(_A0)>::function(_Fp __f,
                                     typename enable_if<!is_integral<_Fp>::value>::type*)
    : __f_(0)
{
    if (__function::__not_null(__f))
    {
        typedef __function::__func<_Fp, allocator<_Fp>, _Rp(_A0)> _FF;
        if (sizeof(_FF) <= sizeof(__buf_))
        {
            __f_ = (__base*)&__buf_;
            ::new (__f_) _FF(__f);
        }
        else
        {
            typedef allocator<_FF> _Ap;
            _Ap __a;
            typedef __allocator_destructor<_Ap> _Dp;
            unique_ptr<__base, _Dp> __hold(__a.allocate(1), _Dp(__a, 1));
            ::new (__hold.get()) _FF(__f, allocator<_Fp>(__a));
            __f_ = __hold.release();
        }
    }
}

template<class _Rp, class _A0>
template <class _Fp, class _Alloc>
function<_Rp(_A0)>::function(allocator_arg_t, const _Alloc& __a0, _Fp __f,
                                     typename enable_if<!is_integral<_Fp>::value>::type*)
    : __f_(0)
{
    typedef allocator_traits<_Alloc> __alloc_traits;
    if (__function::__not_null(__f))
    {
        typedef __function::__func<_Fp, _Alloc, _Rp(_A0)> _FF;
        if (sizeof(_FF) <= sizeof(__buf_))
        {
            __f_ = (__base*)&__buf_;
            ::new (__f_) _FF(__f, __a0);
        }
        else
        {
            typedef typename __rebind_alloc_helper<__alloc_traits, _FF>::type _Ap;
            _Ap __a(__a0);
            typedef __allocator_destructor<_Ap> _Dp;
            unique_ptr<__base, _Dp> __hold(__a.allocate(1), _Dp(__a, 1));
            ::new (__hold.get()) _FF(__f, _Alloc(__a));
            __f_ = __hold.release();
        }
    }
}

template<class _Rp, class _A0>
function<_Rp(_A0)>&
function<_Rp(_A0)>::operator=(const function& __f)
{
    if (__f)
        function(__f).swap(*this);
    else
        *this = std::__1::__get_nullptr_t();
    return *this;
}

template<class _Rp, class _A0>
function<_Rp(_A0)>&
function<_Rp(_A0)>::operator=(nullptr_t)
{
    __base* __t = __f_;
    __f_ = 0;
    if (__t == (__base*)&__buf_)
        __t->destroy();
    else if (__t)
        __t->destroy_deallocate();
    return *this;
}

template<class _Rp, class _A0>
template <class _Fp>
typename enable_if
<
    !is_integral<_Fp>::value,
    function<_Rp(_A0)>&
>::type
function<_Rp(_A0)>::operator=(_Fp __f)
{
    function(std::__1::move(__f)).swap(*this);
    return *this;
}

template<class _Rp, class _A0>
function<_Rp(_A0)>::~function()
{
    if (__f_ == (__base*)&__buf_)
        __f_->destroy();
    else if (__f_)
        __f_->destroy_deallocate();
}

template<class _Rp, class _A0>
void
function<_Rp(_A0)>::swap(function& __f)
{
    if (std::__1::addressof(__f) == this)
      return;
    if (__f_ == (__base*)&__buf_ && __f.__f_ == (__base*)&__f.__buf_)
    {
        typename aligned_storage<sizeof(__buf_)>::type __tempbuf;
        __base* __t = (__base*)&__tempbuf;
        __f_->__clone(__t);
        __f_->destroy();
        __f_ = 0;
        __f.__f_->__clone((__base*)&__buf_);
        __f.__f_->destroy();
        __f.__f_ = 0;
        __f_ = (__base*)&__buf_;
        __t->__clone((__base*)&__f.__buf_);
        __t->destroy();
        __f.__f_ = (__base*)&__f.__buf_;
    }
    else if (__f_ == (__base*)&__buf_)
    {
        __f_->__clone((__base*)&__f.__buf_);
        __f_->destroy();
        __f_ = __f.__f_;
        __f.__f_ = (__base*)&__f.__buf_;
    }
    else if (__f.__f_ == (__base*)&__f.__buf_)
    {
        __f.__f_->__clone((__base*)&__buf_);
        __f.__f_->destroy();
        __f.__f_ = __f_;
        __f_ = (__base*)&__buf_;
    }
    else
        std::__1::swap(__f_, __f.__f_);
}

template<class _Rp, class _A0>
_Rp
function<_Rp(_A0)>::operator()(_A0 __a0) const
{
    if (__f_ == 0)
        __throw_bad_function_call();
    return (*__f_)(__a0);
}



template<class _Rp, class _A0>
const std::type_info&
function<_Rp(_A0)>::target_type() const
{
    if (__f_ == 0)
        return typeid(void);
    return __f_->target_type();
}

template<class _Rp, class _A0>
template <typename _Tp>
_Tp*
function<_Rp(_A0)>::target()
{
    if (__f_ == 0)
        return (_Tp*)0;
    return (_Tp*) const_cast<void *>(__f_->target(typeid(_Tp)));
}

template<class _Rp, class _A0>
template <typename _Tp>
const _Tp*
function<_Rp(_A0)>::target() const
{
    if (__f_ == 0)
        return (const _Tp*)0;
    return (const _Tp*)__f_->target(typeid(_Tp));
}



template<class _Rp, class _A0, class _A1>
class __attribute__ ((__type_visibility__("default"))) function<_Rp(_A0, _A1)>
    : public binary_function<_A0, _A1, _Rp>
{
    typedef __function::__base<_Rp(_A0, _A1)> __base;
    aligned_storage<3*sizeof(void*)>::type __buf_;
    __base* __f_;

public:
    typedef _Rp result_type;


    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit function() : __f_(0) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) function(nullptr_t) : __f_(0) {}
    function(const function&);
    template<class _Fp>
      function(_Fp,
               typename enable_if<!is_integral<_Fp>::value>::type* = 0);

    template<class _Alloc>
      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
      function(allocator_arg_t, const _Alloc&) : __f_(0) {}
    template<class _Alloc>
      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
      function(allocator_arg_t, const _Alloc&, nullptr_t) : __f_(0) {}
    template<class _Alloc>
      function(allocator_arg_t, const _Alloc&, const function&);
    template<class _Fp, class _Alloc>
      function(allocator_arg_t, const _Alloc& __a, _Fp __f,
               typename enable_if<!is_integral<_Fp>::value>::type* = 0);

    function& operator=(const function&);
    function& operator=(nullptr_t);
    template<class _Fp>
      typename enable_if
      <
        !is_integral<_Fp>::value,
        function&
      >::type
      operator=(_Fp);

    ~function();


    void swap(function&);
    template<class _Fp, class _Alloc>
      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
      void assign(_Fp __f, const _Alloc& __a)
        {function(allocator_arg, __a, __f).swap(*this);}


    operator bool() const {return __f_;}

private:

    template<class _R2, class _B0, class _B1>
      bool operator==(const function<_R2(_B0, _B1)>&) const;
    template<class _R2, class _B0, class _B1>
      bool operator!=(const function<_R2(_B0, _B1)>&) const;
public:

    _Rp operator()(_A0, _A1) const;



    const std::type_info& target_type() const;
    template <typename _Tp> _Tp* target();
    template <typename _Tp> const _Tp* target() const;

};

template<class _Rp, class _A0, class _A1>
function<_Rp(_A0, _A1)>::function(const function& __f)
{
    if (__f.__f_ == 0)
        __f_ = 0;
    else if (__f.__f_ == (const __base*)&__f.__buf_)
    {
        __f_ = (__base*)&__buf_;
        __f.__f_->__clone(__f_);
    }
    else
        __f_ = __f.__f_->__clone();
}

template<class _Rp, class _A0, class _A1>
template<class _Alloc>
function<_Rp(_A0, _A1)>::function(allocator_arg_t, const _Alloc&, const function& __f)
{
    if (__f.__f_ == 0)
        __f_ = 0;
    else if (__f.__f_ == (const __base*)&__f.__buf_)
    {
        __f_ = (__base*)&__buf_;
        __f.__f_->__clone(__f_);
    }
    else
        __f_ = __f.__f_->__clone();
}

template<class _Rp, class _A0, class _A1>
template <class _Fp>
function<_Rp(_A0, _A1)>::function(_Fp __f,
                                 typename enable_if<!is_integral<_Fp>::value>::type*)
    : __f_(0)
{
    if (__function::__not_null(__f))
    {
        typedef __function::__func<_Fp, allocator<_Fp>, _Rp(_A0, _A1)> _FF;
        if (sizeof(_FF) <= sizeof(__buf_))
        {
            __f_ = (__base*)&__buf_;
            ::new (__f_) _FF(__f);
        }
        else
        {
            typedef allocator<_FF> _Ap;
            _Ap __a;
            typedef __allocator_destructor<_Ap> _Dp;
            unique_ptr<__base, _Dp> __hold(__a.allocate(1), _Dp(__a, 1));
            ::new (__hold.get()) _FF(__f, allocator<_Fp>(__a));
            __f_ = __hold.release();
        }
    }
}

template<class _Rp, class _A0, class _A1>
template <class _Fp, class _Alloc>
function<_Rp(_A0, _A1)>::function(allocator_arg_t, const _Alloc& __a0, _Fp __f,
                                 typename enable_if<!is_integral<_Fp>::value>::type*)
    : __f_(0)
{
    typedef allocator_traits<_Alloc> __alloc_traits;
    if (__function::__not_null(__f))
    {
        typedef __function::__func<_Fp, _Alloc, _Rp(_A0, _A1)> _FF;
        if (sizeof(_FF) <= sizeof(__buf_))
        {
            __f_ = (__base*)&__buf_;
            ::new (__f_) _FF(__f, __a0);
        }
        else
        {
            typedef typename __rebind_alloc_helper<__alloc_traits, _FF>::type _Ap;
            _Ap __a(__a0);
            typedef __allocator_destructor<_Ap> _Dp;
            unique_ptr<__base, _Dp> __hold(__a.allocate(1), _Dp(__a, 1));
            ::new (__hold.get()) _FF(__f, _Alloc(__a));
            __f_ = __hold.release();
        }
    }
}

template<class _Rp, class _A0, class _A1>
function<_Rp(_A0, _A1)>&
function<_Rp(_A0, _A1)>::operator=(const function& __f)
{
    if (__f)
        function(__f).swap(*this);
    else
        *this = std::__1::__get_nullptr_t();
    return *this;
}

template<class _Rp, class _A0, class _A1>
function<_Rp(_A0, _A1)>&
function<_Rp(_A0, _A1)>::operator=(nullptr_t)
{
    __base* __t = __f_;
    __f_ = 0;
    if (__t == (__base*)&__buf_)
        __t->destroy();
    else if (__t)
        __t->destroy_deallocate();
    return *this;
}

template<class _Rp, class _A0, class _A1>
template <class _Fp>
typename enable_if
<
    !is_integral<_Fp>::value,
    function<_Rp(_A0, _A1)>&
>::type
function<_Rp(_A0, _A1)>::operator=(_Fp __f)
{
    function(std::__1::move(__f)).swap(*this);
    return *this;
}

template<class _Rp, class _A0, class _A1>
function<_Rp(_A0, _A1)>::~function()
{
    if (__f_ == (__base*)&__buf_)
        __f_->destroy();
    else if (__f_)
        __f_->destroy_deallocate();
}

template<class _Rp, class _A0, class _A1>
void
function<_Rp(_A0, _A1)>::swap(function& __f)
{
    if (std::__1::addressof(__f) == this)
      return;
    if (__f_ == (__base*)&__buf_ && __f.__f_ == (__base*)&__f.__buf_)
    {
        typename aligned_storage<sizeof(__buf_)>::type __tempbuf;
        __base* __t = (__base*)&__tempbuf;
        __f_->__clone(__t);
        __f_->destroy();
        __f_ = 0;
        __f.__f_->__clone((__base*)&__buf_);
        __f.__f_->destroy();
        __f.__f_ = 0;
        __f_ = (__base*)&__buf_;
        __t->__clone((__base*)&__f.__buf_);
        __t->destroy();
        __f.__f_ = (__base*)&__f.__buf_;
    }
    else if (__f_ == (__base*)&__buf_)
    {
        __f_->__clone((__base*)&__f.__buf_);
        __f_->destroy();
        __f_ = __f.__f_;
        __f.__f_ = (__base*)&__f.__buf_;
    }
    else if (__f.__f_ == (__base*)&__f.__buf_)
    {
        __f.__f_->__clone((__base*)&__buf_);
        __f.__f_->destroy();
        __f.__f_ = __f_;
        __f_ = (__base*)&__buf_;
    }
    else
        std::__1::swap(__f_, __f.__f_);
}

template<class _Rp, class _A0, class _A1>
_Rp
function<_Rp(_A0, _A1)>::operator()(_A0 __a0, _A1 __a1) const
{
    if (__f_ == 0)
        __throw_bad_function_call();
    return (*__f_)(__a0, __a1);
}



template<class _Rp, class _A0, class _A1>
const std::type_info&
function<_Rp(_A0, _A1)>::target_type() const
{
    if (__f_ == 0)
        return typeid(void);
    return __f_->target_type();
}

template<class _Rp, class _A0, class _A1>
template <typename _Tp>
_Tp*
function<_Rp(_A0, _A1)>::target()
{
    if (__f_ == 0)
        return (_Tp*)0;
    return (_Tp*) const_cast<void *>(__f_->target(typeid(_Tp)));
}

template<class _Rp, class _A0, class _A1>
template <typename _Tp>
const _Tp*
function<_Rp(_A0, _A1)>::target() const
{
    if (__f_ == 0)
        return (const _Tp*)0;
    return (const _Tp*)__f_->target(typeid(_Tp));
}



template<class _Rp, class _A0, class _A1, class _A2>
class __attribute__ ((__type_visibility__("default"))) function<_Rp(_A0, _A1, _A2)>
{
    typedef __function::__base<_Rp(_A0, _A1, _A2)> __base;
    aligned_storage<3*sizeof(void*)>::type __buf_;
    __base* __f_;

public:
    typedef _Rp result_type;


    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit function() : __f_(0) {}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) function(nullptr_t) : __f_(0) {}
    function(const function&);
    template<class _Fp>
      function(_Fp,
               typename enable_if<!is_integral<_Fp>::value>::type* = 0);

    template<class _Alloc>
      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
      function(allocator_arg_t, const _Alloc&) : __f_(0) {}
    template<class _Alloc>
      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
      function(allocator_arg_t, const _Alloc&, nullptr_t) : __f_(0) {}
    template<class _Alloc>
      function(allocator_arg_t, const _Alloc&, const function&);
    template<class _Fp, class _Alloc>
      function(allocator_arg_t, const _Alloc& __a, _Fp __f,
               typename enable_if<!is_integral<_Fp>::value>::type* = 0);

    function& operator=(const function&);
    function& operator=(nullptr_t);
    template<class _Fp>
      typename enable_if
      <
        !is_integral<_Fp>::value,
        function&
      >::type
      operator=(_Fp);

    ~function();


    void swap(function&);
    template<class _Fp, class _Alloc>
      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
      void assign(_Fp __f, const _Alloc& __a)
        {function(allocator_arg, __a, __f).swap(*this);}


    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) operator bool() const {return __f_;}

private:

    template<class _R2, class _B0, class _B1, class _B2>
      bool operator==(const function<_R2(_B0, _B1, _B2)>&) const;
    template<class _R2, class _B0, class _B1, class _B2>
      bool operator!=(const function<_R2(_B0, _B1, _B2)>&) const;
public:

    _Rp operator()(_A0, _A1, _A2) const;



    const std::type_info& target_type() const;
    template <typename _Tp> _Tp* target();
    template <typename _Tp> const _Tp* target() const;

};

template<class _Rp, class _A0, class _A1, class _A2>
function<_Rp(_A0, _A1, _A2)>::function(const function& __f)
{
    if (__f.__f_ == 0)
        __f_ = 0;
    else if (__f.__f_ == (const __base*)&__f.__buf_)
    {
        __f_ = (__base*)&__buf_;
        __f.__f_->__clone(__f_);
    }
    else
        __f_ = __f.__f_->__clone();
}

template<class _Rp, class _A0, class _A1, class _A2>
template<class _Alloc>
function<_Rp(_A0, _A1, _A2)>::function(allocator_arg_t, const _Alloc&,
                                      const function& __f)
{
    if (__f.__f_ == 0)
        __f_ = 0;
    else if (__f.__f_ == (const __base*)&__f.__buf_)
    {
        __f_ = (__base*)&__buf_;
        __f.__f_->__clone(__f_);
    }
    else
        __f_ = __f.__f_->__clone();
}

template<class _Rp, class _A0, class _A1, class _A2>
template <class _Fp>
function<_Rp(_A0, _A1, _A2)>::function(_Fp __f,
                                     typename enable_if<!is_integral<_Fp>::value>::type*)
    : __f_(0)
{
    if (__function::__not_null(__f))
    {
        typedef __function::__func<_Fp, allocator<_Fp>, _Rp(_A0, _A1, _A2)> _FF;
        if (sizeof(_FF) <= sizeof(__buf_))
        {
            __f_ = (__base*)&__buf_;
            ::new (__f_) _FF(__f);
        }
        else
        {
            typedef allocator<_FF> _Ap;
            _Ap __a;
            typedef __allocator_destructor<_Ap> _Dp;
            unique_ptr<__base, _Dp> __hold(__a.allocate(1), _Dp(__a, 1));
            ::new (__hold.get()) _FF(__f, allocator<_Fp>(__a));
            __f_ = __hold.release();
        }
    }
}

template<class _Rp, class _A0, class _A1, class _A2>
template <class _Fp, class _Alloc>
function<_Rp(_A0, _A1, _A2)>::function(allocator_arg_t, const _Alloc& __a0, _Fp __f,
                                     typename enable_if<!is_integral<_Fp>::value>::type*)
    : __f_(0)
{
    typedef allocator_traits<_Alloc> __alloc_traits;
    if (__function::__not_null(__f))
    {
        typedef __function::__func<_Fp, _Alloc, _Rp(_A0, _A1, _A2)> _FF;
        if (sizeof(_FF) <= sizeof(__buf_))
        {
            __f_ = (__base*)&__buf_;
            ::new (__f_) _FF(__f, __a0);
        }
        else
        {
            typedef typename __rebind_alloc_helper<__alloc_traits, _FF>::type _Ap;
            _Ap __a(__a0);
            typedef __allocator_destructor<_Ap> _Dp;
            unique_ptr<__base, _Dp> __hold(__a.allocate(1), _Dp(__a, 1));
            ::new (__hold.get()) _FF(__f, _Alloc(__a));
            __f_ = __hold.release();
        }
    }
}

template<class _Rp, class _A0, class _A1, class _A2>
function<_Rp(_A0, _A1, _A2)>&
function<_Rp(_A0, _A1, _A2)>::operator=(const function& __f)
{
    if (__f)
        function(__f).swap(*this);
    else
        *this = std::__1::__get_nullptr_t();
    return *this;
}

template<class _Rp, class _A0, class _A1, class _A2>
function<_Rp(_A0, _A1, _A2)>&
function<_Rp(_A0, _A1, _A2)>::operator=(nullptr_t)
{
    __base* __t = __f_;
    __f_ = 0;
    if (__t == (__base*)&__buf_)
        __t->destroy();
    else if (__t)
        __t->destroy_deallocate();
    return *this;
}

template<class _Rp, class _A0, class _A1, class _A2>
template <class _Fp>
typename enable_if
<
    !is_integral<_Fp>::value,
    function<_Rp(_A0, _A1, _A2)>&
>::type
function<_Rp(_A0, _A1, _A2)>::operator=(_Fp __f)
{
    function(std::__1::move(__f)).swap(*this);
    return *this;
}

template<class _Rp, class _A0, class _A1, class _A2>
function<_Rp(_A0, _A1, _A2)>::~function()
{
    if (__f_ == (__base*)&__buf_)
        __f_->destroy();
    else if (__f_)
        __f_->destroy_deallocate();
}

template<class _Rp, class _A0, class _A1, class _A2>
void
function<_Rp(_A0, _A1, _A2)>::swap(function& __f)
{
    if (std::__1::addressof(__f) == this)
      return;
    if (__f_ == (__base*)&__buf_ && __f.__f_ == (__base*)&__f.__buf_)
    {
        typename aligned_storage<sizeof(__buf_)>::type __tempbuf;
        __base* __t = (__base*)&__tempbuf;
        __f_->__clone(__t);
        __f_->destroy();
        __f_ = 0;
        __f.__f_->__clone((__base*)&__buf_);
        __f.__f_->destroy();
        __f.__f_ = 0;
        __f_ = (__base*)&__buf_;
        __t->__clone((__base*)&__f.__buf_);
        __t->destroy();
        __f.__f_ = (__base*)&__f.__buf_;
    }
    else if (__f_ == (__base*)&__buf_)
    {
        __f_->__clone((__base*)&__f.__buf_);
        __f_->destroy();
        __f_ = __f.__f_;
        __f.__f_ = (__base*)&__f.__buf_;
    }
    else if (__f.__f_ == (__base*)&__f.__buf_)
    {
        __f.__f_->__clone((__base*)&__buf_);
        __f.__f_->destroy();
        __f.__f_ = __f_;
        __f_ = (__base*)&__buf_;
    }
    else
        std::__1::swap(__f_, __f.__f_);
}

template<class _Rp, class _A0, class _A1, class _A2>
_Rp
function<_Rp(_A0, _A1, _A2)>::operator()(_A0 __a0, _A1 __a1, _A2 __a2) const
{
    if (__f_ == 0)
        __throw_bad_function_call();
    return (*__f_)(__a0, __a1, __a2);
}



template<class _Rp, class _A0, class _A1, class _A2>
const std::type_info&
function<_Rp(_A0, _A1, _A2)>::target_type() const
{
    if (__f_ == 0)
        return typeid(void);
    return __f_->target_type();
}

template<class _Rp, class _A0, class _A1, class _A2>
template <typename _Tp>
_Tp*
function<_Rp(_A0, _A1, _A2)>::target()
{
    if (__f_ == 0)
        return (_Tp*)0;
    return (_Tp*) const_cast<void *>(__f_->target(typeid(_Tp)));
}

template<class _Rp, class _A0, class _A1, class _A2>
template <typename _Tp>
const _Tp*
function<_Rp(_A0, _A1, _A2)>::target() const
{
    if (__f_ == 0)
        return (const _Tp*)0;
    return (const _Tp*)__f_->target(typeid(_Tp));
}



template <class _Fp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator==(const function<_Fp>& __f, nullptr_t) {return !__f;}

template <class _Fp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator==(nullptr_t, const function<_Fp>& __f) {return !__f;}

template <class _Fp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(const function<_Fp>& __f, nullptr_t) {return (bool)__f;}

template <class _Fp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(nullptr_t, const function<_Fp>& __f) {return (bool)__f;}

template <class _Fp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
swap(function<_Fp>& __x, function<_Fp>& __y)
{return __x.swap(__y);}








template<class _Tp> struct __is_bind_expression : public false_type {};
template<class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_bind_expression
    : public __is_bind_expression<typename remove_cv<_Tp>::type> {};






template<class _Tp> struct __is_placeholder : public integral_constant<int, 0> {};
template<class _Tp> struct __attribute__ ((__type_visibility__("default"))) is_placeholder
    : public __is_placeholder<typename remove_cv<_Tp>::type> {};






namespace placeholders
{

template <int _Np> struct __ph {};


__attribute__ ((__visibility__("default"))) extern const __ph<1> _1;
__attribute__ ((__visibility__("default"))) extern const __ph<2> _2;
__attribute__ ((__visibility__("default"))) extern const __ph<3> _3;
__attribute__ ((__visibility__("default"))) extern const __ph<4> _4;
__attribute__ ((__visibility__("default"))) extern const __ph<5> _5;
__attribute__ ((__visibility__("default"))) extern const __ph<6> _6;
__attribute__ ((__visibility__("default"))) extern const __ph<7> _7;
__attribute__ ((__visibility__("default"))) extern const __ph<8> _8;
__attribute__ ((__visibility__("default"))) extern const __ph<9> _9;
__attribute__ ((__visibility__("default"))) extern const __ph<10> _10;

}

template<int _Np>
struct __is_placeholder<placeholders::__ph<_Np> >
    : public integral_constant<int, _Np> {};

template <class _BinaryPredicate, class _ForwardIterator1, class _ForwardIterator2>
pair<_ForwardIterator1, _ForwardIterator1>
__search(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
         _ForwardIterator2 __first2, _ForwardIterator2 __last2, _BinaryPredicate __pred,
         forward_iterator_tag, forward_iterator_tag)
{
    if (__first2 == __last2)
        return make_pair(__first1, __first1);
    while (true)
    {

        while (true)
        {
            if (__first1 == __last1)
                return make_pair(__last1, __last1);
            if (__pred(*__first1, *__first2))
                break;
            ++__first1;
        }

        _ForwardIterator1 __m1 = __first1;
        _ForwardIterator2 __m2 = __first2;
        while (true)
        {
            if (++__m2 == __last2)
                return make_pair(__first1, __m1);
            if (++__m1 == __last1)
                return make_pair(__last1, __last1);
            if (!__pred(*__m1, *__m2))
            {
                ++__first1;
                break;
            }
        }
    }
}

template <class _BinaryPredicate, class _RandomAccessIterator1, class _RandomAccessIterator2>

pair<_RandomAccessIterator1, _RandomAccessIterator1>
__search(_RandomAccessIterator1 __first1, _RandomAccessIterator1 __last1,
         _RandomAccessIterator2 __first2, _RandomAccessIterator2 __last2, _BinaryPredicate __pred,
           random_access_iterator_tag, random_access_iterator_tag)
{
    typedef typename iterator_traits<_RandomAccessIterator1>::difference_type _D1;
    typedef typename iterator_traits<_RandomAccessIterator2>::difference_type _D2;

    const _D2 __len2 = __last2 - __first2;
    if (__len2 == 0)
        return make_pair(__first1, __first1);
    const _D1 __len1 = __last1 - __first1;
    if (__len1 < __len2)
        return make_pair(__last1, __last1);
    const _RandomAccessIterator1 __s = __last1 - (__len2 - 1);

    while (true)
    {
        while (true)
        {
            if (__first1 == __s)
                return make_pair(__last1, __last1);
            if (__pred(*__first1, *__first2))
                break;
            ++__first1;
        }

        _RandomAccessIterator1 __m1 = __first1;
        _RandomAccessIterator2 __m2 = __first2;
         while (true)
         {
             if (++__m2 == __last2)
                 return make_pair(__first1, __first1 + __len2);
             ++__m1;
             if (!__pred(*__m1, *__m2))
             {
                 ++__first1;
                 break;
             }
         }
    }
}

template <class _Container, class _Predicate>
inline void __libcpp_erase_if_container( _Container& __c, _Predicate __pred)
{
 for (typename _Container::iterator __iter = __c.begin(), __last = __c.end(); __iter != __last;)
 {
  if (__pred(*__iter))
   __iter = __c.erase(__iter);
  else
   ++__iter;
 }
}

} }














namespace std { inline namespace __1 {



inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
int __libcpp_ctz(unsigned __x) throw() { return __builtin_ctz(__x); }

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
int __libcpp_ctz(unsigned long __x) throw() { return __builtin_ctzl(__x); }

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
int __libcpp_ctz(unsigned long long __x) throw() { return __builtin_ctzll(__x); }


inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
int __libcpp_clz(unsigned __x) throw() { return __builtin_clz(__x); }

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
int __libcpp_clz(unsigned long __x) throw() { return __builtin_clzl(__x); }

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
int __libcpp_clz(unsigned long long __x) throw() { return __builtin_clzll(__x); }


inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
int __libcpp_popcount(unsigned __x) throw() { return __builtin_popcount(__x); }

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
int __libcpp_popcount(unsigned long __x) throw() { return __builtin_popcountl(__x); }

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
int __libcpp_popcount(unsigned long long __x) throw() { return __builtin_popcountll(__x); }

template <class _Tp>
using __bitop_unsigned_integer = integral_constant<bool,
         is_integral<_Tp>::value &&
         is_unsigned<_Tp>::value &&
        _IsNotSame<typename remove_cv<_Tp>::type, bool>::value &&
        _IsNotSame<typename remove_cv<_Tp>::type, signed char>::value &&
        _IsNotSame<typename remove_cv<_Tp>::type, wchar_t>::value &&
        _IsNotSame<typename remove_cv<_Tp>::type, char16_t>::value &&
        _IsNotSame<typename remove_cv<_Tp>::type, char32_t>::value
    >;


template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp __rotl(_Tp __t, unsigned int __cnt) throw()
{
    _Static_assert(__bitop_unsigned_integer<_Tp>::value, "__rotl requires unsigned");
    const unsigned int __dig = numeric_limits<_Tp>::digits;
    if ((__cnt % __dig) == 0)
        return __t;
    return (__t << (__cnt % __dig)) | (__t >> (__dig - (__cnt % __dig)));
}


template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Tp __rotr(_Tp __t, unsigned int __cnt) throw()
{
    _Static_assert(__bitop_unsigned_integer<_Tp>::value, "__rotr requires unsigned");
    const unsigned int __dig = numeric_limits<_Tp>::digits;
    if ((__cnt % __dig) == 0)
        return __t;
    return (__t >> (__cnt % __dig)) | (__t << (__dig - (__cnt % __dig)));
}



template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
int __countr_zero(_Tp __t) throw()
{
    _Static_assert(__bitop_unsigned_integer<_Tp>::value, "__countr_zero requires unsigned");
    if (__t == 0)
        return numeric_limits<_Tp>::digits;

    if (sizeof(_Tp) <= sizeof(unsigned int))
        return __libcpp_ctz(static_cast<unsigned int>(__t));
    else if (sizeof(_Tp) <= sizeof(unsigned long))
        return __libcpp_ctz(static_cast<unsigned long>(__t));
    else if (sizeof(_Tp) <= sizeof(unsigned long long))
        return __libcpp_ctz(static_cast<unsigned long long>(__t));
    else
    {
        int __ret = 0;
        int __iter = 0;
        const unsigned int __ulldigits = numeric_limits<unsigned long long>::digits;
        while ((__iter = __libcpp_ctz(static_cast<unsigned long long>(__t))) == __ulldigits)
        {
            __ret += __iter;
            __t >>= __ulldigits;
        }
        return __ret + __iter;
    }
}

template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
int __countl_zero(_Tp __t) throw()
{
    _Static_assert(__bitop_unsigned_integer<_Tp>::value, "__countl_zero requires unsigned");
    if (__t == 0)
        return numeric_limits<_Tp>::digits;

    if (sizeof(_Tp) <= sizeof(unsigned int))
        return __libcpp_clz(static_cast<unsigned int>(__t))
              - (numeric_limits<unsigned int>::digits - numeric_limits<_Tp>::digits);
    else if (sizeof(_Tp) <= sizeof(unsigned long))
        return __libcpp_clz(static_cast<unsigned long>(__t))
              - (numeric_limits<unsigned long>::digits - numeric_limits<_Tp>::digits);
    else if (sizeof(_Tp) <= sizeof(unsigned long long))
        return __libcpp_clz(static_cast<unsigned long long>(__t))
              - (numeric_limits<unsigned long long>::digits - numeric_limits<_Tp>::digits);
    else
    {
        int __ret = 0;
        int __iter = 0;
        const unsigned int __ulldigits = numeric_limits<unsigned long long>::digits;
        while (true) {
            __t = __rotr(__t, __ulldigits);
            if ((__iter = __countl_zero(static_cast<unsigned long long>(__t))) != __ulldigits)
                break;
            __ret += __iter;
            }
        return __ret + __iter;
    }
}

template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
int __countl_one(_Tp __t) throw()
{
    _Static_assert(__bitop_unsigned_integer<_Tp>::value, "__countl_one requires unsigned");
    return __t != numeric_limits<_Tp>::max()
        ? __countl_zero(static_cast<_Tp>(~__t))
        : numeric_limits<_Tp>::digits;
}


template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
int __countr_one(_Tp __t) throw()
{
    _Static_assert(__bitop_unsigned_integer<_Tp>::value, "__countr_one requires unsigned");
    return __t != numeric_limits<_Tp>::max()
        ? __countr_zero(static_cast<_Tp>(~__t))
        : numeric_limits<_Tp>::digits;
}


template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
int
__popcount(_Tp __t) throw()
{
    _Static_assert(__bitop_unsigned_integer<_Tp>::value, "__libcpp_popcount requires unsigned");
    if (sizeof(_Tp) <= sizeof(unsigned int))
        return __libcpp_popcount(static_cast<unsigned int>(__t));
    else if (sizeof(_Tp) <= sizeof(unsigned long))
        return __libcpp_popcount(static_cast<unsigned long>(__t));
    else if (sizeof(_Tp) <= sizeof(unsigned long long))
        return __libcpp_popcount(static_cast<unsigned long long>(__t));
    else
    {
        int __ret = 0;
        while (__t != 0)
        {
            __ret += __libcpp_popcount(static_cast<unsigned long long>(__t));
            __t >>= numeric_limits<unsigned long long>::digits;
        }
        return __ret;
    }
}



template<class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
unsigned __bit_log2(_Tp __t) throw()
{
    _Static_assert(__bitop_unsigned_integer<_Tp>::value, "__bit_log2 requires unsigned");
    return std::numeric_limits<_Tp>::digits - 1 - __countl_zero(__t);
}

template <class _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool __ispow2(_Tp __t) throw()
{
    _Static_assert(__bitop_unsigned_integer<_Tp>::value, "__ispow2 requires unsigned");
 return __t != 0 && (((__t & (__t - 1)) == 0));
}

} }









namespace std { inline namespace __1 {




template <class _T1, class _T2 = _T1>
struct __equal_to
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) bool operator()(const _T1& __x, const _T1& __y) const {return __x == __y;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) bool operator()(const _T1& __x, const _T2& __y) const {return __x == __y;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) bool operator()(const _T2& __x, const _T1& __y) const {return __x == __y;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) bool operator()(const _T2& __x, const _T2& __y) const {return __x == __y;}
};

template <class _T1>
struct __equal_to<_T1, _T1>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _T1& __x, const _T1& __y) const {return __x == __y;}
};

template <class _T1>
struct __equal_to<const _T1, _T1>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _T1& __x, const _T1& __y) const {return __x == __y;}
};

template <class _T1>
struct __equal_to<_T1, const _T1>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _T1& __x, const _T1& __y) const {return __x == __y;}
};

template <class _T1, class _T2 = _T1>
struct __less
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _T1& __x, const _T1& __y) const {return __x < __y;}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _T1& __x, const _T2& __y) const {return __x < __y;}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _T2& __x, const _T1& __y) const {return __x < __y;}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _T2& __x, const _T2& __y) const {return __x < __y;}
};

template <class _T1>
struct __less<_T1, _T1>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _T1& __x, const _T1& __y) const {return __x < __y;}
};

template <class _T1>
struct __less<const _T1, _T1>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _T1& __x, const _T1& __y) const {return __x < __y;}
};

template <class _T1>
struct __less<_T1, const _T1>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _T1& __x, const _T1& __y) const {return __x < __y;}
};

template <class _Predicate>
class __invert
{
private:
    _Predicate __p_;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) __invert() {}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    explicit __invert(_Predicate __p) : __p_(__p) {}

    template <class _T1>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _T1& __x) {return !__p_(__x);}

    template <class _T1, class _T2>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const _T1& __x, const _T2& __y) {return __p_(__y, __x);}
};



template <typename _Integral>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_integral<_Integral>::value,
    _Integral
>::type
__half_positive(_Integral __value)
{
    return static_cast<_Integral>(static_cast<typename make_unsigned<_Integral>::type>(__value) / 2);
}

template <typename _Tp>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    !is_integral<_Tp>::value,
    _Tp
>::type
__half_positive(_Tp __value)
{
    return __value / 2;
}

template <class _Comp>
struct __comp_ref_type {



  typedef typename add_lvalue_reference<_Comp>::type type;



};



template <class _InputIterator, class _Predicate>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
all_of(_InputIterator __first, _InputIterator __last, _Predicate __pred)
{
    for (; __first != __last; ++__first)
        if (!__pred(*__first))
            return false;
    return true;
}



template <class _InputIterator, class _Predicate>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
any_of(_InputIterator __first, _InputIterator __last, _Predicate __pred)
{
    for (; __first != __last; ++__first)
        if (__pred(*__first))
            return true;
    return false;
}



template <class _InputIterator, class _Predicate>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
none_of(_InputIterator __first, _InputIterator __last, _Predicate __pred)
{
    for (; __first != __last; ++__first)
        if (__pred(*__first))
            return false;
    return true;
}



template <class _InputIterator, class _Function>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Function
for_each(_InputIterator __first, _InputIterator __last, _Function __f)
{
    for (; __first != __last; ++__first)
        __f(*__first);
    return __f;
}

template <class _InputIterator, class _Tp>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_InputIterator
find(_InputIterator __first, _InputIterator __last, const _Tp& __value_)
{
    for (; __first != __last; ++__first)
        if (*__first == __value_)
            break;
    return __first;
}



template <class _InputIterator, class _Predicate>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_InputIterator
find_if(_InputIterator __first, _InputIterator __last, _Predicate __pred)
{
    for (; __first != __last; ++__first)
        if (__pred(*__first))
            break;
    return __first;
}



template<class _InputIterator, class _Predicate>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_InputIterator
find_if_not(_InputIterator __first, _InputIterator __last, _Predicate __pred)
{
    for (; __first != __last; ++__first)
        if (!__pred(*__first))
            break;
    return __first;
}



template <class _BinaryPredicate, class _ForwardIterator1, class _ForwardIterator2>
                              _ForwardIterator1
__find_end(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
           _ForwardIterator2 __first2, _ForwardIterator2 __last2, _BinaryPredicate __pred,
           forward_iterator_tag, forward_iterator_tag)
{

    _ForwardIterator1 __r = __last1;
    if (__first2 == __last2)
        return __r;
    while (true)
    {
        while (true)
        {
            if (__first1 == __last1)
                return __r;
            if (__pred(*__first1, *__first2))
                break;
            ++__first1;
        }

        _ForwardIterator1 __m1 = __first1;
        _ForwardIterator2 __m2 = __first2;
        while (true)
        {
            if (++__m2 == __last2)
            {
                __r = __first1;
                ++__first1;
                break;
            }
            if (++__m1 == __last1)
                return __r;
            if (!__pred(*__m1, *__m2))
            {
                ++__first1;
                break;
            }
        }
    }
}

template <class _BinaryPredicate, class _BidirectionalIterator1, class _BidirectionalIterator2>
                              _BidirectionalIterator1
__find_end(_BidirectionalIterator1 __first1, _BidirectionalIterator1 __last1,
           _BidirectionalIterator2 __first2, _BidirectionalIterator2 __last2, _BinaryPredicate __pred,
           bidirectional_iterator_tag, bidirectional_iterator_tag)
{

    if (__first2 == __last2)
        return __last1;
    _BidirectionalIterator1 __l1 = __last1;
    _BidirectionalIterator2 __l2 = __last2;
    --__l2;
    while (true)
    {

        while (true)
        {
            if (__first1 == __l1)
                return __last1;
            if (__pred(*--__l1, *__l2))
                break;
        }

        _BidirectionalIterator1 __m1 = __l1;
        _BidirectionalIterator2 __m2 = __l2;
        while (true)
        {
            if (__m2 == __first2)
                return __m1;
            if (__m1 == __first1)
                return __last1;
            if (!__pred(*--__m1, *--__m2))
            {
                break;
            }
        }
    }
}

template <class _BinaryPredicate, class _RandomAccessIterator1, class _RandomAccessIterator2>
                              _RandomAccessIterator1
__find_end(_RandomAccessIterator1 __first1, _RandomAccessIterator1 __last1,
           _RandomAccessIterator2 __first2, _RandomAccessIterator2 __last2, _BinaryPredicate __pred,
           random_access_iterator_tag, random_access_iterator_tag)
{

    typename iterator_traits<_RandomAccessIterator2>::difference_type __len2 = __last2 - __first2;
    if (__len2 == 0)
        return __last1;
    typename iterator_traits<_RandomAccessIterator1>::difference_type __len1 = __last1 - __first1;
    if (__len1 < __len2)
        return __last1;
    const _RandomAccessIterator1 __s = __first1 + (__len2 - 1);
    _RandomAccessIterator1 __l1 = __last1;
    _RandomAccessIterator2 __l2 = __last2;
    --__l2;
    while (true)
    {
        while (true)
        {
            if (__s == __l1)
                return __last1;
            if (__pred(*--__l1, *__l2))
                break;
        }
        _RandomAccessIterator1 __m1 = __l1;
        _RandomAccessIterator2 __m2 = __l2;
        while (true)
        {
            if (__m2 == __first2)
                return __m1;

            if (!__pred(*--__m1, *--__m2))
            {
                break;
            }
        }
    }
}

template <class _ForwardIterator1, class _ForwardIterator2, class _BinaryPredicate>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator1
find_end(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
         _ForwardIterator2 __first2, _ForwardIterator2 __last2, _BinaryPredicate __pred)
{
    return std::__1::__find_end<typename add_lvalue_reference<_BinaryPredicate>::type>
                         (__first1, __last1, __first2, __last2, __pred,
                          typename iterator_traits<_ForwardIterator1>::iterator_category(),
                          typename iterator_traits<_ForwardIterator2>::iterator_category());
}

template <class _ForwardIterator1, class _ForwardIterator2>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator1
find_end(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
         _ForwardIterator2 __first2, _ForwardIterator2 __last2)
{
    typedef typename iterator_traits<_ForwardIterator1>::value_type __v1;
    typedef typename iterator_traits<_ForwardIterator2>::value_type __v2;
    return std::__1::find_end(__first1, __last1, __first2, __last2, __equal_to<__v1, __v2>());
}



template <class _ForwardIterator1, class _ForwardIterator2, class _BinaryPredicate>
                              _ForwardIterator1
__find_first_of_ce(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
              _ForwardIterator2 __first2, _ForwardIterator2 __last2, _BinaryPredicate __pred)
{
    for (; __first1 != __last1; ++__first1)
        for (_ForwardIterator2 __j = __first2; __j != __last2; ++__j)
            if (__pred(*__first1, *__j))
                return __first1;
    return __last1;
}


template <class _ForwardIterator1, class _ForwardIterator2, class _BinaryPredicate>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator1
find_first_of(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
              _ForwardIterator2 __first2, _ForwardIterator2 __last2, _BinaryPredicate __pred)
{
    return std::__1::__find_first_of_ce(__first1, __last1, __first2, __last2, __pred);
}

template <class _ForwardIterator1, class _ForwardIterator2>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator1
find_first_of(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
              _ForwardIterator2 __first2, _ForwardIterator2 __last2)
{
    typedef typename iterator_traits<_ForwardIterator1>::value_type __v1;
    typedef typename iterator_traits<_ForwardIterator2>::value_type __v2;
    return std::__1::__find_first_of_ce(__first1, __last1, __first2, __last2, __equal_to<__v1, __v2>());
}



template <class _ForwardIterator, class _BinaryPredicate>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator
adjacent_find(_ForwardIterator __first, _ForwardIterator __last, _BinaryPredicate __pred)
{
    if (__first != __last)
    {
        _ForwardIterator __i = __first;
        while (++__i != __last)
        {
            if (__pred(*__first, *__i))
                return __first;
            __first = __i;
        }
    }
    return __last;
}

template <class _ForwardIterator>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator
adjacent_find(_ForwardIterator __first, _ForwardIterator __last)
{
    typedef typename iterator_traits<_ForwardIterator>::value_type __v;
    return std::__1::adjacent_find(__first, __last, __equal_to<__v>());
}



template <class _InputIterator, class _Tp>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename iterator_traits<_InputIterator>::difference_type
count(_InputIterator __first, _InputIterator __last, const _Tp& __value_)
{
    typename iterator_traits<_InputIterator>::difference_type __r(0);
    for (; __first != __last; ++__first)
        if (*__first == __value_)
            ++__r;
    return __r;
}



template <class _InputIterator, class _Predicate>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename iterator_traits<_InputIterator>::difference_type
count_if(_InputIterator __first, _InputIterator __last, _Predicate __pred)
{
    typename iterator_traits<_InputIterator>::difference_type __r(0);
    for (; __first != __last; ++__first)
        if (__pred(*__first))
            ++__r;
    return __r;
}



template <class _InputIterator1, class _InputIterator2, class _BinaryPredicate>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
pair<_InputIterator1, _InputIterator2>
mismatch(_InputIterator1 __first1, _InputIterator1 __last1,
         _InputIterator2 __first2, _BinaryPredicate __pred)
{
    for (; __first1 != __last1; ++__first1, (void) ++__first2)
        if (!__pred(*__first1, *__first2))
            break;
    return pair<_InputIterator1, _InputIterator2>(__first1, __first2);
}

template <class _InputIterator1, class _InputIterator2>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
pair<_InputIterator1, _InputIterator2>
mismatch(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2)
{
    typedef typename iterator_traits<_InputIterator1>::value_type __v1;
    typedef typename iterator_traits<_InputIterator2>::value_type __v2;
    return std::__1::mismatch(__first1, __last1, __first2, __equal_to<__v1, __v2>());
}

template <class _InputIterator1, class _InputIterator2, class _BinaryPredicate>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
equal(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _BinaryPredicate __pred)
{
    for (; __first1 != __last1; ++__first1, (void) ++__first2)
        if (!__pred(*__first1, *__first2))
            return false;
    return true;
}

template <class _InputIterator1, class _InputIterator2>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
equal(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2)
{
    typedef typename iterator_traits<_InputIterator1>::value_type __v1;
    typedef typename iterator_traits<_InputIterator2>::value_type __v2;
    return std::__1::equal(__first1, __last1, __first2, __equal_to<__v1, __v2>());
}

template<class _ForwardIterator1, class _ForwardIterator2, class _BinaryPredicate>
                                                    bool
is_permutation(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
               _ForwardIterator2 __first2, _BinaryPredicate __pred)
{

    for (; __first1 != __last1; ++__first1, (void) ++__first2)
        if (!__pred(*__first1, *__first2))
            break;
    if (__first1 == __last1)
        return true;


    typedef typename iterator_traits<_ForwardIterator1>::difference_type _D1;
    _D1 __l1 = std::__1::distance(__first1, __last1);
    if (__l1 == _D1(1))
        return false;
    _ForwardIterator2 __last2 = std::__1::next(__first2, __l1);


    for (_ForwardIterator1 __i = __first1; __i != __last1; ++__i)
    {

        _ForwardIterator1 __match = __first1;
        for (; __match != __i; ++__match)
            if (__pred(*__match, *__i))
                break;
        if (__match == __i) {

            _D1 __c2 = 0;
            for (_ForwardIterator2 __j = __first2; __j != __last2; ++__j)
                if (__pred(*__i, *__j))
                    ++__c2;
            if (__c2 == 0)
                return false;

            _D1 __c1 = 1;
            for (_ForwardIterator1 __j = std::__1::next(__i); __j != __last1; ++__j)
                if (__pred(*__i, *__j))
                    ++__c1;
            if (__c1 != __c2)
                return false;
        }
    }
    return true;
}

template<class _ForwardIterator1, class _ForwardIterator2>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
is_permutation(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
               _ForwardIterator2 __first2)
{
    typedef typename iterator_traits<_ForwardIterator1>::value_type __v1;
    typedef typename iterator_traits<_ForwardIterator2>::value_type __v2;
    return std::__1::is_permutation(__first1, __last1, __first2, __equal_to<__v1, __v2>());
}

template <class _ForwardIterator1, class _ForwardIterator2, class _BinaryPredicate>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator1
search(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
       _ForwardIterator2 __first2, _ForwardIterator2 __last2, _BinaryPredicate __pred)
{
    return std::__1::__search<typename add_lvalue_reference<_BinaryPredicate>::type>
                         (__first1, __last1, __first2, __last2, __pred,
                          typename iterator_traits<_ForwardIterator1>::iterator_category(),
                          typename iterator_traits<_ForwardIterator2>::iterator_category())
            .first;
}

template <class _ForwardIterator1, class _ForwardIterator2>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator1
search(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
       _ForwardIterator2 __first2, _ForwardIterator2 __last2)
{
    typedef typename iterator_traits<_ForwardIterator1>::value_type __v1;
    typedef typename iterator_traits<_ForwardIterator2>::value_type __v2;
    return std::__1::search(__first1, __last1, __first2, __last2, __equal_to<__v1, __v2>());
}

template <class _BinaryPredicate, class _ForwardIterator, class _Size, class _Tp>
                              _ForwardIterator
__search_n(_ForwardIterator __first, _ForwardIterator __last,
           _Size __count, const _Tp& __value_, _BinaryPredicate __pred, forward_iterator_tag)
{
    if (__count <= 0)
        return __first;
    while (true)
    {

        while (true)
        {
            if (__first == __last)
                return __last;
            if (__pred(*__first, __value_))
                break;
            ++__first;
        }

        _ForwardIterator __m = __first;
        _Size __c(0);
        while (true)
        {
            if (++__c == __count)
                return __first;
            if (++__m == __last)
                return __last;
            if (!__pred(*__m, __value_))
            {
                __first = __m;
                ++__first;
                break;
            }
        }
    }
}

template <class _BinaryPredicate, class _RandomAccessIterator, class _Size, class _Tp>
                              _RandomAccessIterator
__search_n(_RandomAccessIterator __first, _RandomAccessIterator __last,
           _Size __count, const _Tp& __value_, _BinaryPredicate __pred, random_access_iterator_tag)
{
    if (__count <= 0)
        return __first;
    _Size __len = static_cast<_Size>(__last - __first);
    if (__len < __count)
        return __last;
    const _RandomAccessIterator __s = __last - (__count - 1);
    while (true)
    {

        while (true)
        {
            if (__first >= __s)
                return __last;
            if (__pred(*__first, __value_))
                break;
            ++__first;
        }

        _RandomAccessIterator __m = __first;
        _Size __c(0);
        while (true)
        {
            if (++__c == __count)
                return __first;
             ++__m;
            if (!__pred(*__m, __value_))
            {
                __first = __m;
                ++__first;
                break;
            }
        }
    }
}

template <class _ForwardIterator, class _Size, class _Tp, class _BinaryPredicate>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator
search_n(_ForwardIterator __first, _ForwardIterator __last,
         _Size __count, const _Tp& __value_, _BinaryPredicate __pred)
{
    return std::__1::__search_n<typename add_lvalue_reference<_BinaryPredicate>::type>
           (__first, __last, __convert_to_integral(__count), __value_, __pred,
           typename iterator_traits<_ForwardIterator>::iterator_category());
}

template <class _ForwardIterator, class _Size, class _Tp>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator
search_n(_ForwardIterator __first, _ForwardIterator __last, _Size __count, const _Tp& __value_)
{
    typedef typename iterator_traits<_ForwardIterator>::value_type __v;
    return std::__1::search_n(__first, __last, __convert_to_integral(__count),
                           __value_, __equal_to<__v, _Tp>());
}


template <class _Iter>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Iter
__unwrap_iter(_Iter __i)
{
    return __i;
}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_trivially_copy_assignable<_Tp>::value,
    _Tp*
>::type
__unwrap_iter(move_iterator<_Tp*> __i)
{
    return __i.base();
}



template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_trivially_copy_assignable<_Tp>::value,
    _Tp*
>::type
__unwrap_iter(__wrap_iter<_Tp*> __i)
{
    return __i.base();
}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_trivially_copy_assignable<_Tp>::value,
    const _Tp*
>::type
__unwrap_iter(__wrap_iter<const _Tp*> __i)
{
    return __i.base();
}

template <class _InputIterator, class _OutputIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
__copy_constexpr(_InputIterator __first, _InputIterator __last, _OutputIterator __result)
{
    for (; __first != __last; ++__first, (void) ++__result)
        *__result = *__first;
    return __result;
}

template <class _InputIterator, class _OutputIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
__copy(_InputIterator __first, _InputIterator __last, _OutputIterator __result)
{
    return __copy_constexpr(__first, __last, __result);
}

template <class _Tp, class _Up>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_same<typename remove_const<_Tp>::type, _Up>::value &&
    is_trivially_copy_assignable<_Up>::value,
    _Up*
>::type
__copy(_Tp* __first, _Tp* __last, _Up* __result)
{
    const size_t __n = static_cast<size_t>(__last - __first);
    if (__n > 0)
        std::__1::memmove(__result, __first, __n * sizeof(_Up));
    return __result + __n;
}

template <class _InputIterator, class _OutputIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
copy(_InputIterator __first, _InputIterator __last, _OutputIterator __result)
{
    if (__libcpp_is_constant_evaluated()) {
        return std::__1::__copy_constexpr(
            __unwrap_iter(__first), __unwrap_iter(__last), __unwrap_iter(__result));
    } else {
        return std::__1::__copy(
            __unwrap_iter(__first), __unwrap_iter(__last), __unwrap_iter(__result));
    }
}



template <class _BidirectionalIterator, class _OutputIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
__copy_backward_constexpr(_BidirectionalIterator __first, _BidirectionalIterator __last, _OutputIterator __result)
{
    while (__first != __last)
        *--__result = *--__last;
    return __result;
}

template <class _BidirectionalIterator, class _OutputIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
__copy_backward(_BidirectionalIterator __first, _BidirectionalIterator __last, _OutputIterator __result)
{
    return __copy_backward_constexpr(__first, __last, __result);
}

template <class _Tp, class _Up>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_same<typename remove_const<_Tp>::type, _Up>::value &&
    is_trivially_copy_assignable<_Up>::value,
    _Up*
>::type
__copy_backward(_Tp* __first, _Tp* __last, _Up* __result)
{
    const size_t __n = static_cast<size_t>(__last - __first);
    if (__n > 0)
    {
        __result -= __n;
        std::__1::memmove(__result, __first, __n * sizeof(_Up));
    }
    return __result;
}

template <class _BidirectionalIterator1, class _BidirectionalIterator2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_BidirectionalIterator2
copy_backward(_BidirectionalIterator1 __first, _BidirectionalIterator1 __last,
              _BidirectionalIterator2 __result)
{
    if (__libcpp_is_constant_evaluated()) {
        return std::__1::__copy_backward_constexpr(__unwrap_iter(__first),
                                                __unwrap_iter(__last),
                                                __unwrap_iter(__result));
    } else {
        return std::__1::__copy_backward(__unwrap_iter(__first),
                                      __unwrap_iter(__last),
                                      __unwrap_iter(__result));
    }
}



template<class _InputIterator, class _OutputIterator, class _Predicate>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
copy_if(_InputIterator __first, _InputIterator __last,
        _OutputIterator __result, _Predicate __pred)
{
    for (; __first != __last; ++__first)
    {
        if (__pred(*__first))
        {
            *__result = *__first;
            ++__result;
        }
    }
    return __result;
}



template<class _InputIterator, class _Size, class _OutputIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    __is_cpp17_input_iterator<_InputIterator>::value &&
   !__is_cpp17_random_access_iterator<_InputIterator>::value,
    _OutputIterator
>::type
copy_n(_InputIterator __first, _Size __orig_n, _OutputIterator __result)
{
    typedef __decltype(__convert_to_integral(__orig_n)) _IntegralSize;
    _IntegralSize __n = __orig_n;
    if (__n > 0)
    {
        *__result = *__first;
        ++__result;
        for (--__n; __n > 0; --__n)
        {
            ++__first;
            *__result = *__first;
            ++__result;
        }
    }
    return __result;
}

template<class _InputIterator, class _Size, class _OutputIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    __is_cpp17_random_access_iterator<_InputIterator>::value,
    _OutputIterator
>::type
copy_n(_InputIterator __first, _Size __orig_n, _OutputIterator __result)
{
    typedef __decltype(__convert_to_integral(__orig_n)) _IntegralSize;
    _IntegralSize __n = __orig_n;
    return std::__1::copy(__first, __first + __n, __result);
}



template <class _InputIterator, class _OutputIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
__move(_InputIterator __first, _InputIterator __last, _OutputIterator __result)
{
    for (; __first != __last; ++__first, (void) ++__result)
        *__result = std::__1::move(*__first);
    return __result;
}

template <class _Tp, class _Up>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_same<typename remove_const<_Tp>::type, _Up>::value &&
    is_trivially_copy_assignable<_Up>::value,
    _Up*
>::type
__move(_Tp* __first, _Tp* __last, _Up* __result)
{
    const size_t __n = static_cast<size_t>(__last - __first);
    if (__n > 0)
        std::__1::memmove(__result, __first, __n * sizeof(_Up));
    return __result + __n;
}

template <class _InputIterator, class _OutputIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
move(_InputIterator __first, _InputIterator __last, _OutputIterator __result)
{
    return std::__1::__move(__unwrap_iter(__first), __unwrap_iter(__last), __unwrap_iter(__result));
}



template <class _InputIterator, class _OutputIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
__move_backward(_InputIterator __first, _InputIterator __last, _OutputIterator __result)
{
    while (__first != __last)
        *--__result = std::__1::move(*--__last);
    return __result;
}

template <class _Tp, class _Up>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
typename enable_if
<
    is_same<typename remove_const<_Tp>::type, _Up>::value &&
    is_trivially_copy_assignable<_Up>::value,
    _Up*
>::type
__move_backward(_Tp* __first, _Tp* __last, _Up* __result)
{
    const size_t __n = static_cast<size_t>(__last - __first);
    if (__n > 0)
    {
        __result -= __n;
        std::__1::memmove(__result, __first, __n * sizeof(_Up));
    }
    return __result;
}

template <class _BidirectionalIterator1, class _BidirectionalIterator2>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_BidirectionalIterator2
move_backward(_BidirectionalIterator1 __first, _BidirectionalIterator1 __last,
              _BidirectionalIterator2 __result)
{
    return std::__1::__move_backward(__unwrap_iter(__first), __unwrap_iter(__last), __unwrap_iter(__result));
}







template <class _InputIterator, class _OutputIterator, class _UnaryOperation>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
transform(_InputIterator __first, _InputIterator __last, _OutputIterator __result, _UnaryOperation __op)
{
    for (; __first != __last; ++__first, (void) ++__result)
        *__result = __op(*__first);
    return __result;
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator, class _BinaryOperation>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
transform(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2,
          _OutputIterator __result, _BinaryOperation __binary_op)
{
    for (; __first1 != __last1; ++__first1, (void) ++__first2, ++__result)
        *__result = __binary_op(*__first1, *__first2);
    return __result;
}



template <class _ForwardIterator, class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
replace(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __old_value, const _Tp& __new_value)
{
    for (; __first != __last; ++__first)
        if (*__first == __old_value)
            *__first = __new_value;
}



template <class _ForwardIterator, class _Predicate, class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
replace_if(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred, const _Tp& __new_value)
{
    for (; __first != __last; ++__first)
        if (__pred(*__first))
            *__first = __new_value;
}



template <class _InputIterator, class _OutputIterator, class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
replace_copy(_InputIterator __first, _InputIterator __last, _OutputIterator __result,
             const _Tp& __old_value, const _Tp& __new_value)
{
    for (; __first != __last; ++__first, (void) ++__result)
        if (*__first == __old_value)
            *__result = __new_value;
        else
            *__result = *__first;
    return __result;
}



template <class _InputIterator, class _OutputIterator, class _Predicate, class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
replace_copy_if(_InputIterator __first, _InputIterator __last, _OutputIterator __result,
                _Predicate __pred, const _Tp& __new_value)
{
    for (; __first != __last; ++__first, (void) ++__result)
        if (__pred(*__first))
            *__result = __new_value;
        else
            *__result = *__first;
    return __result;
}



template <class _OutputIterator, class _Size, class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
__fill_n(_OutputIterator __first, _Size __n, const _Tp& __value_)
{
    for (; __n > 0; ++__first, (void) --__n)
        *__first = __value_;
    return __first;
}

template <class _OutputIterator, class _Size, class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
fill_n(_OutputIterator __first, _Size __n, const _Tp& __value_)
{
   return std::__1::__fill_n(__first, __convert_to_integral(__n), __value_);
}



template <class _ForwardIterator, class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
__fill(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_, forward_iterator_tag)
{
    for (; __first != __last; ++__first)
        *__first = __value_;
}

template <class _RandomAccessIterator, class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
__fill(_RandomAccessIterator __first, _RandomAccessIterator __last, const _Tp& __value_, random_access_iterator_tag)
{
    std::__1::fill_n(__first, __last - __first, __value_);
}

template <class _ForwardIterator, class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
fill(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_)
{
    std::__1::__fill(__first, __last, __value_, typename iterator_traits<_ForwardIterator>::iterator_category());
}



template <class _ForwardIterator, class _Generator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
generate(_ForwardIterator __first, _ForwardIterator __last, _Generator __gen)
{
    for (; __first != __last; ++__first)
        *__first = __gen();
}



template <class _OutputIterator, class _Size, class _Generator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
generate_n(_OutputIterator __first, _Size __orig_n, _Generator __gen)
{
    typedef __decltype(__convert_to_integral(__orig_n)) _IntegralSize;
    _IntegralSize __n = __orig_n;
    for (; __n > 0; ++__first, (void) --__n)
        *__first = __gen();
    return __first;
}



template <class _ForwardIterator, class _Tp>
                                                    _ForwardIterator
remove(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_)
{
    __first = std::__1::find(__first, __last, __value_);
    if (__first != __last)
    {
        _ForwardIterator __i = __first;
        while (++__i != __last)
        {
            if (!(*__i == __value_))
            {
                *__first = std::__1::move(*__i);
                ++__first;
            }
        }
    }
    return __first;
}



template <class _ForwardIterator, class _Predicate>
                                                    _ForwardIterator
remove_if(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred)
{
    __first = std::__1::find_if<_ForwardIterator, typename add_lvalue_reference<_Predicate>::type>
                           (__first, __last, __pred);
    if (__first != __last)
    {
        _ForwardIterator __i = __first;
        while (++__i != __last)
        {
            if (!__pred(*__i))
            {
                *__first = std::__1::move(*__i);
                ++__first;
            }
        }
    }
    return __first;
}



template <class _InputIterator, class _OutputIterator, class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
remove_copy(_InputIterator __first, _InputIterator __last, _OutputIterator __result, const _Tp& __value_)
{
    for (; __first != __last; ++__first)
    {
        if (!(*__first == __value_))
        {
            *__result = *__first;
            ++__result;
        }
    }
    return __result;
}



template <class _InputIterator, class _OutputIterator, class _Predicate>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
remove_copy_if(_InputIterator __first, _InputIterator __last, _OutputIterator __result, _Predicate __pred)
{
    for (; __first != __last; ++__first)
    {
        if (!__pred(*__first))
        {
            *__result = *__first;
            ++__result;
        }
    }
    return __result;
}



template <class _ForwardIterator, class _BinaryPredicate>
                                                    _ForwardIterator
unique(_ForwardIterator __first, _ForwardIterator __last, _BinaryPredicate __pred)
{
    __first = std::__1::adjacent_find<_ForwardIterator, typename add_lvalue_reference<_BinaryPredicate>::type>
                                 (__first, __last, __pred);
    if (__first != __last)
    {


        _ForwardIterator __i = __first;
        for (++__i; ++__i != __last;)
            if (!__pred(*__first, *__i))
                *++__first = std::__1::move(*__i);
        ++__first;
    }
    return __first;
}

template <class _ForwardIterator>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator
unique(_ForwardIterator __first, _ForwardIterator __last)
{
    typedef typename iterator_traits<_ForwardIterator>::value_type __v;
    return std::__1::unique(__first, __last, __equal_to<__v>());
}



template <class _BinaryPredicate, class _InputIterator, class _OutputIterator>
                              _OutputIterator
__unique_copy(_InputIterator __first, _InputIterator __last, _OutputIterator __result, _BinaryPredicate __pred,
              input_iterator_tag, output_iterator_tag)
{
    if (__first != __last)
    {
        typename iterator_traits<_InputIterator>::value_type __t(*__first);
        *__result = __t;
        ++__result;
        while (++__first != __last)
        {
            if (!__pred(__t, *__first))
            {
                __t = *__first;
                *__result = __t;
                ++__result;
            }
        }
    }
    return __result;
}

template <class _BinaryPredicate, class _ForwardIterator, class _OutputIterator>
                              _OutputIterator
__unique_copy(_ForwardIterator __first, _ForwardIterator __last, _OutputIterator __result, _BinaryPredicate __pred,
              forward_iterator_tag, output_iterator_tag)
{
    if (__first != __last)
    {
        _ForwardIterator __i = __first;
        *__result = *__i;
        ++__result;
        while (++__first != __last)
        {
            if (!__pred(*__i, *__first))
            {
                *__result = *__first;
                ++__result;
                __i = __first;
            }
        }
    }
    return __result;
}

template <class _BinaryPredicate, class _InputIterator, class _ForwardIterator>
                              _ForwardIterator
__unique_copy(_InputIterator __first, _InputIterator __last, _ForwardIterator __result, _BinaryPredicate __pred,
              input_iterator_tag, forward_iterator_tag)
{
    if (__first != __last)
    {
        *__result = *__first;
        while (++__first != __last)
            if (!__pred(*__result, *__first))
                *++__result = *__first;
        ++__result;
    }
    return __result;
}

template <class _InputIterator, class _OutputIterator, class _BinaryPredicate>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
unique_copy(_InputIterator __first, _InputIterator __last, _OutputIterator __result, _BinaryPredicate __pred)
{
    return std::__1::__unique_copy<typename add_lvalue_reference<_BinaryPredicate>::type>
                              (__first, __last, __result, __pred,
                               typename iterator_traits<_InputIterator>::iterator_category(),
                               typename iterator_traits<_OutputIterator>::iterator_category());
}

template <class _InputIterator, class _OutputIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
unique_copy(_InputIterator __first, _InputIterator __last, _OutputIterator __result)
{
    typedef typename iterator_traits<_InputIterator>::value_type __v;
    return std::__1::unique_copy(__first, __last, __result, __equal_to<__v>());
}



template <class _BidirectionalIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
__reverse(_BidirectionalIterator __first, _BidirectionalIterator __last, bidirectional_iterator_tag)
{
    while (__first != __last)
    {
        if (__first == --__last)
            break;
        std::__1::iter_swap(__first, __last);
        ++__first;
    }
}

template <class _RandomAccessIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
__reverse(_RandomAccessIterator __first, _RandomAccessIterator __last, random_access_iterator_tag)
{
    if (__first != __last)
        for (; __first < --__last; ++__first)
            std::__1::iter_swap(__first, __last);
}

template <class _BidirectionalIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
reverse(_BidirectionalIterator __first, _BidirectionalIterator __last)
{
    std::__1::__reverse(__first, __last, typename iterator_traits<_BidirectionalIterator>::iterator_category());
}



template <class _BidirectionalIterator, class _OutputIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
reverse_copy(_BidirectionalIterator __first, _BidirectionalIterator __last, _OutputIterator __result)
{
    for (; __first != __last; ++__result)
        *__result = *--__last;
    return __result;
}



template <class _ForwardIterator>
_ForwardIterator
__rotate_left(_ForwardIterator __first, _ForwardIterator __last)
{
    typedef typename iterator_traits<_ForwardIterator>::value_type value_type;
    value_type __tmp = std::__1::move(*__first);
    _ForwardIterator __lm1 = std::__1::move(std::__1::next(__first), __last, __first);
    *__lm1 = std::__1::move(__tmp);
    return __lm1;
}

template <class _BidirectionalIterator>
_BidirectionalIterator
__rotate_right(_BidirectionalIterator __first, _BidirectionalIterator __last)
{
    typedef typename iterator_traits<_BidirectionalIterator>::value_type value_type;
    _BidirectionalIterator __lm1 = std::__1::prev(__last);
    value_type __tmp = std::__1::move(*__lm1);
    _BidirectionalIterator __fp1 = std::__1::move_backward(__first, __lm1, __last);
    *__first = std::__1::move(__tmp);
    return __fp1;
}

template <class _ForwardIterator>
_ForwardIterator
__rotate_forward(_ForwardIterator __first, _ForwardIterator __middle, _ForwardIterator __last)
{
    _ForwardIterator __i = __middle;
    while (true)
    {
        swap(*__first, *__i);
        ++__first;
        if (++__i == __last)
            break;
        if (__first == __middle)
            __middle = __i;
    }
    _ForwardIterator __r = __first;
    if (__first != __middle)
    {
        __i = __middle;
        while (true)
        {
            swap(*__first, *__i);
            ++__first;
            if (++__i == __last)
            {
                if (__first == __middle)
                    break;
                __i = __middle;
            }
            else if (__first == __middle)
                __middle = __i;
        }
    }
    return __r;
}

template<typename _Integral>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_Integral
__algo_gcd(_Integral __x, _Integral __y)
{
    do
    {
        _Integral __t = __x % __y;
        __x = __y;
        __y = __t;
    } while (__y);
    return __x;
}

template<typename _RandomAccessIterator>
_RandomAccessIterator
__rotate_gcd(_RandomAccessIterator __first, _RandomAccessIterator __middle, _RandomAccessIterator __last)
{
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;

    const difference_type __m1 = __middle - __first;
    const difference_type __m2 = __last - __middle;
    if (__m1 == __m2)
    {
        std::__1::swap_ranges(__first, __middle, __middle);
        return __middle;
    }
    const difference_type __g = std::__1::__algo_gcd(__m1, __m2);
    for (_RandomAccessIterator __p = __first + __g; __p != __first;)
    {
        value_type __t(std::__1::move(*--__p));
        _RandomAccessIterator __p1 = __p;
        _RandomAccessIterator __p2 = __p1 + __m1;
        do
        {
            *__p1 = std::__1::move(*__p2);
            __p1 = __p2;
            const difference_type __d = __last - __p2;
            if (__m1 < __d)
                __p2 += __m1;
            else
                __p2 = __first + (__m1 - __d);
        } while (__p2 != __p);
        *__p1 = std::__1::move(__t);
    }
    return __first + __m2;
}

template <class _ForwardIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator
__rotate(_ForwardIterator __first, _ForwardIterator __middle, _ForwardIterator __last,
         std::__1::forward_iterator_tag)
{
    typedef typename std::__1::iterator_traits<_ForwardIterator>::value_type value_type;
    if (std::__1::is_trivially_move_assignable<value_type>::value)
    {
        if (std::__1::next(__first) == __middle)
            return std::__1::__rotate_left(__first, __last);
    }
    return std::__1::__rotate_forward(__first, __middle, __last);
}

template <class _BidirectionalIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_BidirectionalIterator
__rotate(_BidirectionalIterator __first, _BidirectionalIterator __middle, _BidirectionalIterator __last,
         std::__1::bidirectional_iterator_tag)
{
    typedef typename std::__1::iterator_traits<_BidirectionalIterator>::value_type value_type;
    if (std::__1::is_trivially_move_assignable<value_type>::value)
    {
        if (std::__1::next(__first) == __middle)
            return std::__1::__rotate_left(__first, __last);
        if (std::__1::next(__middle) == __last)
            return std::__1::__rotate_right(__first, __last);
    }
    return std::__1::__rotate_forward(__first, __middle, __last);
}

template <class _RandomAccessIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_RandomAccessIterator
__rotate(_RandomAccessIterator __first, _RandomAccessIterator __middle, _RandomAccessIterator __last,
         std::__1::random_access_iterator_tag)
{
    typedef typename std::__1::iterator_traits<_RandomAccessIterator>::value_type value_type;
    if (std::__1::is_trivially_move_assignable<value_type>::value)
    {
        if (std::__1::next(__first) == __middle)
            return std::__1::__rotate_left(__first, __last);
        if (std::__1::next(__middle) == __last)
            return std::__1::__rotate_right(__first, __last);
        return std::__1::__rotate_gcd(__first, __middle, __last);
    }
    return std::__1::__rotate_forward(__first, __middle, __last);
}

template <class _ForwardIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator
rotate(_ForwardIterator __first, _ForwardIterator __middle, _ForwardIterator __last)
{
    if (__first == __middle)
        return __last;
    if (__middle == __last)
        return __first;
    return std::__1::__rotate(__first, __middle, __last,
                           typename std::__1::iterator_traits<_ForwardIterator>::iterator_category());
}



template <class _ForwardIterator, class _OutputIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
rotate_copy(_ForwardIterator __first, _ForwardIterator __middle, _ForwardIterator __last, _OutputIterator __result)
{
    return std::__1::copy(__first, __middle, std::__1::copy(__middle, __last, __result));
}



template <class _ForwardIterator, class _Compare>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator
min_element(_ForwardIterator __first, _ForwardIterator __last, _Compare __comp)
{
    _Static_assert(__is_cpp17_forward_iterator<_ForwardIterator>::value, "std::min_element requires a ForwardIterator");

    if (__first != __last)
    {
        _ForwardIterator __i = __first;
        while (++__i != __last)
            if (__comp(*__i, *__first))
                __first = __i;
    }
    return __first;
}

template <class _ForwardIterator>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator
min_element(_ForwardIterator __first, _ForwardIterator __last)
{
    return std::__1::min_element(__first, __last,
              __less<typename iterator_traits<_ForwardIterator>::value_type>());
}



template <class _Tp, class _Compare>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
const _Tp&
min(const _Tp& __a, const _Tp& __b, _Compare __comp)
{
    return __comp(__b, __a) ? __b : __a;
}

template <class _Tp>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
const _Tp&
min(const _Tp& __a, const _Tp& __b)
{
    return std::__1::min(__a, __b, __less<_Tp>());
}

template <class _ForwardIterator, class _Compare>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator
max_element(_ForwardIterator __first, _ForwardIterator __last, _Compare __comp)
{
    _Static_assert(__is_cpp17_forward_iterator<_ForwardIterator>::value, "std::max_element requires a ForwardIterator");

    if (__first != __last)
    {
        _ForwardIterator __i = __first;
        while (++__i != __last)
            if (__comp(*__first, *__i))
                __first = __i;
    }
    return __first;
}


template <class _ForwardIterator>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator
max_element(_ForwardIterator __first, _ForwardIterator __last)
{
    return std::__1::max_element(__first, __last,
              __less<typename iterator_traits<_ForwardIterator>::value_type>());
}



template <class _Tp, class _Compare>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
const _Tp&
max(const _Tp& __a, const _Tp& __b, _Compare __comp)
{
    return __comp(__a, __b) ? __b : __a;
}

template <class _Tp>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
const _Tp&
max(const _Tp& __a, const _Tp& __b)
{
    return std::__1::max(__a, __b, __less<_Tp>());
}

template <class _ForwardIterator, class _Compare>

std::pair<_ForwardIterator, _ForwardIterator>
minmax_element(_ForwardIterator __first, _ForwardIterator __last, _Compare __comp)
{
  _Static_assert(__is_cpp17_forward_iterator<_ForwardIterator>::value, "std::minmax_element requires a ForwardIterator");

  std::pair<_ForwardIterator, _ForwardIterator> __result(__first, __first);
  if (__first != __last)
  {
      if (++__first != __last)
      {
          if (__comp(*__first, *__result.first))
              __result.first = __first;
          else
              __result.second = __first;
          while (++__first != __last)
          {
              _ForwardIterator __i = __first;
              if (++__first == __last)
              {
                  if (__comp(*__i, *__result.first))
                      __result.first = __i;
                  else if (!__comp(*__i, *__result.second))
                      __result.second = __i;
                  break;
              }
              else
              {
                  if (__comp(*__first, *__i))
                  {
                      if (__comp(*__first, *__result.first))
                          __result.first = __first;
                      if (!__comp(*__i, *__result.second))
                          __result.second = __i;
                  }
                  else
                  {
                      if (__comp(*__i, *__result.first))
                          __result.first = __i;
                      if (!__comp(*__first, *__result.second))
                          __result.second = __first;
                  }
              }
          }
      }
  }
  return __result;
}

template <class _ForwardIterator>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
std::pair<_ForwardIterator, _ForwardIterator>
minmax_element(_ForwardIterator __first, _ForwardIterator __last)
{
    return std::__1::minmax_element(__first, __last,
              __less<typename iterator_traits<_ForwardIterator>::value_type>());
}



template<class _Tp, class _Compare>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
pair<const _Tp&, const _Tp&>
minmax(const _Tp& __a, const _Tp& __b, _Compare __comp)
{
    return __comp(__b, __a) ? pair<const _Tp&, const _Tp&>(__b, __a) :
                              pair<const _Tp&, const _Tp&>(__a, __b);
}

template<class _Tp>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
pair<const _Tp&, const _Tp&>
minmax(const _Tp& __a, const _Tp& __b)
{
    return std::__1::minmax(__a, __b, __less<_Tp>());
}

template <unsigned long long _Xp, size_t _Rp>
struct __log2_imp
{
    static const size_t value = _Xp & ((unsigned long long)(1) << _Rp) ? _Rp
                                           : __log2_imp<_Xp, _Rp - 1>::value;
};

template <unsigned long long _Xp>
struct __log2_imp<_Xp, 0>
{
    static const size_t value = 0;
};

template <size_t _Rp>
struct __log2_imp<0, _Rp>
{
    static const size_t value = _Rp + 1;
};

template <class _UIntType, _UIntType _Xp>
struct __log2
{
    static const size_t value = __log2_imp<_Xp,
                                         sizeof(_UIntType) * 8 - 1>::value;
};

template<class _Engine, class _UIntType>
class __independent_bits_engine
{
public:

    typedef _UIntType result_type;

private:
    typedef typename _Engine::result_type _Engine_result_type;
    typedef typename conditional
        <
            sizeof(_Engine_result_type) <= sizeof(result_type),
                result_type,
                _Engine_result_type
        >::type _Working_result_type;

    _Engine& __e_;
    size_t __w_;
    size_t __w0_;
    size_t __n_;
    size_t __n0_;
    _Working_result_type __y0_;
    _Working_result_type __y1_;
    _Engine_result_type __mask0_;
    _Engine_result_type __mask1_;


    static const _Working_result_type _Rp = _Engine::_Max - _Engine::_Min
                                          + _Working_result_type(1);




    static const size_t __m = __log2<_Working_result_type, _Rp>::value;
    static const size_t _WDt = numeric_limits<_Working_result_type>::digits;
    static const size_t _EDt = numeric_limits<_Engine_result_type>::digits;

public:

    __independent_bits_engine(_Engine& __e, size_t __w);


    result_type operator()() {return __eval(integral_constant<bool, _Rp != 0>());}

private:
    result_type __eval(false_type);
    result_type __eval(true_type);
};

template<class _Engine, class _UIntType>
__independent_bits_engine<_Engine, _UIntType>
    ::__independent_bits_engine(_Engine& __e, size_t __w)
        : __e_(__e),
          __w_(__w)
{
    __n_ = __w_ / __m + (__w_ % __m != 0);
    __w0_ = __w_ / __n_;
    if (_Rp == 0)
        __y0_ = _Rp;
    else if (__w0_ < _WDt)
        __y0_ = (_Rp >> __w0_) << __w0_;
    else
        __y0_ = 0;
    if (_Rp - __y0_ > __y0_ / __n_)
    {
        ++__n_;
        __w0_ = __w_ / __n_;
        if (__w0_ < _WDt)
            __y0_ = (_Rp >> __w0_) << __w0_;
        else
            __y0_ = 0;
    }
    __n0_ = __n_ - __w_ % __n_;
    if (__w0_ < _WDt - 1)
        __y1_ = (_Rp >> (__w0_ + 1)) << (__w0_ + 1);
    else
        __y1_ = 0;
    __mask0_ = __w0_ > 0 ? _Engine_result_type(~0) >> (_EDt - __w0_) :
                          _Engine_result_type(0);
    __mask1_ = __w0_ < _EDt - 1 ?
                               _Engine_result_type(~0) >> (_EDt - (__w0_ + 1)) :
                               _Engine_result_type(~0);
}

template<class _Engine, class _UIntType>
inline
_UIntType
__independent_bits_engine<_Engine, _UIntType>::__eval(false_type)
{
    return static_cast<result_type>(__e_() & __mask0_);
}

template<class _Engine, class _UIntType>
_UIntType
__independent_bits_engine<_Engine, _UIntType>::__eval(true_type)
{
    const size_t _WRt = numeric_limits<result_type>::digits;
    result_type _Sp = 0;
    for (size_t __k = 0; __k < __n0_; ++__k)
    {
        _Engine_result_type __u;
        do
        {
            __u = __e_() - _Engine::min();
        } while (__u >= __y0_);
        if (__w0_ < _WRt)
            _Sp <<= __w0_;
        else
            _Sp = 0;
        _Sp += __u & __mask0_;
    }
    for (size_t __k = __n0_; __k < __n_; ++__k)
    {
        _Engine_result_type __u;
        do
        {
            __u = __e_() - _Engine::min();
        } while (__u >= __y1_);
        if (__w0_ < _WRt - 1)
            _Sp <<= __w0_ + 1;
        else
            _Sp = 0;
        _Sp += __u & __mask1_;
    }
    return _Sp;
}



template<class _IntType = int>
class uniform_int_distribution
{
public:

    typedef _IntType result_type;

    class param_type
    {
        result_type __a_;
        result_type __b_;
    public:
        typedef uniform_int_distribution distribution_type;

        explicit param_type(result_type __a = 0,
                            result_type __b = numeric_limits<result_type>::max())
            : __a_(__a), __b_(__b) {}

        result_type a() const {return __a_;}
        result_type b() const {return __b_;}

        friend bool operator==(const param_type& __x, const param_type& __y)
            {return __x.__a_ == __y.__a_ && __x.__b_ == __y.__b_;}
        friend bool operator!=(const param_type& __x, const param_type& __y)
            {return !(__x == __y);}
    };

private:
    param_type __p_;

public:

    explicit uniform_int_distribution(result_type __a = 0,
                                      result_type __b = numeric_limits<result_type>::max())
        : __p_(param_type(__a, __b)) {}
    explicit uniform_int_distribution(const param_type& __p) : __p_(__p) {}
    void reset() {}


    template<class _URNG> result_type operator()(_URNG& __g)
        {return (*this)(__g, __p_);}
    template<class _URNG> result_type operator()(_URNG& __g, const param_type& __p);


    result_type a() const {return __p_.a();}
    result_type b() const {return __p_.b();}

    param_type param() const {return __p_;}
    void param(const param_type& __p) {__p_ = __p;}

    result_type min() const {return a();}
    result_type max() const {return b();}

    friend bool operator==(const uniform_int_distribution& __x,
                           const uniform_int_distribution& __y)
        {return __x.__p_ == __y.__p_;}
    friend bool operator!=(const uniform_int_distribution& __x,
                           const uniform_int_distribution& __y)
            {return !(__x == __y);}
};

template<class _IntType>
template<class _URNG>
typename uniform_int_distribution<_IntType>::result_type
uniform_int_distribution<_IntType>::operator()(_URNG& __g, const param_type& __p)
__attribute__((__no_sanitize__("unsigned-integer-overflow")))
{
    typedef typename conditional<sizeof(result_type) <= sizeof(uint32_t),
                                            uint32_t, uint64_t>::type _UIntType;
    const _UIntType _Rp = _UIntType(__p.b()) - _UIntType(__p.a()) + _UIntType(1);
    if (_Rp == 1)
        return __p.a();
    const size_t _Dt = numeric_limits<_UIntType>::digits;
    typedef __independent_bits_engine<_URNG, _UIntType> _Eng;
    if (_Rp == 0)
        return static_cast<result_type>(_Eng(__g, _Dt)());
    size_t __w = _Dt - __libcpp_clz(_Rp) - 1;
    if ((_Rp & (std::numeric_limits<_UIntType>::max() >> (_Dt - __w))) != 0)
        ++__w;
    _Eng __e(__g, __w);
    _UIntType __u;
    do
    {
        __u = __e();
    } while (__u >= _Rp);
    return static_cast<result_type>(__u + __p.a());
}



class __attribute__ ((__visibility__("default"))) __rs_default;

__attribute__ ((__visibility__("default"))) __rs_default __rs_get();

class __attribute__ ((__visibility__("default"))) __rs_default
{
    static unsigned __c_;

    __rs_default();
public:
    typedef uint_fast32_t result_type;

    static const result_type _Min = 0;
    static const result_type _Max = 0xFFFFFFFF;

    __rs_default(const __rs_default&);
    ~__rs_default();

    result_type operator()();

    static result_type min() {return _Min;}
    static result_type max() {return _Max;}

    friend __attribute__ ((__visibility__("default"))) __rs_default __rs_get();
};

__attribute__ ((__visibility__("default"))) __rs_default __rs_get();

template <class _RandomAccessIterator>
                            void
random_shuffle(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    typedef uniform_int_distribution<ptrdiff_t> _Dp;
    typedef typename _Dp::param_type _Pp;
    difference_type __d = __last - __first;
    if (__d > 1)
    {
        _Dp __uid;
        __rs_default __g = __rs_get();
        for (--__last, (void) --__d; __first < __last; ++__first, (void) --__d)
        {
            difference_type __i = __uid(__g, _Pp(0, __d));
            if (__i != difference_type(0))
                swap(*__first, *(__first + __i));
        }
    }
}

template <class _RandomAccessIterator, class _RandomNumberGenerator>
                            void
random_shuffle(_RandomAccessIterator __first, _RandomAccessIterator __last,



               _RandomNumberGenerator& __rand)

{
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    difference_type __d = __last - __first;
    if (__d > 1)
    {
        for (--__last; __first < __last; ++__first, (void) --__d)
        {
            difference_type __i = __rand(__d);
            if (__i != difference_type(0))
              swap(*__first, *(__first + __i));
        }
    }
}


template <class _PopulationIterator, class _SampleIterator, class _Distance,
          class _UniformRandomNumberGenerator>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_SampleIterator __sample(_PopulationIterator __first,
                         _PopulationIterator __last, _SampleIterator __output_iter,
                         _Distance __n,
                         _UniformRandomNumberGenerator & __g,
                         input_iterator_tag) {

  _Distance __k = 0;
  for (; __first != __last && __k < __n; ++__first, (void) ++__k)
    __output_iter[__k] = *__first;
  _Distance __sz = __k;
  for (; __first != __last; ++__first, (void) ++__k) {
    _Distance __r = std::__1::uniform_int_distribution<_Distance>(0, __k)(__g);
    if (__r < __sz)
      __output_iter[__r] = *__first;
  }
  return __output_iter + std::__1::min(__n, __k);
}

template <class _PopulationIterator, class _SampleIterator, class _Distance,
          class _UniformRandomNumberGenerator>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_SampleIterator __sample(_PopulationIterator __first,
                         _PopulationIterator __last, _SampleIterator __output_iter,
                         _Distance __n,
                         _UniformRandomNumberGenerator& __g,
                         forward_iterator_tag) {
  _Distance __unsampled_sz = std::__1::distance(__first, __last);
  for (__n = std::__1::min(__n, __unsampled_sz); __n != 0; ++__first) {
    _Distance __r =
        std::__1::uniform_int_distribution<_Distance>(0, --__unsampled_sz)(__g);
    if (__r < __n) {
      *__output_iter++ = *__first;
      --__n;
    }
  }
  return __output_iter;
}

template <class _PopulationIterator, class _SampleIterator, class _Distance,
          class _UniformRandomNumberGenerator>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_SampleIterator __sample(_PopulationIterator __first,
                         _PopulationIterator __last, _SampleIterator __output_iter,
                         _Distance __n, _UniformRandomNumberGenerator& __g) {
  typedef typename iterator_traits<_PopulationIterator>::iterator_category
        _PopCategory;
  typedef typename iterator_traits<_PopulationIterator>::difference_type
        _Difference;
  _Static_assert(__is_cpp17_forward_iterator<_PopulationIterator>::value || __is_cpp17_random_access_iterator<_SampleIterator>::value, "SampleIterator must meet the requirements of RandomAccessIterator");


  typedef typename common_type<_Distance, _Difference>::type _CommonType;
  ((void)0);
  return std::__1::__sample(
      __first, __last, __output_iter, _CommonType(__n),
      __g, _PopCategory());
}

template<class _RandomAccessIterator, class _UniformRandomNumberGenerator>
    void shuffle(_RandomAccessIterator __first, _RandomAccessIterator __last,
                 _UniformRandomNumberGenerator&& __g)
{
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    typedef uniform_int_distribution<ptrdiff_t> _Dp;
    typedef typename _Dp::param_type _Pp;
    difference_type __d = __last - __first;
    if (__d > 1)
    {
        _Dp __uid;
        for (--__last, (void) --__d; __first < __last; ++__first, (void) --__d)
        {
            difference_type __i = __uid(__g, _Pp(0, __d));
            if (__i != difference_type(0))
                swap(*__first, *(__first + __i));
        }
    }
}

template <class _InputIterator, class _Predicate>
                                                    bool
is_partitioned(_InputIterator __first, _InputIterator __last, _Predicate __pred)
{
    for (; __first != __last; ++__first)
        if (!__pred(*__first))
            break;
    if ( __first == __last )
        return true;
    ++__first;
    for (; __first != __last; ++__first)
        if (__pred(*__first))
            return false;
    return true;
}



template <class _Predicate, class _ForwardIterator>
_ForwardIterator
__partition(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred, forward_iterator_tag)
{
    while (true)
    {
        if (__first == __last)
            return __first;
        if (!__pred(*__first))
            break;
        ++__first;
    }
    for (_ForwardIterator __p = __first; ++__p != __last;)
    {
        if (__pred(*__p))
        {
            swap(*__first, *__p);
            ++__first;
        }
    }
    return __first;
}

template <class _Predicate, class _BidirectionalIterator>
_BidirectionalIterator
__partition(_BidirectionalIterator __first, _BidirectionalIterator __last, _Predicate __pred,
            bidirectional_iterator_tag)
{
    while (true)
    {
        while (true)
        {
            if (__first == __last)
                return __first;
            if (!__pred(*__first))
                break;
            ++__first;
        }
        do
        {
            if (__first == --__last)
                return __first;
        } while (!__pred(*__last));
        swap(*__first, *__last);
        ++__first;
    }
}

template <class _ForwardIterator, class _Predicate>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator
partition(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred)
{
    return std::__1::__partition<typename add_lvalue_reference<_Predicate>::type>
                            (__first, __last, __pred, typename iterator_traits<_ForwardIterator>::iterator_category());
}



template <class _InputIterator, class _OutputIterator1,
          class _OutputIterator2, class _Predicate>
                              pair<_OutputIterator1, _OutputIterator2>
partition_copy(_InputIterator __first, _InputIterator __last,
               _OutputIterator1 __out_true, _OutputIterator2 __out_false,
               _Predicate __pred)
{
    for (; __first != __last; ++__first)
    {
        if (__pred(*__first))
        {
            *__out_true = *__first;
            ++__out_true;
        }
        else
        {
            *__out_false = *__first;
            ++__out_false;
        }
    }
    return pair<_OutputIterator1, _OutputIterator2>(__out_true, __out_false);
}



template<class _ForwardIterator, class _Predicate>
                              _ForwardIterator
partition_point(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred)
{
    typedef typename iterator_traits<_ForwardIterator>::difference_type difference_type;
    difference_type __len = std::__1::distance(__first, __last);
    while (__len != 0)
    {
        difference_type __l2 = std::__1::__half_positive(__len);
        _ForwardIterator __m = __first;
        std::__1::advance(__m, __l2);
        if (__pred(*__m))
        {
            __first = ++__m;
            __len -= __l2 + 1;
        }
        else
            __len = __l2;
    }
    return __first;
}



template <class _Predicate, class _ForwardIterator, class _Distance, class _Pair>
_ForwardIterator
__stable_partition(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred,
                   _Distance __len, _Pair __p, forward_iterator_tag __fit)
{


    if (__len == 1)
        return __first;
    if (__len == 2)
    {
        _ForwardIterator __m = __first;
        if (__pred(*++__m))
        {
            swap(*__first, *__m);
            return __m;
        }
        return __first;
    }
    if (__len <= __p.second)
    {
        typedef typename iterator_traits<_ForwardIterator>::value_type value_type;
        __destruct_n __d(0);
        unique_ptr<value_type, __destruct_n&> __h(__p.first, __d);


        value_type* __t = __p.first;
        ::new(__t) value_type(std::__1::move(*__first));
        __d.__incr((value_type*)0);
        ++__t;
        _ForwardIterator __i = __first;
        while (++__i != __last)
        {
            if (__pred(*__i))
            {
                *__first = std::__1::move(*__i);
                ++__first;
            }
            else
            {
                ::new(__t) value_type(std::__1::move(*__i));
                __d.__incr((value_type*)0);
                ++__t;
            }
        }


        __i = __first;
        for (value_type* __t2 = __p.first; __t2 < __t; ++__t2, (void) ++__i)
            *__i = std::__1::move(*__t2);

        return __first;
    }


    _ForwardIterator __m = __first;
    _Distance __len2 = __len / 2;
    std::__1::advance(__m, __len2);



    typedef typename add_lvalue_reference<_Predicate>::type _PredRef;
    _ForwardIterator __first_false = __stable_partition<_PredRef>(__first, __m, __pred, __len2, __p, __fit);



    _ForwardIterator __m1 = __m;
    _ForwardIterator __second_false = __last;
    _Distance __len_half = __len - __len2;
    while (__pred(*__m1))
    {
        if (++__m1 == __last)
            goto __second_half_done;
        --__len_half;
    }


    __second_false = __stable_partition<_PredRef>(__m1, __last, __pred, __len_half, __p, __fit);
__second_half_done:


    return std::__1::rotate(__first_false, __m, __second_false);


}

struct __return_temporary_buffer
{
    template <class _Tp>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void operator()(_Tp* __p) const {std::__1::return_temporary_buffer(__p);}
};

template <class _Predicate, class _ForwardIterator>
_ForwardIterator
__stable_partition(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred,
                   forward_iterator_tag)
{
    const unsigned __alloc_limit = 3;

    while (true)
    {
        if (__first == __last)
            return __first;
        if (!__pred(*__first))
            break;
        ++__first;
    }


    typedef typename iterator_traits<_ForwardIterator>::difference_type difference_type;
    typedef typename iterator_traits<_ForwardIterator>::value_type value_type;
    difference_type __len = std::__1::distance(__first, __last);
    pair<value_type*, ptrdiff_t> __p(0, 0);
    unique_ptr<value_type, __return_temporary_buffer> __h;
    if (__len >= __alloc_limit)
    {
        __p = std::__1::get_temporary_buffer<value_type>(__len);
        __h.reset(__p.first);
    }
    return __stable_partition<typename add_lvalue_reference<_Predicate>::type>
                             (__first, __last, __pred, __len, __p, forward_iterator_tag());
}

template <class _Predicate, class _BidirectionalIterator, class _Distance, class _Pair>
_BidirectionalIterator
__stable_partition(_BidirectionalIterator __first, _BidirectionalIterator __last, _Predicate __pred,
                   _Distance __len, _Pair __p, bidirectional_iterator_tag __bit)
{



    if (__len == 2)
    {
        swap(*__first, *__last);
        return __last;
    }
    if (__len == 3)
    {
        _BidirectionalIterator __m = __first;
        if (__pred(*++__m))
        {
            swap(*__first, *__m);
            swap(*__m, *__last);
            return __last;
        }
        swap(*__m, *__last);
        swap(*__first, *__m);
        return __m;
    }
    if (__len <= __p.second)
    {
        typedef typename iterator_traits<_BidirectionalIterator>::value_type value_type;
        __destruct_n __d(0);
        unique_ptr<value_type, __destruct_n&> __h(__p.first, __d);


        value_type* __t = __p.first;
        ::new(__t) value_type(std::__1::move(*__first));
        __d.__incr((value_type*)0);
        ++__t;
        _BidirectionalIterator __i = __first;
        while (++__i != __last)
        {
            if (__pred(*__i))
            {
                *__first = std::__1::move(*__i);
                ++__first;
            }
            else
            {
                ::new(__t) value_type(std::__1::move(*__i));
                __d.__incr((value_type*)0);
                ++__t;
            }
        }

        *__first = std::__1::move(*__i);
        __i = ++__first;


        for (value_type* __t2 = __p.first; __t2 < __t; ++__t2, (void) ++__i)
            *__i = std::__1::move(*__t2);

        return __first;
    }


    _BidirectionalIterator __m = __first;
    _Distance __len2 = __len / 2;
    std::__1::advance(__m, __len2);



    _BidirectionalIterator __m1 = __m;
    _BidirectionalIterator __first_false = __first;
    _Distance __len_half = __len2;
    while (!__pred(*--__m1))
    {
        if (__m1 == __first)
            goto __first_half_done;
        --__len_half;
    }


    typedef typename add_lvalue_reference<_Predicate>::type _PredRef;
    __first_false = __stable_partition<_PredRef>(__first, __m1, __pred, __len_half, __p, __bit);
__first_half_done:



    __m1 = __m;
    _BidirectionalIterator __second_false = __last;
    ++__second_false;
    __len_half = __len - __len2;
    while (__pred(*__m1))
    {
        if (++__m1 == __last)
            goto __second_half_done;
        --__len_half;
    }


    __second_false = __stable_partition<_PredRef>(__m1, __last, __pred, __len_half, __p, __bit);
__second_half_done:


    return std::__1::rotate(__first_false, __m, __second_false);


}

template <class _Predicate, class _BidirectionalIterator>
_BidirectionalIterator
__stable_partition(_BidirectionalIterator __first, _BidirectionalIterator __last, _Predicate __pred,
                   bidirectional_iterator_tag)
{
    typedef typename iterator_traits<_BidirectionalIterator>::difference_type difference_type;
    typedef typename iterator_traits<_BidirectionalIterator>::value_type value_type;
    const difference_type __alloc_limit = 4;

    while (true)
    {
        if (__first == __last)
            return __first;
        if (!__pred(*__first))
            break;
        ++__first;
    }


    do
    {
        if (__first == --__last)
            return __first;
    } while (!__pred(*__last));




    difference_type __len = std::__1::distance(__first, __last) + 1;
    pair<value_type*, ptrdiff_t> __p(0, 0);
    unique_ptr<value_type, __return_temporary_buffer> __h;
    if (__len >= __alloc_limit)
    {
        __p = std::__1::get_temporary_buffer<value_type>(__len);
        __h.reset(__p.first);
    }
    return __stable_partition<typename add_lvalue_reference<_Predicate>::type>
                             (__first, __last, __pred, __len, __p, bidirectional_iterator_tag());
}

template <class _ForwardIterator, class _Predicate>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator
stable_partition(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred)
{
    return __stable_partition<typename add_lvalue_reference<_Predicate>::type>
                             (__first, __last, __pred, typename iterator_traits<_ForwardIterator>::iterator_category());
}



template <class _ForwardIterator, class _Compare>
                                                    _ForwardIterator
is_sorted_until(_ForwardIterator __first, _ForwardIterator __last, _Compare __comp)
{
    if (__first != __last)
    {
        _ForwardIterator __i = __first;
        while (++__i != __last)
        {
            if (__comp(*__i, *__first))
                return __i;
            __first = __i;
        }
    }
    return __last;
}

template<class _ForwardIterator>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator
is_sorted_until(_ForwardIterator __first, _ForwardIterator __last)
{
    return std::__1::is_sorted_until(__first, __last, __less<typename iterator_traits<_ForwardIterator>::value_type>());
}



template <class _ForwardIterator, class _Compare>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
is_sorted(_ForwardIterator __first, _ForwardIterator __last, _Compare __comp)
{
    return std::__1::is_sorted_until(__first, __last, __comp) == __last;
}

template<class _ForwardIterator>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
is_sorted(_ForwardIterator __first, _ForwardIterator __last)
{
    return std::__1::is_sorted(__first, __last, __less<typename iterator_traits<_ForwardIterator>::value_type>());
}





template <class _Compare, class _ForwardIterator>
unsigned
__sort3(_ForwardIterator __x, _ForwardIterator __y, _ForwardIterator __z, _Compare __c)
{
    unsigned __r = 0;
    if (!__c(*__y, *__x))
    {
        if (!__c(*__z, *__y))
            return __r;

        swap(*__y, *__z);
        __r = 1;
        if (__c(*__y, *__x))
        {
            swap(*__x, *__y);
            __r = 2;
        }
        return __r;
    }
    if (__c(*__z, *__y))
    {
        swap(*__x, *__z);
        __r = 1;
        return __r;
    }
    swap(*__x, *__y);
    __r = 1;
    if (__c(*__z, *__y))
    {
        swap(*__y, *__z);
        __r = 2;
    }
    return __r;
}



template <class _Compare, class _ForwardIterator>
unsigned
__sort4(_ForwardIterator __x1, _ForwardIterator __x2, _ForwardIterator __x3,
            _ForwardIterator __x4, _Compare __c)
{
    unsigned __r = __sort3<_Compare>(__x1, __x2, __x3, __c);
    if (__c(*__x4, *__x3))
    {
        swap(*__x3, *__x4);
        ++__r;
        if (__c(*__x3, *__x2))
        {
            swap(*__x2, *__x3);
            ++__r;
            if (__c(*__x2, *__x1))
            {
                swap(*__x1, *__x2);
                ++__r;
            }
        }
    }
    return __r;
}



template <class _Compare, class _ForwardIterator>
__attribute__ ((__visibility__("hidden")))
unsigned
__sort5(_ForwardIterator __x1, _ForwardIterator __x2, _ForwardIterator __x3,
            _ForwardIterator __x4, _ForwardIterator __x5, _Compare __c)
{
    unsigned __r = __sort4<_Compare>(__x1, __x2, __x3, __x4, __c);
    if (__c(*__x5, *__x4))
    {
        swap(*__x4, *__x5);
        ++__r;
        if (__c(*__x4, *__x3))
        {
            swap(*__x3, *__x4);
            ++__r;
            if (__c(*__x3, *__x2))
            {
                swap(*__x2, *__x3);
                ++__r;
                if (__c(*__x2, *__x1))
                {
                    swap(*__x1, *__x2);
                    ++__r;
                }
            }
        }
    }
    return __r;
}


template <class _Compare, class _BirdirectionalIterator>
void
__selection_sort(_BirdirectionalIterator __first, _BirdirectionalIterator __last, _Compare __comp)
{
    _BirdirectionalIterator __lm1 = __last;
    for (--__lm1; __first != __lm1; ++__first)
    {
        _BirdirectionalIterator __i = std::__1::min_element<_BirdirectionalIterator,
                                                        typename add_lvalue_reference<_Compare>::type>
                                                       (__first, __last, __comp);
        if (__i != __first)
            swap(*__first, *__i);
    }
}

template <class _Compare, class _BirdirectionalIterator>
void
__insertion_sort(_BirdirectionalIterator __first, _BirdirectionalIterator __last, _Compare __comp)
{
    typedef typename iterator_traits<_BirdirectionalIterator>::value_type value_type;
    if (__first != __last)
    {
        _BirdirectionalIterator __i = __first;
        for (++__i; __i != __last; ++__i)
        {
            _BirdirectionalIterator __j = __i;
            value_type __t(std::__1::move(*__j));
            for (_BirdirectionalIterator __k = __i; __k != __first && __comp(__t, *--__k); --__j)
                *__j = std::__1::move(*__k);
            *__j = std::__1::move(__t);
        }
    }
}

template <class _Compare, class _RandomAccessIterator>
void
__insertion_sort_3(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;
    _RandomAccessIterator __j = __first+2;
    __sort3<_Compare>(__first, __first+1, __j, __comp);
    for (_RandomAccessIterator __i = __j+1; __i != __last; ++__i)
    {
        if (__comp(*__i, *__j))
        {
            value_type __t(std::__1::move(*__i));
            _RandomAccessIterator __k = __j;
            __j = __i;
            do
            {
                *__j = std::__1::move(*__k);
                __j = __k;
            } while (__j != __first && __comp(__t, *--__k));
            *__j = std::__1::move(__t);
        }
        __j = __i;
    }
}

template <class _Compare, class _RandomAccessIterator>
bool
__insertion_sort_incomplete(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    switch (__last - __first)
    {
    case 0:
    case 1:
        return true;
    case 2:
        if (__comp(*--__last, *__first))
            swap(*__first, *__last);
        return true;
    case 3:
        std::__1::__sort3<_Compare>(__first, __first+1, --__last, __comp);
        return true;
    case 4:
        std::__1::__sort4<_Compare>(__first, __first+1, __first+2, --__last, __comp);
        return true;
    case 5:
        std::__1::__sort5<_Compare>(__first, __first+1, __first+2, __first+3, --__last, __comp);
        return true;
    }
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;
    _RandomAccessIterator __j = __first+2;
    __sort3<_Compare>(__first, __first+1, __j, __comp);
    const unsigned __limit = 8;
    unsigned __count = 0;
    for (_RandomAccessIterator __i = __j+1; __i != __last; ++__i)
    {
        if (__comp(*__i, *__j))
        {
            value_type __t(std::__1::move(*__i));
            _RandomAccessIterator __k = __j;
            __j = __i;
            do
            {
                *__j = std::__1::move(*__k);
                __j = __k;
            } while (__j != __first && __comp(__t, *--__k));
            *__j = std::__1::move(__t);
            if (++__count == __limit)
                return ++__i == __last;
        }
        __j = __i;
    }
    return true;
}

template <class _Compare, class _BirdirectionalIterator>
void
__insertion_sort_move(_BirdirectionalIterator __first1, _BirdirectionalIterator __last1,
                      typename iterator_traits<_BirdirectionalIterator>::value_type* __first2, _Compare __comp)
{
    typedef typename iterator_traits<_BirdirectionalIterator>::value_type value_type;
    if (__first1 != __last1)
    {
        __destruct_n __d(0);
        unique_ptr<value_type, __destruct_n&> __h(__first2, __d);
        value_type* __last2 = __first2;
        ::new(__last2) value_type(std::__1::move(*__first1));
        __d.__incr((value_type*)0);
        for (++__last2; ++__first1 != __last1; ++__last2)
        {
            value_type* __j2 = __last2;
            value_type* __i2 = __j2;
            if (__comp(*__first1, *--__i2))
            {
                ::new(__j2) value_type(std::__1::move(*__i2));
                __d.__incr((value_type*)0);
                for (--__j2; __i2 != __first2 && __comp(*__first1, *--__i2); --__j2)
                    *__j2 = std::__1::move(*__i2);
                *__j2 = std::__1::move(*__first1);
            }
            else
            {
                ::new(__j2) value_type(std::__1::move(*__first1));
                __d.__incr((value_type*)0);
            }
        }
        __h.release();
    }
}

template <class _Compare, class _RandomAccessIterator>
void
__sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{

    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;
    const difference_type __limit = is_trivially_copy_constructible<value_type>::value &&
                                    is_trivially_copy_assignable<value_type>::value ? 30 : 6;
    while (true)
    {
    __restart:
        difference_type __len = __last - __first;
        switch (__len)
        {
        case 0:
        case 1:
            return;
        case 2:
            if (__comp(*--__last, *__first))
                swap(*__first, *__last);
            return;
        case 3:
            std::__1::__sort3<_Compare>(__first, __first+1, --__last, __comp);
            return;
        case 4:
            std::__1::__sort4<_Compare>(__first, __first+1, __first+2, --__last, __comp);
            return;
        case 5:
            std::__1::__sort5<_Compare>(__first, __first+1, __first+2, __first+3, --__last, __comp);
            return;
        }
        if (__len <= __limit)
        {
            std::__1::__insertion_sort_3<_Compare>(__first, __last, __comp);
            return;
        }

        _RandomAccessIterator __m = __first;
        _RandomAccessIterator __lm1 = __last;
        --__lm1;
        unsigned __n_swaps;
        {
        difference_type __delta;
        if (__len >= 1000)
        {
            __delta = __len/2;
            __m += __delta;
            __delta /= 2;
            __n_swaps = std::__1::__sort5<_Compare>(__first, __first + __delta, __m, __m+__delta, __lm1, __comp);
        }
        else
        {
            __delta = __len/2;
            __m += __delta;
            __n_swaps = std::__1::__sort3<_Compare>(__first, __m, __lm1, __comp);
        }
        }



        _RandomAccessIterator __i = __first;
        _RandomAccessIterator __j = __lm1;



        if (!__comp(*__i, *__m))
        {


            while (true)
            {
                if (__i == --__j)
                {


                    ++__i;
                    __j = __last;
                    if (!__comp(*__first, *--__j))
                    {
                        while (true)
                        {
                            if (__i == __j)
                                return;
                            if (__comp(*__first, *__i))
                            {
                                swap(*__i, *__j);
                                ++__n_swaps;
                                ++__i;
                                break;
                            }
                            ++__i;
                        }
                    }

                    if (__i == __j)
                        return;
                    while (true)
                    {
                        while (!__comp(*__first, *__i))
                            ++__i;
                        while (__comp(*__first, *--__j))
                            ;
                        if (__i >= __j)
                            break;
                        swap(*__i, *__j);
                        ++__n_swaps;
                        ++__i;
                    }



                    __first = __i;
                    goto __restart;
                }
                if (__comp(*__j, *__m))
                {
                    swap(*__i, *__j);
                    ++__n_swaps;
                    break;
                }
            }
        }

        ++__i;


        if (__i < __j)
        {


            while (true)
            {

                while (__comp(*__i, *__m))
                    ++__i;

                while (!__comp(*--__j, *__m))
                    ;
                if (__i > __j)
                    break;
                swap(*__i, *__j);
                ++__n_swaps;


                if (__m == __i)
                    __m = __j;
                ++__i;
            }
        }

        if (__i != __m && __comp(*__m, *__i))
        {
            swap(*__i, *__m);
            ++__n_swaps;
        }


        if (__n_swaps == 0)
        {
            bool __fs = std::__1::__insertion_sort_incomplete<_Compare>(__first, __i, __comp);
            if (std::__1::__insertion_sort_incomplete<_Compare>(__i+1, __last, __comp))
            {
                if (__fs)
                    return;
                __last = __i;
                continue;
            }
            else
            {
                if (__fs)
                {
                    __first = ++__i;
                    continue;
                }
            }
        }

        if (__i - __first < __last - __i)
        {
            std::__1::__sort<_Compare>(__first, __i, __comp);

            __first = ++__i;
        }
        else
        {
            std::__1::__sort<_Compare>(__i+1, __last, __comp);

            __last = __i;
        }
    }
}


template <class _RandomAccessIterator, class _Compare>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    std::__1::__sort<_Comp_ref>(__first, __last, _Comp_ref(__comp));
}

template <class _RandomAccessIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
sort(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    std::__1::sort(__first, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
sort(_Tp** __first, _Tp** __last)
{
    std::__1::sort((size_t*)__first, (size_t*)__last, __less<size_t>());
}

template <class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
sort(__wrap_iter<_Tp*> __first, __wrap_iter<_Tp*> __last)
{
    std::__1::sort(__first.base(), __last.base());
}

template <class _Tp, class _Compare>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
sort(__wrap_iter<_Tp*> __first, __wrap_iter<_Tp*> __last, _Compare __comp)
{
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    std::__1::sort<_Tp*, _Comp_ref>(__first.base(), __last.base(), __comp);
}

extern template __attribute__ ((__visibility__("default"))) void __sort<__less<char>&, char*>(char*, char*, __less<char>&);
extern template __attribute__ ((__visibility__("default"))) void __sort<__less<wchar_t>&, wchar_t*>(wchar_t*, wchar_t*, __less<wchar_t>&);
extern template __attribute__ ((__visibility__("default"))) void __sort<__less<signed char>&, signed char*>(signed char*, signed char*, __less<signed char>&);
extern template __attribute__ ((__visibility__("default"))) void __sort<__less<unsigned char>&, unsigned char*>(unsigned char*, unsigned char*, __less<unsigned char>&);
extern template __attribute__ ((__visibility__("default"))) void __sort<__less<short>&, short*>(short*, short*, __less<short>&);
extern template __attribute__ ((__visibility__("default"))) void __sort<__less<unsigned short>&, unsigned short*>(unsigned short*, unsigned short*, __less<unsigned short>&);
extern template __attribute__ ((__visibility__("default"))) void __sort<__less<int>&, int*>(int*, int*, __less<int>&);
extern template __attribute__ ((__visibility__("default"))) void __sort<__less<unsigned>&, unsigned*>(unsigned*, unsigned*, __less<unsigned>&);
extern template __attribute__ ((__visibility__("default"))) void __sort<__less<long>&, long*>(long*, long*, __less<long>&);
extern template __attribute__ ((__visibility__("default"))) void __sort<__less<unsigned long>&, unsigned long*>(unsigned long*, unsigned long*, __less<unsigned long>&);
extern template __attribute__ ((__visibility__("default"))) void __sort<__less<long long>&, long long*>(long long*, long long*, __less<long long>&);
extern template __attribute__ ((__visibility__("default"))) void __sort<__less<unsigned long long>&, unsigned long long*>(unsigned long long*, unsigned long long*, __less<unsigned long long>&);
extern template __attribute__ ((__visibility__("default"))) void __sort<__less<float>&, float*>(float*, float*, __less<float>&);
extern template __attribute__ ((__visibility__("default"))) void __sort<__less<double>&, double*>(double*, double*, __less<double>&);
extern template __attribute__ ((__visibility__("default"))) void __sort<__less<long double>&, long double*>(long double*, long double*, __less<long double>&);

extern template __attribute__ ((__visibility__("default"))) bool __insertion_sort_incomplete<__less<char>&, char*>(char*, char*, __less<char>&);
extern template __attribute__ ((__visibility__("default"))) bool __insertion_sort_incomplete<__less<wchar_t>&, wchar_t*>(wchar_t*, wchar_t*, __less<wchar_t>&);
extern template __attribute__ ((__visibility__("default"))) bool __insertion_sort_incomplete<__less<signed char>&, signed char*>(signed char*, signed char*, __less<signed char>&);
extern template __attribute__ ((__visibility__("default"))) bool __insertion_sort_incomplete<__less<unsigned char>&, unsigned char*>(unsigned char*, unsigned char*, __less<unsigned char>&);
extern template __attribute__ ((__visibility__("default"))) bool __insertion_sort_incomplete<__less<short>&, short*>(short*, short*, __less<short>&);
extern template __attribute__ ((__visibility__("default"))) bool __insertion_sort_incomplete<__less<unsigned short>&, unsigned short*>(unsigned short*, unsigned short*, __less<unsigned short>&);
extern template __attribute__ ((__visibility__("default"))) bool __insertion_sort_incomplete<__less<int>&, int*>(int*, int*, __less<int>&);
extern template __attribute__ ((__visibility__("default"))) bool __insertion_sort_incomplete<__less<unsigned>&, unsigned*>(unsigned*, unsigned*, __less<unsigned>&);
extern template __attribute__ ((__visibility__("default"))) bool __insertion_sort_incomplete<__less<long>&, long*>(long*, long*, __less<long>&);
extern template __attribute__ ((__visibility__("default"))) bool __insertion_sort_incomplete<__less<unsigned long>&, unsigned long*>(unsigned long*, unsigned long*, __less<unsigned long>&);
extern template __attribute__ ((__visibility__("default"))) bool __insertion_sort_incomplete<__less<long long>&, long long*>(long long*, long long*, __less<long long>&);
extern template __attribute__ ((__visibility__("default"))) bool __insertion_sort_incomplete<__less<unsigned long long>&, unsigned long long*>(unsigned long long*, unsigned long long*, __less<unsigned long long>&);
extern template __attribute__ ((__visibility__("default"))) bool __insertion_sort_incomplete<__less<float>&, float*>(float*, float*, __less<float>&);
extern template __attribute__ ((__visibility__("default"))) bool __insertion_sort_incomplete<__less<double>&, double*>(double*, double*, __less<double>&);
extern template __attribute__ ((__visibility__("default"))) bool __insertion_sort_incomplete<__less<long double>&, long double*>(long double*, long double*, __less<long double>&);

extern template __attribute__ ((__visibility__("default"))) unsigned __sort5<__less<long double>&, long double*>(long double*, long double*, long double*, long double*, long double*, __less<long double>&);



template <class _Compare, class _ForwardIterator, class _Tp>
                              _ForwardIterator
__lower_bound(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_, _Compare __comp)
{
    typedef typename iterator_traits<_ForwardIterator>::difference_type difference_type;
    difference_type __len = std::__1::distance(__first, __last);
    while (__len != 0)
    {
        difference_type __l2 = std::__1::__half_positive(__len);
        _ForwardIterator __m = __first;
        std::__1::advance(__m, __l2);
        if (__comp(*__m, __value_))
        {
            __first = ++__m;
            __len -= __l2 + 1;
        }
        else
            __len = __l2;
    }
    return __first;
}

template <class _ForwardIterator, class _Tp, class _Compare>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator
lower_bound(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_, _Compare __comp)
{
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    return __lower_bound<_Comp_ref>(__first, __last, __value_, __comp);
}

template <class _ForwardIterator, class _Tp>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator
lower_bound(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_)
{
    return std::__1::lower_bound(__first, __last, __value_,
                             __less<typename iterator_traits<_ForwardIterator>::value_type, _Tp>());
}



template <class _Compare, class _ForwardIterator, class _Tp>
                              _ForwardIterator
__upper_bound(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_, _Compare __comp)
{
    typedef typename iterator_traits<_ForwardIterator>::difference_type difference_type;
    difference_type __len = std::__1::distance(__first, __last);
    while (__len != 0)
    {
        difference_type __l2 = std::__1::__half_positive(__len);
        _ForwardIterator __m = __first;
        std::__1::advance(__m, __l2);
        if (__comp(__value_, *__m))
            __len = __l2;
        else
        {
            __first = ++__m;
            __len -= __l2 + 1;
        }
    }
    return __first;
}

template <class _ForwardIterator, class _Tp, class _Compare>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator
upper_bound(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_, _Compare __comp)
{
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    return __upper_bound<_Comp_ref>(__first, __last, __value_, __comp);
}

template <class _ForwardIterator, class _Tp>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_ForwardIterator
upper_bound(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_)
{
    return std::__1::upper_bound(__first, __last, __value_,
                             __less<_Tp, typename iterator_traits<_ForwardIterator>::value_type>());
}



template <class _Compare, class _ForwardIterator, class _Tp>
                              pair<_ForwardIterator, _ForwardIterator>
__equal_range(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_, _Compare __comp)
{
    typedef typename iterator_traits<_ForwardIterator>::difference_type difference_type;
    difference_type __len = std::__1::distance(__first, __last);
    while (__len != 0)
    {
        difference_type __l2 = std::__1::__half_positive(__len);
        _ForwardIterator __m = __first;
        std::__1::advance(__m, __l2);
        if (__comp(*__m, __value_))
        {
            __first = ++__m;
            __len -= __l2 + 1;
        }
        else if (__comp(__value_, *__m))
        {
            __last = __m;
            __len = __l2;
        }
        else
        {
            _ForwardIterator __mp1 = __m;
            return pair<_ForwardIterator, _ForwardIterator>
                   (
                      __lower_bound<_Compare>(__first, __m, __value_, __comp),
                      __upper_bound<_Compare>(++__mp1, __last, __value_, __comp)
                   );
        }
    }
    return pair<_ForwardIterator, _ForwardIterator>(__first, __first);
}

template <class _ForwardIterator, class _Tp, class _Compare>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
pair<_ForwardIterator, _ForwardIterator>
equal_range(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_, _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    return __equal_range<_Comp_ref>(__first, __last, __value_, __comp);
}

template <class _ForwardIterator, class _Tp>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
pair<_ForwardIterator, _ForwardIterator>
equal_range(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_)
{
    return std::__1::equal_range(__first, __last, __value_,
                             __less<typename iterator_traits<_ForwardIterator>::value_type, _Tp>());
}



template <class _Compare, class _ForwardIterator, class _Tp>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
__binary_search(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_, _Compare __comp)
{
    __first = __lower_bound<_Compare>(__first, __last, __value_, __comp);
    return __first != __last && !__comp(__value_, *__first);
}

template <class _ForwardIterator, class _Tp, class _Compare>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
binary_search(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_, _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    return __binary_search<_Comp_ref>(__first, __last, __value_, __comp);
}

template <class _ForwardIterator, class _Tp>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
binary_search(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_)
{
    return std::__1::binary_search(__first, __last, __value_,
                             __less<typename iterator_traits<_ForwardIterator>::value_type, _Tp>());
}



template <class _Compare, class _InputIterator1, class _InputIterator2, class _OutputIterator>
_OutputIterator
__merge(_InputIterator1 __first1, _InputIterator1 __last1,
        _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
    for (; __first1 != __last1; ++__result)
    {
        if (__first2 == __last2)
            return std::__1::copy(__first1, __last1, __result);
        if (__comp(*__first2, *__first1))
        {
            *__result = *__first2;
            ++__first2;
        }
        else
        {
            *__result = *__first1;
            ++__first1;
        }
    }
    return std::__1::copy(__first2, __last2, __result);
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator, class _Compare>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
merge(_InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    return std::__1::__merge<_Comp_ref>(__first1, __last1, __first2, __last2, __result, __comp);
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
merge(_InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result)
{
    typedef typename iterator_traits<_InputIterator1>::value_type __v1;
    typedef typename iterator_traits<_InputIterator2>::value_type __v2;
    return std::__1::merge(__first1, __last1, __first2, __last2, __result, __less<__v1, __v2>());
}



template <class _Compare, class _InputIterator1, class _InputIterator2,
          class _OutputIterator>
void __half_inplace_merge(_InputIterator1 __first1, _InputIterator1 __last1,
                          _InputIterator2 __first2, _InputIterator2 __last2,
                          _OutputIterator __result, _Compare __comp)
{
    for (; __first1 != __last1; ++__result)
    {
        if (__first2 == __last2)
        {
            std::__1::move(__first1, __last1, __result);
            return;
        }

        if (__comp(*__first2, *__first1))
        {
            *__result = std::__1::move(*__first2);
            ++__first2;
        }
        else
        {
            *__result = std::__1::move(*__first1);
            ++__first1;
        }
    }

}

template <class _Compare, class _BidirectionalIterator>
void
__buffered_inplace_merge(_BidirectionalIterator __first, _BidirectionalIterator __middle, _BidirectionalIterator __last,
                _Compare __comp, typename iterator_traits<_BidirectionalIterator>::difference_type __len1,
                                 typename iterator_traits<_BidirectionalIterator>::difference_type __len2,
                typename iterator_traits<_BidirectionalIterator>::value_type* __buff)
{
    typedef typename iterator_traits<_BidirectionalIterator>::value_type value_type;
    __destruct_n __d(0);
    unique_ptr<value_type, __destruct_n&> __h2(__buff, __d);
    if (__len1 <= __len2)
    {
        value_type* __p = __buff;
        for (_BidirectionalIterator __i = __first; __i != __middle; __d.__incr((value_type*)0), (void) ++__i, (void) ++__p)
            ::new(__p) value_type(std::__1::move(*__i));
        __half_inplace_merge(__buff, __p, __middle, __last, __first, __comp);
    }
    else
    {
        value_type* __p = __buff;
        for (_BidirectionalIterator __i = __middle; __i != __last; __d.__incr((value_type*)0), (void) ++__i, (void) ++__p)
            ::new(__p) value_type(std::__1::move(*__i));
        typedef reverse_iterator<_BidirectionalIterator> _RBi;
        typedef reverse_iterator<value_type*> _Rv;
        __half_inplace_merge(_Rv(__p), _Rv(__buff),
                             _RBi(__middle), _RBi(__first),
                             _RBi(__last), __invert<_Compare>(__comp));
    }
}

template <class _Compare, class _BidirectionalIterator>
void
__inplace_merge(_BidirectionalIterator __first, _BidirectionalIterator __middle, _BidirectionalIterator __last,
                _Compare __comp, typename iterator_traits<_BidirectionalIterator>::difference_type __len1,
                                 typename iterator_traits<_BidirectionalIterator>::difference_type __len2,
                typename iterator_traits<_BidirectionalIterator>::value_type* __buff, ptrdiff_t __buff_size)
{
    typedef typename iterator_traits<_BidirectionalIterator>::difference_type difference_type;
    while (true)
    {

        if (__len2 == 0)
            return;
        if (__len1 <= __buff_size || __len2 <= __buff_size)
            return __buffered_inplace_merge<_Compare>
                   (__first, __middle, __last, __comp, __len1, __len2, __buff);

        for (; true; ++__first, (void) --__len1)
        {
            if (__len1 == 0)
                return;
            if (__comp(*__middle, *__first))
                break;
        }

        _BidirectionalIterator __m1;
        _BidirectionalIterator __m2;
        difference_type __len11;
        difference_type __len21;

        if (__len1 < __len2)
        {
            __len21 = __len2 / 2;
            __m2 = __middle;
            std::__1::advance(__m2, __len21);
            __m1 = __upper_bound<_Compare>(__first, __middle, *__m2, __comp);
            __len11 = std::__1::distance(__first, __m1);
        }
        else
        {
            if (__len1 == 1)
            {

                swap(*__first, *__middle);
                return;
            }

            __len11 = __len1 / 2;
            __m1 = __first;
            std::__1::advance(__m1, __len11);
            __m2 = __lower_bound<_Compare>(__middle, __last, *__m1, __comp);
            __len21 = std::__1::distance(__middle, __m2);
        }
        difference_type __len12 = __len1 - __len11;
        difference_type __len22 = __len2 - __len21;


        __middle = std::__1::rotate(__m1, __middle, __m2);


        if (__len11 + __len21 < __len12 + __len22)
        {
            __inplace_merge<_Compare>(__first, __m1, __middle, __comp, __len11, __len21, __buff, __buff_size);

            __first = __middle;
            __middle = __m2;
            __len1 = __len12;
            __len2 = __len22;
        }
        else
        {
            __inplace_merge<_Compare>(__middle, __m2, __last, __comp, __len12, __len22, __buff, __buff_size);

            __last = __middle;
            __middle = __m1;
            __len1 = __len11;
            __len2 = __len21;
        }
    }
}

template <class _BidirectionalIterator, class _Compare>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
inplace_merge(_BidirectionalIterator __first, _BidirectionalIterator __middle, _BidirectionalIterator __last,
              _Compare __comp)
{
    typedef typename iterator_traits<_BidirectionalIterator>::value_type value_type;
    typedef typename iterator_traits<_BidirectionalIterator>::difference_type difference_type;
    difference_type __len1 = std::__1::distance(__first, __middle);
    difference_type __len2 = std::__1::distance(__middle, __last);
    difference_type __buf_size = std::__1::min(__len1, __len2);
    pair<value_type*, ptrdiff_t> __buf = std::__1::get_temporary_buffer<value_type>(__buf_size);
    unique_ptr<value_type, __return_temporary_buffer> __h(__buf.first);
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    return std::__1::__inplace_merge<_Comp_ref>(__first, __middle, __last, __comp, __len1, __len2,
                                            __buf.first, __buf.second);
}

template <class _BidirectionalIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
inplace_merge(_BidirectionalIterator __first, _BidirectionalIterator __middle, _BidirectionalIterator __last)
{
    std::__1::inplace_merge(__first, __middle, __last,
                        __less<typename iterator_traits<_BidirectionalIterator>::value_type>());
}



template <class _Compare, class _InputIterator1, class _InputIterator2>
void
__merge_move_construct(_InputIterator1 __first1, _InputIterator1 __last1,
        _InputIterator2 __first2, _InputIterator2 __last2,
        typename iterator_traits<_InputIterator1>::value_type* __result, _Compare __comp)
{
    typedef typename iterator_traits<_InputIterator1>::value_type value_type;
    __destruct_n __d(0);
    unique_ptr<value_type, __destruct_n&> __h(__result, __d);
    for (; true; ++__result)
    {
        if (__first1 == __last1)
        {
            for (; __first2 != __last2; ++__first2, ++__result, (void) __d.__incr((value_type*)0))
                ::new (__result) value_type(std::__1::move(*__first2));
            __h.release();
            return;
        }
        if (__first2 == __last2)
        {
            for (; __first1 != __last1; ++__first1, ++__result, (void) __d.__incr((value_type*)0))
                ::new (__result) value_type(std::__1::move(*__first1));
            __h.release();
            return;
        }
        if (__comp(*__first2, *__first1))
        {
            ::new (__result) value_type(std::__1::move(*__first2));
            __d.__incr((value_type*)0);
            ++__first2;
        }
        else
        {
            ::new (__result) value_type(std::__1::move(*__first1));
            __d.__incr((value_type*)0);
            ++__first1;
        }
    }
}

template <class _Compare, class _InputIterator1, class _InputIterator2, class _OutputIterator>
void
__merge_move_assign(_InputIterator1 __first1, _InputIterator1 __last1,
        _InputIterator2 __first2, _InputIterator2 __last2,
        _OutputIterator __result, _Compare __comp)
{
    for (; __first1 != __last1; ++__result)
    {
        if (__first2 == __last2)
        {
            for (; __first1 != __last1; ++__first1, (void) ++__result)
                *__result = std::__1::move(*__first1);
            return;
        }
        if (__comp(*__first2, *__first1))
        {
            *__result = std::__1::move(*__first2);
            ++__first2;
        }
        else
        {
            *__result = std::__1::move(*__first1);
            ++__first1;
        }
    }
    for (; __first2 != __last2; ++__first2, (void) ++__result)
        *__result = std::__1::move(*__first2);
}

template <class _Compare, class _RandomAccessIterator>
void
__stable_sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp,
              typename iterator_traits<_RandomAccessIterator>::difference_type __len,
              typename iterator_traits<_RandomAccessIterator>::value_type* __buff, ptrdiff_t __buff_size);

template <class _Compare, class _RandomAccessIterator>
void
__stable_sort_move(_RandomAccessIterator __first1, _RandomAccessIterator __last1, _Compare __comp,
                   typename iterator_traits<_RandomAccessIterator>::difference_type __len,
                   typename iterator_traits<_RandomAccessIterator>::value_type* __first2)
{
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;
    switch (__len)
    {
    case 0:
        return;
    case 1:
        ::new(__first2) value_type(std::__1::move(*__first1));
        return;
    case 2:
        __destruct_n __d(0);
        unique_ptr<value_type, __destruct_n&> __h2(__first2, __d);
        if (__comp(*--__last1, *__first1))
        {
            ::new(__first2) value_type(std::__1::move(*__last1));
            __d.__incr((value_type*)0);
            ++__first2;
            ::new(__first2) value_type(std::__1::move(*__first1));
        }
        else
        {
            ::new(__first2) value_type(std::__1::move(*__first1));
            __d.__incr((value_type*)0);
            ++__first2;
            ::new(__first2) value_type(std::__1::move(*__last1));
        }
        __h2.release();
        return;
    }
    if (__len <= 8)
    {
        __insertion_sort_move<_Compare>(__first1, __last1, __first2, __comp);
        return;
    }
    typename iterator_traits<_RandomAccessIterator>::difference_type __l2 = __len / 2;
    _RandomAccessIterator __m = __first1 + __l2;
    __stable_sort<_Compare>(__first1, __m, __comp, __l2, __first2, __l2);
    __stable_sort<_Compare>(__m, __last1, __comp, __len - __l2, __first2 + __l2, __len - __l2);
    __merge_move_construct<_Compare>(__first1, __m, __m, __last1, __first2, __comp);
}

template <class _Tp>
struct __stable_sort_switch
{
    static const unsigned value = 128*is_trivially_copy_assignable<_Tp>::value;
};

template <class _Compare, class _RandomAccessIterator>
void
__stable_sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp,
              typename iterator_traits<_RandomAccessIterator>::difference_type __len,
              typename iterator_traits<_RandomAccessIterator>::value_type* __buff, ptrdiff_t __buff_size)
{
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    switch (__len)
    {
    case 0:
    case 1:
        return;
    case 2:
        if (__comp(*--__last, *__first))
            swap(*__first, *__last);
        return;
    }
    if (__len <= static_cast<difference_type>(__stable_sort_switch<value_type>::value))
    {
        __insertion_sort<_Compare>(__first, __last, __comp);
        return;
    }
    typename iterator_traits<_RandomAccessIterator>::difference_type __l2 = __len / 2;
    _RandomAccessIterator __m = __first + __l2;
    if (__len <= __buff_size)
    {
        __destruct_n __d(0);
        unique_ptr<value_type, __destruct_n&> __h2(__buff, __d);
        __stable_sort_move<_Compare>(__first, __m, __comp, __l2, __buff);
        __d.__set(__l2, (value_type*)0);
        __stable_sort_move<_Compare>(__m, __last, __comp, __len - __l2, __buff + __l2);
        __d.__set(__len, (value_type*)0);
        __merge_move_assign<_Compare>(__buff, __buff + __l2, __buff + __l2, __buff + __len, __first, __comp);





        return;
    }
    __stable_sort<_Compare>(__first, __m, __comp, __l2, __buff, __buff_size);
    __stable_sort<_Compare>(__m, __last, __comp, __len - __l2, __buff, __buff_size);
    __inplace_merge<_Compare>(__first, __m, __last, __comp, __l2, __len - __l2, __buff, __buff_size);
}

template <class _RandomAccessIterator, class _Compare>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
stable_sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    difference_type __len = __last - __first;
    pair<value_type*, ptrdiff_t> __buf(0, 0);
    unique_ptr<value_type, __return_temporary_buffer> __h;
    if (__len > static_cast<difference_type>(__stable_sort_switch<value_type>::value))
    {
        __buf = std::__1::get_temporary_buffer<value_type>(__len);
        __h.reset(__buf.first);
    }
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    __stable_sort<_Comp_ref>(__first, __last, __comp, __len, __buf.first, __buf.second);
}

template <class _RandomAccessIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
stable_sort(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    std::__1::stable_sort(__first, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}



template <class _RandomAccessIterator, class _Compare>
                                                    _RandomAccessIterator
is_heap_until(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    typedef typename std::__1::iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    difference_type __len = __last - __first;
    difference_type __p = 0;
    difference_type __c = 1;
    _RandomAccessIterator __pp = __first;
    while (__c < __len)
    {
        _RandomAccessIterator __cp = __first + __c;
        if (__comp(*__pp, *__cp))
            return __cp;
        ++__c;
        ++__cp;
        if (__c == __len)
            return __last;
        if (__comp(*__pp, *__cp))
            return __cp;
        ++__p;
        ++__pp;
        __c = 2 * __p + 1;
    }
    return __last;
}

template<class _RandomAccessIterator>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_RandomAccessIterator
is_heap_until(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    return std::__1::is_heap_until(__first, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}



template <class _RandomAccessIterator, class _Compare>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
is_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    return std::__1::is_heap_until(__first, __last, __comp) == __last;
}

template<class _RandomAccessIterator>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
is_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    return std::__1::is_heap(__first, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}



template <class _Compare, class _RandomAccessIterator>
void
__sift_up(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp,
          typename iterator_traits<_RandomAccessIterator>::difference_type __len)
{
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;
    if (__len > 1)
    {
        __len = (__len - 2) / 2;
        _RandomAccessIterator __ptr = __first + __len;
        if (__comp(*__ptr, *--__last))
        {
            value_type __t(std::__1::move(*__last));
            do
            {
                *__last = std::__1::move(*__ptr);
                __last = __ptr;
                if (__len == 0)
                    break;
                __len = (__len - 1) / 2;
                __ptr = __first + __len;
            } while (__comp(*__ptr, __t));
            *__last = std::__1::move(__t);
        }
    }
}

template <class _RandomAccessIterator, class _Compare>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
push_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    __sift_up<_Comp_ref>(__first, __last, __comp, __last - __first);
}

template <class _RandomAccessIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
push_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    std::__1::push_heap(__first, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}



template <class _Compare, class _RandomAccessIterator>
void
__sift_down(_RandomAccessIterator __first, _RandomAccessIterator ,
            _Compare __comp,
            typename iterator_traits<_RandomAccessIterator>::difference_type __len,
            _RandomAccessIterator __start)
{
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;


    difference_type __child = __start - __first;

    if (__len < 2 || (__len - 2) / 2 < __child)
        return;

    __child = 2 * __child + 1;
    _RandomAccessIterator __child_i = __first + __child;

    if ((__child + 1) < __len && __comp(*__child_i, *(__child_i + 1))) {

        ++__child_i;
        ++__child;
    }


    if (__comp(*__child_i, *__start))

        return;

    value_type __top(std::__1::move(*__start));
    do
    {

        *__start = std::__1::move(*__child_i);
        __start = __child_i;

        if ((__len - 2) / 2 < __child)
            break;


        __child = 2 * __child + 1;
        __child_i = __first + __child;

        if ((__child + 1) < __len && __comp(*__child_i, *(__child_i + 1))) {

            ++__child_i;
            ++__child;
        }


    } while (!__comp(*__child_i, __top));
    *__start = std::__1::move(__top);
}

template <class _Compare, class _RandomAccessIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
__pop_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp,
           typename iterator_traits<_RandomAccessIterator>::difference_type __len)
{
    if (__len > 1)
    {
        swap(*__first, *--__last);
        __sift_down<_Compare>(__first, __last, __comp, __len - 1, __first);
    }
}

template <class _RandomAccessIterator, class _Compare>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
pop_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    __pop_heap<_Comp_ref>(__first, __last, __comp, __last - __first);
}

template <class _RandomAccessIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
pop_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    std::__1::pop_heap(__first, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}



template <class _Compare, class _RandomAccessIterator>
void
__make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    difference_type __n = __last - __first;
    if (__n > 1)
    {

        for (difference_type __start = (__n - 2) / 2; __start >= 0; --__start)
        {
            __sift_down<_Compare>(__first, __last, __comp, __n, __first + __start);
        }
    }
}

template <class _RandomAccessIterator, class _Compare>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    __make_heap<_Comp_ref>(__first, __last, __comp);
}

template <class _RandomAccessIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    std::__1::make_heap(__first, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}



template <class _Compare, class _RandomAccessIterator>
void
__sort_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    for (difference_type __n = __last - __first; __n > 1; --__last, (void) --__n)
        __pop_heap<_Compare>(__first, __last, __comp, __n);
}

template <class _RandomAccessIterator, class _Compare>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
sort_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    __sort_heap<_Comp_ref>(__first, __last, __comp);
}

template <class _RandomAccessIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
sort_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    std::__1::sort_heap(__first, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}



template <class _Compare, class _RandomAccessIterator>
void
__partial_sort(_RandomAccessIterator __first, _RandomAccessIterator __middle, _RandomAccessIterator __last,
             _Compare __comp)
{
    __make_heap<_Compare>(__first, __middle, __comp);
    typename iterator_traits<_RandomAccessIterator>::difference_type __len = __middle - __first;
    for (_RandomAccessIterator __i = __middle; __i != __last; ++__i)
    {
        if (__comp(*__i, *__first))
        {
            swap(*__i, *__first);
            __sift_down<_Compare>(__first, __middle, __comp, __len, __first);
        }
    }
    __sort_heap<_Compare>(__first, __middle, __comp);
}

template <class _RandomAccessIterator, class _Compare>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
partial_sort(_RandomAccessIterator __first, _RandomAccessIterator __middle, _RandomAccessIterator __last,
             _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    __partial_sort<_Comp_ref>(__first, __middle, __last, __comp);
}

template <class _RandomAccessIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
partial_sort(_RandomAccessIterator __first, _RandomAccessIterator __middle, _RandomAccessIterator __last)
{
    std::__1::partial_sort(__first, __middle, __last,
                       __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}



template <class _Compare, class _InputIterator, class _RandomAccessIterator>
_RandomAccessIterator
__partial_sort_copy(_InputIterator __first, _InputIterator __last,
                    _RandomAccessIterator __result_first, _RandomAccessIterator __result_last, _Compare __comp)
{
    _RandomAccessIterator __r = __result_first;
    if (__r != __result_last)
    {
        for (; __first != __last && __r != __result_last; ++__first, (void) ++__r)
            *__r = *__first;
        __make_heap<_Compare>(__result_first, __r, __comp);
        typename iterator_traits<_RandomAccessIterator>::difference_type __len = __r - __result_first;
        for (; __first != __last; ++__first)
            if (__comp(*__first, *__result_first))
            {
                *__result_first = *__first;
                __sift_down<_Compare>(__result_first, __r, __comp, __len, __result_first);
            }
        __sort_heap<_Compare>(__result_first, __r, __comp);
    }
    return __r;
}

template <class _InputIterator, class _RandomAccessIterator, class _Compare>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_RandomAccessIterator
partial_sort_copy(_InputIterator __first, _InputIterator __last,
                  _RandomAccessIterator __result_first, _RandomAccessIterator __result_last, _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    return __partial_sort_copy<_Comp_ref>(__first, __last, __result_first, __result_last, __comp);
}

template <class _InputIterator, class _RandomAccessIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_RandomAccessIterator
partial_sort_copy(_InputIterator __first, _InputIterator __last,
                  _RandomAccessIterator __result_first, _RandomAccessIterator __result_last)
{
    return std::__1::partial_sort_copy(__first, __last, __result_first, __result_last,
                                   __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}



template <class _Compare, class _RandomAccessIterator>
void
__nth_element(_RandomAccessIterator __first, _RandomAccessIterator __nth, _RandomAccessIterator __last, _Compare __comp)
{

    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    const difference_type __limit = 7;
    while (true)
    {
    __restart:
        if (__nth == __last)
            return;
        difference_type __len = __last - __first;
        switch (__len)
        {
        case 0:
        case 1:
            return;
        case 2:
            if (__comp(*--__last, *__first))
                swap(*__first, *__last);
            return;
        case 3:
            {
            _RandomAccessIterator __m = __first;
            std::__1::__sort3<_Compare>(__first, ++__m, --__last, __comp);
            return;
            }
        }
        if (__len <= __limit)
        {
            __selection_sort<_Compare>(__first, __last, __comp);
            return;
        }

        _RandomAccessIterator __m = __first + __len/2;
        _RandomAccessIterator __lm1 = __last;
        unsigned __n_swaps = std::__1::__sort3<_Compare>(__first, __m, --__lm1, __comp);



        _RandomAccessIterator __i = __first;
        _RandomAccessIterator __j = __lm1;



        if (!__comp(*__i, *__m))
        {


            while (true)
            {
                if (__i == --__j)
                {


                    ++__i;
                    __j = __last;
                    if (!__comp(*__first, *--__j))
                    {
                        while (true)
                        {
                            if (__i == __j)
                                return;
                            if (__comp(*__first, *__i))
                            {
                                swap(*__i, *__j);
                                ++__n_swaps;
                                ++__i;
                                break;
                            }
                            ++__i;
                        }
                    }

                    if (__i == __j)
                        return;
                    while (true)
                    {
                        while (!__comp(*__first, *__i))
                            ++__i;
                        while (__comp(*__first, *--__j))
                            ;
                        if (__i >= __j)
                            break;
                        swap(*__i, *__j);
                        ++__n_swaps;
                        ++__i;
                    }


                    if (__nth < __i)
                        return;


                    __first = __i;
                    goto __restart;
                }
                if (__comp(*__j, *__m))
                {
                    swap(*__i, *__j);
                    ++__n_swaps;
                    break;
                }
            }
        }
        ++__i;


        if (__i < __j)
        {

            while (true)
            {

                while (__comp(*__i, *__m))
                    ++__i;

                while (!__comp(*--__j, *__m))
                    ;
                if (__i >= __j)
                    break;
                swap(*__i, *__j);
                ++__n_swaps;


                if (__m == __i)
                    __m = __j;
                ++__i;
            }
        }

        if (__i != __m && __comp(*__m, *__i))
        {
            swap(*__i, *__m);
            ++__n_swaps;
        }

        if (__nth == __i)
            return;
        if (__n_swaps == 0)
        {

            if (__nth < __i)
            {

                __j = __m = __first;
                while (++__j != __i)
                {
                    if (__comp(*__j, *__m))

                        goto not_sorted;
                    __m = __j;
                }

                return;
            }
            else
            {

                __j = __m = __i;
                while (++__j != __last)
                {
                    if (__comp(*__j, *__m))

                        goto not_sorted;
                    __m = __j;
                }

                return;
            }
        }
not_sorted:

        if (__nth < __i)
        {

            __last = __i;
        }
        else
        {

            __first = ++__i;
        }
    }
}

template <class _RandomAccessIterator, class _Compare>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
nth_element(_RandomAccessIterator __first, _RandomAccessIterator __nth, _RandomAccessIterator __last, _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    __nth_element<_Comp_ref>(__first, __nth, __last, __comp);
}

template <class _RandomAccessIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
nth_element(_RandomAccessIterator __first, _RandomAccessIterator __nth, _RandomAccessIterator __last)
{
    std::__1::nth_element(__first, __nth, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}



template <class _Compare, class _InputIterator1, class _InputIterator2>
                              bool
__includes(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _InputIterator2 __last2,
           _Compare __comp)
{
    for (; __first2 != __last2; ++__first1)
    {
        if (__first1 == __last1 || __comp(*__first2, *__first1))
            return false;
        if (!__comp(*__first1, *__first2))
            ++__first2;
    }
    return true;
}

template <class _InputIterator1, class _InputIterator2, class _Compare>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
includes(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _InputIterator2 __last2,
         _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    return __includes<_Comp_ref>(__first1, __last1, __first2, __last2, __comp);
}

template <class _InputIterator1, class _InputIterator2>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
includes(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _InputIterator2 __last2)
{
    return std::__1::includes(__first1, __last1, __first2, __last2,
                          __less<typename iterator_traits<_InputIterator1>::value_type,
                                 typename iterator_traits<_InputIterator2>::value_type>());
}



template <class _Compare, class _InputIterator1, class _InputIterator2, class _OutputIterator>
_OutputIterator
__set_union(_InputIterator1 __first1, _InputIterator1 __last1,
            _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
    for (; __first1 != __last1; ++__result)
    {
        if (__first2 == __last2)
            return std::__1::copy(__first1, __last1, __result);
        if (__comp(*__first2, *__first1))
        {
            *__result = *__first2;
            ++__first2;
        }
        else
        {
            if (!__comp(*__first1, *__first2))
                ++__first2;
            *__result = *__first1;
            ++__first1;
        }
    }
    return std::__1::copy(__first2, __last2, __result);
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator, class _Compare>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
set_union(_InputIterator1 __first1, _InputIterator1 __last1,
          _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    return __set_union<_Comp_ref>(__first1, __last1, __first2, __last2, __result, __comp);
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
set_union(_InputIterator1 __first1, _InputIterator1 __last1,
          _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result)
{
    return std::__1::set_union(__first1, __last1, __first2, __last2, __result,
                          __less<typename iterator_traits<_InputIterator1>::value_type,
                                 typename iterator_traits<_InputIterator2>::value_type>());
}



template <class _Compare, class _InputIterator1, class _InputIterator2, class _OutputIterator>
                              _OutputIterator
__set_intersection(_InputIterator1 __first1, _InputIterator1 __last1,
                   _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
    while (__first1 != __last1 && __first2 != __last2)
    {
        if (__comp(*__first1, *__first2))
            ++__first1;
        else
        {
            if (!__comp(*__first2, *__first1))
            {
                *__result = *__first1;
                ++__result;
                ++__first1;
            }
            ++__first2;
        }
    }
    return __result;
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator, class _Compare>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
set_intersection(_InputIterator1 __first1, _InputIterator1 __last1,
                 _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    return __set_intersection<_Comp_ref>(__first1, __last1, __first2, __last2, __result, __comp);
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
set_intersection(_InputIterator1 __first1, _InputIterator1 __last1,
                 _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result)
{
    return std::__1::set_intersection(__first1, __last1, __first2, __last2, __result,
                                  __less<typename iterator_traits<_InputIterator1>::value_type,
                                         typename iterator_traits<_InputIterator2>::value_type>());
}



template <class _Compare, class _InputIterator1, class _InputIterator2, class _OutputIterator>
_OutputIterator
__set_difference(_InputIterator1 __first1, _InputIterator1 __last1,
                 _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
    while (__first1 != __last1)
    {
        if (__first2 == __last2)
            return std::__1::copy(__first1, __last1, __result);
        if (__comp(*__first1, *__first2))
        {
            *__result = *__first1;
            ++__result;
            ++__first1;
        }
        else
        {
            if (!__comp(*__first2, *__first1))
                ++__first1;
            ++__first2;
        }
    }
    return __result;
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator, class _Compare>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
set_difference(_InputIterator1 __first1, _InputIterator1 __last1,
               _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    return __set_difference<_Comp_ref>(__first1, __last1, __first2, __last2, __result, __comp);
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
set_difference(_InputIterator1 __first1, _InputIterator1 __last1,
               _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result)
{
    return std::__1::set_difference(__first1, __last1, __first2, __last2, __result,
                                __less<typename iterator_traits<_InputIterator1>::value_type,
                                       typename iterator_traits<_InputIterator2>::value_type>());
}



template <class _Compare, class _InputIterator1, class _InputIterator2, class _OutputIterator>
_OutputIterator
__set_symmetric_difference(_InputIterator1 __first1, _InputIterator1 __last1,
                           _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
    while (__first1 != __last1)
    {
        if (__first2 == __last2)
            return std::__1::copy(__first1, __last1, __result);
        if (__comp(*__first1, *__first2))
        {
            *__result = *__first1;
            ++__result;
            ++__first1;
        }
        else
        {
            if (__comp(*__first2, *__first1))
            {
                *__result = *__first2;
                ++__result;
            }
            else
                ++__first1;
            ++__first2;
        }
    }
    return std::__1::copy(__first2, __last2, __result);
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator, class _Compare>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
set_symmetric_difference(_InputIterator1 __first1, _InputIterator1 __last1,
                         _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    return __set_symmetric_difference<_Comp_ref>(__first1, __last1, __first2, __last2, __result, __comp);
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
_OutputIterator
set_symmetric_difference(_InputIterator1 __first1, _InputIterator1 __last1,
                         _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result)
{
    return std::__1::set_symmetric_difference(__first1, __last1, __first2, __last2, __result,
                                          __less<typename iterator_traits<_InputIterator1>::value_type,
                                                 typename iterator_traits<_InputIterator2>::value_type>());
}



template <class _Compare, class _InputIterator1, class _InputIterator2>
                              bool
__lexicographical_compare(_InputIterator1 __first1, _InputIterator1 __last1,
                          _InputIterator2 __first2, _InputIterator2 __last2, _Compare __comp)
{
    for (; __first2 != __last2; ++__first1, (void) ++__first2)
    {
        if (__first1 == __last1 || __comp(*__first1, *__first2))
            return true;
        if (__comp(*__first2, *__first1))
            return false;
    }
    return false;
}

template <class _InputIterator1, class _InputIterator2, class _Compare>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
lexicographical_compare(_InputIterator1 __first1, _InputIterator1 __last1,
                        _InputIterator2 __first2, _InputIterator2 __last2, _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    return __lexicographical_compare<_Comp_ref>(__first1, __last1, __first2, __last2, __comp);
}

template <class _InputIterator1, class _InputIterator2>
                      inline
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
lexicographical_compare(_InputIterator1 __first1, _InputIterator1 __last1,
                        _InputIterator2 __first2, _InputIterator2 __last2)
{
    return std::__1::lexicographical_compare(__first1, __last1, __first2, __last2,
                                         __less<typename iterator_traits<_InputIterator1>::value_type,
                                                typename iterator_traits<_InputIterator2>::value_type>());
}



template <class _Compare, class _BidirectionalIterator>
bool
__next_permutation(_BidirectionalIterator __first, _BidirectionalIterator __last, _Compare __comp)
{
    _BidirectionalIterator __i = __last;
    if (__first == __last || __first == --__i)
        return false;
    while (true)
    {
        _BidirectionalIterator __ip1 = __i;
        if (__comp(*--__i, *__ip1))
        {
            _BidirectionalIterator __j = __last;
            while (!__comp(*__i, *--__j))
                ;
            swap(*__i, *__j);
            std::__1::reverse(__ip1, __last);
            return true;
        }
        if (__i == __first)
        {
            std::__1::reverse(__first, __last);
            return false;
        }
    }
}

template <class _BidirectionalIterator, class _Compare>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
next_permutation(_BidirectionalIterator __first, _BidirectionalIterator __last, _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    return __next_permutation<_Comp_ref>(__first, __last, __comp);
}

template <class _BidirectionalIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
next_permutation(_BidirectionalIterator __first, _BidirectionalIterator __last)
{
    return std::__1::next_permutation(__first, __last,
                                  __less<typename iterator_traits<_BidirectionalIterator>::value_type>());
}



template <class _Compare, class _BidirectionalIterator>
bool
__prev_permutation(_BidirectionalIterator __first, _BidirectionalIterator __last, _Compare __comp)
{
    _BidirectionalIterator __i = __last;
    if (__first == __last || __first == --__i)
        return false;
    while (true)
    {
        _BidirectionalIterator __ip1 = __i;
        if (__comp(*__ip1, *--__i))
        {
            _BidirectionalIterator __j = __last;
            while (!__comp(*--__j, *__i))
                ;
            swap(*__i, *__j);
            std::__1::reverse(__ip1, __last);
            return true;
        }
        if (__i == __first)
        {
            std::__1::reverse(__first, __last);
            return false;
        }
    }
}

template <class _BidirectionalIterator, class _Compare>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
prev_permutation(_BidirectionalIterator __first, _BidirectionalIterator __last, _Compare __comp)
{
    typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    return __prev_permutation<_Comp_ref>(__first, __last, __comp);
}

template <class _BidirectionalIterator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
prev_permutation(_BidirectionalIterator __first, _BidirectionalIterator __last)
{
    return std::__1::prev_permutation(__first, __last,
                                  __less<typename iterator_traits<_BidirectionalIterator>::value_type>());
}

} }










namespace std { inline namespace __1 {



using ::FILE;
using ::fpos_t;
using ::size_t;

using ::fclose;
using ::fflush;
using ::setbuf;
using ::setvbuf;
using ::fprintf;
using ::fscanf;
using ::snprintf;
using ::sprintf;
using ::sscanf;
using ::vfprintf;
using ::vfscanf;
using ::vsscanf;
using ::vsnprintf;
using ::vsprintf;
using ::fgetc;
using ::fgets;
using ::fputc;
using ::fputs;
using ::getc;
using ::putc;
using ::ungetc;
using ::fread;
using ::fwrite;
using ::fgetpos;
using ::fseek;
using ::fsetpos;
using ::ftell;
using ::rewind;
using ::clearerr;
using ::feof;
using ::ferror;
using ::perror;


using ::fopen;
using ::freopen;
using ::remove;
using ::rename;
using ::tmpfile;
using ::tmpnam;



using ::getchar;

using ::gets;

using ::scanf;
using ::vscanf;



using ::printf;
using ::putchar;
using ::puts;
using ::vprintf;

} }









namespace std { inline namespace __1 {



template <class _CharT>
struct __attribute__ ((__type_visibility__("default"))) char_traits
{
    typedef _CharT char_type;
    typedef int int_type;
    typedef streamoff off_type;
    typedef streampos pos_type;
    typedef mbstate_t state_type;

    static inline void
        assign(char_type& __c1, const char_type& __c2) throw() {__c1 = __c2;}
    static inline bool eq(char_type __c1, char_type __c2) throw()
        {return __c1 == __c2;}
    static inline bool lt(char_type __c1, char_type __c2) throw()
        {return __c1 < __c2;}

    static
    int compare(const char_type* __s1, const char_type* __s2, size_t __n);
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static
    size_t length(const char_type* __s);
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static
    const char_type* find(const char_type* __s, size_t __n, const char_type& __a);
    static
    char_type* move(char_type* __s1, const char_type* __s2, size_t __n);
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static
    char_type* copy(char_type* __s1, const char_type* __s2, size_t __n);
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static
    char_type* assign(char_type* __s, size_t __n, char_type __a);

    static inline int_type not_eof(int_type __c) throw()
        {return eq_int_type(__c, eof()) ? ~eof() : __c;}
    static inline char_type to_char_type(int_type __c) throw()
        {return char_type(__c);}
    static inline int_type to_int_type(char_type __c) throw()
        {return int_type(__c);}
    static inline bool eq_int_type(int_type __c1, int_type __c2) throw()
        {return __c1 == __c2;}
    static inline int_type eof() throw()
        {return int_type((-1));}
};

template <class _CharT>
                              int
char_traits<_CharT>::compare(const char_type* __s1, const char_type* __s2, size_t __n)
{
    for (; __n; --__n, ++__s1, ++__s2)
    {
        if (lt(*__s1, *__s2))
            return -1;
        if (lt(*__s2, *__s1))
            return 1;
    }
    return 0;
}

template <class _CharT>
inline
                              size_t
char_traits<_CharT>::length(const char_type* __s)
{
    size_t __len = 0;
    for (; !eq(*__s, char_type(0)); ++__s)
        ++__len;
    return __len;
}

template <class _CharT>
inline
                              const _CharT*
char_traits<_CharT>::find(const char_type* __s, size_t __n, const char_type& __a)
{
    for (; __n; --__n)
    {
        if (eq(*__s, __a))
            return __s;
        ++__s;
    }
    return 0;
}

template <class _CharT>
                              _CharT*
char_traits<_CharT>::move(char_type* __s1, const char_type* __s2, size_t __n)
{
    if (__n == 0) return __s1;
    char_type* __r = __s1;
    if (__s1 < __s2)
    {
        for (; __n; --__n, ++__s1, ++__s2)
            assign(*__s1, *__s2);
    }
    else if (__s2 < __s1)
    {
        __s1 += __n;
        __s2 += __n;
        for (; __n; --__n)
            assign(*--__s1, *--__s2);
    }
    return __r;
}

template <class _CharT>
inline
_CharT*
char_traits<_CharT>::copy(char_type* __s1, const char_type* __s2, size_t __n)
{
    ((void)0);
    char_type* __r = __s1;
    for (; __n; --__n, ++__s1, ++__s2)
        assign(*__s1, *__s2);
    return __r;
}

template <class _CharT>
inline
_CharT*
char_traits<_CharT>::assign(char_type* __s, size_t __n, char_type __a)
{
    char_type* __r = __s;
    for (; __n; --__n, ++__s)
        assign(*__s, __a);
    return __r;
}



template <class _CharT>
static inline
_CharT* __move_constexpr(_CharT* __s1, const _CharT* __s2, size_t __n) throw()
{
    if (__n == 0) return __s1;
    if (__s1 < __s2) {
      std::__1::copy(__s2, __s2 + __n, __s1);
    } else if (__s2 < __s1) {
      std::__1::copy_backward(__s2, __s2 + __n, __s1 + __n);
    }
    return __s1;
}

template <class _CharT>
static inline
_CharT* __copy_constexpr(_CharT* __s1, const _CharT* __s2, size_t __n) throw()
{
    std::__1::copy_n(__s2, __n, __s1);
    return __s1;
}

template <class _CharT>
static inline
_CharT* __assign_constexpr(_CharT* __s, size_t __n, _CharT __a) throw()
{
     std::__1::fill_n(__s, __n, __a);
     return __s;
}



template <>
struct __attribute__ ((__type_visibility__("default"))) char_traits<char>
{
    typedef char char_type;
    typedef int int_type;
    typedef streamoff off_type;
    typedef streampos pos_type;
    typedef mbstate_t state_type;

    static inline
    void assign(char_type& __c1, const char_type& __c2) throw() {__c1 = __c2;}
    static inline bool eq(char_type __c1, char_type __c2) throw()
            {return __c1 == __c2;}
    static inline bool lt(char_type __c1, char_type __c2) throw()
        {return (unsigned char)__c1 < (unsigned char)__c2;}

    static
    int compare(const char_type* __s1, const char_type* __s2, size_t __n) throw();
    static inline size_t
    length(const char_type* __s) throw() {return __builtin_strlen(__s);}
    static
    const char_type* find(const char_type* __s, size_t __n, const char_type& __a) throw();
    static inline
    char_type* move(char_type* __s1, const char_type* __s2, size_t __n) throw()
        {
            return __libcpp_is_constant_evaluated()
                       ? __move_constexpr(__s1, __s2, __n)
                       : __n == 0 ? __s1 : (char_type*)memmove(__s1, __s2, __n);
        }
    static inline
    char_type* copy(char_type* __s1, const char_type* __s2, size_t __n) throw()
        {
            ((void)0);
            return __libcpp_is_constant_evaluated()
                       ? __copy_constexpr(__s1, __s2, __n)
                       : __n == 0 ? __s1 : (char_type*)memcpy(__s1, __s2, __n);
        }
    static inline
    char_type* assign(char_type* __s, size_t __n, char_type __a) throw()
        {
            return __libcpp_is_constant_evaluated()
                       ? __assign_constexpr(__s, __n, __a)
                       : __n == 0 ? __s : (char_type*)memset(__s, to_int_type(__a), __n);
        }

    static inline int_type not_eof(int_type __c) throw()
        {return eq_int_type(__c, eof()) ? ~eof() : __c;}
    static inline char_type to_char_type(int_type __c) throw()
        {return char_type(__c);}
    static inline int_type to_int_type(char_type __c) throw()
        {return int_type((unsigned char)__c);}
    static inline bool eq_int_type(int_type __c1, int_type __c2) throw()
        {return __c1 == __c2;}
    static inline int_type eof() throw()
        {return int_type((-1));}
};

inline
int
char_traits<char>::compare(const char_type* __s1, const char_type* __s2, size_t __n) throw()
{
    if (__n == 0)
        return 0;



    return memcmp(__s1, __s2, __n);

}

inline
const char*
char_traits<char>::find(const char_type* __s, size_t __n, const char_type& __a) throw()
{
    if (__n == 0)
        return std::__1::__get_nullptr_t();



    return (const char_type*) memchr(__s, to_int_type(__a), __n);

}




template <>
struct __attribute__ ((__type_visibility__("default"))) char_traits<wchar_t>
{
    typedef wchar_t char_type;
    typedef wint_t int_type;
    typedef streamoff off_type;
    typedef streampos pos_type;
    typedef mbstate_t state_type;

    static inline
    void assign(char_type& __c1, const char_type& __c2) throw() {__c1 = __c2;}
    static inline bool eq(char_type __c1, char_type __c2) throw()
        {return __c1 == __c2;}
    static inline bool lt(char_type __c1, char_type __c2) throw()
        {return __c1 < __c2;}

    static
    int compare(const char_type* __s1, const char_type* __s2, size_t __n) throw();
    static
    size_t length(const char_type* __s) throw();
    static
    const char_type* find(const char_type* __s, size_t __n, const char_type& __a) throw();
    static inline
    char_type* move(char_type* __s1, const char_type* __s2, size_t __n) throw()
        {
            return __libcpp_is_constant_evaluated()
                       ? __move_constexpr(__s1, __s2, __n)
                       : __n == 0 ? __s1 : wmemmove(__s1, __s2, __n);
        }
    static inline
    char_type* copy(char_type* __s1, const char_type* __s2, size_t __n) throw()
        {
            ((void)0);
            return __libcpp_is_constant_evaluated()
                       ? __copy_constexpr(__s1, __s2, __n)
                       : __n == 0 ? __s1 : wmemcpy(__s1, __s2, __n);
        }
    static inline
    char_type* assign(char_type* __s, size_t __n, char_type __a) throw()
        {
            return __libcpp_is_constant_evaluated()
                       ? __assign_constexpr(__s, __n, __a)
                       : __n == 0 ? __s : wmemset(__s, __a, __n);
        }
    static inline int_type not_eof(int_type __c) throw()
        {return eq_int_type(__c, eof()) ? ~eof() : __c;}
    static inline char_type to_char_type(int_type __c) throw()
        {return char_type(__c);}
    static inline int_type to_int_type(char_type __c) throw()
        {return int_type(__c);}
    static inline bool eq_int_type(int_type __c1, int_type __c2) throw()
        {return __c1 == __c2;}
    static inline int_type eof() throw()
        {return int_type(((__darwin_wint_t)-1));}
};

inline
int
char_traits<wchar_t>::compare(const char_type* __s1, const char_type* __s2, size_t __n) throw()
{
    if (__n == 0)
        return 0;



    return wmemcmp(__s1, __s2, __n);

}


template <class _Traits>
__attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))

inline size_t __char_traits_length_checked(const typename _Traits::char_type* __s) throw() {



  return _Traits::length(__s);

}

inline
size_t
char_traits<wchar_t>::length(const char_type* __s) throw()
{



    return wcslen(__s);






}

inline
const wchar_t*
char_traits<wchar_t>::find(const char_type* __s, size_t __n, const char_type& __a) throw()
{
    if (__n == 0)
        return std::__1::__get_nullptr_t();



    return wmemchr(__s, __a, __n);

}

template <>
struct __attribute__ ((__type_visibility__("default"))) char_traits<char16_t>
{
    typedef char16_t char_type;
    typedef uint_least16_t int_type;
    typedef streamoff off_type;
    typedef u16streampos pos_type;
    typedef mbstate_t state_type;

    static inline
    void assign(char_type& __c1, const char_type& __c2) throw() {__c1 = __c2;}
    static inline bool eq(char_type __c1, char_type __c2) throw()
        {return __c1 == __c2;}
    static inline bool lt(char_type __c1, char_type __c2) throw()
        {return __c1 < __c2;}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static
    int compare(const char_type* __s1, const char_type* __s2, size_t __n) throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static
    size_t length(const char_type* __s) throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static
    const char_type* find(const char_type* __s, size_t __n, const char_type& __a) throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static char_type* move(char_type* __s1, const char_type* __s2, size_t __n) throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static char_type* copy(char_type* __s1, const char_type* __s2, size_t __n) throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static char_type* assign(char_type* __s, size_t __n, char_type __a) throw();

    static inline int_type not_eof(int_type __c) throw()
        {return eq_int_type(__c, eof()) ? ~eof() : __c;}
    static inline char_type to_char_type(int_type __c) throw()
        {return char_type(__c);}
    static inline int_type to_int_type(char_type __c) throw()
        {return int_type(__c);}
    static inline bool eq_int_type(int_type __c1, int_type __c2) throw()
        {return __c1 == __c2;}
    static inline int_type eof() throw()
        {return int_type(0xFFFF);}
};

inline
int
char_traits<char16_t>::compare(const char_type* __s1, const char_type* __s2, size_t __n) throw()
{
    for (; __n; --__n, ++__s1, ++__s2)
    {
        if (lt(*__s1, *__s2))
            return -1;
        if (lt(*__s2, *__s1))
            return 1;
    }
    return 0;
}

inline
size_t
char_traits<char16_t>::length(const char_type* __s) throw()
{
    size_t __len = 0;
    for (; !eq(*__s, char_type(0)); ++__s)
        ++__len;
    return __len;
}

inline
const char16_t*
char_traits<char16_t>::find(const char_type* __s, size_t __n, const char_type& __a) throw()
{
    for (; __n; --__n)
    {
        if (eq(*__s, __a))
            return __s;
        ++__s;
    }
    return 0;
}

inline
char16_t*
char_traits<char16_t>::move(char_type* __s1, const char_type* __s2, size_t __n) throw()
{
    if (__n == 0) return __s1;
    char_type* __r = __s1;
    if (__s1 < __s2)
    {
        for (; __n; --__n, ++__s1, ++__s2)
            assign(*__s1, *__s2);
    }
    else if (__s2 < __s1)
    {
        __s1 += __n;
        __s2 += __n;
        for (; __n; --__n)
            assign(*--__s1, *--__s2);
    }
    return __r;
}

inline
char16_t*
char_traits<char16_t>::copy(char_type* __s1, const char_type* __s2, size_t __n) throw()
{
    ((void)0);
    char_type* __r = __s1;
    for (; __n; --__n, ++__s1, ++__s2)
        assign(*__s1, *__s2);
    return __r;
}

inline
char16_t*
char_traits<char16_t>::assign(char_type* __s, size_t __n, char_type __a) throw()
{
    char_type* __r = __s;
    for (; __n; --__n, ++__s)
        assign(*__s, __a);
    return __r;
}

template <>
struct __attribute__ ((__type_visibility__("default"))) char_traits<char32_t>
{
    typedef char32_t char_type;
    typedef uint_least32_t int_type;
    typedef streamoff off_type;
    typedef u32streampos pos_type;
    typedef mbstate_t state_type;

    static inline
    void assign(char_type& __c1, const char_type& __c2) throw() {__c1 = __c2;}
    static inline bool eq(char_type __c1, char_type __c2) throw()
        {return __c1 == __c2;}
    static inline bool lt(char_type __c1, char_type __c2) throw()
        {return __c1 < __c2;}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static
    int compare(const char_type* __s1, const char_type* __s2, size_t __n) throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static
    size_t length(const char_type* __s) throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) static
    const char_type* find(const char_type* __s, size_t __n, const char_type& __a) throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static char_type* move(char_type* __s1, const char_type* __s2, size_t __n) throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static char_type* copy(char_type* __s1, const char_type* __s2, size_t __n) throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    static char_type* assign(char_type* __s, size_t __n, char_type __a) throw();

    static inline int_type not_eof(int_type __c) throw()
        {return eq_int_type(__c, eof()) ? ~eof() : __c;}
    static inline char_type to_char_type(int_type __c) throw()
        {return char_type(__c);}
    static inline int_type to_int_type(char_type __c) throw()
        {return int_type(__c);}
    static inline bool eq_int_type(int_type __c1, int_type __c2) throw()
        {return __c1 == __c2;}
    static inline int_type eof() throw()
        {return int_type(0xFFFFFFFF);}
};

inline
int
char_traits<char32_t>::compare(const char_type* __s1, const char_type* __s2, size_t __n) throw()
{
    for (; __n; --__n, ++__s1, ++__s2)
    {
        if (lt(*__s1, *__s2))
            return -1;
        if (lt(*__s2, *__s1))
            return 1;
    }
    return 0;
}

inline
size_t
char_traits<char32_t>::length(const char_type* __s) throw()
{
    size_t __len = 0;
    for (; !eq(*__s, char_type(0)); ++__s)
        ++__len;
    return __len;
}

inline
const char32_t*
char_traits<char32_t>::find(const char_type* __s, size_t __n, const char_type& __a) throw()
{
    for (; __n; --__n)
    {
        if (eq(*__s, __a))
            return __s;
        ++__s;
    }
    return 0;
}

inline
char32_t*
char_traits<char32_t>::move(char_type* __s1, const char_type* __s2, size_t __n) throw()
{
    if (__n == 0) return __s1;
    char_type* __r = __s1;
    if (__s1 < __s2)
    {
        for (; __n; --__n, ++__s1, ++__s2)
            assign(*__s1, *__s2);
    }
    else if (__s2 < __s1)
    {
        __s1 += __n;
        __s2 += __n;
        for (; __n; --__n)
            assign(*--__s1, *--__s2);
    }
    return __r;
}

inline
char32_t*
char_traits<char32_t>::copy(char_type* __s1, const char_type* __s2, size_t __n) throw()
{
    ((void)0);
    char_type* __r = __s1;
    for (; __n; --__n, ++__s1, ++__s2)
        assign(*__s1, *__s2);
    return __r;
}

inline
char32_t*
char_traits<char32_t>::assign(char_type* __s, size_t __n, char_type __a) throw()
{
    char_type* __r = __s;
    for (; __n; --__n, ++__s)
        assign(*__s, __a);
    return __r;
}






template<class _CharT, class _SizeT, class _Traits, _SizeT __npos>
inline _SizeT __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__str_find(const _CharT *__p, _SizeT __sz,
             _CharT __c, _SizeT __pos) throw()
{
    if (__pos >= __sz)
        return __npos;
    const _CharT* __r = _Traits::find(__p + __pos, __sz - __pos, __c);
    if (__r == 0)
        return __npos;
    return static_cast<_SizeT>(__r - __p);
}

template <class _CharT, class _Traits>
inline const _CharT *
__search_substring(const _CharT *__first1, const _CharT *__last1,
                   const _CharT *__first2, const _CharT *__last2) {


  const ptrdiff_t __len2 = __last2 - __first2;
  if (__len2 == 0)
    return __first1;

  ptrdiff_t __len1 = __last1 - __first1;
  if (__len1 < __len2)
    return __last1;


  _CharT __f2 = *__first2;
  while (true) {
    __len1 = __last1 - __first1;

    if (__len1 < __len2)
      return __last1;


    __first1 = _Traits::find(__first1, __len1 - __len2 + 1, __f2);
    if (__first1 == 0)
      return __last1;






    if (_Traits::compare(__first1, __first2, __len2) == 0)
      return __first1;

    ++__first1;
  }
}

template<class _CharT, class _SizeT, class _Traits, _SizeT __npos>
inline _SizeT __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__str_find(const _CharT *__p, _SizeT __sz,
       const _CharT* __s, _SizeT __pos, _SizeT __n) throw()
{
    if (__pos > __sz)
        return __npos;

    if (__n == 0)
        return __pos;

    const _CharT *__r = __search_substring<_CharT, _Traits>(
        __p + __pos, __p + __sz, __s, __s + __n);

    if (__r == __p + __sz)
        return __npos;
    return static_cast<_SizeT>(__r - __p);
}




template<class _CharT, class _SizeT, class _Traits, _SizeT __npos>
inline _SizeT __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__str_rfind(const _CharT *__p, _SizeT __sz,
              _CharT __c, _SizeT __pos) throw()
{
    if (__sz < 1)
        return __npos;
    if (__pos < __sz)
        ++__pos;
    else
        __pos = __sz;
    for (const _CharT* __ps = __p + __pos; __ps != __p;)
    {
        if (_Traits::eq(*--__ps, __c))
            return static_cast<_SizeT>(__ps - __p);
    }
    return __npos;
}

template<class _CharT, class _SizeT, class _Traits, _SizeT __npos>
inline _SizeT __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__str_rfind(const _CharT *__p, _SizeT __sz,
        const _CharT* __s, _SizeT __pos, _SizeT __n) throw()
{
    __pos = std::__1::min(__pos, __sz);
    if (__n < __sz - __pos)
        __pos += __n;
    else
        __pos = __sz;
    const _CharT* __r = std::__1::__find_end(
                  __p, __p + __pos, __s, __s + __n, _Traits::eq,
                        random_access_iterator_tag(), random_access_iterator_tag());
    if (__n > 0 && __r == __p + __pos)
        return __npos;
    return static_cast<_SizeT>(__r - __p);
}


template<class _CharT, class _SizeT, class _Traits, _SizeT __npos>
inline _SizeT __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__str_find_first_of(const _CharT *__p, _SizeT __sz,
                const _CharT* __s, _SizeT __pos, _SizeT __n) throw()
{
    if (__pos >= __sz || __n == 0)
        return __npos;
    const _CharT* __r = std::__1::__find_first_of_ce
        (__p + __pos, __p + __sz, __s, __s + __n, _Traits::eq );
    if (__r == __p + __sz)
        return __npos;
    return static_cast<_SizeT>(__r - __p);
}



template<class _CharT, class _SizeT, class _Traits, _SizeT __npos>
inline _SizeT __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__str_find_last_of(const _CharT *__p, _SizeT __sz,
               const _CharT* __s, _SizeT __pos, _SizeT __n) throw()
    {
    if (__n != 0)
    {
        if (__pos < __sz)
            ++__pos;
        else
            __pos = __sz;
        for (const _CharT* __ps = __p + __pos; __ps != __p;)
        {
            const _CharT* __r = _Traits::find(__s, __n, *--__ps);
            if (__r)
                return static_cast<_SizeT>(__ps - __p);
        }
    }
    return __npos;
}



template<class _CharT, class _SizeT, class _Traits, _SizeT __npos>
inline _SizeT __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__str_find_first_not_of(const _CharT *__p, _SizeT __sz,
                    const _CharT* __s, _SizeT __pos, _SizeT __n) throw()
{
    if (__pos < __sz)
    {
        const _CharT* __pe = __p + __sz;
        for (const _CharT* __ps = __p + __pos; __ps != __pe; ++__ps)
            if (_Traits::find(__s, __n, *__ps) == 0)
                return static_cast<_SizeT>(__ps - __p);
    }
    return __npos;
}


template<class _CharT, class _SizeT, class _Traits, _SizeT __npos>
inline _SizeT __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__str_find_first_not_of(const _CharT *__p, _SizeT __sz,
                          _CharT __c, _SizeT __pos) throw()
{
    if (__pos < __sz)
    {
        const _CharT* __pe = __p + __sz;
        for (const _CharT* __ps = __p + __pos; __ps != __pe; ++__ps)
            if (!_Traits::eq(*__ps, __c))
                return static_cast<_SizeT>(__ps - __p);
    }
    return __npos;
}



template<class _CharT, class _SizeT, class _Traits, _SizeT __npos>
inline _SizeT __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__str_find_last_not_of(const _CharT *__p, _SizeT __sz,
                   const _CharT* __s, _SizeT __pos, _SizeT __n) throw()
{
    if (__pos < __sz)
        ++__pos;
    else
        __pos = __sz;
    for (const _CharT* __ps = __p + __pos; __ps != __p;)
        if (_Traits::find(__s, __n, *--__ps) == 0)
            return static_cast<_SizeT>(__ps - __p);
    return __npos;
}


template<class _CharT, class _SizeT, class _Traits, _SizeT __npos>
inline _SizeT __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
__str_find_last_not_of(const _CharT *__p, _SizeT __sz,
                         _CharT __c, _SizeT __pos) throw()
{
    if (__pos < __sz)
        ++__pos;
    else
        __pos = __sz;
    for (const _CharT* __ps = __p + __pos; __ps != __p;)
        if (!_Traits::eq(*--__ps, __c))
            return static_cast<_SizeT>(__ps - __p);
    return __npos;
}

template<class _Ptr>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
size_t __do_string_hash(_Ptr __p, _Ptr __e)
{
    typedef typename iterator_traits<_Ptr>::value_type value_type;
    return __murmur2_or_cityhash<size_t>()(__p, (__e-__p)*sizeof(value_type));
}

template <class _CharT, class _Iter, class _Traits=char_traits<_CharT> >
struct __quoted_output_proxy
{
    _Iter __first;
    _Iter __last;
    _CharT __delim;
    _CharT __escape;

    __quoted_output_proxy(_Iter __f, _Iter __l, _CharT __d, _CharT __e)
    : __first(__f), __last(__l), __delim(__d), __escape(__e) {}

};

} }









namespace std { inline namespace __1 {

template<class _CharT, class _Traits = char_traits<_CharT> >
class __attribute__ ((__type_visibility__("default"))) basic_string_view {
public:

    typedef _Traits traits_type;
    typedef _CharT value_type;
    typedef _CharT* pointer;
    typedef const _CharT* const_pointer;
    typedef _CharT& reference;
    typedef const _CharT& const_reference;
    typedef const_pointer const_iterator;
    typedef const_iterator iterator;
    typedef std::__1::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef const_reverse_iterator reverse_iterator;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    static const size_type npos = -1;

    _Static_assert((!is_array<value_type>::value), "Character type of basic_string_view must not be an array");
    _Static_assert(( is_standard_layout<value_type>::value), "Character type of basic_string_view must be standard-layout");
    _Static_assert(( is_trivial<value_type>::value), "Character type of basic_string_view must be trivial");
    _Static_assert((is_same<_CharT, typename traits_type::char_type>::value), "traits_type::char_type must be the same type as CharT");



                      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string_view() throw() : __data (std::__1::__get_nullptr_t()), __size(0) {}

                      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string_view(const basic_string_view&) throw() = default;

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string_view& operator=(const basic_string_view&) throw() = default;

                      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string_view(const _CharT* __s, size_type __len) throw()
        : __data(__s), __size(__len)
    {



    }

                      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string_view(const _CharT* __s)
        : __data(__s), __size(std::__char_traits_length_checked<_Traits>(__s)) {}


                      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_iterator begin() const throw() { return cbegin(); }

                      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_iterator end() const throw() { return cend(); }

                      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_iterator cbegin() const throw() { return __data; }

                      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_iterator cend() const throw() { return __data + __size; }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_reverse_iterator rbegin() const throw() { return const_reverse_iterator(cend()); }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_reverse_iterator rend() const throw() { return const_reverse_iterator(cbegin()); }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_reverse_iterator crbegin() const throw() { return const_reverse_iterator(cend()); }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_reverse_iterator crend() const throw() { return const_reverse_iterator(cbegin()); }


                      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type size() const throw() { return __size; }

                      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type length() const throw() { return __size; }

                      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type max_size() const throw() { return numeric_limits<size_type>::max(); }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool empty() const throw() { return __size == 0; }


                      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_reference operator[](size_type __pos) const throw() { return __data[__pos]; }

                      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_reference at(size_type __pos) const
    {
        return __pos >= size()
            ? (__throw_out_of_range("string_view::at"), __data[0])
            : __data[__pos];
    }

                      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_reference front() const throw()
    {
        return ((void)0), __data[0];
    }

                      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_reference back() const throw()
    {
        return ((void)0), __data[__size-1];
    }

                      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_pointer data() const throw() { return __data; }


                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void remove_prefix(size_type __n) throw()
    {
        ((void)0);
        __data += __n;
        __size -= __n;
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void remove_suffix(size_type __n) throw()
    {
        ((void)0);
        __size -= __n;
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void swap(basic_string_view& __other) throw()
    {
        const value_type *__p = __data;
        __data = __other.__data;
        __other.__data = __p;

        size_type __sz = __size;
        __size = __other.__size;
        __other.__size = __sz;
    }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type copy(_CharT* __s, size_type __n, size_type __pos = 0) const
    {
        if (__pos > size())
            __throw_out_of_range("string_view::copy");
        size_type __rlen = std::__1::min(__n, size() - __pos);
        _Traits::copy(__s, data() + __pos, __rlen);
        return __rlen;
    }

                      __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string_view substr(size_type __pos = 0, size_type __n = npos) const
    {
        return __pos > size()
            ? (__throw_out_of_range("string_view::substr"), basic_string_view())
            : basic_string_view(data() + __pos, std::__1::min(__n, size() - __pos));
    }

                                  int compare(basic_string_view __sv) const throw()
    {
        size_type __rlen = std::__1::min( size(), __sv.size());
        int __retval = _Traits::compare(data(), __sv.data(), __rlen);
        if ( __retval == 0 )
            __retval = size() == __sv.size() ? 0 : ( size() < __sv.size() ? -1 : 1 );
        return __retval;
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    int compare(size_type __pos1, size_type __n1, basic_string_view __sv) const
    {
        return substr(__pos1, __n1).compare(__sv);
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    int compare( size_type __pos1, size_type __n1,
                basic_string_view __sv, size_type __pos2, size_type __n2) const
    {
        return substr(__pos1, __n1).compare(__sv.substr(__pos2, __n2));
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    int compare(const _CharT* __s) const throw()
    {
        return compare(basic_string_view(__s));
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    int compare(size_type __pos1, size_type __n1, const _CharT* __s) const
    {
        return substr(__pos1, __n1).compare(basic_string_view(__s));
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    int compare(size_type __pos1, size_type __n1, const _CharT* __s, size_type __n2) const
    {
        return substr(__pos1, __n1).compare(basic_string_view(__s, __n2));
    }


                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find(basic_string_view __s, size_type __pos = 0) const throw()
    {
        ((void)0);
        return __str_find<value_type, size_type, traits_type, npos>
            (data(), size(), __s.data(), __pos, __s.size());
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find(_CharT __c, size_type __pos = 0) const throw()
    {
        return __str_find<value_type, size_type, traits_type, npos>
            (data(), size(), __c, __pos);
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find(const _CharT* __s, size_type __pos, size_type __n) const
    {
        ((void)0);
        return __str_find<value_type, size_type, traits_type, npos>
            (data(), size(), __s, __pos, __n);
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find(const _CharT* __s, size_type __pos = 0) const
    {
        ((void)0);
        return __str_find<value_type, size_type, traits_type, npos>
            (data(), size(), __s, __pos, traits_type::length(__s));
    }


                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type rfind(basic_string_view __s, size_type __pos = npos) const throw()
    {
        ((void)0);
        return __str_rfind<value_type, size_type, traits_type, npos>
            (data(), size(), __s.data(), __pos, __s.size());
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type rfind(_CharT __c, size_type __pos = npos) const throw()
    {
        return __str_rfind<value_type, size_type, traits_type, npos>
            (data(), size(), __c, __pos);
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type rfind(const _CharT* __s, size_type __pos, size_type __n) const
    {
        ((void)0);
        return __str_rfind<value_type, size_type, traits_type, npos>
            (data(), size(), __s, __pos, __n);
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type rfind(const _CharT* __s, size_type __pos=npos) const
    {
        ((void)0);
        return __str_rfind<value_type, size_type, traits_type, npos>
            (data(), size(), __s, __pos, traits_type::length(__s));
    }


                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_first_of(basic_string_view __s, size_type __pos = 0) const throw()
    {
        ((void)0);
        return __str_find_first_of<value_type, size_type, traits_type, npos>
            (data(), size(), __s.data(), __pos, __s.size());
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_first_of(_CharT __c, size_type __pos = 0) const throw()
    { return find(__c, __pos); }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_first_of(const _CharT* __s, size_type __pos, size_type __n) const
    {
        ((void)0);
        return __str_find_first_of<value_type, size_type, traits_type, npos>
            (data(), size(), __s, __pos, __n);
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_first_of(const _CharT* __s, size_type __pos=0) const
    {
        ((void)0);
        return __str_find_first_of<value_type, size_type, traits_type, npos>
            (data(), size(), __s, __pos, traits_type::length(__s));
    }


                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_last_of(basic_string_view __s, size_type __pos=npos) const throw()
    {
        ((void)0);
        return __str_find_last_of<value_type, size_type, traits_type, npos>
            (data(), size(), __s.data(), __pos, __s.size());
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_last_of(_CharT __c, size_type __pos = npos) const throw()
    { return rfind(__c, __pos); }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_last_of(const _CharT* __s, size_type __pos, size_type __n) const
    {
        ((void)0);
        return __str_find_last_of<value_type, size_type, traits_type, npos>
            (data(), size(), __s, __pos, __n);
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_last_of(const _CharT* __s, size_type __pos=npos) const
    {
        ((void)0);
        return __str_find_last_of<value_type, size_type, traits_type, npos>
            (data(), size(), __s, __pos, traits_type::length(__s));
    }


                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_first_not_of(basic_string_view __s, size_type __pos=0) const throw()
    {
        ((void)0);
        return __str_find_first_not_of<value_type, size_type, traits_type, npos>
            (data(), size(), __s.data(), __pos, __s.size());
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_first_not_of(_CharT __c, size_type __pos=0) const throw()
    {
        return __str_find_first_not_of<value_type, size_type, traits_type, npos>
            (data(), size(), __c, __pos);
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_first_not_of(const _CharT* __s, size_type __pos, size_type __n) const
    {
        ((void)0);
        return __str_find_first_not_of<value_type, size_type, traits_type, npos>
            (data(), size(), __s, __pos, __n);
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_first_not_of(const _CharT* __s, size_type __pos=0) const
    {
        ((void)0);
        return __str_find_first_not_of<value_type, size_type, traits_type, npos>
            (data(), size(), __s, __pos, traits_type::length(__s));
    }


                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_last_not_of(basic_string_view __s, size_type __pos=npos) const throw()
    {
        ((void)0);
        return __str_find_last_not_of<value_type, size_type, traits_type, npos>
            (data(), size(), __s.data(), __pos, __s.size());
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_last_not_of(_CharT __c, size_type __pos=npos) const throw()
    {
        return __str_find_last_not_of<value_type, size_type, traits_type, npos>
            (data(), size(), __c, __pos);
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_last_not_of(const _CharT* __s, size_type __pos, size_type __n) const
    {
        ((void)0);
        return __str_find_last_not_of<value_type, size_type, traits_type, npos>
            (data(), size(), __s, __pos, __n);
    }

                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_last_not_of(const _CharT* __s, size_type __pos=npos) const
    {
        ((void)0);
        return __str_find_last_not_of<value_type, size_type, traits_type, npos>
            (data(), size(), __s, __pos, traits_type::length(__s));
    }

private:
    const value_type* __data;
    size_type __size;
};




template<class _CharT, class _Traits>
                              __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator==(basic_string_view<_CharT, _Traits> __lhs,
                basic_string_view<_CharT, _Traits> __rhs) throw()
{
    if ( __lhs.size() != __rhs.size()) return false;
    return __lhs.compare(__rhs) == 0;
}

template<class _CharT, class _Traits>
                              __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator==(basic_string_view<_CharT, _Traits> __lhs,
                typename common_type<basic_string_view<_CharT, _Traits> >::type __rhs) throw()
{
    if ( __lhs.size() != __rhs.size()) return false;
    return __lhs.compare(__rhs) == 0;
}

template<class _CharT, class _Traits>
                              __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator==(typename common_type<basic_string_view<_CharT, _Traits> >::type __lhs,
                basic_string_view<_CharT, _Traits> __rhs) throw()
{
    if ( __lhs.size() != __rhs.size()) return false;
    return __lhs.compare(__rhs) == 0;
}



template<class _CharT, class _Traits>
                              __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator!=(basic_string_view<_CharT, _Traits> __lhs, basic_string_view<_CharT, _Traits> __rhs) throw()
{
    if ( __lhs.size() != __rhs.size())
        return true;
    return __lhs.compare(__rhs) != 0;
}

template<class _CharT, class _Traits>
                              __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator!=(basic_string_view<_CharT, _Traits> __lhs,
                typename common_type<basic_string_view<_CharT, _Traits> >::type __rhs) throw()
{
    if ( __lhs.size() != __rhs.size())
        return true;
    return __lhs.compare(__rhs) != 0;
}

template<class _CharT, class _Traits>
                              __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator!=(typename common_type<basic_string_view<_CharT, _Traits> >::type __lhs,
                basic_string_view<_CharT, _Traits> __rhs) throw()
{
    if ( __lhs.size() != __rhs.size())
        return true;
    return __lhs.compare(__rhs) != 0;
}



template<class _CharT, class _Traits>
                              __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator<(basic_string_view<_CharT, _Traits> __lhs, basic_string_view<_CharT, _Traits> __rhs) throw()
{
    return __lhs.compare(__rhs) < 0;
}

template<class _CharT, class _Traits>
                              __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator<(basic_string_view<_CharT, _Traits> __lhs,
                typename common_type<basic_string_view<_CharT, _Traits> >::type __rhs) throw()
{
    return __lhs.compare(__rhs) < 0;
}

template<class _CharT, class _Traits>
                              __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator<(typename common_type<basic_string_view<_CharT, _Traits> >::type __lhs,
                basic_string_view<_CharT, _Traits> __rhs) throw()
{
    return __lhs.compare(__rhs) < 0;
}



template<class _CharT, class _Traits>
                              __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator> (basic_string_view<_CharT, _Traits> __lhs, basic_string_view<_CharT, _Traits> __rhs) throw()
{
    return __lhs.compare(__rhs) > 0;
}

template<class _CharT, class _Traits>
                              __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator>(basic_string_view<_CharT, _Traits> __lhs,
                typename common_type<basic_string_view<_CharT, _Traits> >::type __rhs) throw()
{
    return __lhs.compare(__rhs) > 0;
}

template<class _CharT, class _Traits>
                              __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator>(typename common_type<basic_string_view<_CharT, _Traits> >::type __lhs,
                basic_string_view<_CharT, _Traits> __rhs) throw()
{
    return __lhs.compare(__rhs) > 0;
}



template<class _CharT, class _Traits>
                              __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator<=(basic_string_view<_CharT, _Traits> __lhs, basic_string_view<_CharT, _Traits> __rhs) throw()
{
    return __lhs.compare(__rhs) <= 0;
}

template<class _CharT, class _Traits>
                              __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator<=(basic_string_view<_CharT, _Traits> __lhs,
                typename common_type<basic_string_view<_CharT, _Traits> >::type __rhs) throw()
{
    return __lhs.compare(__rhs) <= 0;
}

template<class _CharT, class _Traits>
                              __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator<=(typename common_type<basic_string_view<_CharT, _Traits> >::type __lhs,
                basic_string_view<_CharT, _Traits> __rhs) throw()
{
    return __lhs.compare(__rhs) <= 0;
}



template<class _CharT, class _Traits>
                              __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator>=(basic_string_view<_CharT, _Traits> __lhs, basic_string_view<_CharT, _Traits> __rhs) throw()
{
    return __lhs.compare(__rhs) >= 0;
}


template<class _CharT, class _Traits>
                              __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator>=(basic_string_view<_CharT, _Traits> __lhs,
                typename common_type<basic_string_view<_CharT, _Traits> >::type __rhs) throw()
{
    return __lhs.compare(__rhs) >= 0;
}

template<class _CharT, class _Traits>
                              __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator>=(typename common_type<basic_string_view<_CharT, _Traits> >::type __lhs,
                basic_string_view<_CharT, _Traits> __rhs) throw()
{
    return __lhs.compare(__rhs) >= 0;
}


template<class _CharT, class _Traits>
basic_ostream<_CharT, _Traits>&
operator<<(basic_ostream<_CharT, _Traits>& __os,
           basic_string_view<_CharT, _Traits> __str);

typedef basic_string_view<char> string_view;



typedef basic_string_view<char16_t> u16string_view;
typedef basic_string_view<char32_t> u32string_view;
typedef basic_string_view<wchar_t> wstring_view;


template<class _CharT>
struct __attribute__ ((__type_visibility__("default"))) hash<basic_string_view<_CharT, char_traits<_CharT> > >
    : public unary_function<basic_string_view<_CharT, char_traits<_CharT> >, size_t>
{
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_t operator()(const basic_string_view<_CharT, char_traits<_CharT> > __val) const throw() {
        return __do_string_hash(__val.data(), __val.data() + __val.size());
    }
};

} }



















namespace std { inline namespace __1 {

using ::isalnum;
using ::isalpha;
using ::isblank;
using ::iscntrl;
using ::isdigit;
using ::isgraph;
using ::islower;
using ::isprint;
using ::ispunct;
using ::isspace;
using ::isupper;
using ::isxdigit;
using ::tolower;
using ::toupper;

} }












typedef __darwin_wctrans_t wctrans_t;


inline int
iswblank(wint_t _wc)
{
 return (__istype(_wc, 0x00020000L));
}


inline int
iswascii(wint_t _wc)
{
 return ((_wc & ~0x7F) == 0);
}

inline int
iswhexnumber(wint_t _wc)
{
 return (__istype(_wc, 0x00010000L));
}

inline int
iswideogram(wint_t _wc)
{
 return (__istype(_wc, 0x00080000L));
}

inline int
iswnumber(wint_t _wc)
{
 return (__istype(_wc, 0x00000400L));
}

inline int
iswphonogram(wint_t _wc)
{
 return (__istype(_wc, 0x00200000L));
}

inline int
iswrune(wint_t _wc)
{
 return (__istype(_wc, 0xFFFFFFF0L));
}

inline int
iswspecial(wint_t _wc)
{
 return (__istype(_wc, 0x00100000L));
}

extern "C" {

wint_t nextwctype(wint_t, wctype_t);

wint_t towctrans(wint_t, wctrans_t);
wctrans_t
 wctrans(const char *);
}





namespace std { inline namespace __1 {

using ::wint_t;
using ::wctrans_t;
using ::wctype_t;
using ::iswalnum;
using ::iswalpha;
using ::iswblank;
using ::iswcntrl;
using ::iswdigit;
using ::iswgraph;
using ::iswlower;
using ::iswprint;
using ::iswpunct;
using ::iswspace;
using ::iswupper;
using ::iswxdigit;
using ::iswctype;
using ::wctype;
using ::towlower;
using ::towupper;
using ::towctrans;
using ::wctrans;

} }






namespace std { inline namespace __1 {



using ::mbstate_t;
using ::size_t;
using ::tm;
using ::wint_t;
using ::FILE;
using ::fwprintf;
using ::fwscanf;
using ::swprintf;
using ::vfwprintf;
using ::vswprintf;
using ::swscanf;
using ::vfwscanf;
using ::vswscanf;
using ::fgetwc;
using ::fgetws;
using ::fputwc;
using ::fputws;
using ::fwide;
using ::getwc;
using ::putwc;
using ::ungetwc;
using ::wcstod;
using ::wcstof;
using ::wcstold;
using ::wcstol;

using ::wcstoll;

using ::wcstoul;

using ::wcstoull;

using ::wcscpy;
using ::wcsncpy;
using ::wcscat;
using ::wcsncat;
using ::wcscmp;
using ::wcscoll;
using ::wcsncmp;
using ::wcsxfrm;
using ::wcschr;
using ::wcspbrk;
using ::wcsrchr;
using ::wcsstr;
using ::wmemchr;
using ::wcscspn;
using ::wcslen;
using ::wcsspn;
using ::wcstok;
using ::wmemcmp;
using ::wmemcpy;
using ::wmemmove;
using ::wmemset;
using ::wcsftime;
using ::btowc;
using ::wctob;
using ::mbsinit;
using ::mbrlen;
using ::mbrtowc;
using ::wcrtomb;
using ::mbsrtowcs;
using ::wcsrtombs;


using ::getwchar;
using ::vwscanf;
using ::wscanf;



using ::putwchar;
using ::vwprintf;
using ::wprintf;

} }









namespace std { inline namespace __1 {



template <class _StateT>
class __attribute__ ((__type_visibility__("default"))) fpos
{
private:
    _StateT __st_;
    streamoff __off_;
public:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) fpos(streamoff __off = streamoff()) : __st_(), __off_(__off) {}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) operator streamoff() const {return __off_;}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) _StateT state() const {return __st_;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void state(_StateT __st) {__st_ = __st;}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) fpos& operator+=(streamoff __off) {__off_ += __off; return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) fpos operator+ (streamoff __off) const {fpos __t(*this); __t += __off; return __t;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) fpos& operator-=(streamoff __off) {__off_ -= __off; return *this;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) fpos operator- (streamoff __off) const {fpos __t(*this); __t -= __off; return __t;}
};

template <class _StateT>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
streamoff operator-(const fpos<_StateT>& __x, const fpos<_StateT>& __y)
    {return streamoff(__x) - streamoff(__y);}

template <class _StateT>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator==(const fpos<_StateT>& __x, const fpos<_StateT>& __y)
    {return streamoff(__x) == streamoff(__y);}

template <class _StateT>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool operator!=(const fpos<_StateT>& __x, const fpos<_StateT>& __y)
    {return streamoff(__x) != streamoff(__y);}



template<class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>
operator+(const basic_string<_CharT, _Traits, _Allocator>& __x,
          const basic_string<_CharT, _Traits, _Allocator>& __y);

template<class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>
operator+(const _CharT* __x, const basic_string<_CharT,_Traits,_Allocator>& __y);

template<class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>
operator+(_CharT __x, const basic_string<_CharT,_Traits,_Allocator>& __y);

template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
basic_string<_CharT, _Traits, _Allocator>
operator+(const basic_string<_CharT, _Traits, _Allocator>& __x, const _CharT* __y);

template<class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>
operator+(const basic_string<_CharT, _Traits, _Allocator>& __x, _CharT __y);

extern template __attribute__ ((__visibility__("default"))) string operator+<char, char_traits<char>, allocator<char> >(char const*, string const&);

template <bool>
class __attribute__ ((__type_visibility__("default"))) __basic_string_common
{
protected:
    __attribute__ ((noreturn)) void __throw_length_error() const;
    __attribute__ ((noreturn)) void __throw_out_of_range() const;
};

template <bool __b>
void
__basic_string_common<__b>::__throw_length_error() const
{
    std::__1::__throw_length_error("basic_string");
}

template <bool __b>
void
__basic_string_common<__b>::__throw_out_of_range() const
{
    std::__1::__throw_out_of_range("basic_string");
}

extern template class __attribute__ ((__visibility__("default"))) __basic_string_common<true>;





template <class _Iter>
struct __libcpp_string_gets_noexcept_iterator_impl : public false_type {};

template <class _Iter>
struct __libcpp_string_gets_noexcept_iterator
    : public integral_constant<bool,(__libcpp_is_trivial_iterator<_Iter>::value || __libcpp_string_gets_noexcept_iterator_impl<_Iter>::value)> {};

template <class _CharT, class _Traits, class _Tp>
struct __can_be_converted_to_string_view : public integral_constant<bool,(( is_convertible<const _Tp&, basic_string_view<_CharT, _Traits> >::value && !is_convertible<const _Tp&, const _CharT*>::value))> {};

template<class _CharT, class _Traits, class _Allocator>
class __attribute__ ((__type_visibility__("default"))) basic_string
    : private __basic_string_common<true>
{
public:
    typedef basic_string __self;
    typedef basic_string_view<_CharT, _Traits> __self_view;
    typedef _Traits traits_type;
    typedef _CharT value_type;
    typedef _Allocator allocator_type;
    typedef allocator_traits<allocator_type> __alloc_traits;
    typedef typename __alloc_traits::size_type size_type;
    typedef typename __alloc_traits::difference_type difference_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef typename __alloc_traits::pointer pointer;
    typedef typename __alloc_traits::const_pointer const_pointer;

    _Static_assert((!is_array<value_type>::value), "Character type of basic_string must not be an array");
    _Static_assert(( is_standard_layout<value_type>::value), "Character type of basic_string must be standard-layout");
    _Static_assert(( is_trivial<value_type>::value), "Character type of basic_string must be trivial");
    _Static_assert(( is_same<_CharT, typename traits_type::char_type>::value), "traits_type::char_type must be the same type as CharT");

    _Static_assert(( is_same<typename allocator_type::value_type, value_type>::value), "Allocator::value_type must be same type as value_type");






    typedef __wrap_iter<pointer> iterator;
    typedef __wrap_iter<const_pointer> const_iterator;

    typedef std::__1::reverse_iterator<iterator> reverse_iterator;
    typedef std::__1::reverse_iterator<const_iterator> const_reverse_iterator;

private:

    struct __long
    {
        size_type __cap_;
        size_type __size_;
        pointer __data_;
    };





    static const size_type __short_mask = 0x01;
    static const size_type __long_mask = 0x1ul;


    enum {__min_cap = (sizeof(__long) - 1)/sizeof(value_type) > 2 ?
                      (sizeof(__long) - 1)/sizeof(value_type) : 2};

    struct __short
    {
        union
        {
            unsigned char __size_;
            value_type __lx;
        };
        value_type __data_[__min_cap];
    };



    union __ulx{__long __lx; __short __lxx;};

    enum {__n_words = sizeof(__ulx) / sizeof(size_type)};

    struct __raw
    {
        size_type __words[__n_words];
    };

    struct __rep
    {
        union
        {
            __long __l;
            __short __s;
            __raw __r;
        };
    };

    __compressed_pair<__rep, allocator_type> __r_;

public:
    static const size_type npos = -1;

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) basic_string()
                                                                           ;

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) explicit basic_string(const allocator_type& __a)

                                                                        ;




    basic_string(const basic_string& __str);
    basic_string(const basic_string& __str, const allocator_type& __a);

    template <class = typename enable_if<__is_allocator<_Allocator>::value, nullptr_t>::type>
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string(const _CharT* __s) : __r_(__default_init_tag(), __default_init_tag()) {
      ((void)0);
      __init(__s, traits_type::length(__s));



    }

    template <class = typename enable_if<__is_allocator<_Allocator>::value, nullptr_t>::type>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        basic_string(const _CharT* __s, const _Allocator& __a);

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string(const _CharT* __s, size_type __n);
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string(const _CharT* __s, size_type __n, const _Allocator& __a);
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string(size_type __n, _CharT __c);

    template <class = typename enable_if<__is_allocator<_Allocator>::value, nullptr_t>::type>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        basic_string(size_type __n, _CharT __c, const _Allocator& __a);

    basic_string(const basic_string& __str, size_type __pos, size_type __n,
                 const _Allocator& __a = _Allocator());
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string(const basic_string& __str, size_type __pos,
                 const _Allocator& __a = _Allocator());

    template<class _Tp, class = typename enable_if<__can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value, void>::type>
        inline __attribute__ ((__visibility__("hidden")))
        basic_string(const _Tp& __t, size_type __pos, size_type __n,
                              const allocator_type& __a = allocator_type());

    template<class _Tp, class = typename enable_if<__can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value, void>::type>
        inline __attribute__ ((__visibility__("hidden")))
        explicit basic_string(const _Tp& __t);

    template<class _Tp, class = typename enable_if<__can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value, void>::type>
        inline __attribute__ ((__visibility__("hidden")))
        explicit basic_string(const _Tp& __t, const allocator_type& __a);

    template<class _InputIterator, class = typename enable_if<__is_cpp17_input_iterator<_InputIterator>::value>::type>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        basic_string(_InputIterator __first, _InputIterator __last);
    template<class _InputIterator, class = typename enable_if<__is_cpp17_input_iterator<_InputIterator>::value>::type>
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        basic_string(_InputIterator __first, _InputIterator __last, const allocator_type& __a);







    inline ~basic_string();

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    operator __self_view() const throw() { return __self_view(data(), size()); }

    basic_string& operator=(const basic_string& __str);

    template <class _Tp, class = typename enable_if<__can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value, void>::type>
    basic_string& operator=(const _Tp& __t)
        {__self_view __sv = __t; return assign(__sv);}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) basic_string& operator=(const value_type* __s) {return assign(__s);}
    basic_string& operator=(value_type __c);

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    iterator begin() throw()
        {return iterator(__get_pointer());}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_iterator begin() const throw()
        {return const_iterator(__get_pointer());}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    iterator end() throw()
        {return iterator(__get_pointer() + size());}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_iterator end() const throw()
        {return const_iterator(__get_pointer() + size());}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    reverse_iterator rbegin() throw()
        {return reverse_iterator(end());}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_reverse_iterator rbegin() const throw()
        {return const_reverse_iterator(end());}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    reverse_iterator rend() throw()
        {return reverse_iterator(begin());}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_reverse_iterator rend() const throw()
        {return const_reverse_iterator(begin());}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_iterator cbegin() const throw()
        {return begin();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_iterator cend() const throw()
        {return end();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_reverse_iterator crbegin() const throw()
        {return rbegin();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_reverse_iterator crend() const throw()
        {return rend();}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) size_type size() const throw()
        {return __is_long() ? __get_long_size() : __get_short_size();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) size_type length() const throw() {return size();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) size_type max_size() const throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) size_type capacity() const throw()
        {return (__is_long() ? __get_long_cap()
                             : static_cast<size_type>(__min_cap)) - 1;}

    void resize(size_type __n, value_type __c);
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void resize(size_type __n) {resize(__n, value_type());}

    void reserve(size_type __res_arg);
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void __resize_default_init(size_type __n);

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void reserve() throw() {reserve(0);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void shrink_to_fit() throw() {reserve();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void clear() throw();
                                  __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool empty() const throw() {return size() == 0;}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) const_reference operator[](size_type __pos) const throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) reference operator[](size_type __pos) throw();

    const_reference at(size_type __n) const;
    reference at(size_type __n);

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) basic_string& operator+=(const basic_string& __str) {return append(__str);}

    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            basic_string&
        >::type
                                            operator+=(const _Tp& __t) {__self_view __sv = __t; return append(__sv);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) basic_string& operator+=(const value_type* __s) {return append(__s);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) basic_string& operator+=(value_type __c) {push_back(__c); return *this;}




    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string& append(const basic_string& __str);

    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            basic_string&
        >::type
                  append(const _Tp& __t) { __self_view __sv = __t; return append(__sv.data(), __sv.size()); }
    basic_string& append(const basic_string& __str, size_type __pos, size_type __n=npos);

    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            basic_string&
        >::type
                  append(const _Tp& __t, size_type __pos, size_type __n=npos);
    basic_string& append(const value_type* __s, size_type __n);
    basic_string& append(const value_type* __s);
    basic_string& append(size_type __n, value_type __c);

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void __append_default_init(size_type __n);

    template <class _ForwardIterator>
    inline __attribute__ ((__visibility__("hidden")))
    basic_string& __append_forward_unsafe(_ForwardIterator, _ForwardIterator);
    template<class _InputIterator>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __is_exactly_cpp17_input_iterator<_InputIterator>::value
                || !__libcpp_string_gets_noexcept_iterator<_InputIterator>::value,
            basic_string&
        >::type
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    append(_InputIterator __first, _InputIterator __last) {
      const basic_string __temp (__first, __last, __alloc());
      append(__temp.data(), __temp.size());
      return *this;
    }
    template<class _ForwardIterator>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __is_cpp17_forward_iterator<_ForwardIterator>::value
                && __libcpp_string_gets_noexcept_iterator<_ForwardIterator>::value,
            basic_string&
        >::type
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    append(_ForwardIterator __first, _ForwardIterator __last) {
      return __append_forward_unsafe(__first, __last);
    }






    void push_back(value_type __c);
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void pop_back();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) reference front() throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) const_reference front() const throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) reference back() throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) const_reference back() const throw();

    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            basic_string&
        >::type
                 assign(const _Tp & __t) { __self_view __sv = __t; return assign(__sv.data(), __sv.size()); }
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string& assign(const basic_string& __str) { return *this = __str; }






    basic_string& assign(const basic_string& __str, size_type __pos, size_type __n=npos);
    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            basic_string&
        >::type
                  assign(const _Tp & __t, size_type __pos, size_type __n=npos);
    basic_string& assign(const value_type* __s, size_type __n);
    basic_string& assign(const value_type* __s);
    basic_string& assign(size_type __n, value_type __c);
    template<class _InputIterator>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
           __is_exactly_cpp17_input_iterator<_InputIterator>::value
                || !__libcpp_string_gets_noexcept_iterator<_InputIterator>::value,
            basic_string&
        >::type
        assign(_InputIterator __first, _InputIterator __last);
    template<class _ForwardIterator>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __is_cpp17_forward_iterator<_ForwardIterator>::value
                 && __libcpp_string_gets_noexcept_iterator<_ForwardIterator>::value,
            basic_string&
        >::type
        assign(_ForwardIterator __first, _ForwardIterator __last);





    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string& insert(size_type __pos1, const basic_string& __str);

    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            basic_string&
        >::type
                 insert(size_type __pos1, const _Tp& __t)
    { __self_view __sv = __t; return insert(__pos1, __sv.data(), __sv.size()); }

    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            basic_string&
        >::type
                  insert(size_type __pos1, const _Tp& __t, size_type __pos2, size_type __n=npos);
    basic_string& insert(size_type __pos1, const basic_string& __str, size_type __pos2, size_type __n=npos);
    basic_string& insert(size_type __pos, const value_type* __s, size_type __n);
    basic_string& insert(size_type __pos, const value_type* __s);
    basic_string& insert(size_type __pos, size_type __n, value_type __c);
    iterator insert(const_iterator __pos, value_type __c);
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    iterator insert(const_iterator __pos, size_type __n, value_type __c);
    template<class _InputIterator>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
           __is_exactly_cpp17_input_iterator<_InputIterator>::value
                || !__libcpp_string_gets_noexcept_iterator<_InputIterator>::value,
            iterator
        >::type
        insert(const_iterator __pos, _InputIterator __first, _InputIterator __last);
    template<class _ForwardIterator>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __is_cpp17_forward_iterator<_ForwardIterator>::value
                 && __libcpp_string_gets_noexcept_iterator<_ForwardIterator>::value,
            iterator
        >::type
        insert(const_iterator __pos, _ForwardIterator __first, _ForwardIterator __last);






    basic_string& erase(size_type __pos = 0, size_type __n = npos);
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    iterator erase(const_iterator __pos);
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    iterator erase(const_iterator __first, const_iterator __last);

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string& replace(size_type __pos1, size_type __n1, const basic_string& __str);

    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            basic_string&
        >::type
                  replace(size_type __pos1, size_type __n1, const _Tp& __t) { __self_view __sv = __t; return replace(__pos1, __n1, __sv.data(), __sv.size()); }
    basic_string& replace(size_type __pos1, size_type __n1, const basic_string& __str, size_type __pos2, size_type __n2=npos);
    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            basic_string&
        >::type
                  replace(size_type __pos1, size_type __n1, const _Tp& __t, size_type __pos2, size_type __n2=npos);
    basic_string& replace(size_type __pos, size_type __n1, const value_type* __s, size_type __n2);
    basic_string& replace(size_type __pos, size_type __n1, const value_type* __s);
    basic_string& replace(size_type __pos, size_type __n1, size_type __n2, value_type __c);
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string& replace(const_iterator __i1, const_iterator __i2, const basic_string& __str);

    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            basic_string&
        >::type
                  replace(const_iterator __i1, const_iterator __i2, const _Tp& __t) { __self_view __sv = __t; return replace(__i1 - begin(), __i2 - __i1, __sv); }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string& replace(const_iterator __i1, const_iterator __i2, const value_type* __s, size_type __n);
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string& replace(const_iterator __i1, const_iterator __i2, const value_type* __s);
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string& replace(const_iterator __i1, const_iterator __i2, size_type __n, value_type __c);
    template<class _InputIterator>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __is_cpp17_input_iterator<_InputIterator>::value,
            basic_string&
        >::type
        replace(const_iterator __i1, const_iterator __i2, _InputIterator __j1, _InputIterator __j2);






    size_type copy(value_type* __s, size_type __n, size_type __pos = 0) const;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    basic_string substr(size_type __pos = 0, size_type __n = npos) const;

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void swap(basic_string& __str)




                                                                  ;


    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const value_type* c_str() const throw() {return data();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const value_type* data() const throw() {return std::__1::__to_address(__get_pointer());}





    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    allocator_type get_allocator() const throw() {return __alloc();}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find(const basic_string& __str, size_type __pos = 0) const throw();

    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            size_type
        >::type
              find(const _Tp& __t, size_type __pos = 0) const;
    size_type find(const value_type* __s, size_type __pos, size_type __n) const throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find(const value_type* __s, size_type __pos = 0) const throw();
    size_type find(value_type __c, size_type __pos = 0) const throw();

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type rfind(const basic_string& __str, size_type __pos = npos) const throw();

    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            size_type
        >::type
              rfind(const _Tp& __t, size_type __pos = npos) const;
    size_type rfind(const value_type* __s, size_type __pos, size_type __n) const throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type rfind(const value_type* __s, size_type __pos = npos) const throw();
    size_type rfind(value_type __c, size_type __pos = npos) const throw();

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_first_of(const basic_string& __str, size_type __pos = 0) const throw();

    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            size_type
        >::type
              find_first_of(const _Tp& __t, size_type __pos = 0) const;
    size_type find_first_of(const value_type* __s, size_type __pos, size_type __n) const throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_first_of(const value_type* __s, size_type __pos = 0) const throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_first_of(value_type __c, size_type __pos = 0) const throw();

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_last_of(const basic_string& __str, size_type __pos = npos) const throw();

    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            size_type
        >::type
              find_last_of(const _Tp& __t, size_type __pos = npos) const;
    size_type find_last_of(const value_type* __s, size_type __pos, size_type __n) const throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_last_of(const value_type* __s, size_type __pos = npos) const throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_last_of(value_type __c, size_type __pos = npos) const throw();

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_first_not_of(const basic_string& __str, size_type __pos = 0) const throw();

    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            size_type
        >::type
              find_first_not_of(const _Tp &__t, size_type __pos = 0) const;
    size_type find_first_not_of(const value_type* __s, size_type __pos, size_type __n) const throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_first_not_of(const value_type* __s, size_type __pos = 0) const throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_first_not_of(value_type __c, size_type __pos = 0) const throw();

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_last_not_of(const basic_string& __str, size_type __pos = npos) const throw();

    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            size_type
        >::type
              find_last_not_of(const _Tp& __t, size_type __pos = npos) const;
    size_type find_last_not_of(const value_type* __s, size_type __pos, size_type __n) const throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_last_not_of(const value_type* __s, size_type __pos = npos) const throw();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type find_last_not_of(value_type __c, size_type __pos = npos) const throw();

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    int compare(const basic_string& __str) const throw();

    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            int
        >::type
        compare(const _Tp &__t) const;

    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden")))
    typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            int
        >::type
         compare(size_type __pos1, size_type __n1, const _Tp& __t) const;

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    int compare(size_type __pos1, size_type __n1, const basic_string& __str) const;
    int compare(size_type __pos1, size_type __n1, const basic_string& __str, size_type __pos2, size_type __n2=npos) const;

    template <class _Tp>
    inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        typename enable_if
        <
            __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
            int
        >::type
        compare(size_type __pos1, size_type __n1, const _Tp& __t, size_type __pos2, size_type __n2=npos) const;
    int compare(const value_type* __s) const throw();
    int compare(size_type __pos1, size_type __n1, const value_type* __s) const;
    int compare(size_type __pos1, size_type __n1, const value_type* __s, size_type __n2) const;

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) bool __invariants() const;

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void __clear_and_shrink() throw();

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool __is_long() const throw()
        {return bool(__r_.first().__s.__size_ & __short_mask);}

private:
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    allocator_type& __alloc() throw()
        {return __r_.second();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const allocator_type& __alloc() const throw()
        {return __r_.second();}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void __set_short_size(size_type __s) throw()



        {__r_.first().__s.__size_ = (unsigned char)(__s << 1);}


    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type __get_short_size() const throw()



        {return __r_.first().__s.__size_ >> 1;}




    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void __set_long_size(size_type __s) throw()
        {__r_.first().__l.__size_ = __s;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type __get_long_size() const throw()
        {return __r_.first().__l.__size_;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void __set_size(size_type __s) throw()
        {if (__is_long()) __set_long_size(__s); else __set_short_size(__s);}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void __set_long_cap(size_type __s) throw()
        {__r_.first().__l.__cap_ = __long_mask | __s;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type __get_long_cap() const throw()
        {return __r_.first().__l.__cap_ & size_type(~__long_mask);}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void __set_long_pointer(pointer __p) throw()
        {__r_.first().__l.__data_ = __p;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    pointer __get_long_pointer() throw()
        {return __r_.first().__l.__data_;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_pointer __get_long_pointer() const throw()
        {return __r_.first().__l.__data_;}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    pointer __get_short_pointer() throw()
        {return pointer_traits<pointer>::pointer_to(__r_.first().__s.__data_[0]);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_pointer __get_short_pointer() const throw()
        {return pointer_traits<const_pointer>::pointer_to(__r_.first().__s.__data_[0]);}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    pointer __get_pointer() throw()
        {return __is_long() ? __get_long_pointer() : __get_short_pointer();}
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    const_pointer __get_pointer() const throw()
        {return __is_long() ? __get_long_pointer() : __get_short_pointer();}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void __zero() throw()
        {
            size_type (&__a)[__n_words] = __r_.first().__r.__words;
            for (unsigned __i = 0; __i < __n_words; ++__i)
                __a[__i] = 0;
        }

    template <size_type __a> static
        __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
        size_type __align_it(size_type __s) throw()
            {return (__s + (__a-1)) & ~(__a-1);}
    enum {__alignment = 16};
    static __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    size_type __recommend(size_type __s) throw()
        {
        if (__s < __min_cap) return static_cast<size_type>(__min_cap) - 1;
        size_type __guess = __align_it<sizeof(value_type) < __alignment ?
                     __alignment/sizeof(value_type) : 1 > (__s+1) - 1;
        if (__guess == __min_cap) ++__guess;
        return __guess;
        }

    inline
    void __init(const value_type* __s, size_type __sz, size_type __reserve);
    inline
    void __init(const value_type* __s, size_type __sz);
    inline
    void __init(size_type __n, value_type __c);

    template <class _InputIterator>
    inline
    typename enable_if
    <
        __is_exactly_cpp17_input_iterator<_InputIterator>::value,
        void
    >::type
    __init(_InputIterator __first, _InputIterator __last);

    template <class _ForwardIterator>
    inline
    typename enable_if
    <
        __is_cpp17_forward_iterator<_ForwardIterator>::value,
        void
    >::type
    __init(_ForwardIterator __first, _ForwardIterator __last);

    void __grow_by(size_type __old_cap, size_type __delta_cap, size_type __old_sz,
                   size_type __n_copy, size_type __n_del, size_type __n_add = 0);
    void __grow_by_and_replace(size_type __old_cap, size_type __delta_cap, size_type __old_sz,
                               size_type __n_copy, size_type __n_del,
                               size_type __n_add, const value_type* __p_new_stuff);

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void __erase_to_end(size_type __pos);

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void __copy_assign_alloc(const basic_string& __str)
        {__copy_assign_alloc(__str, integral_constant<bool,
                      __alloc_traits::propagate_on_container_copy_assignment::value>());}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void __copy_assign_alloc(const basic_string& __str, true_type)
        {
            if (__alloc() == __str.__alloc())
                __alloc() = __str.__alloc();
            else
            {
                if (!__str.__is_long())
                {
                    __clear_and_shrink();
                    __alloc() = __str.__alloc();
                }
                else
                {
                    allocator_type __a = __str.__alloc();
                    pointer __p = __alloc_traits::allocate(__a, __str.__get_long_cap());
                    __clear_and_shrink();
                    __alloc() = std::__1::move(__a);
                    __set_long_pointer(__p);
                    __set_long_cap(__str.__get_long_cap());
                    __set_long_size(__str.size());
                }
            }
        }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void __copy_assign_alloc(const basic_string&, false_type) throw()
        {}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void
    __move_assign_alloc(basic_string& __str)



    {__move_assign_alloc(__str, integral_constant<bool,
                      __alloc_traits::propagate_on_container_move_assignment::value>());}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void __move_assign_alloc(basic_string& __c, true_type)

        {
            __alloc() = std::__1::move(__c.__alloc());
        }

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    void __move_assign_alloc(basic_string&, false_type)
        throw()
        {}

    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void __invalidate_all_iterators();
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) void __invalidate_iterators_past(size_type);

    friend basic_string operator+<>(const basic_string&, const basic_string&);
    friend basic_string operator+<>(const value_type*, const basic_string&);
    friend basic_string operator+<>(value_type, const basic_string&);
    friend basic_string operator+<>(const basic_string&, const value_type*);
    friend basic_string operator+<>(const basic_string&, value_type);
};

template <class _CharT, class _Traits, class _Allocator>
inline
void
basic_string<_CharT, _Traits, _Allocator>::__invalidate_all_iterators()
{



}

template <class _CharT, class _Traits, class _Allocator>
inline
void
basic_string<_CharT, _Traits, _Allocator>::__invalidate_iterators_past(size_type



                                                                      )
{

}

template <class _CharT, class _Traits, class _Allocator>
inline
basic_string<_CharT, _Traits, _Allocator>::basic_string()

     : __r_(__default_init_tag(), __default_init_tag())
{



    __zero();
}

template <class _CharT, class _Traits, class _Allocator>
inline
basic_string<_CharT, _Traits, _Allocator>::basic_string(const allocator_type& __a)





: __r_(__default_init_tag(), __a)
{



    __zero();
}

template <class _CharT, class _Traits, class _Allocator>
void basic_string<_CharT, _Traits, _Allocator>::__init(const value_type* __s,
                                                       size_type __sz,
                                                       size_type __reserve)
{
    if (__reserve > max_size())
        this->__throw_length_error();
    pointer __p;
    if (__reserve < __min_cap)
    {
        __set_short_size(__sz);
        __p = __get_short_pointer();
    }
    else
    {
        size_type __cap = __recommend(__reserve);
        __p = __alloc_traits::allocate(__alloc(), __cap+1);
        __set_long_pointer(__p);
        __set_long_cap(__cap+1);
        __set_long_size(__sz);
    }
    traits_type::copy(std::__1::__to_address(__p), __s, __sz);
    traits_type::assign(__p[__sz], value_type());
}

template <class _CharT, class _Traits, class _Allocator>
void
basic_string<_CharT, _Traits, _Allocator>::__init(const value_type* __s, size_type __sz)
{
    if (__sz > max_size())
        this->__throw_length_error();
    pointer __p;
    if (__sz < __min_cap)
    {
        __set_short_size(__sz);
        __p = __get_short_pointer();
    }
    else
    {
        size_type __cap = __recommend(__sz);
        __p = __alloc_traits::allocate(__alloc(), __cap+1);
        __set_long_pointer(__p);
        __set_long_cap(__cap+1);
        __set_long_size(__sz);
    }
    traits_type::copy(std::__1::__to_address(__p), __s, __sz);
    traits_type::assign(__p[__sz], value_type());
}

template <class _CharT, class _Traits, class _Allocator>
template <class>
basic_string<_CharT, _Traits, _Allocator>::basic_string(const _CharT* __s, const _Allocator& __a)
    : __r_(__default_init_tag(), __a)
{
    ((void)0);
    __init(__s, traits_type::length(__s));



}

template <class _CharT, class _Traits, class _Allocator>
inline
basic_string<_CharT, _Traits, _Allocator>::basic_string(const _CharT* __s, size_type __n)
     : __r_(__default_init_tag(), __default_init_tag())
{
    ((void)0);
    __init(__s, __n);



}

template <class _CharT, class _Traits, class _Allocator>
inline
basic_string<_CharT, _Traits, _Allocator>::basic_string(const _CharT* __s, size_type __n, const _Allocator& __a)
    : __r_(__default_init_tag(), __a)
{
    ((void)0);
    __init(__s, __n);



}

template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>::basic_string(const basic_string& __str)
    : __r_(__default_init_tag(), __alloc_traits::select_on_container_copy_construction(__str.__alloc()))
{
    if (!__str.__is_long())
        __r_.first().__r = __str.__r_.first().__r;
    else
        __init(std::__1::__to_address(__str.__get_long_pointer()), __str.__get_long_size());



}

template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>::basic_string(
    const basic_string& __str, const allocator_type& __a)
    : __r_(__default_init_tag(), __a)
{
    if (!__str.__is_long())
        __r_.first().__r = __str.__r_.first().__r;
    else
        __init(std::__1::__to_address(__str.__get_long_pointer()), __str.__get_long_size());



}

template <class _CharT, class _Traits, class _Allocator>
void
basic_string<_CharT, _Traits, _Allocator>::__init(size_type __n, value_type __c)
{
    if (__n > max_size())
        this->__throw_length_error();
    pointer __p;
    if (__n < __min_cap)
    {
        __set_short_size(__n);
        __p = __get_short_pointer();
    }
    else
    {
        size_type __cap = __recommend(__n);
        __p = __alloc_traits::allocate(__alloc(), __cap+1);
        __set_long_pointer(__p);
        __set_long_cap(__cap+1);
        __set_long_size(__n);
    }
    traits_type::assign(std::__1::__to_address(__p), __n, __c);
    traits_type::assign(__p[__n], value_type());
}

template <class _CharT, class _Traits, class _Allocator>
inline
basic_string<_CharT, _Traits, _Allocator>::basic_string(size_type __n, _CharT __c)
     : __r_(__default_init_tag(), __default_init_tag())
{
    __init(__n, __c);



}

template <class _CharT, class _Traits, class _Allocator>
template <class>
basic_string<_CharT, _Traits, _Allocator>::basic_string(size_type __n, _CharT __c, const _Allocator& __a)
    : __r_(__default_init_tag(), __a)
{
    __init(__n, __c);



}

template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>::basic_string(const basic_string& __str,
                                                        size_type __pos, size_type __n,
                                                        const _Allocator& __a)
    : __r_(__default_init_tag(), __a)
{
    size_type __str_sz = __str.size();
    if (__pos > __str_sz)
        this->__throw_out_of_range();
    __init(__str.data() + __pos, std::__1::min(__n, __str_sz - __pos));



}

template <class _CharT, class _Traits, class _Allocator>
inline
basic_string<_CharT, _Traits, _Allocator>::basic_string(const basic_string& __str, size_type __pos,
                                                        const _Allocator& __a)
    : __r_(__default_init_tag(), __a)
{
    size_type __str_sz = __str.size();
    if (__pos > __str_sz)
        this->__throw_out_of_range();
    __init(__str.data() + __pos, __str_sz - __pos);



}

template <class _CharT, class _Traits, class _Allocator>
template <class _Tp, class>
basic_string<_CharT, _Traits, _Allocator>::basic_string(
             const _Tp& __t, size_type __pos, size_type __n, const allocator_type& __a)
    : __r_(__default_init_tag(), __a)
{
    __self_view __sv0 = __t;
    __self_view __sv = __sv0.substr(__pos, __n);
    __init(__sv.data(), __sv.size());



}

template <class _CharT, class _Traits, class _Allocator>
template <class _Tp, class>
basic_string<_CharT, _Traits, _Allocator>::basic_string(const _Tp & __t)
     : __r_(__default_init_tag(), __default_init_tag())
{
    __self_view __sv = __t;
    __init(__sv.data(), __sv.size());



}

template <class _CharT, class _Traits, class _Allocator>
template <class _Tp, class>
basic_string<_CharT, _Traits, _Allocator>::basic_string(const _Tp & __t, const _Allocator& __a)
    : __r_(__default_init_tag(), __a)
{
    __self_view __sv = __t;
    __init(__sv.data(), __sv.size());



}

template <class _CharT, class _Traits, class _Allocator>
template <class _InputIterator>
typename enable_if
<
    __is_exactly_cpp17_input_iterator<_InputIterator>::value,
    void
>::type
basic_string<_CharT, _Traits, _Allocator>::__init(_InputIterator __first, _InputIterator __last)
{
    __zero();

    try
    {

    for (; __first != __last; ++__first)
        push_back(*__first);

    }
    catch (...)
    {
        if (__is_long())
            __alloc_traits::deallocate(__alloc(), __get_long_pointer(), __get_long_cap());
        throw;
    }

}

template <class _CharT, class _Traits, class _Allocator>
template <class _ForwardIterator>
typename enable_if
<
    __is_cpp17_forward_iterator<_ForwardIterator>::value,
    void
>::type
basic_string<_CharT, _Traits, _Allocator>::__init(_ForwardIterator __first, _ForwardIterator __last)
{
    size_type __sz = static_cast<size_type>(std::__1::distance(__first, __last));
    if (__sz > max_size())
        this->__throw_length_error();
    pointer __p;
    if (__sz < __min_cap)
    {
        __set_short_size(__sz);
        __p = __get_short_pointer();
    }
    else
    {
        size_type __cap = __recommend(__sz);
        __p = __alloc_traits::allocate(__alloc(), __cap+1);
        __set_long_pointer(__p);
        __set_long_cap(__cap+1);
        __set_long_size(__sz);
    }
    for (; __first != __last; ++__first, (void) ++__p)
        traits_type::assign(*__p, *__first);
    traits_type::assign(*__p, value_type());
}

template <class _CharT, class _Traits, class _Allocator>
template<class _InputIterator, class>
inline
basic_string<_CharT, _Traits, _Allocator>::basic_string(_InputIterator __first, _InputIterator __last)
     : __r_(__default_init_tag(), __default_init_tag())
{
    __init(__first, __last);



}

template <class _CharT, class _Traits, class _Allocator>
template<class _InputIterator, class>
inline
basic_string<_CharT, _Traits, _Allocator>::basic_string(_InputIterator __first, _InputIterator __last,
                                                        const allocator_type& __a)
    : __r_(__default_init_tag(), __a)
{
    __init(__first, __last);



}

template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>::~basic_string()
{



    if (__is_long())
        __alloc_traits::deallocate(__alloc(), __get_long_pointer(), __get_long_cap());
}

template <class _CharT, class _Traits, class _Allocator>
void
basic_string<_CharT, _Traits, _Allocator>::__grow_by_and_replace
    (size_type __old_cap, size_type __delta_cap, size_type __old_sz,
     size_type __n_copy, size_type __n_del, size_type __n_add, const value_type* __p_new_stuff)
{
    size_type __ms = max_size();
    if (__delta_cap > __ms - __old_cap - 1)
        this->__throw_length_error();
    pointer __old_p = __get_pointer();
    size_type __cap = __old_cap < __ms / 2 - __alignment ?
                          __recommend(std::__1::max(__old_cap + __delta_cap, 2 * __old_cap)) :
                          __ms - 1;
    pointer __p = __alloc_traits::allocate(__alloc(), __cap+1);
    __invalidate_all_iterators();
    if (__n_copy != 0)
        traits_type::copy(std::__1::__to_address(__p),
                          std::__1::__to_address(__old_p), __n_copy);
    if (__n_add != 0)
        traits_type::copy(std::__1::__to_address(__p) + __n_copy, __p_new_stuff, __n_add);
    size_type __sec_cp_sz = __old_sz - __n_del - __n_copy;
    if (__sec_cp_sz != 0)
        traits_type::copy(std::__1::__to_address(__p) + __n_copy + __n_add,
                          std::__1::__to_address(__old_p) + __n_copy + __n_del, __sec_cp_sz);
    if (__old_cap+1 != __min_cap)
        __alloc_traits::deallocate(__alloc(), __old_p, __old_cap+1);
    __set_long_pointer(__p);
    __set_long_cap(__cap+1);
    __old_sz = __n_copy + __n_add + __sec_cp_sz;
    __set_long_size(__old_sz);
    traits_type::assign(__p[__old_sz], value_type());
}

template <class _CharT, class _Traits, class _Allocator>
void
basic_string<_CharT, _Traits, _Allocator>::__grow_by(size_type __old_cap, size_type __delta_cap, size_type __old_sz,
                                                     size_type __n_copy, size_type __n_del, size_type __n_add)
{
    size_type __ms = max_size();
    if (__delta_cap > __ms - __old_cap)
        this->__throw_length_error();
    pointer __old_p = __get_pointer();
    size_type __cap = __old_cap < __ms / 2 - __alignment ?
                          __recommend(std::__1::max(__old_cap + __delta_cap, 2 * __old_cap)) :
                          __ms - 1;
    pointer __p = __alloc_traits::allocate(__alloc(), __cap+1);
    __invalidate_all_iterators();
    if (__n_copy != 0)
        traits_type::copy(std::__1::__to_address(__p),
                          std::__1::__to_address(__old_p), __n_copy);
    size_type __sec_cp_sz = __old_sz - __n_del - __n_copy;
    if (__sec_cp_sz != 0)
        traits_type::copy(std::__1::__to_address(__p) + __n_copy + __n_add,
                          std::__1::__to_address(__old_p) + __n_copy + __n_del,
                          __sec_cp_sz);
    if (__old_cap+1 != __min_cap)
        __alloc_traits::deallocate(__alloc(), __old_p, __old_cap+1);
    __set_long_pointer(__p);
    __set_long_cap(__cap+1);
}



template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::assign(const value_type* __s, size_type __n)
{
    ((void)0);
    size_type __cap = capacity();
    if (__cap >= __n)
    {
        value_type* __p = std::__1::__to_address(__get_pointer());
        traits_type::move(__p, __s, __n);
        traits_type::assign(__p[__n], value_type());
        __set_size(__n);
        __invalidate_iterators_past(__n);
    }
    else
    {
        size_type __sz = size();
        __grow_by_and_replace(__cap, __n - __cap, __sz, 0, __sz, __n, __s);
    }
    return *this;
}

template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::assign(size_type __n, value_type __c)
{
    size_type __cap = capacity();
    if (__cap < __n)
    {
        size_type __sz = size();
        __grow_by(__cap, __n - __cap, __sz, 0, __sz);
    }
    else
        __invalidate_iterators_past(__n);
    value_type* __p = std::__1::__to_address(__get_pointer());
    traits_type::assign(__p, __n, __c);
    traits_type::assign(__p[__n], value_type());
    __set_size(__n);
    return *this;
}

template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::operator=(value_type __c)
{
    pointer __p;
    if (__is_long())
    {
        __p = __get_long_pointer();
        __set_long_size(1);
    }
    else
    {
        __p = __get_short_pointer();
        __set_short_size(1);
    }
    traits_type::assign(*__p, __c);
    traits_type::assign(*++__p, value_type());
    __invalidate_iterators_past(1);
    return *this;
}

template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::operator=(const basic_string& __str)
{
    if (this != &__str)
    {
        __copy_assign_alloc(__str);
        return assign(__str.data(), __str.size());
    }
    return *this;
}

template <class _CharT, class _Traits, class _Allocator>
template<class _InputIterator>
typename enable_if
<
     __is_exactly_cpp17_input_iterator <_InputIterator>::value
          || !__libcpp_string_gets_noexcept_iterator<_InputIterator>::value,
    basic_string<_CharT, _Traits, _Allocator>&
>::type
basic_string<_CharT, _Traits, _Allocator>::assign(_InputIterator __first, _InputIterator __last)
{
    const basic_string __temp(__first, __last, __alloc());
    assign(__temp.data(), __temp.size());
    return *this;
}

template <class _CharT, class _Traits, class _Allocator>
template<class _ForwardIterator>
typename enable_if
<
    __is_cpp17_forward_iterator<_ForwardIterator>::value
         && __libcpp_string_gets_noexcept_iterator<_ForwardIterator>::value,
    basic_string<_CharT, _Traits, _Allocator>&
>::type
basic_string<_CharT, _Traits, _Allocator>::assign(_ForwardIterator __first, _ForwardIterator __last)
{
    size_type __n = static_cast<size_type>(std::__1::distance(__first, __last));
    size_type __cap = capacity();
    if (__cap < __n)
    {
        size_type __sz = size();
        __grow_by(__cap, __n - __cap, __sz, 0, __sz);
    }
    else
        __invalidate_iterators_past(__n);
    pointer __p = __get_pointer();
    for (; __first != __last; ++__first, ++__p)
        traits_type::assign(*__p, *__first);
    traits_type::assign(*__p, value_type());
    __set_size(__n);
    return *this;
}

template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::assign(const basic_string& __str, size_type __pos, size_type __n)
{
    size_type __sz = __str.size();
    if (__pos > __sz)
        this->__throw_out_of_range();
    return assign(__str.data() + __pos, std::__1::min(__n, __sz - __pos));
}

template <class _CharT, class _Traits, class _Allocator>
template <class _Tp>
typename enable_if
<
    __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
    basic_string<_CharT, _Traits, _Allocator>&
>::type
basic_string<_CharT, _Traits, _Allocator>::assign(const _Tp & __t, size_type __pos, size_type __n)
{
    __self_view __sv = __t;
    size_type __sz = __sv.size();
    if (__pos > __sz)
        this->__throw_out_of_range();
    return assign(__sv.data() + __pos, std::__1::min(__n, __sz - __pos));
}


template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::assign(const value_type* __s)
{
    ((void)0);
    return assign(__s, traits_type::length(__s));
}



template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::append(const value_type* __s, size_type __n)
{
    ((void)0);
    size_type __cap = capacity();
    size_type __sz = size();
    if (__cap - __sz >= __n)
    {
        if (__n)
        {
            value_type* __p = std::__1::__to_address(__get_pointer());
            traits_type::copy(__p + __sz, __s, __n);
            __sz += __n;
            __set_size(__sz);
            traits_type::assign(__p[__sz], value_type());
        }
    }
    else
        __grow_by_and_replace(__cap, __sz + __n - __cap, __sz, __sz, 0, __n, __s);
    return *this;
}

template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::append(size_type __n, value_type __c)
{
    if (__n)
    {
        size_type __cap = capacity();
        size_type __sz = size();
        if (__cap - __sz < __n)
            __grow_by(__cap, __sz + __n - __cap, __sz, __sz, 0);
        pointer __p = __get_pointer();
        traits_type::assign(std::__1::__to_address(__p) + __sz, __n, __c);
        __sz += __n;
        __set_size(__sz);
        traits_type::assign(__p[__sz], value_type());
    }
    return *this;
}

template <class _CharT, class _Traits, class _Allocator>
inline void
basic_string<_CharT, _Traits, _Allocator>::__append_default_init(size_type __n)
{
    if (__n)
    {
        size_type __cap = capacity();
        size_type __sz = size();
        if (__cap - __sz < __n)
            __grow_by(__cap, __sz + __n - __cap, __sz, __sz, 0);
        pointer __p = __get_pointer();
        __sz += __n;
        __set_size(__sz);
        traits_type::assign(__p[__sz], value_type());
    }
}

template <class _CharT, class _Traits, class _Allocator>
void
basic_string<_CharT, _Traits, _Allocator>::push_back(value_type __c)
{
    bool __is_short = !__is_long();
    size_type __cap;
    size_type __sz;
    if (__is_short)
    {
        __cap = __min_cap - 1;
        __sz = __get_short_size();
    }
    else
    {
        __cap = __get_long_cap() - 1;
        __sz = __get_long_size();
    }
    if (__sz == __cap)
    {
        __grow_by(__cap, 1, __sz, __sz, 0);
        __is_short = !__is_long();
    }
    pointer __p;
    if (__is_short)
    {
        __p = __get_short_pointer() + __sz;
        __set_short_size(__sz+1);
    }
    else
    {
        __p = __get_long_pointer() + __sz;
        __set_long_size(__sz+1);
    }
    traits_type::assign(*__p, __c);
    traits_type::assign(*++__p, value_type());
}

template <class _Tp>
bool __ptr_in_range (const _Tp* __p, const _Tp* __first, const _Tp* __last)
{
    return __first <= __p && __p < __last;
}

template <class _Tp1, class _Tp2>
bool __ptr_in_range (const _Tp1*, const _Tp2*, const _Tp2*)
{
    return false;
}

template <class _CharT, class _Traits, class _Allocator>
template<class _ForwardIterator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::__append_forward_unsafe(
    _ForwardIterator __first, _ForwardIterator __last)
{
    _Static_assert(__is_cpp17_forward_iterator<_ForwardIterator>::value, "function requires a ForwardIterator");

    size_type __sz = size();
    size_type __cap = capacity();
    size_type __n = static_cast<size_type>(std::__1::distance(__first, __last));
    if (__n)
    {
        typedef typename iterator_traits<_ForwardIterator>::reference _CharRef;
        _CharRef __tmp_ref = *__first;
        if (__ptr_in_range(std::__1::addressof(__tmp_ref), data(), data() + size()))
        {
            const basic_string __temp (__first, __last, __alloc());
            append(__temp.data(), __temp.size());
        }
        else
        {
            if (__cap - __sz < __n)
                __grow_by(__cap, __sz + __n - __cap, __sz, __sz, 0);
            pointer __p = __get_pointer() + __sz;
            for (; __first != __last; ++__p, ++__first)
                traits_type::assign(*__p, *__first);
            traits_type::assign(*__p, value_type());
            __set_size(__sz + __n);
        }
    }
    return *this;
}

template <class _CharT, class _Traits, class _Allocator>
inline
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::append(const basic_string& __str)
{
    return append(__str.data(), __str.size());
}

template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::append(const basic_string& __str, size_type __pos, size_type __n)
{
    size_type __sz = __str.size();
    if (__pos > __sz)
        this->__throw_out_of_range();
    return append(__str.data() + __pos, std::__1::min(__n, __sz - __pos));
}

template <class _CharT, class _Traits, class _Allocator>
template <class _Tp>
    typename enable_if
    <
        __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
        basic_string<_CharT, _Traits, _Allocator>&
    >::type
basic_string<_CharT, _Traits, _Allocator>::append(const _Tp & __t, size_type __pos, size_type __n)
{
    __self_view __sv = __t;
    size_type __sz = __sv.size();
    if (__pos > __sz)
        this->__throw_out_of_range();
    return append(__sv.data() + __pos, std::__1::min(__n, __sz - __pos));
}

template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::append(const value_type* __s)
{
    ((void)0);
    return append(__s, traits_type::length(__s));
}



template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::insert(size_type __pos, const value_type* __s, size_type __n)
{
    ((void)0);
    size_type __sz = size();
    if (__pos > __sz)
        this->__throw_out_of_range();
    size_type __cap = capacity();
    if (__cap - __sz >= __n)
    {
        if (__n)
        {
            value_type* __p = std::__1::__to_address(__get_pointer());
            size_type __n_move = __sz - __pos;
            if (__n_move != 0)
            {
                if (__p + __pos <= __s && __s < __p + __sz)
                    __s += __n;
                traits_type::move(__p + __pos + __n, __p + __pos, __n_move);
            }
            traits_type::move(__p + __pos, __s, __n);
            __sz += __n;
            __set_size(__sz);
            traits_type::assign(__p[__sz], value_type());
        }
    }
    else
        __grow_by_and_replace(__cap, __sz + __n - __cap, __sz, __pos, 0, __n, __s);
    return *this;
}

template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::insert(size_type __pos, size_type __n, value_type __c)
{
    size_type __sz = size();
    if (__pos > __sz)
        this->__throw_out_of_range();
    if (__n)
    {
        size_type __cap = capacity();
        value_type* __p;
        if (__cap - __sz >= __n)
        {
            __p = std::__1::__to_address(__get_pointer());
            size_type __n_move = __sz - __pos;
            if (__n_move != 0)
                traits_type::move(__p + __pos + __n, __p + __pos, __n_move);
        }
        else
        {
            __grow_by(__cap, __sz + __n - __cap, __sz, __pos, 0, __n);
            __p = std::__1::__to_address(__get_long_pointer());
        }
        traits_type::assign(__p + __pos, __n, __c);
        __sz += __n;
        __set_size(__sz);
        traits_type::assign(__p[__sz], value_type());
    }
    return *this;
}

template <class _CharT, class _Traits, class _Allocator>
template<class _InputIterator>
typename enable_if
<
   __is_exactly_cpp17_input_iterator<_InputIterator>::value
        || !__libcpp_string_gets_noexcept_iterator<_InputIterator>::value,
   typename basic_string<_CharT, _Traits, _Allocator>::iterator
>::type
basic_string<_CharT, _Traits, _Allocator>::insert(const_iterator __pos, _InputIterator __first, _InputIterator __last)
{





    const basic_string __temp(__first, __last, __alloc());
    return insert(__pos, __temp.data(), __temp.data() + __temp.size());
}

template <class _CharT, class _Traits, class _Allocator>
template<class _ForwardIterator>
typename enable_if
<
    __is_cpp17_forward_iterator<_ForwardIterator>::value
        && __libcpp_string_gets_noexcept_iterator<_ForwardIterator>::value,
    typename basic_string<_CharT, _Traits, _Allocator>::iterator
>::type
basic_string<_CharT, _Traits, _Allocator>::insert(const_iterator __pos, _ForwardIterator __first, _ForwardIterator __last)
{





    size_type __ip = static_cast<size_type>(__pos - begin());
    size_type __n = static_cast<size_type>(std::__1::distance(__first, __last));
    if (__n)
    {
        typedef typename iterator_traits<_ForwardIterator>::reference _CharRef;
        _CharRef __tmp_char = *__first;
        if (__ptr_in_range(std::__1::addressof(__tmp_char), data(), data() + size()))
        {
            const basic_string __temp(__first, __last, __alloc());
            return insert(__pos, __temp.data(), __temp.data() + __temp.size());
        }

        size_type __sz = size();
        size_type __cap = capacity();
        value_type* __p;
        if (__cap - __sz >= __n)
        {
            __p = std::__1::__to_address(__get_pointer());
            size_type __n_move = __sz - __ip;
            if (__n_move != 0)
                traits_type::move(__p + __ip + __n, __p + __ip, __n_move);
        }
        else
        {
            __grow_by(__cap, __sz + __n - __cap, __sz, __ip, 0, __n);
            __p = std::__1::__to_address(__get_long_pointer());
        }
        __sz += __n;
        __set_size(__sz);
        traits_type::assign(__p[__sz], value_type());
        for (__p += __ip; __first != __last; ++__p, ++__first)
            traits_type::assign(*__p, *__first);
    }
    return begin() + __ip;
}

template <class _CharT, class _Traits, class _Allocator>
inline
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::insert(size_type __pos1, const basic_string& __str)
{
    return insert(__pos1, __str.data(), __str.size());
}

template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::insert(size_type __pos1, const basic_string& __str,
                                                  size_type __pos2, size_type __n)
{
    size_type __str_sz = __str.size();
    if (__pos2 > __str_sz)
        this->__throw_out_of_range();
    return insert(__pos1, __str.data() + __pos2, std::__1::min(__n, __str_sz - __pos2));
}

template <class _CharT, class _Traits, class _Allocator>
template <class _Tp>
typename enable_if
<
    __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
    basic_string<_CharT, _Traits, _Allocator>&
>::type
basic_string<_CharT, _Traits, _Allocator>::insert(size_type __pos1, const _Tp& __t,
                                                  size_type __pos2, size_type __n)
{
    __self_view __sv = __t;
    size_type __str_sz = __sv.size();
    if (__pos2 > __str_sz)
        this->__throw_out_of_range();
    return insert(__pos1, __sv.data() + __pos2, std::__1::min(__n, __str_sz - __pos2));
}

template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::insert(size_type __pos, const value_type* __s)
{
    ((void)0);
    return insert(__pos, __s, traits_type::length(__s));
}

template <class _CharT, class _Traits, class _Allocator>
typename basic_string<_CharT, _Traits, _Allocator>::iterator
basic_string<_CharT, _Traits, _Allocator>::insert(const_iterator __pos, value_type __c)
{
    size_type __ip = static_cast<size_type>(__pos - begin());
    size_type __sz = size();
    size_type __cap = capacity();
    value_type* __p;
    if (__cap == __sz)
    {
        __grow_by(__cap, 1, __sz, __ip, 0, 1);
        __p = std::__1::__to_address(__get_long_pointer());
    }
    else
    {
        __p = std::__1::__to_address(__get_pointer());
        size_type __n_move = __sz - __ip;
        if (__n_move != 0)
            traits_type::move(__p + __ip + 1, __p + __ip, __n_move);
    }
    traits_type::assign(__p[__ip], __c);
    traits_type::assign(__p[++__sz], value_type());
    __set_size(__sz);
    return begin() + static_cast<difference_type>(__ip);
}

template <class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::iterator
basic_string<_CharT, _Traits, _Allocator>::insert(const_iterator __pos, size_type __n, value_type __c)
{





    difference_type __p = __pos - begin();
    insert(static_cast<size_type>(__p), __n, __c);
    return begin() + __p;
}



template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::replace(size_type __pos, size_type __n1, const value_type* __s, size_type __n2)
    __attribute__((__no_sanitize__("unsigned-integer-overflow")))
{
    ((void)0);
    size_type __sz = size();
    if (__pos > __sz)
        this->__throw_out_of_range();
    __n1 = std::__1::min(__n1, __sz - __pos);
    size_type __cap = capacity();
    if (__cap - __sz + __n1 >= __n2)
    {
        value_type* __p = std::__1::__to_address(__get_pointer());
        if (__n1 != __n2)
        {
            size_type __n_move = __sz - __pos - __n1;
            if (__n_move != 0)
            {
                if (__n1 > __n2)
                {
                    traits_type::move(__p + __pos, __s, __n2);
                    traits_type::move(__p + __pos + __n2, __p + __pos + __n1, __n_move);
                    goto __finish;
                }
                if (__p + __pos < __s && __s < __p + __sz)
                {
                    if (__p + __pos + __n1 <= __s)
                        __s += __n2 - __n1;
                    else
                    {
                        traits_type::move(__p + __pos, __s, __n1);
                        __pos += __n1;
                        __s += __n2;
                        __n2 -= __n1;
                        __n1 = 0;
                    }
                }
                traits_type::move(__p + __pos + __n2, __p + __pos + __n1, __n_move);
            }
        }
        traits_type::move(__p + __pos, __s, __n2);
__finish:


        __sz += __n2 - __n1;
        __set_size(__sz);
        __invalidate_iterators_past(__sz);
        traits_type::assign(__p[__sz], value_type());
    }
    else
        __grow_by_and_replace(__cap, __sz - __n1 + __n2 - __cap, __sz, __pos, __n1, __n2, __s);
    return *this;
}

template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::replace(size_type __pos, size_type __n1, size_type __n2, value_type __c)
    __attribute__((__no_sanitize__("unsigned-integer-overflow")))
{
    size_type __sz = size();
    if (__pos > __sz)
        this->__throw_out_of_range();
    __n1 = std::__1::min(__n1, __sz - __pos);
    size_type __cap = capacity();
    value_type* __p;
    if (__cap - __sz + __n1 >= __n2)
    {
        __p = std::__1::__to_address(__get_pointer());
        if (__n1 != __n2)
        {
            size_type __n_move = __sz - __pos - __n1;
            if (__n_move != 0)
                traits_type::move(__p + __pos + __n2, __p + __pos + __n1, __n_move);
        }
    }
    else
    {
        __grow_by(__cap, __sz - __n1 + __n2 - __cap, __sz, __pos, __n1, __n2);
        __p = std::__1::__to_address(__get_long_pointer());
    }
    traits_type::assign(__p + __pos, __n2, __c);
    __sz += __n2 - __n1;
    __set_size(__sz);
    __invalidate_iterators_past(__sz);
    traits_type::assign(__p[__sz], value_type());
    return *this;
}

template <class _CharT, class _Traits, class _Allocator>
template<class _InputIterator>
typename enable_if
<
    __is_cpp17_input_iterator<_InputIterator>::value,
    basic_string<_CharT, _Traits, _Allocator>&
>::type
basic_string<_CharT, _Traits, _Allocator>::replace(const_iterator __i1, const_iterator __i2,
                                                   _InputIterator __j1, _InputIterator __j2)
{
    const basic_string __temp(__j1, __j2, __alloc());
    return this->replace(__i1, __i2, __temp);
}

template <class _CharT, class _Traits, class _Allocator>
inline
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::replace(size_type __pos1, size_type __n1, const basic_string& __str)
{
    return replace(__pos1, __n1, __str.data(), __str.size());
}

template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::replace(size_type __pos1, size_type __n1, const basic_string& __str,
                                                   size_type __pos2, size_type __n2)
{
    size_type __str_sz = __str.size();
    if (__pos2 > __str_sz)
        this->__throw_out_of_range();
    return replace(__pos1, __n1, __str.data() + __pos2, std::__1::min(__n2, __str_sz - __pos2));
}

template <class _CharT, class _Traits, class _Allocator>
template <class _Tp>
typename enable_if
<
    __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
    basic_string<_CharT, _Traits, _Allocator>&
>::type
basic_string<_CharT, _Traits, _Allocator>::replace(size_type __pos1, size_type __n1, const _Tp& __t,
                                                   size_type __pos2, size_type __n2)
{
    __self_view __sv = __t;
    size_type __str_sz = __sv.size();
    if (__pos2 > __str_sz)
        this->__throw_out_of_range();
    return replace(__pos1, __n1, __sv.data() + __pos2, std::__1::min(__n2, __str_sz - __pos2));
}

template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::replace(size_type __pos, size_type __n1, const value_type* __s)
{
    ((void)0);
    return replace(__pos, __n1, __s, traits_type::length(__s));
}

template <class _CharT, class _Traits, class _Allocator>
inline
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::replace(const_iterator __i1, const_iterator __i2, const basic_string& __str)
{
    return replace(static_cast<size_type>(__i1 - begin()), static_cast<size_type>(__i2 - __i1),
                   __str.data(), __str.size());
}

template <class _CharT, class _Traits, class _Allocator>
inline
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::replace(const_iterator __i1, const_iterator __i2, const value_type* __s, size_type __n)
{
    return replace(static_cast<size_type>(__i1 - begin()), static_cast<size_type>(__i2 - __i1), __s, __n);
}

template <class _CharT, class _Traits, class _Allocator>
inline
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::replace(const_iterator __i1, const_iterator __i2, const value_type* __s)
{
    return replace(static_cast<size_type>(__i1 - begin()), static_cast<size_type>(__i2 - __i1), __s);
}

template <class _CharT, class _Traits, class _Allocator>
inline
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::replace(const_iterator __i1, const_iterator __i2, size_type __n, value_type __c)
{
    return replace(static_cast<size_type>(__i1 - begin()), static_cast<size_type>(__i2 - __i1), __n, __c);
}



template <class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>&
basic_string<_CharT, _Traits, _Allocator>::erase(size_type __pos, size_type __n)
{
    size_type __sz = size();
    if (__pos > __sz)
        this->__throw_out_of_range();
    if (__n)
    {
        value_type* __p = std::__1::__to_address(__get_pointer());
        __n = std::__1::min(__n, __sz - __pos);
        size_type __n_move = __sz - __pos - __n;
        if (__n_move != 0)
            traits_type::move(__p + __pos, __p + __pos + __n, __n_move);
        __sz -= __n;
        __set_size(__sz);
        __invalidate_iterators_past(__sz);
        traits_type::assign(__p[__sz], value_type());
    }
    return *this;
}

template <class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::iterator
basic_string<_CharT, _Traits, _Allocator>::erase(const_iterator __pos)
{





    ((void)0);

    iterator __b = begin();
    size_type __r = static_cast<size_type>(__pos - __b);
    erase(__r, 1);
    return __b + static_cast<difference_type>(__r);
}

template <class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::iterator
basic_string<_CharT, _Traits, _Allocator>::erase(const_iterator __first, const_iterator __last)
{





    ((void)0);
    iterator __b = begin();
    size_type __r = static_cast<size_type>(__first - __b);
    erase(__r, static_cast<size_type>(__last - __first));
    return __b + static_cast<difference_type>(__r);
}

template <class _CharT, class _Traits, class _Allocator>
inline
void
basic_string<_CharT, _Traits, _Allocator>::pop_back()
{
    ((void)0);
    size_type __sz;
    if (__is_long())
    {
        __sz = __get_long_size() - 1;
        __set_long_size(__sz);
        traits_type::assign(*(__get_long_pointer() + __sz), value_type());
    }
    else
    {
        __sz = __get_short_size() - 1;
        __set_short_size(__sz);
        traits_type::assign(*(__get_short_pointer() + __sz), value_type());
    }
    __invalidate_iterators_past(__sz);
}

template <class _CharT, class _Traits, class _Allocator>
inline
void
basic_string<_CharT, _Traits, _Allocator>::clear() throw()
{
    __invalidate_all_iterators();
    if (__is_long())
    {
        traits_type::assign(*__get_long_pointer(), value_type());
        __set_long_size(0);
    }
    else
    {
        traits_type::assign(*__get_short_pointer(), value_type());
        __set_short_size(0);
    }
}

template <class _CharT, class _Traits, class _Allocator>
inline
void
basic_string<_CharT, _Traits, _Allocator>::__erase_to_end(size_type __pos)
{
    if (__is_long())
    {
        traits_type::assign(*(__get_long_pointer() + __pos), value_type());
        __set_long_size(__pos);
    }
    else
    {
        traits_type::assign(*(__get_short_pointer() + __pos), value_type());
        __set_short_size(__pos);
    }
    __invalidate_iterators_past(__pos);
}

template <class _CharT, class _Traits, class _Allocator>
void
basic_string<_CharT, _Traits, _Allocator>::resize(size_type __n, value_type __c)
{
    size_type __sz = size();
    if (__n > __sz)
        append(__n - __sz, __c);
    else
        __erase_to_end(__n);
}

template <class _CharT, class _Traits, class _Allocator>
inline void
basic_string<_CharT, _Traits, _Allocator>::__resize_default_init(size_type __n)
{
    size_type __sz = size();
    if (__n > __sz) {
       __append_default_init(__n - __sz);
    } else
        __erase_to_end(__n);
}

template <class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::max_size() const throw()
{
    size_type __m = __alloc_traits::max_size(__alloc());



    return __m - __alignment;

}

template <class _CharT, class _Traits, class _Allocator>
void
basic_string<_CharT, _Traits, _Allocator>::reserve(size_type __res_arg)
{
    if (__res_arg > max_size())
        this->__throw_length_error();
    size_type __cap = capacity();
    size_type __sz = size();
    __res_arg = std::__1::max(__res_arg, __sz);
    __res_arg = __recommend(__res_arg);
    if (__res_arg != __cap)
    {
        pointer __new_data, __p;
        bool __was_long, __now_long;
        if (__res_arg == __min_cap - 1)
        {
            __was_long = true;
            __now_long = false;
            __new_data = __get_short_pointer();
            __p = __get_long_pointer();
        }
        else
        {
            if (__res_arg > __cap)
                __new_data = __alloc_traits::allocate(__alloc(), __res_arg+1);
            else
            {

                try
                {

                    __new_data = __alloc_traits::allocate(__alloc(), __res_arg+1);

                }
                catch (...)
                {
                    return;
                }




            }
            __now_long = true;
            __was_long = __is_long();
            __p = __get_pointer();
        }
        traits_type::copy(std::__1::__to_address(__new_data),
                          std::__1::__to_address(__p), size()+1);
        if (__was_long)
            __alloc_traits::deallocate(__alloc(), __p, __cap+1);
        if (__now_long)
        {
            __set_long_cap(__res_arg+1);
            __set_long_size(__sz);
            __set_long_pointer(__new_data);
        }
        else
            __set_short_size(__sz);
        __invalidate_all_iterators();
    }
}

template <class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::const_reference
basic_string<_CharT, _Traits, _Allocator>::operator[](size_type __pos) const throw()
{
    ((void)0);
    return *(data() + __pos);
}

template <class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::reference
basic_string<_CharT, _Traits, _Allocator>::operator[](size_type __pos) throw()
{
    ((void)0);
    return *(__get_pointer() + __pos);
}

template <class _CharT, class _Traits, class _Allocator>
typename basic_string<_CharT, _Traits, _Allocator>::const_reference
basic_string<_CharT, _Traits, _Allocator>::at(size_type __n) const
{
    if (__n >= size())
        this->__throw_out_of_range();
    return (*this)[__n];
}

template <class _CharT, class _Traits, class _Allocator>
typename basic_string<_CharT, _Traits, _Allocator>::reference
basic_string<_CharT, _Traits, _Allocator>::at(size_type __n)
{
    if (__n >= size())
        this->__throw_out_of_range();
    return (*this)[__n];
}

template <class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::reference
basic_string<_CharT, _Traits, _Allocator>::front() throw()
{
    ((void)0);
    return *__get_pointer();
}

template <class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::const_reference
basic_string<_CharT, _Traits, _Allocator>::front() const throw()
{
    ((void)0);
    return *data();
}

template <class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::reference
basic_string<_CharT, _Traits, _Allocator>::back() throw()
{
    ((void)0);
    return *(__get_pointer() + size() - 1);
}

template <class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::const_reference
basic_string<_CharT, _Traits, _Allocator>::back() const throw()
{
    ((void)0);
    return *(data() + size() - 1);
}

template <class _CharT, class _Traits, class _Allocator>
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::copy(value_type* __s, size_type __n, size_type __pos) const
{
    size_type __sz = size();
    if (__pos > __sz)
        this->__throw_out_of_range();
    size_type __rlen = std::__1::min(__n, __sz - __pos);
    traits_type::copy(__s, data() + __pos, __rlen);
    return __rlen;
}

template <class _CharT, class _Traits, class _Allocator>
inline
basic_string<_CharT, _Traits, _Allocator>
basic_string<_CharT, _Traits, _Allocator>::substr(size_type __pos, size_type __n) const
{
    return basic_string(*this, __pos, __n, __alloc());
}

template <class _CharT, class _Traits, class _Allocator>
inline
void
basic_string<_CharT, _Traits, _Allocator>::swap(basic_string& __str)






{







    ((void)0);



    std::__1::swap(__r_.first(), __str.__r_.first());
    __swap_allocator(__alloc(), __str.__alloc());
}



template <class _Traits>
struct __attribute__ ((__visibility__("hidden"))) __traits_eq
{
    typedef typename _Traits::char_type char_type;
    __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
    bool operator()(const char_type& __x, const char_type& __y) throw()
        {return _Traits::eq(__x, __y);}
};

template<class _CharT, class _Traits, class _Allocator>
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find(const value_type* __s,
                                                size_type __pos,
                                                size_type __n) const throw()
{
    ((void)0);
    return __str_find<value_type, size_type, traits_type, npos>
        (data(), size(), __s, __pos, __n);
}

template<class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find(const basic_string& __str,
                                                size_type __pos) const throw()
{
    return __str_find<value_type, size_type, traits_type, npos>
        (data(), size(), __str.data(), __pos, __str.size());
}

template<class _CharT, class _Traits, class _Allocator>
template <class _Tp>
typename enable_if
<
    __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
    typename basic_string<_CharT, _Traits, _Allocator>::size_type
>::type
basic_string<_CharT, _Traits, _Allocator>::find(const _Tp &__t,
                                                size_type __pos) const
{
    __self_view __sv = __t;
    return __str_find<value_type, size_type, traits_type, npos>
        (data(), size(), __sv.data(), __pos, __sv.size());
}

template<class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find(const value_type* __s,
                                                size_type __pos) const throw()
{
    ((void)0);
    return __str_find<value_type, size_type, traits_type, npos>
        (data(), size(), __s, __pos, traits_type::length(__s));
}

template<class _CharT, class _Traits, class _Allocator>
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find(value_type __c,
                                                size_type __pos) const throw()
{
    return __str_find<value_type, size_type, traits_type, npos>
        (data(), size(), __c, __pos);
}



template<class _CharT, class _Traits, class _Allocator>
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::rfind(const value_type* __s,
                                                 size_type __pos,
                                                 size_type __n) const throw()
{
    ((void)0);
    return __str_rfind<value_type, size_type, traits_type, npos>
        (data(), size(), __s, __pos, __n);
}

template<class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::rfind(const basic_string& __str,
                                                 size_type __pos) const throw()
{
    return __str_rfind<value_type, size_type, traits_type, npos>
        (data(), size(), __str.data(), __pos, __str.size());
}

template<class _CharT, class _Traits, class _Allocator>
template <class _Tp>
typename enable_if
<
    __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
    typename basic_string<_CharT, _Traits, _Allocator>::size_type
>::type
basic_string<_CharT, _Traits, _Allocator>::rfind(const _Tp& __t,
                                                size_type __pos) const
{
    __self_view __sv = __t;
    return __str_rfind<value_type, size_type, traits_type, npos>
        (data(), size(), __sv.data(), __pos, __sv.size());
}

template<class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::rfind(const value_type* __s,
                                                 size_type __pos) const throw()
{
    ((void)0);
    return __str_rfind<value_type, size_type, traits_type, npos>
        (data(), size(), __s, __pos, traits_type::length(__s));
}

template<class _CharT, class _Traits, class _Allocator>
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::rfind(value_type __c,
                                                 size_type __pos) const throw()
{
    return __str_rfind<value_type, size_type, traits_type, npos>
        (data(), size(), __c, __pos);
}



template<class _CharT, class _Traits, class _Allocator>
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find_first_of(const value_type* __s,
                                                         size_type __pos,
                                                         size_type __n) const throw()
{
    ((void)0);
    return __str_find_first_of<value_type, size_type, traits_type, npos>
        (data(), size(), __s, __pos, __n);
}

template<class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find_first_of(const basic_string& __str,
                                                         size_type __pos) const throw()
{
    return __str_find_first_of<value_type, size_type, traits_type, npos>
        (data(), size(), __str.data(), __pos, __str.size());
}

template<class _CharT, class _Traits, class _Allocator>
template <class _Tp>
typename enable_if
<
    __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
    typename basic_string<_CharT, _Traits, _Allocator>::size_type
>::type
basic_string<_CharT, _Traits, _Allocator>::find_first_of(const _Tp& __t,
                                                size_type __pos) const
{
    __self_view __sv = __t;
    return __str_find_first_of<value_type, size_type, traits_type, npos>
        (data(), size(), __sv.data(), __pos, __sv.size());
}

template<class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find_first_of(const value_type* __s,
                                                         size_type __pos) const throw()
{
    ((void)0);
    return __str_find_first_of<value_type, size_type, traits_type, npos>
        (data(), size(), __s, __pos, traits_type::length(__s));
}

template<class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find_first_of(value_type __c,
                                                         size_type __pos) const throw()
{
    return find(__c, __pos);
}



template<class _CharT, class _Traits, class _Allocator>
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find_last_of(const value_type* __s,
                                                        size_type __pos,
                                                        size_type __n) const throw()
{
    ((void)0);
    return __str_find_last_of<value_type, size_type, traits_type, npos>
        (data(), size(), __s, __pos, __n);
}

template<class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find_last_of(const basic_string& __str,
                                                        size_type __pos) const throw()
{
    return __str_find_last_of<value_type, size_type, traits_type, npos>
        (data(), size(), __str.data(), __pos, __str.size());
}

template<class _CharT, class _Traits, class _Allocator>
template <class _Tp>
typename enable_if
<
    __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
    typename basic_string<_CharT, _Traits, _Allocator>::size_type
>::type
basic_string<_CharT, _Traits, _Allocator>::find_last_of(const _Tp& __t,
                                                size_type __pos) const
{
    __self_view __sv = __t;
    return __str_find_last_of<value_type, size_type, traits_type, npos>
        (data(), size(), __sv.data(), __pos, __sv.size());
}

template<class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find_last_of(const value_type* __s,
                                                        size_type __pos) const throw()
{
    ((void)0);
    return __str_find_last_of<value_type, size_type, traits_type, npos>
        (data(), size(), __s, __pos, traits_type::length(__s));
}

template<class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find_last_of(value_type __c,
                                                        size_type __pos) const throw()
{
    return rfind(__c, __pos);
}



template<class _CharT, class _Traits, class _Allocator>
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find_first_not_of(const value_type* __s,
                                                             size_type __pos,
                                                             size_type __n) const throw()
{
    ((void)0);
    return __str_find_first_not_of<value_type, size_type, traits_type, npos>
        (data(), size(), __s, __pos, __n);
}

template<class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find_first_not_of(const basic_string& __str,
                                                             size_type __pos) const throw()
{
    return __str_find_first_not_of<value_type, size_type, traits_type, npos>
        (data(), size(), __str.data(), __pos, __str.size());
}

template<class _CharT, class _Traits, class _Allocator>
template <class _Tp>
typename enable_if
<
    __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
    typename basic_string<_CharT, _Traits, _Allocator>::size_type
>::type
basic_string<_CharT, _Traits, _Allocator>::find_first_not_of(const _Tp& __t,
                                                size_type __pos) const
{
    __self_view __sv = __t;
    return __str_find_first_not_of<value_type, size_type, traits_type, npos>
        (data(), size(), __sv.data(), __pos, __sv.size());
}

template<class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find_first_not_of(const value_type* __s,
                                                             size_type __pos) const throw()
{
    ((void)0);
    return __str_find_first_not_of<value_type, size_type, traits_type, npos>
        (data(), size(), __s, __pos, traits_type::length(__s));
}

template<class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find_first_not_of(value_type __c,
                                                             size_type __pos) const throw()
{
    return __str_find_first_not_of<value_type, size_type, traits_type, npos>
        (data(), size(), __c, __pos);
}



template<class _CharT, class _Traits, class _Allocator>
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find_last_not_of(const value_type* __s,
                                                            size_type __pos,
                                                            size_type __n) const throw()
{
    ((void)0);
    return __str_find_last_not_of<value_type, size_type, traits_type, npos>
        (data(), size(), __s, __pos, __n);
}

template<class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find_last_not_of(const basic_string& __str,
                                                            size_type __pos) const throw()
{
    return __str_find_last_not_of<value_type, size_type, traits_type, npos>
        (data(), size(), __str.data(), __pos, __str.size());
}

template<class _CharT, class _Traits, class _Allocator>
template <class _Tp>
typename enable_if
<
    __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
    typename basic_string<_CharT, _Traits, _Allocator>::size_type
>::type
basic_string<_CharT, _Traits, _Allocator>::find_last_not_of(const _Tp& __t,
                                                size_type __pos) const
{
    __self_view __sv = __t;
    return __str_find_last_not_of<value_type, size_type, traits_type, npos>
        (data(), size(), __sv.data(), __pos, __sv.size());
}

template<class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find_last_not_of(const value_type* __s,
                                                            size_type __pos) const throw()
{
    ((void)0);
    return __str_find_last_not_of<value_type, size_type, traits_type, npos>
        (data(), size(), __s, __pos, traits_type::length(__s));
}

template<class _CharT, class _Traits, class _Allocator>
inline
typename basic_string<_CharT, _Traits, _Allocator>::size_type
basic_string<_CharT, _Traits, _Allocator>::find_last_not_of(value_type __c,
                                                            size_type __pos) const throw()
{
    return __str_find_last_not_of<value_type, size_type, traits_type, npos>
        (data(), size(), __c, __pos);
}



template <class _CharT, class _Traits, class _Allocator>
template <class _Tp>
typename enable_if
<
    __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
    int
>::type
basic_string<_CharT, _Traits, _Allocator>::compare(const _Tp& __t) const
{
    __self_view __sv = __t;
    size_t __lhs_sz = size();
    size_t __rhs_sz = __sv.size();
    int __result = traits_type::compare(data(), __sv.data(),
                                        std::__1::min(__lhs_sz, __rhs_sz));
    if (__result != 0)
        return __result;
    if (__lhs_sz < __rhs_sz)
        return -1;
    if (__lhs_sz > __rhs_sz)
        return 1;
    return 0;
}

template <class _CharT, class _Traits, class _Allocator>
inline
int
basic_string<_CharT, _Traits, _Allocator>::compare(const basic_string& __str) const throw()
{
    return compare(__self_view(__str));
}

template <class _CharT, class _Traits, class _Allocator>
int
basic_string<_CharT, _Traits, _Allocator>::compare(size_type __pos1,
                                                   size_type __n1,
                                                   const value_type* __s,
                                                   size_type __n2) const
{
    ((void)0);
    size_type __sz = size();
    if (__pos1 > __sz || __n2 == npos)
        this->__throw_out_of_range();
    size_type __rlen = std::__1::min(__n1, __sz - __pos1);
    int __r = traits_type::compare(data() + __pos1, __s, std::__1::min(__rlen, __n2));
    if (__r == 0)
    {
        if (__rlen < __n2)
            __r = -1;
        else if (__rlen > __n2)
            __r = 1;
    }
    return __r;
}

template <class _CharT, class _Traits, class _Allocator>
template <class _Tp>
typename enable_if
<
    __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
    int
>::type
basic_string<_CharT, _Traits, _Allocator>::compare(size_type __pos1,
                                                   size_type __n1,
                                                   const _Tp& __t) const
{
    __self_view __sv = __t;
    return compare(__pos1, __n1, __sv.data(), __sv.size());
}

template <class _CharT, class _Traits, class _Allocator>
inline
int
basic_string<_CharT, _Traits, _Allocator>::compare(size_type __pos1,
                                                   size_type __n1,
                                                   const basic_string& __str) const
{
    return compare(__pos1, __n1, __str.data(), __str.size());
}

template <class _CharT, class _Traits, class _Allocator>
template <class _Tp>
typename enable_if
<
    __can_be_converted_to_string_view<_CharT, _Traits, _Tp>::value,
    int
>::type
basic_string<_CharT, _Traits, _Allocator>::compare(size_type __pos1,
                                                   size_type __n1,
                                                   const _Tp& __t,
                                                   size_type __pos2,
                                                   size_type __n2) const
{
    __self_view __sv = __t;
    return __self_view(*this).substr(__pos1, __n1).compare(__sv.substr(__pos2, __n2));
}

template <class _CharT, class _Traits, class _Allocator>
int
basic_string<_CharT, _Traits, _Allocator>::compare(size_type __pos1,
                                                   size_type __n1,
                                                   const basic_string& __str,
                                                   size_type __pos2,
                                                   size_type __n2) const
{
        return compare(__pos1, __n1, __self_view(__str), __pos2, __n2);
}

template <class _CharT, class _Traits, class _Allocator>
int
basic_string<_CharT, _Traits, _Allocator>::compare(const value_type* __s) const throw()
{
    ((void)0);
    return compare(0, npos, __s, traits_type::length(__s));
}

template <class _CharT, class _Traits, class _Allocator>
int
basic_string<_CharT, _Traits, _Allocator>::compare(size_type __pos1,
                                                   size_type __n1,
                                                   const value_type* __s) const
{
    ((void)0);
    return compare(__pos1, __n1, __s, traits_type::length(__s));
}



template<class _CharT, class _Traits, class _Allocator>
inline
bool
basic_string<_CharT, _Traits, _Allocator>::__invariants() const
{
    if (size() > capacity())
        return false;
    if (capacity() < __min_cap - 1)
        return false;
    if (data() == 0)
        return false;
    if (data()[size()] != value_type(0))
        return false;
    return true;
}



template<class _CharT, class _Traits, class _Allocator>
inline
void
basic_string<_CharT, _Traits, _Allocator>::__clear_and_shrink() throw()
{
    clear();
    if(__is_long())
    {
        __alloc_traits::deallocate(__alloc(), __get_long_pointer(), capacity() + 1);
        __set_long_cap(0);
        __set_short_size(0);
    }
}



template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator==(const basic_string<_CharT, _Traits, _Allocator>& __lhs,
           const basic_string<_CharT, _Traits, _Allocator>& __rhs) throw()
{
    size_t __lhs_sz = __lhs.size();
    return __lhs_sz == __rhs.size() && _Traits::compare(__lhs.data(),
                                                        __rhs.data(),
                                                        __lhs_sz) == 0;
}

template<class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator==(const basic_string<char, char_traits<char>, _Allocator>& __lhs,
           const basic_string<char, char_traits<char>, _Allocator>& __rhs) throw()
{
    size_t __lhs_sz = __lhs.size();
    if (__lhs_sz != __rhs.size())
        return false;
    const char* __lp = __lhs.data();
    const char* __rp = __rhs.data();
    if (__lhs.__is_long())
        return char_traits<char>::compare(__lp, __rp, __lhs_sz) == 0;
    for (; __lhs_sz != 0; --__lhs_sz, ++__lp, ++__rp)
        if (*__lp != *__rp)
            return false;
    return true;
}

template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator==(const _CharT* __lhs,
           const basic_string<_CharT, _Traits, _Allocator>& __rhs) throw()
{
    typedef basic_string<_CharT, _Traits, _Allocator> _String;
    ((void)0);
    size_t __lhs_len = _Traits::length(__lhs);
    if (__lhs_len != __rhs.size()) return false;
    return __rhs.compare(0, _String::npos, __lhs, __lhs_len) == 0;
}

template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator==(const basic_string<_CharT,_Traits,_Allocator>& __lhs,
           const _CharT* __rhs) throw()
{
    typedef basic_string<_CharT, _Traits, _Allocator> _String;
    ((void)0);
    size_t __rhs_len = _Traits::length(__rhs);
    if (__rhs_len != __lhs.size()) return false;
    return __lhs.compare(0, _String::npos, __rhs, __rhs_len) == 0;
}

template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(const basic_string<_CharT,_Traits,_Allocator>& __lhs,
           const basic_string<_CharT, _Traits, _Allocator>& __rhs) throw()
{
    return !(__lhs == __rhs);
}

template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(const _CharT* __lhs,
           const basic_string<_CharT, _Traits, _Allocator>& __rhs) throw()
{
    return !(__lhs == __rhs);
}

template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator!=(const basic_string<_CharT, _Traits, _Allocator>& __lhs,
           const _CharT* __rhs) throw()
{
    return !(__lhs == __rhs);
}



template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator< (const basic_string<_CharT, _Traits, _Allocator>& __lhs,
           const basic_string<_CharT, _Traits, _Allocator>& __rhs) throw()
{
    return __lhs.compare(__rhs) < 0;
}

template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator< (const basic_string<_CharT, _Traits, _Allocator>& __lhs,
           const _CharT* __rhs) throw()
{
    return __lhs.compare(__rhs) < 0;
}

template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator< (const _CharT* __lhs,
           const basic_string<_CharT, _Traits, _Allocator>& __rhs) throw()
{
    return __rhs.compare(__lhs) > 0;
}



template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator> (const basic_string<_CharT, _Traits, _Allocator>& __lhs,
           const basic_string<_CharT, _Traits, _Allocator>& __rhs) throw()
{
    return __rhs < __lhs;
}

template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator> (const basic_string<_CharT, _Traits, _Allocator>& __lhs,
           const _CharT* __rhs) throw()
{
    return __rhs < __lhs;
}

template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator> (const _CharT* __lhs,
           const basic_string<_CharT, _Traits, _Allocator>& __rhs) throw()
{
    return __rhs < __lhs;
}



template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<=(const basic_string<_CharT, _Traits, _Allocator>& __lhs,
           const basic_string<_CharT, _Traits, _Allocator>& __rhs) throw()
{
    return !(__rhs < __lhs);
}

template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<=(const basic_string<_CharT, _Traits, _Allocator>& __lhs,
           const _CharT* __rhs) throw()
{
    return !(__rhs < __lhs);
}

template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator<=(const _CharT* __lhs,
           const basic_string<_CharT, _Traits, _Allocator>& __rhs) throw()
{
    return !(__rhs < __lhs);
}



template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>=(const basic_string<_CharT, _Traits, _Allocator>& __lhs,
           const basic_string<_CharT, _Traits, _Allocator>& __rhs) throw()
{
    return !(__lhs < __rhs);
}

template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>=(const basic_string<_CharT, _Traits, _Allocator>& __lhs,
           const _CharT* __rhs) throw()
{
    return !(__lhs < __rhs);
}

template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
bool
operator>=(const _CharT* __lhs,
           const basic_string<_CharT, _Traits, _Allocator>& __rhs) throw()
{
    return !(__lhs < __rhs);
}



template<class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>
operator+(const basic_string<_CharT, _Traits, _Allocator>& __lhs,
          const basic_string<_CharT, _Traits, _Allocator>& __rhs)
{
    basic_string<_CharT, _Traits, _Allocator> __r(__lhs.get_allocator());
    typename basic_string<_CharT, _Traits, _Allocator>::size_type __lhs_sz = __lhs.size();
    typename basic_string<_CharT, _Traits, _Allocator>::size_type __rhs_sz = __rhs.size();
    __r.__init(__lhs.data(), __lhs_sz, __lhs_sz + __rhs_sz);
    __r.append(__rhs.data(), __rhs_sz);
    return __r;
}

template<class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>
operator+(const _CharT* __lhs , const basic_string<_CharT,_Traits,_Allocator>& __rhs)
{
    basic_string<_CharT, _Traits, _Allocator> __r(__rhs.get_allocator());
    typename basic_string<_CharT, _Traits, _Allocator>::size_type __lhs_sz = _Traits::length(__lhs);
    typename basic_string<_CharT, _Traits, _Allocator>::size_type __rhs_sz = __rhs.size();
    __r.__init(__lhs, __lhs_sz, __lhs_sz + __rhs_sz);
    __r.append(__rhs.data(), __rhs_sz);
    return __r;
}

template<class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>
operator+(_CharT __lhs, const basic_string<_CharT,_Traits,_Allocator>& __rhs)
{
    basic_string<_CharT, _Traits, _Allocator> __r(__rhs.get_allocator());
    typename basic_string<_CharT, _Traits, _Allocator>::size_type __rhs_sz = __rhs.size();
    __r.__init(&__lhs, 1, 1 + __rhs_sz);
    __r.append(__rhs.data(), __rhs_sz);
    return __r;
}

template<class _CharT, class _Traits, class _Allocator>
inline
basic_string<_CharT, _Traits, _Allocator>
operator+(const basic_string<_CharT, _Traits, _Allocator>& __lhs, const _CharT* __rhs)
{
    basic_string<_CharT, _Traits, _Allocator> __r(__lhs.get_allocator());
    typename basic_string<_CharT, _Traits, _Allocator>::size_type __lhs_sz = __lhs.size();
    typename basic_string<_CharT, _Traits, _Allocator>::size_type __rhs_sz = _Traits::length(__rhs);
    __r.__init(__lhs.data(), __lhs_sz, __lhs_sz + __rhs_sz);
    __r.append(__rhs, __rhs_sz);
    return __r;
}

template<class _CharT, class _Traits, class _Allocator>
basic_string<_CharT, _Traits, _Allocator>
operator+(const basic_string<_CharT, _Traits, _Allocator>& __lhs, _CharT __rhs)
{
    basic_string<_CharT, _Traits, _Allocator> __r(__lhs.get_allocator());
    typename basic_string<_CharT, _Traits, _Allocator>::size_type __lhs_sz = __lhs.size();
    __r.__init(__lhs.data(), __lhs_sz, __lhs_sz + 1);
    __r.push_back(__rhs);
    return __r;
}

template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
void
swap(basic_string<_CharT, _Traits, _Allocator>& __lhs,
     basic_string<_CharT, _Traits, _Allocator>& __rhs)

{
    __lhs.swap(__rhs);
}






typedef basic_string<char16_t> u16string;
typedef basic_string<char32_t> u32string;


__attribute__ ((__visibility__("default"))) int stoi (const string& __str, size_t* __idx = 0, int __base = 10);
__attribute__ ((__visibility__("default"))) long stol (const string& __str, size_t* __idx = 0, int __base = 10);
__attribute__ ((__visibility__("default"))) unsigned long stoul (const string& __str, size_t* __idx = 0, int __base = 10);
__attribute__ ((__visibility__("default"))) long long stoll (const string& __str, size_t* __idx = 0, int __base = 10);
__attribute__ ((__visibility__("default"))) unsigned long long stoull(const string& __str, size_t* __idx = 0, int __base = 10);

__attribute__ ((__visibility__("default"))) float stof (const string& __str, size_t* __idx = 0);
__attribute__ ((__visibility__("default"))) double stod (const string& __str, size_t* __idx = 0);
__attribute__ ((__visibility__("default"))) long double stold(const string& __str, size_t* __idx = 0);

__attribute__ ((__visibility__("default"))) string to_string(int __val);
__attribute__ ((__visibility__("default"))) string to_string(unsigned __val);
__attribute__ ((__visibility__("default"))) string to_string(long __val);
__attribute__ ((__visibility__("default"))) string to_string(unsigned long __val);
__attribute__ ((__visibility__("default"))) string to_string(long long __val);
__attribute__ ((__visibility__("default"))) string to_string(unsigned long long __val);
__attribute__ ((__visibility__("default"))) string to_string(float __val);
__attribute__ ((__visibility__("default"))) string to_string(double __val);
__attribute__ ((__visibility__("default"))) string to_string(long double __val);

__attribute__ ((__visibility__("default"))) int stoi (const wstring& __str, size_t* __idx = 0, int __base = 10);
__attribute__ ((__visibility__("default"))) long stol (const wstring& __str, size_t* __idx = 0, int __base = 10);
__attribute__ ((__visibility__("default"))) unsigned long stoul (const wstring& __str, size_t* __idx = 0, int __base = 10);
__attribute__ ((__visibility__("default"))) long long stoll (const wstring& __str, size_t* __idx = 0, int __base = 10);
__attribute__ ((__visibility__("default"))) unsigned long long stoull(const wstring& __str, size_t* __idx = 0, int __base = 10);

__attribute__ ((__visibility__("default"))) float stof (const wstring& __str, size_t* __idx = 0);
__attribute__ ((__visibility__("default"))) double stod (const wstring& __str, size_t* __idx = 0);
__attribute__ ((__visibility__("default"))) long double stold(const wstring& __str, size_t* __idx = 0);

__attribute__ ((__visibility__("default"))) wstring to_wstring(int __val);
__attribute__ ((__visibility__("default"))) wstring to_wstring(unsigned __val);
__attribute__ ((__visibility__("default"))) wstring to_wstring(long __val);
__attribute__ ((__visibility__("default"))) wstring to_wstring(unsigned long __val);
__attribute__ ((__visibility__("default"))) wstring to_wstring(long long __val);
__attribute__ ((__visibility__("default"))) wstring to_wstring(unsigned long long __val);
__attribute__ ((__visibility__("default"))) wstring to_wstring(float __val);
__attribute__ ((__visibility__("default"))) wstring to_wstring(double __val);
__attribute__ ((__visibility__("default"))) wstring to_wstring(long double __val);

template<class _CharT, class _Traits, class _Allocator>
    const typename basic_string<_CharT, _Traits, _Allocator>::size_type
                   basic_string<_CharT, _Traits, _Allocator>::npos;

template <class _CharT, class _Allocator>
struct __attribute__ ((__type_visibility__("default")))
    hash<basic_string<_CharT, char_traits<_CharT>, _Allocator> >
    : public unary_function<
          basic_string<_CharT, char_traits<_CharT>, _Allocator>, size_t>
{
    size_t
    operator()(const basic_string<_CharT, char_traits<_CharT>, _Allocator>& __val) const throw()
    { return __do_string_hash(__val.data(), __val.data() + __val.size()); }
};


template<class _CharT, class _Traits, class _Allocator>
basic_ostream<_CharT, _Traits>&
operator<<(basic_ostream<_CharT, _Traits>& __os,
           const basic_string<_CharT, _Traits, _Allocator>& __str);

template<class _CharT, class _Traits, class _Allocator>
basic_istream<_CharT, _Traits>&
operator>>(basic_istream<_CharT, _Traits>& __is,
           basic_string<_CharT, _Traits, _Allocator>& __str);

template<class _CharT, class _Traits, class _Allocator>
basic_istream<_CharT, _Traits>&
getline(basic_istream<_CharT, _Traits>& __is,
        basic_string<_CharT, _Traits, _Allocator>& __str, _CharT __dlm);

template<class _CharT, class _Traits, class _Allocator>
inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage))
basic_istream<_CharT, _Traits>&
getline(basic_istream<_CharT, _Traits>& __is,
        basic_string<_CharT, _Traits, _Allocator>& __str);

extern template class __attribute__ ((__visibility__("default"))) basic_string<char>;
extern template class __attribute__ ((__visibility__("default"))) basic_string<wchar_t>;

} }










class Post;



struct Comment {
    Post* post;

    std::string title;
    std::string author;
    std::string body;
    unsigned long score;
    std::string id;
    std::string thumbnail;
    std::string url;
    void** children;
    unsigned long no_children;
};

typedef void (*comment_cb)(Comment*, void *, int);


class Subreddit;

class Post{
public:
    std::string title;
    std::string author;
    Subreddit* subreddit;
    std::string text;
    std::string thumbnail;
    std::string url;
    unsigned long upvotes;
    unsigned long downvotes;
    unsigned long score;
    std::string id;
    std::string type;

    int get_comments(unsigned long limit, std::string after, comment_cb callback, void* ptr);

    int get_comments_t(unsigned long limit, std::string after, comment_cb callback, void *ptr);

    std::string fullname();
    std::string full_url();

    bool is_img();
};

typedef void (*post_cb)(Post*, void*);



class Reddit;

class Subreddit {
public:
    std::string name;
    unsigned long subs;
    Reddit* reddit;

    Subreddit(Reddit* reddit, std::string name, std::string url);
    Subreddit(Reddit* reddit, std::string name);

    int get_posts(std::string type, unsigned long limit, std::string before, post_cb callback, void *ptr);

    std::vector<Post*> get_posts_list(std::string type, unsigned long limit, std::string after);

    int get_posts_t(std::string type, unsigned long limit, std::string after, post_cb callback, void *ptr);

private:
    std::string url;
};





class Reddit {
public:
    bool authenticated;

    Reddit(std::string username, std::string password, std::string client_id, std::string secret);
    Reddit(std::string username, std::string token);

    struct Headers* get_headers();

    int get_posts_hot(unsigned long limit, std::string before, post_cb callback, void* ptr);

    std::vector<Subreddit*> get_subbed_list();
    std::vector<Post*> get_posts_hot_list(unsigned long limit, std::string after);

    enum {
        AUTHENTICATED = true,
        UNAUTHENTICATED = false
    };

private:
    std::string token;

    int login(std::string username, std::string password, std::string client_id, std::string secret);
    int get_login_status();
};
