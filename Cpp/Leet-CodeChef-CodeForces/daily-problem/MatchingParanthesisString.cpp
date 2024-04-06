#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    s[i] = '*'; // Marking invalid closing parenthesis
                }
            }
        }
        
        // Marking remaining unmatched opening parentheses
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        
        // Constructing the final result string
        string result;
        for (char ch : s) {
            if (ch != '*') {
                result += ch;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    string s1 = "lee(t(c)o)de)";
    string s2 = "a)b(c)d";
    string s3 = "))((";

    cout << "Input: " << s1 << ", Output: " << sol.minRemoveToMakeValid(s1) << endl;
    cout << "Input: " << s2 << ", Output: " << sol.minRemoveToMakeValid(s2) << endl;
    cout << "Input: " << s3 << ", Output: " << sol.minRemoveToMakeValid(s3) << endl;

    return 0;
}
