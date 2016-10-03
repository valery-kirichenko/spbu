#include "stdafx.h"
#include <iostream>

using namespace std;

const int n = 3;

void outM(int a[][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int dofM(int a[][n])
{
	int d = 0;
	d = ((a[0][0] * a[1][1] * a[2][2]) + (a[0][1] * a[1][2] * a[2][0]) + (a[1][0] * a[0][2] * a[2][1]) - (a[2][0] * a[1][1] * a[0][2]) - (a[0][0] * a[2][1] * a[1][2]) - (a[1][0] * a[0][1] * a[2][2]));
	return d;
}

int main()
{

	int k = 0, d1, d2, d3;
	int  a[n][n], b[n][n], c[n][n], d[n][n], e[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Enter the element of a " << i << " " << j << " : ";
			cin >> a[i][j];
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Enter the element of b " << i << " " << j << " : ";
			cin >> b[i][j];
		}
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			d[i][j] = a[i][j] - b[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			e[i][j] = 0;
			for (int l = 0; l < n; l++)
				e[i][j] += a[i][l] * b[l][j];
		}
	}
	cout << endl;

	cout << "Matrix A: \n";
	outM(a);
	cout << "d (A): " << dofM(a) << endl;
	cout << endl;

	cout << "Matrix B: \n";
	outM(b);
	cout << "d (B): " << dofM(b) << endl;
	cout << endl;

	cout << "Matrix A+B: \n";
	outM(c);
	cout << "d (A+B): " << dofM(c) << endl;
	cout << endl;

	cout << "Matrix A-B: \n";
	outM(d);
	cout << "d (A-B): " << dofM(d) << endl;
	cout << endl;

	cout << "Matrix A*B: \n";
	outM(e);
	cout << "d (A*B): " << dofM(e) << endl;
	cout << endl;

	system("pause");
	return 0;
}