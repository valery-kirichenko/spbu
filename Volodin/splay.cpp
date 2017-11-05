#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <ctime>

using namespace std;


uint64_t get_cycles() {
	return time(NULL);
}

template <typename T>
struct node {
	T key;
	T sum = 0;
	int count = 0;
	node *left = NULL, *right = NULL, *father = NULL;
	void recount() {
		if (this == NULL)
			return;
		sum = key * count;
		if (left != NULL)
			sum += left->sum;
		if (right != NULL)
			sum += right->sum;
	}
	~node<T>() {
		if (left != NULL)
			left->~node<T>();
		if (right != NULL)
			right->~node<T>();
		left = NULL;
		right = NULL;
		delete left;
		delete right;
	}
};


template <typename T>
struct splay_tree {
	node<T> *root = NULL;
	int _size = 0;


	void insert(T x) {
		if (find(x)) {
			root->count++;
			root->recount();
		}
		else {
			auto trees = split(root, x);
			root = new node<T>;
			root->key = x;
			root->count++;
			root->recount();
			assign(root, trees.first, true);
			assign(root, trees.second, false);
		}
		_size++;
	}
	bool remove(T x) {
		root = splay(find_node(root, x), root);
		if (!root || root->key != x)
			return false;
		if (root->count > 1) {
			root->count--;
			root->recount();
		}
		else
			root = merge(root->left, root->right);
		_size--;
		return true;
	}
	int size() {
		return _size;
	}
	bool find(T x) {
		if (root == NULL)
			return false;
		node<T> *res = find_node(root, x);
		root = splay(res, root);
		return res->key == x;
	}
	int count(T x) {
		if (!find(x))
			return 0;
		return root->count;
	}

	T sum(T l, T r) {
		auto byr = split(root, r + 1);
		auto byl = split(byr.first, l);
		T res = byl.second ? byl.second->sum : 0;
		root = merge(merge(byl.first, byl.second), byr.second);
		return res;
	}



	node<T>* merge(node<T>* t1, node<T>* t2) {
		if (t1)
			t1->father = NULL;
		if (t2)
			t2->father = NULL;
		node<T> *tmp = splay(find_max(t1), t1);
		if (tmp == NULL)
			return t2;
		assign(tmp, t2, false);
		return tmp;
	}
	pair <node<T>*, node<T>*> split(node<T>*& t, T x) {
		if (t == NULL)
			return make_pair((node<T>*)NULL, (node<T>*)NULL);
		node<T> *tmp1 = find_node(t, x);
		node<T> *tmp = splay(tmp1, t);
		node<T> *left, *right;
		if (tmp->key < x) {
			right = tmp->right;
			left = tmp;
			left->right = NULL;
		}
		else {
			left = tmp->left;
			right = tmp;
			right->left = NULL;
		}
		if (left != NULL)
			left->father = NULL;
		if (right != NULL)
			right->father = NULL;
		right->recount();
		left->recount();
		return make_pair(left, right);
	}

	node<T>* splay(node<T>* x, node<T>* upper) {
		if (x == NULL)
			return x;
		while (x->father != NULL && x != upper) {
			x = zigzigzagzig(x, upper);
		}
		return x;
	}

	node<T>* zigzigzagzig(node<T>* x, node<T>* upper) {
		if (x == upper || x == NULL)
			return x;
		node<T> *father = x->father;
		if (father == upper) {
			if (father->left == x)
				return rotate_left(father);
			if (father->right == x)
				return rotate_right(father);
		}
		node<T> *grandy = father->father;
		if (grandy->left == father)
			if (father->left == x)
				return rotate_left(rotate_left(grandy));
			else {
				rotate_right(father);
				return rotate_left(grandy);
			}
		else
			if (father->right == x)
				return rotate_right(rotate_right(grandy));
			else {
				rotate_left(father);
				return rotate_right(grandy);
			}
	}

	node<T>* rotate_left(node<T>* t) {
		node<T> *x = t->left, *father = t->father;
		assign(t, x->right, true);
		assign(x, t, false);
		replace_child(father, x, t);
		return x;
	}
	node<T>* rotate_right(node<T>* t) {
		node<T> *x = t->right, *father = t->father;
		assign(t, x->left, false);
		assign(x, t, true);
		replace_child(father, x, t);
		return x;
	}

	void assign(node<T> *&father, node<T> *&child, bool left) {
		if (left)
			father->left = child;
		else
			father->right = child;
		if (child != NULL)
			child->father = father;
		father->recount();
	}
	void replace_child(node<T> *&father, node<T> *&newchild, node<T> *&oldChild) {
		if (father == NULL) {
			newchild->father = NULL;
			return;
		}
		if (father->left == oldChild)
			father->left = newchild;
		else
			father->right = newchild;
		newchild->father = father;
		father->recount();
	}

	//left <=, right >
	node<T>* find_node(node<T>* t, T x) {
		if (t == NULL || t->key == x)
			return t;
		return t->key >= x ?
			(t->left ? find_node(t->left, x) : t) :
			(t->right ? find_node(t->right, x) : t);
	}
	node<T>* find_max(node<T>* t) {
		return !t || !t->right ? t : find_max(t->right);
	}
	node<T>* find_min(node<T>* t) {
		return !t || !t->left ? t : find_max(t->left);
	}
	~splay_tree() {
		if (root != NULL)
			root->~node();
	}


