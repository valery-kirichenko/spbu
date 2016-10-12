#include <iostream> 
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> vec1(n), vec2(n);
	for (int i = 0; i < n; i++)
		cin >> vec1[i];
	for (int i = 0; i < n; i++) 
		cin >> vec2[i];

	for (int i = 0; i < n; i++)
		vec1[i] *= vec2[i];

	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));

	return 0;
}
