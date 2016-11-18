#include<iostream>
#include<cstdlib>
using namespace std;


int main()
{
	

	int i;
	
	cout<<"Cycle for:	";
	for (i=1;i<=10;i++)
		cout<<i<<" ";
	cout<<endl;
	i = 1;

	cout<<"Cycle while:	";
	while (i<=10)
	{
		cout<<i<<" ";
		i++;
	}
	cout<<endl;
	i = 1;

	cout<<"Cycle do while:	";
	do
	{
		cout<<i<<" ";
		i++;
	} while (i<=10);
	cout<<endl;

	system("pause");
	return 0;
}

