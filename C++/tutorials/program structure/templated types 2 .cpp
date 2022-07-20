//function templates

#include <iostream>
using namespace std;

template <typename T, typename U>
bool are_equal (T a, U b)
{
  return (a==b);
}

int main()
{
  if(are_equal(10,10))
    cout<<"Equal\n";
  else
    cout<<"Not Equal\n";

  //return 0;
}