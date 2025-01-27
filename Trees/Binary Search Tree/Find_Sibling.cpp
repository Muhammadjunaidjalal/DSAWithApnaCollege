#include "BST.h"

int BinarySearchTree::findSibling(int data) {
    if (!root || root->data == data) 
        return -1; // Tree is empty or the node is the root (no sibling)

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
            // Node found; check for sibling
            if (parent) {
                if (parent->left == child && parent->right)
                    return parent->right->data; // Return sibling on the right
                if (parent->right == child && parent->left)
                    return parent->left->data; // Return sibling on the left
            }
            return -1; // No sibling
        }
    }

    return -1; // Node not found
}
