#include "stdafx.h"
#include <iostream>

using namespace std;

class Circle;

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

class Square {
	int side;
public:
	void set_side(int a) 
	{
		side = a;
	}
	int getside()
	{
		return side;
	}
	friend class Circle;
};

class Circle {
	int rad;
public:
	void convert(Square s)
	{
		rad = s.side;
	}
	void set_rad(int a)
	{
		rad = a;
	}
	int getrad()
	{
		return rad;
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

	Square s1;
	Circle s2;
	s1.set_side(5);
	s2.set_rad(3);
	cout << "Before: ";
	cout << s1.getside() << " " << s2.getrad() << endl;
	s2.convert(s1);
	cout << "After: ";
	cout << s1.getside() << " " << s2.getrad() << endl;
	system("pause");
    return 0;
}