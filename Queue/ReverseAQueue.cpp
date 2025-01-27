#include "QueueUsingSinglyLL.cpp"
#include <iostream>
using namespace std;

// Function to reverse the queue using recursion
void reverseQueue(Queue<int> &q) {
    // Base case: if the queue is empty or has only one element, do nothing
    if (q.isEmpty()) return;

    // Remove the front element
    int frontElement = q.deQueue();

    // Recursively reverse the remaining queue
    reverseQueue(q);

    // Add the removed element to the back of the queue
    q.enQueue(frontElement);
}

int main() {
    Queue<int> q;

    // Enqueue elements into the queue
    for (int i = 1; i <= 10; i++) {
        q.enQueue(i);
    }

    // Reverse the queue
    reverseQueue(q);

    // Print the reversed queue
    while (!q.isEmpty()) {
        cout << q.deQueue() << " ";
    }
    cout << endl;

    return 0;
}
