// Normaltree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
template <typename T>
struct tree{
	T inf;
	tree<T> * left;
	tree<T> * right;
};
 
template <typename T>//напечатать дерево
 void print(tree<T> *&node,int k,int l){
	if (node) {
				if(node->right) 
					print(node->right,k+2,l+3);
				cout << endl;
				for (int i=0;i<k+2;i++)
					cout << " ";
				cout << node->inf;
				for(int i=0;i<l+2;i++)
					cout << " ";
				if (node->left) 
					print(node->left,k+2,l+3);
                
               }
	else cout << " Empty tree! " << endl;
};
template <typename T>
void search (T val,tree<T> *&node){
	if (!node){
		cout << "EMPTY tree " << endl;
		return;
	}

	if (val < node->inf) search (val,node->left);
	else if(val > node->inf) search (val,node->right);
	else cout << " Yes we found !! " << endl;
}
template <typename T>//добавить элемент в дерево
void add(T val,tree<T> *&node){
	if(!node){
		node = new tree<T>;
		node->inf = val;
		node->left = nullptr;
		node->right=nullptr;
	}	
	else if(node->inf > val) add (val,node->left);
	else add (val,node->right);
};
template <typename T>//удалить элеменент
void  remove(T val,tree<T> *&node){
	if(!node){
        cout << "ERROR NOT FOUND" << endl;
        system("pause");
        return;
    }

    if(val < node->inf) remove(val,node->left);
    else if(val > node->inf) remove(val,node->right);
    else{
        tree<T> *left = node->left;
        tree<T> *right = node->right;

        if(left && right && left->right){
            tree<T> *p = node;

            while(left->right){
                p = left;
                left = left->right;
            }

            p->right = left->left;
            left->left = nullptr;
            node->inf = left->inf;

            delete left;
        }else if(left){
            if(!left->right) left->right = node->right;

            node->left = nullptr;
            node->right = nullptr;

            delete node;
            node = left;
        }else{
            //right->right = mt->righ
				node->left = nullptr;
				node->right = nullptr;

            delete node;
            node = right;
        }
    }
}


int _tmain(int argc, _TCHAR* argv[])
{
	tree <int>* root = new tree <int>;
	root->left = nullptr;
	root->right = nullptr;
	cout << "Enter amount alements " << endl;
	int N;
	cin >> N;
	root->inf = rand () %100;
	for (int i=0;i<N;i++){
		int v = rand() %100;
		add(v,root);
	}
	print (root,N-1,0);
	cout << endl;
	cout << "Press 1 - search an element " << endl
	     << "Press 2 - add an element " << endl
	     << "Press 3 - delete an alement " << endl;
	int tmp; cin >> tmp;
	switch(tmp){
	case 1 :{
		cout << "enter element u want find " << endl;
		int vr;
		cin>>  vr;
		search (vr,root);
		print (root,N-1,0);
		cout << endl;
		break; 
			}
	case 2 : {
		cout << "enter element u want inset " << endl;
		int vr;
		cin >> vr;
		add (vr,root);
		print (root,N-1,0);
		break;
			 }
	case 3 : {
		cout << "enter element u want remove " << endl;
		int vr;
		cin >> vr;
		remove(vr,root);
		print (root,N-1,0);
		break;
			}
	}//close switch
	system("pause");
	return 0;
}

