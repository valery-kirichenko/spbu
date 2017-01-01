#pragma once
#ifndef TREE_H
#define TREE_H

template <typename TR>
class treeV {
private:
	bool isExist;
	struct bintree {
		TR value;
		bintree *left;
		bintree *right;
	};

public:
	bintree *root;

	treeV() 
	{
		root = nullptr;
		isExist = false;
	}

	~treeV()
	{
		if (isExist)
			deleteSubtree(root);
	}

	//Добавление элементов/создание дерева.
	bintree *addNode(TR value, bintree *tree) 
	{
		isExist = true;
		if (tree == nullptr) {
			tree = new bintree;
			tree->value = value;
			tree->left = nullptr;
			tree->right = nullptr;
		}
		else  if (value < tree->value)
			tree->left = addNode(value, tree->left);
		else
			tree->right = addNode(value, tree->right);
		return tree;
	}

	//Удаление поддерева с потомками.
	void deleteSubtree(bintree *tree) 
	{
		if (tree == root)
			isExist = false;
		if (tree != nullptr) {
			if (tree->left != nullptr)
				deleteSubtree(tree->left);
			if (tree->right != nullptr)
				deleteSubtree(tree->right);
			delete tree;
		}
	}

	//Удаление с изменением структуры дерева.
	bintree *deleteNode(TR value, bintree *node)
	{
		if (isExist) {
			if (node == nullptr)
				return node;
			if (value == node->value) {
				bintree *temp;
				if (node->right == nullptr)
					temp = node->left;
				else {
					bintree *ptr = node->right;
					if (ptr->left == nullptr) {
						ptr->left = node->left;
						temp = ptr;
					}
					else {
						bintree *pmin = ptr->left;
						while (pmin->left != nullptr)
						{
							ptr = pmin;
							pmin = ptr->left;
						}
						ptr->left = pmin->right;
						pmin->left = node->left;
						pmin->right = node->right;
						temp = pmin;
					}
				}
				delete node;
				return temp;
			}
			else if (value < node->value)
				node->left = deleteNode(value, node->left);
			else
				node->right = deleteNode(value, node->right);
			return node;
		}
		return node;
	}

	//Наглядная печать.
	void print_Tree(bintree *tree, int level)
	{
		if ((tree != nullptr) && (isExist)) {
			print_Tree(tree->left, level + 1);
			for (int i = 0; i < level; i++)
				std::cout << "   ";
			std::cout << tree->value << "\n";
			print_Tree(tree->right, level + 1);
		}
	}

	//Обход дерева в префиксной форме.
	void printPref(bintree *tree) 
	{
		if ((tree != nullptr) && (isExist)) {
			std::cout << tree->value << "\n";
			printPref(tree->left);
			printPref(tree->right);
		}
	}

	//Обход дерева в инфиксной форме.
	void printInf(bintree *tree) 
	{
		if ((tree != nullptr) && (isExist)) {
			printInf(tree->left);
			std::cout << tree->value << "\n";
			printInf(tree->right);
		}
	}

	//Обход дерева в постфиксной форме.
	void printPost(bintree *tree) 
	{
		if ((tree != nullptr) && (isExist)) {
			printPost(tree->left);
			printPost(tree->right);
			std::cout << tree->value << "\n";
		}
	}

	//Подсчёт узлов дерева.
	int countElem(bintree *tree) 
	{
		int count = 0;
		if ((tree != nullptr) && (isExist)) {
			count++;
			count += countElem(tree->left);
			count += countElem(tree->right);
		}
		return count;
	}

	//Подсчёт листьев дерева.
	int countLeaf(bintree *tree) 
	{
		int count = 0;
		if ((tree != nullptr) && (isExist)) {
			if ((tree->left == nullptr) && (tree->right == nullptr))
				count++;
			count += countLeaf(tree->left);
			count += countLeaf(tree->right);
		}
		return count;
	}

	//Подсчёт высоты дерева.
	int countHeight(bintree *tree) 
	{
		int left = 0, right = 0;
		if ((tree != nullptr) && (isExist)) {
			left = (tree->left != nullptr) ? countHeight(tree->left) : 0;
			right = (tree->right != nullptr) ? countHeight(tree->right) : 0;
			return ((left > right) ? left : right) + 1;
		}
		return 0;
	}

	bintree *rootTree()
	{
		return root;
	}

	bool exist()
	{
		return isExist;
	}
};

#endif /* TREE_H */