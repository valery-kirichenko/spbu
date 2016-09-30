#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <random>
#include <string>
#include <algorithm>
#include <time.h>
#include <conio.h>

using namespace std;

int F(int, int);
vector<double> operator + (vector<double>, vector<double>);
vector<double> operator * (double c, vector<double>);

struct matrix{
	int n, m;
	vector<vector<double>> A;
	matrix(){
		n = 0;
		m = 0;
	}
	matrix(vector<vector<double>> _A){
		A = _A;
		if (A.size() == 0){
			n = 0;
			m = 0;
		}
		else{
			n = A.size();
			m = A[0].size();
		}
	}
	inline void resize(int _n, int _m, double _k = 0){
		A.resize(_n, vector<double>(_m, _k));
	}
	pair<int, int> size(){
		if (A.size() == 0)
			return make_pair(0, 0);
		else
			return make_pair(A.size(), A[0].size());
	}
	vector<double>& operator [] (int a){
		return A[a];
	}
	void gaus(){
		for (int i = 0; i < A.size(); i++){
			for (int j = i + 1; j < A.size(); j++){
				A[j] = A[i][i] * A[j] + (-1)*A[j][i] * A[i];
			}
		}
	}//need n==m and A.size!=0
	double det(){
		if (A.size() == 0)
			return 0;
		matrix B(A);
		B.gaus();
		double ans = 1;
		for (int i = 0; i < A.size(); i++)
			ans *= B[i][i];
		return ans;
	}
	~matrix(){
		A.clear();
	}
};

vector<double> operator + (vector<double> A, vector<double> B){
	for (int i = 0; i < A.size(); i++){
		A[i] += B[i];
	}
	return A;
}//need A.size()==B.size()

vector<double> operator * (double c, vector<double> A){
	for (int i = 0; i < A.size(); i++){
		A[i] *= c;
	}
	return A;
}

matrix operator *(double c, matrix A){
	for (int i = 0; i < A.size().first; i++){
		for (int j = 0; j < A.size().second; j++)
			A[i][j] *= c;
	}
	return A;
}

matrix operator +(matrix B, matrix A){
	if (B.size() == A.size())
	for (int i = 0; i < A.size().first; i++){
		for (int j = 0; j < A.size().second; j++)
			A[i][j] += B[i][j];
	}
	return A;
}

matrix operator *(matrix A, matrix B){
	int n=A.size().first, m=A.size().second, k=B.size().second;
	matrix ans;
	ans.resize(n, k);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < k; j++){
			for (int t = 0; t < m; t++){
				ans[i][j] += A[i][t] * B[t][j];
			}
		}
	}
	return ans;
}

int F(int k, int m){
	if (m == 0)
		return -1;
	while (k < 0)
		k += m;
	return k%m;
}

ostream& operator << (ostream& out, matrix A){
	if (A.size() != make_pair(0, 0)){
		//out<<fixed;
		for (int i = 0; i < A.size().first; i++){
			for (int j = 0; j < A.size().second; j++){
				out.width(6);
				out<<left << A[i][j] << " ";
			}
			out << "\n";
		}
	}
	return out;
}

matrix in(){
	matrix A;
	int n, m;
	cout << "insert size of matrix\n";
	cin >> n >> m;
	cout << "insert matrix\n";
	A.resize(n, m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> A[i][j];
		}
	}
	return A;
}

int main(){
	//freopen("feelgood.in", "r", stdin);
	//freopen("feelgood.out", "w", stdout);
	matrix A, B,C;
	int n, m;
	cout << "insert size of first matrix\n";
	cin >> n >> m;
	cout << "insert first matrix\n";
	A.resize(n, m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> A[i][j];
		}
	}
	cout << "insert size of second matrix\n";
	cin >> n >> m;
	cout << "insert second matrix\n";
	B.resize(n, m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> B[i][j];
		}
	}//*/
	while (0 == 0){
		system("cls");
		cout << A << "\n" << B << "\n";
		cout << "what should i do?\n1) +\n2) -\n3) *\n4) det of first matrix\n5) insert first matrix\n6) insert second matrix\n7) swap matrix\n8) exit\n";
		n = _getch() - '0';
		switch (n){
		case 1:
			if (A.size() == B.size()){
				C = A + B;
				cout << "\nThe result is:\n" << C;
			}
			else{
				cout << "\nimposible\n";
			}
			cout << "press any button";
			_getch();
			break;
		case 2:
			if (A.size() == B.size()){
				C = A + -1 * B;
				cout << "\nThe result is:\n" << C;
			}
			else{
				cout << "\nimposible\n";
			}
			cout << "press any button";
			_getch();
			break;
		case 3:
			if (A.size().second == B.size().first){
				C = A * B;
				cout << "\nThe result is:\n" << C;
			}
			else{
				cout << "\nimposible\n";
			}
			cout << "press any button";
			_getch();
			break;
		case 4:
			if (A.size().first == A.size().second){
				cout.setf(ios::fixed);
				cout << "\nThe result is:\n" << A.det()<<"\n";
				cout.unsetf(ios::fixed);
			}
			else{
				cout << "\nimposible\n";
			}
			cout << "press any button";
			_getch();
			break;
		case 5:
			A = in();
			break;
		case 6:
			B = in();
			break;
		case 7:
			swap(A, B);
			break;
		case 8:
			return 0;
		default:
			cout << "\nwe need more minerals and correct tests...\n";
			cout << "press any button";
			_getch();
			break;
		}
	}
	return 0;
}