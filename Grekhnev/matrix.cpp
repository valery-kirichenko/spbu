#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int a[2][2], b[2][2], r[2][2];

	cout << "Vvedite A \n";
	for (int i = 0; i<2; i++)
		for (int j = 0; j<2; j++)
			cin >> a[i][j];
	cout << "\n";
	

	cout << "Vvedite B \n";
	for (int i = 0; i<2; i++)
		for (int j = 0; j<2; j++)
			cin >> b[i][j];
	cout << "\n";

	cout << "Vvedite nomer operacii \n";
	int c; cin >> c;
	cout << "\n";
	

	switch (c)
	{
	case 1:
	{
		r[0][0] = (a[0][0] * b[0][0]) + (a[0][1] * b[1][0]);
		r[0][1] = (a[0][0] * b[0][1]) + (a[0][1] * b[1][1]);
		r[1][0] = (a[1][0] * b[0][0]) + (a[1][1] * b[1][0]);
		r[1][1] = (a[1][0] * b[0][1]) + (a[1][1] * b[1][1]);
		
		for (int i = 0; i<2; i++)
		{
			for (int j = 0; j < 2; j++)
				cout << r[i][j] << "  ";;
			cout << "\n";
		}
		break;
	}
	case 2:
	{
		for (int i = 0; i<2; i++)
		{
			for (int j = 0; j<2; j++)
			{
				r[i][j] = a[i][j] + b[i][j];
				cout << r[i][j] << " ";
			}
			cout << "\n";
		}
		break;
	}
	case 3:
	{
		for (int i = 0; i<2; i++)
		{
			for (int j = 0; j<2; j++)
			{
				r[i][j] = a[i][j] - b[i][j];
				cout << r[i][j] << " ";
			}
			cout << "\n";
		}
		break;
	}
	case 4:
	{
		int k, n;
		k = a[0][0] * a[1][1] - a[0][1] * a[1][0];
		n = b[0][0] * b[1][1] - b[0][1] * b[1][0];
		cout << "\n";
		cout << "det A= " << k;
		cout << "\n";
		cout << "det B= " << n;
		break;
	}
	}
	cout << "\n";
	system("pause");
	return 0;
}
