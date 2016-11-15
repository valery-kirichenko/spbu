#include "stdafx.h"
#include <iostream>

using namespace std;

struct list
{
	int inf;
	list *next;
	list *last;
};

list* in(list* first,int n)
{
	
	list *p = first;

	cout << "Введите 1 элемент списка ";
	cin >> p->inf;

	for (int i = 0; i<n - 1; i++)
	{
		p->next = new list;
		p->next->last = p;
		p = p->next;
		cout << "Введите " << i + 2 << " элемент списка ";
		cin >> p->inf;
	}
	p->next = 0;

	return p;
}


void  out(list *a)
{
	while (a)
	{
		cout << a->inf << " ";
		a = a->next;
	};
	cout << endl;
}

void sum(list* first,list* p)
{
	int sum = 0;
	while (first)
	{
		sum = sum + first->inf*p->inf;
		first = first->next;
		p = p->last;
	}
	cout << "3) Х1*Хn + Х2*Хn-1 + ... + Хn*Х1 = " << sum << endl;

}

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	char v = '0';
	cout << "Введите количество элементов списка ";
	cin >> n;
	list *first = new list;
	first->last = 0;
	list *p = in(first,n);
	system("cls"); 

	while (v != '4')
	{
		cout << "1) Ввести новый список " << endl;
		cout << "2) Вывести список " << endl;
		cout << "3) Вычислить:  Х1*Хn + Х2*Хn-1 + ... + Хn*Х1" << endl;
		cout << "4) Выход " << endl;
		cin >> v;
		switch (v)
		{
		case '1':
			system("cls");
			cout << "Введите количество элементов списка ";
			cin >> n;
			p = in(first, n);
			system("cls");
			break;
		case '2':
			system("cls");
			out(first);
			break;
		case '3':
			system("cls");
			sum(first, p);
			break;
		}

	}


	return 0;
}
