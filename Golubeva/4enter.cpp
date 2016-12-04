#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
srand( time( 0 ) );
	const int n=10;int c;
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
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
		c=a[i]; a[i]=a[min];a[min]=c;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
	system("pause");
    return 0;
}
