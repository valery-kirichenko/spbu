#include <iostream>
using namespace std;

int main()
{
    int n=3;
 int a[n][n];
 int b[n][n];
 int c[n][n];
 int i,j,k;
 cout << "Enter the first matrix: \n";
 for (i=0; i<n; i++)
 {
     for (j=0; j<n; j++)
     {
         cin >> a[i][j];
     }
 }
 cout << "Enter the second matrix: \n";
 for (i=0; i<n; i++)
 {
     for (j=0; j<n; j++)
     {
         cin >> b[i][j];
     }
 }
 
 for (i=0;i<n;i++)
 {
    for (j=0;j<n;j++)
    { 
        c[i][j]=0; 
        for (k=0;k<n;k++)
        {
            c[i][j]+=a[i][k]*b[k][j];
        }
    }
 }
 
 cout << "\nMatrix a*b=\n";
 for (i=0; i<n; i++)
 {
     for (j=0; j<n; j++)
     {
         cout << c[i][j] << " ";
     }
     cout << "\n";
 }
 return 0;
}