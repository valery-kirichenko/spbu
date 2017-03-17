#include <iostream>

class RBT {
	bool isExist;

	struct Node {
		int value;
		int color;
		Node *parent;
		Node *left;
		Node *right;
	};

	Node emptyNode = { 0, 0, nullptr, nullptr, nullptr };
	Node *nullNode = &emptyNode;
	Node *root;

	void RotateLeft(Node *node) {
		Node *right = node->right;
		// Переносим указатель правого поддерева текущего узла на right.
		node->right = right->left;
		if (right->left != nullNode)
			right->left->parent = node;
		// Переносим указатель родителя текущего узла на right.
		if (right != nullNode)
			right->parent = node->parent;
		if (node->parent != nullNode) {
			if (node == node->parent->left)
				node->parent->left = right;
			else
				node->parent->right = right;
		}
		else {
			root = right;
		}
		right->left = node;
		if (node != nullNode)
			node->parent = right;
	}

	// Правый поворот дерева.
	void RotateRight(Node *node) {
		Node *left = node->left;
		// Переносим указатель левого поддерева текущего узла на left.
		node->left = left->right;
		if (left->right != nullNode)
			left->right->parent = node;
		// Переносим указатель родителя текущего узла на left.
		if (left != nullNode)
			left->parent = node->parent;
		if (node->parent != nullNode) {
			if (node == node->parent->right)
				node->parent->right = left;
			else
				node->parent->left = left;
		}
		else {
			root = left;
		}
		left->right = node;
		if (node != nullNode)
			node->parent = left;
	}

	// Восстановление свойств после добавления узла.
	void InsertFixup(Node *node) {
		Node *uncle;
		// Текущий узел является красным.
		while ((node != root) && (node->parent->color == 1)) {
			if (node->parent == node->parent->parent->left) {
				// Узел находится в левом поддереве "деда".
				uncle = node->parent->parent->right;
				if (uncle->color == 1) {
					// Случай 1 - "дядя" является красным узлом.
					node->parent->color = 0;
					uncle->color = 0;
					node->parent->parent->color = 1;
					node = node->parent->parent;
				}
				else {
					// Случаи 2 и 3 - "дядя" является чёрным узлом.
					if (node == node->parent->right) {
						//Преобразуем случай 2 в случай 3.
						node = node->parent;
						RotateLeft(node);
					}
					// Случай 3.
					node->parent->color = 0;
					node->parent->parent->color = 1;
					RotateRight(node->parent->parent);
				}
			}
			else {
				// Узел находится в правом поддереве "деда".
				uncle = node->parent->parent->left;
				if (uncle->color == 1) {
					//"Дядя" является красным узлом.
					node->parent->color = 0;
					uncle->color = 0;
					node->parent->parent->color = 1;
					node = node->parent->parent;
				}
				else {
					// "Дядя" является чёрным узлом.
					if (node == node->parent->left) {
						node = node->parent;
						RotateRight(node);
					}
					node->parent->color = 0;
					node->parent->parent->color = 1;
					RotateLeft(node->parent->parent);
				}
			}
		}
		root->color = 0;
	}

	// Восстановление сбалансированности дерева после удаления.
	void RemoveFixup(Node *node) {
		while ((node != root) && (node->color == 0)) {
			if (node == node->parent->left) {
				Node *w = node->parent->right;
				if (w->color == 1) {
					w->color = 0;
					node->parent->color = 1;
					RotateLeft(node->parent);
					w = node->parent->right;
				}
				if ((w->left->color == 0) && (w->right->color == 0)) {
					w->color = 1;
					node = node->parent;
				}
				else {
					if (w->right->color == 0) {
						w->left->color = 0;
						w->color = 1;
						RotateRight(w);
						w = node->parent->right;
					}
					w->color = node->parent->color;
					node->parent->color = 0;
					w->right->color = 0;
					RotateLeft(node->parent);
					node = root;
				}
			}
			else {
				Node *w = node->parent->left;
				if (w->color == 1) {
					w->color = 0;
					node->parent->color = 1;
					RotateRight(node->parent);
					w = node->parent->left;
				}
				if ((w->right->color == 0) && (w->left->color == 0)) {
					w->color = 1;
					node = node->parent;
				}
				else {
					if (w->left->color == 0) {
						w->right->color = 0;
						w->color = 1;
						RotateLeft(w);
						w = node->parent->left;
					}
					w->color = node->parent->color;
					node->parent->color = 0;
					w->left->color = 0;
					RotateRight(node->parent);
					node = root;
				}
			}
		}
		node->color = 0;
	}

