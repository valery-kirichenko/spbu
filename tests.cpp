#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "srch.h"
#include "sort.h"
#include "tree.h"
#include "redblacktree.h"

using namespace std;

int main()
{
	
	const int size = 10;
	int *arr = new int[size], x;
	for (int i = 0; i < size; i++)
		arr[i] = i;
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	putchar('\n');
	cin >> x;
	cout << linesrch(arr, x, size) << endl;
	cout << binarsrch(arr, x, size);
	cout << "\n\n";

	qcksort(arr, size, -1);
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;

	bsort(arr, size, 1);
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;

	inssort(arr, size, -1);
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;

	selsort(arr, size, 1);
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n\n";

	treeV<int> tree;
	tree.root = tree.addNode(12, tree.root);
	tree.root = tree.addNode(6, tree.root);
	tree.root = tree.addNode(17, tree.root);
	tree.root = tree.deleteNode(12, tree.root);
	tree.root = tree.addNode(5, tree.root);
	tree.root = tree.addNode(5, tree.root);
	tree.root = tree.addNode(1, tree.root);
	tree.root = tree.addNode(20,tree.root);
	cout << tree.countElem(tree.root) << " " << tree.countHeight(tree.root) << " " << tree.countLeaf(tree.root) << "\n";
	tree.print_Tree(tree.root, 0);
	tree.deleteSubtree(tree.root);
	cout << "\n\n";

	rbtreeV<int> rbtree;
	rbtree.addNode(24);
	rbtree.addNode(6);
	rbtree.addNode(1);
	rbtree.deleteNode(6);
	rbtree.addNode(1);
	rbtree.addNode(3);
	rbtree.addNode(5);
	rbtree.addNode(20);
	cout << rbtree.countElem(rbtree.rootTree()) << " " << rbtree.countHeight(rbtree.rootTree()) << " " << rbtree.countLeaf(rbtree.rootTree()) << "\n";
	rbtree.print_Tree(rbtree.rootTree(), 0);
	system("pause");
	return 0;
} 
