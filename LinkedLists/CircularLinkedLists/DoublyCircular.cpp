#include <iostream>
using namespace std;

template <typename Type>
class Node {
public:
    Type data;
    Node<Type>* next;
    Node<Type>* prev;

    Node(Type value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename Type>
class DoublyCircularLinkedList {
    Node<Type>* head;

public:
    DoublyCircularLinkedList() : head(nullptr) {}

    // Insert at the head of the list
    void insertAtHead(Type value) {
        Node<Type>* newNode = new Node<Type>(value);
        if (isEmpty()) {
            head = newNode;
            newNode->next = head; // Circular link to itself
            newNode->prev = head; // Circular link to itself
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode; // Update the last node's next pointer
            head->prev = newNode;       // Update the head's prev pointer
            head = newNode;             // Update the head to point to the new node
        }
    }

    // Insert at the tail of the list
    void insertAtTail(Type value) {
        Node<Type>* newNode = new Node<Type>(value);
        if (isEmpty()) {
            head = newNode;
            newNode->next = head; // Circular link to itself
            newNode->prev = head; // Circular link to itself
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode; // Update the last node's next pointer
            head->prev = newNode;       // Update the head's prev pointer
        }
    }

    // Delete the node at the head
    void deleteAtHead() {
        if (isEmpty()) {
            cerr << "List is empty. Cannot delete." << endl;
            return;
        }
        if (head->next == head) {  // Only one node in the list
            delete head;
            head = nullptr;
        } else {
            Node<Type>* nodeToDelete = head;
            head = head->next;
            head->prev = nodeToDelete->prev; // Update the new head's prev pointer
            nodeToDelete->prev->next = head; // Update the last node's next pointer
            delete nodeToDelete;
        }
    }

    // Delete the node at the tail
    void deleteAtTail() {
        if (isEmpty()) {
            cerr << "List is empty. Cannot delete." << endl;
            return;
        }
        if (head->next == head) {  // Only one node in the list
            delete head;
            head = nullptr;
        } else {
            Node<Type>* nodeToDelete = head->prev;
            nodeToDelete->prev->next = head;  // Update the second-to-last node's next pointer
            head->prev = nodeToDelete->prev;  // Update the head's prev pointer
            delete nodeToDelete;
        }
    }

    // Display the list
    void display() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }
        Node<Type>* temp = head;
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);  // Loop back to the head to stop at one complete cycle
        cout << "(back to head)" << endl;
    }

    // Check if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    ~DoublyCircularLinkedList() {
        while (!isEmpty()) {
            deleteAtHead();
        }
    }
};
