#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;
 
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

int Search_Binary (int a[], int l, int r, int x)
{
	int m = 0;
	while (1)
	{
		m = (l + r) / 2;
		
		if (x > a[m])      
			r = m - 1;      
		else if (x < a[m])  
			l = m + 1;	   
		else                       
			return m;          
 
		if (l > r)         
			return -1;
	}
}

int main()
{
	srand( time( 0 ) ); 
	const int n=10; int a[n];
	for (int i=0; i<n; i++)
	{a[i]=rand() % 100 - rand() % 100;}

	quickSort(a,0,n);

	for (int i=0; i<n; i++)
	{cout << a[i] <<" ";}
	cout <<endl;

    int num, s;
	cout << "Search: ";
	cin >> s;
	num = Search_Binary (a, 0, n, s);
	if (num >= 0) 
		cout << "Index: " << num << "\n\n";
	else
		cout << "Not found\n\n";
    system("pause");
    return 0;
} 
