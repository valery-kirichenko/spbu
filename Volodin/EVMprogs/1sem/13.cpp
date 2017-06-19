#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory>

using namespace std;

namespace nd {
	struct node {
		node *left = NULL, *right = NULL, *pred = NULL;
		int key;
		node(int x, node* pred) :key(x), pred(pred) {}
	};
	typedef node* pnode;

	vector <int> sorted;
	const int szo = 80;
	vector < vector <int> > out(szo, vector <int>(szo));
	vector < vector <bool> > outok(szo, vector <bool>(szo));
	void print2(pnode t, int level, int col, bool pred = true) {
		col = min(max(0, col), szo - 1);
		if (t == NULL)
			return;
		if (t->pred == NULL || !pred)
			for (int i = 0; i < szo; i++)
				for (int j = 0; j < szo; j++) {
					outok[i][j] = false;
					out[i][j] = -1;
				}
		out[level][col] = t->key;
		outok[level][col] = true;
		print2(t->left, level + 1, col - szo / (1 << (level + 2)));
		print2(t->right, level + 1, col + szo / (1 << (level + 2)));
		if (t->pred == NULL || !pred) {
			for (int i = 0; i < szo; i++) {
				bool was = false;
				for (int j = 0; j < szo; j++)
					if (outok[i][j])
						was = true;
				if (was)
					for (int j = 0; j < szo; j++) {
						if (outok[i][j])
							cout << out[i][j];
						else
							cout << ' ';
					}
				cout << endl;
				if (!was)
					break;
			}
		}
	}
	void writeSorted(pnode t) {
		if (t == NULL)
			return;
		writeSorted(t->left);
		sorted.push_back(t->key);
		writeSorted(t->right);
	}
	pnode insert(pnode t, int x, pnode pred = NULL) {
		if (t == NULL)
			t = new node(x, pred);
		else if (x <= t->key)
			t->left = insert(t->left, x, t);
		else
			t->right = insert(t->right, x, t);
		return t;
	}
	void clear(pnode& t) {
		if (t == NULL)
			return;
		clear(t->left);
		clear(t->right);
		t->left = NULL;
		t->right = NULL;
		delete t;
		t = NULL;
	}
	pnode findnode(pnode t, int x) {
		if (t == NULL || t->key == x)
			return t;
		if (x < t->key)
			return findnode(t->left, x);
		else
			return findnode(t->right, x);
	}
	bool find(pnode t, int x) {
		return findnode(t, x) != NULL;
	}
	int height(pnode t) {
		if (t == NULL)
			return 0;
		return max(height(t->left), height(t->right)) + 1;
	}
	vector <int> getSorted(pnode t) {
		sorted.clear();
		writeSorted(t);
		return sorted;
	}
	int size(pnode t) {
		if (t == NULL)
			return 0;
		return size(t->left) + size(t->right) + 1;
	}
	int leaves(pnode t) {
		if (t == NULL)
			return 0;
		if (!t->left && !t->right)
			return 1;
		return leaves(t->left) + leaves(t->right);
	}
	int degree(pnode t) {
		if (t == NULL)
			return 0;
		return (t->left != NULL) + (t->right != NULL);
	}
	int level(pnode t) {
		if (t->pred == NULL)
			return 0;
		return level(t->pred) + 1;
	}
	void print(pnode t, bool dl = true) {
		if (dl && t == NULL)
			return void(cout << "NULL\n");
		cout << "(";
		cout << "key: " << t->key;
		if (t->left) {
			cout << ", left: ";
			print(t->left, false);
		}
		if (t->right) {
			cout << ", right: ";
			print(t->right, false);
		}
		cout << ")";
		if (dl)
			cout << endl;
	}
	void printSorted(pnode t) {
		vector <int> a = getSorted(t);
		for (auto i : a)
			cout << i << ' ';
		cout << endl;
	}

