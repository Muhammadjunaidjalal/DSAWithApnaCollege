#include <iostream> 
using namespace std; 

template <typename Type>
class Node {
public:
    Type data; // Data stored in the node
    Node* next; // Pointer to the next node

    // Constructor to initialize a node with a value
    Node(Type value) : data(value), next(nullptr) {}
};

template <typename Type>
class Stack {
    Node<Type>* head; // Pointer to the top node of the stack

public:
    // Constructor to initialize an empty stack
    Stack() : head(nullptr) {}

    // Check if the stack is empty
    bool isEmpty() {
        return head == nullptr; // Return true if the stack is empty (no top element)
    }

    // Push an element onto the stack
    void push(Type data) {
        Node<Type>* newNode = new Node<Type>(data); // Create a new node with the given data
        newNode->next = head; // Set the next of the new node to the current top
        head = newNode; // Make the new node the top of the stack
    }

    // Pop the top element from the stack
    Type pop() {
        if (isEmpty()) {
            cout << "Stack is empty " << endl; // Error message if the stack is empty
            return Type(); // Return a default value of Type
        }
        Node<Type>* nodeToDelete = head; // Get the current top node
        head = head->next; // Move the head pointer to the next node
        Type value = nodeToDelete->data; // Store the data of the node to delete
        delete nodeToDelete; // Delete the old top node
        return value; // Return the data of the popped node
    }

    // Get the top element of the stack without removing it
    Type top() {
        if (isEmpty()) {
            cout << "Stack is empty " << endl; // Error message if the stack is empty
            return Type(); // Return a default value of Type
        }
        return head->data; // Return the data of the top node
    }

    // Destructor to free memory used by the stack
    ~Stack() {
        while (!isEmpty()) {
            Node<Type>* nodeToDelete = head; // Get the current top node
            head = head->next; // Move the head pointer to the next node
            delete nodeToDelete; // Delete the current top node
        }
    }
};
