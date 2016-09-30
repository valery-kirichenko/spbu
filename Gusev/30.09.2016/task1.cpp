// problem1!.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <math.h>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL,"rus");
	vector<int> A;
	int n,a;
	cout<<"insert size of array\n";
	cin>>n;
	cout<<"insert array\n";
	for(int i=0;i<n;i++){
		cin>>a;
		A.push_back(a);
	}
	copy( A.begin(), A.end(), ostream_iterator<int>(cout," "));
	_getch();
	return 0;
}
