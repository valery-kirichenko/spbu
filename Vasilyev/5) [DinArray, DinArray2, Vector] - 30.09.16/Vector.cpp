#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	const int n = 10;
	vector <int> a(n), b(n), c(n);
	for (int i = 0; i < a.size(); i++)
		a[i] = i + 1;
	for (int i = 0; i < b.size(); i++)
		b[i] = i * 10;
	for (int i = 0; i < c.size(); i++)
		c[i] = a[i] * b[i];
	copy(c.begin(), c.end(), ostream_iterator<int>(cout, " "));
	system("pause");
	return 0;
}