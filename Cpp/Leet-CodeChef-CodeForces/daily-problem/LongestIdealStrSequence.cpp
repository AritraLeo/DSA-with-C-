/*
1st approach - 
*/


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int l = 0, r = 0, maxLen = 0, n = s.length(), a, b, diff = 0;
        while (l < n - 1) {
            int c=0;
            while (r < n) {
                a = s[l];
                b = s[r];
                // cout << " l -> " << l << " r -> " << r << " a -> " << a
                //      << " b -> " << b << " maxLen -> " << maxLen << endl;
                diff = abs(b - a);
                if (diff <= k) {
                    maxLen = max(maxLen, r - l + 1 - c);
                }else{
                    r++;
                    c++;
                }
                // else{
                //     l=r;
                //     if(s[r+1] != '\0') r++;
                // }
                r++;
            }
            l++;
        }
        return maxLen;
    }
};


int main() {
    Solution sol;

    // Test cases
    string s1 = "acfgbd";
    int k1 = 2;
    cout << "Test Case 1: " << sol.longestIdealString(s1, k1) << endl; // Output: 4 (acfg)

    string s2 = "aaaaa";
    int k2 = 3;
    cout << "Test Case 2: " << sol.longestIdealString(s2, k2) << endl; // Output: 5 (aaaaa)

    string s3 = "abcdef";
    int k3 = 1;
    cout << "Test Case 3: " << sol.longestIdealString(s3, k3) << endl; // Output: 1 (a)

    return 0;
}