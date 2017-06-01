#include <vector>
#include <iterator>

using namespace std;

int main() {
	vector<int> vec1(10);
	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout," "));
	return 0;
}
