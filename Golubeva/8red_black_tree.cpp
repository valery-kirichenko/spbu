#include "stdafx.h";
#include<iostream>
#include<cstdlib>
#include <Windows.h>
using namespace std;

const bool red = true;
const bool black = false;
const int lvl = 2;

struct node
{
	int value;
	node *left;
	node *right;
	node *prev;
	bool colour;
};

static node *nil = new node;
node *root = new node;

void delete_node(node *z);
void delete_rotate(node *x);
void insert_rotate(node *z);
void print_tree(node *tree, int level)
{
	if (tree != nil)
	{
	print_tree(tree->left, level + lvl);
	for (int i=0; i < level; i++) cout<<" ";
	if (tree->colour == red) {HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(handle, FOREGROUND_RED); 
								cout<<tree->value <<endl;
							 SetConsoleTextAttribute(handle,  (WORD) ((0 << 4) | 7));}
		if (tree->colour == black) cout<<tree->value <<endl;
	print_tree(tree->right, level + lvl);
	}
}
bool find_del(node *tree, int element)
{
	if (tree != nil)
	{
		if (tree->value == element) {delete_node(tree); return true;}
		if (find_del(tree->left, element)) {delete_node(tree); return true;};
		if (find_del(tree->right, element)) {delete_node(tree); return true;}
	}
	return false;
}
bool search(node *tree, int element)
{
	if (tree != nil)
	{
		if (tree->value == element) {return true;}
		if (search(tree->left, element)) {return true;};
		if (search(tree->right, element)) {return true;}
	}
	return false;
}
void left_rotate(node *x)
{
	node *y = x->right;
	x->right = y->left;
	if (y->left != nil) {y->left->prev = x;}
	y->prev = x->prev;
	if (x->prev == nil) {root = y;}
	else if (x == x->prev->left) {x->prev->left = y;}
	else {x->prev->right = y;}
	y->left = x;
	
	x->prev = y;
}
void right_rotate(node *x)
{
	node *y = x->left;
	x->left = y->right;
	if (y->right != nil) {y->right->prev = x;}
	y->prev = x->prev;
	if (x->prev == nil) {root = y;}
	else if (x->prev->left == x) {x->prev->left = y;}
	else {x->prev->right = y;}
	y->right = x;

	x->prev = y;
}
void insert()
{
	int element;
	cout<<"Enter the number: ";
	cin>>element;
	node *x = root;
	node *y = nil;
	node *z = new node;
	if (root->colour == red) 
		{
		root->prev = nil;
		root->colour = black;
		root->left = nil;
		root->right = nil;
		root->value = element;
		return;
		}
	else
	{
	while(x != nil)
	{
		y = x;
		if (element == x->value) {return;}
		if (element < x->value) {x = x->left;}
		else {x = x->right;}
	}
	if (y->value > element) {y->left = z;}
	else {y->right = z;}
	}

	z->prev = y;
	z->colour = red;
	z->left = nil;
	z->right = nil;
	z->value = element;
	insert_rotate(z);
}
void insert_rotate(node *z)
{
	node *y;

	while (z->prev->colour == red)
	{
		if (z->prev == z->prev->prev->left)
		{
			y = z->prev->prev->right;
			if (y->colour == red)
			{
				y->colour = black;
				z->prev->colour = black;
				z->prev->prev->colour = red;
				z = z->prev->prev; 
			}
			else 
			{
				if (z == z->prev->right)
				{
					z = z->prev;
					left_rotate(z);
				}
				z->prev->colour = black;
				z->prev->prev->colour = red;
				right_rotate(z->prev->prev);
			}
		}
		else
		{
			y = z->prev->prev->left;
			if (y->colour == red)
			{
				y->colour = black;
				z->prev->colour = black;
				z->prev->prev->colour = red;
				z = z->prev->prev; 
			}
			else 
			{
				if (z == z->prev->left)
				{
					z = z->prev;
					right_rotate(z);
				}
				z->prev->colour = black;
				z->prev->prev->colour = red;
				left_rotate(z->prev->prev);
			}
		}
	}
	root->colour = black;
}
void transplant(node *u, node *v)
{
	if (u->prev == nil) 
	{
		root = v;
	}
	else if (u == u->prev->left) 
	{
		u->prev->left = v;
	}
	else {u->prev->right = v;}
	v->prev = u->prev;
}
void delete_node(node *z)
{
	node *y = z;
	node *x;
	bool colour = z->colour;
	
	if (z->left == nil)
	{
		x = z->right;
		transplant(z, z->right);
	}
	else if (z->right == nil)
	{
		x = z->left;	
		transplant(z, z->left);
	}
	else 
	{
		y = z->right;
		while(y->left != nil) {y = y->left;}
		colour = y->colour;
		x = y->right;
		if (y->prev == z)
		{
			x->prev = y;
		}
		else 
		{
			transplant(y, y->right);
			y->right = z->right;
			y->right->prev = y;
		}
		transplant(z, y);
		y->left = z->left;
		y->left->prev = y;
		y->colour = z->colour;
	}
	if (colour == black) {delete_rotate(x);}
}
void delete_rotate(node *x)
{
	node *w;

	while ((x != root)&&(x->colour == black))
	{
	if (x == x->prev->left)
		{
			w = x->prev->right; 
			if (w->colour == red)
			{
				w->colour = black;
				x->prev->colour = red;
				left_rotate(x->prev);
				w = x->prev->right;
			}
			if ((w->left->colour == black)&&(w->right->colour == black))
			{
				w->colour = red;
				x = x->prev;
			}
			else
			{
				if (w->right->colour == black)
				{
				w->left->colour = black;
				w->colour = red;
				right_rotate(w);
				w = x->prev->right;
				}
			w->colour = x->prev->colour;
			x->prev->colour = black;
			w->right->colour = black;
			left_rotate(x->prev);
			x = root;
			}
		}
	else
		{
			w = x->prev->left;
			if (w->colour == red)
			{
				w->colour = black;
				x->prev->colour = red;
				right_rotate(x->prev);
				w = x->prev->left;
			}
			if ((w->left->colour == black)&&(w->right->colour == black))
			{
				w->colour = red;
				x = x->prev;
			}
			else 
			{
				if (w->left->colour == black)
				{
					w->right->colour = black;
					w->colour = red;
					left_rotate(w);
					w = x->prev->left;
				}
			w->colour = x->prev->colour;
			x->prev->colour = black;
			w->left->colour = black;
			right_rotate(x->prev);
			x = root;
			}
		}
	}
	x->colour = black;
}
int main()
{
	nil->colour = black;
	nil->left = nil;
	nil->right = nil;
	root->prev = nil;
	root->colour = red;
	root->left = nil;
	root->right = nil;

	int x=0;
	int element;
	while(x != 5)
	{
		cout<<"1. Add element to the tree.\n";
		cout<<"2. Show the tree.\n";
		cout<<"3. Search the element.\n";
		cout<<"4. Delete the element.\n";
		cout<<"5. Exit.\n";
		cin>>x;
		switch (x)
		{
		case 1: 
			{ 
				system("cls"); 
				insert(); 
				system("cls"); 
				break;
			}
		case 2: 
			{ 
				system("cls");
			if ((root->colour == red)&&(root->left == nil)&&(root->right == nil)) 
			{
				cout<<"The tree is empty. Try it later.\n"; 
				break;
			}
			else 
				print_tree(root, 0);
			system("pause"); system("cls");
			break;
			}
		case 3:
			{ 
				system("cls");
				cout<<"Enter the element: ";
				cin>>element;
				if(search(root, element)) cout<<"The element was found.\n"; 
				else cout<<"The element wasn't found.\n";
				break;
			}
		case 4 :
			{ 
				system("cls");
				print_tree(root,0);
				cout<<"Enter the element: ";
				cin>>element;
				if(!search(root, element)) 
					cout<<"The element wasn't found.\n";
				else 
					find_del(root, element);
				print_tree(root,0);
				cout <<endl;
				system("pause");
				system("cls");
				break;
			}
		case 5 : break;
		default : cout<<"Unknown command. Try again\n";
		}
	}
	return 0;
}