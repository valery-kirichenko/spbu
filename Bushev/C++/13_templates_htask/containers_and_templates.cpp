#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class abs_row4 {
	int values[4];

public:
	abs_row4() {
		for (int i = 0; i < 4; i++) values[i] = -1;
	}

	abs_row4(int *input) {
		for (int i = 0; i < 4; i++) values[i] = abs(input[i]);
	}

	int get_val(int pos) {
		if (pos < 0 || pos > 3) return -1;
		return values[pos];
	}

	abs_row4(int a) {
		for (int i = 0; i < 4; i++) values[i] = a;
	}
};

ostream& operator<<(ostream& a, abs_row4 irow4) {
	for (int i = 0; i < 4; i++) a << irow4.get_val(i) << (i == 3 ? "" : "-");
	return a;
}

template <class type>
struct deq {
protected:
	type val;
	deq *first, *next = nullptr;
	int ds;

	deq(type data) {
		val = data;
	}

public:
	deq() { first = this; ds = 0; }

	bool is_empty() {
		return !first->ds;
	}

	void push_f(type data) {
		if (!first->ds) {
			first->val = data;
			++first->ds;
			return;
		}

		deq *tail = new deq(data);
		tail->next = first;
		tail->ds = first->ds;
		first = tail;

		first->ds++;
	}

	void push_b(type data) {
		if (!first->ds) {
			first->val = data;
			++first->ds;
			return;
		}

		deq *tail = first;
		while (tail->next) tail = tail->next;

		tail->next = new deq(data);
		first->ds++;
	}

	type pop_f() {
		if (this->is_empty()) return -1;

		type fval = first->val;

		if (first->next) {
			deq *next = first->next;
			first->val = next->val;
			first->next = first->next->next;
			--first->ds;
			delete next;
		}else this->ds = 0;

		return fval;
	}

	type pop_b() {
		if (this->is_empty()) return -1;

		type fval;

		if (this->size() == 1) {
			fval = first->val;
			this->ds = 0;
		}
		else {
			deq *lnext = first;
			for (int i = 0; i < this->size() - 2; i++) {
				lnext = lnext->next;
			}

			fval = lnext->next->val;
			delete(lnext->next);
			lnext->next = nullptr;
			--first->ds;
		}

		return fval;
	}

	int size() {
		return first->ds;
	}

	void show() {
		if (this->is_empty()) {
			cout << "empty" << endl;
			return;
		}

		deq *locq = first;

		while (locq->next) {
			cout << locq->val << " ";
			locq = locq->next;
		}

		cout << locq->val << endl;
	}

	bool is_equal(deq *p, type val, int num) {
		if (p->val == val) {
			cout << "Found at [" << num << "] pos!" << endl;
			return true;
		}
		else return false;
	}

	bool look_for(type val) {
		if (this->is_empty()) return false;

		int num = 1;
		deq *p = first;
		while (p->next) {
			if (is_equal(p, val, num)) return true;
			p = p->next;
			++num;
		}

		return is_equal(p, val, num);
	}
};

int main() {
	int *mrow_in = new int[4];
	for (int i = 0; i < 4; i++) mrow_in[i] = i;
	abs_row4 mrow(mrow_in);

	for (int i = 0; i < 4; i++) mrow_in[i] = i * 2;
	abs_row4 m2row(mrow_in);

	deq<abs_row4> mdr;
	mdr.push_f(mrow);
	mdr.push_b(m2row);

	cout << "Input mdr containts: " << endl;
	mdr.show();

	cout << "pop_front: " << mdr.pop_f() << endl;
	mdr.show();

	cout << "pop_back: " << mdr.pop_b() << endl;
	mdr.show(); cout << endl;

	system("pause");

	deq<int> md;
	int ch; int d;

	bool exit = 0;
	while (!exit) {
		system("cls");
		cout << "1 - push (back)" << endl;
		cout << "2 - push (front)" << endl;
		cout << "3 - pop (back)" << endl;
		cout << "4 - pop (front)" << endl;
		cout << "5 - check if empty" << endl;
		cout << "6 - find element" << endl;
		cout << "Your deque: "; md.show();
		cout << "Your choise: "; cin >> ch;

		switch (ch) {
			case 1: {
				cout << "Enter element: ";
				cin >> d;

				md.push_b(d);
				break;
			}case 2: {
				cout << "Enter element: ";
				cin >> d;

				md.push_f(d);
				break;
			}case 3: {
				md.pop_b();
				break;
			}case 4: {
				md.pop_f();
				break;
			}case 5: {
				if (md.is_empty()) {
					cout << "Your deque is empty!" << endl;
				}
				else cout << "Your deque is NOT empty!" << endl;

				system("pause");
				break;
			}case 6: {
				cout << "Search val: ";
				cin >> d;

				if (!md.look_for(d)) cout << "Element not found" << endl;

				system("pause");
				break;
			}case 0: {
				exit = true;
				break;
			}
		}
	}

	return 0;
}
