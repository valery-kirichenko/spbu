#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int *b = new int [10];
	for (int count = 0; count < 10; count++)
		b[count] = count;
	cout << "array = ";
	for (int count = 0; count < 10; count++)
		cout << " " << b[count] << "  ";
	delete [] b;
	cout << endl;
	system("pause");
	return 0;
}