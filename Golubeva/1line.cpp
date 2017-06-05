#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;


int main()
{
	srand( time( 0 ) );
	const int n=10; int max, min;
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
	max=a[0]; min=a[0];
	for (int i=0; i<n; i++)
	{
				if  (a[i]>max)
				{
					max=a[i];
				}
				if (a[i]<min)
				{
					min=a[i];
				}
	}
	cout << "Maximum: " << max << endl;
	cout << "Minimum: " << min << endl;
	system ("pause");
	return 0;
}

