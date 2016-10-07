#include "stdafx.h"
#include <iostream> 
using namespace std;

int main()
{
	struct st {string name; string fname; int id; int age;};
	struct st mst[3];
	mst[0].name="Ivan";
	mst[0].fname="Ivanov";
	mst[0].id=1;
	mst[0].age=17;

	mst[1].name="Alexander";
	mst[1].fname="Alexandrov";
	mst[1].id=2;
	mst[1].age=19;

	mst[2].name="Anna";
	mst[2].fname="Fedotova";
	mst[2].id=3;
	mst[2].age=18;

	for (int i=0; i<3; i++)
	{
		cout << mst[i].fname << ' ' << mst[i].name << ' ' << "ID: " << mst[i].id << " Age: " << mst[i].age << endl;
	}

	return 0;
}

