// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>;

using namespace std;

template <typename T>
void out( const T *a, int b)
{
	for(int i=0;i<b;i++)
	{
		cout << a[i] << " ";
	};

};


int main()
{
	int a[5]={1,2,3,4,5};
	int b=5;
	out(a,b);
	
	system("pause");
	return 0;
}

