
//  Copyright 2017 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

#ifdef TEST_STD
#  include <type_traits>
#else
#  include <boost/type_traits/is_nothrow_swappable.hpp>
#endif

#include <boost/config.hpp>

#if defined(BOOST_NO_SFINAE_EXPR) || defined(BOOST_NO_CXX11_NOEXCEPT) || defined(BOOST_NO_CXX11_DECLTYPE) || defined(BOOST_NO_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGS)

int main()
{
}

#else

#include "test.hpp"
#include "check_integral_constant.hpp"
#include <utility>

struct X
{
};

struct Y
{
    Y( Y const& ) {}
};

struct Z
{
    Z& operator=( Z const& ) { return *this; }
};

struct V
{
    V( V const& ) {}
    V& operator=( V const& ) { return *this; }
};

void swap( V&, V& ) noexcept {}

TT_TEST_BEGIN(is_nothrow_swappable)

BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<int>::value, true);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<int const>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<int volatile>::value, true);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<int const volatile>::value, false);

BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<int[2]>::value, true);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<int const[2]>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<int volatile[2]>::value, true);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<int const volatile[2]>::value, false);

BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<void>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<void const>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<void volatile>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<void const volatile>::value, false);

BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<X>::value, true);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<X const>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<X volatile>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<X const volatile>::value, false);

BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<X[2]>::value, true);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<X const[2]>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<X volatile[2]>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<X const volatile[2]>::value, false);

BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<Y>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<Y const>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<Y volatile>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<Y const volatile>::value, false);

BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<Y[2]>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<Y const[2]>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<Y volatile[2]>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<Y const volatile[2]>::value, false);

BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<Z>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<Z const>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<Z volatile>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<Z const volatile>::value, false);

BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<Z[2]>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<Z const[2]>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<Z volatile[2]>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<Z const volatile[2]>::value, false);

BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<V>::value, true);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<V const>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<V volatile>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<V const volatile>::value, false);

BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<V[2]>::value, true);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<V const[2]>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<V volatile[2]>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_swappable<V const volatile[2]>::value, false);

BOOST_CHECK_INTEGRAL_CONSTANT((::tt::is_nothrow_swappable<std::pair<X, int> >::value), true);
BOOST_CHECK_INTEGRAL_CONSTANT((::tt::is_nothrow_swappable<std::pair<X, int> const>::value), false);
BOOST_CHECK_INTEGRAL_CONSTANT((::tt::is_nothrow_swappable<std::pair<X, int> volatile>::value), false);
BOOST_CHECK_INTEGRAL_CONSTANT((::tt::is_nothrow_swappable<std::pair<X, int> const volatile>::value), false);

BOOST_CHECK_INTEGRAL_CONSTANT((::tt::is_nothrow_swappable<std::pair<Y, int> >::value), false);
BOOST_CHECK_INTEGRAL_CONSTANT((::tt::is_nothrow_swappable<std::pair<Y, int> const>::value), false);
BOOST_CHECK_INTEGRAL_CONSTANT((::tt::is_nothrow_swappable<std::pair<Y, int> volatile>::value), false);
BOOST_CHECK_INTEGRAL_CONSTANT((::tt::is_nothrow_swappable<std::pair<Y, int> const volatile>::value), false);

BOOST_CHECK_INTEGRAL_CONSTANT((::tt::is_nothrow_swappable<std::pair<V, int> >::value), true);
BOOST_CHECK_INTEGRAL_CONSTANT((::tt::is_nothrow_swappable<std::pair<V, int> const>::value), false);
BOOST_CHECK_INTEGRAL_CONSTANT((::tt::is_nothrow_swappable<std::pair<V, int> volatile>::value), false);
BOOST_CHECK_INTEGRAL_CONSTANT((::tt::is_nothrow_swappable<std::pair<V, int> const volatile>::value), false);

TT_TEST_END

#endif
