#include <iostream>

int main() {
	int m, n;
	std::cout << "Размер массива: ";
	std::cin >> m >> n;

	int **b = new int *[m];

	for (int j = 0; j < m; j++) {
		b[j] = new int[n];
		for (int i = 0; i < n; i++) {
			std::cin >> b[j][i];
		}

	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			std::cout << b[j][i] << "\t";
		}
		std::cout << std::endl;
	}
	

	return 0;
}