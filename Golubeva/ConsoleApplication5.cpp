// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	cout << "enter something\n";
	char s;
	cin >> s;
	if (isalpha (s))
		cout <<"It's letter. \n";
	else
		cout << "It's number";
	cin >> s;
	return 0;
}

