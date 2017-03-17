#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct STUDENT{
	string firstname;
	string lastname;
	int id;
};

void outID(struct STUDENT *ptr)
{
	cout << ptr->firstname << endl;
	cout << ptr->lastname << endl;
	cout << ptr->id << endl;
}


int main()
{
	STUDENT st[5];
	st[0].firstname = "Alex";
	st[0].lastname = "Larin";
	st[0].id = 1;

	st[1].firstname = "Ivan";
	st[1].lastname = "Ivanov";
	st[1].id = 2;

	st[2].firstname = "Alexander";
	st[2].lastname = "Filonov";
	st[2].id = 3;

	st[3].firstname = "Max";
	st[3].lastname = "Rokatanski";
	st[3].id = 4;

	st[4].firstname = "Zachary";
	st[4].lastname = "Comstock";
	st[4].id = 5;

	for (int i = 0; i < 5; i++)
	{	
		STUDENT *ptr = &st[i];
		outID(ptr);
	}
	system("pause");
	return 0;
}

