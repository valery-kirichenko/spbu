package Tree;

public class Tree {
    class Leaf {
        private int data;
        private Leaf left;
        private Leaf right;
        Leaf() {
            data = 0;
            left = null;
            right = null;
        }
    }
    private int numOfLeaves;
    private int tempData;
    private Leaf tempLeaf;
    private Leaf root;
    Tree() {
        tempLeaf = null;
        tempData = 0;
        numOfLeaves = 0;
    }
    public void addleaf(int x) {
        if (numOfLeaves == 0) {
            root.data = x;
            root.left = null;
            root.right = null;
            numOfLeaves = 1;
            tempLeaf = root;
            tempData = x;
        }
        else {
            recursionFunction(x);
        }
    }
    private void recursionFunction(int x) {
        if (x >= tempData) {
            if (tempLeaf.left == null) {
                Leaf newLeaf = new Leaf();
                newLeaf.data = x;
                newLeaf.left = null;
                newLeaf.right = null;
                tempLeaf.left = newLeaf;
                tempLeaf = root;
            }
            if (tempLeaf.left != null) {
                tempLeaf = tempLeaf.left;
                recursionFunction(x);
            }
        }
        if (x < tempData) {
            if (tempLeaf.right == null) {
                Leaf newLeaf = new Leaf();
                newLeaf.data = x;
                newLeaf.left = null;
                newLeaf.right = null;
                tempLeaf.right = newLeaf;
                tempLeaf = root;
            }
            if (tempLeaf.right != null) {
                tempLeaf = tempLeaf.right;
                recursionFunction(x);
            }
        }
    }

    public static void main(String[] args) {
        Tree t = new Tree();
        t.addleaf(1);
    }
}
