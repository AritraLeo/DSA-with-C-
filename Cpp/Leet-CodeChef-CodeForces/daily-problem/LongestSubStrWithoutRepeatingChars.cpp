// #include <algorithm>

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         // if all eles same return 1;
//         int c=1, n = s.length();
//         for(int i=0; i < n; i++){
//             if(s[i] == s[i+1]) c++; 
//         }
//         if(c == n) return 1;
//         int l=0, r=l+1, maxlen = 0;
//         // if(n == 2 && s[l] != s[r]) return 2;
//         unordered_map<char, int> m;
//         m[s[l]]++;
//         while(r < n){
//             if(m.find(s[r]) != m.end()){
//                 m[s[r]]++;
//                 r++;
//             } 
//             else{
//                 l++;
//                 m[s[l]]--;
//                 if(m[s[l]] == 0) 
//                     m.erase(s[l]);
//             }
//             maxlen = max(maxlen, static_cast<int>(m.size()));
//             // maxlen = max(maxlen, r-l+1);
//         }
//         return maxlen;
//     }
// };


#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n <= 1) return n; // Handle edge case where the string has only one character

        int maxlen = 0;
        unordered_map<char, int> m;
        int l = 0, r = 0;

        while (r < n) {
            if (m.find(s[r]) == m.end()) {
                m[s[r]] = 1;
                maxlen = max(maxlen, r - l + 1);
                r++;
            } else {
                m.erase(s[l]);
                l++;
            }
        }

        return maxlen;
    }
};

int main() {
    Solution solution;

    // Test cases
    string s1 = "abcabcbb";
    cout << "Test Case 1: " << solution.lengthOfLongestSubstring(s1) << endl; // Output: 3 (abc)

    string s2 = "bbbbb";
    cout << "Test Case 2: " << solution.lengthOfLongestSubstring(s2) << endl; // Output: 1 (b)

    string s3 = "pwwkew";
    cout << "Test Case 3: " << solution.lengthOfLongestSubstring(s3) << endl; // Output: 3 (wke)

    string s4 = "";
    cout << "Test Case 4: " << solution.lengthOfLongestSubstring(s4) << endl; // Output: 0

    string s5 = " ";
    cout << "Test Case 5: " << solution.lengthOfLongestSubstring(s5) << endl; // Output: 1

    return 0;
}
