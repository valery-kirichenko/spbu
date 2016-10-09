#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int nc = 10;
	int n, x = 0, k = 0, b = 0, sumeven = 0, sumodd = 0, l = 0;
	int c[nc];
	string st, sr;
	//c[0] = 2; c[1] = -2; c[2] = 4; c[3] = -4; c[4] = 1; c[5] = 3; c[6] = 0; c[7] = -5; c[8] = 10; c[9] = 10;
	cout << "Program for working with one-dimensional arrays\n" << endl;
	
	enter:
	for (int i = 0; i < nc; i++)
		c[i] = 0;
	cout << "Please, enter 10 integers of array: \n";
	for (int i = 0; i < nc; i++)
	{
		check:
		cout << "Element " << i + 1 << ": ";
		cin >> st;
		try {
			x = stoi(st);
			c[i] = x;
		}
		catch (...) {
			cout << "You enter not integer.\n";
			goto check;
		}
	}

	cout << endl;
	cout << "Please, choose and enter Your command:\n";
	cout << "1) Quantity of even numbers;\n";
	cout << "2) Number of minimal element;\n";
	cout << "3) Quantity of elements equal A (You must enter A);\n";
	cout << "4) Number of first negative element;\n";
	cout << "5) Maximal negative element;\n";
	cout << "6) The number of integers that are less than first element;\n";
	cout << "7) The difference of the sums of even and odd elements of the array;\n";
	cout << "8) Enter array again\n";
	cout << "9) Close the program;\n";
	start:
	cout << endl;
	cout << "Your command: ";
	cin >> sr;
	try {
		x = stoi(sr);
		n = x;
	}
	catch (...) {
		cout << "Your command are not correct.\n";
		cout << "Please, enter your command again.\n";
		goto start;
	}
	
	switch (n)
	{
		case 1:
			k = 0;
			for (int i = 0; i < nc; i++)
				if (c[i] % 2 == 0)
					k++;
			if (k > 0)
				cout << "Quantity of even numbers is " << k << ".\n";
			else
				cout << "Array has not even numbers.\n";
			goto start;
			break;

		case 2:
			k = 0;
			for (int i = 1; i < nc; i++)
				if (c[i] < c[k])
					k = i;
			cout << "Number of minimal element is " << k + 1 << ".\n";
			goto start;
			break;

		case 3:
			int a;
			k = 0;
			cout << "Please, enter A: ";
			cin >> a;
			for (int i = 0; i < nc; i++)
				if (c[i] == a)
					k++;
			if (k > 0)
				cout << "Quantity of elements equal " << a << " is " << k << ".\n";
			else
				cout << "Array has not elements equal " << a << ".\n";
			goto start;
			break;

		case 4:
			k = -1;
			for (int i = 0; i < nc; i++)
				if (c[i] < 0) {
					k = i;
					break;
				}
			if (k != -1)
				cout << "Number of first negative element is " << k + 1 << ".\n";
			else
				cout << "Array has not negative elements.\n";
			goto start;
			break;

		case 5:
			b = 0;
			for (int i = 0; i < nc; i++)
				if ((c[i] < 0) & ((b == 0) | (c[i] > b)))
					b = c[i];
			if (b != 0)
				cout << "Maximal negative element is " << b << ".\n";
			else
				cout << "Array has not negative elements.\n";
			goto start;
			break;

		case 6:
			k = 0;
			for (int i = 1; i < nc; i++)
				if (c[i] < c[0])
					k++;
			if (k > 0)
				cout << "The number of integers that are less than first element is " << k << ".\n";
			else
				cout << "Array has not elements that are less than first element.\n";
			goto start;
			break;

		case 7:
			sumeven = 0; sumodd = 0;
			for (int i = 0; i < nc; i++)
				if (c[i] % 2 == 0)
					sumeven += c[i];
				else
					sumodd += c[i];
			cout << "The difference of the sums of even and odd elements of the array is " << sumeven - sumodd << endl;
			goto start;
			break;
				
		case 8:
			cout << endl;
			goto enter;
			break;

		case 9:
			return 0;
			break;

		default:
			cout << "Your command are not correct.\n";
			cout << "Please, enter your command again.\n";
			goto start;
			break;
	}
    return 1;
}