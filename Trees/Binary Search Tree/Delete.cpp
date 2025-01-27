#include "BST.h"

void BinarySearchTree::remove(int data){
    root = deleteRecursive(root, data);
}
Node* BinarySearchTree::deleteRecursive(Node* root, int data) {
    // Base case: if the root is null, return null
    if (!root) 
        return root;

    // Traverse the tree to find the node to delete
    if (data < root->data) {
        root->left = deleteRecursive(root->left, data);
    } else if (data > root->data) {
        root->right = deleteRecursive(root->right, data);
    } else {
        // Node to be deleted found

        // Case 1: Node has no left child
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 2: Node has no right child
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node has two children
        // Find the in-order successor (minimum node in the right subtree)
        Node* temp = getMinimumNode(root->right);

        // Copy the successor's data to the current node
        root->data = temp->data;

        // Delete the in-order successor
        root->right = deleteRecursive(root->right, temp->data);
    }

    return root; // Return the updated root
}


// Iterative Delete Function
void BinarySearchTree::deleteIterative(int data) {
        Node* current = root;
        Node* parent = nullptr;

        // Find the node to delete and its parent
        while (current && current->data != data) {
            parent = current;
            if (data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (!current)
            return; // Key not found

        // Case 1: Node with no children
        if (!current->left && !current->right) {
            if (current == root)
                root = nullptr;
            else if (parent->left == current)
                parent->left = nullptr;
            else
                parent->right = nullptr;
            delete current;
        }
        // Case 2: Node with one child
        else if (!current->left || !current->right) {
            Node* child = (current->left) ? current->left : current->right;

            if (current == root)
                root = child;
            else if (parent->left == current)
                parent->left = child;
            else
                parent->right = child;
            delete current;
        }
        // Case 3: Node with two children
        else {
            Node* successor = current->right;
            Node* successorParent = current;

            // Find the in-order successor
            while (successor->left) {
                successorParent = successor;
                successor = successor->left;
            }

            current->data = successor->data; // Replace current's key with successor's key

            // Remove the successor
            if (successorParent->left == successor)
                successorParent->left = successor->right;
            else
                successorParent->right = successor->right;

            delete successor;
        }
    }

