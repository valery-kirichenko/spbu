#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> vec={1,2,3,4};
	 std::for_each(vec.begin(), vec.end(), [](int f){std::cout << f << ' ';}); 
	 
	 	
	 
	// your code goes here
	return 0;
}
