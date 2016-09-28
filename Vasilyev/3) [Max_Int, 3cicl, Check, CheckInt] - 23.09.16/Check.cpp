#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n, m, k = 0;
	cout << "Enter two integers : ";
	cin >> n >> m;
	cout << endl;
	try	{
		if (m == 0)
			throw 0;
	}
	catch (...) {
		cout << "Error";
		return 0;
	}
	cout << n / m;
	return 0;
}