// stack.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;
template <typename T>


class stack
{
public:
	struct stack_str
	{
	T x; stack_str * next;
	};
	stack_str *first = new stack_str;
	stack()
	{
		first->x=0; first->next = NULL;
	}
	stack(int n)
	{
		if (n!=0) cin >> first->x;
		else first->x = 0;
			first->next = NULL;
		for (int i = 0; i < n-1; i++)
		{
			stack_str *p = new stack_str;
			cin >> p->x;
			p->next = first;
			first = p; 	
		}
	}
	
	void check1()
	{
		int k1 = 0; int k2 = 0;
		for (stack_str *p = first; p != NULL; p = p->next)
		{
			if (k2<k1)
			if (p->x == '(') k1++;
			else if (p->x == ')') k2++;
			else { k1 += k2; break; }
		}
		if (k1 == k2) cout << "\nSkobki rastavlenu verno!\n";
		else cout << "\nSkobki rastavlenu neverno!\n";
	}
	void del()
	{
		
			stack_str *p = first;
			first = first->next; delete p;
		
	}
	void ent()
	{
		stack_str *p = new stack_str;
		p->next = first; cin >> p->x; first = p;
	}
	void ent1(char c)
	{
		stack_str *p = new stack_str;
		p->next = first; p->x=c; first = p;
	}
	bool check()
	{
		if (first == NULL) return true;
		else return false;
	}
	int prove(int n)
	{
		stack_str *r = new stack_str; r->next = NULL; int k = 0;
		for (stack_str *p = first; p != NULL; p = p->next)
		{
			if (p->x > 0)
			{
				if (k == 0) { r->x = p->x; k++; }
				else
				{
					stack_str *t = new stack_str;
					t->x = p->x; t->next = r; r = t; k++;

				}
			}
		}
		stack_str *p = first;
		for (int i=0;i<k-1; i++)
		{
			p->x = r->x; p=p->next;r = r->next;
		}
		p->x = r->x;p->next = NULL;
		return k;
		
	}
	void print(int n)
	{
		cout << "\n";
		for (stack_str *p = first; p != NULL; p = p->next)
		{
			cout << p->x << " ";
		}
		cout << "\n";
	}
};
class que
{
public:
	struct que_str
	{
		int x; que_str * next;
	};
	que_str *first = new que_str;
	que_str *last = new que_str;
	que()
	{
		first->x = 0; first->next = NULL;
	}
	que(int n)
	{
		if (n != 0) cin >> first->x;
		else first->x = 0;
		first->next = NULL; que_str *p = first;
		for (int i = 0; i < n - 1; i++)
		{
			first->next = new que_str;
			cin >> first->next->x;
			first = first->next;
		}
		last = first; first = p; last->next = NULL;
	}

	int del(int n)
	{
		que_str *p = first;
		first = first->next; delete p;
		return n - 1;
	}
	int ent(int n)
	{
		que_str *p = new que_str;
		last->next = p;
		cin >> p->x; last = p; last->next = NULL;
		return n + 1;
	}
	int ent1(int n,int x1)
	{
		que_str *p = new que_str;
		last->next = p;
		 p->x=x1; last = p; last->next = NULL;
		return n + 1;
	}
	void print(int n)
	{
		for (que_str *p = first; p != NULL; p = p->next)
		{
			cout << p->x << " ";
		}
	}
	void check()
	{
		if (first == NULL) cout << "Pustoi";
		else cout << "Ne pystoi";
	}
	void search(int n)
	{
		que_str *p = first;int z = 0;int x1;
		for (int i = 0; i < n; i++)
		{
			if (p->x < 0) { if (z == 0) { x1 = p->x;z++; }
			else if (x1 < p->x) x1 = p->x;
				}
			p = p->next;
		}
		if (z == 0) { cout << "\nZnachenie ne naideno\n"; }
		else cout << "Maximal'noe otricatel'noe - " << x1;
	}
};

class deck
{
public:
	struct deck_str
	{
		int x; deck_str * next, *prev;
	};
	deck_str *first = new deck_str;
	deck_str *last = new deck_str;
	deck()
	{
		first->x = 0; first->next = NULL;
	}
	deck(int n)
	{
		cin >> first->x; first->prev = NULL; deck_str *p=first,*e = first;
		for (int i = 0; i < n - 1; i++)
		{
			p->next = new deck_str;
			p = p->next;
			p->prev = e;
			e = p;
			cin >> p->x;
		}
		last = p; last->next = NULL;
	}

	int del(int n)
	{
		cout << "\nYdalit' :\n1 - iz nachala\n2 - iz konca\n"; int y; cin >> y;
		if (y == 1) 
		{
			deck_str *p = first;
			first = first->next;first->prev = NULL; delete p;
		}
		else
		{
			deck_str *p = last;
			last = last->prev;last->next = NULL; delete p;
		}
		return n - 1;
	}
	int ent(int n)
	{
		cout << "\nVstavit' :\n1 - V nachalo\n2 - V konec\n"; int y; cin >> y; cout << "\nVvedite znahenie\n";
		if (y == 2)
		{
			deck_str *p = new deck_str;
			last->next = p;
			cin >> p->x;p->prev = last; last = p; last->next = NULL;
		}
		else
		{
			deck_str *p = new deck_str; first->prev = p; p->next = first;
			cin >> p->x; first = p; first->prev = NULL;
		}
		return n + 1;
	}
	void print(int n)
	{
		for (deck_str *p = first; p != NULL; p = p->next)
		{
			cout << p->x << " ";
		}
	}
	void check()
	{
		if (first == NULL) cout << "Pustoi";
		else cout << "Ne pystoi";
	}
	void search(int n)
	{
		int x; cout << "\nVvedite element dlya poiask:\n"; cin >> x;
		deck_str *p = first;int z = 0;
		for (int i = 0; i < n; i++)
		{
			if (x == p->x) { cout << "\nZnachenie naideno\n ";z++;break; }
			p = p->next;
		}
		if (z == 0) { cout << "\nZnachenie ne naideno\n";}
	}
};

