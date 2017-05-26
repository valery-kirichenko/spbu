// Win32Project6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int a,b;
	cin>>a>>b;
	try{
		a/b;
	if (b==0) throw 2;
	else cout<<a/b;
	}
	catch (int i){
		cout<<"Error "<<i;
	}

	system("pause");
	return 0;
}

