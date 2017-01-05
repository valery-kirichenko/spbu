
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;
	for (int val = 0; val < 10; val++)
	{
		vec.push_back(val);
	}

	for_each(vec.begin(), vec.end(), [](int _n)
	{
		cout << _n << " ";
	});
	cout << endl;
	return 0;
}