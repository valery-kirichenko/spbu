// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int opr,i,j,a,m1[2][2], m2[2][2], r[2][2];
	cout << "Enter elements of matrix 1: " << endl;
	for (int i = 0; i < 2; i++) 
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> m1[i][j];
		}
	}
	cout << "Enter elements of matrix 2: " << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> m2[i][j];
		}
	}
	cout << "Enter action: " << endl << 
		"1 Addition" << endl << 
		"2 Subtraction" << endl << 
		"3 Multiplication" << endl << 
		"4 Opredelitel" << endl;
	cin >> a;
	switch (a)
	{
	case 1:
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << m1[i][j] + m2[i][j];
			}
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << m1[i][j] - m2[i][j];
			}
		}
		break;
	case 3:
		for (j = 0;j < 2;j++)
			r[0][j] = m1[0][0] * m2[0][j] + m1[0][1] * m2[1][j];
		for (j = 0;j < 2;j++)
			r[1][j] = m1[1][0] * m2[0][j] + m1[1][1] * m2[1][j];
		for (i = 0;i < 2;i++)
		{
			for (j = 0;j < 2;j++)
			{
				cout << r[i][j];
			}

		}
		break;
	case 4:
	{
		for (j = 0;j < 2;j++)
			r[0][j] = m1[0][0] * m2[0][j] + m1[0][1] * m2[1][j];
		for (j = 0;j < 2;j++)
			r[1][j] = m1[1][0] * m2[0][j] + m1[1][1] * m2[1][j];
		opr = r[0][0] * r[1][1] - r[0][1] * r[1][0];
		cout << opr << endl;
	}
	}
	system("pause");
	return 0;
}

