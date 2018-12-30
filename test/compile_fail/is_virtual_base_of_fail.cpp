
//  (C) Copyright John Maddock 2017. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#  include <boost/type_traits/is_virtual_base_of.hpp>
#include "../test.hpp"

#if BOOST_WORKAROUND(__ICC, < 1700) && defined(CI_SUPPRESS_KNOWN_ISSUES)
#  error "Unsupport test"
#endif

int main()
{
   return boost::is_virtual_base_of<UDT, incomplete_type>::value;
}


