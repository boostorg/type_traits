
//  (C) Copyright John Maddock 2015.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_DETAIL_DECL_HEADER
#define BOOST_TT_DETAIL_DECL_HEADER

#include <boost/config.hpp>
#include <boost/type_traits/add_rvalue_reference.hpp>
#include <boost/type_traits/add_lvalue_reference.hpp>
#include <boost/type_traits/remove_reference.hpp>

namespace boost { namespace detail{

template <typename T>
typename add_rvalue_reference<T>::type tt_declval() BOOST_NOEXCEPT; // as unevaluated operand
template <typename T>
typename add_lvalue_reference<typename remove_reference<T>::type const>::type tt_decl_const_ref() BOOST_NOEXCEPT; // as unevaluated operand
template <typename T>
typename add_lvalue_reference<typename remove_reference<T>::type>::type tt_decl_ref() BOOST_NOEXCEPT; // as unevaluated operand


}} // namespace boost

#endif // BOOST_TT_DETAIL_DECL_HEADER
