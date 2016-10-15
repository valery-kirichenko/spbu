#include "stdafx.h"
using namespace std;

class SEG
{
public:
int x1, y1;
SEG (int, int);
~SEG ();
void set(int , int);
void put();
};


SEG::SEG (int x1, int y1)
{
	cout<<"------------------Внутри конструктора--------------------"<<endl;
	this->x1=x1;
	this->y1=y1;

	char x;
	cout<<"1 - input a, b & output a, b\n";
	cout<<"2 - input a, b & output 2a, 2b\n";
	cin>>x;
	switch (x)
		{
		case '1': break;
		case '2':	x1 *= 2; 
					y1 *= 2; 
					break;
		}

	cout<<"a = "<<x1<<endl;
	cout<<"b = "<<y1<<endl;
}

SEG::~SEG ()
{
	cout<<"------------------Внутри деструктора---------------------"<<endl;
	x1 = 0;
	y1 = 0;
	
};

void SEG::set(int xs,int ys)
{
x1 = xs;
y1 = ys;
}

void SEG::put()
{
cout<<"x1 = "<<x1<<endl;
cout<<"y1 = "<<y1<<endl;
}

int main()
{
	setlocale(LC_ALL, "");
	int a, b;
	


	SEG s(a, b);

	system("pause");
	return 0;
}

