#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

typedef struct {
	int id;
	union{
		struct {
			string fn; 
			string ln;
			string ls;
			int pp;
		};
	};
}_employer;

void outID(_employer *ptr, int num)
{
	switch (num)
	{
		case 1:
			cout << ptr->fn << endl;
			cout << ptr->ln << endl;
			cout << ptr->id << endl;
			break;
		case 2: 
			cout << ptr->ls << endl;
			cout << ptr->id << endl;
			break;
		case 3:
			cout << ptr->pp << endl;
			cout << ptr->id << endl;
			break;
	}
}


int main()
{
	_employer st[3], lec[3], adm[3];
	st[0].fn = "Alex";
	st[0].ln = "Larin";
	st[0].id = 1;

	st[1].fn = "Max";
	st[1].ln = "Rokatanski";
	st[1].id = 2;

	st[2].fn = "Zachary";
	st[2].ln = "Comstock";
	st[2].id = 3;

	lec[0].ls = "English";
	lec[0].id = 10;

	lec[1].ls = "Programming";
	lec[1].id = 20;

	lec[2].ls = "IT";
	lec[2].id = 30;

	adm[0].pp = 15;
	adm[0].id = 100;

	adm[1].pp = 25;
	adm[1].id = 200;

	adm[2].pp = 38;
	adm[2].id = 300;

	for (int i = 0; i < 3; i++)
	{
		_employer *pts = &st[i];
		outID(pts, 1);
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		_employer *ptl = &lec[i];
		outID(ptl, 2);
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		_employer *pta = &adm[i];
		outID(pta, 3);
	}
	cout << endl;
	system("pause");
	return 0;
}