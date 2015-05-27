//  common_type.hpp  ---------------------------------------------------------//

//  Copyright 2008 Howard Hinnant
//  Copyright 2008 Beman Dawes

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef BOOST_TYPE_TRAITS_COMMON_TYPE_HPP
#define BOOST_TYPE_TRAITS_COMMON_TYPE_HPP

#include <boost/config.hpp>
#include <boost/static_assert.hpp>

#if defined(__SUNPRO_CC) && !defined(BOOST_COMMON_TYPE_DONT_USE_TYPEOF)
#  define BOOST_COMMON_TYPE_DONT_USE_TYPEOF
#endif
#if defined(__IBMCPP__) && !defined(BOOST_COMMON_TYPE_DONT_USE_TYPEOF)
#  define BOOST_COMMON_TYPE_DONT_USE_TYPEOF
#endif

#ifdef __GNUC__
// All supported GCC versions (and emulations thereof) support __typeof__
#define BOOST_COMMON_TYPE_USE_TYPEOF
#endif

//----------------------------------------------------------------------------//
#if defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES) && !defined(BOOST_COMMON_TYPE_ARITY)
#define BOOST_COMMON_TYPE_ARITY 3
#endif

//----------------------------------------------------------------------------//
#if !defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/utility/declval.hpp>
#elif defined(BOOST_COMMON_TYPE_USE_TYPEOF)
#include <boost/type_traits/add_rvalue_reference.hpp>
#elif defined(BOOST_COMMON_TYPE_DONT_USE_TYPEOF)
#include <boost/type_traits/remove_cv.hpp>
#include <boost/type_traits/detail/common_type_imp.hpp>
#else
#include <boost/typeof/typeof.hpp>   // boost wonders never cease!
#include <boost/type_traits/detail/common_type_imp.hpp>
#include <boost/type_traits/add_rvalue_reference.hpp>
#endif

#include <boost/type_traits/remove_cv.hpp>
#include <boost/type_traits/decay.hpp>

//----------------------------------------------------------------------------//
//                                                                            //
//                           C++03 implementation of                          //
//             20.9.7.6 Other transformations [meta.trans.other]              //
//                          Written by Howard Hinnant                         //
//      Adapted for Boost by Beman Dawes, Vicente Botet and  Jeffrey Hellrung //
//                                                                            //
//----------------------------------------------------------------------------//

namespace boost {

    namespace type_traits_detail {

        template <class T>
        struct std_decay: boost::remove_cv<
            typename boost::decay<T>::type> {};

    }

// prototype
#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
    template<typename... T>
    struct common_type;
#else // or no specialization
    template <class T, class U = void, class V = void>
    struct common_type
    {
    public:
        typedef typename common_type<typename common_type<T, U>::type, V>::type type;
    };
#endif


// 1 arg
    template<typename T>
#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
    struct common_type<T>
#else
    struct common_type<T, void, void>

#endif
    {
        BOOST_STATIC_ASSERT_MSG(sizeof(T) > 0, "The template arguments to common_type must be complete types");
    public:
        typedef typename type_traits_detail::std_decay<T>::type type;
    };

// 2 args
namespace type_traits_detail {

    template <class T, class U>
    struct common_type_2
    {
    private:
        BOOST_STATIC_ASSERT_MSG(sizeof(T) > 0, "The template arguments to common_type must be complete types");
        BOOST_STATIC_ASSERT_MSG(sizeof(U) > 0, "The template arguments to common_type must be complete types");

#if !defined(BOOST_NO_CXX11_DECLTYPE)
    public:
        typedef typename std_decay<decltype(declval<bool>() ? declval<T>() : declval<U>())>::type type;
#elif defined(BOOST_COMMON_TYPE_USE_TYPEOF)
        static typename add_rvalue_reference<T>::type declval_T();  // workaround gcc bug; not required by std
        static typename add_rvalue_reference<U>::type declval_U();  // workaround gcc bug; not required by std
        static typename add_rvalue_reference<bool>::type declval_b();  
    public:
        typedef typename std_decay<__typeof__(declval_b() ? declval_T() : declval_U())>::type type;
#elif defined(BOOST_COMMON_TYPE_DONT_USE_TYPEOF)
    public:
    typedef typename detail_type_traits_common_type::common_type_impl<
          typename remove_cv<T>::type,
          typename remove_cv<U>::type
      >::type type;
#else
        static typename add_rvalue_reference<T>::type declval_T();  // workaround gcc bug; not required by std
        static typename add_rvalue_reference<U>::type declval_U();  // workaround gcc bug; not required by std
        static typename add_rvalue_reference<bool>::type declval_b();
    public:
        typedef typename std_decay<BOOST_TYPEOF_TPL(declval_b() ? declval_T() : declval_U())>::type type;
#endif

#if defined(__GNUC__) && __GNUC__ == 3 && __GNUC_MINOR__ == 3
    public:
        void public_dummy_function_just_to_silence_warning();
#endif
    };

    template <class T>
    struct common_type_2<T, T>
    {
        typedef typename type_traits_detail::std_decay<T>::type type;
    };
    }

#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
    template <class T, class U>
    struct common_type<T, U>
#else
    template <class T, class U>
    struct common_type<T, U, void>
#endif
    : public type_traits_detail::common_type_2<T,U>
    { };


// 3 or more args
#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
    template<typename T, typename U, typename... V>
    struct common_type<T, U, V...> {
    public:
        typedef typename common_type<typename common_type<T, U>::type, V...>::type type;
    };
#endif
}  // namespace boost

#endif  // BOOST_TYPE_TRAITS_COMMON_TYPE_HPP
