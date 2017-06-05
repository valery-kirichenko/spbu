#include <iostream>

using namespace std;

int main() {
	int n = 10;
	int i = 0;
	while (i <= n) {
		cout << "while " << i << endl;
		i++;
	}

	for (i = 0; i <= n; i++) {
		cout << "for " << i << endl;
		i++;
	}

	i = 0;

	do {
		cout << "do-while " << i << endl;
		i++;
	} while (i <= n);

	return 0;
}
