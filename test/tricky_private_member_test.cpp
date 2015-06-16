
//  (C) Copyright John Maddock 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "test.hpp"
#include "check_integral_constant.hpp"
#ifdef TEST_STD
#  include <type_traits>
#else
#  include <boost/type_traits.hpp>
#endif

struct private_default_construct
{
private:
   private_default_construct();
public:
   private_default_construct(char val) : member(val) {}
   char member;
};

struct non_copy
{
   non_copy();
private:
   non_copy(const non_copy&);
};

struct non_assignable
{
   non_assignable();
private:
   non_assignable& operator=(const non_assignable&);
};

struct private_copy
{
   private_copy();
private:
   private_copy(const private_copy&);
};

struct private_destruct
{
   private_destruct();
private:
   ~private_destruct();
};



TT_TEST_BEGIN(tricky_private_members_test)

BOOST_CHECK_INTEGRAL_CONSTANT(::tt::has_nothrow_constructor<private_default_construct>::value, false);
#if !defined(BOOST_NO_CXX11_DECLTYPE) && !BOOST_WORKAROUND(BOOST_MSVC, < 1800)
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::has_nothrow_copy<non_copy>::value, false);
#endif
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::has_trivial_assign<non_assignable>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::has_trivial_constructor<private_default_construct>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::has_trivial_copy<private_copy>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::has_trivial_destructor<private_destruct>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_default_constructible<private_default_construct>::value, false);
BOOST_CHECK_INTEGRAL_CONSTANT(::tt::is_nothrow_move_constructible<non_copy>::value, false);



TT_TEST_END