	void RemoveSubtree(Node *node) {
		if (node == root)
			isExist = false;
		if (node != nullNode) {
			if (node->left != nullNode)
				RemoveSubtree(node->left);
			if (node->right != nullNode)
				RemoveSubtree(node->right);
			delete node;
		}
	}

public:
	RBT() {
		root = nullNode;
		isExist = false;
	}

	~RBT() {
		if (isExist)
			RemoveSubtree(root);
	}

	void Insert(int value) {
		Node *node = nullNode;
		Node *parent = nullNode;
		isExist = true;
		// Поиск листа для нового элемента.
		for (node = root; (node != nullNode) && (node != nullptr);) {
			parent = node;
			/*
			if (value < node->value)
				node = node->left;
			else if (value > node->value)
				node = node->right;
			else
				return;
				*/
			if (value > node->value)
				node = node->right;
			else
				node = node->left;
		}
		node = new Node;
		node->value = value;
		node->color = 1;
		node->parent = parent;
		node->left = nullNode;
		node->right = nullNode;

		if (parent != nullNode) {
			if (value < parent->value)
				parent->left = node;
			else
				parent->right = node;
		}
		else {
			root = node;
		}

		InsertFixup(node);
	}

	void RemoveNode(int value) {
		Node *x, *y, *z;
		// Находим узел в дереве.
		z = root;
		while (z != nullNode) {
			if (value == z->value)
				break;
			else
				z = (value < z->value) ? z->left : z->right;
		}
		if (z == nullNode)
			return;
		if ((z->left == nullNode) || (z->right == nullNode)) {
			// Ставим Y нулевой узел как ребёнка.
			y = z;
		}
		else {
			// Находим в дереве "преемника" с нулевым узлом в качестве ребёнка.
			y = z->right;
			while (y->left != nullNode)
				y = y->left;
		}
		// X только единственный ребёнок.
		if (y->left != nullNode)
			x = y->left;
		else
			x = y->right;
		// Удаляем из родительской цепи.
		x->parent = y->parent;
		if ((y->parent && y->parent != nullNode) || (CountNodes(root) == 2 && y != root))
			if (y == y->parent->left)
				y->parent->left = x;
			else
				y->parent->right = x;
		else
			root = x;
		if (y != z)
			z->value = y->value;
		if (y->color == 0)
			RemoveFixup(x);
		if (y == root)
			isExist = false;
		delete y;
	}

	void PrintTree(Node *node, int level) {
		if ((node != nullNode) && (isExist)) {
			PrintTree(node->left, level + 1);
			for (int i = 0; i < level; i++)
				std::cout << "   ";
			if (node != nullNode)
				std::cout << node->value << " " << node->color;
			std::cout << std::endl;
			PrintTree(node->right, level + 1);
		}
	}

	void PrintTree() {
		PrintTree(root, 0);
	}

	int CountNodes(Node *node) {
		int count = 0;
		if ((node != nullNode) && (isExist)) {
			count++;
			count += CountNodes(node->left);
			count += CountNodes(node->right);
		}
		return count;
	}
};

int main() {
	RBT a;
	a.Insert(11);
	a.Insert(2);
	a.Insert(14);
	a.Insert(1);
	a.Insert(7);
	a.Insert(5);
	a.Insert(8);
	a.Insert(15);
	a.PrintTree();
	a.Insert(4);
	a.PrintTree();
	/*
	std::cout << "-------------------" << std::endl;
	a.RemoveNode(3);
	a.PrintTree();
	std::cout << "-------------------" << std::endl;
	a.RemoveNode(3);
	a.PrintTree();
	std::cout << "-------------------" << std::endl;
	a.RemoveNode(5);
	a.PrintTree();
	*/
	return 0;
}