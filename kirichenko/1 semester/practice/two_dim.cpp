#include <iostream>

int main() {
	int m;
	std::cout << "Введите порядок матрицы: ";
	std::cin >> m;

	int matrix[m][m];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << "(" << i << ", " << j << "): ";
			std::cin >> matrix[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	int to = 0, el = 0;
	while (el < m * m) {
		for (int i = 0; i < m - to; i++) {
			std::cout << matrix[to][i] << " ";
			el++;
		}
		std::cout << std::endl;
		for (int i = to + 1; i < m; i++) {
			std::cout << matrix[i][m - 1 - to] << " ";
			el++;
		}
		std::cout << std::endl;
		to++;
	}

	return 0;
}