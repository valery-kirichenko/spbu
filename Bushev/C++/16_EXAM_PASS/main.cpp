#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <ctime>

using namespace std;

#include "bintree.h"
#include "rbtree.h"
#include "sort_n_search.h"

ostream& operator<<(ostream& a, vector<int> v) {
	for (unsigned int i = 0; i < v.size(); i++) {
		a << v[i] << (i == v.size() - 1 ? "" : " ");
	}

	if (!v.size()) a << "empty";

	return a;
}

// 0 - space, 1 - as tree
bool current_print_type = 0;

void show_bintree_menu(string param) {
	int counter = 4;
	system("cls");

	cout << "[1] Create " << param << endl;
	cout << "[2] Add node" << endl;
	cout << "[3] Delete tree" << endl;

	if(param != "rbtree") cout << "[4] Delete node" << endl;
	else counter--;

	cout << "[" << ++counter << "] Safe delete node" << endl;
	if (param != "rbtree") cout << "[" << ++counter << "] Change print type" << endl;
	cout << endl << "[0] Exit" << endl << endl;
}

void bintree_menu() {
	bintree<int> *mt = nullptr;
	int in_progress = 1, val;

	while (in_progress) {
		show_bintree_menu("bintree");
		show_tree(mt, current_print_type);
		
		cout << "Your choice: ";
		cin >> in_progress;

		switch (in_progress) {
			case 1: {
				if(mt) delete mt;
				mt = nullptr;

				cout << "Enter size: ";
				cin >> in_progress;

				for (int i = 0; i < in_progress; i++) {
					val = rand() % 99 + 1;
					tree_add(mt, val);
				}

				break;
			}case 2: {
				cout << "Enter value: ";
				cin >> val;

				tree_add(mt, val);
				break;
			}case 3: {
				delete mt;
				mt = nullptr;
				break;
			}case 4: {
				cout << "Enter value: ";
				cin >> val;

				tree_delete_node(mt, val);
				break;
			}case 5: {
				cout << "Enter value: ";
				cin >> val;

				tree_delete_safe(mt, val);
				break;
			}case 6: {
				current_print_type = !current_print_type;
				break;
			}
		}
	}
}

void rbtree_menu() {
	rbtm *mt = new rbtm();

	int in_progress = 1, val;

	while (in_progress) {
		show_bintree_menu("rbtree");
		mt->show_tree(mt->rootTree(), 0);

		cout << "Your choice: ";
		cin >> in_progress;

		switch (in_progress) {
			case 1: {
				cout << "Enter size: ";
				cin >> in_progress;

				for (int i = 0; i < in_progress; i++) {
					val = rand() % 100;
					mt->adding_node(val, 0);
				}

				break;
			}case 2: {
				cout << "Enter value: ";
				cin >> val;

				mt->adding_node(val, 1);
				break;
			}case 3: {
				delete mt;
				mt = new rbtm();
				break;
			}case 4: {
				cout << "Enter value: ";
				cin >> val;

				mt->safe_deleting_node(val);
				break;
			}
		}
	}
}

void show_array_menu() {
	system("cls");

	cout << "[1] Set array up" << endl << endl;
	cout << "[2] Linear search" << endl;
	cout << "[3] Binary search" << endl << endl;
	cout << "[4] Quicksort" << endl;
	cout << "[5] Bubble sort" << endl;
	cout << "[6] Insertion sort" << endl;
	cout << "[7] Selection sort" << endl << endl;
	cout << "[0] Exit" << endl << endl;
}

void array_menu() {
	vector<int> arr;
	int in_progress = 1;

	while (in_progress) {
		show_array_menu();
		cout << "Your array: " << arr << endl;
		cout << "Your choise: "; cin >> in_progress;

		if (arr.size() < 1 && in_progress != 1 && in_progress != 0) {
			cout << "Array is not set" << endl;
			system("pause");
			continue;
		}

		switch (in_progress) {
			case 1: {
				init_array(arr);
				break;
			}case 2: {
				linear_search(arr);
				break;
			}case 3: {
				binary_search(arr);
				break;
			}case 4: {
				quicksort(arr, 0, arr.size() - 1);
				break;
			}case 5: {
				bubble_sort(arr);
				break;
			}case 6: {
				insertion_sort(arr);
				break;
			}case 7: {
				selection_sort(arr);
				break;
			}
			case 0: {
				arr.clear();
				break;
			}
		}
	}
}

void show_main_menu() {
	system("cls");

	cout << "[1] Search and sort" << endl;
	cout << "[2] Binary tree" << endl;
	cout << "[3] Red-black-tree" << endl << endl;
	cout << "[0] Exit" << endl << endl;
	cout << "Your choise: ";
}

int main() {
	srand(time(NULL));
	int in_progress = 1;

	while (in_progress) {
		show_main_menu();
		cin >> in_progress;

		switch (in_progress) {
			case 1: {
				array_menu();
				break;
			}case 2: {
				bintree_menu();
				break;
			}case 3: {
				rbtree_menu();
				break;
			}
		}
	}

	return 0;
}