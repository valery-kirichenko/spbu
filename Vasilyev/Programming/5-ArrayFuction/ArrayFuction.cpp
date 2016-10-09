#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int k = -1;

int chF(vector <int> &b, int &a)
{
	int n = 0, nk, m = 0;
	nk = b[0];
	for (int i = 0; i < b.size(); i++)
		if (b[i] > nk)
			nk = b[i];
	if (nk < 0) {
		k = -2;
		return 0;
	}
	for (n = 1; n < nk; n++)
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i] == n) {
				b[i] = 0;
				break;
			}
			if (i == a - 1) {
				for (int j = 0; j < b.size(); j++)
					if ((b[j] < nk) & (b[j] > 0)) {
						k = j;
						nk = b[j];
					}
				return 0;
			}
		}
	return 0;
}

int main()
{
	int a;
	cout << "Enter size of array : ";
	cin >> a;
	vector <int> b(a);
	for (int i = 0; i < b.size(); i++)
	{
		cout << "Enter element " << i + 1 << " :";
		cin >> b[i];
		cout << endl;
	}
	cout << endl;
	chF(b, a);
	if (k != -1)
		if (k == -2)
			cout << "Array has not positive elements!";
		else
			cout << k + 1;
	else
		cout << "All right!";
	system("pause");
    return 0;
}

