#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "stack.h"
#include "queue.h"
#include "search.h"
#include "sort.h"
#include "tree.h"
#include "rbtree.h"

int main()
{
	///Тесты
	stackV<int> s1;
	bool t = s1.empty();
	s1.print();
	unsigned int n = s1.getSize();
	s1.push(1);
	s1.push(2);
	t = s1.empty();
	n = s1.getSize();
	s1.print();
	s1.pop();
	s1.pop();
	s1.print();
	s1.push(3);
	s1.clear();
	t = s1.empty();
	n = s1.getSize();
	std::cout << "\nNext block...\n";

	queueV<int> s2;
	bool t1 = s2.empty();
	s2.print();
	unsigned int n1 = s2.getSize();
	s2.push(1);
	s2.push(2);
	t1 = s2.empty();
	n1 = s2.getSize();
	s2.print();
	s2.pop();
	s2.pop();
	s2.print();
	s2.push(3);
	s2.clear();
	t1 = s2.empty();
	n1 = s2.getSize();
	std::cout << "\nNext block...\n";

	const unsigned int size = 10;
	int *arr = new int[size], no;
	for (unsigned int i = 0; i < size; i++)
		arr[i] = i;
	for (unsigned int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	putchar('\n');
	std::cin >> no;
	std::cout << linSearch(arr, no, size) << std::endl;
	std::cout << binSearch(arr, no, size);
	std::cout << "\nNext block...\n";
	quickSort(0, size - 1, arr, 0);
	for (unsigned int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	bubbleSort(arr, size, 1);
	for (unsigned int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	insertionSort(arr, size, 0);
	for (unsigned int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	choicesSort(arr, size, 1);
	for (unsigned int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << "\nNext block...\n";

	treeV<int> tree;
	tree.root = tree.addNode(13, tree.root);
	tree.root = tree.addNode(8, tree.root);
	tree.root = tree.addNode(17, tree.root);
	tree.root = tree.deleteNode(17, tree.root);
	tree.root = tree.addNode(1, tree.root);
	tree.root = tree.addNode(15, tree.root);
	tree.root = tree.addNode(11, tree.root);
	tree.root = tree.addNode(25, tree.root);
	tree.root = tree.addNode(6, tree.root);
	tree.root = tree.addNode(22, tree.root);
	tree.root = tree.addNode(27, tree.root);
	tree.root = tree.addNode(28, tree.root);
	tree.root = tree.addNode(29, tree.root);
	tree.root = tree.addNode(30, tree.root);
	tree.root = tree.addNode(31, tree.root);
	tree.root = tree.addNode(32, tree.root);
	std::cout << tree.countElem(tree.root) << " " << tree.countHeight(tree.root) << " " << tree.countLeaf(tree.root) << "\n";
	tree.print_Tree(tree.root, 0);
	tree.deleteSubtree(tree.root);
	std::cout << "\nNext block...\n";

	rbtreeV<int> rbtree;
	rbtree.addNode(13);
	rbtree.addNode(8);
	rbtree.addNode(17);
	rbtree.deleteNode(17);
	rbtree.addNode(1);
	rbtree.addNode(15);
	rbtree.addNode(11);
	rbtree.addNode(25);
	rbtree.addNode(6);
	rbtree.addNode(22);
	rbtree.addNode(27);
	rbtree.addNode(28);
	rbtree.addNode(29);
	rbtree.addNode(30);
	rbtree.addNode(31);
	rbtree.addNode(32);
	std::cout << rbtree.countElem(rbtree.rootTree()) << " " << rbtree.countHeight(rbtree.rootTree()) << " " << rbtree.countLeaf(rbtree.rootTree()) << "\n";
	rbtree.print_Tree(rbtree.rootTree(), 0);
	system("pause");
	return 0;
}