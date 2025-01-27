#include "BST.h"

void BinarySearchTree::printLeafNodesRecursive(Node* root){
    if(!root) return; // Base case: if the tree is empty or we've reached a null node

     // Recurse on the left subtree
    printLeafNodesRecursive(root->left); 
    // Check if the current node is a leaf node
    if(!root->left && !root->right){
        cout<<root->data<<" "; // Print the leaf node's data
    }
    // Recurse on the right subtree
    printLeafNodesRecursive(root->right);
}


void BinarySearchTree::leafNodes(){
    printLeafNodesRecursive(root);
}