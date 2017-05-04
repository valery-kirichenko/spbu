#include <iostream>

using namespace std;

int ix = 0;

class Animal {
public:
	virtual void print_ix() {
		cout << ++ix << endl;
	}
};

class Cat : public Animal {
public:
	void print_ix() {
		cout << ++ix << endl;
	}
};

class Dog : public Animal {
public:
	void print_ix() {
		cout << ++ix << endl;
	}
};

class Snake : public Animal {
public:
	void print_ix() {
		cout << ++ix << endl;
	}
};


int main() {
	Animal a;
	Cat b;
	Dog c;
	Snake d;

	a.print_ix();
	b.print_ix();
	c.print_ix();
	d.print_ix();

	return 0;
}
