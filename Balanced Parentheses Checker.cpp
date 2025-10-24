#include <iostream>
#include <stack>
using namespace std;

// Function to check if two characters are matching pairs
bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

// Function to check if parentheses are balanced
bool areParenthesesBalanced(const string& expr) {
    stack<char> s;

    for (char ch : expr) {
        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // If closing bracket, check for matching
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty() || !isMatchingPair(s.top(), ch)) {
                return false; // Unmatched closing bracket
            }
            s.pop(); // Pop the matched opening bracket
        }
    }

    // If stack is empty, all brackets were matched
    return s.empty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (areParenthesesBalanced(expression)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}
