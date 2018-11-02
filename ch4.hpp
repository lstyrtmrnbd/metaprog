#include <boost/mpl/logical.hpp>
#include <type_traits>

using namespace boost::mpl;

namespace four {

  /**
   * Write tests for mpl::or_ and mpl::and_ metafunctions that
   * use their short-circuit behavior
   */
  namespace zero {

    // will fail if queried for nested type or value
    struct fail {};

    // will compile if B = true, fails if B = false
    template <bool B>
    struct test_or : or_<bool_<B>, fail>
    {};

    // will compile if B = false, fails if B = true
    template <bool B>
    struct test_and : not_<and_<bool_<B>, fail>>
    {};
  }

  /**
   *
   */
  namespace one {

  }
  
}
