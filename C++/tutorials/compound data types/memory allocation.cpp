// memory allocation
#include <iostream>
#include <new>
using namespace std;

int main()
{
  int i,n;
  int * p;
  cout<<"How many?"<<endl;
  cin>>i;
  p = new (nothrow) int [i]; // size can be variable
  if (p==nullptr)
    cout<<"Error in Allocation";
  else{

    for (n=0;n<i;n++)
    {
      cout<<"Enter: ";
      cin>> p[n];
    }
    cout<<"You Entered:" ;
    for (n=0;n<i;n++)
      cout << p[n] <<", ";
    delete[] p;
  }

  return 0;

}