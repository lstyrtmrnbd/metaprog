#include <boost/static_assert.hpp>
#include <boost/mpl/arithmetic.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/vector_c.hpp>

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

      static const int  digit = N%10;
      static const bool check = (digit == 0 || digit == 1);
      BOOST_STATIC_ASSERT(check);
      
      static unsigned const value = binary<N/10>::value << 1 | N%10;
    };

    template <>
    struct binary<0> {

      static unsigned const value = 0;
    };
    
    // examples
    unsigned const one   = binary<1>::value;
    unsigned const three = binary<11>::value;
    unsigned const five  = binary<101>::value;
    unsigned const seven = binary<111>::value;
    unsigned const nine  = binary<1001>::value;
  }

  /**
   * Turn vector_c<int,1,2,3> into a type sequence with elements (2,3,4)
   * using transform
   */
  namespace one {

    typedef vector_c<int,1,2,3> old_vec;

    typedef typename transform<old_vec, boost::mpl::plus<_,int_<1>>>::type new_vec;

    typedef typename boost::mpl::equal<new_vec, vector_c<int,2,3,4>>::type check;
  }

  /**
   * Turn a vector_c<int,1,2,3> into a type sequence with elements (1,4,9)
   * using transform
   */
  namespace two {

    typedef vector_c<int,1,2,3> old_vec;

    typedef typename transform<old_vec, boost::mpl::times<_1,_1>>::type new_vec;

    typedef typename boost::mpl::equal<new_vec, vector_c<int,1,4,9>>::type check;
  }
}
