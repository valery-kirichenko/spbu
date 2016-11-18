#include <iostream>

template <typename T>
void print_array (T *array, int size) {
	for (int i = 0; i < size; i++) std::cout << array[i] << " ";
	std::cout << std::endl;
}

template <typename T>
void sort_array(T *array, int size) {
	bool not_sorted = true;
	T temp;
	while (not_sorted) {
		not_sorted = false;
		for (int i = 0; i < size - 1; i++) {
			if (array[i] > array[i + 1]) {
				T temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				not_sorted = true;
			}
		}
	}
}

int main() {
	const int size = 10;
	int a[size];

	for (int i = 0; i < size; i++)
		std::cin >> a[i];

	print_array(a, size);

	sort_array(a, size);

	print_array(a, size);

	return 0;
}