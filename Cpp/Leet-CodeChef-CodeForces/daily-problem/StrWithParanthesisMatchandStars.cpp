/*

The function checks the validity of a string containing parentheses and asterisks. It uses two stacks to track left parentheses and asterisks encountered. When a right parenthesis is found, it tries to match it with a corresponding left parenthesis or an asterisk. Finally, it ensures that all left parentheses are matched, considering asterisks as valid placeholders. If successful, it returns true; otherwise, it returns false.
*/


#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftParentheses;
        stack<int> stars;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                leftParentheses.push(i);
            } else if (s[i] == '*') {
                stars.push(i);
            } else { // s[i] == ')'
                if (!leftParentheses.empty()) {
                    leftParentheses.pop();
                } else if (!stars.empty()) {
                    stars.pop();
                } else {
                    return false; // No matching left parenthesis or star
                }
            }
        }

        while (!leftParentheses.empty() && !stars.empty()) {
            if (leftParentheses.top() < stars.top()) {
                leftParentheses.pop();
                stars.pop();
            } else {
                break; // No more valid matching pairs
            }
        }

        return leftParentheses.empty();
    }
};

int main() {
    Solution sol;

    // Test cases
    cout << "Test Case 1: " << sol.checkValidString("(((((()*)(*)*))())())(()())())))((**)))))(()())()") << endl; // Expected: false
    cout << "Test Case 2: " << sol.checkValidString("(*)") << endl; // Expected: true
    cout << "Test Case 3: " << sol.checkValidString("((*)") << endl; // Expected: true
    cout << "Test Case 4: " << sol.checkValidString("(*))") << endl; // Expected: true
    cout << "Test Case 5: " << sol.checkValidString("((*)*)") << endl; // Expected: true
    cout << "Test Case 6: " << sol.checkValidString("((*)**)") << endl; // Expected: true

    return 0;
}
