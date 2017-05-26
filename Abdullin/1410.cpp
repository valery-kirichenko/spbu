// 1410.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class MAT;
class SEG{
int x,y;
public:
	void set_val(int a, int b)
	{
		
		x = a;
		y = b;
	};
friend SEG dup(SEG);
friend class MAT;
void get_val()
{
	cout << "Znach " << x <<" "<< y<<"\n";
};
};
SEG dup(SEG source) {
	SEG seg1;
	seg1.set_val(source.x * 2, source.y * 2);
	return seg1;
}
class MAT
{
	int z, c;
public:
	void conv(SEG seg)
	{
		z = seg.x+1;
		c = seg.y+1;
	};
	void set_val(int a, int b)
	{
		z = a;
		c = b;
	}
	void get_val()
	{
		cout << "Znach " << z << " " << c << "\n";
	};

};

int main()
{
	SEG x;
	x.set_val(5,6);
	x=dup(x);
	x.get_val();
	MAT mat;
	mat.conv(x);
	mat.get_val();
	system("pause");
	return 0;
}

