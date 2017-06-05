// vector.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	std::vector<int> v(n);
	
	for (int i = 0; i<v.size(); i++)
	{
		cin >> v[i];
	}
	std::vector<int> v1(n);
	std::vector<int> v2(n);
	for (int i = 0; i<v.size(); i++)
	{
		cin >> v1[i]; v2[i] = v[i] * v1[i];
	}
	copy(v2.begin(), v2.end(),
		ostream_iterator <int>(cout, " "));
	system("pause");
	return 0;
}


