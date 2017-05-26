// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int Maximum(int a, int b){
	if (a > b) return a;
		else   return b; 
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	int Max;
	int a;
	int b;
	cin >> a >> b;
	Max = Maximum(a,b);
	cout << "Maximum is : " << Max << endl;
	system("pause");
	return 0;
}

