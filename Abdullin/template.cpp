// 1111.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
template <typename T>
void A (const T *a, int b)
{
	for (int i = 0; i < b; i++)
	{
		cout << a[i] << " ";
	}
}
template <typename T>
void B(T *a, int b)
{
	for (int i = 0; i < b-1; i++)
		for (int j = 0; j < b-i - 1; j++)
			if (a[j] < a[j + 1]) swap(a[j], a[j + 1]);
	
}

int main()
{
	const int b = 5;
	int a[b];
	char c[b];
	for (int i = 0; i < b; i++)
		cin >> a[i];
	for (int i = 0; i < b; i++)
		cin >> c[i];
	B(a, b); B(c, b);
	A(a, b); A(c, b);
	system("pause");
    return 0;
}

