#include "stdafx.h"
#include <iostream>
#include <algorithm>  
#include <vector>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	vector <int> vec;
	for(int i=0;i<10;i++)
		 vec.push_back(i); 
	for_each(vec.begin(), vec.end(),[](int _n) {
	cout << _n <<" ";}); 
	system("pause");
	return 0;
}

