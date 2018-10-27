#include <iostream>
#include <type_traits>

/**
 * Write an unary metafunction that returns T if it is 
 * a reference type and otherwise returns T const&
 */

using namespace std;

template <bool b, typename T> struct ref_type;

template <typename T>
struct add_const_ref {
    
  typedef typename ref_type<is_reference<T>::value, T>::type type;
};
  
template <typename T>
struct ref_type<true, T> {
    
  typedef T type;
};

template <typename T>
struct ref_type<false, T> {
    
  typedef add_lvalue_reference<add_const<T>> type;
};

template <typename T>
struct is_working {

  static const bool value = is_same<T, add_const_ref<T>>::value;
};

template <typename T>
struct is_sane {

  static const bool value = is_same<T, T>::value;
};

