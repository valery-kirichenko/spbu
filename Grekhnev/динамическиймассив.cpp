#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	setlocale(0, "");
	int n;
	cout << "¬ведите количество чисел в массиве \n";
	cin >> n;
	int *mass = new int[n];
	for (int i = 0; i < n; i++)
	{
		*(mass + i) = i + 10;
		cout << *(mass+i) << " ";
	}
	delete [] mass;
	system("pause");
    return 0;
}

