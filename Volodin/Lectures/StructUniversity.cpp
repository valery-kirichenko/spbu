#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

const int k = 100;
const int lim = 1000;
const int len = 20;

char get();
int main()
{
	struct student
	{
		int id;
		char profession;
		union
		{
			struct { public: char name[len]; char family[len]; };
			struct { public: char lesson[len]; };
			struct { public: int paper; };
		};
	};

	int i, x;
	char work;
	char n[20];

	student *link, people[k];
	link = people;
	cout << "Enter the number of people: ";
	cin >> x;
	for (i = 0; i < x; i++)
	{
		work = get();
		while (work > '3' || work < '1') {
			cout << "Wrong\n"; work = get();
		}
		(link + i)->profession = work;
		srand(time(NULL));
		(link + i)->id = rand() % lim;
		switch (work)
		{
		case('1'):  cout << "Enter the name of student: ";
			cin >> (link + i)->name;
			cout << "Enter the family of student: ";
			cin >> (link + i)->family;
			break;
		case('2'):  cout << "Enter the lesson of lector: ";
			cin >> (link + i)->lesson;
			break;
		case('3'):  cout << "Enter the number of paper in administration: ";
			cin >> (link + i)->paper;
			break;
		}
	}
	system("cls");

	for (i = 0; i < x; i++)
	{
		cout << "Person number " << i << ":\n";
		switch ((link + i)->profession)
		{
		case('1'):  cout << "Name: " << (link + i)->name << endl;
			cout << "Family: " << (link + i)->family << endl;
			break;
		case('2'):  cout << "Lesson: " << (link + i)->lesson << endl;
			break;
		case('3'):  cout << "Number of paper: " << (link + i)->paper << endl;
			break;
		}
		cout << "The id is " << (link + i)->id << endl;
		cout << endl;
	}
	cout << endl;
}

char get()
{
	char work;
	system("cls");
	cout << "1 - student.\n";
	cout << "2 - lector.\n";
	cout << "3 - administration\n";
	cin >> work;
	return work;
}