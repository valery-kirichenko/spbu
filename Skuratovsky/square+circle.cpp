#include <iostream>
//#include <cstdlib>
//#include <random>
using namespace std;

class Circle;
//class Square;

class Square {
	int side;
public:
	void set_side (int a){side=a;}
	void show_side() {cout<<side<<endl;}
	friend class Circle;

};
class Circle {
	int rad;
public:
	void set_rad(int a) {rad=a;}
	void show_rad() {cout<<rad<<endl;}
	void convert(const Square& a)
	{rad=a.side;}

};

int main()
{
	Square a;
	Circle b;
	a.set_side(5);
	b.set_rad(10);
	a.show_side();
	b.show_rad();
	b.convert(a);
	b.show_rad();
	cout<<
	system("pause");




	return 0;
}
