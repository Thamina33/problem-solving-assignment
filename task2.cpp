#include <iostream>
#include <stack>
#include <string>

using namespace std;

string removeDuplicates(const string& s) {
    stack<char> stk;

    for (char c : s) {
        if (!stk.empty() && stk.top() == c) {
            stk.pop(); // Remove the top of the stack if it's the same as the current character
        } else {
            stk.push(c); // Otherwise, add the current character to the stack
        }
    }

    // Construct the result string from the characters remaining in the stack
    string result;
    while (!stk.empty()) {
        result = stk.top() + result;
        stk.pop();
    }

    return result;
}

int main() {
    string s1 = "abbaca";
    string s2 = "azxxzy";

    cout << "Input: " << s1 << " Output: " << removeDuplicates(s1) << endl;
    cout << "Input: " << s2 << " Output: " << removeDuplicates(s2) << endl;

    return 0;
}

/*
 * Time and Space Complexity:
 * Time Complexity: O(n), where n is the length of the input string. Each character is pushed and popped from the stack at most once.
 *Space Complexity: O(n), where n is the length of the input string. In the worst case, all characters are stored in the stack if no duplicates are removed.
 */