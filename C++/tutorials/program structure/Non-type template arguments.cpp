//function templates

#include <iostream>
using namespace std;

template <typename T, int N>
T fixed_mult(T val)
{
  return val*N;
}
int same(int x)
{
  return x;
}
int main()
{
  int x = 2; // what's passed in the <> has to be a constant 
  cout<< fixed_mult<int, 2>(10)<<"\n";
  cout<< fixed_mult<int, 3>(10)<<"\n";
  return 0;
}