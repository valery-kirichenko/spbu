#include<iostream>
#include<cstdlib>
using namespace std;
const bool red = true;
const bool black = false;
const int otstup = 6;

struct node
{
int value;
node *left;
node *right;
node *prev;
bool colour;
};
static node *nil = new node;
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
int counter (node *tree)
{
	int count = 0;
	if (tree != nil)
	{
		count = count + counter(tree->left);
		count = count + counter(tree->right);
	}
	count++;
	return count;
}
int counter_leaves (node *tree)
{
	int count = 0;
	if ((tree->left != nil)&&(tree->right != nil))
	{
		count = count + counter_leaves(tree->left);
		count = count + counter_leaves(tree->right);
	}
	else if (tree->left != nil)
	{
		count = count + counter_leaves(tree->left);
	}
	else if (tree->right != nil)
	{
		count = count + counter_leaves(tree->right);
	}
	else count++;
	return count;
}
int degree(node *tree, int element)
{
	if (tree != nil)
	{
		if (tree->value == element) {return counter_leaves(tree);}
		if (search(tree->left, element)) {return degree(tree->left, element);};
		if (search(tree->right, element)) {return degree(tree->right, element);}
	}
	return 0;
}
int level(node *tree, int element)
{
	int count = 0;
	bool flug = false;
	if (tree != nil)
	{
		if (tree->value == element) {return count;}
		if (search(tree->left, element)) {flug = true; return level(tree->left, element)+1;}
		if (search(tree->right, element)) {flug = true; return level(tree->right, element)+1;}
	}
	if (!flug) return -1;
}
int level(node *tree)
{
	int count = 0;
	if (tree != nil)
	{
		if (count += level(tree->left)) {return level(tree->left)+1;}
		if (count += level(tree->right)) {return level(tree->right)+1;}
	}
 return count;
}

int height(node *tree)
{
	int left=0;
	int right= 0;

	if (tree != nil)
	{
	left = height(tree->left)+1;
	right = height(tree->right)+1;
	if (left >= right) return left;
	else return right;
	}
	return 0;
}

