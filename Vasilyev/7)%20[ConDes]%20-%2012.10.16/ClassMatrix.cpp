#include "stdafx.h"
#include <iostream>

using namespace std;

const int n = 3;

class Matrix{
	public:
		int count[n][n];
		int d;
		void reset();
		void outM()
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cout << this->count[i][j] << " ";
				}
				cout << endl;
			}
		}
		void dofM() 
		{
			d = ((this->count[0][0] * this->count[1][1] * this->count[2][2]) + (this->count[0][1] * this->count[1][2] * this->count[2][0]) + (this->count[1][0] * this->count[0][2] * this->count[2][1]) - (this->count[2][0] * this->count[1][1] * this->count[0][2]) - (this->count[0][0] * this->count[2][1] * this->count[1][2]) - (this->count[1][0] * this->count[0][1] * this->count[2][2]));
		}
};

void Matrix::reset()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Enter the element of matrix " << i + 1 << " " << j + 1 << " : ";
			cin >> this->count[i][j];
		}
	}
	cout << endl;
}

void plusM(Matrix &a, Matrix &b)
{
	cout << endl;
	Matrix plus;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			plus.count[i][j] = a.count[i][j] + b.count[i][j];
		}
	}
	plus.outM();
	plus.dofM();
	cout << "Det m1 + m2 = " << plus.d << endl << endl;
}

void minusM(Matrix &a, Matrix &b)
{
	cout << endl;
	Matrix minus;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			minus.count[i][j] = a.count[i][j] - b.count[i][j];
		}
	}
	minus.outM();
	minus.dofM();
	cout << "Det m1 - m2 = " << minus.d << endl << endl;
}

void multM(Matrix &a, Matrix &b)
{
	cout << endl;
	Matrix mult;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mult.count[i][j] = 0;
			for (int l = 0; l < n; l++)
				mult.count[i][j] += a.count[i][l] * b.count[l][j];
		}
	}
	mult.outM();
	mult.dofM();
	cout << "Det m1 * m2 = " << mult.d << endl << endl;
}

void redM(Matrix &a, Matrix &b)
{
	cout << endl;
	Matrix temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp.count[i][j] = a.count[i][j];
			a.count[i][j] = b.count[i][j];
			b.count[i][j] = temp.count[i][j];
		}
	}
	cout << "Swap completed!\n" << endl;
}

int main()
{
	int k = 0;
	char n;
	cout << "Enter matrix 1: \n";
	Matrix alpha;
	alpha.reset();
	cout << "Enter matrix 2: \n";
	Matrix beta;
	beta.reset();

	while (true)
	{
		cout << "1) m1 + m2;\n";
		cout << "2) m1 - m2;\n";
		cout << "3) m1 * m2;\n";
		cout << "4) Redefine m1;\n";
		cout << "5) Redefine m2;\n";
		cout << "6) Out determinant of m1;\n";
		cout << "7) Out determinant of m2;\n";
		cout << "8) Swap m1 and m2;\n";
		cout << "9) Exit;\n";
		cout << "Enter your comand: ";
		cin >> n;
		if (n == '1')
			plusM(alpha, beta);
		else if (n == '2')
			minusM(alpha, beta);
		else if (n == '3')
			multM(alpha, beta);
		else if (n == '4')
			alpha.reset();
		else if (n == '5')
			beta.reset();
		else if (n == '6') {
			alpha.dofM();
			cout << "Det m1 = " << alpha.d << endl << endl;
		}
		else if (n == '7') {
			beta.dofM();
			cout << "Det m2 = " << beta.d << endl << endl;
		}
		else if (n == '8') 
			redM(alpha, beta);
		else if (n == '9') {
			system("pause");
			return 0;
		}
		else
			cout << "Wrong data! Enter command again!\n";
	}
}