// pointers as arguments:
#include <iostream>
using namespace std;

void increment_all(int * start, int * stop)
{
  int* current = start;
  while(current != stop)
  {
      ++(*current);
      ++current;
  }
}

void print_all(const int * start, const int * stop)
{
  const int* current = start;
  while(current != stop)
  {
      cout<<(*current)<<" ";
      ++current;
  }
}

int main()
{
  int numbers[] = {10, 20, 30, 50};
  increment_all(numbers, numbers+4);
  print_all(numbers, numbers+4);
}