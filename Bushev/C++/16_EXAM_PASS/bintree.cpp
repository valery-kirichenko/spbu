#include "bintree.h"
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

// подсчет количества узлов
int tree_nodes(bintree<type> *mt) {
	int count = 0;
	if (mt) {
		count++;
		count += tree_nodes(mt->left);
		count += tree_nodes(mt->right);
	}

	return count;
}

// добавление нового элемента
void tree_add(bintree<type> *&mt, type val) {
	if (!mt) {
		mt = new bintree<type>();
		mt->field = val;
	}
	else if (val < mt->field) tree_add(mt->left, val);
	else tree_add(mt->right, val);
};

// удаление узла по значению
void tree_delete_node(bintree<type> *&mt, type val) {
	if (!mt) {
		cout << "Your val was NOT found" << endl;
		system("pause");
		return;
	}

	if (val < mt->field) tree_delete_node(mt->left, val);
	else if (val > mt->field) tree_delete_node(mt->right, val);
	else {
		delete mt;
		mt = nullptr;
	}
}

// удаление узла с перестройкой дерева
void tree_delete_safe(bintree<type> *&mt, type val) {
	if (!mt) {
		cout << "Your val was NOT found" << endl;
		system("pause");
		return;
	}

	if (val < mt->field) tree_delete_safe(mt->left, val);
	else if (val > mt->field) tree_delete_safe(mt->right, val);
	else {
		bintree<type> *left = mt->left;
		bintree<type> *right = mt->right;

		if (left && right && left->right) {
			bintree<type> *parent = mt;

			while (left->right) {
				parent = left;
				left = left->right;
			}

			parent->right = left->left;
			left->left = nullptr;
			mt->field = left->field;

			delete left;
		}
		else if (left) {
			if (!left->right) left->right = mt->right;

			mt->left = nullptr;
			mt->right = nullptr;

			delete mt;
			mt = left;
		}
		else {
			mt->left = nullptr;
			mt->right = nullptr;

			delete mt;
			mt = right;
		}
	}
}

/////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
int make_link_list(bintree<type> *mt, bintree<type> **pointer, vector<type> *&link_list, int id) {
	pointer[id] = mt;
	int old = id;

	// раздаем id левым потомкам
	if (mt->left) {
		link_list[old].push_back(id + 1);
		id = make_link_list(mt->left, pointer, link_list, id + 1);
	}

	// правым
	if (mt->right) {
		link_list[old].push_back(id + 1);
		id = make_link_list(mt->right, pointer, link_list, id + 1);
	}

	return id;
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

// nice print
void as_tree_print(bintree<type> *mt, int start_level) {
	if (mt) {
		bintree<int>** pointer = new bintree<int>*[tree_nodes(mt)];
		vector<int> *link_list = new vector<int>[tree_nodes(mt)];

		make_link_list(mt, pointer, link_list, 0);

		queue<int> mq;
		mq.push(0);

		int circle = 0, length = 0, cons_width = 80, current_level = 0;
		queue<int> cq, sq;
		sq.push(1);

		int i = 0;

		while (!mq.empty()) {
			int id = mq.front();
			mq.pop();

			int sid = sq.front();
			sq.pop();

			for (i; i < (80 / (pow(2, current_level) + 1)) * sid; i++) cout << " ";
			if (pointer[id]->field < 10) cout << " " << pointer[id]->field;
			else cout << pointer[id]->field;

			i += 2;
			sid *= 2;

			for (unsigned int i = 0; i < link_list[id].size(); i++) {
				mq.push(link_list[id][i]);

				if (pointer[link_list[id][i]]->field > pointer[id]->field) sq.push(sid);
				else sq.push((sid - 1));
			}

			length += link_list[id].size();

			if (circle <= 0) {
				i = 0;
				cout << endl;
				current_level++;

				cq.push(length);
				length = 0;

				if (cq.size() > 0) {
					circle = cq.front();
					cq.pop();
				}
			}

			--circle;
		}

		cout << endl << endl;
	}
}

// space numbers
void space_print(bintree<type> *mt, int start_level) {
	if (mt) {
		// выводим левую ветку (сверху), сдвигаясь на уровень, чтобы добавить отступов
		space_print(mt->left, start_level + 1);
		for (int i = 0; i < start_level; i++) cout << "   ";

		// показываем значение текущего узла
		cout << mt->field << "\n";
		// выводим правую ветку, сдвигаясь на один уровень
		space_print(mt->right, start_level + 1);
	}
}

// managing printing
void show_tree(bintree<type> *mt, int print_type) {
	if (mt) {
		if (!print_type) space_print(mt, 0);
		else as_tree_print(mt, 0);
	}
	else cout << "Tree is not created" << endl;
	cout << endl;
}