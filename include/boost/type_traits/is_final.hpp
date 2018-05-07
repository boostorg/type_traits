
//  Copyright (c) 2014 Agustin Berge
//
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.


#ifndef BOOST_TT_IS_FINAL_HPP_INCLUDED
#define BOOST_TT_IS_FINAL_HPP_INCLUDED

#include <boost/type_traits/intrinsics.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace boost {

#ifdef BOOST_IS_FINAL
// Note: gcc 6.4 and 7.2 break for some template types if we use remove_cv here
template <class T> struct is_final : public integral_constant<bool, BOOST_IS_FINAL(T)> {};
template <class T> struct is_final< const T > : public integral_constant<bool, BOOST_IS_FINAL(T)> {};
template <class T> struct is_final< volatile T > : public integral_constant<bool, BOOST_IS_FINAL(T)> {};
template <class T> struct is_final< const volatile T > : public integral_constant<bool, BOOST_IS_FINAL(T)> {};
#else
template <class T> struct is_final : public integral_constant<bool, false> {};
#endif

} // namespace boost

#endif // BOOST_TT_IS_FINAL_HPP_INCLUDED
