// ConsoleApplication2.cpp : main project file.

#include "stdafx.h"
#include <iostream>
using namespace std;

void vivod(int arr[2][2], int arr1[2][2])
{
	cout << endl << "Matrix a:" << endl;


	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl << "Matrix b:" << endl;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			cout << arr1[i][j] << " ";
		cout << endl;
	}
	
}

void sum(int arr[2][2], int arr1[2][2])
{
	cout << "Sum = " << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			cout << arr[i][j] + arr1[i][j] << " ";
		cout << endl;
	}
}

void raz(int arr[2][2], int arr1[2][2])
{
	cout << "Raz = " << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			cout << arr[i][j] - arr1[i][j] << " ";
		cout << endl;
	}
}

void umn(int arr[2][2], int arr1[2][2])
{
	cout << "Umn = " << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			cout << arr[i][0] * arr1[0][j] + arr[i][1] * arr1[1][j] << " ";
		cout << endl;
	}
}

void opr(int arr[2][2])
{
	cout << arr[0][0] * arr[1][1] - arr[1][0] * arr[0][1] << endl;		
}

int main()
{
	int b[2][2];
	int a[2][2];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			cout << "[" << i + 1 << "]" << "[" << j + 1 << "]: ";
			cin >> a[i][j];
		}

	cout << endl;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			cout << "[" << i + 1 << "]" << "[" << j + 1 << "]: ";
			cin >> b[i][j];
		}
	char c;

	while (c != '5')
	{
		vivod(a, b);
		cout << endl << "Chose operation" << endl;
		cout << "1: +" << endl;
		cout << "2: -" << endl;
		cout << "3: *" << endl;
		cout << "4: d" << endl;
		cout << "5: exit" << endl;
		cin >> c;
		cout << endl;

		switch (c)
		{
			case '1':
				sum(a, b);
				break;
			case '2':
				raz(a, b);
				break;
			case '3':
				umn(a, b);
				break;
			case '4':			
				cout << "d(a)= ";
				opr(a);
				cout << "d(b)= ";
				opr(b);
				cout << endl;
				break;		
			default:
				break;
		}
	}	
	return 0;
}




	