	void print(node<T> * t) {
		cout << "\t\t\t\t\ttree\n\n";
		out.clear();
		outok.clear();
		out.resize(szo, vector <T>(szo));
		outok.resize(szo, vector <bool>(szo));
		print2(t);
	}
	void print() {
		print(root);
	}
	void print1(node<T> *t, bool caret = true) {
		if (t == NULL)
			cout << "N";
		else {
			cout << '(';
			cout << "key: " << t->key;
			cout << ", ";
			cout << "left: ";
			print1(t->left, false);
			cout << ", ";
			cout << "right: ";
			print1(t->right, false);
			cout << ')';
		}
		if (caret)
			cout << endl;
	}
	static const int szo = 80;
	vector < vector <T> > out;
	vector < vector <bool> > outok;
	void print2(node<T>* t, int level = 0, int col = szo / 2, bool pred = true) {
		col = min(max(0, col), szo - 1);
		if (t == NULL)
			return;
		if (t->father == NULL || !pred)
			for (int i = 0; i < szo; i++)
				for (int j = 0; j < szo; j++) {
					outok[i][j] = false;
					out[i][j] = -1;
				}
		out[level][col] = t->key;
		outok[level][col] = true;
		print2(t->left, level + 1, col - szo / (1 << (level + 2)));
		print2(t->right, level + 1, col + szo / (1 << (level + 2)));
		if (t->father == NULL || !pred) {
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
	vector <int> sorted;
	void writeSorted(node<T>* t) {
		if (t == NULL)
			return;
		writeSorted(t->left);
		sorted.push_back(t->key);
		writeSorted(t->right);
	}
	vector <int> getSorted(node<T>* t) {
		sorted.clear();
		writeSorted(t);
		return sorted;
	}
	void printSorted() {
		vector <int> a = getSorted(root);
		for (auto i : a)
			cout << i << ' ';
		cout << endl;
	}
};

void testtime() {
	vector <int> v;
	for (int i = 0; i < 1000000; i++)
		v.push_back(rand() % 10000);
	set<int> s;
	splay_tree<int> t;
	clock_t tStart, tStop;
	tStart = clock();
	for (int i : v)
		s.insert(i);
	while (s.size())
		s.erase(s.begin());
	tStop = clock();
	cout << "set " << (double)(tStop - tStart) / CLOCKS_PER_SEC << endl;
	tStart = clock();
	for (int i : v)
		t.insert(i);
	while (t.size())
		t.remove(t.root->key);
	tStop = clock();
	cout << "splay " << (double)(tStop - tStart) / CLOCKS_PER_SEC << endl;
}

void testcorrectness() {
	splay_tree<int> t;
	multiset<int> s;
	for (int i = 0; i < 10000; i++) {
		int x = rand() % 100;
		if (rand() % 2) {
			if (t.count(x) != s.count(x) || t.size() != s.size()) {
				cout << "bad";
			}
		}
		else if (rand() % 2) {
			t.insert(x);
			s.insert(x);
		}
		else {
			if (s.count(x))
				s.erase(s.find(x));
			t.remove(x);
		}
	}
}

void testsums() {
	splay_tree<int> t;
	multiset<int> s;
	for (int i = 0; i < 10000; i++) {
		int x = rand() % 100;
		if (rand() % 2 == 0) {
			int l = (rand() % 100) - 5;
			int r = (rand() % (105 - l + 1)) + l;
			int sums = 0, sumt = 0;
			for (int t : s)
				if (l <= t && t <= r)
					sums += t;
			sumt = t.sum(l, r);
			if (sums != sumt) {
				cout << "badsum";
			}
			//cout << sums << ' ' << sumt << endl;
		}
		else if (rand() % 3 == 0) {
			if (t.find(x) != s.count(x) > 0 || t.size() != s.size())
				cout << "badfind";
		}
		else if (rand() % 2 == 0) {
			t.insert(x);
			s.insert(x);
		}
		else {
			if (s.count(x))
				s.erase(s.find(x));
			t.remove(x);
		}
	}
}

void testsome() {
	auto tm = get_cycles();
	tm = 4222720548343;
	cout << tm << endl;
	srand(tm);
	testsums();
}

int main() {
	splay_tree<long long> st;
	long long m = 1000000001;
	long long x = 0;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		if (c == '?') {
			long long t; cin >> t;
			cout << (st.find((t + x) % m) ? "Found" : "Not found");
			cout << '\n';
		}
		if (c == '+') {
			long long t; cin >> t;
			if (!st.find((t + x) % m))
				st.insert((t + x) % m);
		}
		if (c == '-') {
			long long t; cin >> t;
			st.remove((t + x) % m);
		}
		if (c == 's') {
			long long l, r; cin >> l >> r;
			x = st.sum((l + x) % m, (r + x) % m) % m;
			//x = 0;
			cout << x << '\n';
		}
	}
}


/*
4222720548343
*/
