#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Figure {
protected:
	int n;
	double P, S;

public:
	Figure(int n){
		this->P = 0;
		this->S = 0;
	}

	void print(){
        cout << " => P: " << countP() << ", S: " << countS() << endl;
	}

	virtual double countP() = 0;
	virtual double countS() = 0;
};

class Triangle : public Figure {
public:
	Triangle(int n) : Figure(n){
		this->n = n;
	}

	double countP(){
		P = n * 3;
		return P;
	}

	double countS(){
		S = n * n * (sqrt(3)/4);
		return S;
	}
};

class Square : public Figure {
public:
	Square(int n) : Figure(n){
		this->n = n;
	}

	double countP(){
		P = n * 4;
		return P;
	}

	double countS(){
		S = n * n;
		return S;
	}
};

class Circle : public Figure {
public:
	Circle(int n) : Figure(n){
		this->n = n;
	}

	double countP(){
		P = 2 * (3.14) * n;
		return P;
	}

	double countS(){
		S = (3.14) * n * n;
		return S;
	}
};

int main(){
	int n = 5;

	Triangle t(n);
	Square r(n + 1);
	Circle c(n - 1);

	cout << setprecision(5) << "Triangle: ";
	t.print();

	cout << "Square: ";
	r.print();

	cout << "Circle: ";
	c.print();

	return 0;
}