	pnode getEraseMax(pnode& t) {
		if (t->right == NULL)
			return t;
		return getEraseMax(t->right);
	}
	pnode erase(pnode& t, pnode& root) {
		if (!t || (!t->left && !t->right)) {
			auto tmp = t ? t->pred : NULL;
			if (t && t->pred)
				if (t->pred->right == t)
					t->pred->right = NULL;
				else
					t->pred->left = NULL;
			delete t;
			return tmp;
		}
		if (!t->left || !t->right) {
			auto now = t->left ? t->left : t->right;
			now->pred = t->pred;
			if (now->pred->right == t)
				now->pred->right = now;
			else
				now->pred->left = now;
			delete t;
			return now;
		}
		pnode tmp = getEraseMax(t->left);
		int temporar = tmp->key;
		erase(tmp, root);
		t->key = temporar;
		return t;
	}
	int simmetrical(pnode t) {
		vector <pnode> v[2];
		v[0].push_back(t);
		int res = 2;
		for (int i = 0; ; i++) {
			v[(i + 1) % 2].clear();
			int now = v[i % 2].size();
			bool was = false;
			for (int j = 0; j < now; j++) {
				pnode a = v[i % 2][j]->left, b = v[i % 2][j]->right, c = v[i % 2][now - j - 1]->right, d = v[i % 2][now - j - 1]->left;
				if ((a == NULL) != (c == NULL) || (b == NULL) != (d == NULL))
					return 0;
				if (a != NULL) {
					v[(i + 1) % 2].push_back(a);
					if (a->key != c->key)
						res = 1;
					was = true;
				}
				if (b != NULL) {
					v[(i + 1) % 2].push_back(b);
					if (b->key != d->key)
						res = 1;
					was = true;
				}
			}
			if (!was)
				break;
		}
		return res;
	}
};

using namespace nd;

void treeFunctions() {
	pnode t = NULL;
	pnode root = NULL;
	cout << "Commands:\ninsert <key>\nclear\nprintSorted\nclear\nfind <x>\nheight\nsize\nleaves\ndegree\nlevel\nprint\nright\nleft\nup\nerase\nsymmetry\ndeltree\n\n";
	while (true) {
		cout << "Command: ";
		string s; cin >> s;
		if (s == "insert") {
			int key;
			cin >> key;
			bool b = t == root;
			root = insert(root, key);
			if (b)
				t = root;
		}
		else if (s == "clear") {
			if (t && t->pred)
				if (t->pred->right == t)
					t->pred->right = NULL;
				else
					t->pred->left = NULL;
			pnode tmp = NULL;
			if (t)
				tmp = t->pred;
			bool b = t == root;
			clear(t);
			if (b)
				root = NULL;
			t = tmp;
		}
		else if (s == "eraseNumber") {
			int a; cin >> a;
			while (true) {
				auto p = findnode(t, a);
				if (p == NULL)
					break;
				erase(p, root);
			}
		}
		else if (s == "deltree")
			clear(root);
		else if (s == "printSorted")
			printSorted(t);
		else if (s == "find") {
			int x; cin >> x;
			cout << find(t, x) << endl;
		}
		else if (s == "height")
			cout << height(t) << endl;
		else if (s == "size")
			cout << size(t) << endl;
		else if (s == "leaves")
			cout << leaves(t) << endl;
		else if (s == "degree")
			cout << degree(t) << endl;
		else if (s == "level")
			cout << level(t) << endl;
		else if (s == "print")
			if (size(root) > szo / 5 || root == NULL)
				print(root);
			else
				print2(root, 0, szo / 2);
		else if (s == "right")
			if (t->right != NULL)
				t = t->right;
			else
				cout << "loser\n";
		else if (s == "left")
			if (t->left != NULL)
				t = t->left;
			else
				cout << "loser\n";
		else if (s == "up")
			if (t && t->pred)
				t = t->pred;
			else
				cout << "loser\n";
		else if (s == "erase") {
			bool b = t == root;
			t = erase(t, root);
			if (b)
				root = t;
		}
		else if (s == "symmetry") {
			int res = simmetrical(t);
			if (res == 0)
				cout << "No symetry";
			if (res == 1)
				cout << "Symmetrical structure";
			if (res == 2)
				cout << "The most symmetrical tree!";
			cout << endl;
		}
		else if (s == "getdata")
			cout << (t ? t->key : 0) << endl;
		else
			cout << "!!!Warning, wrong command!!!\n";
	}
}

int main() {
	treeFunctions();
}

/*insert 25
insert 20
insert 50
insert 15
insert 27
insert 42
insert 8
insert 22
insert 34
insert 18
insert 31
insert 48
insert -1
insert 33
printSorted
find 42
find 33
find 10
print
getdata
height
size
leaves
degree
level
symmetry
right
left
right
getdata
height
size
leaves
degree
level
symmetry
erase
print
erase
print
clear
print
up
up
insert 70
insert 80
insert 90
insert 60
print
symmetry
eraseNumber -1
eraseNumber 90
eraseNumber 80
eraseNumber 60
eraseNumber 18
eraseNumber 8
print
getdata
symmetry
deltree
print
*/