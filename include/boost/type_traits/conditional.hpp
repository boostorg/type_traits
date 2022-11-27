//  (C) Copyright John Maddock 2010.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.


#ifndef BOOST_TT_CONDITIONAL_HPP_INCLUDED
#define BOOST_TT_CONDITIONAL_HPP_INCLUDED

#include <boost/type_traits/detail/config.hpp>

namespace boost {

BOOST_TYPE_TRAITS_MODULE_EXPORT template <bool b, class T, class U> struct conditional { typedef T type; };
BOOST_TYPE_TRAITS_MODULE_EXPORT template <class T, class U> struct conditional<false, T, U> { typedef U type; };

#if !defined(BOOST_NO_CXX11_TEMPLATE_ALIASES)

BOOST_TYPE_TRAITS_MODULE_EXPORT template <bool b, class T, class U> using conditional_t = typename conditional<b, T, U>::type;

#endif

} // namespace boost


#endif // BOOST_TT_CONDITIONAL_HPP_INCLUDED
