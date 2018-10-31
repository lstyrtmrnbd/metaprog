#include <typeinfo> // typeid(var).name()

#include "print_type.hpp"
#include "ch2.hpp"
#include "ch3.hpp"

int main() {
  using namespace std;
  
  // Ch.2 Tests
  cout << two::zero::is_working<int>::value << endl;               // 0
  cout << two::zero::is_working<int&>::value << endl;              // 1
  cout << two::zero::is_working<const char&>::value << endl;       // 1

  typedef typename two::one::replace_type<const volatile int, int, double>::type one_test0;
  typedef typename two::one::replace_type<const long&, long, float>::type one_test1;
  cout << get_name<one_test0>() << endl;
  cout << get_name<one_test1>() << endl;

  const bool ic0 = three::zero::illegal_numeral<101>::value;
  const bool ic1 = three::zero::illegal_numeral<123>::value;
  cout << ic0 << endl;
  cout << ic1 << endl;
}
