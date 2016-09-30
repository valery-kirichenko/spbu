// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int a, b, c;
	cout << "Enter the first number" << endl;
	cin >> a;
	cout << "Enter the second number" << endl;
	cin >> b;
	cout << "Select action" << endl << "1 addition" << endl << "2 subtraction" << endl << "3 multiplication" << endl << "4 division" << endl;
	cin >> c;
	switch (c)
	{
	case 1 :
		cout << a + b << endl;
		break;
	case 2 :
		cout << a - b << endl;
		break;
	case 3 :
			cout << a*b << endl;
			break;
	case 4:
			cout << a / b << endl;
			break;
	}
    return 0;
}

