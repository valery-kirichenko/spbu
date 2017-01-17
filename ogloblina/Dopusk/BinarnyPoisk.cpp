// BinarnyPoisk.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{	const int size=10;
	int a[size]={-5, -4, -3, -2, -1, 0, 1, 2, 3, 4};
	int average_index = 0, 
         first_index = 0, 
       last_index = size -1;

	int search_value = 1;
      while (first_index < last_index)
    {
        average_index = first_index + (last_index - first_index) / 2; 
        search_value <= a[average_index] ? last_index = average_index : first_index = average_index + 1;    
    }
    if ( a[last_index] == search_value)
        cout << "value is found" << endl <<"index = " << last_index << endl;
    else
        cout << "value is not found" << endl;
    system("pause");




	return 0;
}

