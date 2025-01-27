#include "BST.h"

Node* BinarySearchTree::getMinimumNode(Node* root){
    while (root && root->left)
        root = root->left;
    return root;
}