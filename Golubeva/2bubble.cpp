#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;


int main()
{
	srand( time( 0 ) );
	const int n=10; bool m; int c;
	int a[n];
	for (int i=0; i<n; i++)
	{
		a[i]=rand() % 100 - rand() % 100;
	}
	for (int i=0; i<n; i++)
	{
		cout << a[i] <<" ";
	}
	cout <<endl;
	m=false;
	while (m!=true)
	{
		m=true;
		for (int i=0; i<n; i++)
		{
			if(a[i]<a[i+1])
			{
				c=a[i];
				a[i]=a[i+1];
				a[i+1]=c;
				m=false;
			}
		
		}
	}
	for (int i=0; i<n; i++)
	{
		cout << a[i] <<" ";
	}
	system ("pause");
	return 0;
}

