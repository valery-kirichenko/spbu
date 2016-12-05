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
};

using namespace nd;

void treeFunctions() {
	pnode t = NULL;
	pnode root = NULL;
	cout << "Commands:\ninsert <key>\nclear\nprintSorted\nclear\nfind <x>\nheight\nsize\nleaves\ndegree\nprint\nright\nleft\nup\n\n";
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
			print(t);
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
		else
			cout << "!!!Warning, wrong command!!!\n";
	}
}

int main() {
	treeFunctions();
}