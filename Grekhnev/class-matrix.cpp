#include <iostream>

using namespace std;

class MATRIX
{
public:
	int a[3][3];
	MATRIX()
	{
		cout << "Введите матрицу \n";
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				cin >> a[i][j];
	}
	MATRIX(int c)
	{
		for (int i = 0; i<3; i++)
			for (int j = 0; j<3; j++)
				a[i][j] = c;
	}
	MATRIX operator +(MATRIX b)
	{
		MATRIX c(0);
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				c.a[i][j] = this->a[i][j] + b.a[i][j];
		return c;
	}
	MATRIX operator -(MATRIX b)
	{
		MATRIX c(0);
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				c.a[i][j] = this->a[i][j] - b.a[i][j];
		return c;
	}
	MATRIX operator *(MATRIX b)
	{
		MATRIX c(0);
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					c.a[i][j] += this->a[i][k] * b.a[k][j];
		return c;
	}
	int det()
	{
		return a[0][0] * a[1][1] * a[2][2] + a[1][0] * a[2][1] * a[0][2] + a[0][1] * a[1][2] * a[2][0] - a[2][0] * a[1][1] * a[0][2] - a[1][0] * a[0][1] * a[2][2] - a[2][1] * a[1][2] * a[0][0];
	}
};

int main()
{
	setlocale(0, "");
	MATRIX x;
	MATRIX y;
	MATRIX z(0);
	int r;
	while (true)
	{
		cout << "Введите номер операции:\n1) Сложение матриц\n2)Разность матриц\n3) Умножение матриц\nВведите 0, чтобы выйти\n";
		cin >> r;
		switch (r)
		{
		case (1):
		{
			z = x + y;
			break;
		}
		case (2):
		{
			z = x - y;
			break;
		}
		case (3):
		{
			z = x*y;
			break;
		}
		case (0):
		{
			return 0;
		}
		}
		system("cls");
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
				cout << z.a[i][j] << " ";
			cout << "\n";
		}
		cout << "\ Определитель результата =" << z.det() << "\n\n";
		system("pause");
	}
	return 0;
}