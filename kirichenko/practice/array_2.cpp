#include <iostream>

int main()
{
	int m, n;
	std::cout << "Введите размер массива: ";
	std::cin >> m >> n;
	int a[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << "Введите элемент массива " << i << " " << j << ": ";
			std::cin >> a[i][j];
		}
	}

	int action, x, y, min, t;
	bool working = true;

	while(working) {
		std::cout << "1. Определить номер минимального положительного элемента массива\n" <<
					 "2. Определить значение элемента массива по его индексу\n" <<
					 "3. Поменять местами строки массива\n" <<
					 "4. Поменять местами первый и последний столбцы\n" <<
					 "5. Выход\n";

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << a[i][j] << " ";
			}
			std::cout << std::endl;	
		}
		std::cout << "Выберите действие: ";
		std::cin >> action;

		switch (action) {
			case 1:
				min = -1;
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						if (a[i][j] > 0 && (a[i][j] < min || min == -1)) {
							x = j;
							y = i;
							min = a[i][j];
						}
					}
				}
				if (min == -1) std::cout << "Нет положительных элементов в массиве" << std::endl;
				else std::cout << "Минимальный положительный элемент находится по координатам (" << y << ", " << x << ")\n";
				break;
			case 2:
				std::cout << "Введите индексы x, y: ";
				std::cin >> x >> y;
				if (x >= m || y >= n || x < 0 || y < 0) std::cout << "Неправильные индексы" << std::endl;
				else std::cout << "(" << x << ", " << y << ") = " << a[x][y] << std::endl;
				break;
			case 3:
				std::cout << "Введите номера строк: ";
				std::cin >> x >> y;
				if (x > m || y > m) std::cout << "Таких(ой) строк(и) нет в массиве" << std::endl;
				else {
					x--;
					y--;
					for (int i = 0; i < n; i++) {
						t = a[x][i];
						a[x][i] = a[y][i];
						a[y][i] = t;
					}
				}
				break;
			case 4:
				x = 0;
				y = n - 1;
				for (int i = 0; i < m; i++) {
					t = a[i][x];
					a[i][x] = a[i][y];
					a[i][y] = t;
				}
				break;
			case 5:
				working = false;
				break;
			default:
				std::cout << "Команда не найдена\n";
				break;
		}

	}
	return 0;
}