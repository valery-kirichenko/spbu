#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int l=2;
void det(int E[l][l]);
int main()
{
	setlocale(0, " ");
	srand ( time(NULL) ); 
	int i, j, k;
	int A[l][l];
	int B[l][l];
	int E[l][l];



	for (i=0;i<l;i++)
	for (j=0;j<l;j++)
	{
		A[i][j] = rand() % 5 - 2;
		B[i][j] = rand() % 5 - 2;
	}

	cout<<"The first matrix"<<endl;
	for (i=0;i<l;i++)
	{
	for (j=0;j<l;j++)
		cout<<A[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	cout<<"The second matrix"<<endl;
	for (i=0;i<l;i++)
	{
	for (j=0;j<l;j++)
		cout<<B[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

		cout<<"The sum of matrices"<<endl;
		for (i=0;i<l;i++)
		{
		for (j=0;j<l;j++)
			{
			E[i][j] = A[i][j]+B[i][j];
			cout<<E[i][j]<<" ";
			}
			cout<<endl;
		}
		det(E);

	cout<<"The difference of matrices"<<endl;
	for (i=0;i<l;i++)
	{
	for (j=0;j<l;j++)
		{	
		E[i][j] = A[i][j]-B[i][j];
		cout<<E[i][j]<<" ";
		}
		cout<<endl;
	}
	det(E);
		
		for (int i=0;i<l;i++)
		for (int j=0;j<l;j++)
		E[i][j] = 0;
	
	cout<<"The composition of matrices"<<endl;
	for (k=0;k<l;k++)
	{
	for (i=0;i<l;i++)
	{
	for (j=1;j<=l;j++)
		E[k][i]=E[k][i]+A[k][j]*B[j][i];
		cout<<E[k][i]<<" ";
	}
	cout<<endl;
	}
	det(E);

	system("pause");
	return 0;	
}


void det(int E[l][l])
{
cout<<"The determinat of this matrix is "<<E[0][0]*E[1][1]-E[0][1]*E[1][0]<<endl;
cout<<endl;
}

