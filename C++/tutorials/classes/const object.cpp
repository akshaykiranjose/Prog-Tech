//const object
/*
You may think that anyway you are seldom going to declare 
const objects, and thus marking all members that don't modify
the object as const is not worth the effort, but const 
objects are actually very common. Most functions taking
classes as parameters actually take them by const reference,
and thus, these functions can only access their const members:
*/
#include <iostream>
using namespace std;

class MyClass {
    int x;
  public:
    MyClass(int val) : x(val) {}
    const int& get() const {return x;}
};

void print (const MyClass& arg) {
  cout << arg.get() << '\n';
}

int main() {
  MyClass foo (10);
  print(foo);

  return 0;
}
