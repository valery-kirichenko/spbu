#include <iostream>

struct list {
	int value;
	list *next;
};

void print_list(list *lst) {
	list *p = lst;
	while (p != nullptr) {
		std::cout << p << " " << p->value << std::endl;
		p = p->next;
	}
}

int get_list_length(list *lst) {
	int length = 0;
	list *p = lst;
	while (p != nullptr) {
		length++;
		p = p->next;
	}
	return length;
}

list* insert_item(list *lst, int pos, int value) {
	int length = get_list_length(lst);
	if (pos == 0) {
		list *n = new list;
		n->value = value;
		n->next = lst;

		return n;
	} else if (pos >= length) {
		if (pos > length) pos = length;
		int i = 0;
		list *prev = lst;
		while (i < pos - 1) {
			i++;
			prev = prev->next;
		}
		prev->next = new list;
		prev = prev->next;
		prev->value = value;
		prev->next = nullptr;

		return lst;
	} else if (pos < length && pos > 0) {
		int i = 0;
		list *prev = lst;
		while (i < pos - 1) {
			i++;
			prev = prev->next;
		}
		list *next = prev->next;
		prev->next = new list;
		prev = prev->next;
		prev->value = value;
		prev->next = next;

		return lst;
	} else {
		return lst;
	}
}

list* remove_item(list *lst, int pos) {
	if (pos == 0) {
		list *next = lst->next;
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
		return lst;
	} else {
		return lst;
	}
}

list* search_item(list *lst, int value) {
	list *prev = lst;
	int length = get_list_length(lst),
	    i = 0;
	while (prev->value != value && i < length) {
		i++;
		if (i < length) prev = prev->next;
	}

	if (i < length) return prev;
	else return nullptr;
}

int main() {
	int n;
	std::cin >> n;

	list *lst = new list;
	list *p = lst;

	std::cin >> p->value;

	for (int i = 0; i < n - 1; i++) {
		p->next = new list;
		p = p->next;
		std::cin >> p->value;
	}
	p->next = nullptr;

	std::cout << "Input ended" << std::endl;
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

	

	return 0;
}