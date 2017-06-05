// Win32Project4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int maxx(int a, int b);
int maxx(int a, int b)
{
	if (a>b)
		cout<<a;
	else
		cout<<b;
	return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a,b;
	cout<<"VVedite dva chisla ";
	cin>>a>>b;
	maxx(a,b);
	system("pause");
	return 0;
}

