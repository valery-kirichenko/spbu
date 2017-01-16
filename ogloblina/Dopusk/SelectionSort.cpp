// SelectionSort.cpp: определяет точку входа для консольного приложения.
//Сортировка выбором.

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
   cout << "Enter size" << endl;
    int size;
    cin >> size;
	int *a = new int[size];
	for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < size; i++)
    {  int minValueIndex = i;

        for (int j = i + 1; j < size; j++) 
        {   if (a[j] < a[minValueIndex])
            {
                minValueIndex = j;
            }
		}
        swap (a[i], a[minValueIndex]);
    }
	for (int i = 0; i < size; i++)
    {
        cout << a[i] << ' ';
    }
	system("pause");
    return 0;
}





