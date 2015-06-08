
//  (C) Copyright John Maddock 2015.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_IS_CONSTRUCTIBLE_HPP_INCLUDED
#define BOOST_TT_IS_CONSTRUCTIBLE_HPP_INCLUDED

#include <boost/type_traits/integral_constant.hpp>
#include <boost/detail/workaround.hpp>

#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES) && !defined(BOOST_NO_CXX11_DECLTYPE) && !BOOST_WORKAROUND(BOOST_MSVC, < 1800)

#include <boost/type_traits/detail/yes_no_type.hpp>
#include <boost/type_traits/detail/decl.hpp>

namespace boost{

   namespace detail{

      struct is_constructible_imp
      {
         template<typename T, typename ...TheArgs, typename = decltype(T(tt_declval<TheArgs>()...))>
         static boost::type_traits::yes_type test(int);

         template<typename, typename>
         static boost::type_traits::no_type test(...);
      };

   }

   template <class T, class ...Args> struct is_constructible : public integral_constant<bool, sizeof(detail::is_constructible_imp::test<T, Args...>(0)) == sizeof(boost::type_traits::yes_type)>{};

#else

#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/is_default_constructible.hpp>

namespace boost{

   // We don't know how to implement this:
   template <class T, class U = void> struct is_constructible : public is_convertible<U, T>{};
   template <class T> struct is_constructible<T, void> : public is_default_constructible<T>{};
#endif

} // namespace boost

#endif // BOOST_TT_IS_ASSIGNABLE_HPP_INCLUDED
