#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int nc = 3;
	int n, x = 0, k = 0, b = 0, ki = 0, kj = 0, a1, a2, in = 0, jn = 0, k1 = 0, k2 = 2;
	int c[nc][nc];
	int a[nc];
	int w[nc];
	string st, sr, s;
	cout << "Program for working with matrix\n" << endl;

	enter:
	for (int i = 0; i < nc; i++)
		for (int j=0; j<nc; j++)
			c[i][j] = 0;
	cout << "Please, enter 3x3 integers of matrix: \n";
	for (int i = 0; i < nc; i++)
		for (int j = 0; j < nc; j++)
		{
			check:
			cout << "Element " << i + 1 << " " << j + 1 << ": ";
			cin >> st;
			try {
				x = stoi(st);
				c[i][j] = x;
			}
			catch (...) {
				cout << "You enter not integer.\n";
				goto check;
			}
	}

	cout << endl;
	cout << "Please, choose and enter Your command:\n";
	cout << "1) Number of minimal positive element of the matrix;\n";
	cout << "2) Finding the value of matrix element by its index (You must enter the index of element);\n";
	cout << "3) To swap rows of the matrix specified by You (You must enter two numbers of rows);\n";
	cout << "4) Swap first and last columns of the matrix;\n";
	cout << "5) Enter matrix again\n";
	cout << "6) Close the program;\n";
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
			b = 0;
			in = 0;
			jn = 0;
			for (int i = 0; i < nc; i++)
				for (int j = 0; j < nc; j++)
					if ((c[i][j] > 0) & ((b == 0) | (c[i][j] < b))) {
						b = c[i][j];
						in = i; 
						jn = j;
					}
			if (b != 0)
				cout << "Number of minimal positive element of the matrix is " << in + 1 << " " << jn + 1 << ".\n";
			else
				cout << "Array has not positive numbers.\n";
			goto start;
			break;

		case 2:
			ki = 0;
			kj = 0;
			k = 0;
			index1:
			cout << "Enter first index: ";
			cin >> s;
			try {
				x = stoi(s);
				ki = x - 1;
			}
			catch (...) {
				cout << "You enter not integer.\n";
				goto index1;
			}
			if ((ki < 0) | (ki > 2)) {
				cout << "Incorrect index of matrix.\n";
				goto index1;
			}
			index2:
			cout << "Enter second index: ";
			cin >> s;
			try {
				x = stoi(s);
				kj = x - 1;
			}
			catch (...) {
				cout << "You enter not integer.\n";
				goto index2;
			}
			if ((kj < 0) | (kj > 2)) {
				cout << "Incorrect index of matrix.\n";
				goto index2;
			}	
			k = c[ki][kj];
			cout << "Value of matrix element by its index " << k << ".\n";
			goto start;
			break;

		case 3:
			a1 = 0;
			a2 = 0;
			indexa1:
			cout << "Enter first row: ";
			cin >> s;
			try {
				x = stoi(s);
				a1 = x - 1;
			}
			catch (...) {
				cout << "You enter not integer.\n";
				goto indexa1;
			}
			if ((a1 < 0) | (a1 > 2)) {
				cout << "Incorrect index of matrix.\n";
				goto indexa1;
			}
			indexa2:
			cout << "Enter second row: ";
			cin >> s;
			try {
				x = stoi(s);
				a2 = x - 1;
			}
			catch (...) {
				cout << "You enter not integer.\n";
				goto indexa2;
			}
			if ((a2 < 0) | (a2 > 2) | (a2 == a1)) {
				cout << "Incorrect index of matrix.\n";
				goto indexa2;
			}
			for (int i = 0; i < nc; i++)
			{
				a[i] = c[a1][i];
				c[a1][i] = c[a2][i];
				c[a2][i] = a[i];
			}
			cout << "Program swaped " << a1 + 1 << " and " << a2 + 1 << ".\n";
			goto start;
			break;

		case 4:
			k1 = 0;
			k2 = 2;
			for (int i = 0; i < nc; i++)
			{
				w[i] = c[i][k1];
				c[i][k1] = c[i][k2];
				c[i][k2] = w[i];
			}
			cout << "Program swaped first and last columns of the matrix.\n";
			goto start;
			break;

		case 5:
			cout << endl;
			goto enter;
			break;

		case 6:
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