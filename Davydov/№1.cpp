// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int main()
{
	
	vector<int> v;
	v.reserve(10);
	v.resize(10);
	int i;

	for (i=0; i < v.size(); i++)
		cout<<v[i]<<endl;

	system("pause");
	return 0;
}


