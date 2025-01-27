#include "BST.h"

// Public search function
bool BinarySearchTree::search(int data) {
    // Call the recursive or iterative method (choose one)
    return searchRecursive(root, data);
    // Alternatively: return searchIterative(data);
}

// Recursive search helper function
bool BinarySearchTree::searchRecursive(Node* root, int data) {
    // Base Case: Node is null (data not found)
    if (!root) 
        return false;

    // Base Case: Data found
    if (data == root->data) 
        return true;

    // Recur for left or right subtree based on data comparison
    if (data < root->data)
        return searchRecursive(root->left, data);
    else
        return searchRecursive(root->right, data);
}

// Iterative search function
bool BinarySearchTree::searchIterative(int data) {
    Node* current = root;

    while (current) {
        if (data == current->data) 
            return true;
        else if (data < current->data) 
            current = current->left;
        else 
            current = current->right;
    }

    // Data not found
    return false;
}
