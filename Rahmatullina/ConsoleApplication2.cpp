// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   int a;
	cout<<"ВВедите первое число"<<endl;
    cin>>a;
	cout<<"ВВедите знак"<<endl;
	char z;
	cin>>z;
	int b;
	cout<<"Введите второе число"<<endl;
	cin>>b;
	int c;
	if (z=='+') c=a+b;
	if (z=='*') c=a*b;
	if (z=='-') c=a-b;
    if (z=='/') c=a/b;
	if (z=='%') c=a%b;
	cout<<"c="<<c;
   
    return 0;
}

