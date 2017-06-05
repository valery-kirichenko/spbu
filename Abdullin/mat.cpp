// 1210.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>;
using namespace std;
class MAT {
	
public: 
	int m[3][3];	
	MAT();
	MAT(int x)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				m[i][j]=x;
		}
	}
	MAT operator + (MAT x)
	{
		MAT a(0);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				a.m[i][j] = this->m[i][j] + x.m[i][j];
		}
		return a;
	}
	MAT operator - (MAT x)
	{
		MAT a(0);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				a.m[i][j] = this->m[i][j] - x.m[i][j];
		}
		return a;
	}
	MAT operator * (MAT x)
	{
		MAT a(0);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3;k++)
					a.m[i][j] += this->m[i][k] * x.m[k][j];
			}
		}
		return a;
	}
	int det()
	{
		return m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] + m[1][0] * m[2][1] * m[0][2] - m[0][2] * m[1][1] * m[2][0] - m[0][1] * m[1][0] * m[2][2] - m[0][0] * m[2][1] * m[1][2];
	}
};
MAT::MAT()
{
	cout << "Vvedite znacheniya matrici \n";;
	for (int i = 0; i < 3; i++)
	{		for (int j = 0; j < 3; j++)
			cin >> m[i][j];
	cout << "\n";
    }
		}
int main()
{
	MAT a;
	MAT b;
	MAT c(0);
	int z=6;
	cout << "\n\n";
	while (z!=4)
	{
		cout << "Viberite deystvie \nSumma - 1\nRaznica - 2\nProizv - 3\nvihod - 4\n";
		cin >> z;
		switch (z)
		{
		case (1): {c = a + b; break;}
		case (2): {c = a - b;break; }
		case (3): {c = a*b; break;}
		case (4): return 0;
		}
		system("cls");
		for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3;j++)
			cout << c.m[i][j] << "  ";
		cout << "\n";
	}
	cout << "\nDet rezultata = "<<c.det()<<"\n";
	system("pause");
	}
	
    return 0;
}

