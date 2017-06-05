// ConsoleApplication8.cpp: определяет точку входа для консольного приложения.

#include<iostream>
using namespace std;
        class MATRIX { 
		public: 
		int ar[3][3];};
	 int main()
{   
	
	MATRIX m1,m2,m3;
	cout << "enter elementes of matrix1:";
	for (int i=0;i<3;i++)
        for (int j=0;j<3;j++) cin >> m1.ar[i][j];

   cout << "enter elementes of matrix2:";
	for (int i=0;i<3;i++)
        for (int j=0;j<3;j++) cin >> m2.ar[i][j];

	for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
			m3.ar[i][j] = m1.ar[i][j] + m2.ar[i][j];
	for (int i=0;i<3;i++){  for (int j=0;j<3;j++) cout  << m1.ar[i][j] << " "; cout << endl; }

   	for (int i==;i<3;i++) for (int j=0;j<3;j++) cout  << m2.ar[i][j] << " "; cout << endl;}	
	
	 for (int i=0;i<3;i++){ for (int j=0;j<3;j++) cout  << m1.ar[i][j] << " "; cout << endl;}
	
	 system ("pause");
	 return 0;
}

