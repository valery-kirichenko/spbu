#include<iostream>
#include<cstdlib>
using namespace std;

void det(int *a);
const int l=2;
int main()
{
	setlocale(0, " ");
	int i, j, k;
	int A[l+1][l+1];
	int B[l+1][l+1];
	int E[l+1][l+1];
	int C[l+1][l+1];

	for (i=1;i<=l;i++)
	for (j=1;j<=l;j++)
	{
	E[i][j] = 0;
	C[i][j] = 0;
	}

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
			{
			C[i][j] = A[i][j]+B[i][j];
			cout<<C[i][j]<<" ";
			}
			cout<<endl;
		}
		det(&C[1][1]);

	cout<<"The difference of matrices"<<endl;
	for (i=1;i<=l;i++)
	{
	for (j=1;j<=l;j++)
		{	
		C[i][j] = A[i][j]-B[i][j];
		cout<<C[i][j]<<" ";
		}
		cout<<endl;
	}
	det(&C[1][1]);
		
	cout<<"The composition of matrices"<<endl;
	for (k=1;k<=l;k++)
	{
	for (i=1;i<=l;i++)
	{
	for (j=1;j<=l;j++)
		E[k][i]=E[k][i]+A[k][j]*B[j][i];
		cout<<E[k][i]<<" ";
	}
	cout<<endl;
	}
	det(&E[1][1]);

	system("pause");
	return 0;	
}
void det(int *c)
{
cout<<"The determinat of this matrix is "<<*(c)**(c+4)-*(c+1)**(c+3)<<endl;
cout<<endl;
}
