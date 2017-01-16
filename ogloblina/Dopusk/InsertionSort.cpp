// InsertionSort.cpp: определяет точку входа для консольного приложения.
//Сортировка вставками.

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
    {cout << "Enter element of index: " << i << endl;
        cin >> a[i];
    }    
    for (int i = 0; i < size; i++)
    {
        int temp = a[i];
        int j =i-1;
        while(j >= 0 && a[j] > temp)
               {
            a[j + 1] = a[j];
                  j--;
        }
        a[j + 1] = temp;        
    }
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << ' ';
    }
	system ("pause");
    return 0;
}
