#include <iostream>

int main() {
	int k, n, t, sum = 0;
	std::cout << "Введите K, N: ";
	std::cin >> k >> n;

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			std::cout << "Введите " << j << " элемент " << i << " набора: ";
			std::cin >> t;
			sum += t;
		}
		std::cout << "Сумма элементов " << i << " набора: " << sum << std::endl;
		sum = 0;
	}

	return 0;
}