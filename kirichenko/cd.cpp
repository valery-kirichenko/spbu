#include <iostream>

class CD {
	int a, b;
public:
	CD(int inA, int inB) {
		a = inA;
		b = inB;
		a *= 2;
		b *= 2;
	}

	~CD() {
		std::cout << a << " " << b << std::endl;
	}
};

int main() {
	int a, b;
	std::cin >> a >> b;
	CD c(a, b);

	return 0;
}