#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n, j = 0;
	cout << "1) 'for' \n";
	cout << "2) 'while' \n";
	cout << "3) 'do while' \n";
	cout << "Enter 'n' : ";
	cin >> n;
	switch (n)
	{
	case 1:
		for (int i = 0; i < 11; i++)
			cout << i << endl;
		break;
	case 2:
		while (j < 11)
		{
			cout << j << endl;
			j++;
		}
		break;
	case 3:
		do
		{
			cout << j << endl;
			j++;
		}
		while (j <11);
		break;
	}
}