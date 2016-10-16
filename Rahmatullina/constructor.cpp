// ConsoleApplication8.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
        class SEG {
	    public:
			int x11,y11,x21,y21;
		SEG (int x1 ,int x2,int y1,int y2)
		{this->x11=2*x1;this->x21=2*x2;this->y11=2*y1;this->y21=2*y2;};
		};
	 int _tmain(int argc, _TCHAR* argv[])
{
	
	SEG seg(1,1,2,2);
	

    cout << seg.x11 << " " << seg.y11 << " " << " " << seg.x21 << " " << seg.y21;
	system ("pause");
	return 0;
}

