#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int **a = new int *[n];

	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
		for (int j = 0; j < m; j++)
			cout << setw(3) << a[i][j];
	}

	for (int i = 0; i < n; i++)
		delete [] a[i];
	delete a;
}