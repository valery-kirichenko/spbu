#include <iostream> 
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> vec(n);

	for (int i = 0; i < n; i++)
		std::cin >> vec[i];

	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));

	return 0;
}
