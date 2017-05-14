#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
    int a = 0, b = 0;
	cout << "Calculator v 0.1" << endl;
	cout << "Please, entry two numbers (!Programm works with only integers!):" << endl;
	cin >> a >> b;
	cout << "Plus : " << a << " + " << b << " = " << a + b << endl;
	cout << "Minus : " << a << " - " << b << " = " << a - b << endl;
	cout << "Multiplication : " << a << " * " << b << " = " << a * b << endl;
	cout << "Division : " << a << " / " << b << " = " << a / b << endl;
	cout << "Remainder of the division : "  << a << " % " << b << " = " << a % b << endl;
	system("pause");
	return 0;
}
