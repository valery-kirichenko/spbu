#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

template <typename T>
void generate(T *a, int n)
{
	for (int i=0; i<n; i++) {a[i] = rand()%100 - 50;}
}
template <typename T>
void show(T *a, int n)
{
	for (int i=0; i<n; i++) {cout<<a[i]<<" ";}
	cout<<"\n\n";
}
template <typename T>
void original(T *a, int n)
{
	cout<<"--------------------------------------------------------------------------------\n";
	cout<<"The original array:\n";
	generate(a, n);
	show(a, n);
}

template <typename T>
void choice(T *a, int n)
{
	int i, j;
	T t;

	for (i=0; i<n-1; i++)
		for (j=i+1; j<n; j++)
			if (a[i]>a[j]) 
			{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			}
}

template <typename T>
void qsort(T *a, int begin, int end)
{
	int x = begin;
	int y = end;
	T t;
	T support = a[(x+y)/2];
	
	while (x < y)
	{
	while (a[x]<support) x++;
	while (a[y]>support) y--;	
	if (x <= y)
		{
		t = a[x];
		a[x] = a[y];
		a[y] = t;
		x++;
		y--;
		}
	} 
	if (y > begin) qsort(a, begin, y);
	if (x < end) qsort(a, x, end);
}

template <typename T>
void bubble(T *a, int n)
{
 int temp = 0;
 bool flug = false;
 
 while (!flug)
 {
	flug = true;
	for (int i = 0; i < (n-1); i++)
	{
		if (a[i] > a[i+1]) {temp = a[i]; a[i] = a[i+1]; a[i+1] = temp; flug = false;}
	}
 }
}
template <typename T>
void insert(T *a, int n)
{
	T t;

	for (int i = 1; i<n; i++)
	{
		t = a[i];
		for (int j = i-1; j>=0; j--)
		{
			if (a[j] > t) {a[j+1] = a[j]; a[j] = t; }
		}
	}
}

int main()
{
	int n = 20;
	int *a = new int [n];

	srand(time(NULL));
	cout<<"Welcome to sorter of arrays.\n";

	original(a, n);
	cout<<"The array, which was sorted by method of 'choice':\n";
	choice(a, n);
	show(a, n);

	original(a, n);
	cout<<"The array, which was sorted by 'quick sort':\n";
	qsort(a, 0, n-1);
	show(a, n);

	original(a, n);
	cout<<"The array, which was sorted by method of 'bubble':\n";
	bubble(a, n);
	show(a, n);

	original(a, n);
	cout<<"The array, which was sorted by method of 'insert':\n";
	insert(a, n);
	show(a, n);

	system("pause");
	return 0;
}