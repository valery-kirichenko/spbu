#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

bool mon = false, retry = false;

int inp(std::string &m)																				//input checking fuction
{
	std::string str;
	int b = 0, x = 0;
	bool k = true, flag = true;
	while (flag)
	{
		b = 0; x = 0;
		k = true;
		str.clear();
		std::cout << m;
		std::getline(std::cin, str);
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
			std::cout << "Error! Wrong data! Try again.\n" << std::endl;
		}
		else {
			try
			{
				x = std::stoi(str);
				return x;
			}
			catch (...)
			{
				std::cout << "Error! Wrong data! Try again.\n" << std::endl;
			}
		}
	}
	return 0;
}

int outWord(std::string &w, std::vector<bool> &v, std::vector<char> &c, std::string str[])			//output fuction
{
	int kol = 0;
	std::system("cls");
	std::cout << "Game phase\n";
	std::cout << "Known letters: ";
	for (unsigned int i = 0; i < c.size(); i++) {
		if (c[i] >= 65 && c[i] <= 90)
			c[i] = c[i] + 32;
		std::cout << c[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 7; i++) {
		for (unsigned int j = 0; j < str[i].size(); j++)
			std::putchar(str[i][j]);
		std::putchar('\n');
	}
	std::cout << " ";
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == true) {
			std::cout << w[i] << " ";
			kol++;
		}
		else if (w[i] == ' ') {
			std::cout << " ";
			v[i] = true;
			kol++;
		}
		else
			std::cout << "_ ";
	}
	std::cout << std::endl;
	if (kol == w.size())
		return 1;
	else
		return 0;
}

bool chWord(char &var, std::string &w, std::vector<bool> &v, std::vector<char> &c)				//function which watching for chars and opening letters in hiden word
{
	bool flag = false;
	char var2 = ' ';
	int ck = 0;
	retry = false;
	if ((var >= 65) & (var <= 90))
		var2 = var + 32;
	else if ((var >= 97) & (var <= 122))
		var2 = var - 32;
	
	for (unsigned int i = 0; i < v.size(); i++)
		if ((var == w[i]) | (var2 == w[i])) {
			if (v[i] == false) {
				v[i] = true;
				flag = true;
			}
		}
	if (flag == true) {
		if (mon == true)
			c.push_back(var);
		return true;
	}
	else {
		if (mon == true) {
			for (unsigned int i = 0; i < c.size(); i++)
				if (var != c[i])
					ck++;
			if (ck == c.size()) {
				c.push_back(var);
			}
			else {
				retry = true;
				return false;
			}
		}
		return false;
	}
}

bool checkChars(std::string word)																//function which checking entered string
{
	std::vector<char> count;
	count.reserve(1000);
	for (unsigned int i = 0; i < word.size(); i++)
		if ((word[0] >= 65) & (word[0] <= 90))
			word[i] = word[i] + 32;

	count.push_back(word[0]);
	bool uniq = true;
	for (unsigned int i = 0; i < word.size(); i++)
	{
		uniq = true;
		for (unsigned int j = 0; j < count.size(); j++)
			if (word[i] == count[j])
				uniq = false;
		if (uniq == true)
			count.push_back(word[i]);
	}
	if (count.size() > 2)
		return true;
	else
		return false;
}

