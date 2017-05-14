#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main() {
	int s, max, min;
	double Average;
	int sA = 0;
	cout << "Size of array: ";
	cin >> s;
	vector<int> vec(s);
	cout << endl << "Elements: " << endl;
	cin >> vec[0];
	max = vec[0]; 
	min = vec[0];
	for (int i = 1; i < vec.size(); i++) {
		cin >> vec[i];
		sA = sA + vec[i];
		if (vec[i] > max) max = vec[i];
		if (vec[i] < min) min = vec[i];
	}
	Average = (double)sA / (double)vec.size();
	cout 
		<< "average is " << Average << endl
		<< "max is " << max << endl
		<< "min is " << min << endl
		<< "your array is: " << endl;
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout," "));
	return 0;
}
