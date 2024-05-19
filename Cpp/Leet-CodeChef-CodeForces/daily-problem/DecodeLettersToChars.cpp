#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0; // If the string is empty, return 0

        // DP array to store the number of ways to decode substrings of different lengths
        vector<int> dp(n + 1, 0);

        // Base case: there's one way to decode an empty string
        dp[0] = 1;

        // If the first character is not '0', initialize dp[1] to 1
        dp[1] = s[0] != '0' ? 1 : 0;

        for (int i = 2; i <= n; i++)
        {
            // Check the last single digit
            int oneDigit = stoi(s.substr(i - 1, 1));
            if (oneDigit >= 1 && oneDigit <= 9)
            {
                dp[i] += dp[i - 1];
            }

            // Check the last two digits
            int twoDigits = stoi(s.substr(i - 2, 2));
            if (twoDigits >= 10 && twoDigits <= 26)
            {
                dp[i] += dp[i - 2];
            }
        }

        // The last element of dp array contains the total number of ways to decode the entire string
        return dp[n];
    }
};

int main()
{
    Solution sol;

    // Test case 1
    string s1 = "11106";
    cout << "Number of ways to decode \"" << s1 << "\": " << sol.numDecodings(s1) << endl;

    // Test case 2
    string s2 = "226";
    cout << "Number of ways to decode \"" << s2 << "\": " << sol.numDecodings(s2) << endl;

    // Test case 3
    string s3 = "0";
    cout << "Number of ways to decode \"" << s3 << "\": " << sol.numDecodings(s3) << endl;

    // Test case 4
    string s4 = "06";
    cout << "Number of ways to decode \"" << s4 << "\": " << sol.numDecodings(s4) << endl;

    return 0;
}
