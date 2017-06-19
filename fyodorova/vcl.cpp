#include "stdafx.h"
#include <iostream>
using namespace std;

class animal{
	int i;
public :
	void set (int b) {i = b;}
	virtual void print() {cout << i << " legs" << endl;}};

class cat : public  animal {
	
public :
	void print() {cout << 4 << " legs" << endl;}};

class spider : public animal {
	
public :
	void print() {cout << 8 << " legs" << endl;}};

class duck : public animal {
	
public :
	void print() {cout << 2 << " legs" << endl;}};




int main()
{
	animal a;
	cat c;
	spider s;
	duck d;
	
	c.print();
	s.print();
	d.print();

	system("pause");
	return 0;
}
