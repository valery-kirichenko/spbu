#include <iostream>

int main() {
	int a, b;
	std::cin >> a;
	std::cin >> b;
	try {
		if (b == 0) throw b;
	}
	catch (int) {
		std::cout << "Error";
		system("pause");
		return 0;
	}
	std::cout << "a / b =" << a / b;
	system("pause");
}