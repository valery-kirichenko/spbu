#include <iostream>

struct list {
	char value;
	list *next;
	list *prev;
};

int main() {
	char c;
	list *seq = new list;
	list *p = seq;
	p->prev = nullptr;
	std::cin >> p->value;
	std::cin >> c;
	while (c != '.') {
		if (c == '*') {
			delete p;
			p = p->prev;
		} else {
			list *n = p;
			p->next = new list;
			p = p->next;
			p->prev = n;

			p->value = c;
		}
		std::cin >> c;
	}
	p->next = nullptr;

	while (seq != nullptr) {
		std::cout << seq->value;
		seq = seq->next;
	}
	std::cout << std::endl;

	return 0;
}