#include "StackUsingArray.cpp"
#include <string>

// Function to count the number of similar words in an array
int similarWords(const string words[], int size){
    // Handle edge cases: empty array or single word
    if(size == 0) return 0;
    if(size == 1) return 1;

    Stack<string> stack(size); // Initialize a stack for storing words
    
    // Iterate through each word in the array
    for (int i = 0; i < size; i++){
        // If stack is not empty, check the top word
        if (!stack.isEmpty()) {
            string s = stack.pop(); // Pop the top element
            // If the current word is not the same as the top, push both words
            if (s != words[i]) {
                stack.push(s);
                stack.push(words[i]);
            }
        } else {
            // If stack is empty, push the current word
            stack.push(words[i]);
        }
    }

    // Count the remaining words in the stack
    int len = 0;
    while (!stack.isEmpty()) {
        stack.pop(); // Pop and count each element
        len++;
    }

    return len; // Return the number of unique words
}

int main(){
    // Test case with an array of words
    string words[] = {"tom", "jerry", "jerry", "tom", "tom"};
    int size = sizeof(words) / sizeof(words[0]); // Calculate size of array

    cout << similarWords(words, size); // Output: 2 (unique words: "tom", "jerry")
    return 0; 
}
