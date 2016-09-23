// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	int a,c;
	char b;

	cout << "Vvedite primer" << endl;
    cin >> a;
    cin >> b;
	cin >> c;

	switch ( b )
	{	case '+':
			a=a+c;
			break;
		case '-':
			a=a-c;
			break;
		case '*':
			a=a*c;
			break;
		case '/':
			a=a/c;
			break;
		case '%':
			a=a%c;
			break;
		default:
			break;
	}

	cout << a ;
	
	return 0;
}

