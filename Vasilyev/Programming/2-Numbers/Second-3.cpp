#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int a, x, k1, k;
	cout << "Please, entry your number:" << endl;
	cin >> x;
	a = x;
	k1 = a % 1000;
	k = k1 / 100;
	cout << k << endl;
	system("pause");
	return 0;
}