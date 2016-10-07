#include <iostream>
#include <string>

struct Student {
	int id;
	std::string firstName;
	std::string lastName;
};

void printStudent(struct Student* ptr, int n) {
	std::cout << "Студент под номером " << n << ": " << ptr->firstName << " " << ptr->lastName << std::endl;
}

int main() {
	struct Student group[3];
	for (int i = 0; i < 3; i++) {
		std::cout << "Введите имя и фамилию " << i + 1 << " студента: ";
		std::cin >> group[i].firstName >> group[i].lastName;
		group[i].id = i + 1;
	}

	int n;
	while (true) {
		std::cout << "Введите номер студента для вывода (1–3): ";
		std::cin >> n;
		printStudent(&group[n - 1], n);
	}

	return 0;
}
