
//  (C) Copyright John Maddock 2000. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/type_traits/is_void.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/config.hpp>

template <class T>
BOOST_CONSTEXPR int dispatch_test_imp1(const boost::mpl::bool_<true>&)
{
   return 0;
}
template <class T>
BOOST_CONSTEXPR int dispatch_test_imp1(const boost::mpl::bool_<false>&)
{
   return 1;
}

template <class T>
BOOST_CONSTEXPR int dispatch_test_imp2(boost::mpl::true_)
{
   return 0;
}
template <class T>
BOOST_CONSTEXPR int dispatch_test_imp2(boost::mpl::false_)
{
   return 1;
}

template <class T>
BOOST_CONSTEXPR int dispatch_test()
{
   return dispatch_test_imp1<T>(boost::is_void<T>()) +
          dispatch_test_imp2<T>(boost::is_void<T>());
}


int main()
{
   BOOST_CONSTEXPR bool result = (dispatch_test<int>() == 2) && (dispatch_test<void>() == 0);
   return result ? 0 : 1;
}
