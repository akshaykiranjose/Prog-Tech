// namespaces
#include <iostream>
using namespace std;

namespace bar
{
  const double pi = 3.1416;
}

namespace bar
{
  double value() { return 2*pi; }
}
namespace foo
{
  int value() { return 5; }
}



int main () {
  cout << foo::value() << '\n';
  cout << bar::value() << '\n';
  cout << bar::pi << '\n';
  return 0;
}