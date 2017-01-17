// tree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class tree
{
public:
	struct tree_str
	{
		tree_str *left=nullptr;	
		tree_str *prev = nullptr;
		tree_str *right=nullptr;
		int x=0;
	};
	
	tree_str *first = new tree_str;
	tree_str *cur = new tree_str;

	void ent(int y)
	{
		if (first == 0)
		{
			first = new tree_str;
			first->x = y;
			first->prev = nullptr;
			first->left = nullptr;
			first->right = nullptr;
		}
		else
		{
			tree_str *p = new tree_str;
			if (cur->x >= y)
				if (cur->left == NULL)
				{
					p->x = y;
					cur->left = p; p->prev = cur;
				}
				else
				{
					cur = cur->left; ent(y);
				}
			else
				if (cur->x <= y)
					if (cur->right == NULL)
					{
						p->x = y;
						cur->right = p;p->prev = cur;
					}
					else
					{
						cur = cur->right; ent(y);
					}
		}
	}
	tree(int n)
	{
		cout << "\nVvedite derevo - \n";
		if (n != 0) cin >> first->x;
		else first->x = 0;
		int y; first->prev = nullptr;
		for (int i = 0; i < n - 1; i++)
		{
			cur = first;
			cin >> y;
			ent(y);
		}
		cur = first;
	}
	tree()
	{
		first->left = NULL; first->right = NULL;first->x = 0;
	}
	void print(tree_str *cur, int n)
	{
		int i;
		if (cur != nullptr)
		{
			print(cur->right, n + 2);
			for (i = 0; i < n; i++)
				cout << " ";
			cout << cur->x << "\n";
			print(cur->left, n + 2);
		}
	}
	void delfull(int y)
	{
		tree_str *b = nullptr;
		b = searchfordel(first, y, b);
		if (first != b)
			if (b->prev->right == b)
				b->prev->right = nullptr;
			else
				b->prev->left = nullptr;
		else
			first = 0;
	}
	
	int searchnotbin(tree_str *cur, int k, int y)
	{
		if (cur != nullptr)
			{
				y = searchnotbin(cur->right, k, y); 
				if (cur->x == k) return 1;
				y = searchnotbin(cur->left, k, y);
			}
		return y;
	}
	int check(tree_str *cur, int k)
	{
		if (cur != nullptr)
		{
			k = check(cur->right, k);
			k++;
			k = check(cur->left, k);
		}
		return k;
	}
	int check2(tree_str *cur, int k)
	{
		if (cur != nullptr)
		{
			k = check2(cur->right, k);
			if ((cur->left==nullptr)&&(cur->right==nullptr)) k++;
			k = check2(cur->left, k);
		}
		return k;
	}
	int search2(tree_str *cur, int y, int k)
	{
		if (cur != nullptr)
		{
			if (cur->x > y) k = search2(cur->left, y, k);
			else if (cur->x < y) k = search2(cur->right, y, k);
			else if (cur->left!=nullptr) if (cur->right!=nullptr) k=2;
			else k = 1;
			else k = 0;
		}
		return k;
	}
	int search(tree_str *cur, int y, int k)
	{
		if (cur != nullptr)
		{
			if (cur->x > y) k = search(cur->left, y, k);
			else if (cur->x < y) k = search(cur->right, y, k);
			else k++;
		}
		return k;
	}
	int degree(tree_str *cur, int y, int k)
	{
		if (cur != nullptr)
		{
			if (cur->x > y) {
				k++; k = degree(cur->left, y, k);
			}
			else if (cur->x < y) {
				k++; k = degree(cur->right, y, k);
			}
		}
		return k;
	}
	tree_str *searchfordel(tree_str *cur, int y,tree_str *b)
	{
		
		if (cur != nullptr)
		{
			if (cur->x > y) { b = searchfordel(cur->left, y, b);}
			else if (cur->x < y) { b = searchfordel(cur->right, y, b); }
			else b = cur;
		}
		return b;
	}
	int height(tree_str *cur,int max)
	{
		int k = 0;
		if (cur!= nullptr)
		{
			k = degree(first, cur->x, k);
		}
		if (k > max) max = k;
		if (cur->left != nullptr)
		{
			max=height(cur->left, max);
		}
		
		if (cur->right != nullptr)
		{
			max=height(cur->right, max);
		}
		return max;
	}
	void del(int y)
	{
		int k = 0;
		tree_str *b = nullptr;
		tree_str *q = nullptr;
		b = searchfordel(first, y, b);
		tree_str *last = b->right;
		if (b->right == nullptr&&b->left == nullptr) //esli posle nego nikogo net!
		{
			if (b->prev == nullptr) //esli do nego nikogo net
			{
				first = 0;
			}
			else //esli do nego est'
			{
				if (b->prev->right == b) //proverka sprava ili ne sprava
				{
					b->prev->right = nullptr;
					b->prev = nullptr;
					delete b;
				}
				else
				{
					b->prev->left = nullptr;
					b->prev = nullptr;
					delete b;
				}
			}
		} //rabotaet!
		else
		{
			if (b->right == nullptr&&b->left != nullptr) //esli est' tol'ko levii
			{
				if (b->prev == nullptr) //esli do nego nikogo net
				{
					b->left->prev = nullptr;
					first = b->left;
					delete b;
				} //rabotaet
				else //else do nego kto-to est'
				{
					if (b->prev->right == b) //proverka sprava ili ne sprava
					{
						b->prev->right = b->left;
						b->left->prev = b->prev;
						delete b;
					}
					else
					{
						b->prev->left = b->left;
						b->left->prev = b->prev;
						delete b;
					}
				}
			} //rabotaet
			else
			{
				if (b->right != nullptr && b->left == nullptr) //esli est' tol'ko pravii
				{
					if (b->prev == nullptr) //esli do nego nikogo net
					{
						first = b->right;
						first->prev = nullptr;
						delete b;
					}
					else //else do nego kto-to est'
					{
						if (b->prev->right == b) //proverka sprava ili ne sprava
						{
							b->prev->right = b->right;
							b->right->prev = b->prev;
							delete b;
						}
						else
						{
							b->prev->left = b->right;
							b->right->prev = b->prev;
							delete b;
						}
					}
				}//rabotaet
				else
				{
					while (true)
					{
						if ((last->left == nullptr)) break; //searsh for minimal left value
						last = last->left;
					}
					if (last->right == nullptr)
					{
						if (last->prev->right == last) //proverka sprava ili ne sprava
						{
							last->prev->right = nullptr;
							last->prev = nullptr;
						}
						else
						{
							last->prev->left = nullptr;
							last->prev = nullptr;
						}
					}
					b->x = last->x;
					if (last->right != nullptr)
					{
						b->right = last->right;
						last->right->prev = b;
					}
					delete last;
				}//rabotaet
			}
		}
	}
	int kolvo(tree_str *cur, int k)
	{
		if (cur != nullptr)
		{
			k=kolvo(cur->right, k);
			k++;
			k=kolvo(cur->left, k);
		}
		return k;
	}
	void isit(tree_str *cur)
	{
		if (cur != nullptr)
		{
			isit(cur->right); 
			if ((kolvo(cur->right, 0) - kolvo(cur->left, 0)) == 2 || (kolvo(cur->right, 0) - kolvo(cur->left, 0)) == -2) { del(cur->x); cur = first; }
			isit(cur->left);
		}
	}
};


