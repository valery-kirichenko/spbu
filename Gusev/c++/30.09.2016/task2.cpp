// problem1!.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <math.h>
#include <string>

using namespace std;

vector<int> in(){
	vector<int> A;
	int n,a;
	cout<<"insert size of array\n";
	cin>>n;
	cout<<"insert array\n";
	for(int i=0;i<n;i++){
		cin>>a;
		A.push_back(a);
	}
	return A;
}

vector<int> operator *=(vector<int>& A,vector<int>& B){
	for(int i=0;i<min(A.size(),B.size());i++)
		A[i]*=B[i];
	return A;
}

int main()
{
	setlocale(LC_ALL,"rus");
	vector<int> A,B;
	cout<<"first array\n";
	A=in();
	cout<<"second array\n";
	B=in();
	A*=B;
	cout<<"result is:\n";
	copy( A.begin(), A.end(), ostream_iterator<int>(cout," "));
	_getch();
	return 0;
}
