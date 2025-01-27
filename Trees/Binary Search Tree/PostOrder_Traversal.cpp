#include "BST.h"

// Post-Order Traversal caller function
void BinarySearchTree::postOrderTraversal() {
    if (!root) {
       cout << "Tree is empty."<<endl;
        return;
    }
    postOrderRecursive(root);
}

void BinarySearchTree::postOrderRecursive(Node* root) {
    // Base Case: If root is null, return
    if (!root) return;

    // Functionality based on LRN (Left -> Right -> Node)
    postOrderRecursive(root->left);
    postOrderRecursive(root->right);
    cout << root->data << " ";
}

// Postorder Traversal (Left, Right, Root)
void BinarySearchTree::postOrderIterative() {
    Node* dummy = new Node(0);
    dummy->left = root;
    Node* current = dummy;

    while (current) {
        if (!current->left) {
            current = current->right;
        } else {
            Node* pred = current->left;
            while (pred->right && pred->right != current)
                pred = pred->right;

            if (!pred->right) {
                pred->right = current;
                 current = current->left;
            } else {
                Node* temp = current->left;
                Node* tail = nullptr;
                pred->right = nullptr;

                while (temp != current) {
                    Node* next = temp->right;
                    temp->right = tail;
                    tail = temp;
                    temp = next;
                }
                while (tail) {
                    cout << tail->data << " ";
                    Node* next = tail->right;
                    tail->right = temp;
                    temp = tail;
                    tail = next;
                }
                current = current->right;
            }
        }
    }
        delete dummy;
        cout << endl;
}

