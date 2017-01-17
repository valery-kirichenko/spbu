#include "rbtree.h"

void rbtm::rotate_left(rbtree *node) {
	rbtree *right = node->right;

	node->right = right->left;
	if (right->left != nil) right->left->parent = node;

	if (right != nil) right->parent = node->parent;
	if (node->parent != nil) {
		if (node == node->parent->left) node->parent->left = right;
		else node->parent->right = right;
	}
	else root = right;

	right->left = node;
	if (node != nil) node->parent = right;
}

void rbtm::rotate_right(rbtree *node) {
	rbtree *left = node->left;

	node->left = left->right;
	if (left->right != nil)
		left->right->parent = node;

	if (left != nil) left->parent = node->parent;
	if (node->parent != nil) {
		if (node == node->parent->right) node->parent->right = left;
		else node->parent->left = left;
	}
	else root = left;

	left->right = node;
	if (node != nil) node->parent = left;
}

void rbtm::splash_deletion(rbtree *node) {
	if (node == nullptr || node == nil) return;

	if (node->left && node->left != nil) delete node->left;
	if (node->right && node->right != nil) delete node->right;
	delete node;
}

void rbtm::fixing_insertion(rbtree *node) {
	rbtree *uncle;

	while (node != root && node->parent->color == red) {
		// if parent is on the left of granpa
		if (node->parent == node->parent->parent->left) {
			uncle = node->parent->parent->right;

			// and uncle is red [1]
			if (uncle->color == red) {
				node->parent->color = black;
				uncle->color = black;
				node->parent->parent->color = red;
				node = node->parent->parent;
			}
			else {
				// and uncle is black [2, 3]
				if (node == node->parent->right) {
					// rotate node if node is on the right side
					node = node->parent;
					rotate_left(node);
				}

				// case 3 -> rotate grandpa (don't work with 2 elements)
				node->parent->color = black;
				node->parent->parent->color = red;
				rotate_right(node->parent->parent);
			}
		}
		else {
			// if parent is on the right of granpa
			uncle = node->parent->parent->left;

			// and uncle is red [4]
			if (uncle->color == red) {
				node->parent->color = black;
				uncle->color = black;
				node->parent->parent->color = red;
				node = node->parent->parent;
			}
			else {
				// and uncle is black [5, 6]
				if (node == node->parent->left) {
					// rotate node if node is on the right side
					node = node->parent;
					rotate_right(node);
				}

				// case 6 -> rotate grandpa (don't work with 2 elements)
				node->parent->color = black;
				node->parent->parent->color = red;
				rotate_left(node->parent->parent);
			}
		}
	}

	// root color is always black
	root->color = black;
}

void rbtm::adding_node(type field, bool notification) {
	rbtree *node = nil;
	rbtree *parent = nil;

	// searching place
	for (node = root; (node != nil) && (node != nullptr);) {
		parent = node;
		if (field < node->field) node = node->left;
		else if (field > node->field) node = node->right;
		else {
			if (notification) {
				cout << "Such val is already using" << endl;
				system("pause");
			}

			return;
		}
	}

	// object is not null
	inited = true;

	// creating a new node
	node = new rbtree();
	node->field = field;
	node->color = red;
	node->parent = parent;
	node->left = nil;
	node->right = nil;

	if (parent != nil) {
		if (field < parent->field) parent->left = node;
		else parent->right = node;
	}
	else root = node;	// it was the root
	fixing_insertion(node);
}

void rbtm::fixing_deleting(rbtree *node) {
	while (node != root && node->color == black) {
		if (node == node->parent->left) {
			rbtree *w = node->parent->right;
			if (w->color == red) {
				w->color = black;
				node->parent->color = red;
				rotate_left(node->parent);
				w = node->parent->right;
			}
			if ((w->left->color == black) && (w->right->color == black)) {
				w->color = red;
				node = node->parent;
			}
			else {
				if (w->right->color == black) {
					w->left->color = black;
					w->color = red;
					rotate_right(w);
					w = node->parent->right;
				}
				w->color = node->parent->color;
				node->parent->color = black;
				w->right->color = black;
				rotate_left(node->parent);
				node = root;
			}
		}
		else {
			rbtree *w = node->parent->left;
			if (w->color == red) {
				w->color = black;
				node->parent->color = red;
				rotate_right(node->parent);
				w = node->parent->left;
			}
			if ((w->right->color == black) && (w->left->color == black)) {
				w->color = red;
				node = node->parent;
			}
			else {
				if (w->left->color == black) {
					w->right->color = black;
					w->color = red;
					rotate_left(w);
					w = node->parent->left;
				}
				w->color = node->parent->color;
				node->parent->color = black;
				w->left->color = black;
				rotate_right(node->parent);
				node = root;
			}
		}
	}
	node->color = black;
}

void rbtm::safe_deleting_node(type val) {
	rbtree *child, *deleted, *node;
	node = root;

	// searching for the val
	while (node != nil) {
		if (val == node->field) break;
		else node = (val < node->field) ? node->left : node->right;
	}

	// if not found
	if (node == nil) {
		cout << "Your val was NOT found" << endl;
		system("pause");
		return;
	}

	// if new_node has just one child
	if (node->left == nil || node->right == nil) deleted = node;
	else {
		// finding the last left element of the right child
		deleted = node->right;
		while (deleted->left != nil) deleted = deleted->left;
	}

	// if there is only one child
	if (deleted->left != nil) child = deleted->left;
	else child = deleted->right;

	// replacing node (root) by child
	child->parent = deleted->parent;
	if ((deleted->parent && deleted->parent != nil)
		|| (count_nodes(root) == 2 && deleted != root)) {
		if (deleted == deleted->parent->left) deleted->parent->left = child;
		else deleted->parent->right = child;
	}
	else root = child;

	// fixing colors & change values
	node->field = deleted->field;
	if (deleted->color == black) fixing_deleting(child);

	// if splash deletion
	//deleted->left = nil;
	//deleted->right = nil;

	delete deleted;
}

void rbtm::space_print(rbtree *mt, int start_level) {
	if ((mt != nil) && (inited)) {
		// выводим левую ветку (сверху), сдвигаясь на уровень, чтобы добавить отступов
		space_print(mt->left, start_level + 1);
		for (int i = 0; i < start_level; i++) cout << "   ";

#if (!defined __linux__)
		// изменяем цвет консоли и текста в ней
		if (mt->color == black) SetConsoleTextAttribute(hCons, (WORD)((0 << 4) | 7));		// black = white :(
		else SetConsoleTextAttribute(hCons, (WORD)((0 << 4) | 4));							// 7 - gray / 4 - red
#endif

		// показываем значение текущего узла
		cout << mt->field << "\n";

		// выводим правую ветку, сдвигаясь на один уровень
		space_print(mt->right, start_level + 1);
	}
}

void rbtm::show_tree(rbtree *mt, int print_type) {
	if (mt != nil && inited) {
		//if (!print_type)
		space_print(mt, 0);
		//else as_tree_print(mt, 0);

#if (!defined __linux__)
		SetConsoleTextAttribute(hCons, (WORD)((0 << 4) | 7));
#endif
	}
	else cout << "Tree is not created" << endl;
	cout << endl;
}

int rbtm::count_nodes(rbtree *node){
	int count = 0;
	if (node != nil && inited) {
		++count;
		count += count_nodes(node->left);
		count += count_nodes(node->right);
	}
	return count;
}