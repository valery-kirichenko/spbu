#include <iostream>

using namespace std;

class leaf
{
public:
    int val;
    leaf *left;
    leaf *right;
    leaf *prev;
    int color;
};

class tree
{
public:
    leaf *root;

    tree()
    {
        root = NULL;
    }

    tree(int a)
    {
        root = new leaf;
        root->val = a;
        root->left = NULL;
        root->right = NULL;
        root->prev = NULL;
    }

    void clear()
    {
        root = NULL;
    }

    bool isEmpty()
    {
        if (root == NULL) return true;
        return false;
    }

    void add(int a)
    {
        if (isEmpty())
        {
            root = new leaf;
            root->val = a;
            root->left = NULL;
            root->right = NULL;
            root->prev = NULL;
        }
        else
        {
        leaf *p = root;
        bool b = true;
        while(b)
        {
            if (a >= p->val)
            {
                if (p->right != NULL) p = p->right;
                else
                {
                    leaf *pr = new leaf;
                    pr->left = NULL;
                    pr->right = NULL;
                    pr->val = a;
                    pr->prev = p;
                    p->right = pr;
                    b = false;
                }
            }
            else
            {
                if (p->left != NULL) p = p->left;
                else
                {
                    leaf *pl = new leaf;
                    pl->left = NULL;
                    pl->right = NULL;
                    pl->val = a;
                    pl->prev = p;
                    p->left = pl;
                    b = false;
                }
            }
        }
        }
    }

    void print(int k, leaf *p,int l)
    {
        if (p != NULL)
        {
            if (p->right) print(k+1,p->right,l+2);
            cout << endl;
            for (int i = 0; i<k+l; i++)
                cout << ' ';
            cout << p->val;
            for (int i = 0; i<l; i++)
                cout << ' ';
            if (p->left) print(k+1,p->left,l+2);
        }
        else cout << "Pustoe derevo\n";
    }

    int high(int m,leaf *p)
    {
        if (p == NULL) return -1;
        if (p->left == NULL && p->right == NULL) {return m;}
        int r = 0,l = 0;
        if (p->left) {l = high(m+1,p->left); }
        if (p->right) {r = high(m+1,p->right); }
        return max(r,l);
    }

    int countAns(leaf *p)
    {
        int ans = 0;
        if (p->left == NULL && p->right == NULL) return 1;
        if (p->left && p->right)
            if (high(0,p->left) == high(0,p->right)) ans++;
        if (p->left) ans += countAns(p->left);
        if (p->right) ans += countAns(p->right);
        return ans;
    }

    void create()
    {
        int n;
        if (root != NULL)
        {
            cout << "Derevo uzhe est'. Zamenit'?\n1.Da\n0.Net\n";
            int k;
            cin >> k;
            if (k == 1)
            {
                deleteAllTree();
                cout << "\nVvedite kolichestvo elementov v dereve: ";
                cin >> n;
                cout << "Vvedite binarnoye derevo:\n";
                int a;
                for (int i = 0; i<n; i++)
                {
                    cin >> a;
                    add(a);
                }
            }
        }
        else
        {
            cout << "Vvedite kolichestvo elementov v dereve: ";
            cin >> n;
            cout << "Vvedite binarnoye derevo:\n";
            int a;
            for (int i = 0; i<n; i++)
            {
                cin >> a;
                add(a);
            }
        }
    }

    bool search(leaf *l,int a)
    {
        if (l == NULL) return false;
        if (l->val == a) return true;
        if (l->left)
            if (search(l->left,a)) return true;
        if (l->right)
            if (search(l->right,a)) return true;
        return false;
    }

    int sum(leaf *l)
    {
        if (l ==NULL) return 0;
        int k = 1;
        if (l->left) k+=sum(l->left);
        if (l->right) k+=sum(l->right);
        return k;
    }

    int sumLeaves(leaf *l)
    {
        if (l == NULL) return 0;
        int k = 0;
        if (l->left == NULL && l->right == NULL) return 1;
        if (l->left) k+=sumLeaves(l->left);
        if (l->right) k+=sumLeaves(l->right);
        return k;
    }

    void countDegree(leaf *l, int a)
    {
        if (l)
        {
            int n = 0;
            if (a == l->val)
            {
                int k = 0;
                if (l->left) k++;
                if (l->right) k++;
                cout << k << endl;
                n++;
            }
            if (l->left) countDegree(l->left,a);
            if (l->right) countDegree(l->right,a);
            if (n == 0) cout << "Net takogo elementa\n";
        }
        else cout << "Pustoye derevo!\n";
    }

    void countLevel(leaf *l, int a, int k)
    {
        if (l)
        {
            int n;
            if (a == l->val)
                { cout << k << endl; n++; }
            if (l->left) countLevel(l->left,a,k+1);
            if (l->right) countLevel(l->right,a,k+1);
            if (n == 0) cout << "Net takogo elementa\n";
        }
        else cout << "Pustoye derevo!\n";
    }

