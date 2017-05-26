// redblacktree.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include <iostream>
using namespace std;
enum color{red,black} Ncol;
template <typename T>
struct node {
	T inf;
	node * left;
	node * right;
	node * parent;
	color col;
};
template <typename T>
void search (T val,node<T> *tr){
	if (!tr){
		cout << "EMPTY tree " << endl;
		return;
	}
    if (val < tr->inf) search (val,tr->left);
	else if(val > tr->inf) search (val,tr->right);
	else cout << " Yes we found !! " << endl;
}
template <typename T>
int  add(T val,node<T> *&tr,node<T> *&nl){
	if ( !tr){
		 tr = new node<T>;
		 tr->inf = val;
		tr->left = nullptr;
		tr->right = nullptr;
        tr->parent = nl;
		tr->col = red;
		if (nl){
			if (val < nl->inf)
			nl->left = tr;
			else nl->right = tr;
		}
		insert1(tr);
		return 0;
	}
    else if (tr!=nullptr) if (val < tr->inf) add (val,tr->left,tr);
	else if (tr!=nullptr) if (val >= tr->inf) add (val,tr->right,tr);
};

template <typename T>
node<T> *grandparent (node<T> *tr){

	if ((tr != nullptr) && (tr->parent != nullptr))
		return tr->parent->parent;
	
	return nullptr;
};
template <typename T>
node<T> *uncle( node<T> *tr)
{
	node<T> *g = grandparent(tr);
	if (g == nullptr)
		return nullptr; 
	if (tr->parent == g->left)
		return g->right;
	
	else return g->left;
};
template <typename T>
void rotate_left(node<T> *P)
{
   node<T> *N = P->right;
  if(N!=nullptr) N->parent = P->parent; 
   if (P->parent != nullptr) {
        if (P->parent->left==P)
            P->parent->left = N;
        else
            P->parent->right = N;
    }		
	P->right = N->left;
    if (N->left != nullptr)
        N->left->parent = P;
    P->parent = N;
    N->left = P;
	
};

template <typename T>
void rotate_right( node<T> *P)
{
    node<T> *N = P->left;
	node <T> *tmp = P->parent;
  
    if (P->parent != nullptr) {
        if (tmp->left==P)
            tmp->left = N;
        else
            tmp->right = N;
    }
	node<T> *p = P;
	if(N != nullptr) N->parent = tmp; 
	P=p;
    P->left = N->right;
    if (N->right != nullptr)
        N->right->parent = P;
    P->parent = N;
    N->right = P;
	
}

template <typename T>
void insert1(node<T> *tr){
	if (tr->parent == nullptr)
		tr->col=black;
	else insert2(tr);
};
template <typename T>
void insert2(node<T> *&tr){
	if (tr->parent->col == black)
		return;
	else insert3(tr);
};
template <typename T>
void insert3(node<T> *tr){
	node<T> *u = uncle(tr);
	
	if ((u != nullptr) && (u->col == red) && (tr->parent->col == red)) {
		tr->parent->col = black;
		u->col = black;
		node<T> *g = grandparent(tr);
		g->col = red;
		insert1(g);
	} else {
		insert4(tr);
	}
}
template <typename T>
void insert4(node<T> *tr){
node<T> *g = grandparent(tr);

	if ((tr == tr->parent->right) && (tr->parent == g->left)) {
		rotate_left(tr->parent);
		tr = tr->left;
	} 
	else if ((tr == tr->parent->left) && (tr->parent == g->right)) {
		rotate_right(tr->parent);
		tr = tr->right;
	}
	insert5(tr);
};
template <typename T>
void insert5(node<T> *tr){
	 node<T> *g = grandparent(tr);
     tr->parent->col = black;
	if(g->parent!=nullptr){
		g->col = red;
		if ((tr == tr->parent->left) && (tr->parent == g->left)) 
			rotate_right(g);
	
		else rotate_left(g);
	}
	
};
template <typename T>
void print(node<T> *tr,int k,int l){
	if (tr) {
				if(tr->right) 
					print(tr->right,k+3,l+3);
				cout << endl;
				for (int i=0;i<k+3;i++)
					cout << " ";
				cout << tr->inf << "-" << tr->col;  
				for(int i=0;i<l+2;i++)
					cout << " ";
				if (tr->left) 
					print(tr->left,k+3,l+3);
                
               }
	else cout << " Empty tree! " << endl;
};
/*/ deleting node
template <typename T>
void del_node(node<T> *&mt, T val) {
	if ( mt == nullptr) {
		cout << "Your val was NOT found" << endl;
		system("pause");
		return;
	}

	if (val < mt->field) del_node(mt->left, val);
	else if (val > mt->field) del_node(mt->right, val);
	else {
		delete mt;
		mt = nullptr;
	}
}
*/
template <typename T>
node<T>* sibling(node<T> *n)
{
	if (n == n->parent->left)
		return n->parent->right;
	else
		return n->parent->left;
}

