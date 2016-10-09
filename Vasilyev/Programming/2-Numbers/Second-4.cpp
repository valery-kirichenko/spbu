#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int a, x, k1, k;
	cout << "Please, entry your number:" << endl;
	cin >> x;
	a = x;
	k1 = a % 10000;
	k = k1 / 1000;
	cout << k << endl;
	system("pause");
	return 0;
}