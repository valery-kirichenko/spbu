// ConsoleApplication7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<iterator>
#include<vector>
using namespace  std;
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int>v(10);
	for (int i=0;i<v.size();i++)
		v[i]=i;
	copy(v.begin(),v.end(), ostream_iterator<int>(cout," "));
	system("pause");
	return 0;
}

