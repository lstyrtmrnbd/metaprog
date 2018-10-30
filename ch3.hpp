#include <boost/static_assert.hpp>
#include <boost/mpl/count_if.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/logical.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/vector.hpp>
#include <type_traits>

using namespace std;
using namespace boost::mpl;

namespace three {

  /**
   * Use BOOST_STATIC_ASSERT to add error checking to the binary template 
   * presented in section 1.4.1, so that binary<N>::value causes a
   * compilation error if N contains digits other than 0 or 1
   */
  namespace zero {

    template <unsigned long N>
    struct binary {

      static unsigned const value = binary<N/10>::value << 1 | N%10;
    };

    template <>
    struct binary<0> {

      static unsigned const value = 0;
    };

    template <unsigned long N, class Vector>
    struct fill_vector {

      typedef typename fill_vector<(N - (N%10))/10,
                                   typename push_back<Vector, int_<N%10>>::type>::type type;
    };

    template<class Vector>
    struct fill_vector<0, Vector> {

      typedef Vector type;
    };

    template<unsigned long N>
    struct illegal_contents {

      static const int count = count_if<fill_vector<N, vector<>>,
                                        or_<not_<is_same<_, int_<0>>>,
                                            not_<is_same<_, int_<1>>>>>::value;
      static const bool value = (count != 0);
    };

    template <unsigned long N>
    struct test0 {

      typedef typename fill_vector<N, vector<>>::type type;
    };

    // examples
    unsigned const one   = binary<1>::value;
    unsigned const three = binary<11>::value;
    unsigned const five  = binary<101>::value;
    unsigned const seven = binary<111>::value;
    unsigned const nine  = binary<1001>::value;
  }
  
}
