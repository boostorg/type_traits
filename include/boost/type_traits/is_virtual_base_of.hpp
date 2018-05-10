//  (C) Copyright Daniel Frey and Robert Ramey 2009.
//  (C) Copyright Balint Cserni 2017
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.
 
#ifndef BOOST_TT_IS_VIRTUAL_BASE_OF_HPP_INCLUDED
#define BOOST_TT_IS_VIRTUAL_BASE_OF_HPP_INCLUDED

#include <boost/type_traits/is_base_of.hpp>

namespace boost {
namespace detail {


#ifdef BOOST_MSVC
#pragma warning( push )
#pragma warning( disable : 4584 4250 4594)
#elif defined(__GNUC__) && (__GNUC__ >= 4)
#pragma GCC system_header
#endif

template<class Base, class Derived>
struct is_virtual_base_of_impl
{
	template<class From, class To>
	struct can_cast
	{
		typedef char YES;
		typedef struct { char x[2]; } NO;

		// C-style casts have the power to ignore inheritance visibility while still act as a static_cast.
		// They can also fall back to the behaviour of reinterpret_cast, which allows is_virtual_base_of to work on non-class types too.
		// Note that because we are casting pointers there can be no user-defined operators to interfere.
		template<unsigned = sizeof((To*)((From*)(0)))> static YES test(int*);
		static NO test(...);

		BOOST_STATIC_CONSTANT(bool, value = (sizeof(test(nullptr)) == sizeof(YES)));
	};

	// Implementation based on the standard's rules of explicit type conversions.
	// A pointer to an object of *derived* class type may be explicitly converted to a pointer to an *unambiguous* *base* class type.
	// A pointer to an object of an *unambiguous* *non-virtual* *base* class type may be explicitly converted to a pointer of a *derived* class type.
	// Therefore Derived has a virtual base Base if and only if
	//   (1) a Derived* can be converted to Base* (so the base class is unambiguous, which comes necessarily from virtual inheritance)
	//   (2) a Base* cannot be converted to Derived* (so the base class is either ambiguous or virtual)
	// With both conditions true, Base must be a virtual base of Derived.
	// The "is_base_of" is only needed so the compiler can (but is not required to) error out if the types are incomplete.
	// This is in league with the the expected behaviour.
	BOOST_STATIC_CONSTANT(bool, value = (boost::is_base_of<Base, Derived>::value && can_cast<Derived, Base>::value && !can_cast<Base, Derived>::value));
};

#ifdef BOOST_MSVC
#pragma warning( pop )
#endif

} // namespace detail

template <class Base, class Derived> struct is_virtual_base_of : public integral_constant<bool, (::boost::detail::is_virtual_base_of_impl<Base, Derived>::value)>{};

template <class Base, class Derived> struct is_virtual_base_of<Base&, Derived> : public false_type{};
template <class Base, class Derived> struct is_virtual_base_of<Base, Derived&> : public false_type{};
template <class Base, class Derived> struct is_virtual_base_of<Base&, Derived&> : public false_type{};

} // namespace boost

#endif
