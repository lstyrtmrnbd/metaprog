#include <iostream>
#include <type_traits>

using namespace std;

/**
 * 2-0
 * Write an unary metafunction that returns T if it is 
 * a reference type and otherwise returns T const&
 */

namespace zero {
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

    static const bool value = is_same<T, typename add_const_ref<T>::type>::value;
  };

  template <typename T>
  struct is_sane {

    static const bool value = is_same<T, T>::value;
  };
}

/**
 * 2-1
 * Write a ternary metafunction replace_type<c,x,y> that takes an
 * arbitrary compoud type 'c' as its first parameter, and replaces
 * all occurrences of a type 'x' within 'c' with 'y'
 */

namespace one {

}
