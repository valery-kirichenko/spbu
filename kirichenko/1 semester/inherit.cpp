#include <cmath>
#include <iostream>
#define PI 3.1415926

class Figure {
	float side;
public:
	Figure(float s) {
		this->side = s;
	}

	void setSide(float s) {
		this->side = s;
	}

	float getSide() {
		return this->side;
	} 

};

class Circle : public Figure {
	using Figure::Figure;
public:
	float square() {
		return this->getSide() * this->getSide() * PI;
	}

	float perimeter() {
		return 2 * this->getSide() * PI;
	}
};

class Square : public Figure {
	using Figure::Figure;
public:
	float square() {
		return this->getSide() * this->getSide();
	}

	float perimeter() {
		return 4 * this->getSide();
	}
};

class Triangle : public Figure {
	using Figure::Figure;
public:
	float square() {
		return this->getSide() * this->getSide() * std::sqrt(3) / 4;
	}

	float perimeter() {
		return 3 * this->getSide();
	}
};

int main() {
	Circle c(3.0);
	std::cout << "Circle S: " << c.square() << " P: " << c.perimeter() << std::endl;

	Square s(2.0);
	std::cout << "Square S: " << s.square() << " P: " << s.perimeter() << std::endl;

	Triangle t(4.2);
	std::cout << "Triangle S: " << t.square() << " P: " << t.perimeter() << std::endl;

	return 0;
}
