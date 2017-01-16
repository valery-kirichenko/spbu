#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;


class Matrix{
public:
	vector < vector<double> > A;
	int n, m;
	vector <double> & operator[](int i){	return A[i];}
	Matrix (int n, int m, double def):n(n), m(m){A.resize(n, vector <double> (m, def));}
	Matrix (int n, int m):n(n), m(m){A.resize(n, vector <double> (m));}
	friend Matrix operator + (Matrix , Matrix );
	friend Matrix operator * (Matrix , Matrix );
	double determinant();
	void fillRand(int);
};
Matrix operator+(Matrix A, Matrix B){
	if (A.n != B.n || A.m != B.m)
		throw (string) "Matrix::operator + : incorrect sizes of matrixes\n";
	int n = A.n, m = B.m;
	Matrix C(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			C[i][j] = A[i][j] + B[i][j];
	return C;
} 
Matrix operator*(Matrix A, Matrix B){
	if (A.m != B.n)
		throw (string) "Matrix::operator * : incorrect sizes of matrixes\n";
	int l = A.m;
	Matrix C(A.n, B.m);
	for (int i = 0; i < A.n; i++)
		for (int j = 0; j < B.m; j++)
			for (int k = 0; k < l; k++)
				C[i][j] += A[i][k] * B[k][j];
	return C;
} 
void Matrix::fillRand(int pr = 5){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			A[i][j] = rand() % pr;
}

istream& operator >> (istream& in, Matrix& m){
	for (int i = 0; i < m.n; i++)
		for (int j = 0; j < m.m; j++)
			in >> m[i][j];
	return in;
}
ostream& operator << (ostream& out, Matrix& m){
	for (int i = 0; i < m.n; i++){
		for (int j = 0; j < m.m; j++)
			out << m[i][j] << ' ';
		cout << endl;
	}
	return out;
}

double Matrix::determinant(){
	Matrix A = *this;
	int n = A.n;
	if (A.n != A.m)
		throw (string) "Matrix::determinant : not squared\n";
	for (int i = 0; i < n; i++){
		if (A[i][i] == 0)
			return 0;
		for (int j = i + 1; j < n; j++){
			A[j][i] /= A[i][i];
			for (int k = i + 1; k < n; k++)
				A[j][k] -= A[i][k] * A[j][i];
		}
	}
	double det = 1;
	for (int i = 0; i < n; i++)
		det *= A[i][i];
	return det;
}

int main(){
	srand((int)time(NULL));
	int a = rand() % 10, b = rand() % 10, c = rand() % 10, d = rand() % 10;
	Matrix A(a, b), B(b, d), C(a, a), D(a, b);
	A.fillRand();
	B.fillRand();
	C.fillRand();
	D.fillRand();
	cout << "A: \n" << A << "B:\n " << B <<"D:\n " << D << "A+D:\n" << A + D << "A*B:\n" << A * B << "C:\n"<< C << "det C: " << C.determinant() << endl;
	
}

/*
3 3
3 3 -1
4 1 3
1 -2 -2

3 3
1 2 3
-1 0 -2
-4 -3 5

3 3
5 7 1
-4 1 0
2 0 3

2 3
1 2 3
4 5 6

3 4
0 -1 1 -2
1 -1 0 2
1 3 0 2
*/