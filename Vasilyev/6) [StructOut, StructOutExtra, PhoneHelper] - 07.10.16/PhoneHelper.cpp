#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

typedef struct {
	string number;
	string firstname;
	string lastname;
	string town;
}phoneHelp;

int inp(string &mes)
{
	string str;
	int b = 0, x = 0;
	bool k = true;
	while (true)
	{
		b = 0; x = 0;
		k = true;
		cout << mes;
		str.clear();
		getline(cin, str);
		for (unsigned int i = 0; i < str.size(); i++)
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
			}
		}
	}
}

void outID(phoneHelp *ptr)
{
	cout << ptr->number << endl;
	cout << ptr->firstname << endl;
	cout << ptr->lastname << endl;
	cout << ptr->town << endl;
}


int main()
{
	int n, count = 0;
	phoneHelp Lib[1000];
	string mes = "Enter command: ";
	while (true)
	{
		cout << "1) Add new contact;\n";
		cout << "2) Out all contacts;\n";
		cout << "3) Exit;\n";
		n = inp(mes);

		if (n == 1) {
			cout << "Enter the number: ";
			cin >> Lib[count].number;
			cout << "Enter the firsname: ";
			cin >> Lib[count].firstname;
			cout << "Enter the lastname: ";
			cin >> Lib[count].lastname;
			cout << "Enter the town: ";
			cin >> Lib[count].town;
			cout << count + 1 << " number was successfully added!\n" << endl;
			count++;
			string buff;
			getline(cin, buff);
		}

		else if (n == 2) {
			phoneHelp *ptr;
			cout << endl;
			if (count == 0)
				cout << "No any numbers!\n" << endl;
			else
				for (int i = 0; i < count; i++)
				{
					cout << i + 1 << " contact\n";
					ptr = &Lib[i];
					outID(ptr);
					putchar('\n');
				}
		}

		else if (n == 3) {
			system("pause");
			return 0;
		}
		else
			cout << "Error! Enter your command again.\n" << endl;
	}
}