#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int **ar2 = new int* [5];
	for (int count = 0; count < 5; count++)
		ar2[count] = new int [5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			ar2[i][j] = i + j;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << " "  << ar2[i][j] << "   ";
		cout << endl;
	}
	for (int count = 0; count < 5; count++)
		delete [] ar2[count];
	system("pause");
	return 0;
}