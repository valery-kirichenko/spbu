// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int a;
	int b;
	cout << "Enter numbers\n";
	cin >> a;
	cin >> b;
	try {
		if (b==0)
			throw 0;
	}
	catch (int)
	{cout << "Division by zero!";
	return 0;}
	cout << "a/b= " << a/b << "\n";
	system ("pause");
	return 0;
}

