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
	void print2(pnode t, int level, int col) {
		col = min(max(0, col), szo - 1);
		if (t == NULL)
			return;
		out[level][col] = t->key;
		outok[level][col] = true;
		print2(t->left, level + 1, col - szo / (1 << (level + 2)));
		print2(t->right, level + 1, col + szo / (1 << (level + 2)));
		if (t->pred == NULL) {
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
		delete t;
		t = NULL;
	}
	bool find(pnode t, int x) {
		if (t == NULL)
			return false;
		if (t->key == x)
			return true;
		if (x < t->key)
			return find(t->left, x);
		else
			return find(t->right, x);
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
	pnode eraseMax(pnode& t) {
		if (t->right == NULL) {
			pnode x = t;
			if (t->pred->right == t)
				t->pred->right = t->left;
			else
				t->pred->left = t->left;
			return x;
		}
		return eraseMax(t->right);
	}
	pnode erase(pnode& t) {
		if (!t || (!t->left && !t->right)) {
			delete t;
			return t = NULL;
		}
		if (!t->left || !t->right) {
			pnode tmp = t;
			t = t->left ? t->left : t->right;
			delete tmp;
			return t;
		}
		pnode tmp = eraseMax(t->left);
		pnode lf = t->left, rt = t->right;
		delete t;
		t = tmp;
		t->left = lf;
		t->right = rt;
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
	cout << "Commands:\ninsert <key>\nclear\nprintSorted\nclear\nfind <x>\nheight\nsize\nleaves\ndegree\nprint\nright\nleft\nup\nerase\nsymmetry\n\n";
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
			bool b = t == root;
			clear(t);
			if (b)
				root = NULL;
		}
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
			if (size(t) > szo/5 || t == NULL)
				print(t);
			else
				print2(t, 0, szo / 2);
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
			if (t->pred != NULL)
				t = t->pred;
			else
				cout << "loser\n";
		else if (s == "erase") {
			bool b = t == root;
			t = erase(t);
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
		else
			cout << "!!!Warning, wrong command!!!\n";
	}
}

int main() {
	treeFunctions();
}