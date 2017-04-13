#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n; cin >> n;
	vector <vector <int> > a(n, vector <int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	int p = 0, q = 0, r = n - 1, s = n - 1;
	int di = 0, dj = 1;
	int i = 0, j = 0;
	for (int k = 0; k < n*n; k++) {
		cout << a[i][j] << ' ';
		i += di;
		j += dj;
		if (dj == 1 && j + dj > s) {
			di = 1; dj = 0;
			p++;
		}
		if (dj == -1 && j + dj < q) {
			di = -1; dj = 0;
			r--;
		}
		if (di == 1 && i + di > r) {
			di = 0; dj = -1;
			s--;
		}
		if (di == -1 && i + di < p) {
			di = 0; dj = 1;
			q++;
		}
	}
}