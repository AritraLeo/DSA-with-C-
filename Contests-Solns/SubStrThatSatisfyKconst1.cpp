#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int countSubstrings(string s, int k)
    {
        int n = s.length();
        int total = 0;

        // Iterate over each possible starting point of the substring
        for (int i = 0; i < n; i++)
        {
            int count0 = 0;
            int count1 = 0;

            // Iterate over each possible ending point of the substring starting from i
            for (int j = i; j < n; j++)
            {
                // Count the number of 0s and 1s in the substring s[i..j]
                if (s[j] == '0')
                {
                    count0++;
                }
                else
                {
                    count1++;
                }

                // Check if the substring satisfies the k-constraint
                if (count0 <= k || count1 <= k)
                {
                    total++;
                }
                else
                {
                    // If the substring no longer satisfies the condition, break early
                    break;
                }
            }
        }

        return total;
    }
};

// Example usage:
int main()
{
    Solution sol;
    string s = "10101";
    int k = 1;
    int result = sol.countSubstrings(s, k);
    cout << "Output: " << result << endl; // Output should be 12
    return 0;
}
