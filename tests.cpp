#include <typeinfo> // typeid(var).name()

#include "ch2.hpp"

int main(int argc, char** argv) {
  using namespace std;

  int test = 4;
  
  cout << is_working<int>::value << endl;
  cout << is_working<const char&>::value << endl;
  cout << (typeid(test).hash_code() == typeid(4).hash_code()) << endl;
}