    void deleteTreePart(leaf *l,int a)
    {
        if (l)
        {
            if (l->val == a) root = NULL;
            if (l->left)
                if (l->left->val == a) l->left = NULL;
                else deleteTreePart(l->left,a);
            if (l->right)
                if (l->right->val == a) l->right = NULL;
                else deleteTreePart(l->right,a);
        }
    }

    void deleteAllTree()
    {
        if (root) deleteTreePart(root,root->val);
    }

    void deleteSmart(leaf *l, int a)
    {
        if (l)
        if (l->val == a)
        {
            if (l->left == NULL && l->right == NULL) l = NULL;
            else if (l->left == NULL) {leaf *p = l->right; l->val = p->val; l->left = p->left; l->right = p->right;}
            else if (l->right == NULL) {leaf *p = l->left; l->val = p->val; l->left = p->left; l->right = p->right;}
            else
            {
                leaf *p = l;
                p = p->right;
                while (p->left) p = p->left;
                if (p->left == NULL && p->right == NULL)
                {
                    l->val = p->val;
                    p->prev->left = NULL;
                    p = NULL;
                }
                else
                {
                    l->val = p->val;
                    deleteSmart(p,p->val);
                }
            }
        }
        if (l!=NULL)
        {
            if (l->left) deleteSmart(l->left,a);
            if (l->right) deleteSmart(l->right,a);
        }
        else
        {
            root = NULL;
        }
    }
};

class rbtreeV {
public:
	bool isExist;
	leaf emptyNode = { 0, NULL, NULL, NULL, 1 };
	leaf *nullNode = &emptyNode;
	leaf *root;
	void rotateLeft(leaf *node)
	{
		leaf *right = node->right;
		node->right = right->left;
		if (right->left != nullNode)
			right->left->prev = node;
		if (right != nullNode)
			right->prev = node->prev;
		if (node->prev != nullNode) {
			if (node == node->prev->left)
				node->prev->left = right;
			else
				node->prev->right = right;
		}
		else {
			root = right;
		}
		right->left = node;
		if (node != nullNode)
			node->prev = right;
	}

	void rotateRight(leaf *node)
	{
		leaf *left = node->left;
		node->left = left->right;
		if (left->right != nullNode)
			left->right->prev = node;
		if (left != nullNode)
			left->prev = node->prev;
		if (node->prev != nullNode) {
			if (node == node->prev->right)
				node->prev->right = left;
			else
				node->prev->left = left;
		}
		else {
			root = left;
		}
		left->right = node;
		if (node != nullNode)
			node->prev = left;
	}

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

	void fixupAdd(leaf *node)
	{
		leaf *uncle;
		while ((node != root) && (node->prev->color == 0)) {
			if (node->prev == node->prev->prev->left) {
				uncle = node->prev->prev->right;
				if (uncle->color == 0) {
					node->prev->color = 1;
					uncle->color = 1;
					node->prev->prev->color = 0;
					node = node->prev->prev;
				}
				else {
					if (node == node->prev->right) {
						node = node->prev;
						rotateLeft(node);
					}
					node->prev->color = 1;
					node->prev->prev->color = 0;
					rotateRight(node->prev->prev);
				}
			}
			else {
				uncle = node->prev->prev->left;
				if (uncle->color == 0) {
					node->prev->color = 1;
					uncle->color = 1;
					node->prev->prev->color = 0;
					node = node->prev->prev;
				}
				else {
					if (node == node->prev->left) {
						node = node->prev;
						rotateRight(node);
					}
					node->prev->color = 1;
					node->prev->prev->color = 0;
					rotateLeft(node->prev->prev);
				}
			}
		}
		root->color = 1;
	}

	void addNode(int value)
	{
		leaf *node = nullNode;
		leaf *parent = nullNode;
		isExist = true;
		for (node = root; (node != nullNode) && (node != nullptr);) {
			parent = node;
			if (value < node->val)
				node = node->left;
			else if (value > node->val)
				node = node->right;
			else
				return;
		}
		node = new leaf;
		node->val = value;
		node->color = 0;
		node->prev = parent;
		node->left = nullNode;
		node->right = nullNode;

		if (parent != nullNode) {
			if (value < parent->val)
				parent->left = node;
			else
				parent->right = node;
		}
		else {
			root = node;
		}

		fixupAdd(node);
	}

	void deleteSubtree(leaf *node)
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

