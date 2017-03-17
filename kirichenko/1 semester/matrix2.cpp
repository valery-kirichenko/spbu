#include <iostream>
#include <vector>

class Matrix {
	std::vector< std::vector<int> > m;
	
	public:
	Matrix(const std::vector< std::vector<int> >& vec = 
		   std::vector< std::vector<int> >(3, std::vector<int>(3, 0))) {
		m.resize(3, std::vector<int>(3, 0));
		m = vec;
	}

	int det() {
		return (m[0][0]*m[1][1]*m[2][2] + m[0][1]*m[1][2]*m[2][0] +
				m[0][2]*m[1][0]*m[2][1] - m[0][2]*m[1][1]*m[2][0] -
				m[0][0]*m[1][2]*m[2][1] - m[0][1]*m[1][0]*m[2][2]); 
	}

	void print_matrix() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << m[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	void set(int i, int j, int val) {
		m[i][j] = val;
	}

	int get(int i, int j) {
		return m[i][j];
	}

	Matrix operator+(Matrix &other) {
		Matrix result;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				result.set(i, j, m[i][j] + other.get(i, j));
			}
		}
		return result;
	}

	void operator+=(Matrix &other) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				m[i][j] += other.get(i, j);
			}
		}
	}

	Matrix operator-(Matrix &other) {
		Matrix result;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				result.set(i, j, m[i][j] - other.get(i, j));
			}
		}
		return result;
	}

	void operator-=(Matrix &other) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				m[i][j] -= other.get(i, j);
			}
		}
	}

	Matrix operator*(Matrix &other) {
		Matrix result;
		for (int row = 0; row < 3; row++) {
			for (int col = 0; col < 3; col++) {
				int s = 0;
				for (int i = 0; i < 3; i++) {
					s += m[row][i] * other.get(i, col);
				}
				result.set(row, col, s);
			}
		}
		return result;
	}

	void operator*=(Matrix &other) {
		for (int row = 0; row < 3; row++) {
			for (int col = 0; col < 3; col++) {
				int s = 0;
				for (int i = 0; i < 3; i++) {
					s += m[row][i] * other.get(i, col);
				}
				m[row][col] = s;
			}
		}
	}
};



int main() {
	std::vector< std::vector<int> > m;
	m.resize(3, std::vector<int>(3, 0));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> m[i][j];
		}
	}
	Matrix first(m);

	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> m[i][j];
		}
	}
	Matrix second(m);

	//std::cout << "\n+:" << std::endl;
	//(first + second).print_matrix();

	std::cout << "\n*:" << std::endl;
	(first * second).print_matrix();

	std::cout << "\nDeterminant of first matrix:" << std::endl;
	std::cout << first.det() << std::endl;


	return 0;
}