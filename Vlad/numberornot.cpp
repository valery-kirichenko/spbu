#include <iostream>

int main() {
		char symbol;
		std::cin >> symbol;
		int code = symbol;
		if ((code > 47) && (code < 58)) {
			std::cout << "It's a number!" << std::endl;
			system("pause");
		}
		else {
			std::cout << "It's not a number!" << std::endl;
			system("pause");
		}
}