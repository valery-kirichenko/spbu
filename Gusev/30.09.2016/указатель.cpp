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
	int n;
	cout<<"what is size of array?\n";
	cin>>n;
	int *a=new int[n];
	cout<<"insert arrsy\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"size of array is: "<<n<<"\narray is: ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	_getch();
	delete[] a;
	return 0;
}