void gameMode(std::string &word, std::string hangman[])									//game function
{
	int k = 6;
	std::vector<char> buk;
	buk.reserve(26);
	
	std::cout << "Prepare for game\n";
	std::system("pause");
	std::system("cls");
	std::cout << "Game phase\n";
	std::vector<bool> check(word.size());
	for (unsigned int i = 0; i < check.size(); i++)
		check[i] = false;
	check[0] = true;
	check[check.size() - 1] = true;
	char w0, w2;
	w0 = word[0];
	w2 = word[word.size() - 1];
	if ((word[0] >= 65) & (word[0] <= 90))
		w0 = word[0] + 32;
	if ((word[word.size() - 1] >= 65) & (word[word.size() - 1] <= 90))
		w2 = word[word.size() - 1] + 32;

	if (w0 == w2) {
		buk.push_back(word[0]);
		chWord(word[0], word, check, buk);
	}
	else {
		buk.push_back(word[0]);
		buk.push_back(word[word.size() - 1]);
		chWord(word[0], word, check, buk);
		chWord(word[word.size() - 1], word, check, buk);
	}
	mon = true;
	outWord(word, check, buk, hangman);
	std::putchar('\a');

	bool process = true, beck = false;
	while (process)
	{
		if (k == 6)
			std::cout << "You have " << k << " attempts.\n";
		if ((k < 6) & (k > 1))
			std::cout << "Wrong letter!" << "You have " << k << " attempts.\n";
		if (k == 1)
			std::cout << "Wrong letter!" << "You have last attempt.\n";
		std::cout << "Enter your letter ~'0' - return back~ : ";
		char var = ' ';
		std::cin >> var;
		std::cout << std::endl;
		std::string buff = "";
		std::getline(std::cin, buff);
		if ((var == '0') & (buff.empty())) {
			beck = true;
			std::cout << "Answer: " << word << std::endl;
			process = false;
		}
		else if (!buff.empty()) {
				std::cout << "Error! You try to enter more than one char! Enter your letter again.\n";
				std::system("pause");
				std::system("cls");
				outWord(word, check, buk, hangman);
			}
			else if (((var < 65) | (var > 90)) & ((var < 97) | (var > 122))) {														//1025 + 1040-1071, 1072-1103 + 1105 russian unicode
					std::cout << "You entered not only letters! Try again.\n";														// -32=-1, -64=-33, -72, -88
					std::system("pause");
					std::system("cls");
					outWord(word, check, buk, hangman);
				}
				else if (chWord(var, word, check, buk) == true) {
						if (outWord(word, check, buk, hangman) == 1) {
							std::cout << "You won!\n";
							std::putchar('\a');
							process = false;
						}
					}
					else {
						if (retry == true) {
							std::cout << "You entered known letter!. Try again.\n";
							std::system("pause");
							std::system("cls");
							outWord(word, check, buk, hangman);
						}
						else {
							k--;
							switch (k)
							{
							case 5:
								hangman[3][6] = (char)79;
								break;
							case 4:
								hangman[4][6] = (char)124;
								break;
							case 3:
								hangman[4][5] = (char)47;
								break;
							case 2:
								hangman[4][7] = (char)92;
								break;
							case 1:
								hangman[5][5] = (char)47;
								break;
							case 0:
								hangman[5][7] = (char)92;
								break;
							}
							outWord(word, check, buk, hangman);
							std::putchar('\a');
							if (k == 0) {
								std::cout << "You lost!\n";
								std::cout << "Answer: " << word << std::endl;
								process = false;
							}
						}
					}
	}
	if (beck == true)
		std::cout << "Game over!\n";
	std::system("pause");
	std::putchar('\a');
}

void draw(std::string str[])
{
	std::cout << " ............................................................................." << std::endl;
	std::cout << " ....##.....##....###....##....##..#######...##.....##....###....##....##....." << std::endl;
	std::cout << " ....##.....##...##.##...###...##.##.....##..###...###...##.##...###...##....." << std::endl;
	std::cout << " ....##.....##..##...##..####..##.##.........####.####..##...##..####..##....." << std::endl;
	std::cout << " ....#########.##.....##.##.##.##.##..######.##.###.##.##.....##.##.##.##....." << std::endl;
	std::cout << " ....##.....##.#########.##..####.##.....##..##.....##.#########.##..####....." << std::endl;
	std::cout << " ....##.....##.##.....##.##...###.##.....##..##.....##.##.....##.##...###....." << std::endl;
	std::cout << " ....##.....##.##.....##.##....##..#######...##.....##.##.....##.##....##....." << std::endl;
	std::cout << " ............................................................................." << std::endl << std::endl;
	/*for (int i = 0; i < 7; i++) {
		for (int j = 0; j < str[i].size(); j++)
			putchar(str[i][j]);
		putchar('\n');
	}*/
}

void intro()
{
	//					1				2				3				4					5				6				7
	std::cout << "  _____    " << "  _____    " << "  _____    " << "  _____    " << "  _____    " << "  _____    " << "  _____    " << std::endl;
	std::cout << "  | / |    " << "  | / |    " << "  | / |    " << "  | / |    " << "  | / |    " << "  | / |    " << "  | / |    " << std::endl;
	std::cout << "  |/  |    " << "  |/  |    " << "  |/  |    " << "  |/  |    " << "  |/  |    " << "  |/  |    " << "  |/  |    " << std::endl;
	std::cout << "  |        " << "  |   O    " << "  |   O    " << "  |   O    " << "  |   O    " << "  |   O    " << "  |   O    " << std::endl;
	std::cout << "  |        " << "  |        " << "  |   |    " << "  |  /|    " << "  |  /|\\   " << "  |  /|\\   " << "  |  /|\\   " << std::endl;
	std::cout << "  |        " << "  |        " << "  |        " << "  |        " << "  |        " << "  |  /     " << "  |  / \\   " << std::endl;
	std::cout << "__|________\a" << "__|________\a" << "__|________\a" << "__|________\a" << "__|________\a" << "__|________\a" << "_|________\a" << std::endl;
}

