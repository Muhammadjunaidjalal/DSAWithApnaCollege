#include <iostream> 
using namespace std; 

class Node{
    public: 
    int data; 
    Node* left; 
    Node* right; 

    Node(int value){
        this->data = value; 
        this->left = NULL; 
        this->right = NULL; 
    }

    ~Node(){
        delete left; 
        delete right;
    }
}; 

class BinarySearchTree{
    private: 
    Node *root; 
    
    //Helper Functions 
    Node* insertRecursive(Node*, int);
    void insertIterative(int); 

    void inOrderRecursive(Node*); 
    void preOrderRecursive(Node*);
    void postOrderRecursive(Node*); 
    void inOrderIterative(); 
    void preOrderIterative();
    void postOrderIterative(); 

    bool searchRecursive(Node*, int);
    bool searchIterative(int);

    int minimumRecursive(Node*);
    int maximumRecursive(Node*);
    int minimumIterative();
    int maximumIterative();

    Node* getMinimumNode(Node*);
    Node* getMaximumNode(Node*);

    Node* deleteRecursive(Node*, int);
    void deleteIterative(int);

    Node* inOrderSuccessorRecursive(Node*, int, Node*); 
    Node* inOrderPredecessorRecursive(Node*, int, Node*); 

    void printLeafNodesRecursive(Node*); 
    void sumOfLeafNodesRecursive(Node*,int&);

    int max(int, int);
    int heightRecursive(Node*);

    //public functions
    public: 
    void insert(int data);

    void inOrderTraversal(); 
    void preOrderTraversal(); 
    void postOrderTraversal();

    bool search(int);

    int getMin(); 
    int getMax();

    void remove(int);

    int inOrderSuccessor(int);
    int inOrderPredecessor(int);

    void leafNodes();

    int sumOfLeafNodes();

    int findParent(int);

    int findSibling(int);

    int getHeight();

     



};