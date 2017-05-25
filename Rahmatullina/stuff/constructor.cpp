// ConsoleApplication8.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
        class Martix{
	    public:
			int ar[3][3];
		}
	 int _tmain(int argc, _TCHAR* argv[])
{
	
	Matrix m1,m2,m3;
	cout << "enter elemente os matrix1:";
	for (int i=0;i<3;i++)
        for (int j=0;j<3;i++) cin >> m1.ar[i][j];

   cout << "enter elemente os matrix2:";
	for (int i=0;i<3;i++)
        for (int j=0;j<3;i++) cin >> m2.ar[i][j];

	for (int i=0;i<3;i++)
        for (int j=0;j<3;i++)
			m3.ar[i][j] = m1.ar[i][j] + m2.ar[i][j];
	for (int i=0;i<3;i++){  for (int j=0;j<3;i++) cout  << m1.ar[i][j] << " "; cout << endl; }

   	for (int i==;i<3;i++) for (int j=0;j<3;i++) cout  << m2.ar[i][j] << " "; cout << endl;}	
	
	 for (int i=0;i<3;i++){ for (int j=0;j<3;i++) cout  << m1.ar[i][j] << " "; cout << endl;}
	
	 system ("pause");
	 return 0;
}

