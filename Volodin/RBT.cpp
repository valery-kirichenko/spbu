#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <functional>

using namespace std;

namespace stv {
	

	template <class T>
	class RBT {
		
		template <class T>
		struct Node;
		Node<T> *NIL = new Node<T>(NIL);
		enum nodeColor { BLACK, RED };

		template <class T>
		struct Node {
			Node *left, *right, *parent;
			nodeColor color;
			T data;
			Node(T data, Node<T>* NIL) :data(data), left(NIL), right(NIL), parent(NIL), color(RED) {}
			Node(Node<T>* NIL) :left(NIL), right(NIL), parent(NIL) { color = BLACK; }

			Node*& l(bool op) { return op ? right : left; }
			Node*& r(bool op) { return op ? left : right; }
		};

		Node<T> *root = NIL;

		void rotate(Node<T>* x, bool b) {//b = right
			Node<T> *y = x->r(b);
			x->r(b) = y->l(b);
			if (x->r(b) != NIL)
				x->r(b)->parent = x;
			y->parent = x->parent;
			if (x->parent == NIL)
				root = y;
			x->parent->r(b ^ (x->parent->l(b) == x)) = y;
			y->l(b) = x;
			x->parent = y;
		}

		void print(Node<T>* t, bool en = true) {
			cout << '(';
			if (t == NIL)
				cout << "NIL";
			else {
				cout << "d: " << t->data << ", c: " << t->color;
				cout << ", l: ";
				print(t->left, false);
				cout << ", r: ";
				print(t->right, false);
			}
			cout << ')';
			if (en)
				cout << endl;
		}

		void insert_fixup(Node<T>* z) {
			while (z->parent->color == RED) {
				bool b = z->parent != z->parent->parent->left;
				Node<T> *y = z->parent->parent->r(b); //uncle
				if (y->color == RED) {
					z->parent->color = BLACK;
					y->color = BLACK;
					z->parent->parent->color = RED;
					z = z->parent->parent;
				}
				else {
					if (z == z->parent->r(b)) {
						z = z->parent;
						rotate(z, b);
					}
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					rotate(z->parent->parent, !b);
				}
			}
			root->color = BLACK;
		}

		void insert(Node<T>* z) {
			Node<T> *y = NIL, *x = root;
			while (x != NIL) {
				y = x;
				x = x->r(z->data < x->data);
			}
			z->parent = y;
			if (y == NIL)
				root = z;
			else
				y->r(z->data < y->data) = z;
			insert_fixup(z);
		}

		void del(Node<T>* t) {
			if (t == NIL)
				return;
			del(t->right);
			del(t->left);
			delete t;
		}

		void transplant(Node<T>* u, Node<T>* v) {
			if (u->parent == NIL)
				root = v;
			else
				u->parent->r(u == u->parent->left) = v;
			v->parent = u->parent;
		}

		Node<T>* treemin(Node<T>* t) {
			while (t->left != NIL)
				t = t->left;
			return t;
		}

		void erase_fixup(Node<T>* x) {
			while (x != root && x->color == BLACK) {
				bool b = x != x->parent->left;
				Node<T> *w = x->parent->r(b);
				if (w->color == RED) {
					swap(w->color, x->parent->color);
					rotate(x->parent, b);
					w = x->parent->r(b);
				}
				if (w->l(b)->color == BLACK && w->r(b)->color == BLACK) {
					w->color = RED;
					x = x->parent;
				}
				else {
					if (w->r(b)->color == BLACK) {
						swap(w->l(b)->color, w->color);
						rotate(w, !b);
						w = x->parent->r(b);
					}
					w->color = x->parent->color;
					x->parent->color = BLACK;
					w->r(b)->color = BLACK;
					rotate(x->parent, b);
					x = root;
				}
			}
			x->color = BLACK;
		}

		void erase(Node<T> *z) {
			if (z == NIL)
				return;
			Node<T> *y = z, *x;
			nodeColor origin_color = y->color;
			if (z->left == NIL || z->right == NIL) {
				x = z->r(z->right == NIL);
				transplant(z, z->r(z->right == NIL));
			}
			else {
				y = treemin(z->right);
				origin_color = y->color;
				x = y->right;
				if (y->parent == z)
					x->parent = y;
				else {
					transplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				transplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			if (origin_color == BLACK)
				erase_fixup(x);
		}

		Node<T>* treefind(Node<T>* t, T x) {
			if (t == NIL || t->data == x)
				return t;
			return treefind(t->r(t->data > x), x);
		}

		int h(Node<T> *t) {
			if (t == NIL)
				return 0;
			return max(h(t->left), h(t->right)) + 1;
		}
		int size(Node<T> *t) {
			if (t == NIL)
				return 0;
			return size(t->left) + size(t->right) + 1;
		}

	public:
		void insert(T x) {
			insert(new Node<T>(x, NIL));
		}
		void erase(T x) {
			erase(treefind(root, x));
		}
		int getHeight() {
			return h(root);
		}
		int getSize() {
			return size(root);
		}
		~RBT() {
			del(root);
			root = NIL;
		}
	};
}
using namespace stv;

/*void hsz() {
	int n = 1000000;
	while (n--)
		insert(new Node(rand()));
	cout << "h: " << h(root) << "\tsize: " << size(root) << endl;
	del(root);
	root = NIL;
}
void ff() {
	int a; 
	while ((cin >> a), a != 0) {
		insert(new Node(a));
		print(root);
	}
	del(root);
	root = NIL;
}
void gg() {
	char c; int a;
	while ((cin >> c >> a), c != '0') {
		if (c == 'i') 
			insert(new Node(a));
		else if (c == 'e')
			erase(treefind(root, a));
		print(root);
	}
}*/
void tester() {
	const int n = 1000000;
	cout << "size: " << n << endl;
	vector <int> a(n);
	generate(a.begin(), a.end(), rand);
	RBT<int> r;
	clock_t cstartis = clock();
	for (int i : a)
		r.insert(i);
	clock_t cfinishis = clock();
	cout << "Insert-time: " << (double)(cfinishis - cstartis) / CLOCKS_PER_SEC << endl;
	random_shuffle(a.begin(), a.end());

	clock_t cstart = clock();
	for (int i : a)
		r.erase(i);
	clock_t cfinish = clock();
	cout << "Erase-time: " << (double)(cfinish - cstart) / CLOCKS_PER_SEC << endl;
	
}
void stdr(function<void()> f) {
	srand(time(NULL));
	clock_t cstart = clock();
	f();
	clock_t cfinish = clock();
	cout << "Time: " << (double)(cfinish - cstart) / CLOCKS_PER_SEC << endl;
}

int main() {
	stdr(tester);
}