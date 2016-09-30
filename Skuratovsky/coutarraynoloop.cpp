#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
int main()
{
  vector<int> a(10);
   copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
 

  return 0;
}
