// Win32Project3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int a,b,n;
	char c,f;
	f=1;
	while (f=1)
	{
	cin>>a;
	cin>>c;
	cin>>b;
	if (c=='+') 
		n=a+b;
	else if (c=='-')
		n=a-b;
	else if (c=='*')
		n=a*b;
	else if (c=='/')
		n=a/b;
	cout<<"="<<n;
	cout<<"\n";
	f=0;
	cout<<"dlya prodolzheniya vvedite '1'";
	cin>>f;

	}


	system("pause");
	return 0;
}

