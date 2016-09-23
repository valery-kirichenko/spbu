#include "stdafx.h"
#include <iostream>

using namespace std;

int mInte(int a, int b)
{
	if (a > b)
		return a;
	else if (b > a)
		return b;
	else
		return 0;
}

int main()
{
	int a, b;
	cout << "Enter two integers : ";
	cin >> a >> b;
	if (mInte(a, b) != 0)
		cout << "Max is " << mInte(a, b);
	else
		cout << "Equal integers";
	return 0;
}

