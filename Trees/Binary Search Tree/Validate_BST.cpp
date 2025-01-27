#include "BST.h"

bool validateBST(Node* root, int min, int max){

    //base case 
    if(!root) return true;

    if(root->data > min && root->data < max){
        bool left = validateBST(root->left, min, root->data);
        bool right = validateBST(root->right, root->data, max);
    }else 
        return false;
}