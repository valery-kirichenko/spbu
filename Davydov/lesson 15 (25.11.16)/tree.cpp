#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;


template<typename T>
struct node
{
T element;
node *left, *right;
};
static node <int> *first;

template<typename T>
void show(node <T> *&tree)
{
	if (tree != NULL)
	{
		show(tree->left);
		cout<<tree->element<<" ";
		show(tree->right);
	}
}
template<typename T>
void show_tree(node <T> *&tree, int value)
{
	if (tree != NULL)
	{
		show_tree(tree->left, value+4);
		for (int i=0; i<value; i++) cout<<" ";
		cout<<tree->element<<endl;
		show_tree(tree->right, value+4);
	}
}
template <typename T>
void add(node<T> *&tree, T x)
{
	if (tree == NULL)
	{
	tree = new node <T>;
	tree->element = x;
	tree->left = tree->right = NULL;
	}
	if (x < tree->element)
	{
		add(tree->left, x);
	}
	if (x > tree->element)
	{
		add(tree->right, x);
	}
}
template <typename T>
void del(node <T> *&tree)
{
	if (tree != NULL)
	{
		del(tree->left);
		del(tree->right);
		delete tree;
		tree = NULL;
	}
}
template <typename T>
void del(node <T> *&tree, T value)
{
	if (tree != NULL)
	{
		if (tree->element == value) {return del(tree);}
		if (search(tree->left, value)) {return del(tree->left, value);};
		if (search(tree->right, value)) {return del(tree->right, value);}
	}
}

template <typename T>
bool search(node <T> *&tree, T value)
{
	if (tree != NULL)
	{
		if (tree->element == value) {return true;}
		if (search(tree->left, value)) {return true;};
		if (search(tree->right, value)) {return true;}
	}
	return false;
}
template <typename T>
int counter (node <T> *&tree)
{
	int count = 0;
	if (tree != NULL)
	{
		count = count + counter(tree->left);
		count = count + counter(tree->right);
	}
	count++;
	return count;
}
template <typename T>
int counter_leaves (node <T> *&tree)
{
	int count = 0;
	if ((tree->left != NULL)&&(tree->right != NULL))
	{
		count = count + counter_leaves(tree->left);
		count = count + counter_leaves(tree->right);
	}
	else if (tree->left != NULL)
	{
		count = count + counter_leaves(tree->left);
	}
	else if (tree->right != NULL)
	{
		count = count + counter_leaves(tree->right);
	}
	else count++;
	return count;
}
template <typename T>
int degree(node <T> *&tree, T value)
{
	if (tree != NULL)
	{
		if (tree->element == value) {return counter_leaves(tree);}
		if (search(tree->left, value)) {return degree(tree->left, value);};
		if (search(tree->right, value)) {return degree(tree->right, value);}
	}
	return NULL;
}
template <typename T>
int level(node <T> *&tree, T value)
{
	int count = 0;
	bool flug = false;
	if (tree != NULL)
	{
		if (tree->element == value) {return count;}
		if (search(tree->left, value)) {flug = true; return level(tree->left, value)+1;}
		if (search(tree->right, value)) {flug = true; return level(tree->right, value)+1;}
	}
	if (!flug) return -1;
}
template <typename T>
int level(node <T> *&tree)
{
	int count = 0;
	if (tree != NULL)
	{
		if (count += level(tree->left)) {return level(tree->left)+1;}
		if (count += level(tree->right)) {return level(tree->right)+1;}
	}
 return count;
}
template <typename T>
int height(node <T> *&tree)
{
	int left=0;
	int right= 0;

	if (tree != NULL)
	{
	left = height(tree->left)+1;
	right = height(tree->right)+1;
	if (left >= right) return left;
	else return right;
	}
	return 0;
}
template <typename T>
int length(node<T> *&tree)
{
	int count = 0;
	if (tree != NULL)
	{
		count++;
		count += length(tree->left);
		count += length(tree->right);
		return count;
	}
	return 0;
}
template <typename T>
void myfunc(node <T> *&tree)
{
	int count = length(tree);
	T *arr = new T [count];
	
	cout<<count<<endl;
}

template <typename T>
void rebuild(node <T> *&tree, T value)
{
	node <T> *ptr;
	node <T> *p = tree;
	if (tree != NULL)
	{
		if (tree->element == value) 
			{
				if((tree->left==NULL)&&(tree->right==NULL)) 
				{
					del(tree, value); 
					return;
				}
				else if((tree->left!=NULL)&&(tree->right==NULL))
				{
					delete (tree->right);
					tree = tree->left;
				}
				else if((tree->left==NULL)&&(tree->right!=NULL))
				{
					delete (tree->left);
					tree = tree->right;
				}
				else if((tree->left!=NULL)&&(tree->right!=NULL))
				{
					ptr=tree->left;
					p=tree->left;
					if (ptr->right!=NULL) 
					{
						{ptr=ptr->right;}
						while (ptr->right!=NULL)
						{
							ptr=ptr->right;
							p=p->right;
						}
					tree->element = ptr->element;
					ptr = ptr->left;
					p->right = ptr;
					}
					else 
					{
						tree->element = ptr->element;
						p=tree;
						p->left = p->left->left;
					}
				}
			}
		if (search(tree->left, value)) {rebuild(tree->left, value);}
		if (search(tree->right, value)) {rebuild(tree->right, value);}
	}
}


