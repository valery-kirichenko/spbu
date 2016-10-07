// ukazat.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *b = new int [n];
	for (int i = 0; i<n; i++)
	{
		cin >> *(b + i);
	}
	for (int i = 0; i<n; i++)
	{
		cout << *(b+i)<<" ";
	}
	system("pause");
	return 0;
}

