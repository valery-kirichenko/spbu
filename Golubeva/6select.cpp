#include "stdafx.h"
#include <ctime>
#include <iostream>
using namespace std; 

void select(int a[], long n) {
  int i, j, k, x;
  for (i=0; i < n; i++)
  { 
    k=i; x=a[i];
    for (j=i+1; j < n; j++)
      if (a[j] < x) 
	  {
        k=j; x=a[j];
      }
    a[k] = a[i]; a[i] = x; 
  }
}


int main()
{
	srand( time( 0 ) );
	const int n=10; 
	int a[n];
	for (int i=0; i<n; i++)
	{
		a[i]=rand() % 100-rand()%100;
	}
	for (int i=0; i<n; i++)
	{
		cout << a[i] <<" ";
	}
	cout <<endl;
	select(a,n);

	for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }      
	system ("pause");
	return 0;
}

