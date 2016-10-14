#include "stdafx.h"
#include <iostream>

using namespace std;

class matrix
{
	public:
	int mat[3][3];
	void inm();
	void outm();
	void dm();	
	int d;
};

void matrix::inm()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "Enter the element of matrix " << i + 1 << " " << j + 1 << " : ";
			cin >> this->mat[i][j];
		}
	}
	cout << endl;
}

void matrix::outm()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << this->mat[i][j] << " ";
		}
		cout << endl;
	}
}

void matrix::dm()
{
	d = ((this->mat[0][0] * this->mat[1][1] * this->mat[2][2]) + (this->mat[0][1] * this->mat[1][2] * this->mat[2][0]) + (this->mat[1][0] * this->mat[0][2] * this->mat[2][1]) - (this->mat[2][0] * this->mat[1][1] * this->mat[0][2]) - (this->mat[0][0] * this->mat[2][1] * this->mat[1][2]) - (this->mat[1][0] * this->mat[0][1] * this->mat[2][2]));
}

void plusm(matrix &a, matrix &b)
{
	cout << endl;
	matrix plus;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			plus.mat[i][j] = a.mat[i][j] + b.mat[i][j];
		}
	}
	plus.outm();
	plus.dm();
	cout << "Det m1 + m2 = " << plus.d << endl << endl;
}

void minusm(matrix &a, matrix &b)
{
	cout << endl;
	matrix minus;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			minus.mat[i][j] = a.mat[i][j] - b.mat[i][j];
		}
	}
	minus.outm();
	minus.dm();
	cout << "Det m1 - m2 = " << minus.d << endl << endl;
}

void umnm(matrix &a, matrix &b)
{
	cout << endl;
	matrix umn;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			umn.mat[i][j] = 0;
			for (int l = 0; l < 3; l++)
				umn.mat[i][j] += a.mat[i][l] * b.mat[l][j];
		}
	}
	umn.outm();
	umn.dm();
	cout << "Det m1 * m2 = " << umn.d << endl << endl;
}


int main()
{
	char n;
	cout << "Enter matrix 1: " << endl;
	matrix a;
	a.inm();
	cout << "Enter matrix 2: " << endl;
	matrix b;
	b.inm();

	while (true)
	{
		cout << "1) m1 + m2" << endl;
		cout << "2) m1 - m2" << endl;
		cout << "3) m1 * m2" << endl;
		cout << "4) Exit" << endl;
		cout << "Enter your comand: ";
		cin >> n;
		if (n == '1')
			plusm(a, b);
		else if (n == '2')
			minusm(a, b);
		else if (n == '3')
			umnm(a, b);
		else if (n == '4')
			return 0;
				
	}
}