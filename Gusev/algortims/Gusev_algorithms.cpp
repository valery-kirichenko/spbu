#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <climits>
#include <string>
//#include <Windows.h>
#include <fstream>
#include <vector>
//#include<bits/stdc++.h>
#include<algorithm>
#include<conio.h>
#include<random>
#include<time.h>

using namespace std;

mt19937 rnd(time(NULL));

//HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

template<typename T>
int linear_search(T* left,T* right,T val){
	int ans = 0;
	while (left != right){
		ans += (val == *left);
		left++;
	}
	return ans;
}
//-------------------------------------------------------
//search number of elments equal to val
//-------------------------------------------------------

int* binary_search(int* A, int size, int val){
	int mid, left = 0, right = size - 1;
	while (left != right){
		mid = left + (right - left + 1) / 2;
		if (*(A + mid) < val)
			left = mid;
		else
			right = mid - 1;
	}
	return A + mid;
}
//-------------------------------------------------------
//search pointer to first elment equal to val in sorted array
//-------------------------------------------------------

template<typename T>
void bubble_sort(T *A, int size){
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (A[i]>A[j])
				swap(A[i], A[j]);
}
//-------------------------------------
//just slow sort
//-------------------------------------

template<typename T>
void choose_sort(T *A, int size){
	int t;
	for (int i = 0; i < size; i++){
		t = i;
		for (int j = i + 1; j < size; j++)
			if (A[t]>A[j])
				t = j;
		swap(A[i], A[t]);
	}
}
//-------------------------------------
//just slow sort
//-------------------------------------

template<typename T>
void insert_sort(T *A, int size){
	for (int i = 0; i < size; i++){
		for (int j = i - 1; j >= 0; j--){
			if (A[j + 1] < A[j])
				swap(A[j], A[j + 1]);
			else
				break;
		}
	}
}
//-------------------------------------
//just slow sort
//-------------------------------------

template<typename T>
void qsort(T *A, int size){
	T m = *(A + (rnd() % (size+1)));
	int i=0, j=size;
	while (i <= j){
		while (i<size && A[i] < m)
			i++;
		while (j>0 && A[j] > m)
			j--;
		if (i <= j)
			swap(A[i++], A[j--]);
	}
	if (j>0)
		qsort(A, j);
	if (i < size)
		qsort(A + i, size - i);
}
//-------------------------------------
//black box of quick_sort
//-------------------------------------

template<typename T>
void quick_sort(T *A, int size){
	random_shuffle(A, A + size);
	qsort(A, size-1);
}
//-------------------------------------
//just random sort
//-------------------------------------

class tree{
	struct vertex{
		int val;
		vertex* p;
		vector<vertex*> nxt;
		vertex(int _val = -1,vertex *_p=NULL){
			val = _val;
			p = _p;
		}
		vertex* insert(int pos, vertex *t){
			if (val == pos){
				nxt.push_back(t);
				return this;
			}
			vertex* k;
			for (int i = 0; i < nxt.size(); i++){
				k = nxt[i]->insert(pos, t);
				if (k!=NULL)
					return k;
			}
			return NULL;
		}
		bool erase(int _val){
			for (int i = 0; i < nxt.size(); i++){
				if (nxt[i]->val == _val){
					for (int j = 0; j < nxt[i]->nxt.size(); j++){
						nxt.push_back(nxt[i]->nxt[j]);
						nxt[i]->nxt[j]->p = this;
					}
					for (int j = i + 1; j < nxt.size(); j++)
						swap(nxt[j - 1], nxt[j]);
					delete nxt.back();
					nxt.pop_back();
					return true;
				}
			}
			for (int i = 0; i < nxt.size(); i++)
				if (nxt[i]->erase(_val))
					return true;
			return false;
		}
		void show(){
			cout << val;
			if (nxt.size() != 0){
				cout << "(";
				for (int i = 0; i < nxt.size(); i++){
					nxt[i]->show();
					cout << ",";
				}
				cout << ")";
			}
		}
	};
public:
	vertex *root;
	tree(){
		root = NULL;
	}
	void insert(int pos, int val){
		vertex *t = new vertex(val);
		if (root == NULL)
			root = t;
		else
			t->p = root->insert(pos, t);
	}
	void erase(int _val){
		if (root == NULL)
			return;
		if (root->val != _val)
			root->erase(_val);
		else{
			if (root->nxt.size() == 0){
				delete root;
				root = NULL;
			}
			else{
				for (int i = 1; i < root->nxt.size(); i++){
					root->nxt[0]->nxt.push_back(root->nxt[i]);
					root->nxt[i]->p = root->nxt[0];
				}
				root->nxt[0]->p = NULL;
				vertex *t = root->nxt[0];
				delete root;
				root = t;
			}
		}
	}
	void show(){
		if (root == NULL)
			cout << "empty\n";
		else{
			cout << "tree:\n";
			root->show();
		}
	}
};

