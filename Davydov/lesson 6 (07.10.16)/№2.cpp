#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

const int k = 100;
const int lim = 1000;
const int leng = 20;

char out();
int main()
{
	setlocale(LC_ALL, " ");
	struct student
	{ 
		int id;
		char profession;
		union
		{
			struct {public: char name[leng]; char family[leng];};
			struct {public: char lesson[leng];};
			struct {public: int paper;};
		};
	};

	int i, x;
	char work;
	char n[20];

	student *link, people[k];
	link = people;
	cout<<"Enter the number of people: ";
	cin>>x;
	for (i=0;i<x;i++)
	{
		work = out();
		while ((work>'3')||(work<'1'))
		{cout<<"You entered wrong number.\n"; work = out();}
		(link+i)->profession = work;
		srand ( time(NULL) ); 
		(link+i)->id= rand()%lim;
		switch(work)
		{
		case('1'):  cout<<"Enter the name of student: ";
					cin>>(link+i)->name;
					cout<<"Enter the family of student: ";
					cin>>(link+i)->family;
					break;
		case('2'):  cout<<"Enter the lesson of lector: ";
					cin>>(link+i)->lesson;
					break;
		case('3'):  cout<<"Enter the number of paper in administration: ";
					cin>>(link+i)->paper;
					break;
		}
	}
	system("cls");

	for (i=0;i<x;i++)
	{
		cout<<"Person number "<<i<<":\n";
	switch ((link+i)->profession)
		{
		case('1'):  cout<<"The name of student: "<<(link+i)->name<<endl;
					cout<<"The family of student: "<<(link+i)->family<<endl;
					break;
		case('2'):  cout<<"The lesson of lector: "<<(link+i)->lesson<<endl;
					break;
		case('3'):  cout<<"The number of paper in administration: "<<(link+i)->paper<<endl;
					break;
		}
	cout<<"The id is "<<(link+i)->id<<endl;
	cout<<endl;
	}
	cout<<endl;
	system("pause");
	return 0;
}

char out()
{
	char work;
		system("cls");
		cout<<"Enter who is he.\n";
		cout<<"1 - if he is student.\n";
		cout<<"2 - if he is lector.\n";
		cout<<"3 - if he is administration employee.\n";
		cin>>work;
		return work;
}