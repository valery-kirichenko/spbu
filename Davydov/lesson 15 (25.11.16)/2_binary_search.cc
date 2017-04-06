#include <iostream>
using namespace std;
 
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
void Search_Binary (T a[], int left, int right)
{
	int number; 
	int midd = 0;

	choice(a, right-left+1);
	for (int i = left; i < right+1; i++)
	{
		cout << a[i] << " ";
	}
	cout<<"\n\n";
	cout << "Enter your count: ";
	cin >> number;

	while (true)
	{
		midd = (left + right) / 2;
		
		if (number < a[midd]) right = midd - 1;
		else if (number > a[midd]) left = midd + 1;
		else {cout <<"There is this number.\n"; return;}
		if (left > right) {cout <<"There is not this number.\n"; return;}
	}
}
 
int main()
{
	int N = 0;

	while (N <= 0)
	{
	cout<<"Enter the number of elements in array: ";
	cin>>N;
	if (N <= 0) cout<<"Wrong number.\n";
	}
	int *a = new int [N];
 
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % N+10 - 10;
		cout << a[i] << " ";
	}
	cout<<"\n\n";
	
	Search_Binary (a, 0, N-1);
		
	system("pause");
	return 0;
}