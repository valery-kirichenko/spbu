#include <iostream>

struct list {
	int value;
	list *next;
	list *prev;
};

void print_list(list *lst, bool upside_down = false) {
	list *p = lst;
	while (p != nullptr) {
		std::cout << p << " " << p->value << std::endl;
		p = upside_down ? p->prev : p->next;
	}
}

int get_list_length(list *lst, bool upside_down = false) {
	int length = 0;
	list *p = lst;
	while (p != nullptr) {
		length++;
		p = upside_down ? p->prev : p->next;
	}
	return length;
}

list* insert_item(list *lst, int pos, int value) {
	int length = get_list_length(lst);
	if (pos == 0) {
		list *n = new list;
		n->value = value;
		n->next = lst;
		n->prev = nullptr;

		return n;
	} else if (pos >= length) {
		if (pos > length) pos = length;
		int i = 0;
		list *l = lst;
		while (i < pos - 1) {
			i++;
			l = l->next;
		}
		list *p = l;
		l->next = new list;
		l = l->next;
		l->prev = p;
		l->value = value;
		l->next = nullptr;

		return lst;
	} else if (pos < length && pos > 0) {
		int i = 0;
		list *l = lst;
		while (i < pos - 1) {
			i++;
			l = l->next;
		}
		list *next = l->next;
		l->next = new list;
		list *p = l;
		l = l->next;
		l->value = value;
		l->next = next;
		l->prev = p;

		return lst;
	} else {
		return lst;
	}
}

list* remove_item(list *lst, int pos) {
	if (pos == 0) {
		list *next = lst->next;
		next->prev = nullptr;
		delete lst;
		return next;
	} else if (pos < get_list_length(lst) && pos > 0) {
		int i = 0;
		list *prev = lst;
		while (i < pos - 1) {
			i++;
			prev = prev->next;
		}
		list *next = prev->next->next;
		delete prev->next;
		prev->next = next;
		if (next != nullptr) next->prev = prev;
		return lst;
	} else {
		return lst;
	}
}

list* search_item(list *lst, int value, bool upside_down = false) {
	list *p = lst;
	int length = get_list_length(lst, upside_down),
	    i = 0;

	while (p->value != value && i < length) {
		i++;
		if (i < length) p = upside_down ? p->prev : p->next;
	}

	if (i < length) return p;
	else return nullptr;
}

int main() {
	int n;
	std::cin >> n;

	list *lst = new list;
	list *p = lst;

	p->prev = nullptr;
	std::cin >> p->value;

	for (int i = 0; i < n - 1; i++) {
		list *n = p;
		p->next = new list;
		p = p->next;
		p->prev = n;
		std::cin >> p->value;
	}
	p->next = nullptr;

	print_list(lst);

	int pos, value;
	std::cout << "Insert: Enter position (0-started) and value: ";
	std::cin >> pos >> value;
	
	lst = insert_item(lst, pos, value);	
	print_list(lst);

	std::cout << "Remove: Enter position (0-started): ";
	std::cin >> pos;

	lst = remove_item(lst, pos);
	print_list(lst);

	std::cout << "Search: Enter value: ";
	std::cin >> value;
	list *find = search_item(lst, value);
	if (find != nullptr) std::cout << find << " " << find->value << std::endl;
	else std::cout << "Not found" << std::endl;

	p = lst;
	while (p->next != nullptr) p = p->next;
	std::cout << "Search upside down: Enter value: ";
	std::cin >> value;
	find = search_item(p, value, true);
	if (find != nullptr) std::cout << find << " " << find->value << std::endl;
	else std::cout << "Not found" << std::endl;

	std::cout << "\n\n===== Задание 3 =====\n\n";
	std::cin >> n;
	list *seq = new list;
	p = seq;

	p->prev = nullptr;
	std::cin >> p->value;

	for (int i = 0; i < n - 1; i++) {
		list *n = p;
		p->next = new list;
		p = p->next;
		p->prev = n;
		std::cin >> p->value;
	}
	p->next = nullptr;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += seq->value * p->value;
		seq = seq->next;
		p = p->prev;
	}
	std::cout << "Sum: " << sum << std::endl;

	return 0;
}