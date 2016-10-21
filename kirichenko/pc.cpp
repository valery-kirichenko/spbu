#include <iostream>

class Parent {
public:
	Parent() {
		std::cout << "P Constructor without parameters" << std::endl;
	}

	Parent(int a) {
		std::cout << "P Constructor with parameter a: " << a << std::endl;
	}

	Parent(int a, int b) {
		std::cout << "P Constructor with 2 parameters a, b: " << a << ", " << b << std::endl;
	}

	~Parent() {
		std::cout << "P Destructor" << std::endl;
	}
};

class Child : public Parent {
public:
	Child() {
		std::cout << "C Constructor without parameters" << std::endl;
	}

	Child(int a) {
		std::cout << "C Constructor with parameter a: " << a << std::endl;
	}

	Child(int a, int b) : Parent(a ,b) {
		std::cout << "C Constructor with 2 parameters a, b: " << a << ", " << b << std::endl;
	}

	~Child() {
		std::cout << "C Destructor" << std::endl;
	}
};

int main() {
	Child c;
	Child c1(2);
	Child c2(2, 3);

	return 0;
}