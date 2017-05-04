#include <iostream>

int func();

int main() {
	std::cout << func() << std::endl;

	return 0;
}

int func() {
	return 5;
}