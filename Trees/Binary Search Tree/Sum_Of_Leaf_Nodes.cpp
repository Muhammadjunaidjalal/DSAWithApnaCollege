#include "BST.h"

//Helper function to calculate sum of leaf nodes
void BinarySearchTree::sumOfLeafNodesRecursive(Node* root, int & sum){

    if(!root) return;

    sumOfLeafNodesRecursive(root->left, sum);
    if(!root->left && !root->right){
        sum+= root->data;
    }
    sumOfLeafNodesRecursive(root->right, sum);

}

//public funtion to get sum 
int BinarySearchTree::sumOfLeafNodes(){
    int sum = 0; 

    sumOfLeafNodesRecursive(root, sum);

    return sum;
}

