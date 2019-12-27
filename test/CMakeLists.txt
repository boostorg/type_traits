# Copyright 2018, 2019 Peter Dimov
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt

include(BoostTestJamfile OPTIONAL RESULT_VARIABLE HAVE_BOOST_TEST)

if(HAVE_BOOST_TEST)

  set(link_libraries Boost::type_traits Boost::core Boost::function Boost::mpl)
  set(compile_definitions CI_SUPPRESS_KNOWN_ISSUES)

  file(GLOB rtests RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*_test*.cpp")

  foreach(test IN LISTS rtests)

    boost_test(TYPE run SOURCES ${test} COMPILE_DEFINITIONS ${compile_definitions} LINK_LIBRARIES ${link_libraries})

  endforeach()

  file(GLOB cftests RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "compile_fail/*.cpp")

  foreach(test IN LISTS cftests)

    boost_test(TYPE compile-fail SOURCES ${test} COMPILE_DEFINITIONS ${compile_definitions} LINK_LIBRARIES ${link_libraries})

  endforeach()

  foreach(test IN ITEMS has_nothrow_assign_test has_nothrow_constr_test has_nothrow_copy_test is_nothrow_move_assignable_test is_nothrow_move_constructible_test)

    boost_test(TYPE run NAME ${test}_no_intrinsics SOURCES ${test}.cpp COMPILE_DEFINITIONS BOOST_TT_DISABLE_INTRINSICS ${compile_definitions} LINK_LIBRARIES ${link_libraries})

  endforeach()

endif()
