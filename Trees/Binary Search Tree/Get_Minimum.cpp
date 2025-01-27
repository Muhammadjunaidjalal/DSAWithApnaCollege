#include "BST.h"

// Public function to get the minimum value in the BST
int BinarySearchTree::getMin() {
    return minimumRecursive(root); // Call the recursive helper
}

// Recursive helper function to find the minimum value
int BinarySearchTree::minimumRecursive(Node* root) {
    if (!root) 
        return -1; // Return -1 for empty tree (can be adjusted as needed)

    if (!root->left)
        return root->data; // Base case: leftmost node found

    return minimumRecursive(root->left); // Recur to the left subtree
}

// Iterative function to find the minimum value
int BinarySearchTree::minimumIterative() {
    if (!root) 
        return -1; // Return -1 for empty tree

    Node* temp = root; // Temporary pointer for traversal

    // Traverse to the leftmost node
    while (temp->left)
        temp = temp->left;

    return temp->data; // Return the data of the leftmost node
}