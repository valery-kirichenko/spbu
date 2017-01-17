// Vse_prevse.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
const int n = 5; int a[n];
using namespace std;

void sort()
{
	for (int i = 0; i < n-1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
}
void poisk( int x)
{
	vector <int> e; int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x) { e.resize(k + 1); e[k] = i;k++; }
	}
	if (k != 0) {
		cout << "Znachenie naideno pod nomerami - ";
		for (int i = 0; i < k; i++)
		{
			cout << e[i] << " ";
		}
	}
	else cout << "Znachenie ne naideno";
	cout << "\n";
}
void print()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}
void poisk2(int x)
{
	int k = 0; sort(); print(); int first = 0; int last = n - 1; int cen = 0;
	while (first < last)
	{
		cen = first + (last - first) / 2;
		if (x <= a[cen])
			last = cen;
		else first = cen + 1;
	}
	if (a[last]==x) {
		cout << "Znachenie naideno pod nomerom - "<<last+1;
	}
	else cout << "Znachenie ne naideno";
	cout << "\n";
}

void quick_sort(int f ,int n)
{
		int x = a[f + (n-1 - f) / 2];
		int i = f;
		int j = n - 1;
		while (i <= j)
		{
			while (a[i] < x)i++;
			while (a[j] > x)j--;
			if (i <= j)
			{
				swap(a[i], a[j]); i++; j--;
			}
		}
		if (i < n) quick_sort(i, n);
		if (f < j) quick_sort(f, j);
}
void sort_by_enter()
{
	int k;
	for (int i = 1; i < n; i++)
	{
		k = i;
		for (int j = k - 1; j >= 0;j--)
		{
			if (a[j] > a[k])
			{
				swap(a[j], a[k]);
				k = j;
			}
		}
	}
}
int lookfor(int i)
{
	int min = a[i]; int k=i;
	for (i; i < n;i++)
	{
		if (a[i] < min)
		{
			min = a[i]; k = i;
		}
	}
	return k;
}
void sort_by_choose()
{
	for (int i = 0; i < n; i++)
	{
		swap(a[lookfor(i)],a[i]);
	}
}


int main()
{
	cout << "Vvedite massiv iz 5 elementov - "; 
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "\n";
	int k = 0;
	while (k != 7)
	{
		system("cls");
		cout << "Viberite deystvie s ciklom \n1 - Lineinii poisk\n2 - Binarnii poisk\n3 - Sortirovka pysir'kom\n4 - Bistroi sortirovkoi\n5 - Sortirovka viborom\n6 - Sortirovka vstavkoi\n7 - Vihod\n";
		cin >> k;
		switch (k)
		{
		case 1: 
		{
			cout << "Vvedite znahenie dlya poiska - "; int x; cin >> x;
			poisk(x); break;
		}
		case 2:
		{
			cout << "Vvedite znahenie dlya poiska - "; int x; cin >> x;
			poisk2(x); break;
		}
		case 3:
		{
			sort(); print(); system("pause"); break;
		}
		case 4:
		{
			print();quick_sort(0, n); print();system("pause"); break;
		}
		case 5:
		{
			print(); sort_by_choose(); print(); system("pause"); break;
		}
		case 6:
		{
			print(); sort_by_enter(); print(); system("pause"); break;
		}
		}
	}
	
	system("pause");
    return 0;
}

