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
	int mi,ma,sum,n;
	cout<<"insert size of array\n";
	cin>>n;
	int *A = new int[n];
	cout<<"insert array\n";
	for(int i=0;i<n;i++)
		cin>>A[i];
	mi=INT_MAX;
	ma=INT_MIN;
	sum=0;
	for(int i=0;i<n;i++){
		if(mi>A[i])
			mi=A[i];
		if(ma<A[i])
			ma=A[i];
		sum+=A[i];
	}
	system("cls");
	copy(A,A+n,ostream_iterator<int>(cout," "));
	cout<<"\nmin element: "<<mi<<"\nnax element: "<<ma<<"\naverage: "<<(double)(sum)/n;
	_getch();
	delete [] A;
	return 0;
}
