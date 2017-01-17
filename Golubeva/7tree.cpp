#include "stdafx.h"
#include<iostream>
using namespace std;

struct tree{
	int x;
	tree * left;
	tree * right;
};
 
 void print_Tree(tree* p,int level)
{
    if(p)
    {
        print_Tree(p->left,level + 1);
        for(int i = 0;i< level;i++) cout<<"   ";
        cout << p->x << endl;
        print_Tree(p->right,level + 1);
    }
};

void search (int val,tree *&node){ 
	if (!node){
		cout << "Sorry, the element wasn't found." << endl;
		return;
	}

	if (val < node->x) search (val,node->left);
	else if(val > node->x) search (val,node->right);
	else cout << "The element was found." << endl;
}

void add_node(int x,tree *&MyTree) 
{
	if (NULL==MyTree)
	{
		MyTree=new tree;  
		MyTree->x=x; 
		MyTree->left=MyTree->right=NULL;
		return;
	}
	 if (x<=MyTree->x) 
     {
        if (MyTree->left!=NULL) 
			add_node(x,MyTree->left); 
        else 
        {
            MyTree->left=new tree; 
            MyTree->left->left=MyTree->left->right=NULL; 
            MyTree->left->x=x; 
            }
     }
	  if (x>MyTree->x) 
     {
        if (MyTree->right!=NULL) 
			add_node(x,MyTree->right); 
        else 
        {
			MyTree->right=new tree; 
			MyTree->right->left=MyTree->right->right=NULL; 
			MyTree->right->x=x; 
            }
     }
}

void  remove(int val,tree *&node){ 
	if(!node){
        cout << "Sorry, the element is not in the tree." << endl;
        system("pause");
        return;
    } 

    if(val < node->x) remove(val,node->left);
    else if(val > node->x) remove(val,node->right);
    else{
        tree *left = node->left;
        tree *right = node->right;

        if(left && right && left->right){
            tree *p = node;

            while(left->right){
                p = left;
                left = left->right;
            }

            p->right = left->left;
            left->left = nullptr;
            node->x = left->x;

            delete left;
        }
		else 
			if(left){
				if(!left->right) left->right = node->right;

            node->left = nullptr;
            node->right = nullptr;

            delete node;
            node = left;
        }
		else
		{
				node->left = nullptr;
				node->right = nullptr;

            delete node;
            node = right;
        }
    }
}

int main()
{
	tree * root = NULL;

	int N=0;int vr;
	while (N!=5)
	{
	cout << "1. Enter element" << endl
	     << "2. Search the element" << endl
	     << "3. Delete the element " << endl
		 << "4. Print the tree" << endl
		 << "5. Close the program" << endl;
	cin >> N;
	switch(N){
	case 1: 
		{
			system("cls");
			cout << "Enter the number: ";
			cin >> vr;
			add_node (vr,root); 
			system("cls");
			break;
		}
	case 2:
		{
			system("cls");
			print_Tree(root,0);
			cout << "What are we looking for?  ";
			cin>>  vr;
			search (vr,root);
			cout << endl;
			break;
		}
	case 3: 
		{
			system("cls");
			print_Tree(root,0);
			cout << "What are we deleting? " << endl;
			cin >> vr;
			remove(vr,root);
			cout << endl;
			print_Tree(root,0);
			system("pause");
			system("cls");
			break;
		}
	case 4:
		{
			system("cls");
			print_Tree(root,0);
			cout <<endl;
		}
	}
	}
	return 0;
}
