//#include<stdafx.h>
#include<iostream>
#include<cstdlib>
#include<ctime>

const int k = 10;
class A
{
int count[k];
public:
	A()
	{
		srand(time(NULL));
		for (int i=0; i<k; i++)
		{
			count[i] = rand()%5 + 10;
		}
	}

	void operator() ()
	{
		cout<<"\nЧётные: ";
		for (int i=0; i<k; i++)
		{
			if (count[i] % 2 == 0) cout<<count[i]<<" ";
		}
		cout<<"\nНечётные: ";
		for (int i=0; i<k; i++)
		{
			if (count[i] % 2 != 0) cout<<count[i]<<" ";
		}
	}
};

int main()
{
	A a;
	a();

	system("pause");
	return 0;
}