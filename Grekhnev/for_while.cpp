// Win32Project5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	char b;
	int a;
	for (int a=0; a<=10; a++)
		cout<<a<<"  ";
	a=65;
	cout<<"\n";
	while (a<=90)
	{
		b=a;
		cout<<b<<"  ";
		a++;
	}
	system("pause");
	return 0;
}


