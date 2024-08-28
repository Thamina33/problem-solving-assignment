#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

bool isValid(const string& s) {
    stack<char> stk;
    unordered_map<char, char> matchingBrackets = {
            {')', '('},
            {']', '['},
            {'}', '{'}
    };

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stk.empty() || stk.top() != matchingBrackets[c]) {
                return false;
            }
            stk.pop();
        }
    }

    return stk.empty();
}

int main() {
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";
    string s4 = "{()}";
    string s5 = "{(})";

    cout << boolalpha; // To print boolean values as true/false
    cout << "Input: " << s1 << " Output: " << isValid(s1) << endl;
    cout << "Input: " << s2 << " Output: " << isValid(s2) << endl;
    cout << "Input: " << s3 << " Output: " << isValid(s3) << endl;
    cout << "Input: " << s4 << " Output: " << isValid(s4) << endl;
    cout << "Input: " << s5 << " Output: " << isValid(s5) << endl;

    return 0;
}

/*
 * Time and Space Complexity:
 * Time Complexity: O(n) where n is the length of the input string.Each character is processed exactly once.
 * Space Complexity: O(n), due to the stack storing up to n opening brackets in the worst case.
 */