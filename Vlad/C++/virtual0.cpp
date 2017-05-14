#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

class animal {
protected:
	int legs;
public:
	virtual int setlegs() {
		return 0;
	}
};

class dog : public animal {
public:
	int setlegs() {
		return 4;
	}
};

class spider : public animal {
public:
	int setlegs() {
		return 8;
	}
};

class man : public animal {
public:
	int setlegs() {
		return 2;
	}
};

int main() {
	dog dog1; spider spider1; man man1;
	cout << "Dog has " << dog1.setlegs() << " legs." << endl;
	cout << "Spider has " << spider1.setlegs() << " legs." << endl;
	cout << "Man has " << man1.setlegs() << " legs." << endl;
}
