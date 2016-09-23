#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, m, k = 0;
	string s;
	cout << "Enter integer : ";
	cin >> s;
	cout << endl;
	try	{
		n = stoi(s);
	}
	catch (...) {
		cout << "Error";
		return 0;
	}
	cout << "Good!";
	return 0;
}