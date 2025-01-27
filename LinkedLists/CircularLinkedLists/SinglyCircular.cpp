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
class SinglyCircularLinkedList {
    Node<Type>* head;

public:
    SinglyCircularLinkedList() : head(nullptr) {}

    // Insert at the head of the list
    void insertAtHead(Type value) {
        Node<Type>* newNode = new Node<Type>(value);
        if (isEmpty()) {
            head = newNode;
            newNode->next = head;  // Circular link for the single node
        } else {
            newNode->next = head;
            Node<Type>* temp = head;
            // Traverse to the last node to maintain circular link
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            head = newNode;
        }
    }

    // Insert at the tail of the list
    void insertAtTail(Type value) {
        Node<Type>* newNode = new Node<Type>(value);
        if (isEmpty()) {
            head = newNode;
            newNode->next = head;  // Circular link for the single node
        } else {
            Node<Type>* temp = head;
            while (temp->next != head) {  // Traverse to the last node
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;  // Maintain circular link
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
            Node<Type>* temp = head;
            // Traverse to the last node to update the circular link
            while (temp->next != head) {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;  // Update the last node's next pointer
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
            Node<Type>* temp = head;
            // Traverse to the second last node
            while (temp->next->next != head) {
                temp = temp->next;
            }
            Node<Type>* nodeToDelete = temp->next;
            temp->next = head;  // Update the circular link
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
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);  // Loop back to the head to stop at one complete cycle
        cout << "(back to head)" << endl;
    }

    // Check if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    ~SinglyCircularLinkedList() {
        while (!isEmpty()) {
            deleteAtHead();
        }
    }
};
