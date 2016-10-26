// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include <vector>
#include "string"
#include <fstream>

using namespace std;
void outr(int k,string ar[9])
{
	switch (k)
	{
	case 0:
		ar[3][10] = ' ';
		ar[4][10] = ' ';
		ar[4][11] = ' ';
		ar[4][9] = ' ';
		ar[5][10] = ' ';
		ar[6][9] = ' ';
		ar[6][11] = ' ';
		break;
	case 1:
		ar[3][10] = '0';
		break;
	case 2:
		ar[4][10] = '|';
		break;
	case 3:
		ar[4][11] = '/';
		break;
	case 4:
		ar[4][9] = '\\';
		break;
	case 5:
		ar[5][10] = '|';
		break;
	case 6:
		ar[6][9] = '/';
		break;
	case 7:
		ar[6][11] = '\\';
		break;
	}
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 12; j++)
		{
					
			cout << ar[i][j];
		}
		cout << endl;
	}

} 
// вывод рисунка
int outw(int k, string &word, string &otv,string &l)
{
	
	int n = 0;
	char c;
	
	cout << "Press letter\n";
	cin >> c;
	l = l+ " " + c;
	system("cls");
	for (int i = 0; i < word.size(); i++)
		if (c == word[i]) 
		{
			otv[i] = c; 
			n = n + 1;
		}
	
	if (n == 0) k = k + 1;
	for (int i = 0; i < word.size(); i++) cout << otv[i];
	cout << endl;
	cout << "Known letters " << l << endl;
	
	return k;
} 
//отгадывание слова и вывод вводимых букв


int main()
{
	
	string r[9];          //рисунок
	r[0] = " __________  ";
	r[1] = " |        |  ";
	r[2] = " |        |  ";
	r[3] = " |           ";
	r[4] = " |           ";
	r[5] = " |           ";
	r[6] = " |           ";	
	r[7] = " |           ";
	r[8] = "_|__________";
	

	int k = 0; // k - кол-во ошибок
	int f = 0; // f- кол-во слов в словаре
	int p = 0; 
	char v='0'; 
	string word,otv,l; 	
	string slov[100];

	ifstream in("input.txt");
	while (!in.eof())
	{
		getline(in, slov[f]);		
		f++;
	}
	in.close();

	

	while (v != '3')
	{
		cout << "Choose kind of game \n";
		cout << "1) PVP \n";
		cout << "2) PVE \n";
		cout << "3) EXIT \n";
		cin >> v;

		switch (v)
		{
		case '1':	
			cout << "Player 1 enter your word \n";
			cin >> word;
			system("cls");
			outr(0, r);
			otv = word;
			for (int i = 0; i < word.size(); i++)
			{
				otv[i] = '_';
				cout << otv[i];
			}
			cout << endl;
			while ((k != 7) & (word!=otv))
			{		
				k = outw(k, word,otv,l);
				outr(k, r);
			}
			if (k == 7) cout << "YOU LOSE \nTHIS WORD WAS: " << word << endl;
			else cout << "YOU WIN \n";
			l = "";
			k = 0;
			word = "";
			break;
		case '2':
			p = 1 + rand() % (f - 1);		
			word = slov[p];
			otv = word;
			for (int i = 0; i < word.size(); i++)
			{
				otv[i] = '_';
				cout << otv[i];
			}
			cout << endl;
			
			outr(0, r);
			while ((k != 7) & (word != otv))
			{
				k = outw(k, word, otv, l);
				outr(k, r);			
			}
			if (k == 7) cout << "YOU LOSE \nTHIS WORD WAS: " << word << endl;
			else cout << "YOU WIN \n";
			l = "";
			k = 0;
			word = "";
			break;
		}
	}

	return 0;
}

