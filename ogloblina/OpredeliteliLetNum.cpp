// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;


int main()
{
	char c='C';
	cout << "Enter" << endl;
	c = _getche(); 
	cin >> c;   
			if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
		{
			cout << "Its number" << endl;
		}
		else
			cout << "Its letter" << endl;
	system("pause");
    return 0;
}

