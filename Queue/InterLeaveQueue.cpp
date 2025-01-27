#include <iostream>
#include "QueueUsingSinglyLL.cpp" // Assuming this file defines the Queue class with enQueue, deQueue, isEmpty methods.
using namespace std;

void interleaveQueue(Queue<int>& q) {
    int size = 0; 
    Queue<int> firstHalf;
    Queue<int> secondHalf;

    // Move all elements from the original queue to a temporary queue to calculate size
    Queue<int> tempQueue; 
    while (!q.isEmpty()) {
        tempQueue.enQueue(q.deQueue());
        size++;
    }

    // Handle cases where interleaving is not possible
    if (size <= 1) {
        cout << "Nothing to interleave!" << endl;
        return;
    }

    // Split the temporary queue into two halves
    for (int i = 0; i < size / 2; i++) {
        firstHalf.enQueue(tempQueue.deQueue());
    }
    for (int i = size / 2; i < size; i++) {
        secondHalf.enQueue(tempQueue.deQueue());
    }

    // Interleave elements from both halves back into the original queue
    while (!firstHalf.isEmpty() && !secondHalf.isEmpty()) {
        q.enQueue(firstHalf.deQueue());
        q.enQueue(secondHalf.deQueue());
    }

    // If there are any remaining elements (for odd-sized queues), add them back
    while (!firstHalf.isEmpty()) {
        q.enQueue(firstHalf.deQueue());
    }
    while (!secondHalf.isEmpty()) {
        q.enQueue(secondHalf.deQueue());
    }
}

int main() {
    Queue<int> q; 

    // Enqueue some elements into the queue
    for (int i = 1; i <= 6; i++) { // Change this range to test with different sizes
        q.enQueue(i);
    }

    // Call the interleaveQueue function
    interleaveQueue(q);

    // Print the interleaved queue
    while (!q.isEmpty()) {
        cout << q.deQueue() << " ";
    }
    cout << endl;

    return 0; 
}
