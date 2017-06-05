#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	cout << "Enter the length: ";
	int n; cin >> n;
	vector <int> c(n);
	cout << "Enter the array: ";
	for (int i = 0; i < n; i++)
		cin >> c[i];
	map <int, int> eqA;
	int chtcount = 0, minid = 0, firstnegid = -1, maxneg = 0, lessC1num = 0, sumdif = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] % 2 == 0)
			chtcount++;
		if (c[i] < c[minid])
			minid = i;
		eqA[c[i]]++;
		if (firstnegid == -1 && c[i] < 0)
			firstnegid = i + 1;
		if (c[i] < 0 && (maxneg == 0 || c[i] > maxneg))
			maxneg = c[i];
		if (c[i] < c[0])
			lessC1num++;
		if (c[i] % 2)
			sumdif -= c[i];
		else
			sumdif += c[i];
	}
	minid++;
	sumdif = abs(sumdif);
	cout << "1 - number of even elements\n 2 - min element index\n3 - number of elements equal to A\n4 - " <<
		"number of first non-negative element\n5 - max negative number\n6 - number of elements less than C1\n7 - " <<
		"difference of sums of even numbers and odd numbers";
	while (true) {
		int k; cin >> k;
		switch (k) {
		case 1: cout << chtcount; break;
		case 2: cout << minid; break;
		case 3: cout << "Enter A: "; int b; cin >> b; cout << eqA[b]; break;
		case 4: if (firstnegid == -1) cout << "No negatives"; else cout << firstnegid; break;
		case 5: if (firstnegid == -1) cout << "No negatives"; cout << maxneg; break;
		case 6: cout << lessC1num; break;
		case 7: cout << sumdif; break;
		default: cout << "1-7"; break;
		}
		cout << endl;
	}
}