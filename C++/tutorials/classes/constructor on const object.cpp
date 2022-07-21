// constructor on const object
#include <iostream>
using namespace std;

class MyClass {
  public:
    int x;
    MyClass(int val): x{val} {}
    int get() {return x;} // only cost members can be called
};
/*
int get() const {return x;}        // const member function
const int& get() {return x;}       // member function returning a const&
const int& get() const {return x;} // const member function returning a const& 
*/

int main() {
  const MyClass foo(10);
// foo.x = 20;            // not valid: x cannot be modified
  cout << foo.x << '\n';  // ok: data member x can be read
  return 0;
}