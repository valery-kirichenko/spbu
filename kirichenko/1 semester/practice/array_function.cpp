#include <iostream>

void do_action(int* a, int n) {
	int last1, last2;
	last1 = a[0];
	last2 = a[1];
	for (int i = 1; i < n - 1; i++) {
		a[i] = (last1 + a[i + 1]) / 2;
		last1 = last2;
		last2 = a[i + 1];
	}
}

int main() {
	int n;
	std::cout << "Введите размер массива: ";
	std::cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		std::cout << "Введите " << i + 1 << " элемент: ";
		std::cin >> a[i];
	}

	do_action(a, n);
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}