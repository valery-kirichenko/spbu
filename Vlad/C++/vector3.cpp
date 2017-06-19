#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main() {
	vector<int> vec1(10);
	vector<int> vec2(vec1.size());
	vector<int> vec3(vec1.size());
	
	for (int a = 0; a < vec1.size(); a++) {
		vec1[a] = a + 1;
		vec2[a] = a * 3;
	}
	
	for (int b = 0; b < vec1.size(); b++) {
		vec3[b] = vec1[b] * vec2[b];
	}
	
	copy(vec3.begin(), vec3.end(), ostream_iterator<int>(cout," "));
	return 0;
}
