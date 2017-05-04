#include <iostream>

int *a, n = -1;

void fill_array() {
	std::cout << "Введите размер массива: ";
	std::cin >> n;
	if (n < 1) {
		n = -1;
		std::cout << "Неверный ввод" << std::endl;
		return;
	}
	a = new int[n];
	for (int i = 0; i < n; i++) {
		std::cout << "Введите " << i + 1 << " элемент: ";
		std::cin >> a[i];
	}
}

void do_smth() {
	if (n == -1) {
		std::cout << "Сначала необходимо заполнить массив" << std::endl;
		return;
	}

	while (true) {
		int action, count, minVal, minNum, s, num, maxVal, sumEven, sumOdd;
		
		std::cout << "1. Найти количество четных чисел\n" <<
					 "2. Найти номер минимального числа\n" <<
					 "3. Найти количество чисел, равных A\n" <<
					 "4. Найти номер первого отрицательного числа\n" <<
					 "5. Найти максимальное отрицательное число\n" <<
					 "6. Найти количество чисел, меньших первого числа\n" <<
					 "7. Найти разность сумм четных и нечетных чисел\n" <<
					 "8. Назад\n" <<
					 "Выберите действие: ";
		std::cin >> action;
		switch (action) {
			case 1:
				count = 0;
				for (int i = 0; i < n; i++) {
					if (a[i] % 2 == 0) count++;
				}
				if (count == 0) std::cout << "Нет четных чисел";
				else std::cout << "Всего " << count << " четных чисел";
				std::cout << std::endl;
				break;
			case 2:
				minVal = a[0];
				minNum = 0;
				for (int i = 1; i < n; i++) {
					if (a[i] < minVal) {
						minVal = a[i];
						minNum = i;
					}
				}
				std::cout << "Номер минимального числа: " << minNum + 1 << std::endl;
				break;
			case 3:
				count = 0;
				std::cout << "Введите A: ";
				std::cin >> s;
				for (int i = 0; i < n; i++) {
					if (a[i] == s) {
						count++;
					}
				}
				if (count == 0) std::cout << "Нет чисел, равных " << s;
				else std::cout << "Всего " << count << " чисел, равных " << s;
				std::cout << std::endl;
				break;
			case 4:
				num = -1;
				for (int i = 0; i < n; i++) {
					if (a[i] < 0) {
						num = i;
						break;
					}
				}
				if (num == -1) std::cout << "Нет отрицательных чисел";
				else std::cout << "Первое отрицательное число под номером " << num + 1;
				std::cout << std::endl;
				break;
			case 5:
				maxVal = 0;
				for (int i = 0; i < n; i++) {
					if (a[i] < 0 && (a[i] > maxVal || maxVal == 0)) {
						maxVal = a[i];
						break;
					}
				}
				if (maxVal == -1) std::cout << "Нет отрицательных чисел";
				else std::cout << "Максимальное отрицательное число: " << maxVal;
				std::cout << std::endl;
				break;
			case 6:
				count = 0;
				for (int i = 1; i < n; i++) {
					if (a[i] < a[0]) count++;
				}
				if (count == 0) std::cout << "Нет чисел, меньших первого";
				else std::cout << "Всего " << count << " чисел, меньших первого";
				std::cout << std::endl;
				break;
			case 7:
				sumOdd = 0;
				sumEven = 0;
				for (int i = 0; i < n; i++) {
					if (a[i] % 2 == 0) sumEven += a[i];
					else sumOdd += a[i];
				}
				std::cout << "Разность сумм четных и нечетных равна " << sumEven - sumOdd << std::endl;
				break;
			case 8:
				return;
				break;
			default:
				std::cout << "Неверный ввод" << std::endl;
				break;
		}
	}

}

int main() {
	int action;
	while (true) {
		std::cout << "1. Заполнить массив\n" <<
					 "2. Выполнить операции над массивом\n" <<
					 "3. Выйти из программы\n" <<
					 "Выберите действие: ";
		std::cin >> action;
		switch (action) {
			case 1:
				fill_array();
				break;
			case 2:
				do_smth();
				break;
			case 3:
				return 0;
				break;
			default:
				std::cout << "Неверный ввод" << std::endl;
				break;
		}
	}
	return 0;
}