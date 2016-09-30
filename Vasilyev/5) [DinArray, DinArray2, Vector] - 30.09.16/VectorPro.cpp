#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int inp()
{
	string str;
	int b, x;
	bool k;
st:
	b = 0; x = 0;
	k = true;
	str.clear();
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
	{
		if (((str[i] < '0') | (str[i] > '9')) & (str[0] != '-')) {
			k = false;
			break;
		}
		if (str[i] == '-') {
			b++;
			if (b > 1) {
				k = false;
				break;
			}
		}
	}
	if (k == false) {
		cout << "Error! Wrong data! Try again.\n";
		goto st;
	}
	else {
		try
		{
			x = stoi(str);
			return x;
		}
		catch (...)
		{
			cout << "Error! Wrong data! Try again.\n";
			goto st;
		}
	}
	return 0;
}

int main()
{
	int n;
sv:
	cout << "Enter size of array: ";
	n = 0;
	n = inp();
	if (n <= 0) {
		cout << "Error! Wrong size! Try again.\n";
		goto sv;
	}
	vector <int> a(n);
	for (int i = 0; i < a.size(); i++)
	{
		cout << "Enter element " << i + 1 << " : ";
		a[i] = inp();
		cout << endl;
	}

	int min = a[0], max = a[0], sum = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
		sum += a[i];
	}
	cout << "Max = " << max << endl;
	cout << "Min = " << min << endl;
	cout << "Average = " << sum / a.size() << endl;
	system("pause");
	return 0;
}
