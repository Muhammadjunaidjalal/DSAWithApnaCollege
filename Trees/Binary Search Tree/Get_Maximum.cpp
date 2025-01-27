#include "BST.h"

// Public function to get the maximum value in the BST
int BinarySearchTree::getMax() {
    return maximumRecursive(root); // Call the recursive helper
}

// Recursive helper function to find the maximum value
int BinarySearchTree::maximumRecursive(Node* root) {
    if (!root) 
        return -1; // Return -1 for empty tree (can be adjusted as needed)

    if (!root->right)
        return root->data; // Base case: rightmost node found

    return maximumRecursive(root->right); // Recur to the right subtree
}

// Iterative function to find the maximum value
int BinarySearchTree::maximumIterative() {
    if (!root) 
        return -1; // Return -1 for empty tree

    Node* temp = root; // Temporary pointer for traversal

    // Traverse to the rightmost node
    while (temp->right)
        temp = temp->right;

    return temp->data; // Return the data of the rightmost node
}
