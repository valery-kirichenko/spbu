// Classes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

class Obj{
	private:
	public:
		int Int1, Int2;
		Obj(int Int1, int Int2);
		~Obj(){
			cout << "\nDestructor is called";
			_getch();
		};
};

Obj::Obj (int Int1, int Int2){
			this->Int1 = Int1*2;
			this->Int2 = Int2*2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	int a,b;
	cout << "Enter 2 numbers: \n";
	cin >> a >> b;
	cout << "Given numbers: " << a << " and " << b << endl;
	Obj object(a, b);
	cout << "Processed numbers: " << object.Int1 << " and " << object.Int2;
	_getch();
	return 0;
}

