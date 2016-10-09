#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	const int bsize = 256;
	vector<string> words;
	words.reserve(bsize);
	vector<string> nwords;
	nwords.reserve(bsize);
	vector<string> inp;
	inp.reserve(bsize);
	int k = 0, k1 = 0, n = -1, n1= -1, n2 = -1, n3 = -1, num = 0;
	bool ch = false, flag = true;
	char buff[bsize], ds[] = "#define ", us[] = "#undef ";			//buffer arrays
	string s, s1, s2, s3, sd, su;
	sd = ds;
	su = us;
	ifstream input("input.txt");									//input data file
	ofstream output("output.txt");									//output data file
	if (!input.is_open()) {
		cout << "ER01: Input error!\n";								//check input file
		output << "ER01: Input error!\n";
		std::system("pause");
		return 1;
	}
	while (!input.eof())											//reading before the end of input file
	{
		input.getline(buff, 256);									//getting array of symbols of the line
		k = strlen(buff);											//count size of line
		s = buff;													//string equal char's array
		n = s.find(sd);												//finding replaced word in current line
		if (n != -1) {												//if we finding replaced word, we add this word to vector
			n1 = s.find(" ");
			s.erase(n1, 1);
			n2 = s.find(" ");
			s.insert(n1, " ");
			s1 = s.substr(n1+1, n2-n1);								//replaced instruction
			s2 = s.substr(n2+2, k);									//new instruction
			ch = true;
			if (num >= 256) {
				cout << "ER02: Overflow number of instruction!\n";	//check size of vector
				output << "ER02: Overflow number of instruction!\n";
				std::system("pause");
				return 2;
			}
			else {
				words.push_back(s1);								//add word to vector
				nwords.push_back(s2);								//add new value to vector
				num++;
			}
		}
	//cout << n << endl;
	}
	input.seekg(SEEK_SET);
	while (!input.eof())											//reading before the end of input file
	{
		input.getline(buff, 256);									//getting array of symbols of the line
		s = buff;													//string equal char's array
		inp.push_back(s);
	}
	for (int i = 0; i < words.size(); i++)
	{
		flag = true;
		s1 = words[i];												//replaced word
		s2 = nwords[i];												//new word
		k = s1.size();
		for (int j = 0; j < inp.size(); j++)						//reading from vector
		{
			s = inp[j];												//string from vector
			k1 = s.size();
			n = s.find(s1);
			n1 = s.find(sd);
			n2 = s.find(su);
			if (n2 != -1) {
				n3 = s.find(" ");
				s.erase(n3, 1);
				s.insert(n3, " ");
				s3 = s.substr(n3 + 1, k1);
				if (s3 == s1) {
					flag = false;
					break;
				}
			}
			if (flag == false) {
				continue;
			}
			while ((n != -1) & (n1 == -1) & (n2 == -1))
			{														//finding replaced word in current line
				if (n != -1) {										//if we finding replaced word, we replace this word with new word
					s.replace(n, k, s2);
					//ch = true;
					//s.erase(n, k);
					//s.insert(n, s2);
				}
				n = s.find(s1);				
			}
			inp[j] = s;												//writing new line in output file
			//cout << n << endl;
		}
	}
	for (int i = 0; i < inp.size(); i++)
		output << inp[i] << endl;
	if (ch == false)
		cout << "Didn't find instruction!\n";
	else
		cout << "Good job well done!\n";
	input.close();
	output.close();													//close input and output files
	std::system("pause");
	return 0;
}