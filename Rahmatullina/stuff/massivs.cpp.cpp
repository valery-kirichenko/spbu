// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{ int i,j,A;
int a[2][2];
int b[2][2];
int c[2][2];
cout << "Enter massive a" << endl;
for(i=0;i<2;i++)
for(j=0;j<2;j++) 
cin >> a[i][j];
cout << "Enter massive b" << endl;
for(i=0;i<2;i++)
for(j=0;j<2;j++)
cin >> b[i][j];
      for(i=0;i<2;i++)
      for(j=0;j<2;j++)
      c[i][j] = a[i][j] +b[i][j];
cout << "massive a =" << endl;
for(i=0;i<2;i++)
  {
    for(j=0;j<2;j++)
    cout << a[i][j] << " ";
    cout << endl;
   }
cout << "massive b =" << endl;
for(i=0;i<2;i++)
  {
    for(j=0;j<2;j++)
    cout << b[i][j] << " ";
    cout << endl;
   }
cout << "massive a + b =" << endl;
for(i=0;i<2;i++)
  {
    for(j=0;j<2;j++)
    cout << c[i][j] << " ";
    cout << endl;
   }
   A = c[0][0]*c[1][1] - c[0][1]*c[1][0];
   cout << "opredelitel a+b =" << A << endl;
 
      for(i=0;i<2;i++)
      for(j=0;j<2;j++)
      c[i][j] = a[i][j]-b[i][j];
    cout << "massive a - b =" << endl;
for(i=0;i<2;i++)
  {
    for(j=0;j<2;j++)
    cout << c[i][j] << " ";
    cout << endl;
	 }
A = c[0][0]*c[1][1] - c[0][1]*c[1][0];
   cout << "opredelitel a-b =" << A << endl;
 
for(j=0;j<2;j++) 
	c[0][j]=a[0][0]*b[0][j]+a[0][1]*b[1][j];
for(j=0;j<2;j++)
	c[1][j]=a[1][0]*b[0][j]+a[1][1]*b[1][j];
    
cout << "massive a*b =" << endl;
for(i=0;i<2;i++)
  {
    for(j=0;j<2;j++)
    cout << c[i][j] << " ";
    cout << endl;
	
   }
A = c[0][0]*c[1][1] - c[0][1]*c[1][0];
   cout << "opredelitel a*b =" << A << endl;
 

system("pause");
return 0;
}