class bst{
	struct bst_block{
		int val;
		bst_block *L, *R;
		void insert_subtree_right(bst_block *r){
			if (R == NULL)
				R = r;
			else
				R->insert_subtree_right(r);
		}
		void insert_subtree_left(bst_block *l){
			if (L == NULL)
				L = l;
			else
				L->insert_subtree_left(l);
		}
		bst_block(int _val = -1){
			val = _val;
			L = R = NULL;
		}
		void show(){
			cout << "(";
			if (L != NULL)
				L->show();
			cout << val;
			if (R != NULL)
				R->show();
			cout << ")";
		}
		void insert(int _val){
			if (val > _val){
				if (L == NULL)
					L = new bst_block(_val);
				else
					L->insert(_val);
			}
			else{
				if (R == NULL)
					R = new bst_block(_val);
				else
					R->insert(_val);
			}
		}
		void erase(int _val){
			if (L != NULL){
				while (L != NULL && L->val == _val){
					bst_block *t;
					if (L->L == NULL || L->R == NULL)
						t = (L->R==NULL)?L->L:L->R;
					else{
						L->L->insert_subtree_right(L->L->R);
						t = L;
					}
					delete L;
					L = t;
				}
				if (L != NULL)
					L->erase(_val);
			}
			if (R != NULL){
				while (R != NULL && R->val == _val){
					bst_block *t;
					if (R->L == NULL || R->R == NULL)
						t = (R->R == NULL) ? R->L : R->R;
					else{
						R->L->insert_subtree_right(R->L->R);
						t = R;
					}
					delete R;
					R = t;
				}
				if (R != NULL)
					R->erase(_val);
			}
		}
	};
	bst_block *root;
public:
	bst(){
		root = NULL;
	}
	void show(){
		if (root == NULL)
			cout << "empty\n";
		else{
			cout << "BST is:\n";
			root->show();
		}
	}
	void insert(int _val){
		if (root == NULL)
			root = new bst_block(_val);
		else
			root->insert(_val);
	}
	void erase(int _val){
		while (root != NULL && root->val == _val){
			bst_block *t;
			if (root->L == NULL || root->R == NULL)
				t = (root->R == NULL) ? root->L : root->R;
			else{
				root->L->insert_subtree_right(root->L->R);
				t = root;
			}
			delete root;
			root = t;
		}
		if (root != NULL)
			root->erase(_val);
	}
};

class rbt{
	struct block{
		bool col;
		int val;
		block *L, *R,*P;
		block(int _val = -1){
			L = NULL;
			R = NULL;
			P = NULL;
			col = 1;
			val = _val;
		}
		void show(int len){
			int tmp = val,k=0;
			while (tmp > 0){
				tmp /= 10;
				k++;
			}
			if (R != NULL)
				R->show(len + k + 1);
			for (int i = 0; i < len; i++)
				putchar(' ');
			//if (col == 0)
			//	SetConsoleTextAttribute(hconsole, (WORD)(15));
			//else
			//	SetConsoleTextAttribute(hconsole, (WORD)(12));
			cout << '(' << col << ')' << val << '\n';
			if (L != NULL)
				L->show(len + k + 1);
		}

		void rotate_left(){
			if (R == NULL)
				return;
			block *tmp=R->L;
			R->P = P;
			if (P != NULL){
				if (P->L == this)
					P->L = R;
				else
					P->R = R;
			}
			P = R;
			R->L = this;
			R = tmp;
			if (tmp!= NULL)
				tmp->P = this;
		}

		void rotate_right(){
			if (L == NULL)
				return;
			block *tmp = L->R;
			L->P = P;
			if (P != NULL){
				if (P->L == this)
					P->L = L;
				else
					P->R = L;
			}
			P = L;
			L->R = this;
			L = tmp;
			if (tmp!=NULL)
				tmp->P = this;
		}

		bool brocol(){
			if (this == P->L){
				if (P->R == NULL)
					return 0;
				else
					return P->R->col;
			}
			else{
				if (P->L == NULL)
					return 0;
				else
					return P->L->col;
			}
		}

		void insert_case2(){
			if (P->brocol() == 1){
				P->P->L->col = 0;
				P->P->R->col = 0;
				P->P->col = 1;
				P->P->insert_case1();
			}
			else{
				if (P->P->L == P){
					if (this == P->R){
						P->rotate_left();
						P->rotate_right();
						R->col = 1;
						col = 0;
					}
					else{
						P->P->rotate_right();
						P->col = 0;
						P->R->col = 1;
					}
				}
				else{
					if (this == P->L){
						P->rotate_right();
						P->rotate_left();
						L->col = 1;
						col = 0;
					}
					else{
						P->P->rotate_left();
						P->col = 0;
						P->L->col = 1;
					}
				}
			}
		}

