#include <iostream>

void print_matrix(int matrix[][2]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

int main() {
	int matrix1[2][2], matrix2[2][2], result[2][2];

	std::cout << "Введите элементы 1 матрицы:" << std::endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << i + 1<< " строка, " << j + 1 << " столбец: ";
			std::cin >> matrix1[i][j];
		}
	}

	std::cout << "Введите элементы 2 матрицы:" << std::endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << i + 1 << " строка, " << j + 1 << " столбец: ";
			std::cin >> matrix2[i][j];
		}
	}

	std::cout << "1 матрица:" << std::endl;
	print_matrix(matrix1);
	std::cout << std::endl;
	std::cout << "2 матрица:" << std::endl;
	print_matrix(matrix2);

	int action, det;
	bool r = false, working = true;
	while (working) {
		std::cout << "Выберите действие:\n" <<
					 "1. Перемножить матрицы\n" <<
					 "2. Сложить матрицы\n" <<
					 "3. Вычесть из первой матрицы вторую\n" <<
					 "4. Посчитать определитель результата\n" <<
					 "5. Выход\n";
		std::cin >> action;

		switch (action) {
			case 1:
				result[0][0] = matrix1[0][0]*matrix2[0][0] + matrix1[0][1]*matrix2[1][0];
				result[0][1] = matrix1[0][0]*matrix2[0][1] + matrix1[0][1]*matrix2[1][1];
				result[1][0] = matrix1[1][0]*matrix2[0][0] + matrix1[1][1]*matrix2[1][0];
				result[1][1] = matrix1[1][0]*matrix2[0][1] + matrix1[1][1]*matrix2[1][1];
				std::cout << "\nРезультат:\n";
				r = true;
				print_matrix(result);
				break;
			case 2:
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						result[i][j] = matrix1[i][j] + matrix2[i][j];
					}
				}
				std::cout << "\nРезультат:\n";
				r = true;
				print_matrix(result);
				break;
			case 3:
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						result[i][j] = matrix1[i][j] - matrix2[i][j];
					}
				}
				std::cout << "\nРезультат:\n";
				r = true;
				print_matrix(result);
				break;
			case 4:
				if (!r) {
					std::cout << "Сначала необходимо сделать одно из первых трех действий" << std::endl;
					break;
				}
				det = result[0][0]*result[1][1] - result[0][1]*result[1][0];
				std::cout << "Определитель матрицы" << std::endl;
				print_matrix(result);
				std::cout << "Равен " << det << std::endl;
				break;
			case 5:
				working = false;
				break;
			default:
				std::cout << "Команда не найдена" << std::endl;
				break;

		}
	}
	return 0;
}