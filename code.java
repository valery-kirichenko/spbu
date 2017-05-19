package Tree;

public class Tree {
    class Leaf {
        private int data;
        private Leaf left;
        private Leaf right;
        Leaf() {
            this.data = 0;
            this.left = null;
            this.right = null;
        }
    }

    private int numOfLeaves;
    private int tempData;
    private Leaf tempLeaf;
    private Leaf root;

    Tree() {
        this.tempLeaf = new Leaf();
        this.root = new Leaf();
        this.tempData = 0;
        this.numOfLeaves = 0;
    }

    public void addleaf(int x) {
        if (this.numOfLeaves == 0) {
            this.root.data = x;
            this.root.left = null;
            this.root.right = null;
            this.numOfLeaves = 1;
            this.tempLeaf = root;
            this.tempData = x;
        }
        else {
            recursionFunction(x);
        }
    }

    private void recursionFunction(int x) {
        if (x >= this.tempData) {
            if (this.tempLeaf.left == null) {
                Leaf newLeaf = new Leaf();
                newLeaf.data = x;
                newLeaf.left = null;
                newLeaf.right = null;
                this.tempLeaf.left = newLeaf;
                this.tempLeaf = this.root;
            }
            if (this.tempLeaf.left != null) {
                this.tempLeaf = tempLeaf.left;
                recursionFunction(x);
            }
        }
        if (x < this.tempData) {
            if (this.tempLeaf.right == null) {
                Leaf newLeaf = new Leaf();
                newLeaf.data = x;
                newLeaf.left = null;
                newLeaf.right = null;
                this.tempLeaf.right = newLeaf;
                this.tempLeaf = this.root;
            }
            if (this.tempLeaf.right != null) {
                this.tempLeaf = this.tempLeaf.right;
                recursionFunction(x);
            }
        }
    }

    public static void main(String[] args) {
        Tree t = new Tree();
        t.addleaf(1);
    }
}
