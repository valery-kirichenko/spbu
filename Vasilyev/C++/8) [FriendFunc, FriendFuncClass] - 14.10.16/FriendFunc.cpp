#include "stdafx.h"
#include <iostream>

using namespace std;

class Seg {
	int x, y;
public:
	void set_val(int x1, int y1) 
	{
		x = x1;
		y = y1;
	}
	friend Seg dup(Seg);
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
};

Seg dup(Seg source)
{
	Seg seg1;
	seg1.set_val(source.x * 2, source.y * 2);
	return seg1;
}

int main()
{
	Seg sec;
	sec.set_val(5, 5);
	Seg sec1;
	sec1 = dup(sec);
	cout << "Before: ";
	cout << sec.getx() << " " << sec.gety() << endl;
	cout << "After: ";
	cout << sec1.getx() << " " << sec1.gety() << endl;
	system("pause");
    return 0;
}