	void deleteFixup(leaf *node) {
		while ((node != root) && (node->color == 1)) {
			if (node == node->prev->left) {
				leaf *w = node->prev->right;
				if (w->color == 1) {
					w->color = 1;
					node->prev->color = 0;
					rotateLeft(node->prev);
					w = node->prev->right;
				}
				if ((w->left->color == 1) && (w->right->color == 1)) {
					w->color = 0;
					node = node->prev;
				}
				else {
					if (w->right->color == 1) {
						w->left->color = 1;
						w->color = 0;
						rotateRight(w);
						w = node->prev->right;
					}
					w->color = node->prev->color;
					node->prev->color = 1;
					w->right->color = 1;
					rotateLeft(node->prev);
					node = root;
				}
			}
			else {
				leaf *w = node->prev->left;
				if (w->color == 0) {
					w->color = 1;
					node->prev->color = 0;
					rotateRight(node->prev);
					w = node->prev->left;
				}
				if ((w->right->color == 1) && (w->left->color == 1)) {
					w->color = 0;
					node = node->prev;
				}
				else {
					if (w->left->color == 1) {
						w->right->color = 1;
						w->color = 0;
						rotateLeft(w);
						w = node->prev->left;
					}
					w->color = node->prev->color;
					node->prev->color = 1;
					w->left->color = 1;
					rotateRight(node->prev);
					node = root;
				}
			}
		}
		node->color = 1;
	}

	void deleteNode(int value) {
		leaf *x, *y, *z;
		z = root;
		while (z != nullNode) {
			if (value == z->val)
				break;
			else
				z = (value < z->val) ? z->left : z->right;
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
		x->prev = y->prev;
		if (y->prev)
			if (y == y->prev->left)
				y->prev->left = x;
			else
				y->prev->right = x;
		else
			root = x;
		if (y != z)
			z->val = y->val;
		if (y->color == 1)
			deleteFixup(x);
		delete y;
	}

	void print_Tree(leaf *node, int level)
	{
		if ((node != nullNode) && (isExist)) {
			print_Tree(node->left, level + 1);
			for (int i = 0; i < level; i++)
				cout << "   ";
			if (node != nullNode)
				cout << node->val;
			cout << endl;
			print_Tree(node->right, level + 1);
		}
	}

	void printPref(leaf *node)
	{
		if ((node != nullNode) && (isExist)) {
			cout << node->val << "\n";
			printPref(node->left);
			printPref(node->right);
		}
	}

	void printInf(leaf *node)
	{
		if ((node != nullNode) && (isExist)) {
			printInf(node->left);
			cout << node->val << "\n";
			printInf(node->right);
		}
	}

	void printPost(leaf *node)
	{
		if ((node != nullNode) && (isExist)) {
			printPost(node->left);
			printPost(node->right);
			cout << node->val << "\n";
		}
	}

	int countElem(leaf *node)
	{
		int count = 0;
		if ((node != nullNode) && (isExist)) {
			count++;
			count += countElem(node->left);
			count += countElem(node->right);
		}
		return count;
	}

	int countLeaf(leaf *node)
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

	int countHeight(leaf *node)
	{
		int left = 0, right = 0;
		if ((node != nullNode) && (isExist)) {
			left = (node->left != nullNode) ? countHeight(node->left) : 0;
			right = (node->right != nullNode) ? countHeight(node->right) : 0;
			return ((left > right) ? left : right) + 1;
		}
		return 0;
	}

	leaf *rootTree()
	{
		return root;
	}

	bool exist()
	{
		return isExist;
	}
};

template <typename T>
int binSearch(T k,T a[],int l,int r)
{
    int m;
    while(l<r)
    {
        m = (l+r)/2;
        if (k>a[m-1]) l = m+1;
        else r = m;
    }
    return l;
}

template <typename T>
int lineSearch(T k,T a[],int n)
{
    int i = 0;
    bool b = true;
    while(b && i<n)
    {
        if (a[i] == k) b = false;
        i++;
    }
    if (!b) return i;
    else return -1;
}

template <typename T>
void sortPuzirkom(T a[],int n)
{
    int f;
    for (int i = 0; i<n; i++)
    {
        f = 0;
        for (int j = 0; j<n-i; j++)
            if (a[j]>a[j+1]) { swap(a[j],a[j+1]); f++; }
        if (f == 0) break;
    }
}

template <typename T>
void sortVstavkami(T a[],int n)
{
    int i,j,k;
    T val,val1;
    for (i = 1; i<n; i++)
    {
        if (a[i]<a[i-1])
        {
            k = binSearch(a[i],a,1,i);
            val = a[k-1];
            a[k-1] = a[i];
            for (j = k; j<=i; j++)
            {
                val1 = a[j];
                a[j] = val;
                val = val1;
            }
        }
    }
}

template <typename T>
void sortViborom(T a[],int n)
{
    T m;
    int i,j;
    for (i = 0; i<n; i++)
    {
        m = i;
        for (j = i; j<n; j++)
        {
            if (a[j]<a[m]) m = j;
        }
        swap(a[i],a[m]);
    }
}

template <typename T>
void QuickSort(T a[],int l,int n)
{
    int i = l,j = n;
    T p = a[(n+l)/2];
    do
    {
        while(a[i] < p) i++;
        while(a[j] > p) j--;
        if (i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    } while(i<=j);
    if (j>l) QuickSort(a,l,j);
    if (n>i) QuickSort(a,j+1,n);
}

int main()
{
    return 0;
}
