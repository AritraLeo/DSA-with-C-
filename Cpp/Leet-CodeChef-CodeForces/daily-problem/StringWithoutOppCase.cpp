/*
Initial approach breaking for case - abBAcC

class Solution {
public:
    string makeGood(string s) {
        // Will check case of s[i] & s[i+1]. If same, then proceed; else, omit both.
        // Lowercase = -1, Uppercase = 1
        for(int i = 0; i < s.size() - 1; i++) {
            int CaseOfi = checkCase(s, i);
            int CaseOfiplus1 = checkCase(s, i + 1);
            if((CaseOfi == -1 && CaseOfiplus1 == 1) || (CaseOfi == 1 && CaseOfiplus1 == -1)) {
                // Omit
                s.erase(i, 2);
                // Reset the index to check the previous pairs
                i = max(0, i - 2);
            }
            cout << s << " " << i << " " << s.size() << endl;
        }
        return s;
    }

    int checkCase(string &s, int i) {
        return islower(s[i]) ? -1 : 1; 
    }
};


*/

#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;

        // Traverse the string
        for (char ch : s) {
            // Check if the stack is not empty and the current character cancels the top character
            if (!st.empty() && abs(st.top() - ch) == 32) {
                // Pop the top character from the stack
                st.pop();
            } else {
                // Otherwise, push the current character onto the stack
                st.push(ch);
            }
        }

        // Reconstruct the string from the stack
        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;
    string input = "abBAcC";
    cout << "Input: " << input << endl;
    cout << "Output: " << sol.makeGood(input) << endl;
    return 0;
}
