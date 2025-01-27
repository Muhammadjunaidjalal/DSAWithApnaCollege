#include "BST.h"

int BinarySearchTree::findParent(int data) {
    if (!root || root->data == data) 
        return -1; // Return -1 if tree is empty or the node is the root (no parent)

    Node* parent = nullptr; // To store the parent node
    Node* child = root;     // Start with the root

    while (child) {
        if (data < child->data) {
            parent = child;        // Update parent before moving left
            child = child->left;   // Move to the left child
        } else if (data > child->data) {
            parent = child;        // Update parent before moving right
            child = child->right;  // Move to the right child
        } else {
            // Node with the given data is found, return the parent's data
            return parent ? parent->data : -1;
        }
    }

    // If the loop ends, the node doesn't exist in the tree
    return -1;
}
