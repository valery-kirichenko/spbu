
#include "stdafx.h"
#include <iostream>

using namespace std;

struct list
{
	int inf; 
	list *next;
	list *last;
};


int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите количество элементов списка ";
	cin >> n;
	list *first = new list; 
	list *p = first;
	list *w;
	p->last = 0;
	cout << "Введите 1 элемент списка ";
	cin >> p->inf;

	for (int i = 0; i<n - 1; i++)
	{
		p->next = new list; 
		w = p;
		p = p->next;
		p->last = w;
		cout << "Введите " << i+2 << " элемент списка ";
		cin >> p->inf;
	}	
	p->next = 0;
	
	p = first;
	while (p)
	{
		cout << p->inf << " ";
		p = p->next;
	};
	system("cls");
	
	int k;
	cout << "Введите номер элемента ";
	cin >> k;
	p = first;
	if (k < n)
	{
		for (int i = 0; i < k; i++)	p = p->next;
		w = p->last;
		cout << "Указатель на этот элемент равен " << w << endl;
		cout << "Этот элемент равен " << w->inf << endl;
	}
	else
	{	
		for (int i = 0; i < n-2; i++)	p = p->next;
		w = p->next;
		cout << "Указатель на этот элемент равен " << w << endl;
		cout << "Этот элемент равен " << w->inf << endl;
		
	};
	system("pause");
	system("cls");
	if (k != 1)
	{
		p = w->last;
		p->next = w->next;
		w->next = first;
		w->last = 0;
		first->last = w;
		first = w;
	};


	cout << "Переработанный список:" << endl;
	p = first;
	
	for (int i = 0; i < n - 1; i++)
	{
		cout << p->inf << " ";
		p = p->next;
	};
	cout << p->inf;

	cout << endl << "Указатель на первый элемент равен " << first->next->last << endl;
	cout << "Указатель на последний элемент равен " << p->last->next << endl;

	p = first;
	for (int i = 0; i < n - 1; i++)
	{
		w = p->next;
		delete p;
		p = w;
	};
	

	system("pause");
	return 0;
}
