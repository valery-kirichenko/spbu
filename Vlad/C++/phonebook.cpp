#include <iostream>
#include <conio.h>
#include <vector>

typedef struct {
		char name[100];
		char number[15];
	}str;

int main() {
	char switcher = '0';
	int size = 0;
	
	std::vector<str> phonebook(size);

	while (switcher != '3') {
		std::cout << "Chouse the op:" << std::endl 
				  << "1. Check a list of phone numbers" << std::endl
				  << "2. Add new phone number" << std::endl
				  << "3. Exit" << std::endl << std::endl;
		switcher = _getch();
		if ((switcher < '1') || (switcher > '3'))
			std::cout << "You can only chouse among 1-3!" << std::endl;
		if (switcher == '1') {
			if (size == 0) 
				std::cout << "Your book is empty!" << std::endl << std::endl;
			else 
				for (int i = 0; i < size; i++) {
					std::cout << "Name: " << phonebook[i].name << std::endl 
							  << "Number: " << phonebook[i].number << std::endl << std::endl;
				}
		}
		if (switcher == '2') {
			size++;
			phonebook.resize(size);
			std::cout << "Enter name: ";
			std::cin >> phonebook[size-1].name;
			
			std::cout << "Enter number: ";
			std::cin >> phonebook[size-1].number;
		}
	}
}
