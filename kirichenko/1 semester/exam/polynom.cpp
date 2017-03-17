#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

class Polynom {
public:
	int degree;
	std::vector<int> coeff;

	Polynom() {
		degree = 0;
	}

	Polynom(int d, std::vector<int> &c) {
		coeff = c;
		degree = d;
	}

	void Print() {
		int t;
		for (int i = degree; i >= 0; i--) {
			t = coeff[i];
			if (i == 0) {
				std::cout << ((t >= 0) ? "+ " : "- ") << std::abs(t);
				continue;
			}
			std::cout << ((t >= 0) ? "+ " : "- ") << std::abs(t) << "x^" << i << " ";
		}
		std::cout << std::endl;
	}

	Polynom operator+(Polynom a) {
		int d = std::max(a.degree, degree), t;
		std::vector<int> c;
		for (int i = 0; i <= d; i++) {
			t = ((a.degree >= i) ? a.coeff[i] : 0) + ((degree >= i) ? coeff[i] : 0);
			c.push_back(t);
		}
		return Polynom(d, c);
	}

	Polynom operator-(Polynom a) {
		for (int i = 0; i <= a.degree; i++) {
			a.coeff[i] = -a.coeff[i];
		}
		return (*this + a);
	}

	Polynom operator*(Polynom a) {
		int d = a.degree + degree;
		std::vector<int> c;
		for (int i = 0; i <= d; i++) c.push_back(0);
		for (int i = 0; i <= degree; i++) {
			for (int j = 0; j <= a.degree; j++) {
				c[i + j] += coeff[i] * a.coeff[j];
			}
		}
		return Polynom(d, c);
	}
};

int main() {
	std::ifstream input("polynom.in");
	int s, d, t;
	input >> s;
	std::vector<Polynom> p;
	for (int i = 0; i < s; i++) {
		std::vector<int> c;
		input >> d;
		for (int i = 0; i <= d; i++) {
			input >> t;
			c.push_back(t);
		}
		p.push_back(Polynom(d, c));
	}

	for (int i = 0; i < s; i++) {
		p[i].Print();
	}

	(p[0] + p[1]).Print();
	(p[0] - p[1]).Print();
	(p[0] * p[1]).Print();
	return 0;
}