template <typename T>
void delete_case1(node<T> *n)
{
	if (n->parent != nullptr)
		delete_case2(n);
}

template <typename T>
void delete_case2(node<T> *n)
{
	node<T> *s = sibling(n);
	
	if (s->col == red) {
		n->parent->col = red;
		s->col = black;
		if (n == n->parent->left)
			rotate_left(n->parent);
		else
			rotate_right(n->parent);
	}
	delete_case3(n);
}

template <typename T>
void delete_case3(node<T> *n)
{
	node<T> *s = sibling(n);

	if ((n->parent->col == black) &&
		(s->col == black) &&
		(s->left->col == black) &&
		(s->right->col == black)) {
		s->col = red;
		delete_case1(n->parent);
	}
	else
		delete_case4(n);
}

template <typename T>
void delete_case4(node<T> *n)
{
	node<T> *s = sibling(n);
	if (!s || s == nullptr) return;
	
	if ((n->parent->col == red) &&
		(s->col == black) &&
		(s->left->col == black) &&
		(s->right->col == black)) {
		s->col = red;
		n->parent->col = black;
	}
	else delete_case5(n);
}

template <typename T>
void delete_case5(node<T> *n)
{
	node<T> *s = sibling(n);

	if (s->col == black) { 
		if ((n == n->parent->left) &&
			(s->right->col == black) &&
			(s->left->col == red)) { 
			s->col = red;
			s->left->col = black;
			rotate_right(s);
		}
		else if ((n == n->parent->right) &&
			(s->left->col == black) &&
			(s->right->col == red)) {
			s->col = red;
			s->right->col = black;
			rotate_left(s);
		}
	}
	delete_case6(n);
}

template <typename T>
void delete_case6(node<T> *n)
{
	node<T> *s = sibling(n);

	s->col = n->parent->col;
	n->parent->col = black;

	if (n == n->parent->left) {
		s->right->col = black;
		rotate_left(n->parent);
	}
	else {
		s->left->col = black;
		rotate_right(n->parent);
	}
}

// safe delete
template <typename T>
void del_safe(node<T> *&mt, T val) {
	if (!mt || mt == nullptr) {
		cout << "Your val was NOT found" << endl;
		system("pause");
		return;
	}

	if (val < mt->inf) del_safe(mt->left, val);
	else if (val > mt->inf) del_safe(mt->right, val);
	else {
		node<T> *left = mt->left;
		node<T> *right = mt->right;

		node<T> *child = (mt->right == nullptr) ? mt->left : mt->right;

		
		if (child){ 
			if (child->col == red)
				child->col = black;
			else
			delete_case1(mt);
		
		}
		if (left && right && left->right) {
			node<T> *parent = mt;

			while (left->right) {
				parent = left;
				left = left->right;
			}

			parent->right = left->left;
			left->left = nullptr;
			mt->inf = left->inf;

			delete left;
		}
		else if (left != nullptr) {
			if ( left->right == nullptr) left->right = mt->right;

			left->parent = mt->parent;
			if (left->right)left->right->parent = left;

			mt->left = nullptr;
			mt->right = nullptr;

			delete mt;
			mt = left;
		}
		else  if (right) {
			right->parent = mt->parent;

			mt->left = nullptr;
			mt->right = nullptr;

			delete mt;
			mt = right;
		}
		else if(!right && !left){
			if (mt->parent->left==mt)
				mt->parent->left=nullptr;
			else mt->parent->right=nullptr;
			delete mt;

		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Enter amount of elements " << endl;
	int N ;
	int vr;
	cin >> N;
	node<int> * root = new node<int>;
	node<int> * nul = new node<int>;
	cout << "Enter  elements " << endl;
	cin >> vr;
	root->inf = vr;
	root->col = black;
	root->parent = nullptr;
	root->right = nullptr;
	root->left = nullptr;
    for (int i=0;i<N-1;i++){
		cin >> vr;
		int var = add(vr,root,nul);
	}
	print(root,N-1,0);
	cout << endl << "Enter element u eant delete ";
	cin >> vr;
	del_safe(root,vr);
	N--;
	print(root,N-1,0);
	cout << " Enter element u want find " << endl;
	cin >> vr;
	search(vr,root);
	system("pause");
	return 0;
}
