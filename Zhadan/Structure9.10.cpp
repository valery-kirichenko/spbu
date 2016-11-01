#include "stdafx.h"
#include "iostream"
#include <fstream>
#include <string>
#include <algorithm>   
using namespace std;
const int q = 4;

struct Pharmacy
{
	int number;
	string name;
	int k;
	int price;
	int d, m, y;
	int srok;
};


void out(Pharmacy &A)
{
	cout << "Номер аптеки: " << A.number << endl;
	cout << "Название препарата: " << A.name << endl;
	cout << "Количество: " << A.k << endl;	
	cout << "Цена за упаковку: " << A.price << endl;
	cout << "Дата поступления: " << A.d << " " << A.m << " " << A.y << endl;
	cout << "Срок хранения: " << A.srok << endl << endl;
}

bool Number(Pharmacy &A, Pharmacy &B)
{
	return A.number < B.number;
};

bool z(Pharmacy &A, Pharmacy &B, int &i, int &min)
{

	bool n = 0;
	if (unsigned(A.name[i]) > unsigned(B.name[i])) n = 1;
	else if ((unsigned(A.name[i]) == unsigned(B.name[i]))&(i<min))
	{
		i++;
		z(A, B, i, min);
	}
	return n;
};

bool Name(Pharmacy &A, Pharmacy &B)
{
	int i = 1;
	bool n = 0;	
	int min = 0;
	if (A.name.length() < B.name.length()) min = A.name.length();
	else min = B.name.length();
	n = z(A, B, i, min);
	return n;
};



bool Data(Pharmacy &A, Pharmacy &B)
{
	return (A.y < B.y) | ((A.y == B.y)&(A.m < B.m)) | ((A.y == B.y)&(A.m == B.m)&(A.d < B.d));
};

int main()
{
	string a;
	char v='0';
	setlocale(LC_ALL, "Russian");
	Pharmacy mas[q];
	
	ifstream in("input.txt");
	
	
	for (int i = 0; i < q; i++)
	{
		in >> mas[i].number;
		getline(in, a);
		getline(in, mas[i].name);
		in >> mas[i].k;
		getline(in, a);
		in >> mas[i].price;
		getline(in, a);
		in >> mas[i].d;
		in >> mas[i].m;
		in >> mas[i].y;
		getline(in, a);
		in >> mas[i].srok;
		getline(in, a);
	};
	in.close();

	
	for (int i = 0; i < q; i++)
	{
		out(mas[i]);
	};

	while (v != '4')
	{
		cout << "Выберете тип сортировки: \n";
		cout << "1) По номеру аптеки \n";
		cout << "2) По наименованию препарата \n";
		cout << "3) По дате поступления \n";
		cout << "4) Выход \n";
		cin >> v;
		system("cls");

		switch (v)
		{
		case '1':
			sort(mas, mas + q, Number);

			for (int i = 0; i < q; i++)
			{
				out(mas[i]);
			};
			break;
		case '2':
			sort(mas, mas + q, Name);

			for (int i = 0; i < q; i++)
			{
				out(mas[i]);
			};
			break;
		case '3':
			sort(mas, mas + q, Data);

			for (int i = 0; i < q; i++)
			{
				out(mas[i]);
			};

			break;
		}

		system("pause");
		system("cls");
	}

	return 0;
}