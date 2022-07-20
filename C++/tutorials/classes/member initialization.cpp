// member initialization
#include <iostream>
using namespace std;

class Circle {
    double radius;
  public:
    Circle(double r) { radius = r; } // does not have a default constructor
    double area() {return radius*radius*3.14159265;}
};

class Cylinder {
    Circle base; // member object
    double height; // member variable fundamental type
  public:
    Cylinder(double r, double h) :  base (r), height(h) {}
    /*
    Because objects of class Circle can only be constructed 
    with a parameter, Cylinder's constructor needs to call 
    base's constructor, and the only way to do this 
    is in the member initializer list.
    */
    double volume() {return base.area() * height;}
};

int main () {
  Cylinder foo (10,20);

  cout << "foo's volume: " << foo.volume() << '\n';
  return 0;
}