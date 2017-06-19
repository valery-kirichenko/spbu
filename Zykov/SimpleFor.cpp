// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < 11; i++){
		cout << i << endl;
	}
	system("pause");
	return 0;
}

