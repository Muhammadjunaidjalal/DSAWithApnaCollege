#include <iostream> 
using namespace std; 

template <typename Type>
class Stack {
    int current, size; 
    Type* arr; 

public: 
    // Constructor to initialize the stack with a given size
    Stack(int size = 10) : size(size), current(0) { 
        this->arr = new Type[size]; // Dynamically allocate memory for the stack array
    }

    // Check if the stack is empty
    bool isEmpty() {
        return current == 0; // Return true if the current size is 0
    }

    // Check if the stack is full
    bool isFull() {
        return current == size; // Return true if the current size is equal to the stack size
    }

    // Push data onto the stack
    void push(Type data) {
        if (isFull()) {
            cout << "Stack is Full!" << endl; // Error message when the stack is full
            return;
        }
        arr[current++] = data; // Add the data and increment the current size
    }

    // Pop the top element from the stack
    Type pop() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl; // Error message when the stack is empty
            return Type(); // Return a default value of Type
        }

        return arr[--current]; // Return the top element and decrement the current size
    }

    // Get the top element of the stack without removing it
    Type top() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl; // Error message when the stack is empty
            return Type(); // Return a default value of Type
        }
        return arr[current - 1]; // Return the top element
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr; // Deallocate memory used by the stack
    }
};
