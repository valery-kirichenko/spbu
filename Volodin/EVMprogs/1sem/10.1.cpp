#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Node {
	Node *next;
	int d;
};

void insert(Node *&t, int pos, int val) {
	if (!pos) {
		Node *nd = new Node();
		nd->next = t->next;
		nd->d = val;
		t->next = nd;
	}
	else
		insert(t->next, pos - 1, val);
}

void print(Node *t, bool skip = true) {
	if (t == NULL)
		return;
	if (!skip)
		cout << t->d << ' ';
	print(t->next, false);
}

void erase(Node *&t, int pos) {
	if (!pos) {
		Node *tmp = t->next;
		t->next = t->next->next;
		delete tmp;		
	}
	else erase(t->next, pos - 1);
}

int find(Node *t, int val, bool start = true) {
	if (t == NULL)
		return -2;
	if (val == t->d && !start)
		return -1;
	else {
		int k = find(t->next, val, false);
		if (k == -2)
			return -2;
		return k + 1;
	}
}


int main() {
	cout << "Commands:\ninsert <pos> <val>\nerase <pos>\nfind <val>\n";
	Node *t = new Node();
	while (true) {
		string s; cin >> s;
		int a, b;
		if (s == "insert") {
			cin >> a >> b;
			insert(t, a, b);
		}
		if (s == "erase") {
			cin >> a;
			erase(t, a);
		}
		if (s == "find") {
			cin >> a;
			cout << find(t, a) << endl;
		}
		cout << "List: ";
		print(t);
		cout << endl;
	}
}