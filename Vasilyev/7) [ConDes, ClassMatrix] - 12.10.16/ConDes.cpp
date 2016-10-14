#include "stdafx.h"
#include <iostream>

using namespace std;

class cor{
	//private:
	public:
		int x1, x2;
		cor(int, int);
		void set(int, int);
		~cor();
	//protected:
};

cor::~cor()
{
	this->x1 = 0;
	this->x2 = 0;
}

cor::cor(int x1, int x2)
{
	this->x1 = 2*x1;
	this->x2 = 2*x2;
}

void cor::set(int xStart, int xFinish)
{
	x1 = xStart;
	x2 = xFinish;
}

int main()
{
	int a, b;
	cout << "Input a, b : ";
	cin >> a >> b;
	cout << "Number a: " << a << endl << "Number b: " << b << endl;
	system("pause");

	cor segment(a, b);
	cout << "Constructor has finished work!\n";
	a = segment.x1;
	b = segment.x2;
	cout << "Number a: " << a << endl << "Number b: " << b << endl;
	system("pause");

	segment.~cor();
	cout << "Destructor has finished work!\n";
	a = segment.x1;
	b = segment.x2;
	cout << "Number a: " << a << endl << "Number b: " << b << endl;
	system("pause");
	return 0;
}

