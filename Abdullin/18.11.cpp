// 18.11.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <string>

using namespace std;



class VEG
{
public:
	string name,color; int srok;
	void ent()
	{
		system("cls");
		cout << "\nVvedite nazvanie ovosh'a - "; cin >> name;
		cout << "\nVvedite cvet ovosh'a - ";  cin >> color;
		cout << "\nVvedite srok cozrevaniya ovosh'a - "; cin >> srok;
	}
	void p()
	{
		cout << "\nNazvanie ovosh'a - "<< name;
		cout << "\nCvet ovosh'a - "<< color;
		cout << "\nSrok cozrevaniya ovosh'a - "<< srok;
	}
};
template <class T>
class LIST
{
public:
	T x; unsigned int size;
	LIST *next; LIST *first;
	LIST()
	{
		size = 0; next = NULL;
	}
	LIST(unsigned int size)
	{
		
		cout << "Vvedite znacheniya spiska - \n"; 
		LIST *p = new LIST;
		p->x.ent();
		first = p;
		for (unsigned int i = 0; i < size - 1; i++)
		{
			p->next = new LIST;
			p = p->next;
			p->x.ent();
		}
		p->next = NULL;
	}
	int enter(int x1, int n)
	{
		if (x1 != 1)
		{
			LIST *p = first;
			for (int i = 0; i < x1 - 2; i++)
				p = p->next;
			LIST *r = new LIST;
			cout << "Vvedite znachenie ";
			r->x.ent();
			r->next = p->next;
			p->next = r;

		}
		else
		{
			LIST *p = new LIST;
			p->next = first;
			cout << "Vvedite znachenie ";
			p->x.ent();
			first = p;
		}
		return n + 1;
	}
	int del(int x1, int n)
	{
		if (x1 != 1)
		{
			LIST *p = first;
			for (int i = 0;i < x1 - 2;i++)
				p = p->next;
			LIST *w = new LIST;
			w = p->next;
			p->next = w->next;
			delete w;
		}
		else {
			LIST *p = first;
			first = p->next;
		}


		return n - 1;
	}
	void print(int n)
	{
		LIST *p = first;
		for (int i = 0; i < n; i++)
		{
			p->x.p();
			cout << "\n";
			p = p->next;
		}

	}

};
int main()
{
	cout << "Vvedite kol-vo elementov - ";
	unsigned int n;
	cin >> n;
	LIST <VEG> list(n); int k = 10;
	while (k) 
	{
		system("cls"); cout << "\nViberite deistvie -\n1 - dobavit'\n2 - ydalit'\n3 - vivod\n4 - vihod\n";
		cin >> k;
		switch (k)
		{
		case 1: {int x; cout << "Viberite nomer elementa "; cin >> x; n=list.enter(x, n);break;}
		case 2: {int x; cout << "Viberite nomer elementa "; list.print(n); cin >> x;  n=list.del(x, n);break;}
		case 4: return 0;
		case 3: {list.print(n); break;}
		default: break;
		}
		cout << "\n"; system("pause");
	}
    return 0;
}

