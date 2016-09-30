#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
int main()
{
  vector<int> a(10);
  ostream_iterator<int> out (cout, " ");
   copy(a.begin(), a.end(), out);
 

  return 0;
}
