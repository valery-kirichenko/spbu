// 1210.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>;
using namespace std;
class SEG {
	
public: 
	int x1, x2;	
	SEG(int x1, int x2);
	~SEG() { x1 = 0;x2 = 0;cout << "\nZapyschen distructor " << endl << "Znacheniya " << x1 << " " << x2; system("pause"); }
};
SEG::SEG(int x1, int x2)
		{
	this->x1 = x1 * 2; this->x2 = x2 * 2; cout << "\nZapyschen constructor " << endl << "Znacheniya " << this->x1 << " " << this->x2;
		}
int main()
{
	int x1, x2;
	
	cout << "Vvedite znacheniya ";
	cin >> x1 >> x2;
	SEG seg(x1,x2);
	
    return 0;
}

