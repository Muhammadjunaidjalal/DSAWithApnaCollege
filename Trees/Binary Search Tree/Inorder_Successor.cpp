#include "BST.h"

// Public function to find the in-order successor
int BinarySearchTree::inOrderSuccessor(int data) {
    Node* successor = inOrderSuccessorRecursive(root, data);
    if (successor) {
        return successor->data; 
    } else {
        cout << "NO SUCCESSOR!" << endl;
        return -1;
    }
}


// Recursive function to find the in-order successor
Node* BinarySearchTree::inOrderSuccessorRecursive(Node* root, int key, Node* successor = nullptr) {
    if (!root) return successor;

    if (key < root->data) {
        // Potential successor, move to the left subtree
        successor = root;
        return inOrderSuccessorRecursive(root->left, key, successor);
    } else {
        // Key is greater or equal, move to the right subtree
        return inOrderSuccessorRecursive(root->right, key, successor);
    }
}

