
//  Copyright (c) 2014 Agustin Berge
//
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "test.hpp"
#include "check_integral_constant.hpp"
#ifdef TEST_STD
#  include <type_traits>
#else
#  include <boost/type_traits/is_final.hpp>
#endif
#include <iostream>

TT_TEST_BEGIN(is_final)

   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<int>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<const int>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<volatile int>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<int*>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<int* const>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<int[2]>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<int&>::value, false);
#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<int&&>::value, false);
#endif
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<mf4>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<f1>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<enum_UDT>::value, false);

#if defined(BOOST_HAS_TYPE_TRAITS_INTRINSICS)
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<final_UDT>::value, true);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<final_UDT const>::value, true);
#else
   std::cout <<
   "\n<note>\n"
   "This compiler version does not provide support for is_final on\n"
   "final types.n"
   "</note>\n";
#endif

   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<UDT>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<UDT const>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<UDT volatile>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<empty_UDT>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<std::iostream>::value, false);

   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<UDT*>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<UDT[2]>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<UDT&>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<void>::value, false);

   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<test_abc1>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<foo0_t>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<foo1_t>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<foo2_t>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<foo3_t>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<foo4_t>::value, false);
   BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_final<incomplete_type>::value, false);

TT_TEST_END









