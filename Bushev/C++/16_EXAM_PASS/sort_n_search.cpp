#include "sort_n_search.h"
#include <iostream>

void init_array(vector<int> &v) {
	int size = 0;

	while (size < 1) {
		cout << "Enter array size (> 0): ";
		cin >> size;
	}

	cout << "Fill in your array: ";
	v.resize(size);

	for (int i = 0; i < size; i++) {
		cin >> v[i];
	}
}

void linear_search(vector<int> v) {
	int val;
	bool found = false;

	cout << "Enter value: ";
	cin >> val;

	for (unsigned int i = 0; i < v.size(); i++) {
		if (v[i] == val) {
			cout << "We found " << val << " at [" << (i + 1) << "] position" << endl;
			found = true;
		}
	}

	if (!found) cout << "We can't find " << val << " in array" << endl;
	system("pause");
}

void binary_search(vector<int> v) {
	int val, left = 0, right = v.size() - 1, mid;

	cout << "Enter value: ";
	cin >> val;

	while (right - left > 0) {
		mid = (left + right) / 2;
		if (val <= v[mid]) right = mid;
		else left = mid + 1;
	}

	if (v[right] == val) cout << "We found " << val << " at [" << (right + 1) << "] position" << endl;
	else cout << "We can't find " << val << " in array" << endl;

	system("pause");
}

void quicksort(vector<int> &v, int default_left, int default_right) {
	int left = default_left, right = default_right;
	int mid = v[(left + right) / 2];

	while (left <= right) {
		while (v[left] < mid) ++left;
		while (v[right] > mid) --right;

		if (left <= right) swap(v[left++], v[right--]);
	}

	if (default_left < right) quicksort(v, default_left, right);
	if (left < default_right) quicksort(v, left, default_right);
}

void bubble_sort(vector<int> &v) {
	bool was_swap;

	for (unsigned int i = 0; i < v.size() - 1; i++) {
		was_swap = false;

		for (unsigned int j = 0; j < v.size() - 1 - i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);

				if (j > 0) was_swap = true;
			}
		}

		if (!was_swap) break;
	}
}

void insertion_sort(vector<int> &v) {
	int j, key;

	for (unsigned int i = 1; i < v.size(); i++) {
		j = i;
		key = v[j];

		while (j > 0 && v[j - 1] > key) {
			v[j] = v[j - 1];
			--j;
		}

		v[j] = key;
	}
}

void selection_sort(vector<int> &v) {
	int min;
	for (unsigned int i = 0; i < v.size(); i++) {
		min = i;

		for (unsigned int j = i + 1; j < v.size(); j++) {
			if (v[j] < v[min]) min = j;
		}

		if (min != i) {
			swap(v[min], v[i]);
		}
	}
}