#pragma once

#include <iostream>
#include <windows.h>

typedef int type;
typedef enum { red, black } nodeColor;

using namespace std;

// tree structure
struct rbtree {
	type field;
	rbtree *parent;
	rbtree *left;
	rbtree *right;
	nodeColor color;
};

// rbtree manager class
class rbtm {
private:
	// initialized or not
	bool inited;
	rbtree *root;

	// nil element & link to it
	rbtree emptyNode = { NULL, nullptr, nullptr, nullptr, black };
	rbtree *nil = &emptyNode;

	// handle to change color
	HANDLE hCons = hCons = GetStdHandle(STD_OUTPUT_HANDLE);

	// rotation
	void rotate_left(rbtree *node);
	void rotate_right(rbtree *node);

	// deleting elem & childs
	void splash_deletion(rbtree *node);

public:
	rbtm() {
		root = nil;
		inited = false;
	}

	~rbtm() {
		if (inited) splash_deletion(root);
	}

	// fixing colors + adding elements
	void fixing_insertion(rbtree *node);
	void adding_node(type field, bool notification);

	// fixing colors after del + safe delition
	void fixing_deleting(rbtree *node);
	void safe_deleting_node(type val);

	// space numbers
	void space_print(rbtree *mt, int start_level);
	void show_tree(rbtree *mt, int print_type);

	int count_nodes(rbtree *node);
	rbtree *rootTree() { return root; }
};