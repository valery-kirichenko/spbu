#pragma once
#ifndef SORT_H
#define SORT_H

//Сортировка пузырьком.
template <typename SOB>
void bubbleSort(SOB  *arr, unsigned int size, int in_ascending)
{
	if (size == 0)
		std::cout << "\nArray is empty!\n";
	else if ((in_ascending == 0) || (in_ascending == 1)) {
		SOB *temp = new SOB;
		for (unsigned int i = 0; i < size; i++)
			for (unsigned int j = i; j < size; j++)
				if (((arr[i] > arr[j]) && (in_ascending == 1)) || ((arr[i] < arr[j]) && (in_ascending == 0))) {
					*temp = arr[i];
					arr[i] = arr[j];
					arr[j] = *temp;
				}
		delete temp;
	}
	else
		std::cout << "\nFunction got bad parameters!\n";
}

//Сортировка выбором.
template <typename SOC>
void choicesSort(SOC *arr, unsigned int size, int in_ascending)
{
	if (size == 0)
		std::cout << "\nArray is empty!\n";
	else if ((in_ascending == 0) || (in_ascending == 1)) {
		SOC *temp = new SOC;
		for (unsigned int repeat_counter = 0; repeat_counter < size; repeat_counter++) {
			*temp = arr[0];
			for (unsigned int element_counter = repeat_counter + 1; element_counter < size; element_counter++) {
				if (((arr[repeat_counter] > arr[element_counter]) && (in_ascending == 1)) || ((arr[repeat_counter] < arr[element_counter]) && (in_ascending == 0))) {
					*temp = arr[repeat_counter];
					arr[repeat_counter] = arr[element_counter];
					arr[element_counter] = *temp;
				}
			}
		}
		delete temp;
	}
	else
		std::cout << "\nFunction got bad parameters!\n";
}

//Сортировка вставками.
template <typename SOI>
void insertionSort(SOI *arr, unsigned int size, int in_ascending)
{
	if (size == 0)
		std::cout << "\nArray is empty!\n";
	else if ((in_ascending == 0) || (in_ascending == 1)) {
		SOI *temp = new SOI;
		int pred;
		for (unsigned int counter = 1; counter < size; counter++) {
			*temp = arr[counter];
			pred = counter - 1;
			while (((pred >= 0) && (arr[pred] > *temp) && (in_ascending == 1)) || ((pred >= 0) && (arr[pred] < *temp) && (in_ascending == 0))) {
				arr[pred + 1] = arr[pred];
				arr[pred] = *temp;
				pred--;
			}
		}
		delete temp;
	}
	else
		std::cout << "\nFunction got bad parameters!\n";
}

//Быстрая сортировка.
template <typename SOQ>
void quickSort(int l, int r, SOQ *arr, int in_ascending)
{
	if ((in_ascending == 0) || (in_ascending == 1)) {
		SOQ x = arr[l + (r - l) / 2], *temp = new SOQ;
		int i = l, j = r;
		while (i <= j) {
			while (((arr[i] < x) && (in_ascending == 1)) || ((arr[i] > x) && (in_ascending == 0)))
				i++;
			while (((arr[j] > x) && (in_ascending == 1)) || ((arr[j] < x) && (in_ascending == 0)))
				j--;
			if (i <= j) {
				*temp = arr[i];
				arr[i] = arr[j];
				arr[j] = *temp;
				i++;
				j--;
			}
		}
		if (i < r)
			quickSort(i, r, arr, in_ascending);
		if (l < j)
			quickSort(l, j, arr, in_ascending);
		delete temp;
	}
	else
		std::cout << "\nFunction got bad parameters!\n";
}

#endif /* SORT_H */