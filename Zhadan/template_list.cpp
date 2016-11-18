#include "stdafx.h"
#include <iostream>

using namespace std;

template < typename T>
class list
{
public:
	int size;
	T inf;
	list<T> *next;
	
	list()
	{
		size=0;
	}
	
	list<T>* in(int n)
	{
		list<T> *first = new list<T>;
		list<T> *p = first;

		cout << "Введите 1 элемент листа ";
		cin >> p->inf;

		for (int i = 0; i<n - 1; i++)
		{
			p->next = new list<T>;
			p = p->next;
			cout << "Введите " << i + 2 << " элемент листа ";
			cin >> p->inf;
		}
		p->next = 0;

		return first;
	};

	void out(list<T> *a)
	{
		while (a)
		{
			cout << a->inf << " ";
			a = a->next;
		};
		cout << endl;
	};

	list<T>* add(list<T> *a)
	{
		list<T> *w=new list<T>;
		cout << "Введите новый элемент листа ";
		cin >> w->inf;
		w->next=a;
		size++;
		return w;
	};
	list<T>* del(list<T> *a)
	{
		list *w=a->next;
		delete a;
		size--;
		return w;
	};

};




int main()
{
	setlocale(LC_ALL, "Russian");
	char v = '0';
	list<float>  A;	
	list<float> *first = new list<float>;
	cout << "Введите количество элементов листа ";
	cin >> A.size;
	first=A.in(A.size);
	


	while (v != '4')
	{
		system("cls");
		cout << "1) Вывести список " << endl;
		cout << "2) Добавить элемент в начало " << endl;
		cout << "3) Удалить первый элемент " << endl;
		cout << "4) Выход" << endl;
		
		cin >> v;
		switch (v)
		{
		case '1':
			system("cls");
			A.out(first);
			system("pause");
			break;
		case '2':
			system("cls");
			first=A.add(first);	
			A.out(first);
			system("pause");
			break;
		case '3':
			system("cls");		
			first=A.del(first);
			A.out(first);
			system("pause");
			break;
		
		}

	}

	return 0;
}
