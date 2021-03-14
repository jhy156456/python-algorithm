

public class test {

    public static void main(String[] args) {
        Node root = null;
        root = insert(root, 50);
        insert(root, 30);
        insert(root, 20);
        insert(root, 40);
        insert(root, 70);
        insert(root, 60);
        insert(root, 80);

        // print iNoder traversal of the BST
        inorder(root);
    }

    static class Node {
        int key;
        Node left, right, parent;
    }

    // A utility function to create a new BST Node
    static Node newNode(int item) {
        Node temp = new Node();
        temp.key = item;
        temp.left = null;
        temp.right = null;
        temp.parent = null;
        return temp;
    }

    // A utility function to do inorder traversal of BST
    static void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.print("Node : " + root.key + " , ");
            if (root.parent == null)
                System.out.println("Parent : NULL");
            else
                System.out.println("Parent : " + root.parent.key);
            inorder(root.right);
        }
    }

    /* A utility function to insert a new Node with
    given key in BST */
    static Node insert(Node node, int key) {
        /* If the tree is empty, return a new Node */
        if (node == null) return newNode(key);

        /* Otherwise, recur down the tree */
        if (key < node.key) {
            Node lchild = insert(node.left, key);
            node.left = lchild;

            // Set parent of root of left subtree
            lchild.parent = node;
        } else if (key > node.key) {
            Node rchild = insert(node.right, key);
            node.right = rchild;

            // Set parent of root of right subtree
            rchild.parent = node;
        }

        /* return the (unchanged) Node pointer */
        return node;
    }

}
