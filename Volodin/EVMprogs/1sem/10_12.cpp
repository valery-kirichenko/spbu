#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


typedef pair <int, int> pii;
ostream& operator << (ostream & out, pii a) {
	out << a.first << ' ' << a.second << "  ";
	return out;
}

namespace nd {
	template <class T>
	struct node {
		node *next, *pred;
		T d;
		node() { next = NULL; pred = NULL; }
		node(T val, node* next, node* pred):next(next), pred(pred), d(val){}
	};
	
	template <class T>
	class nodeWorker {
		bool pop_last() {
			delete first;
			first = last = NULL;
			sz--;
			return true;
		}
		node<T>* push_first(T val) {
			sz++;
			node <T> *p = new node<T>(val, NULL, NULL);
			return first = last = p;
		}
		node <T> *first = NULL, *last = NULL;
		int sz = 0;
	protected:
		void print(node<T>* t) {
			if (t == NULL)
				return;
			cout << t->d << ' ';
			print(t->next);
		}
		void printBack(node<T>* t) {
			if (t == NULL)
				return;
			cout << t->d << ' ';
			printBack(t->pred);
		}

		node<T>* push_back(T val) {
			if (last == NULL)
				return push_first(val);
			sz++;
			node <T> *p = new node<T>(val, NULL, last);
			return last = p->pred->next = p;
		}
		node<T>* push_front(T val) {
			if (first == NULL)
				return push_first(val);
			sz++;
			node <T> *p = new node<T>(val, first, NULL);
			return first = p->next->pred = p;
		}
		bool pop_front() {
			if (first == last)
				return pop_last();
			node<T> *tmp = first->next;
			delete first;
			first = tmp;
			tmp->pred = NULL;
			sz--;
			return true;
		}
		bool pop_back() {
			if (first == last)
				return pop_last();
			node<T> *tmp = last->pred;
			delete last;
			last = tmp;
			tmp->next = NULL;
			sz--;
			return true;
		}
		node<T>* front() {
			return first;
		}
		node<T>* back() {
			return last;
		}

		node<T>* insert(node<T>* t, int pos, int val) {
			if (pos - (t == first) <= 0) {
				if (t == first && pos == 0)
					return push_front(val);
				else if (t == last)
					return push_back(val);
				sz++;
				node<T> *p = new node<T>(val, t->next, t);
				return p->next->pred = p->pred->next = p;
			}
			else if (t->next != NULL && pos >= 0)
				return insert(t->next, pos - 1 - (t == first), val);
			cerr << "Bad position in insert2\n";
			return NULL;
		}

		bool erase(node<T>* t, int pos) {
			if (!pos) {
				if (t == first)
					return pop_front();
				else if (t == last)
					return pop_back();
				node<T> *nx = t->next, *pr = t->pred;
				delete t;
				t = NULL;
				nx->pred = pr;
				pr->next = nx;
				sz--;
				return true;
			}
			else if (t->next != NULL && pos >= 0)
				return erase(t->next, pos - 1);
			cerr << "Bad position in insert2\n";
			return false;
		}

		void clear() {
			while (first != NULL)
				erase(first, 0);
		}
		int size() {
			return sz;
		}
		bool empty() {
			return first == NULL;
		}
		node<T>* getFirst() {
			return first;
		}
		node<T>* getLast() {
			return last;
		}

		int find(node<T>* t, T val, bool forward = true) {
			int pos = 0;
			while (t != NULL) {
				if (t->d == val)
					break;
				pos++;
				t = forward ? t->next : t->pred;
			}
			return  t ? pos : -1;
		}

		~nodeWorker() {
			clear();
		}
	};

	template <class T>
	class lst: nodeWorker<T>{
	public:
		void insert(int pos, T val) {
			nodeWorker::insert(getFirst(), pos, val);
		}
		void erase(int pos) {
			nodeWorker::erase(getFirst(), pos);
		}
		void clear() {
			nodeWorker::clear();
		}
		void print() {
			nodeWorker::print(getFirst());
		}
		int somesum(){
			node<T> *a = getFirst(), *b = getLast();
			int res = 0;
			while (a) {
				res += a->d * b->d;
				a = a->next;
				b = b->pred;
			}
			return res;
		}
		node<T>* someMethod(node<T>* t, T val){
			nodeWorker::insert(t, 0, val);
		}
		int size() {
			return nodeWorker::size();
		}
		bool empty() {
			return nodeWorker::empty();
		}
	};

	template <class T>
	class stk :nodeWorker<T> {
	public:
		void push(T val) {
			nodeWorker::push_back(val);
		}
		void pop() {
			nodeWorker::pop_back(val);
		}
		T top() {
			return nodeWorker::back()->d;
		}
		bool empty() {
			return nodeWorker::empty();
		}
	};

	template <class T>
	class que:nodeWorker<T> {
	public:
		void push(T val) {
			nodeWorker::push_back(val);
		}
		void pop() {
			nodeWorker::pop_front();
		}
		T front() {
			return nodeWorker::front()->d;
		}
		bool empty() {
			return nodeWorker::empty();
		}
		void print() {
			nodeWorker::print(getFirst());
		}
	};
};

using namespace nd;

void listFeatures() {
	cout << "Commands:\ninsert <pos> <val>\nerase <pos>\nsomesum\nsize\nprint\n\n";
	lst<int> ls;
	while (true) {
		string s; cin >> s;
		int a, b;
		if (s == "insert") {
			cin >> a >> b;
			ls.insert(a, b);
		}
		if (s == "erase") {
			cin >> a;
			ls.erase(a);
		}
		if (s == "somesum") {
			cout << ls.somesum() << endl;
		}
		if (s == "size") {
			cout << ls.size() << endl;
		}
		if (s == "print") {
			cout << "List: ";
			ls.print();
			cout << endl;
		}
	}
}

#define mp make_pair
int& getd(pii a, vector <vector <int> > & d) {
	return d[a.first][a.second];
}
void chess() {
	int dx[] = {1,2,2,1,-1,-2,-2,-1};
	int dy[] = {2,1,-1,-2,-2,-1,1,2};
	string a, b; cin >> a >> b;
	vector < vector <int> > d(8, vector <int>(8, -1));
	pii start = mp(a[0] - 'A', a[1] - '1'), finish = mp(b[0] - 'A', b[1] - '1');
	que <pii> q;

	getd(start, d) = 0;
	q.push(start);
	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			pii to = mp(now.first + dx[i], now.second + dy[i]);
			if (to.first >= 0 && to.second >= 0 && to.first < 8 && to.second < 8) 
				if (getd(to, d) == -1) {
					getd(to, d) = getd(now, d) + 1;
					q.push(to);
				}
		}
	}
	cout << getd(finish, d) << endl;
}

int main() {
	while (true)
		chess();
}