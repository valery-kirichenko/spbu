#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector <vector <int> > a(n, vector <int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	bool cont = true;
	while (cont) {
		int k; cin >> k;
		switch (k) {
		case 1: {
			int mxj = -1, mxi = -1;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (a[i][j] > 0 && (mxj == -1 || a[i][j] < a[mxi][mxj])) {
						mxi = i;
						mxj = j;
					}
			cout << mxi + 1 << ' ' << mxj + 1;
			break;
		}
		case 2: {int i, j; cin >> i >> j; i--; j--; cout << a[i][j]; break; }
		case 3: {int i, j; cin >> i >> j;  i--; j--; swap(a[i], a[j]); break; }
		case 4: {
			int i, j; cin >> i >> j; i--; j--;
			for (int c = 0; c < n; c++)
				swap(a[c][i], a[c][j]);
			break; 
		}
		case 5:cont = false; break;
		default: cout << "1-5"; break;
		}
		cout << endl;
	}
	cout << "Bye";
}