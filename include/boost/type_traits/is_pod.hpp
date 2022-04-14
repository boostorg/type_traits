
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_IS_POD_HPP_INCLUDED
#define BOOST_TT_IS_POD_HPP_INCLUDED

#ifndef BOOST_TYPE_TRAITS_AS_MODULE
#include <cstddef> // size_t
#endif
#include <boost/type_traits/detail/config.hpp>
#include <boost/type_traits/is_void.hpp>
#include <boost/type_traits/is_scalar.hpp>
#include <boost/type_traits/intrinsics.hpp>

#ifdef __SUNPRO_CC
#include <boost/type_traits/is_function.hpp>
#endif

#ifndef BOOST_IS_POD
#define BOOST_INTERNAL_IS_POD(T) false
#else
#define BOOST_INTERNAL_IS_POD(T) BOOST_IS_POD(T)
#endif

namespace boost {

// forward declaration, needed by 'is_pod_array_helper' template below
BOOST_TYPE_TRAITS_MODULE_EXPORT template< typename T > struct is_POD;

BOOST_TYPE_TRAITS_MODULE_EXPORT template <typename T> struct is_pod
: public integral_constant<bool, ::boost::is_scalar<T>::value || ::boost::is_void<T>::value || BOOST_INTERNAL_IS_POD(T)>
{};

#if !defined(BOOST_NO_ARRAY_TYPE_SPECIALIZATIONS)
BOOST_TYPE_TRAITS_MODULE_EXPORT template <typename T, std::size_t sz> struct is_pod<T[sz]> : public is_pod<T>{};
#endif


// the following help compilers without partial specialization support:
BOOST_TYPE_TRAITS_MODULE_EXPORT template<> struct is_pod<void> : public true_type{};

#ifndef BOOST_NO_CV_VOID_SPECIALIZATIONS
BOOST_TYPE_TRAITS_MODULE_EXPORT template<> struct is_pod<void const> : public true_type{};
BOOST_TYPE_TRAITS_MODULE_EXPORT template<> struct is_pod<void const volatile> : public true_type{};
BOOST_TYPE_TRAITS_MODULE_EXPORT template<> struct is_pod<void volatile> : public true_type{};
#endif

BOOST_TYPE_TRAITS_MODULE_EXPORT template<class T> struct is_POD : public is_pod<T>{};

} // namespace boost

#undef BOOST_INTERNAL_IS_POD

#endif // BOOST_TT_IS_POD_HPP_INCLUDED
