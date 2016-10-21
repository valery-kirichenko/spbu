#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

const int maxi = 1000;
const int leng=20;

struct phonebook
{
	int phone;
	char name[leng];
	char family[leng];
	char profession[leng];
	union
	{
		struct{int card;};
		struct{char lesson[leng];};
		struct{int paper;};
	};
};

static int number;
void add(phonebook *link);
void out(phonebook *link);
bool compare(phonebook *ptr, char line[leng]);
void search(phonebook *link);
void compare_n(phonebook *link);
void compare_f(phonebook *link);
void compare_p(phonebook *link);

int main()
{
	setlocale(LC_ALL, " ");
	char x = ' ';
	phonebook *link, people[maxi];
	link = people;
	number = 0;

while (x!='0')
{
	cout<<"Welcome to the programm \"Phonebook\""<<endl;
	cout<<"Enter the number from list below."<<endl;
	cout<<"\"0\" - Leave the programm."<<endl;
	cout<<"\"1\"  - Add person in the phonebook."<<endl;
	cout<<"\"2\"  - Find person from the phonebook."<<endl;
	cout<<"\"3\"  - Display all phonebook."<<endl;
	cin>>x;
	switch(x)
	{
	case '0': 
		break;
	case '1': 
		add(link);
		break;
	case '2': 
		search(link);
		break;
	case '3': 
		out(link);
		break;
	}
}
	system("cls");
	cout<<"--------Thank you for what you choose us.-----"<<endl;
	system("pause");
	return 0;
}

void add(phonebook *link)
{
char line[leng];
int x, i, j, f;
system("cls");
number++;

cout<<"Name: ";
cin>>(link+number-1)->name;
cout<<"Family: ";
cin>>(link+number-1)->family;
cout<<"Phone number: ";
cin>>(link+number-1)->phone;
cout<<"Profession: ";
cin>>(link+number-1)->profession;
if (compare((link+number-1), "student")) f = 1;
else if (compare((link+number-1), "lector")) f = 2;
else f = 3;
switch(f)
	{
case(1):    cout<<"The number of student card: ";
					cin>>x;
					(link+number-1)->card = x;
					break;
case(2):     cout<<"The title of lesson: ";
					cin>>line;
					for (j=0;j<strlen(line);j++)(link+number-1)->lesson[j] = line[j];
					break;
case(3):      cout<<"The number of lists of paper: ";
					cin>>x;
					(link+number-1)->paper = x;
					break;
	}
}

void out(phonebook *link)
{
	int f;

	system("cls");
	for (int i=1;i<=number;i++)
	{
cout<<"------------------------------------------------------------"<<endl;
cout<<"Name: "<<(link+i-1)->name<<endl;
cout<<"Family: "<<(link+i-1)->family<<endl;
cout<<"Phone number: "<<(link+i-1)->phone<<endl;
if (compare((link+i-1), "student")) f = 1;
else if (compare((link+i-1), "lector")) f = 2;
else f = 3;
	switch(f)
		{
	case(1):		cout<<"Profession - student"<<endl;
					cout<<"The number of student card: "<<(link+i-1)->card<<endl;
					break;
	case(2):		cout<<"Profession - lector"<<endl;
					cout<<"The title of lesson: "<<(link+i-1)->lesson<<endl;
					break;
	case(3):		cout<<"Profession - administration worker"<<endl;
					cout<<"The number of list of paper: "<<(link+i-1)->paper<<endl;
					break;
		}
cout<<"------------------------------------------------------------"<<endl;
	}
}

bool compare(phonebook *ptr, char line[leng])
{
	int i;
	bool flug=true;

	for(i=0;i<strlen(line);i++)
		if (ptr->profession[i] != line[i]) flug=false;
	return flug;
}
void search(phonebook *link)
{
	char x;

	system("cls");
	cout<<"What are you know about this person\n";
	cout<<"Enter the number from list below."<<endl;
	cout<<"\"1\"  - Name."<<endl;
	cout<<"\"2\"  - Family."<<endl;
	cout<<"\"3\"  - Phone."<<endl;
	cin>>x;
	switch(x)
	{
	case('1'):
		compare_n(link);
		break;
	case('2'):
		compare_f(link);
		break;
	case('3'):
		compare_p(link);
		break;
	}
}

