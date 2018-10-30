#include <typeinfo> // typeid(var).name()

#include "print_type.hpp"
#include "ch2.hpp"
#include "ch3.hpp"

int main(int argc, char** argv) {
  using namespace std;
  
  // Ch.2 Tests
  cout << two::zero::is_working<int>::value << endl;               // 0
  cout << two::zero::is_working<int&>::value << endl;              // 1
  cout << two::zero::is_working<const char&>::value << endl;       // 1

  typedef typename two::one::replace_type<const volatile int, int, double>::type one_test0;
  typedef typename two::one::replace_type<const long&, long, float>::type one_test1;
  cout << get_name<one_test0>() << endl;
  cout << get_name<one_test1>() << endl;
}
