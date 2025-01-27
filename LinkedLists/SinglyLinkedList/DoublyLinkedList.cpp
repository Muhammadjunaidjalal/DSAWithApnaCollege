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
class DoublyLinkedList {
    Node<Type>* head;
    Node<Type>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at the head of the list
    void insertAtHead(Type value) {
        Node<Type>* newNode = new Node<Type>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
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
            newNode->prev = tail;
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
        } else {
            head->prev = nullptr;
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
        Node<Type>* nodeToDelete = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete nodeToDelete;
    }

    // Display the list from head to tail
    void display() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }
        Node<Type>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Check if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    ~DoublyLinkedList() {
        while (!isEmpty()) {
            deleteAtHead();
        }
    }
};

