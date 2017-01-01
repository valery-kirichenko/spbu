#pragma once
#ifndef SEARCH_H
#define SEARCH_H

//Ћинейный поиск.
template <typename SEL>
int linSearch(SEL *arr, SEL key, unsigned int size)
{
	if (size == 0) {
		std::cout << "\nArray is empty!\n";
		return -1;
	}
	for (unsigned int i = 0; i < size; i++)
		if (key == arr[i])
			return i;
	return -1;
}

//Ѕинарный поиск.
template <typename SEB>
int binSearch(SEB *arr, SEB key, unsigned int size)
{
	int average_index = 0, first_index = 0, last_index = size - 1;
	if (last_index == -1) {
		std::cout << "\nArray is empty!\n";
		return -1;
	}
	while (first_index < last_index) {
		average_index = first_index + (last_index - first_index) / 2;
		if (key <= arr[average_index])
			last_index = average_index;
		else
			first_index = average_index + 1;
		//key <= arr[average_index] ? last_index = average_index : first_index = average_index + 1;
	}
	if (arr[last_index] == key)
		return last_index;
	else
		return -1;
}

#endif /* SEARCH_H */