#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class matrix
{
public : 
	int m[3][3];
matrix();
void out()
{
for (int i=0;i<3;i++)
	{
	for (int j=0;j<3;j++) cout<<m[i][j]<<' ';
	cout<<endl;
	}
}
};
matrix::matrix()
{
	char y='0';
	while ((y!='1')&&(y!='2')) 
	{
	cout<<"Choose the operation from list below.\n";
	cout<<"1 - to fill in the matrix by yourself.\n";
	cout<<"2 - to AutoComplete the matrix.\n";
	cout<<"Your choice: ";
	cin>>y;
	}
	switch (y)
	{
	case '1':	int x;
				cout<<"Enter t1he matrix:\n";
				for (int i=0;i<3;i++)
				for (int j=0;j<3;j++)
					{
					cin>>x;
					m[i][j]=x;
					}
				break;
	case '2':	
				srand(time(NULL)); 
				for (int i=0;i<3;i++)
				for (int j=0;j<3;j++) 
				{
					m[i][j]= rand() % 10 - 5;
				}
				break;	
	}
	//system("cls");
}

void sum(matrix &a, matrix &b)
{
for (int i=0;i<3;i++)
	{
for (int j=0;j<3;j++) 
	cout<<a.m[i][j]+b.m[i][j]<<' ';
	cout<<endl;
	}
}

void difference(matrix &a, matrix &b)
{
for (int i=0;i<3;i++)
	{
for (int j=0;j<3;j++) 
	cout<<a.m[i][j]-b.m[i][j]<<' ';
	cout<<endl;
	}
}

void product(matrix &a, matrix &b)
{
	int p[3][3];
	for (int i=0;i<3;i++)
	for (int j=0;j<3;j++) p[i][j]=0;

for (int t=0;t<3;t++)
for (int i=0;i<3;i++)
for (int j=0;j<3;j++) 
	p[t][i] += a.m[t][j]*b.m[j][i];

for (int i=0;i<3;i++)
	{
	for (int j=0;j<3;j++) cout<<p[i][j]<<' ';
	cout<<endl;
	}
}
void determinant(matrix &a)
{
int det = a.m[0][0]*a.m[1][1]*a.m[2][2]+a.m[1][0]*a.m[2][1]*a.m[0][2]+a.m[0][1]*a.m[1][2]*a.m[2][0]
         -a.m[2][0]*a.m[1][1]*a.m[0][2]-a.m[0][1]*a.m[1][0]*a.m[2][2]-a.m[0][0]*a.m[1][2]*a.m[2][1];
cout<<"The determinant of matrix is "<<det<<endl;
}

int main()
{
	   
	matrix m1;
	m1.out();
	matrix m2;
	m2.out();

	char y='q';
	while (y!='0') 
	{
	cout<<"Choose the operation from list below.\n";
	cout<<"0 - exit the programm.\n";
	cout<<"1 - sum of matrices.\n";
	cout<<"2 - difference of matrices.\n";
	cout<<"3 - product of matrices.\n";
	cout<<"4 - determinant of the first matrix.\n";
	cout<<"5 - determinant of the second matrix.\n";
	cout<<"Your choice: ";
	cin>>y;
	switch (y)
{
	case '0':   break;
	case '1':	sum(m1, m2);
				break;
	case '2':	difference(m1, m2);
				break;	
	case '3':	product(m1, m2);
				break;	
	case '4':	determinant(m1);
				break;
	case '5':	determinant(m2);
				break;
	}
}

	system("pause");
	return 0;
}