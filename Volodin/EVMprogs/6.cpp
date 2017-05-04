#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n; cin >> n;
	int count = 0;
	while (n--) {
		bool up = true;
		int pred;
		bool started = false;
		while (true) {
			int a; cin >> a;
			if (a == 0)
				break;
			if (started && a < pred)
				up = false;
			pred = a;
			started = true;
		}
		count += up;
	}
	cout << count;
}