int main()
{
	//Main body
	std::cout << "Hello, human!\n";
	std::system("pause");

	while (true)
	{
		std::system("cls");
		std::string hangman[7] = {
			"  _____    ",
			"  | / |    ",
			"  |/  |    ",
			"  |   O    ",
			"  |  /|\\   ",
			"  |  / \\   ",
			"__|________"
		};
		int variant, k = 6;
		std::string word, buff, mes, s;
		std::vector<char> buk;
		buk.reserve(26);
		std::vector<std::string> inpt;
		inpt.reserve(1000);
		mon = false;
		draw(hangman);
		intro();
		hangman[3][6] = (char)32;																						//1 step
		hangman[4][5] = (char)32;																						//2 step
		hangman[4][6] = (char)32;																						//3 step
		hangman[4][7] = (char)32;																						//4 step
		hangman[5][5] = (char)32;																						//5 step
		hangman[5][7] = (char)32;																						//6 step

		std::cout << "Choose the variant of game: \n";
		std::cout << "1) PvE (game player vs. environment - need file 'input.txt' in this folder, but not more than 1000 words in file);\n";
		std::cout << "2) PvP (game player vs. player);\n";
		std::cout << "3) Exit;\n";
		bool game = true, back = false;
		while (game)
		{
			mes = "Enter your command: ";
			variant = inp(mes);
			std::cout << std::endl;
			if ((variant != 1) & (variant != 2) & (variant != 3)) {
				std::cout << "Error! Wrong data! Try again.\n";
			}


			//PvE mode
			else if (variant == 1) {
				int strnum = 0, numstr;
				std::ifstream input("input.txt");																		//input data file
				if (!input.is_open()) {
					std::system("cls");
					std::cout << "ER01: Input error! Didn't find file 'input.txt' in folder.\n";						//check input file
					std::system("pause");
					break;
					//return 1;
				}
				bool rage = true;
				while (!input.eof())																					//reading before the end of input file
				{
					std::getline(input, s);																				//getting array of symbols of the line
					strnum++;
					if (strnum > 1000) {
						inpt.clear();
						rage = false;
						std::system("cls");
						std::cout << "ER02: Out of range! Too many (>1000) words in input file!\n";
						std::system("pause");
						break;
						//return 2;
					}
					inpt.push_back(s);
				}
				s.clear();
				if (rage == false)
					break;
				srand(time(0));
				numstr = rand() % strnum;																				//random number from 0-188
				word = inpt[numstr];
				inpt.clear();
				bool worcdcheck = true;
				if (word.size() < 3) {
					std::cout << "Error! You entered little word! Try again.\n";
					worcdcheck = false;
				}
				else if (checkChars(word) == false) {
					std::cout << "Error! Word consists of only two letters! Fix it in input file.\n";
					worcdcheck = false;
					}
					else {
						for (unsigned int i = 0; i < word.size(); i++)
							if ((i == 0) | (i == word.size() - 1)) {
								if ((((char)word[i] < 65) | ((char)word[i] > 90)) & (((char)word[i] < 97) | ((char)word[i] > 122))) {
									std::cout << "Word consists not only letters! Fix it in input file.\n";
									worcdcheck = false;
									break;
								}
							}
							else if ((((char)word[i] < 65) | ((char)word[i] > 90)) & (((char)word[i] < 97) | ((char)word[i] > 122)) & ((char)word[i] != 32)) {
								std::cout << "Word consists not only letters! Fix it in input file.\n";
								worcdcheck = false;
								break;
							}
					}
				if (worcdcheck == true)
					gameMode(word, hangman);
				else
					std::system("pause");
				game = false;
			}


			//PvP mode
			else if (variant == 2) {
				std::cout << "Preparation phase\n";
				bool step = false;
				while (step == false)
				{
					step = true;
					std::cout << "Enter your word (you can enter only letters) ~'0' - return back~ : ";
					std::getline(std::cin, word);
					std::cout << std::endl;
					if (word == "0") {
						back = true;
						break;
					}
					if (word.size() < 3) {
						std::cout << "Error! You entered little word! Try again.\n";
						step = false;
					}
					else if (checkChars(word) == false) {
						std::cout << "Error! You entered word consists of only two letters! Try again.\n";
						step = false;
					}
					else {
						for (unsigned int i = 0; i < word.size(); i++)
							if ((i == 0) | (i == word.size() - 1)) {
								if ((((char)word[i] < 65) | ((char)word[i] > 90)) & (((char)word[i] < 97) | ((char)word[i] > 122))) {
									std::cout << "You entered not only letters! Try again.\n";
									step = false;
									break;
								}
							}
							else if ((((char)word[i] < 65) | ((char)word[i] > 90)) & (((char)word[i] < 97) | ((char)word[i] > 122)) & ((char)word[i] != 32)) {
									std::cout << "You entered not only letters! Try again.\n";
									step = false;
									break;
								}
					}
				}
				if (back == false)
					gameMode(word, hangman);
				game = false;
			}


			//Exit
			else if (variant == 3) {
				std::system("cls");
				std::cout << "Goodbye, human!\n";
				std::putchar('\a');
				std::system("pause");
				return 0;
			}
		}
	}
}