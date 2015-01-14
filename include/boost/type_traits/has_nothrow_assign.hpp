
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_HAS_NOTHROW_ASSIGN_HPP_INCLUDED
#define BOOST_TT_HAS_NOTHROW_ASSIGN_HPP_INCLUDED

#include <boost/type_traits/integral_constant.hpp>
#include <boost/type_traits/intrinsics.hpp>

#if !defined(BOOST_HAS_NOTHROW_ASSIGN) || defined(BOOST_MSVC) || defined(BOOST_INTEL)
#include <boost/type_traits/has_trivial_assign.hpp>
#endif
#if defined(__GNUC__)
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/is_volatile.hpp>
#endif

namespace boost {

template <class T>
struct has_nothrow_assign : public integral_constant<bool,
#ifndef BOOST_HAS_NOTHROW_ASSIGN
   ::boost::has_trivial_assign<T>::value
#else
   BOOST_HAS_NOTHROW_ASSIGN(T)
#endif
>{};

template <> struct has_nothrow_assign<void> : public false_type{};
#ifndef BOOST_NO_CV_VOID_SPECIALIZATIONS
template <> struct has_nothrow_assign<void const> : public false_type{};
template <> struct has_nothrow_assign<void const volatile> : public false_type{};
template <> struct has_nothrow_assign<void volatile> : public false_type{};
#endif

} // namespace boost

#endif // BOOST_TT_HAS_NOTHROW_ASSIGN_HPP_INCLUDED
