// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	int a, b, c;
	cin >> a >> b;
	try{
		if (b==0) throw 1;
			else cout << a/b << endl;
	}catch (int i){ 
		cout << "Error " << i << endl;
	}
	system("pause");
	return 0;
}

