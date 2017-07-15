#ifndef BOOST_TYPE_TRAITS_IS_NOTHROW_SWAPPABLE_HPP_INCLUDED
#define BOOST_TYPE_TRAITS_IS_NOTHROW_SWAPPABLE_HPP_INCLUDED

//  Copyright 2017 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

#include <boost/config.hpp>

#if defined(BOOST_NO_SFINAE_EXPR) || defined(BOOST_NO_CXX11_NOEXCEPT) || defined(BOOST_NO_CXX11_DECLTYPE) || defined(BOOST_NO_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGS)
#else

#include <boost/type_traits/declval.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <algorithm>

namespace boost
{

namespace type_traits_swappable_detail
{

using std::swap;

template<class T, class U, bool B = noexcept(swap(declval<T>(), declval<U>()))> integral_constant<bool, B> is_nothrow_swappable_with_impl( int );
template<class T, class U> false_type is_nothrow_swappable_with_impl( ... );

template<class T, bool B = noexcept(swap(declval<T&>(), declval<T&>()))> integral_constant<bool, B> is_nothrow_swappable_impl( int );
template<class T> false_type is_nothrow_swappable_impl( ... );

} // namespace type_traits_swappable_detail

template<class T, class U> struct is_nothrow_swappable_with: decltype( type_traits_swappable_detail::is_nothrow_swappable_with_impl<T, U>(0) )
{
};

template<class T> struct is_nothrow_swappable: decltype( type_traits_swappable_detail::is_nothrow_swappable_impl<T>(0) )
{
};

} // namespace boost

#endif

#endif // #ifndef BOOST_TYPE_TRAITS_IS_NOTHROW_SWAPPABLE_HPP_INCLUDED
