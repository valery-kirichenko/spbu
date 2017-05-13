// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{   int i,j;
	cout<<"Enter i,j"<<endl;
	cin >> i >> j;
	try
	{ if(j==0) {throw 5;}}
	catch(int k)
	{cout << "Error "<< k << " can not to devide on zero";}

	cout<<"devide="<<i/j;
	return 0;
}

