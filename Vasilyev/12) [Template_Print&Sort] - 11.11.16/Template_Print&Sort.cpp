#include "stdafx.h"
#include <iostream>
#include <string>

template <typename T>
void printArray(const T *array, const int count)
{
	for (int i = 0; i < count; i++)
		std::cout << array[i] << "   ";
	std::cout << std::endl;
}

template <typename P>
void sortArray(P  *arr, const int count)
{
	int *temp = new int;
	for (int i = 0; i < count; i++)
		for (int j = i; j < count; j++)
			if (arr[i] > arr[j]) {
				*temp = arr[i];
				arr[i] = arr[j];
				arr[j] = *temp;
			}
	delete temp;
}

int main()
{
	const int n = 10;
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
		//arr[i] = n - i;
		std::cin >> arr[i];

	printArray(arr, n);
	
	sortArray(arr, n);

	std::cout << std::endl;
	printArray(arr, n);

	std::cin.get();
	std::system("pause");
	delete arr;
	return 0;
}