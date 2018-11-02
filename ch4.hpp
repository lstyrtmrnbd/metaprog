#include <boost/mpl/logical.hpp>
#include <boost/mpl/if.hpp>

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
   * Implement binary metafunctions logical_or and logical_and
   * that model the behavior of mpl::or_ and mpl::and_ correspondingly.
   * Use tests from 4-0 to verify your implementation
   */
  namespace one {

    template <class A, class B>
    struct logical_or {

      static const bool value = if_<A,
				    bool_<true>,
				    B>::type::value;
    };

    template <class A, class B>
    struct logical_and {

      static const bool value = if_<not_<A>,
				    bool_<false>,
				    B>::type::value;
    };

    // tests from 4-0 restated in terms of corresponding solutions
    struct fail {};

    // will compile if B = true, fails if B = false
    template <bool B>
    struct test_or : logical_or<bool_<B>, fail>
    {};

    // will compile if B = false, fails if B = true
    template <bool B>
    struct test_and : not_<logical_and<bool_<B>, fail>>
    {};
    
  }
  
}
