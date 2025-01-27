#include "BST.h"

int BinarySearchTree::max(int a, int b){
    return (a>b)?a:b;
}

int BinarySearchTree::heightRecursive(Node* root){
    if(!root) return 0; 

    return max(heightRecursive(root->left), heightRecursive(root->right))+1;
}

int BinarySearchTree::getHeight(){
    return heightRecursive(root);
}