#include <typeinfo> // typeid(var).name()

#include "print_type.hpp"
#include "ch2.hpp"

int main(int argc, char** argv) {
  using namespace std;
  
  // Ch.2 Tests
  cout << zero::is_working<int>::value << endl;               // 0
  cout << zero::is_working<int&>::value << endl;              // 1
  cout << zero::is_working<const char&>::value << endl;       // 1
}
