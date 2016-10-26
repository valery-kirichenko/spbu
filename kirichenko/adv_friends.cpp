#include <iostream>

class Circle;

class Square {
	int side;
	public:
	void set_side(int a) {
		side = a;
	}
	friend class Circle;
};

class Circle {
	int radius;
	public:
	void convert(Square s) {
		radius = s.side;
	}
	void set_radius(int r) {
		radius = r;
	}
	void print_radius() {
		std::cout << radius << std::endl;
	}

};

int main() {
	Circle c;
	c.set_radius(4);
	c.print_radius();
	Square s;
	s.set_side(5);
	c.convert(s);
	c.print_radius();
	return 0;
}