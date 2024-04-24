#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

class LongestSubStrWithKDistinctChars {
    public:
        int maxLenOfK(string s, int k){
            int maxLen = 0, l = 0, r = 0;
            unordered_map<char, int> m;
            while (r < s.size())
            {
                m[s[r]]++;
                if(m.size() <= k) 
                    maxLen = max(maxLen, r-l+1);

                while (m.size() > k)
                {
                    m[s[l]]--;
                    if(m[s[l]] == 0) 
                        m.erase(m[s[l]]);

                    l++;
                }
                r++;
            }
            return maxLen;
        }
};


int main() {
    LongestSubStrWithKDistinctChars obj;

    // Test Case 1: Basic test case with k=2
    string str1 = "abcba";
    int k1 = 2;
    cout << "Test Case 1: " << obj.maxLenOfK(str1, k1) << endl; // Output: 4 (abcb)

    // Test Case 2: All characters are distinct
    string str2 = "abcdef";
    int k2 = 3;
    cout << "Test Case 2: " << obj.maxLenOfK(str2, k2) << endl; // Output: 3 (abc)

    // Test Case 3: String length is less than k
    string str3 = "aab";
    int k3 = 4;
    cout << "Test Case 3: " << obj.maxLenOfK(str3, k3) << endl; // Output: 3 (aab)

    // Test Case 4: Empty string
    string str4 = "";
    int k4 = 2;
    cout << "Test Case 4: " << obj.maxLenOfK(str4, k4) << endl; // Output: 0

    return 0;
}
