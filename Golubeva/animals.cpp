#include "stdafx.h"
#include <iostream>
using namespace std;

class animals{
public:
	int legs;
	void pr(){
		cout << legs;
	}
};

class cat: public animals{
public:
	void pr(){
		legs=4; 
		cout << "Cat has " << legs << " legs.\n";
	}
};

class kangaroo: public animals{
public:
	void pr(){
		legs=2; 
		cout << "Kangaroo has " << legs << " legs.\n";
	}
};

class snake: public animals{
public:
	void pr(){
		legs=0; 
		cout << "Snake has " << legs << " legs.\n";
	}
};

int main()
{
	cat Tom;
	kangaroo fighter;
	snake anakonda;
	Tom.pr();
	fighter.pr();
	anakonda.pr();
	system("pause");
	return 0;
}

