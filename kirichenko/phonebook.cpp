#include <iostream>
#include <string>
#include <vector>

struct record {
	int id;
	std::string name;
	std::string phoneNumber;
};

void printPhonebook(std::vector<record>& pb, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << pb[i].name << ": " << pb[i].phoneNumber << std::endl;
	}
}

int main() {
	int n;
	std::cout << "Введите количество записей: ";
	std::cin >> n;
	std::vector<record> phonebook;

	for (int i = 0; i < n; i++) {
		record t;
		std::cout << i + 1 << " запись.\nВведите имя: ";
		std::cin >> t.name;
		std::cout << "Введите номер телефона: ";
		std::cin >> t.phoneNumber;
		t.id = i;
		phonebook.push_back(t);
	}
	std::cout << "\n\n";
	printPhonebook(phonebook, n);

	return 0;
}