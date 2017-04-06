#include <iostream>

class BST {
	struct Node {
		int value;
		Node *left, *right, *parent;
	};

	Node *root;

	void ReplaceParent(Node *node, Node *replace = nullptr) {
		if (node->parent != nullptr) {
			if (node->value > node->parent->value) {
				node->parent->right = replace;
			} else {
				node->parent->left = replace;
			}
		} else {
			root = replace;
		}
	}

public:
	BST() {
		root = nullptr;
	}

	BST(int value) {
		BST();
		Insert(value);
	}

	~BST() {
		RemoveSubtree(root);
	}

	Node* Insert(int value) {
		Node* parent = nullptr;
		Node* walk = root;

		Node *insert = new Node;
		insert->value = value;
		insert->left = nullptr;
		insert->right = nullptr;

		while (walk != nullptr) {
			parent = walk;
			if (value > walk->value) {
				walk = walk->right;
			} else {
				walk = walk->left;
			}
		}

		insert->parent = parent;

		if (parent == nullptr) {
			insert->parent = nullptr;
			root = insert;
		} else if (value > parent->value) {		
			parent->right = insert;
		} else {
			parent->left = insert;
		}

		return insert;
	}

	Node* Search(Node *tree, int value) {
		if (tree == nullptr || tree->value == value) {
			return tree;
		}

		if (value > tree->value) {
			return Search(tree->right, value);
		} else {
			return Search(tree->left, value);
		}
	}

	Node* Search(int value) {
		return Search(root, value);
	}

	void RemoveSubtree(Node *tree) {
		if (tree == nullptr) return;
		if (tree->left != nullptr) {
			RemoveSubtree(tree->left);
		}

		if (tree->right != nullptr) {
			RemoveSubtree(tree->right);
		}

		if (tree->value > tree->parent->value) {
			tree->parent->right = nullptr;
		} else {
			tree->parent->left = nullptr;
		}
		delete tree;
	}

	void RemoveNode(Node *node) {
		if (node->left == nullptr && node->right == nullptr) {
			ReplaceParent(node, nullptr);
		} else if (node->left != nullptr && node->right != nullptr) {
			Node *replace = node->right;
			while (replace->left != nullptr) {
				replace = replace->left;
			}
			ReplaceParent(node, replace);
			replace->left = node->left;
			replace->right = node->right;
			replace->parent = node->parent;
		} else {
			if (node->left != nullptr) {
				ReplaceParent(node, node->left);
				node->left->parent = node->parent;
			} else {
				ReplaceParent(node, node->right);
				node->right->parent = node->parent;
			}
		}
		delete node;
	}

	void PrintTree(Node *tree, int level) {
		if (tree != nullptr) {
			PrintTree(tree->right, level + 1);
			for (int i = 0; i < level; i++) {
				std::cout << "  ";
			}
			std::cout << tree->value << "\n";
			PrintTree(tree->left, level + 1);
		}
	}

	void PrintTree() {
		PrintTree(root, 0);
	}
};

int main() {
	BST a;
	a.Insert(5);
	a.Insert(3);
	a.Insert(1);
	a.Insert(3);
	a.Insert(3);
	a.PrintTree();
	std::cout << "-------------------" << std::endl;
	a.RemoveNode(a.Search(3));
	a.PrintTree();
	std::cout << "-------------------" << std::endl;
	a.RemoveNode(a.Search(3));
	a.PrintTree();
	std::cout << "-------------------" << std::endl;
	a.RemoveNode(a.Search(5));
	a.PrintTree();

	return 0;
}
