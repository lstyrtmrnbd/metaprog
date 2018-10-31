#include <cassert>
#include <typeinfo> // typeid(var).name()

#include "print_type.hpp"
#include "ch2.hpp"
#include "ch3.hpp"

int main() {
  using namespace std;
  
  // Ch.2 Tests
  cout << "2-0 tests: ";
  assert(two::zero::is_working<int>::value == 0);
  assert(two::zero::is_working<int&>::value == 1);
  assert(two::zero::is_working<const char&>::value == 1);
  cout << "success" << endl;

  cout << "2-1 tests: " << endl;
  typedef typename two::one::replace_type<const volatile int, int, double>::type one_test0;
  typedef typename two::one::replace_type<const long&, long, float>::type one_test1;
  cout << get_name<one_test0>() << endl;
  cout << get_name<one_test1>() << endl;

  cout << "3-0 tests: ";
  assert(three::zero::binary<101>::value != 0);
  //three::zero::binary<123>::value; //fails compilation as it should
  cout << "success" << endl;
}
