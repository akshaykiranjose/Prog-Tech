// pointers as strings:
#include <iostream>
using namespace std;

int main()
{
  const char * foo = "situation is fubar";
  const char *ptr =  foo; 
  while(*ptr != '\0')
  {
    cout<<*(ptr++);
  }
}