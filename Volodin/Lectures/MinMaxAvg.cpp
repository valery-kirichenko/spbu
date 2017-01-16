#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector<int> v;
	cin >> n;
	v.reserve(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int mx = v[0], mn = v[0], avg = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mx, v[i]);
		mn = min(mn, v[i]);
		avg += v[i];
	}
	cout << "Max: " << mx << "\nMin: " << mn << "\nAvg: " << (double) avg / n << endl;
}