void show_tree(node *tree, int number)
{
	if (tree != nil)
	{
	show_tree(tree->right, number + otstup);
	for (int i=0; i < number; i++) {cout<<" ";}
	cout<<tree->value;
		if (tree->colour == red)cout<<" (red)"<<endl;
		if (tree->colour == black)cout<<" (black)"<<endl;
	show_tree(tree->left, number + otstup);
	}
}
void left_rotate(node *tree, node *x)
{
	node *y = x->right;

	node *ptr = new node;
		ptr->colour = x->colour; 
		ptr->value = x->value;
		ptr->left = x->left;
	if (x == tree) 
		{
			tree->colour = y->colour;
			tree->value = y->value;
			tree->left = ptr;
			tree->right = y->right;

			ptr->prev = tree;
			ptr->right = y->left;
			if (y->left != nil) {y->left->prev = ptr;}
			if (y->right != nil) {y->right->prev = tree;}
			return;
		}

	x->right = y->left;
	if (y->left != nil) {y->left->prev = x;}
	y->prev = x->prev;
	if (x == x->prev->left) {x->prev->left = y;}
	else {x->prev->right = y;}
	
	y->left = x;
	x->prev = y;
}
void right_rotate(node *tree, node *x)
{
	node *y = x->left;

	node *ptr = new node;
	if (x == tree)
	{
		ptr->value = x->value;
		ptr->right = x->right;
		ptr->colour = x->colour;

		tree->colour = y->colour;
		tree->value = y->value;
		tree->left = y->left;
		tree->right = ptr;

		ptr->prev = tree;
		ptr->left = y->right;
		if (y->right != nil) {y->right->prev = ptr;}
		if (y->left != nil) {y->left->prev = tree;}
		return;
	}

	x->left = y->right;
	if (y->right != nil) {y->right->prev = x;}
	y->prev = x->prev;
	if (x->prev->left == x) {x->prev->left = y;}
	else {x->prev->right = y;}

	y->right = x;
	x->prev = y;
}
void insert_fix(node *tree, node *z)
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
					left_rotate(tree, z);
				}
				z->prev->colour = black;
				z->prev->prev->colour = red;
				right_rotate(tree, z->prev->prev);
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
					right_rotate(tree, z);
				}
				z->prev->colour = black;
				z->prev->prev->colour = red;
				left_rotate(tree, z->prev->prev);
			}
		}
	}
	
}
void insert(node *tree)
{
	int element;
	cout<<"Enter your element: ";
	cin>>element;

	node *x = tree;
	node *y = nil;
	node *z = new node;

	if (tree->colour == red) {tree->value = element; tree->colour = black; return;}
	while(x != nil)
	{
		y = x;
		if (element == x->value) {return;}
		if (element < x->value) {x = x->left;}
		else {x = x->right;}
	}
	//if (y == nil) {tree->value = element; tree->colour = black; return;}
	if (y->value > element) {y->left = z;}
	else {y->right = z;}

	z->prev = y;
	z->colour = red;
	z->left = nil;
	z->right = nil;
	z->value = element;
	insert_fix(tree, z);
}
node *minimum(node *ptr)
{
	while (ptr != nil)
	{
		ptr = ptr->left;
	}
	return ptr;
}
node *maximum(node *ptr)
{
	while (ptr != nil)
	{
		ptr = ptr->right;
	}
	return ptr;
}
int main()
{
	node *tree = new node;
	nil->colour = black;
	tree->prev = nil;
	tree->colour = red;
	tree->left = nil;
	tree->right = nil;
	//nil->left = tree;
	//nil->right = tree;

	char x = 'q';
	int element;

	cout<<"Welcome to the programm 'Red-Black Tree'\n";
	while(x != '0')
	{
		cout<<"Enter 0 - to leave the programm.\n";
		cout<<"Enter 1 - to add element to the tree.\n";
		cout<<"Enter 2 - to show the tree.\n";
		cout<<"Enter 3 - to search the element.\n";
		cout<<"Enter 4 - to count nodes.\n";
		cout<<"Enter 5 - to count leaves.\n";
		cout<<"Enter 6 - to count degree of node.\n";
		cout<<"Enter 7 - to count level of node.\n";
		cout<<"Enter 8 - to count height of the tree.\n";
		cout<<"Your choice: ";
		cin>>x;
		//system("cls");
		switch (x)
		{
		case '0' : break;
		case '1' : 
			insert(tree);
			break;
		case '2' : 
			if ((tree->colour == red)&&(tree->left == nil)&&(tree->right == nil)) {break;}
			//else (tree->colour != red)
			else show_tree(tree, 0);
			break;
		case '3' : cout<<"Enter the element: ";
			cin>>element;
			if(search(tree, element)) cout<<"This element is founded.\n"; 
			else cout<<"The element is not founded.\n";
			break;
		case '4' : cout<<"The number of nodes: "<<counter(tree)-counter_leaves(tree)<<endl; break;
		case '5' : cout<<"The number of leaves: "<<counter_leaves(tree)<<endl; break;
		case '6' : cout<<"Enter the element: ";
			cin>>element;
			element = degree(tree, element);
			if (element) {cout<<"The degree of this node is: "<<element<<endl;} 
			else cout<<"The element is not founded.\n";
			break;
		case '7' : cout<<"Enter the element: ";
			cin>>element;
			element = level(tree, element);
			if (element != -1)
			{cout<<"The level of this node is: "<<element<<endl;} 
			else cout<<"The element is not founded.\n";
			break;
		case '8' : cout<<"The height: "<<height(tree)<<endl; break;
		default : cout<<"Wrong number.\n";
		}
	}
	system("pause");
	return 0;
}
