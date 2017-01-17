#pragma once
#define COLOR_RED 0
#define COLOR_BLACK 1

template <typename RBTR>
class rbtreeV {
	private:
		bool isExist;
		struct tree {
			RBTR value;
			int color;
			tree *parent;
			tree *left;
			tree *right;
			
		};
		tree emptyNode = { NULL, COLOR_BLACK, nullptr, nullptr, nullptr };
		tree *nullNode = &emptyNode;
		tree *root;
		
			void rotateLeft(tree *node)
			 {
			tree *right = node->right;
				node->right = right->left;
			if (right->left != nullNode)
				right->left->parent = node;
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
			void rotateRight(tree *node)
			 {
			tree *left = node->left;
				node->left = left->right;
			if (left->right != nullNode)
				left->right->parent = node;
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

					void fixupAdd(tree *node)
					{
					tree *uncle;
						while ((node != root) && (node->parent->color == COLOR_RED)) {
						if (node->parent == node->parent->parent->left) {
								uncle = node->parent->parent->right;
							if (uncle->color == COLOR_RED) {
								
								node->parent->color = COLOR_BLACK;
								uncle->color = COLOR_BLACK;
								node->parent->parent->color = COLOR_RED;
								node = node->parent->parent;
								
							}
							else {
									if (node == node->parent->right) {
									node = node->parent;
									rotateLeft(node);
									
								}
								
									node->parent->color = COLOR_BLACK;
								node->parent->parent->color = COLOR_RED;
								rotateRight(node->parent->parent);
								
							}
							
						}
						else {
							uncle = node->parent->parent->left;
							if (uncle->color == COLOR_RED) {							
									node->parent->color = COLOR_BLACK;
								uncle->color = COLOR_BLACK;
								node->parent->parent->color = COLOR_RED;
								node = node->parent->parent;
								
							}
							else {
								
									if (node == node->parent->left) {
									node = node->parent;
									rotateRight(node);
									
								}
								node->parent->color = COLOR_BLACK;
								node->parent->parent->color = COLOR_RED;
								rotateLeft(node->parent->parent);
								
							}
							
						}
						
					}
					root->color = COLOR_BLACK;
					}
				
					
					void addNode(RBTR value)
					{
					tree *node = nullNode;
					tree *parent = nullNode;
					isExist = true;
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
					node->color = COLOR_RED;
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
									
					void deleteFixup(tree *node) {
					while ((node != root) && (node->color == COLOR_BLACK)) {
						if (node == node->parent->left) {
							tree *w = node->parent->right;
							if (w->color == COLOR_RED) {
								w->color = COLOR_BLACK;
								node->parent->color = COLOR_RED;
								rotateLeft(node->parent);
								w = node->parent->right;
								
							}
							if ((w->left->color == COLOR_BLACK) && (w->right->color == COLOR_BLACK)) {
								w->color = COLOR_RED;
								node = node->parent;
								
							}
							else {
								if (w->right->color == COLOR_BLACK) {
									w->left->color = COLOR_BLACK;
									w->color = COLOR_RED;
									rotateRight(w);
									w = node->parent->right;
									
								}
								w->color = node->parent->color;
								node->parent->color = COLOR_BLACK;
								w->right->color = COLOR_BLACK;
								rotateLeft(node->parent);
								node = root;
								
							}
							
						}
						else {
							tree *w = node->parent->left;
							if (w->color == COLOR_RED) {
								w->color = COLOR_BLACK;
								node->parent->color = COLOR_RED;
								rotateRight(node->parent);
								w = node->parent->left;
								
							}
							if ((w->right->color == COLOR_BLACK) && (w->left->color == COLOR_BLACK)) {
								w->color = COLOR_RED;
								node = node->parent;
								
							}
							else {
								if (w->left->color == COLOR_BLACK) {
									w->right->color = COLOR_BLACK;
									w->color = COLOR_RED;
									rotateLeft(w);
									w = node->parent->left;
									
								}
								w->color = node->parent->color;
								node->parent->color = COLOR_BLACK;
								w->left->color = COLOR_BLACK;
								rotateRight(node->parent);
								node = root;
								
							}
							
						}
						
					}
					node->color = COLOR_BLACK;
					
				}
				
					
					void deleteNode(RBTR value) {
					tree *x, *y, *z;
					
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
						y = z;
						
					}
					else {
						
							y = z->right;
						while (y->left != nullNode)
							 y = y->left;
						
						}
							
						if (y->left != nullNode)
							 x = y->left;
						else
							 x = y->right;
					
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
					if (y->color == COLOR_BLACK)
						 deleteFixup(x);
					delete y;
					
				}
				
				
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
									
					void printPref(tree *node)
					{
					if ((node != nullNode) && (isExist)) {
						std::cout << node->value << "\n";
						printPref(node->left);
						printPref(node->right);
						
					}
					}
				
					void printInf(tree *node)
					{
					if ((node != nullNode) && (isExist)) {
						printInf(node->left);
						std::cout << node->value << "\n";
						printInf(node->right);
					
					}
					}
									
					void printPost(tree *node)
					 {
					if ((node != nullNode) && (isExist)) {
						printPost(node->left);
						printPost(node->right);
						std::cout << node->value << "\n";
						
					}
					}
				
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