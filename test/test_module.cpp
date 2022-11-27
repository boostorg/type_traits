//  (C) John Maddock 2022.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#include <complex>

import boost.type_traits;

template<class T>
using type_t = typename T::type;

struct has_type {
   using type = char;
};


int main()
{
   {
      using t1 = boost::add_const_t<int>;
      static_assert(boost::is_same<t1, const int>::value);
   }
   {
      using t1 = boost::add_cv_t<int>;
      static_assert(boost::is_same<t1, const volatile int>::value);
   }
   {
      using t1 = boost::add_reference_t<int>;
      static_assert(boost::is_same<t1, int&>::value);
   }
   {
      using t1 = boost::add_lvalue_reference_t<int>;
      static_assert(boost::is_same<t1, int&>::value);
   }
   {
      using t1 = boost::add_pointer_t<int>;
      static_assert(boost::is_same<t1, int*>::value);
   }
   {
      using t1 = boost::add_rvalue_reference_t<int>;
      static_assert(boost::is_same<t1, int&&>::value);
   }
   {
      using t1 = boost::add_volatile_t<int>;
      static_assert(boost::is_same<t1, volatile int>::value);
   }
   {
      using t1 = boost::common_type<int, long>::type;
      static_assert(boost::is_same<t1, long>::value);
   }
   {
      using t1 = boost::conditional<true, long, int>::type;
      static_assert(boost::is_same<t1, long>::value);
   }
   {
      using t1 = boost::conjunction<boost::true_type, boost::false_type>::type;
      static_assert(boost::is_same<t1, boost::false_type>::value);
   }
   {
      using t1 = boost::copy_cv<int, const long>::type;
      static_assert(boost::is_same<t1, const int>::value);
   }
   {
      using t1 = boost::copy_cv<int&, const char&>::type;
      static_assert(boost::is_same<t1, int&>::value);
   }
   {
      using t1 = boost::copy_cv<int, const char&>::type;
      static_assert(boost::is_same<t1, int>::value);
   }
   {
      using t1 = boost::decay<int[2]>::type;
      static_assert(boost::is_same<t1, int*>::value);
   }
   {
      static_assert(boost::is_same<boost::detected_t<type_t, has_type>, char>::value);
   }
   {
      static_assert(boost::detected_or<bool, type_t, has_type>::value_t::value);
   }
   {
      using t1 = boost::disjunction<boost::true_type, boost::false_type>::type;
      static_assert(boost::is_same<t1, boost::true_type>::value);
   }
   {
      static_assert(boost::extent<int[3]>::value == 3);
   }
   {
      using t1 = boost::floating_point_promotion<const float>::type;
      static_assert(boost::is_same<t1, const double>::value);
   }
   {
      typedef int(t1)(int, int);
      static_assert(boost::function_traits<t1>::arity == 2);
   }
   {
      static_assert(boost::has_bit_and<int>::value);
      static_assert(boost::has_bit_and_assign<int>::value);
      static_assert(boost::has_bit_or<int>::value);
      static_assert(boost::has_bit_or_assign<int>::value);
      static_assert(boost::has_bit_xor<int>::value);
      static_assert(boost::has_bit_xor_assign<int>::value);
      static_assert(boost::has_complement<int>::value);
      static_assert(boost::has_dereference<int*>::value);
      static_assert(!boost::has_dereference<int>::value);
      static_assert(boost::has_divides<int>::value);
      static_assert(boost::has_divides_assign<int>::value);
      static_assert(boost::has_equal_to<int>::value);
      static_assert(boost::has_greater<int>::value);
      static_assert(boost::has_greater_equal<int>::value);
      static_assert(boost::has_left_shift<int>::value);
      static_assert(boost::has_left_shift_assign<int>::value);
      static_assert(boost::has_less<int>::value);
      static_assert(boost::has_less_equal<int>::value);
      static_assert(boost::has_logical_and<int>::value);
      static_assert(boost::has_logical_or<int>::value);
      static_assert(boost::has_logical_not<int>::value);
      static_assert(boost::has_minus<int>::value);
      static_assert(boost::has_minus_assign<int>::value);
      static_assert(boost::has_modulus<int>::value);
      static_assert(boost::has_modulus_assign<int>::value);
      static_assert(boost::has_multiplies<int>::value);
      static_assert(boost::has_multiplies_assign<int>::value);
      static_assert(boost::has_negate<int>::value);
      static_assert(!boost::has_new_operator<int>::value);
      static_assert(boost::has_not_equal_to<int>::value);
      static_assert(boost::has_nothrow_assign<int>::value);
      static_assert(boost::has_nothrow_constructor<int>::value);
      static_assert(boost::has_nothrow_copy_constructor<int>::value);
      static_assert(boost::has_nothrow_destructor<int>::value);
      static_assert(boost::has_plus<int>::value);
      static_assert(boost::has_plus_assign<int>::value);
      static_assert(boost::has_post_increment<int>::value);
      static_assert(boost::has_post_decrement<int>::value);
      static_assert(boost::has_pre_increment<int>::value);
      static_assert(boost::has_pre_decrement<int>::value);
      static_assert(boost::has_right_shift<int>::value);
      static_assert(boost::has_right_shift_assign<int>::value);
      static_assert(boost::has_trivial_assign<int>::value);
      static_assert(boost::has_trivial_constructor<int>::value);
      static_assert(boost::has_trivial_copy<int>::value);
      static_assert(boost::has_trivial_destructor<int>::value);
      static_assert(boost::has_trivial_move_assign<int>::value);
      static_assert(boost::has_trivial_move_constructor<int>::value);
      static_assert(boost::has_unary_plus<int>::value);
      static_assert(boost::has_unary_minus<int>::value);
      static_assert(!boost::has_virtual_destructor<int>::value);
      
      static_assert(!boost::is_abstract<int>::value);
      static_assert(boost::is_arithmetic<int>::value);
      static_assert(!boost::is_array<int>::value);
      static_assert(boost::is_assignable<int&>::value);
      static_assert(!boost::is_base_of<int, double>::value);
      static_assert(!boost::is_base_and_derived<int, double>::value);
      static_assert(!boost::is_bounded_array<int[]>::value);
      static_assert(boost::is_bounded_array<int[2]>::value);
      static_assert(boost::is_complete<int>::value);
      static_assert(boost::is_complex<std::complex<double>>::value);
      static_assert(!boost::is_compound<int>::value);
      static_assert(!boost::is_const<int>::value);
      static_assert(boost::is_const<const int>::value);
      static_assert(boost::is_convertible<int, double>::value);
      static_assert(boost::is_constructible<int, double>::value);
      static_assert(boost::is_copy_assignable<int>::value);
      static_assert(boost::is_copy_constructible<int>::value);
      static_assert(!boost::is_class<int>::value);
      static_assert(boost::is_class<std::complex<double>>::value);
      static_assert(boost::is_default_constructible<int>::value);
      static_assert(boost::is_destructible<int>::value);
      static_assert(!boost::is_detected<type_t, int>::value);
      static_assert(boost::is_detected<type_t, has_type>::value);
      static_assert(boost::is_detected_convertible<int, type_t, has_type>::value);
      static_assert(boost::is_detected_exact<char, type_t, has_type>::value);
      static_assert(!boost::is_empty<std::complex<double>>::value);
      static_assert(!boost::is_enum<int>::value);
      static_assert(!boost::is_final<std::complex<double>>::value);
      static_assert(boost::is_float<double>::value);
      static_assert(boost::is_floating_point<double>::value);
      static_assert(boost::is_function<double(int)>::value);
      static_assert(boost::is_fundamental<int>::value);
      static_assert(boost::is_integral<int>::value);
      static_assert(boost::is_list_constructible<int[2]>::value);
      static_assert(boost::is_lvalue_reference<int&>::value);
      static_assert(boost::is_member_function_pointer<double (std::complex<double>::*)()>::value);
      static_assert(!boost::is_member_object_pointer<double (std::complex<double>::*)()>::value);
      static_assert(boost::is_member_pointer<double (std::complex<double>::*)()>::value);
      static_assert(!boost::is_noncopyable<std::complex<double>>::value);
      static_assert(boost::is_nothrow_move_assignable<int>::value);
      static_assert(boost::is_nothrow_move_constructible<int>::value);
      static_assert(boost::is_nothrow_swappable<int>::value);
      static_assert(boost::is_object<int>::value);
      static_assert(boost::is_pod<int>::value);
      static_assert(!boost::is_polymorphic<int>::value);
      static_assert(boost::is_reference<int&>::value);
      static_assert(boost::is_rvalue_reference<int&&>::value);
      static_assert(boost::is_same<int, int>::value);
      static_assert(!boost::is_scoped_enum<int>::value);
      static_assert(boost::is_scalar<int>::value);
      static_assert(boost::is_signed<int>::value);
      static_assert(!boost::is_stateless<int>::value);
      static_assert(boost::is_trivially_copyable<int>::value);
      static_assert(boost::is_unbounded_array<int[]>::value);
      static_assert(!boost::is_union<int>::value);
      static_assert(!boost::is_unscoped_enum<int>::value);
      static_assert(boost::is_unsigned<unsigned int>::value);
      static_assert(!boost::is_virtual_base_of<std::complex<float>, std::complex<double>>::value);
      static_assert(boost::is_void<void const>::value);
      static_assert(boost::is_volatile<volatile int>::value);
      static_assert(boost::is_same<boost::make_signed_t<unsigned int>, int>::value);
      static_assert(boost::is_same<boost::make_unsigned_t<int>, unsigned>::value);
      static_assert(boost::negation<boost::is_void<int>>::value);
      static_assert(boost::is_same<boost::promote_t<short>, int>::value);
      static_assert(boost::rank<int[2][3]>::value == 2);
      static_assert(boost::is_same<boost::remove_all_extents_t<int[2][3]>, int>::value);
      static_assert(boost::is_same<boost::remove_bounds_t<int[2][3]>, int[3]>::value);
      static_assert(boost::is_same<boost::remove_const_t<int const>, int>::value);
      static_assert(boost::is_same<boost::remove_cv_t<int const>, int>::value);
      static_assert(boost::is_same<boost::remove_cv_ref_t<int const&>, int>::value);
      static_assert(boost::is_same<boost::remove_extent_t<int[2][3]>, int[3]>::value);
      static_assert(boost::is_same<boost::remove_pointer_t<int**>, int*>::value);
      static_assert(boost::is_same<boost::remove_reference_t<int&>, int>::value);
      static_assert(boost::is_same<boost::remove_volatile_t<int const volatile>, int const>::value);
      static_assert(boost::is_same<boost::type_identity_t<int>, int>::value);
      static_assert(boost::alignment_of<boost::type_with_alignment<16>::type>::value == 16);
   }
   
   {
      using t1 = boost::remove_reference_t<int&>;
      static_assert(boost::is_same<t1, int>::value);
   }
   {
      using t1 = boost::aligned_storage<8>::type;
      using t2 = boost::aligned_storage<64>::type;
   }
   {
      using t1 = boost::type_with_alignment<8>::type;
      using t2 = boost::type_with_alignment<64>::type;
   }
}

