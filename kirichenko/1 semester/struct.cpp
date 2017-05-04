#include <iostream>
#include <string>

typedef struct {
	int id;
	int type;
	std::string name;
	union {
		struct {
			int studentID;
		};
		struct {
			int exp;
		};
	};
}_employer;

void printEmployer(_employer *ptr, int n) {
	std::cout << "Имя: " << ptr->name << std::endl;
	if (ptr->type == 0) std::cout << "Номер студенческого: " << ptr->studentID << std::endl;
	else if (ptr->type == 1) std::cout << "Опыт работы: " << ptr->exp << std::endl;
}

int main() {
	_employer employers[3];
	for (int i = 0; i < 3; i++) {
		std::cout << "Введите имя: ";
		std::cin >> employers[i].name;
		int a;
		while (true) {
			std::cout << "Введите 1, если это студент или 2, если это член администрации: ";
			std::cin >> a;
			if (a == 1) {
				std::cout << "Введите номер студенческого: ";
				std::cin >> employers[i].studentID;
				employers[i].type = 0;
				break;
			} else if (a == 2) {
				std::cout << "Введите опыт работы: ";
				std::cin >> employers[i].exp;
				employers[i].type = 1;
				break;
			}
		}
		employers[i].id = i + 1;
	}

	int n;
	while (true) {
		std::cout << "Введите номер для вывода (1–3): ";
		std::cin >> n;
		printEmployer(&employers[n - 1], n);
	}

	return 0;
}