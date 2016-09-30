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
	int n,m;
	cout<<"what is size of array?\n";
	cin>>n>>m;
	int **a=new int*[n];
	for(int i=0;i<n;i++)
		a[i]=new int[m];
	cout<<"insert arrsy\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	}
	cout<<"size of array is: "<<n<<" "<<m<<"\narray is:\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
	_getch();
	for(int i=0;i<n;i++)
		delete [] a[i];
	delete[] a;
	return 0;
}
