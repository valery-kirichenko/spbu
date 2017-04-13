#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;
const int sz = 8;
const int moves = 7;
string pict[][sz] = {
	{
		"--------",
		" |    | ",
		" |      ",
		" |      ",
		" |      ",
		" |      ",
		" |      ",
		" -      "
	},
	{
		"--------",
		" |    | ",
		" |  /--\\",
		" |  ~~~~",
		" |      ",
		" |      ",
		" |      ",
		" -      "
	},
	{
		"--------",
		" |    | ",
		" |  /--\\",
		" |  ~~~~",
		" |    | ",
		" |      ",
		" |      ",
		" -      "
	},
	{
		"--------",
		" |    | ",
		" |  /--\\",
		" |  ~~~~",
		" |   -| ",
		" |      ",
		" |      ",
		" -      "
	},
	{
		"--------",
		" |    | ",
		" |  /--\\",
		" |  ~~~~",
		" |   -|-",
		" |      ",
		" |      ",
		" -      "
	},
	{
		"--------",
		" |    | ",
		" |  /--\\",
		" |  ~~~~",
		" |   -|-",
		" |   / ",
		" |      ",
		" -      "
	},
	{
		"--------",
		" |    | ",
		" |  /xx\\",
		" |  ~~~~",
		" |   -|-",
		" |   / \\",
		" |      ",
		" -      "
	}
};

const int keynum = 7;
string keys[keynum] = {
	"cheese", 
	"apple", 
	"orange",
	"colloqium",
	"programming",
	"focus",
	"hangman"
};

void outGame(int move, string s) {
	system("cls");
	for (int i = 0; i < sz; i++)
		cout << pict[move][i] << endl;
	cout << to_string(s.length()) << " letters:\n";
	cout << s << endl;
}

int main() {
	srand(time(NULL));
	while (true) {
		cout << "New Game\n1 - Computer vs Player, 2 - Player1 vs Player2: ";
		int a; 
		while ((cin >> a), a != 1 && a != 2)
			cout << "Incorrect Input\n";
		cout << "Enter the name of the person who is to solve: ";
		string name; cin >> name;
		string key;
		if (a == 1)
			key = keys[rand() % keynum];
		else {
			cout << "Please, close your opponent's eyes and enter your word: ";
			cin >> key;
		}
		string now = ""; for (int i = 0; i < key.length(); i++) now += '-';
		int move = 0;
		int opened = 0;

		while (move + 1 < moves && opened < key.length()) {
			outGame(move, now);
			char c; cin >> c;
			bool win = false;
			bool already = false;
			for (int i = 0; i < key.length(); i++)
				if (now[i] == c)
					already = true;
				else if (key[i] == c) {
					win = true;
					now[i] = c;
					opened++;
				}
			if (already) {
				cout << "You have already opened this letter\n";
				continue;
			}
			else if (!win)
				move++;
		}
		outGame(move, now);
		cout << name + (move + 1 == moves ? " lose" : " win") + '\n';

		string vvv; cin >> vvv;
		system("cls");
	}
}