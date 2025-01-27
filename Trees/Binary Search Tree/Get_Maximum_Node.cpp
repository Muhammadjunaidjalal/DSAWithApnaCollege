#include "BST.h"

Node* BinarySearchTree::getMaximumNode(Node* root){
    while (root && root->right)
        root = root->right;
    return root;
}