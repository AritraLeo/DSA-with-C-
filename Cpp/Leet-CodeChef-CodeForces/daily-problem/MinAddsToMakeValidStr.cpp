#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int addMinimum(string word)
    {
        int cnt = 0;
        int l = word.length();

        // We will iterate through the string and make sure each 'a' is followed by 'b' and 'c'
        for (int i = 0; i < l;)
        {
            if (word[i] == 'a')
            {
                if (i + 1 < l && word[i + 1] == 'b')
                {
                    if (i + 2 < l && word[i + 2] == 'c')
                    {
                        i += 3; // "abc" is found, move to the next sequence
                    }
                    else
                    {
                        cnt += 1; // "ab" found, missing 'c'
                        i += 2;
                    }
                }
                else
                {
                    if (i + 1 < l && word[i + 1] == 'c')
                    {
                        cnt += 1; // "ac" found, missing 'b'
                        i += 2;
                    }
                    else
                    {
                        cnt += 2; // Only "a" found, missing "bc"
                        i += 1;
                    }
                }
            }
            else if (word[i] == 'b')
            {
                if (i + 1 < l && word[i + 1] == 'c')
                {
                    cnt += 1; // "bc" found, missing 'a'
                    i += 2;
                }
                else
                {
                    cnt += 2; // Only "b" found, missing "ac"
                    i += 1;
                }
            }
            else if (word[i] == 'c')
            {
                cnt += 2; // Only "c" found, missing "ab"
                i += 1;
            }
        }

        return cnt;
    }
};

// Main function for testing
int main()
{
    Solution solution;
    vector<string> testCases = {
        "abc",    // Valid
        "a",      // Missing "bc"
        "ab",     // Missing "c"
        "ac",     // Missing "b"
        "b",      // Missing "ac"
        "bc",     // Missing "a"
        "c",      // Missing "ab"
        "aabcbca" // Complex case
    };

    for (auto &testCase : testCases)
    {
        int result = solution.addMinimum(testCase);
        cout << "Word: " << testCase << " => Additions needed: " << result << endl;
    }

    return 0;
}
