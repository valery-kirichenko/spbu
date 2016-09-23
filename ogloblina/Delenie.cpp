// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int k, m;
	cout << "Enter numbers k,m" << endl;
	cin >> k >> m;
	try { if (m == 0) { throw 4; } }
	catch (int i)
	{
		cout << "Error " << i << ". Change m (except 0)" << endl;
	}
	cout << "k/m =" << k / m << endl;
    return 0;
}

