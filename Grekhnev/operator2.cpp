#include "stdafx.h"
#include <iostream>

using namespace std;

class A
{
public:
	int b;
	A() {};
	void operator()(int a[10])
	{
		for (int i=0; i<10; i++)
		if (a[i] % 2 == 1)
			cout << a[i] << " - нечетное число\n";
		else
			cout << a[i] << " - четное число\n";
	}
};


int main()
{
	setlocale(0, "");
	int a[10];
	for (int i = 0; i < 10; i++)
		a[i] = i + 1;
	A v;
	v(a);
	system("pause");
    return 0;
}

