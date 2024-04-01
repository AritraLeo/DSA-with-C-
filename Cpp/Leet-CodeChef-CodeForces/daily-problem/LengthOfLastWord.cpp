#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        // insert space at last
        s.insert(s.length(), " ");
        s.insert(0, " ");
        int c=0, j;
        for(int i=s.length() - 1; i >= 0; i--){
            c = 0;
            if(s[i] == ' ' && s[i-1] != ' '){
                // run loop till we don't get space again
                j=i-1;
                // has 1 char
                if(s[j-1] == ' ') return 1;
                while(s[j] != ' '){
                    c++;
                    j--;
                }
                return c;
                // set i to next word (not needed here)
                // i = j;
            }
        }
        return c;
    }
};

int main() {
    Solution solution;

    // Test cases
    string s1 = "Hello World";
    cout << "Example 1: " << solution.lengthOfLastWord(s1) << endl;

    string s2 = "Hello fly   ";
    cout << "Example 2: " << solution.lengthOfLastWord(s2) << endl;

    string s3 = "a ";
    cout << "Example 3: " << solution.lengthOfLastWord(s3) << endl;

    return 0;
}