/*
template <typename T>
int count_child(node <T> *&tree)
{
	int count=0;

	if (tree != NULL)
	{
		count += count_child(tree->left);
		if ((tree->left!=NULL)&&(tree->right!=NULL))
		{
			if (	(counter_leaves(tree->left) == counter_leaves(tree->right))||(level(first, tree->left->element) == level(first, tree->right->element))	) count++;
		}
		else count++;
		count += count_child(tree->right);
	}
	return count;
}
*/
template <typename T>
int count_child(node <T> *&tree)
{
	int count=0;

	if (tree != NULL)
	{
		count += count_child(tree->left);
		if ((tree->left!=NULL)&&(tree->right!=NULL))
		{
			if (	(counter_leaves(tree->left) == counter_leaves(tree->right))||(height(tree->left) == height(tree->right))	) count++;
		}
		if ((tree->left==NULL)&&(tree->right==NULL)) count++;
		count += count_child(tree->right);
	}
	return count;
}
/*
template <typename T>
int count_height(node <T> *&tree)
{
	int count=0;

	if (tree != NULL)
	{
		count += count_height(tree->left);
		if (tree->left == tree->right) count++;
		else if (level(first, tree->left->element) == level(first, tree->right->element)) count++;
		count += count_height(tree->right);
	}
	return count;
}
*/
int main()
{
	int value;
	node <int> *tree = NULL;
	int x = 1;
	int n;
	first = tree;

	cout<<"Welcome to the programm 'Tree' " <<endl;
	while (x)
	{
		cout<<"---------------------------------------------------------------------\n";
		cout<<"Choose the operation from list below.\n";
		cout<<"Enter 0 - to leave the programm.\n";
		cout<<"Enter 1 - to add elements to the tree.\n";
		cout<<"Enter 2 - to show elements of the tree.\n";
		cout<<"Enter 3 - to search the element.\n";
		cout<<"Enter 4 - to count nodes.\n";
		cout<<"Enter 5 - to count leaves.\n";
		cout<<"Enter 6 - to count degree of node.\n";
		cout<<"Enter 7 - to count level of node.\n";
		cout<<"Enter 8 - to count height of the tree.\n";
		cout<<"Enter 9 - to search the element.\n";
		cout<<"Enter 10 - to delete the node with subtrees.\n";
		cout<<"Enter 11 - to delete the tree.\n";
		cout<<"Enter 12 - to delete the node with rebuilding of the tree.\n";
		cout<<"---------------------------------------------------------------------\n";
		cout<<"Enter 13 - to count the number of verteces of the tree, that\n";
		cout<<"has equal heights or numbers of subtrees.\n";
		cout<<"---------------------------------------------------------------------\n";
		cout<<"Enter 14 - to show the tree.\n";
		cout<<"Your choice: ";
		cin>>x;
		system("cls");
		switch (x)
		{
		case 0 : break;
		case 1 : cout<<"Enter the number of elements: ";
			cin>>n;
			for (int i=1; i<=n; i++)
			{
			cout<<i<<" element = ";
			cin>>value;
			add(tree, value);
			}
			break;
		case 2 : show(tree); cout<<endl; break;
		case 3 : cout<<"Enter the element: ";
			cin>>value;
			if(search(tree, value)) cout<<"This element is founded.\n"; 
			else cout<<"The element is not founded.\n";
			break;
		case 4 : cout<<"The number of nodes: "<<counter(tree)-counter_leaves(tree)<<endl; break;
		case 5 : cout<<"The number of leaves: "<<counter_leaves(tree)<<endl; break;
		case 6 : cout<<"Enter the element: ";
			cin>>value;
			value = degree(tree, value);
			if(value) {cout<<"The degree of this node is: "<<value<<endl;} 
			else cout<<"The element is not founded.\n";
			break;
		case 7 : cout<<"Enter the element: ";
			cin>>value;
			value = level(tree, value);
			if (value != -1)
			{cout<<"The level of this node is: "<<value<<endl;} 
			else cout<<"The element is not founded.\n";
			break;
		case 8 : cout<<"The height: "<<height(tree)<<endl; break;
		case 9 : cout<<"Enter the element: ";
			cin>>value;
			if(search(tree, value)) cout<<"This element is founded.\n"; 
			else cout<<"The element is not founded.\n";
			break;
		case 10 : cout<<"Enter the element: ";
			cin>>value;
			del(tree, value); break;
		case 11 : del(tree); break;
		case 12 : 
			cout<<"Enter the element: ";
			cin>>value;
			rebuild(tree, value);
			break;
		case 13 :
			cout<<"The number of verteces of the tree, that has\n";
			cout<<"equal heights or numbers of subtrees: "<<count_child(tree)<<endl;
			break;
		case 14 : 
			show_tree(tree, 0);
			break;
		default : cout<<"Wrong number.\n";
		}
	}
	
	system("pause");
	return 0;
}
