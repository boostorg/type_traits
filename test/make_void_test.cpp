/*
Copyright 2017 Glen Joseph Fernandes
<glenjofe -at- gmail.com>

Distributed under the Boost Software License,
Version 1.0. (See accompanying file LICENSE_1_0.txt
or copy at http://www.boost.org/LICENSE_1_0.txt)
*/

#include "test.hpp"
#include "check_type.hpp"

#ifdef TEST_STD
#include <type_traits>
#else
#include <boost/type_traits/make_void.hpp>
#endif

TT_TEST_BEGIN(make_void)

BOOST_CHECK_TYPE(::tt::make_void<int>::type, void);
BOOST_CHECK_TYPE(::tt::make_void<const volatile int>::type, void);
BOOST_CHECK_TYPE(::tt::make_void<int&>::type, void);
BOOST_CHECK_TYPE(::tt::make_void<void>::type, void);
BOOST_CHECK_TYPE(::tt::make_void<int(*)(int)>::type, void);
BOOST_CHECK_TYPE(::tt::make_void<int[]>::type, void);
BOOST_CHECK_TYPE(::tt::make_void<int[1]>::type, void);

#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
BOOST_CHECK_TYPE(::tt::make_void<>::type, void);
BOOST_CHECK_TYPE3(::tt::make_void<int, int>::type, void);
#endif

TT_TEST_END
