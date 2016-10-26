

#include "stdafx.h"
#include "iostream"

using namespace std;

class Animal{	
public:
	virtual void print(){};
};

class Dog : public Animal
{
public:
	void print(){cout << 4 << endl;}
};

class Man : public Animal
{
public:
	void print(){cout << 2 << endl;}
};

class Sneak : public Animal
{
public:
	void print(){cout << 0 << endl;}
};

int main()
{

	Dog b;
	Man c;
	Sneak a;
	
	b.print();
	c.print();
	a.print();


	system("pause");
	return 0;
}

