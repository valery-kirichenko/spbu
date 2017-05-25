#include<iostream>
#include<cstdlib>
using namespace std;

template <typename T>
void show(const T *a, int b)
{
	for (int i=0; i<b; i++)
		cout<<*(a++)<<" ";
	cout<<endl;
}
template <typename T>
void sort(T *a, int b)
{
	T t;
	for (int i=0; i<(b-1); i++)
		for (int j=i; j<b; j++)
			if (a[i]>a[j]) 
			{
			t = a[i];
			a[i]=a[j];
			a[j]=t;
			}
};


int main()
{
	int N;
	char x = 'z';

	while (x != '0')
	{
		do
		{
		cout<<"Enter the number of elements in array: ";
		cin>>N;
		system("cls");
		} while (N<1);
		int *arri = new int[N];
		double *arrd = new double[N];
		char *arrc = new char[N];
		cout<<"Enter 0 - to leave the programm\n";
		cout<<"Enter 1 - to input array of int\n";
		cout<<"Enter 2 - to input array of double\n";
		cout<<"Enter 3 - to input array of char\n";
		cout<<"Your choice: ";
		cin>>x;
		switch (x)
		{
		case ('0'): break;
		case ('1'): 
			for (int i=0; i<N; i++) {cout<<i+1<<" = "; cin>>arri[i];}
			sort(arri, N);
			show(arri, N);
			break;
		case ('2'):
			for (int i=0; i<N; i++) {cout<<i+1<<" = "; cin>>arrd[i];}
			sort(arrd, N);
			show(arrd, N);
			break;
		case ('3'): 
			for (int i=0; i<N; i++) {cout<<i+1<<" = "; cin>>arrc[i];}
			sort(arrc, N);
			show(arrc, N);
			break;
		default: cout<<"Error.\n";
		}
		cout<<"\n";
		delete []arri;
		delete []arrd;
		delete []arrc;
	}
	
	system("pause");
	return 0;
}
