#include "stdafx.h"
#include <iostream>

using namespace std;

template <typename T>
void out(const T*a, int b)
{
	for (int i = 0; i < b; i++)
		cout << a[i] << " ";
	cout << endl;
}

template <typename T>
void sort(T*a, int b)
{
	T c;
	for (int i = 0; i < b; i++)
		for (int j = b - 1; j > i; j--)
			if (a[j] < a[j - 1])
			{
				c = a[j];
				a[j] = a[j - 1];
				a[j - 1] = c;

			}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int a[10];
	cout << "¬ведите массив из 10 элементов \n";
	
	for (int i = 0; i < 10; i++)
		cin >> a[i];

	out(a, 10);
	sort(a, 10);
	out(a, 10);
	system("pause");
	return 0;
}