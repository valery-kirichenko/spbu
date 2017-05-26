// 0712.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
const int n = 5;

class A
{
public:
	int z;
	int a[5] = { 1, 2, 3, 4, 5 };
	A(int z)
	{
		z = 0;
	}
	void operator () ()
	{
		cout << "nechetnie chisla - ";
		for (int i = 0; i < n; i++)
		{
			if (a[i] % 2 != 0) cout << a[i]<<" ";
		}
	}
};


int main()
{
	A a1(5);
	a1 ();
	system("pause");
    return 0;
}

