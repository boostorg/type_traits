
//  (C) Copyright John Maddock 2017. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#  include <boost/type_traits/is_convertible.hpp>
#include "../test.hpp"

#if defined(CI_SUPPRESS_KNOWN_ISSUES) && defined(BOOST_MSVC) && (BOOST_MSVC <= 1800)
#error "Sorry check doesn't work"
#endif

int main()
{
   return boost::is_convertible<incomplete_type, UDT>::value;
}


