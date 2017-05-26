#include "stdafx.h"
#include <iostream>

using namespace std;

class ANIMAL
{
protected:
	int i;
public:
	void set(int b){i=b;}
	virtual void print(){cout<<"ANIMAl \n";}
};

class DOG:public ANIMAL
{
public:
	void print(){cout<<"Dog "<<i<<"\n";}
};

class SPIDER:public ANIMAL
{
public:
	void print(){cout<<"Spider "<<i<<"\n";}
};

class DUCK:public ANIMAL
{
public:
	void print(){cout<<"Duck "<<i<<"\n";}
};

int _tmain(int argc, _TCHAR* argv[])
{
	ANIMAL a;
	ANIMAL*ptr=&a;
	DOG b;
	SPIDER c;
	DUCK d;
	a.set(0);
	b.set(4);
	c.set(8);
	d.set(2);
	ptr->print();
	ptr=&b;
	ptr->print();
	ptr=&c;
	ptr->print();
	ptr=&d;
	ptr->print();
	system("pause");
	return 0;
}

