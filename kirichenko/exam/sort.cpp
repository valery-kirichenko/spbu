#include <iostream>
#include <vector>
#include <algorithm>

void PrintVector(std::vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

void BubbleSort(std::vector<int> &v) {
	bool sorted = false;
	int cycles = 1;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < v.size() - cycles; i++) {
			if (v[i] > v[i + 1]) {
				std::swap(v[i], v[i + 1]);
				sorted = false;
			}
		}
		cycles++;
	}
}

void SelectionSort(std::vector<int> &v) {
	for (int i = 0; i < v.size() - 1; i++) {
		int min = v[i], index = i;
		for (int j = i + 1; j < v.size(); j++) {
			if (v[j] < min) {
				index = j;
				min = v[j];
			}
		}
		if (index != i) std::swap(v[i], v[index]);
	}
}

void InsertionSort(std::vector<int> &v) {
	int x, i, j;

	for (i = 0; i < v.size(); i++) {
		x = v[i];

		for (j = i - 1; j >= 0 && v[j] > x; j--)
			v[j + 1] = v[j];

		v[j + 1] = x;
	}
}

void QuickSort(std::vector<int> &v, int from, int to) {
	int l = from, r = to;
	int piv = v[(l + r) / 2];
	while (l <= r) {
		while (v[l] < piv)
			l++;
		while (v[r] > piv)
			r--;
		if (l <= r)
			std::swap(v[l++], v[r--]);
	}
	if (from < r)
		QuickSort(v, from, r);
	if (to > l)
		QuickSort(v, l, to);
}

int LinearSearch(std::vector<int> &v, int el) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == el) return i;
	}

	return -1;
}

int main() {
	std::vector<int> a = {1, 0, 2, 4, 1, 2, 7, 6};
	PrintVector(a);
	QuickSort(a, 0, a.size() - 1);
	PrintVector(a);

	return 0;
}
