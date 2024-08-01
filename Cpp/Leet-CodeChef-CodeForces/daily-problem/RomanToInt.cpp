#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            // For C before D, M and otherwise
            if (ch == 'C')
            {
                if (i + 1 < s.length() && s[i + 1] == 'D')
                {
                    res += 400;
                    i++;
                }
                else if (i + 1 < s.length() && s[i + 1] == 'M')
                {
                    res += 900;
                    i++;
                }
                else
                {
                    res += 100;
                }
            }
            // For X before L, C and otherwise
            else if (ch == 'X')
            {
                if (i + 1 < s.length() && s[i + 1] == 'L')
                {
                    res += 40;
                    i++;
                }
                else if (i + 1 < s.length() && s[i + 1] == 'C')
                {
                    res += 90;
                    i++;
                }
                else
                {
                    res += 10;
                }
            }
            // For I before V and X and otherwise
            else if (ch == 'I')
            {
                if (i + 1 < s.length() && s[i + 1] == 'V')
                {
                    res += 4;
                    i++;
                }
                else if (i + 1 < s.length() && s[i + 1] == 'X')
                {
                    res += 9;
                    i++;
                }
                else
                {
                    res += 1;
                }
            }
            // For M, D, L, V
            else if (ch == 'M')
                res += 1000;
            else if (ch == 'D')
                res += 500;
            else if (ch == 'L')
                res += 50;
            else if (ch == 'V')
                res += 5;
        }
        return res;
    }
};

// Main function to test the Solution
int main()
{
    Solution solution;
    vector<pair<string, int>> testCases = {
        {"III", 3},
        {"IV", 4},
        {"IX", 9},
        {"LVIII", 58},
        {"MCMXCIV", 1994},
        {"CM", 900},
        {"CD", 400},
        {"XL", 40},
        {"XC", 90},
        {"XCIX", 99}};

    for (auto &testCase : testCases)
    {
        string roman = testCase.first;
        int expected = testCase.second;
        int result = solution.romanToInt(roman);
        cout << "Roman: " << roman << " => Integer: " << result << " (Expected: " << expected << ")" << endl;
        if (result != expected)
        {
            cout << "Test case failed!" << endl;
        }
    }

    return 0;
}
