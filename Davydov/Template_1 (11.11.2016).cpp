#include "stdafx.h"
#include<iostream>
#include<cstdlib>
using namespace std;

const int size = 10;

template <typename T>
void show(const T *a, int b)
{
	for (int i=0; i<b; i++)
		cout<<*(a++)<<" ";
};

int main()
{
	int arr[size];
	for (int i=0; i<size; i++) arr[i]=i;
	show(arr, size);

	system("pause");
	return 0;
}

