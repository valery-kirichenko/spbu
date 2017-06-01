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
	int max, min, k = 0;
	double s = 0;
	copy(v.begin(), v.end(),
		ostream_iterator <int>(cout, " "));
	cout << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		if (k == 0) {
			max = v[i]; min = v[i]; k++;
	}
		else if (v[i] > max) max = v[i];
		else if (v[i] < min) min = v[i];
		s += v[i];
	}
	cout << "Max = " << max << "\n Min = " << min << "\n Srednee arifmeticheskoe = " << s / n<<"\n";
	system("pause");
	return 0;
}


