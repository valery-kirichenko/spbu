#include "stdafx.h"
#include <iostream>

using namespace std;

template <typename T>
void A(const T*a, int b)
{
	for (int i = 0; i < b; i++)
		cout << a[i] << " ";
	cout << "\n";
}

template <typename T>
void B( T*a, int b)
{
	for (int i = 0; i < b; i++)
		for (int j = b - 1; j > i; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}


int main()
{
	int a[5];
	cout << "Vvedite massiv iz 5 elementov \n";
	for (int i = 0; i < 5; i++)
		cin >> a[i];
	A(a, 5);
	B(a, 5);
	A(a, 5);
	system("pause");
    return 0;
}

