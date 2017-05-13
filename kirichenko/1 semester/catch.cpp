#include <iostream>

int main() {
	int i, j;
	char c;
	std::cout << "i j:" << std::endl;
	std::cin >> i >> j;

	try {
		if (j == 0) throw 0;
		std::cout << i / j << std::endl;
	} catch (int i) {
		std::cout << "Error: ";
		switch (i) {
			case 0:
				std::cout << "zero division";
				break;
			default:
				std::cout << "undefined error";
				break;
		}
		std::cout << std::endl;
	}


	std::cout << "c:" << std::endl;
	std::cin >> c;
	std::cout << "It's a ";
	
	if (c >= 48 && c <= 57) {
		std::cout << "number";
	} else if (c >= 65 && c <= 90) {
		std::cout << "uppercase letter";
	} else if (c >= 97 && c <= 122) {
		std::cout << "lowercase letter";
	} else {
		std::cout << "some symbol";
	}

	std::cout << std::endl;

	return 0;

}