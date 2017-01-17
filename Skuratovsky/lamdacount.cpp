#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> vec={1,2,3,4,5,6,7,8,9,10};
	int i=5;
	int j=9;
	int c;
	c= std::count_if(vec.begin(), vec.end(), [i,j](int f) {return f<i || f>j;}); 
	 cout<<c;
	 	
	 
	// your code goes here
	return 0;
}
