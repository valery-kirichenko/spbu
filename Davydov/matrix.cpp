#include<iostream>
#include<cstdlib>
using namespace std;

void P(int *a,int *b)
const int l=2;
int main()
{
	int i, j;
	int A[l][l];
	int B[l][l];
	int E[l][l];

	
	

	for (i=1;i<=l;i++)
	for (j=1;j<=l;j++)
	{
		A[i][j] = rand() % 5 - 2;
		B[i][j] = rand() % 5 - 2;
	}

	cout<<"The first matrix"<<endl;
	for (i=1;i<=l;i++)
	{
	for (j=1;j<=l;j++)
		cout<<A[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	cout<<"The second matrix"<<endl;
	for (i=1;i<=l;i++)
	{
	for (j=1;j<=l;j++)
		cout<<B[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	cout<<"The sum of matrices"<<endl;
	for (i=1;i<=l;i++)
	{
	for (j=1;j<=l;j++)
		cout<<A[i][j]+B[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	cout<<"The difference of matrices"<<endl;
	for (i=1;i<=l;i++)
	{
	for (j=1;j<=l;j++)
		cout<<A[i][j]-B[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	

	system("pause");
	return 0;
}

void P(int *a,int *b)
{

}