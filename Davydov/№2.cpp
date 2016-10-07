#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

const int k = 3;
int main()
{
	struct student 
	{
		char name[20];
		char family[20];
		int id;
	};
	struct student person[k];
	int i;
	char n[20];

	 
	for (i=1;i<=k;i++)
	{
		srand ( time(NULL) ); 
		cout<<"Enter the name ";
		cin>>n;
		strcpy_s(person[i].name, n);
		
		cout<<"Enter the family ";
		cin>>n;
		strcpy_s(person[i].family, n);

		person[i].id = rand()%10;
	}
	for (i=1;i<=k;i++)
	{
		cout<<"person["<<i<<"].name = "<<person[i].name<<endl;
		cout<<"person["<<i<<"].family = "<<person[i].family<<endl;
		cout<<"person["<<i<<"].id = "<<person[i].id<<endl;
		cout<<endl;
	}


	cout<<endl;
	system("pause");
	return 0;
}


