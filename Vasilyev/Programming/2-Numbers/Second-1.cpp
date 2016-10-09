#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int a, x, k1, k2, k3, k;
	cout << "Please, entry your number:" << endl;
	cin >> x;
	a = x;
	k3 = a % 10;
	a = a / 10;
	k2 = a % 10;
	a = a / 10;
	k1 = a % 10;
	k = k2 * 100 + k1 * 10 + k3;
	cout << k << endl;
	system("pause");
	return 0;
}