void compare_n(phonebook *link)
{
	int i, j, f;
	char name[leng];
	bool flug = true;

	system("cls");
	cout<<"Enter the name of this person\n";
	cin>>name;
	for(j=1;j<=number;j++)
	{
	flug = true;
	for(i=0;i<strlen(name);i++)
		if ((link+j-1)->name[i] != name[i]) flug = false;
	if (flug)
		{
cout<<"------------------------------------------------------------"<<endl;
cout<<"Name: "<<(link+j-1)->name<<endl;
cout<<"Family: "<<(link+j-1)->family<<endl;
cout<<"Phone number: "<<(link+j-1)->phone<<endl;
if (compare((link+j-1), "student")) f = 1;
else if (compare((link+j-1), "lector")) f = 2;
else f = 3;
	switch(f)
		{
	case(1):		cout<<"Profession - student"<<endl;
					cout<<"The number of student card: "<<(link+j-1)->card<<endl;
					break;
	case(2):		cout<<"Profession - lector"<<endl;
					cout<<"The title of lesson: "<<(link+j-1)->lesson<<endl;
					break;
	case(3):		cout<<"Profession - administration worker"<<endl;
					cout<<"The number of list of paper: "<<(link+j-1)->paper<<endl;
					break;
		}
cout<<"------------------------------------------------------------"<<endl;
return ;
		}
	}
	cout<<"Sorry, but person with this name did not find."<<endl;
}

void compare_f(phonebook *link)
{
int i, j, f;
	char name[leng];
	bool flug = true;

	system("cls");
	cout<<"Enter the name of this person\n";
	cin>>name;
	for(j=1;j<=number;j++)
	{
	flug = true;
	for(i=0;i<strlen(name);i++)
		if ((link+j-1)->family[i] != name[i]) flug = false;
	if (flug)
		{
cout<<"------------------------------------------------------------"<<endl;
cout<<"Name: "<<(link+j-1)->name<<endl;
cout<<"Family: "<<(link+j-1)->family<<endl;
cout<<"Phone number: "<<(link+j-1)->phone<<endl;
if (compare((link+j-1), "student")) f = 1;
else if (compare((link+j-1), "lector")) f = 2;
else f = 3;
	switch(f)
		{
	case(1):		cout<<"Profession - student"<<endl;
					cout<<"The number of student card: "<<(link+j-1)->card<<endl;
					break;
	case(2):		cout<<"Profession - lector"<<endl;
					cout<<"The title of lesson: "<<(link+j-1)->lesson<<endl;
					break;
	case(3):		cout<<"Profession - administration worker"<<endl;
					cout<<"The number of list of paper: "<<(link+j-1)->paper<<endl;
					break;
		}
cout<<"------------------------------------------------------------"<<endl;
return ;
		}
	}
	cout<<"Sorry, but person with this family did not find."<<endl;
}

void compare_p(phonebook *link)
{
	int i, j, f, x;
	bool flug = false;

	system("cls");
	cout<<"Enter the phone number of this person: ";
	cin>>x;
	for(j=1;j<=number;j++)
	{
	if (link->phone == x) flug = true;
	if (flug)
		{
cout<<"------------------------------------------------------------"<<endl;
cout<<"Name: "<<(link+j-1)->name<<endl;
cout<<"Family: "<<(link+j-1)->family<<endl;
cout<<"Phone number: "<<(link+j-1)->phone<<endl;
if (compare((link+j-1), "student")) f = 1;
else if (compare((link+j-1), "lector")) f = 2;
else f = 3;
	switch(f)
		{
	case(1):		cout<<"Profession - student"<<endl;
					cout<<"The number of student card: "<<(link+j-1)->card<<endl;
					break;
	case(2):		cout<<"Profession - lector"<<endl;
					cout<<"The title of lesson: "<<(link+j-1)->lesson<<endl;
					break;
	case(3):		cout<<"Profession - administration worker"<<endl;
					cout<<"The number of list of paper: "<<(link+j-1)->paper<<endl;
					break;
		}
cout<<"------------------------------------------------------------"<<endl;
return ;
		}
	}
	cout<<"Sorry, but person with this phone number did not find."<<endl;
}