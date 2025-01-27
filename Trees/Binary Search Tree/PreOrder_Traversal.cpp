#include "BST.h"

// Pre-Order Traversal caller function
void BinarySearchTree::preOrderTraversal() {
    if (!root) {
        cout << "Tree is empty."<<endl;
        return;
    }
    preOrderRecursive(root);
}

void BinarySearchTree::preOrderRecursive(Node* root) {
    // Base Case: If root is null, return
    if (!root) return;

    // Functionality based on NLR (Node -> Left -> Right)
    cout << root->data << " ";
    preOrderRecursive(root->left);
    preOrderRecursive(root->right);
}


// Preorder Traversal (Root, Left, Right)
void BinarySearchTree::preOrderIterative() {
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
                cout << current->data << " ";
                pred->right = current;
                current = current->left;
            } else {
                pred->right = nullptr;
                current = current->right;
            }
        }
    }
    cout << endl;
}