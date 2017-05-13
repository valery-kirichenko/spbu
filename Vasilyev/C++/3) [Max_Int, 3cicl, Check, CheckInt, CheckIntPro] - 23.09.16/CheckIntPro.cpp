#include "stdafx.h"
#include <iostream>
#include <string>

bool inp(std::string &str)	//input checking fuction
{
	int b = 0;
	bool k = true;
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
		return false;
	}
	else {
		return true;
	}
}

int main()
{
	std::string s;
	std::cout << "Enter integer: ";
	std::getline(std::cin, s);
	if (inp(s))
		std::cout << "It's number!\n";
	else	
		std::cout << "It's not number.\n";
	system("pause");
	return 0;
}