int main()
{
	int k = 0;
	cout << "Vvedite kol-vo elementov - ";
	int n; 
	cin >> n;
	while (k!=5)
	{
		system("cls");
		cout << "Viberite sposob hraneniya dannih: \n1 - Stack\n2 - Queue\n3 - Deck\nInache vihod\n";
		cin >> k;
		switch (k)
		{
		case 1: 
			{
			system("cls");
			cout << "Vvedite znacheniya -\n"; stack <int> a(n); int z = 0;
			while (z!=5)
			{
				system("cls");
				cout << "Viberite deistvie:\n1 - Dobavit' element\n2 - Ydalit' ellement\n3 - Proverit' na pystoty\n4 - Vivod\n5 - Nazad\n";
				cin >> z;
				switch (z)
				{
				case 1: {n--;cout << "\nVvedite znashenie\n"; a.ent(); cout << "\nStack posle : \n"; a.print(n); break;}
				case 2: {n++; a.del(); cout << "\nStack posle : \n"; a.print(n); break;}
				case 3: {if (a.check()) cout << "\nPustoi\n"; else cout << "\nNe pustoi\n";  break;}
				case 4: { cout << "\nStack : \n"; a.print(n); break;}
				case 5: break;
				default: break;
				}
				system("pause");
			}
			break;
			}
		case 2: 
		{
			system("cls");
			cout << "Vvedite znacheniya -\n"; que a(n); int z = 0;
			while (z != 5)
			{
				system("cls");
				cout << "Viberite deistvie:\n1 - Dobavit' element\n2 - Ydalit' ellement\n3 - Proverit' na pystoty\n4 - Vivod\n5 - Nazad\n";
				cin >> z;
				switch (z)
				{
				case 1: {n = a.ent(n); cout << "\nQueue posle : \n"; a.print(n); break;}
				case 2: {n = a.del(n); cout << "\nQueue posle : \n"; a.print(n); break;}
				case 3: {a.check();  break;}
				case 4: { cout << "\nQueue : \n"; a.print(n); break;}
				case 5: break;
				default: break;
				}
				system("pause");
			}
			break;
		}
		case 3:
		{
			system("cls");
			cout << "Vvedite znacheniya -\n"; deck a(n); int z = 0;
			while (z != 6)
			{
				system("cls");
				cout << "Viberite deistvie:\n1 - Dobavit' element\n2 - Ydalit' ellement\n3 - Proverit' na pystoty\n4 - Vivod\n5 - Poisk\n6 - Nazad\n";
				cin >> z;
				switch (z)
				{
				case 1: {n = a.ent(n); cout << "\nDeck posle : \n"; a.print(n); break;}
				case 2: {n = a.del(n); cout << "\nDeck posle : \n"; a.print(n); break;}
				case 3: {a.check();  break;}
				case 4: { cout << "\nDeck : \n"; a.print(n); break;}
				case 5: {a.search(n); break;}
				case 6: break;
				default: break;
				}
				system("pause");
			}
		}
		}
	}
	system("cls");
	while (k != 2)
	{
		system("cls");
		cout << "Zadacha №2\nVvedite stroky - ";
		n = 0;
		stack <char> a(n); char c;  
		int k1 = 0; int  y = 0;
		while (cin)
		{
			cin.get(c);
			if (k1 > 0) 
			{
				
				if (c == '\n') break;
				if (c == '(') { a.ent1(c); n++; }
							else  
								if (c == ')') 
								{
									if ((a.first->next == NULL) || (a.first->x == ')')) 
													{
														y++;
													}
									else {
										a.del();
										n--;
										}
								}
				
			}
			else k1++;
		}
		if ((y == 0)&& (a.first->next == NULL))
									cout << "\nSkobki verni\n"; 
						else 
									cout << "\nSkobki neverni\n";
		cout << "\nEshe raz?\n1 - Da\n2 - net\n"; 
		cin >> k;
	}
	
	system("cls");
	cout << "Zadacha #3"<<"\nVvedite posledovatel'nost' chisel, gde 0 eto konec - "; 
	int x = 1; k = 0; n = 0; que b(n);
	while (x!=0)
	{
		 cin >> x; 
		 if (x != 0)
		 {
			 n++;
			 n = b.ent1(n, x);
			 n--;
		 }
		 if (k == 0) { n = b.del(n) + 1; k++; }
	}
	b.search(n);system("pause");
	system("cls");
	cout << "Vvedite kol-vo elementov - "; cin >> n;
	cout << "\nVvedite elementi - "; 
	stack <int> c(n); cout << "\nDo obrabotki -";
	c.print(n);
	n=c.prove(n);cout << "\nPosle obrabotki -";
	c.print(n);

	system("pause");
    return 0;
}

