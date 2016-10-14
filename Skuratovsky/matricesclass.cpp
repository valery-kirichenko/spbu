#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;
     random_device rd;   // non-deterministic generator  
     mt19937 gen(rd());
class Matrix

{   public:
		int a[3][3];
		Matrix multiply(Matrix&);
		void add(Matrix&);
		void show();
		int determinant();
		Matrix();
		~Matrix(){};
};
int Matrix::determinant()
{
	return ((a[0][0]*a[1][1]*a[2][2]) + (a[0][1]*a[1][2]*a[2][0])+ (a[1][0]*a[0][2]*a[2][1]) - (a[2][0]*a[1][1]*a[0][2]) - (a[0][0]*a[2][1]*a[1][2]) - (a[1][0]*a[0][1]*a[2][2]));
};
void Matrix::add (Matrix& b)
{
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			a[i][j]+=b.a[i][j];

};
void Matrix::show()
{
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";


};
Matrix Matrix::multiply(Matrix& b)
{
	Matrix newMatrix;
	for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
	 newMatrix.a[i][j]=0;
	for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
	{
		  for(int k = 0; k < 3; k++)
		  newMatrix.a[i][j]+=a[i][k]*b.a[k][j];

	  }
	return newMatrix;
};
Matrix::Matrix()
{
	 
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			a[i][j]=gen()%10+1;
};
int main()
{
	
	Matrix a,b,c;
a.show();
b.show();
c=a.multiply(b);
c.show();
cout<<c.determinant();
	system("pause");

	return 0;
}
