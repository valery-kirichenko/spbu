#pragma once
#include <vector>

typedef int type;

// bintree structure
template <typename T>
struct bintree {
	T field;
	bintree *left, *right;

	~bintree() {
		delete left;
		delete right;
	}
};

int tree_nodes(bintree<type> *mt);
void tree_add(bintree<type> *&mt, type val);
void tree_delete_node(bintree<type> *&mt, type val);
void tree_delete_safe(bintree<type> *&mt, type val);
int make_link_list(bintree<type> *mt, bintree<type> **pointer, std::vector<type> *&link_list, int id);
void as_tree_print(bintree<type> *mt, int start_level);
void space_print(bintree<type> *mt, int start_level);
void show_tree(bintree<type> *mt, int print_type);