		void insert_case1(){
			if (P == NULL){
				col = 0;
				return;
			}
			if (P->col == 1){
				insert_case2();
			}
		}

		void insert(int _val){
			if (val > _val){
				if (L == NULL){
					L = new block(_val);
					L->P = this;
					L->insert_case1();
				}
				else
					L->insert(_val);
			}
			else{
				if (R == NULL){
					R = new block(_val);
					R->P = this;
					R->insert_case1();
				}
				else
					R->insert(_val);
			}
		}

		block* erase(int _val){
			if (val == _val){
				if (L != NULL){
					block *tmp = L;
					while (tmp->R != NULL)
						tmp = tmp->R;
					swap(val, tmp->val);
					return tmp;
				}
				if (R != NULL){
					block *tmp = R;
					while (tmp->L != NULL)
						tmp = tmp->L;
					swap(val, tmp->val);
					return tmp;
				}
				return this;
			}
			if (val > _val){
				if (L != NULL)
					return L->erase(_val);
			}
			else{
				if (R != NULL)
					return R->erase(_val);
			}
			return NULL;
		}
	};

	block* deleting(block *v){
		block *tmp;
		if (v->L == NULL && v->R == NULL){
			if (v == v->P->L)
				v->P->L = NULL;
			else
				v->P->R = NULL;
			delete v;
			return NULL;
		}
		if (v->L == NULL){
			if (v == v->P->L){
				v->P->L = v->R;
				v->R->P = v->P;
				delete v;
			}
			else{
				v->P->R = v->R;
				v->R->P = v->P;
				delete v;
			}
			tmp = v->R;
		}
		else{
			if (v == v->P->L){
				v->P->L = v->L;
				v->L->P = v->P;
				delete v;
			}
			else{
				v->P->R = v->L;
				v->L->P = v->P;
				delete v;
			}
			tmp = v->L;
		}
		return tmp;
	}

	void erase_case3(block *v){
		block*tmp = (v == v->P->L) ? v->P->R : v->P->L;
		if (v->P->col == 1 && tmp->col == 0 && (tmp->L == NULL || tmp->L->col == 0) && (tmp->R == NULL || tmp->R->col == 0)){
			tmp->col = 1;
			v->P = 0;
			return;
		}
		if (tmp == tmp->P->R){
			if (tmp->R == NULL || tmp->R->col == 0){
				tmp->col = 1;
				tmp->L->col= 0;
				tmp->rotate_right();
				tmp = tmp->P;
			}
			tmp->R->col = 0;
			swap(tmp->col, tmp->P->col);
			tmp->P->rotate_left();
		}
		else{
			if (tmp->L == NULL || tmp->L->col == 0){
				tmp->col = 1;
				tmp->R->col = 0;
				tmp->rotate_left();
				tmp = tmp->P;
			}
			tmp->L->col = 0;
			swap(tmp->col, tmp->P->col);
			tmp->P->rotate_right();
		}
	}

	void erase_case2(block *v){
		if (v->P == NULL)
			return;
		block*tmp = (v == v->P->L) ? v->P->R : v->P->L;
		if (tmp != NULL && tmp->col == 1){
			v->P->col = 1;
			tmp->col = 0;
			if (v == v->P->L)
				v->P->rotate_left();
			else
				v->P->rotate_right();
			erase_case3(v);
		}
		if (v->P->col == 0 && tmp->col == 0 && (tmp->L == NULL || tmp->L->col == 0) && (tmp->R == NULL || tmp->R->col == 0)){
			tmp->col = 1;
			return;
		}
		erase_case3(v);
	}

	void erase_case1(block *v){
		if (v == NULL)
			return;
		if (v->col == 1){
			deleting(v);
			return;
		}
		if (v->L == NULL && v->R == NULL){
			erase_case2(v);
			deleting(v);
			return;
		}
		v = deleting(v);
		if (v->col != 1){
			v->col = 0;
			return;
		}
		erase_case2(v);
	}

	block *root = NULL;
public:
	void insert(int val){
		if (root == NULL){
			root = new block(val);
			root->col = 0;
		}
		else{
			root->insert(val);
			while (root->P != NULL)
				root = root->P;
		}
	}
	void show(){
		if (root == NULL)
			cout << "empty\n";
		else
			root->show(0);
		//SetConsoleTextAttribute(hconsole, (WORD)(15));
	}
	void erase(int val){
		if (root != NULL){
			if (root->val == val && root->L == NULL && root->R == NULL){
				delete root;
				root = NULL;
			}
			else{
				erase_case1(root->erase(val));
				while (root->P != NULL)
					root = root->P;
			}
		}
	}
};

