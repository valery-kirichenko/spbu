// redblacktree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

class rbtreeV {
private:
	bool isExist;
	struct tree 
	{
		int value;
		int color;
		tree *parent;
		tree *left;
		tree *right;
	};
	tree emptyNode = { NULL, 1, nullptr, nullptr, nullptr };
	tree *nullNode = &emptyNode;
	tree *root;

	//Левый поворот дерева.
	void rotateLeft(tree *node)
	{
		tree *right = node->right;
		//Переносим указатель правого поддерева текущего узла на right.
		node->right = right->left;
		if (right->left != nullNode)
			right->left->parent = node;
		//Переносим указатель родителя текущего узла на right.
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

	//Правый поворот дерева.
	void rotateRight(tree *node)
	{
		tree *left = node->left;
		//Переносим указатель левого поддерева текущего узла на left.
		node->left = left->right;
		if (left->right != nullNode)
			left->right->parent = node;
		//Переносим указатель родителя текущего узла на left.
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

public:
	rbtreeV()
	{
		root = nullNode;
		isExist = false;
	}

	~rbtreeV()
	{
		if (isExist)
			deleteSubtree(root);
	}

	//Восстановление свойств после добавления узла.
	void fixupAdd(tree *node)
	{
		tree *uncle;
		//Текущий узел является красным.
		while ((node != root) && (node->parent->color == 0)) {
			if (node->parent == node->parent->parent->left) {
				//Узел находится в левом поддереве "деда".
				uncle = node->parent->parent->right;
				if (uncle->color == 0) {
					//Случай 1 - "дядя" является красным узлом.
					node->parent->color = 1;
					uncle->color = 1;
					node->parent->parent->color = 0;
					node = node->parent->parent;
				}
				else {
					//Случаи 2 и 3 - "дядя" является чёрным узлом.
					if (node == node->parent->right) {
						//Преобразуем случай 2 в случай 3.
						node = node->parent;
						rotateLeft(node);
					}
					//Случай 3.
					node->parent->color = 1;
					node->parent->parent->color = 0;
					rotateRight(node->parent->parent);
				}
			}
			else {
				//Узел находится в правом поддереве "деда".
				uncle = node->parent->parent->left;
				if (uncle->color == 0) {
					//"Дядя" является красным узлом.
					node->parent->color = 1;
					uncle->color = 1;
					node->parent->parent->color = 0;
					node = node->parent->parent;
				}
				else {
					//"Дядя" является чёрным узлом.
					if (node == node->parent->left) {
						node = node->parent;
						rotateRight(node);
					}
					node->parent->color = 1;
					node->parent->parent->color = 0;
					rotateLeft(node->parent->parent);
				}
			}
		}
		root->color = 1;
	}

	//Добавление элементов/создание дерева.
	void add(int value)
	{
		tree *node = nullNode;
		tree *parent = nullNode;
		isExist = true;
		//Поиск листа для нового элемента.
		for (node = root; (node != nullNode) && (node != nullptr);) {
			parent = node;
			if (value < node->value)
				node = node->left;
			else if (value > node->value)
				node = node->right;
			else
				return;
		}
		node = new tree;
		node->value = value;
		node->color = 0;
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

		fixupAdd(node);
	}

	//Удаление поддерева с потомками.
	void deleteSubtree(tree *node)
	{
		if (node == root)
			isExist = false;
		if (node != nullNode) {
			if (node->left != nullNode)
				deleteSubtree(node->left);
			if (node->right != nullNode)
				deleteSubtree(node->right);
			delete node;
		}
	}

	//Восстановление сбалансированности дерева после удаления.
	void deleteFixup(tree *node) {
		while ((node != root) && (node->color == 1)) {
			if (node == node->parent->left) {
				tree *w = node->parent->right;
				if (w->color == 0) {
					w->color = 1;
					node->parent->color = 0;
					rotateLeft(node->parent);
					w = node->parent->right;
				}
				if ((w->left->color == 1) && (w->right->color == 1)) {
					w->color = 0;
					node = node->parent;
				}
				else {
					if (w->right->color == 1) {
						w->left->color = 1;
						w->color = 0;
						rotateRight(w);
						w = node->parent->right;
					}
					w->color = node->parent->color;
					node->parent->color = 1;
					w->right->color = 1;
					rotateLeft(node->parent);
					node = root;
				}
			}
			else {
				tree *w = node->parent->left;
				if (w->color == 0) {
					w->color = 1;
					node->parent->color = 0;
					rotateRight(node->parent);
					w = node->parent->left;
				}
				if ((w->right->color == 1) && (w->left->color == 1)) {
					w->color = 0;
					node = node->parent;
				}
				else {
					if (w->left->color == 1) {
						w->right->color = 1;
						w->color = 0;
						rotateLeft(w);
						w = node->parent->left;
					}
					w->color = node->parent->color;
					node->parent->color = 1;
					w->left->color = 1;
					rotateRight(node->parent);
					node = root;
				}
			}
		}
		node->color = 1;
	}

	//Удаление с изменением структуры дерева.
	void deleteNode(int value) {
		tree *x, *y, *z;
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
		if (y->parent)
			if (y == y->parent->left)
				y->parent->left = x;
			else
				y->parent->right = x;
		else
			root = x;
		if (y != z)
			z->value = y->value;
		if (y->color == 1)
			deleteFixup(x);
		delete y;
	}


	//Наглядная печать.
	void print_Tree(tree *node, int level)
	{
		if ((node != nullNode) && (isExist)) {
			print_Tree(node->left, level + 1);
			for (int i = 0; i < level; i++)
				std::cout << "   ";
			if (node != nullNode)
				std::cout << node->value;
			std::cout << std::endl;
			print_Tree(node->right, level + 1);
		}
	}

	//Обход дерева в префиксной форме.
	void printPref(tree *node)
	{
		if ((node != nullNode) && (isExist)) {
			std::cout << node->value << "\n";
			printPref(node->left);
			printPref(node->right);
		}
	}

	//Обход дерева в инфиксной форме.
	void printInf(tree *node)
	{
		if ((node != nullNode) && (isExist)) {
			printInf(node->left);
			std::cout << node->value << "\n";
			printInf(node->right);
		}
	}

	//Обход дерева в постфиксной форме.
	void printPost(tree *node)
	{
		if ((node != nullNode) && (isExist)) {
			printPost(node->left);
			printPost(node->right);
			std::cout << node->value << "\n";
		}
	}

	//Подсчёт узлов дерева.
	int countElem(tree *node)
	{
		int count = 0;
		if ((node != nullNode) && (isExist)) {
			count++;
			count += countElem(node->left);
			count += countElem(node->right);
		}
		return count;
	}

	//Подсчёт листьев дерева.
	int countLeaf(tree *node)
	{
		int count = 0;
		if ((node != nullNode) && (isExist)) {
			if ((node->left == nullNode) && (node->right == nullNode))
				count++;
			count += countLeaf(node->left);
			count += countLeaf(node->right);
		}
		return count;
	}

	//Подсчёт высоты дерева.
	int countHeight(tree *node)
	{
		int left = 0, right = 0;
		if ((node != nullNode) && (isExist)) {
			left = (node->left != nullNode) ? countHeight(node->left) : 0;
			right = (node->right != nullNode) ? countHeight(node->right) : 0;
			return ((left > right) ? left : right) + 1;
		}
		return 0;
	}

	tree *rootTree()
	{
		return root;
	}

	bool exist()
	{
		return isExist;
	}
};


int main()
{
	rbtreeV rbtree;
	rbtree.add(2);
	rbtree.add(3);
	rbtree.add(10);
	rbtree.delete(10);
	rbtree.add(1);
	rbtree.add(2);
	rbtree.add(7);
	rbtree.add(5);
	std::cout << rbtree.countElem(rbtree.rootTree()) << " " << rbtree.countHeight(rbtree.rootTree()) << " " << rbtree.countLeaf(rbtree.rootTree()) << "\n";
	rbtree.print_Tree(rbtree.rootTree(), 0);
	system("pause");
    return 0;
}

