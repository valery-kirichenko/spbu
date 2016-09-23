// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <dos.h>
#include <string>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	int a;
	int b;
	float res;
	int otherres;
	int choice;
	string yesno;
while (yesno != "Да-с" || yesno != "Нет"){
	L1:
	cout << "Какую операцию выполняем-с, милейший?" << endl
		 <<	"1. Будем-с складывать!" << endl
		 <<	"2. Повычитаем-с!" << endl
		 <<	"3. Имею желание умножать!" << endl
		 <<	"4. Числа делить желаю!" << endl
		 <<	"5. Остаток от числа надобно мне найти, сударь!" << endl;
	cin >> choice;
	switch(choice){
	case 1:
		cout << "Вводите два числа, мессир!" << endl;
		cin >> a >> b;
		res = (float)a + (float)b;
		cout << "Складываем-с! " << a << " + " << b << ", значится, равняется " << res;
		cout << ", милейший! Всегда рады вам помочь!\n Это всё на сегодня? (Да-с/Нет)\n";
		cin >> yesno;
		if (yesno == "Да-с") break;
		if (yesno == "Нет-с") cin >> choice;
	case 2:
		cout << "Вводите два числа, мессир!" << endl;
		cin >> a >> b;
		res = (float)a - (float)b;
		cout << "Вычитаем-с! " << a << " - " << b << ", значится, равняется " << res;
		cout << ", господин! Всегда рады вам помочь!\n Это всё на сегодня? (Да-с/Нет)\n";
		cin >> yesno;
		if (yesno == "Да-с") break;
		if (yesno == "Нет-с") cin >> choice;
	case 3:
		cout << "Вводите два числа, мессир!" << endl;
		cin >> a >> b;
		res = (float)a * (float)b;
		cout << "Умножаем-с! " << a << " * " << b << ", значится, равняется " << res;
		cout << ", уважаемый! Всегда рады вам помочь!\n Это всё на сегодня? (Да-с/Нет)\n";
		cin >> yesno;
		if (yesno == "Да-с") break;
		if (yesno == "Нет-с") cin >> choice;
	case 4:
		cout << "Вводите два числа, мессир!" << endl;
		cin >> a >> b;
		res = (float)a / (float)b;
		cout << "Делим-с! " << a << " : " << b << ", значится, равняется " << res;
		cout << ", сударь! Всегда рады вам помочь!\n Это всё на сегодня? (Да-с/Нет)\n";
		cin >> yesno;
		if (yesno == "Да-с") break;
		if (yesno == "Нет-с") cin >> choice;
	case 5:
		cout << "Вводите два числа, мессир!" << endl;
		cin >> a >> b;
		otherres = a % b;
		cout << "Находим-с остаток! " << a << " % " << b << ", значится, равняется " << otherres;
		cout << ", господин! Всегда рады вам помочь!\n Это всё на сегодня? (Да-с/Нет)\n";
		cin >> yesno;
		if (yesno == "Да-с") break;
		if (yesno == "Нет-с") cin >> choice;
		}
	};
	system("pause");
	return 0;
}

