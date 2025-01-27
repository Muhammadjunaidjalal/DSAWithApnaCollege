#include "BST.h"
// In-Order Traversal caller function
void BinarySearchTree::inOrderTraversal() {
    if (!root) {
        cout << "Tree is empty."<<endl;
        return;
    }
    inOrderRecursive(root);

}
// Helper functions
void BinarySearchTree::inOrderRecursive(Node* root) {
    // Base Case: If root is null, return
    if (!root) return;

    // Functionality based on LNR (Left -> Node -> Right)
    inOrderRecursive(root->left);
    cout << root->data << " ";
    inOrderRecursive(root->right);
}

// Inorder Traversal (Left, Root, Right)
void BinarySearchTree::inOrderIterative() {
    Node* current = root;
    while (current) {
        if (!current->left) {
                cout << current->data << " ";
                current = current->right;
        } else {
            Node* pred = current->left;
            while (pred->right && pred->right != current)
                pred = pred->right;

                if (!pred->right) {
                    pred->right = current;
                    current = current->left;
                } else {
                    pred->right = nullptr;
                    cout << current->data << " ";
                    current = current->right;
                }
        }
    }
    cout << endl;
}