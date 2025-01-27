#include "StackUsingArray.cpp"

// Function to check if the given string of braces is balanced
bool checkBraces(const string& braces) {
    int length = braces.length(); // Get the length of the input string
    Stack<char> stack(length); // Initialize a stack with the given length

    // Return false for empty or single-character strings
    if (length == 0 || length == 1)
        return false;

    // Iterate through each character in the string
    for (int i = 0; i < length; i++) {
        // Push opening braces onto the stack
        if (braces[i] == '(' || braces[i] == '{' || braces[i] == '[') {
            stack.push(braces[i]);
        }
        // For closing braces, check for a matching opening brace
        else if (braces[i] == ')' || braces[i] == '}' || braces[i] == ']') {
            // If the stack is empty, it's an invalid sequence
            if (stack.isEmpty()) {
                return false;
            }
            // Pop the top element and check if it matches the closing brace
            char c = stack.pop();
            if ((braces[i] == ')' && c != '(') ||
                (braces[i] == '}' && c != '{') ||
                (braces[i] == ']' && c != '[')) {
                return false;
            }
        }
    }
    // If the stack is empty, all braces were matched; otherwise, it's invalid
    return stack.isEmpty();
}

int main() {
    string s = "[()]{}{[()()]()}"; // Balanced braces
    cout << checkBraces(s) << endl; // Output: 1 (true)

    string s2 = "[(])"; // Unbalanced braces
    cout << checkBraces(s2) << endl; // Output: 0 (false)

    string s3 = "}"; // Single unmatched closing brace
    cout << checkBraces(s3) << endl; // Output: 0 (false)

    string s4 = ""; // Empty string
    cout << checkBraces(s4) << endl; // Output: 0 (false)

    return 0; 
}
