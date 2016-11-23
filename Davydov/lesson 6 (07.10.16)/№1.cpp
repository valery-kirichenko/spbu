#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

const int maxi = 100;
const int leng = 20;
int k;

struct student 
	{
		char name[leng];
		char family[20];
		int id;
	};

void in(student *human);
int main()
{
	setlocale(LC_ALL, " ");
	student *human, person[maxi];
	human = &person[1];
	in(human);
	
	int i;
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

void in(student *human)
{
	int i;
	char n[leng];

	cout<<"Enter the count of pupils: ";
	cin>>k;
	for (i=0;i<k;i++)
	{
		srand ( time(NULL) ); 
		cout<<"Enter the name ";
		cin>>n;
		for (int j=0;j<strlen(n);j++) (human+i)->name[j] = n[j];
		cout<<"Enter the family ";
		cin>>n;
		for (int j=0;j<strlen(n);j++) (human+i)->family[j] = n[j];
		(human+i)->id = rand()%1000;
	}
}

