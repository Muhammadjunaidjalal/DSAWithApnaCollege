#include "BST.h"

// Public function to call other insert functions
void BinarySearchTree::insert(int data) {
    root = insertRecursive(root, data);
    // Alternatively, you can call insertIterative(data) instead.
}

// Implementation of the recursive helper function
Node* BinarySearchTree::insertRecursive(Node* root, int data) {
    // Create a new node and return it (Base Case)
    if (!root) 
        return new Node(data);

    // Decide whether data should be inserted at left or right subtree
    if (data < root->data)
        root->left = insertRecursive(root->left, data);
    else if (data > root->data)
        root->right = insertRecursive(root->right, data);

    // Return root to maintain the links in the recursion
    return root;
}

// Iterative insertion function
void BinarySearchTree::insertIterative(int data) {
    // Create a new node to insert
    Node* newNode = new Node(data);

    // If the tree is empty, make the new node the root
    if (!root) {
        root = newNode;
        return;
    }

    // Helper nodes to locate the position for insertion
    Node* current = root;
    Node* previous = nullptr;

    while (current) {
        previous = current;

        // Update current according to the required subtree
        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else
            return; // Key already exists, no insertion needed
    }

    // Connect the new node to its supposed parent
    if (data < previous->data)
        previous->left = newNode;
    else
        previous->right = newNode;
}
