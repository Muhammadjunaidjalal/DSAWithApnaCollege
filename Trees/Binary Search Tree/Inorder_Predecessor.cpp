#include "BST.h"

// Public function to find the in-order predecessor
int BinarySearchTree::inOrderPredecessor(int data) {
    Node* predecessor = inOrderPredecessorRecursive(root, data);
    if (predecessor) {
        return predecessor->data; 
    } else {
        cout << "NO PREDECESSOR!" << endl;
        return -1;
    }
}

// Recursive function to find the in-order predecessor
Node* BinarySearchTree::inOrderPredecessorRecursive(Node* root, int key, Node* predecessor = nullptr) {
    if (!root) return predecessor;

    if (key > root->data) {
        // Potential predecessor, move to the right subtree
        predecessor = root;
        return inOrderPredecessorRecursive(root->right, key, predecessor);
    } else {
        // Key is smaller or equal, move to the left subtree
        return inOrderPredecessorRecursive(root->left, key, predecessor);
    }
}
