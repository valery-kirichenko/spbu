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
	cout << endl;
	int i,j,k;

	cout << "Enter i and j: ";
	cin >> i >> j;
	cout << "Numbers in the interval: ";
	for_each(vec.begin(), vec.end(),[i,j](int _n) {
	if (i<_n && _n<j)
		cout << _n <<" ";}); 
	cout << endl;

	k=count_if(vec.begin(),vec.end(),[i,j](int n) {return i<n && n<j;});
	cout << k << endl;

	system("pause");
	return 0;
}

