// Classes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include <iomanip>
using namespace std;

class Matrix3x3{
	private:
	public:
		vector<vector<int> > Matrix;
		Matrix3x3(vector<vector<int> > Matrix);		
};

Matrix3x3::Matrix3x3 (vector<vector<int> > Matrix){
	this->Matrix = Matrix;
}

void VisualMatrix(Matrix3x3 GivenMatrix){
	for (int i = 0; i < 3; i++){
		for (int k = 0; k < 3; k++){
			cout << setw(5) << GivenMatrix.Matrix[i][k];
		}
		cout << endl;
	}
}

Matrix3x3 AddMatrixes(Matrix3x3 GivenMatrix1, Matrix3x3 GivenMatrix2){
	Matrix3x3 ResultMatrix = GivenMatrix1;
	for (int i = 0; i < 3; i++){
		for (int k = 0; k < 3; k++){
			ResultMatrix.Matrix[i][k] = GivenMatrix1.Matrix[i][k] + GivenMatrix2.Matrix[i][k];
		}
	}
	return ResultMatrix;
}

Matrix3x3 MultiplyMatrixes(Matrix3x3 GivenMatrix1, Matrix3x3 GivenMatrix2){
	Matrix3x3 ResultMatrix = GivenMatrix1;
	for(int i = 0; i < 3; i++){
		for(int k = 0; k < 3; k++){
			ResultMatrix.Matrix[i][k] = 0;
			for(int j = 0; j < 3; j++){
				ResultMatrix.Matrix[i][k] += GivenMatrix1.Matrix[i][j] * GivenMatrix2.Matrix[j][k];
			}
		}
	}
	return ResultMatrix;
}

int GetDeterminator(Matrix3x3 Matrix){
	int Determinator = (Matrix.Matrix[0][0] * Matrix.Matrix[1][1] * Matrix.Matrix[2][2]) + (Matrix.Matrix[0][1] * Matrix.Matrix[1][2] * Matrix.Matrix[2][0]) + (Matrix.Matrix[0][2] * Matrix.Matrix[1][0] * Matrix.Matrix[2][1]) - (Matrix.Matrix[0][2] * Matrix.Matrix[1][1] * Matrix.Matrix[2][0]) - (Matrix.Matrix[0][0] * Matrix.Matrix[1][2] * Matrix.Matrix[2][1]) - (Matrix.Matrix[0][1] * Matrix.Matrix[1][0] * Matrix.Matrix[2][2]);
	return Determinator;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	int temp;
	vector<int> EmptyVector = vector<int>();
	vector<vector<int> > RegularMatrix1 = vector<vector<int> >();
	vector<vector<int> > RegularMatrix2 = vector<vector<int> >();
	cout << "Matrix #1: \n";
	for (int i = 0; i < 3; i++){
		RegularMatrix1.push_back(EmptyVector);
		cout << "Fill the row #" << i << ": ";
		for (int k = 0; k < 3; k++){
			cin >> temp;
			RegularMatrix1.at(i).push_back(temp);
		}
	}

	cout << "Matrix #2: \n";
	for (int i = 0; i < 3; i++){
		RegularMatrix2.push_back(EmptyVector);
		cout << "Fill the row #" << i << ": ";
		for (int k = 0; k < 3; k++){
			cin >> temp;
			RegularMatrix2.at(i).push_back(temp);
		}
	}

	Matrix3x3 NewMatrix1(RegularMatrix1);
	cout << "\nFirst matrix: \n";
	VisualMatrix(NewMatrix1);
	int Det1 = GetDeterminator(NewMatrix1);
	cout << "Determinator: " << Det1 << endl;
	_getch();

	Matrix3x3 NewMatrix2(RegularMatrix2);
	cout << "\nSecond matrix: \n";
	VisualMatrix(NewMatrix2);
	int Det2 = GetDeterminator(NewMatrix2);
	cout << "Determinator: " << Det2 << endl;
	_getch();

	Matrix3x3 AddThem = AddMatrixes(NewMatrix1, NewMatrix2);
	cout << "\nAdding matrixes to each other: \n";
	VisualMatrix(AddThem);
	int DetAdd = GetDeterminator(AddThem);
	cout << "Determinator: " << DetAdd << endl;
	_getch();

	Matrix3x3 MultiplyThem = MultiplyMatrixes(NewMatrix1, NewMatrix2);
	cout << "\nMultiplying matrixes by each other: \n";
	VisualMatrix(MultiplyThem);
	int DetMult = GetDeterminator(MultiplyThem);
	cout << "Determinator: " << DetMult << endl;
	_getch();

	return 0;
}

