#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        int currentDepth = 0;
        
        for (char c : s) {
            if (c == '(') {
                currentDepth++;
                maxDepth = max(maxDepth, currentDepth);
            } else if (c == ')') {
                currentDepth--;
            }
        }
        
        return maxDepth;
    }
};

int main() {
    Solution sol;

    // Test cases
    string s1 = "(1+(2*3)+((8)/4))+1"; // Nesting depth is 3
    string s2 = "(1)+((2))+(((3)))";   // Nesting depth is 3
    string s3 = "1+(2*3)/(2-1)";       // Nesting depth is 1

    cout << "Test Case 1: " << sol.maxDepth(s1) << endl;
    cout << "Test Case 2: " << sol.maxDepth(s2) << endl;
    cout << "Test Case 3: " << sol.maxDepth(s3) << endl;

    return 0;
}
