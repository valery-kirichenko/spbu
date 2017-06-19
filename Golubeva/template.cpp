#include "stdafx.h"
#include <iostream>
using namespace std;

template <typename T>
void sort( T * a, int b)
{
	int m;
	int c=0;
	while (c==0)
	{
	c=1;
    for (int i = 0; i < b-1; i++)
		if (a[i]>a[i+1])
		{
			m=a[i];
			a[i]=a[i+1];
			a[i+1]=m;
			c=0;
		}
	}
}

template <typename T> 
void pr(const T * a, int b) 
{
	for(int i=0; i<b; i++)
	{
		cout << a[i] << ' ';
	}
}

int main()
{
    const int s = 10;
    int    a[s] = {8, 15, 0, -4, 56, 11, 5, 12, 9, 10};
	sort(a, s);
	pr(a,s);
	system ("pause");
    return 0;
}