int main()
{
	cout << "Vvedite kol-vo elementov - "; int n; cin >> n;int k = 0;
	tree a(n);
	while (k != 12)
	{
		system("cls"); a.print(a.first,0); cout << "Viberite deistvie - \n1 - Vstavit' element\n2 - Poisk elementa\n3 - Kol-vo yzlov\n4 - Kol-vo list'ev\n5 - Yznat' stepen' vershini\n6 - Yroven' vershini\n7 - Ydalit' yzel s perestroikoi\n"; 
		cout << "8 - Visota dereva\n9 - Poisk ne binarnii\n10 - Ydalit' uzel s potomkami\n11 - Proverka i ydalenie\n12 - Vihod\n";
		cin >> k;system("cls");
		switch (k)
		{
		case 1:
		{
			cout << "Vvedite znachenie - "; int y; cin >> y; a.ent(y); cout << "\n"; a.print(a.first, 0); break;
		}
		case 2:
		{
			cout << "Vvedite znachenie dlya poiska - "; int y,k=0; cin >> y; if (a.search(a.first, y,k) > 0) cout << "Znahenie naideno!"; else cout << "Znahenie ne naideno!"; break;
		}
		case 3:
		{
			int k1 = 0; cout << "\nVot stol'ko - " << a.check(a.first, k1); break;
		}
		case 4:
		{
			int k2 = 0; cout << "\nVot stol'ko - " << a.check2(a.first, k2 ); break;
		}
		case 5:
		{
			a.print(a.first, 0); cout << "Vvedite znachenie - "; int y, k = 0; cin >> y; cout << "Vot takaya stepen' - " << a.search2(a.first, y, k); break;
		}
		case 6:
		{
			a.print(a.first, 0); cout << "Vvedite znahchenie - "; int y, k = 0; cin >> y; cout << "Vot takoi yroven' vershini - " << a.degree(a.first, y, k); break;
		}
		case 7:
		{
			a.print(a.first, 0); cout << "Vvedite znahchenie - "; int y, k = 0; cin >> y; a.del(y); cout << endl;  a.print(a.first, 0); break;
		}
		case 8:
		{
			cout << "Vot takay visota - " << a.height(a.first, 0); break;
		}
		case 9:
		{
			cout << "Vvedite znachenie dlya poiska - "; int y; cin >> y; if (a.searchnotbin(a.first, y, 0) > 0) cout << "Znahenie naideno!"; else cout << "Znahenie ne naideno!"; break;
		}
		case 10:
		{
			a.print(a.first, 0); cout << "Vvedite znachenie dlya ydaleniya - "; int y; cin >> y; a.delfull(y); a.print(a.first, 0);  break;
		}
		case 11:
		{
			a.print(a.first, 0); cout << "Idet proverka "; a.isit(a.first);cout << "\nNovoe derevo\n "; a.print(a.first, 0);  break;
		}
		}
		cout << "\n";
		system("pause");
	}
    return 0;
}

