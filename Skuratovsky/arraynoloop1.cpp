#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {

  vector<int> a(10, 100);
  vector <int>b (10,1000);
  for(int i=0; i<10; i++)
  a[i]*=b[i];
   copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
	// your code goes here
	return 0;
}
