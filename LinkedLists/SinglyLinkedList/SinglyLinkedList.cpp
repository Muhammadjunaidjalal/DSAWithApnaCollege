#include <iostream>
using namespace std;

template <typename Type>
class Node {
public:
    Type data;
    Node<Type>* next;

    Node(Type value) : data(value), next(nullptr) {}
};

template <typename Type>
class SinglyLinkedList {
    Node<Type>* head;
    Node<Type>* tail;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at the head of the list
    void insertAtHead(Type value) {
        Node<Type>* newNode = new Node<Type>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Insert at the tail of the list
    void insertAtTail(Type value) {
        Node<Type>* newNode = new Node<Type>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete the node at the head
    void deleteAtHead() {
        if (isEmpty()) {
            cerr << "List is empty. Cannot delete." << endl;
            return;
        }
        Node<Type>* nodeToDelete = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr; // If list becomes empty
        }
        delete nodeToDelete;
    }

    // Delete the node at the tail
    void deleteAtTail() {
        if (isEmpty()) {
            cerr << "List is empty. Cannot delete." << endl;
            return;
        }
        if (head == tail) { // Only one node
            delete head;
            head = tail = nullptr;
            return;
        }
        Node<Type>* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    // Display the list
    void display() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }
        Node<Type>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Check if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    ~SinglyLinkedList() {
        while (!isEmpty()) {
            deleteAtHead();
        }
    }
};