#include "stdafx.h"
#include <iostream>

using namespace std;
class SEG
{
	int x1,x2;
	public:
	SEG(int,int);
	~SEG ();
};

SEG::SEG(int x1, int x2)
{
	this->x1=x1;
	this->x2=x2;
	cout << "Constructor done" << endl;	
	cout << "a = " << x1 << endl;
	cout << "b = " << x2 << endl;
}

SEG::~SEG()
{
	cout << "Destructor done" << endl;
	this->x1 = 0;
	this->x2 = 0;
	cout << "a = " << x1 << endl;
	cout << "b = " << x2 << endl;
	system("pause");
}



int main()
{
	int a,b;
	cout << "Press a: " ;
	cin >>  a;
	cout << endl << "Press b: " ;
	cin >>  b;
	
	SEG SEG(a,b);

	return 0;
}
