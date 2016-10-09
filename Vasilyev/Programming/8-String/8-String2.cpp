#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	int k = 0, k1 = 0, k2 = 0, n = -1;
	bool ch = false;
	char buff[256];											//buffer array
	string s, s1, s2;
	ifstream input("input.txt");							//input data file
	ofstream output("output.txt");							//output data file
	if (!input.is_open()) {
		cout << "ER01: Input error!\n";						//check input file
		system("pause");
		return 1;
	}

	cout << "Enter word you want to replace: ";
	getline(cin, s1);										//entering replaced word
	k = s1.length();										//size of replaced word
	cout << "Enter new word: ";
	getline(cin, s2);
	while (!input.eof())									//reading before the end of input file
	{
		input.getline(buff, 256);							//getting array of symbols of the line
		k1 = strlen(buff);									//count size of line
		s = buff;											//string equal char's array
		n = s.find(s1);
		while (n != -1)
		{
			//n = s.find(s1);								//finding replaced word in current line
			if (n != -1) {									//if we finding replaced word, we replace this word with new word
				s.replace(n, k, s2);
				ch = true;
				//s.erase(n, k);
				//s.insert(n, s2);
			}
			n = s.find(s1);
		}
		//cout << n << endl;
		output << s << endl;								//writing new line in output file
	}

	if (ch == false)
		cout << "Didn't find replaced word!\n";
	input.close();
	output.close();											//close input and output files
	system("pause");
	return 0;
}