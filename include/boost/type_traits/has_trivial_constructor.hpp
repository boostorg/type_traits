
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_HAS_TRIVIAL_CONSTRUCTOR_HPP_INCLUDED
#define BOOST_TT_HAS_TRIVIAL_CONSTRUCTOR_HPP_INCLUDED

#include <boost/type_traits/intrinsics.hpp>
#include <boost/type_traits/is_pod.hpp>

#ifdef BOOST_HAS_TRIVIAL_CONSTRUCTOR
#ifdef BOOST_HAS_SGI_TYPE_TRAITS
#include <boost/type_traits/is_same.hpp>
#elif defined(__GNUC__)
#include <boost/type_traits/is_volatile.hpp>
#ifdef BOOST_INTEL
#include <boost/type_traits/is_pod.hpp>
#endif
#endif
#endif

namespace boost {

template <typename T> struct has_trivial_constructor
#ifdef BOOST_HAS_TRIVIAL_CONSTRUCTOR
   : public integral_constant <bool, (::boost::is_pod<T>::value || BOOST_HAS_TRIVIAL_CONSTRUCTOR(T))>{};
#else
   : public integral_constant <bool, ::boost::is_pod<T>::value>{};
#endif

template <class T> struct has_trivial_default_constructor : public has_trivial_constructor<T> {};

} // namespace boost

#endif // BOOST_TT_HAS_TRIVIAL_CONSTRUCTOR_HPP_INCLUDED
