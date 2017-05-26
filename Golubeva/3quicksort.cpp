#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

int a[100];
void quickSort(int *a, int l, int r)
{
    int x=a[l+(r-l)/2];
    int i=l;
    int j=r;
    while(i<=j)
    {
        while(a[i]>x) i++;
        while(a[j]<x) j--;
        if(i<=j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (i<r)
                quickSort(a, i, r);
    if (l<j)    
        quickSort(a, l, j);    
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
    quickSort(a, 0, n-1);
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }        
	system ("pause");
    return 0;
}
