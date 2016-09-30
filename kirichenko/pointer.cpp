#include <iostream>

int main() {
	int *b, n;
	std::cout << "Размер массива: ";
	std::cin >> n;
	
	b = new int[n];

	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
	}

	for(int i = 0; i < n; i++) {
		std::cout << b[i] << std::endl;
	}

	delete [] b;

	return 0;
}