void array_work(){
	int *A=NULL, n=0;
	while (0 == 0){
		system("cls");
		if (n != 0){
			cout << "array is:\n";
			for (int i = 0; i < n; i++)
				cout << A[i]<<" ";
			cout << "\n";
		}
		cout << "what should i do?\n1)insert array\n2)delte array\n3)use linear serch\n4)use binary search\n5)use bubble sort\n6)use insert sort\n7)use choose sort8)use quick sort\n9)previous menu\n";
		int t;
		cin >> t;
		if (t == 1){
			if (A != NULL){
				delete[] A;
				A = NULL;
			}
			cout << "insert size of array: ";
			cin >> n;
			A = new int[n];
			cout << "insert elments of array:\n";
			for (int i = 0; i < n; i++)
				cin >> A[i];
		}
		else if (t == 2){
			n = 0;
			delete[] A;
			A = NULL;
		}
		else if (t == 3){
			cout << "insert vallue: ";
			int k;
			cin >> k;
			cout << "array include " << linear_search(A, A + n, k) << " lements with vallue " << k << "\n";
		}
		else if (t == 4){
			bool f = true;
			for (int i = 0; i < n - 1; i++)
				f &= A[i] >= A[i - 1];
			if (f){
				cout << "insert vallue: ";
				int k;
				cin >> k;
				cout << binary_search(A, n, k) - A << " is position of first element which no less than " << k;
			}
			else
				cout << "is not sorted\n";
		}
		else if (t == 5)
			bubble_sort(A, n);
		else if (t == 6)
			insert_sort(A, n);
		else if (t == 7)
			choose_sort(A, n);
		else if (t == 8)
			quick_sort(A, n);
		else if (t == 9)
			return;
		else
			cout << "error\n";
		_getch();
	}
}

void tree_work(){
	tree A;
	while (0 == 0){
		system("cls");
		A.show();
		cout << "\nwhat should i do?\n1)insert element\n2)erase element\n3)previous menu\n";
		int t = -1,pos,val;
		cin >> t;
		switch (t){
		case 1:
			cout << "insert position and value\n";
			cin >> pos >> val;
			A.insert(pos, val);
			break;
		case 2:
			cout << "insert deleting value\n";
			cin >> val;
			A.erase(val);
			break;
		case 3:
			return ;
		default: 
			cout << "incorrect format";
			_getch();
		}
	}
}

void bintree_work(){
	bst A;
	while (0 == 0){
		system("cls");
		A.show();
		cout << "\nwhat should i do?\n1)insert element\n2)erase element\n3)previous menu\n";
		int t = -1, val;
		cin >> t;
		switch (t){
		case 1:
			cout << "insert value\n";
			cin >> val;
			A.insert(val);
			break;
		case 2:
			cout << "insert delenting value\n";
			cin >> val;
			A.erase(val);
			break;
		case 3:
			return;
		default:
			cout << "incorrect format";
			_getch();
		}
	}
}

void rbt_work(){
	rbt A;
	while (0 == 0){
		system("cls");
		A.show();
		cout << "\nwhat should i do?\n1)insert element\n2)erase element\n3)previous menu\n";
		int t = -1, val;
		cin >> t;
		switch (t){
		case 1:
			cout << "insert value\n";
			cin >> val;
			A.insert(val);
			break;
		case 2:
			cout << "insert deleting value\n";
			cin >> val;
			A.erase(val);
			break;
		case 3:
			return;
		default:
			cout << "incorrect format";
			_getch();
		}
	}
}

void start_tree_work(){
	system("cls");
	int t=-1;
	cout << "which type of tree do you want to use?\n1)usual tree\n2)binary serch tree\n3)red-black tree\n";
	cin >> t;
	switch (t){
	case 1:
		tree_work();
		break;
	case 2:
		bintree_work();
		break;
	case 3:
		rbt_work();
		break;
	default:
		cout << "non_correct input format\n";
	}
}

int main() {/*
	freopen("swapper.in", "r", stdin);
	freopen("swapper.out", "w", stdout);
	int A[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	quick_sort(A, n);
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";//*/
	while (0 == 0){
		system("cls");
		cout << "insert 1 if work with arrays\ninsert 2 if work with trees\ninsert 3 for exit\n";
		int t;
		cin >> t;
		switch (t){
		case 1:
			array_work();
			break;
		case 2: 
			start_tree_work();
			break;
		case 3:
			return 0;
		default:
			cout << "incorrrect input data\n";
			_getch();
		}
	}
	return 0;
}