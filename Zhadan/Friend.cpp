// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

class SEG{	
	public:
	int x,y;
	void set_val(int,int);
	friend SEG dup();
};

void SEG::set_val(int a, int b)
{
	cout << a*2 << " " << b*2 << endl;
}

void dup(SEG &source)
{
	SEG seg1;
	seg1.set_val(source.x,source.y);
}


int main()
{
	SEG a;
	cin >> a.x >> a.y;
	
	dup(a);
	system("pause");
	return 0;
}

