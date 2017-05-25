#include <iostream>

class Animal {
public:
	virtual void print_paws() {
		std::cout << 0 << std::endl;
	}
};

class Duck : public Animal {
public:
	void print_paws() {
		std::cout << 2 << std::endl;
	}
};

class Bear : public Animal {
public:
	void print_paws() {
		std::cout << 4 << std::endl;
	}
};

class Crab : public Animal {
public:
	void print_paws() {
		std::cout << 8 << std::endl;
	}
};


int main() {
	Animal a;
	Bear b;
	Crab c;
	Duck d;

	a.print_paws();
	b.print_paws();
	c.print_paws();
	d.print_paws();

	return 0;
}