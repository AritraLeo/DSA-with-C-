#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string largestPalindromic(string num)
    {
        vector<int> digit_count(10, 0);
        string middle = "";
        string half_palindrome = "";

        for (char c : num)
        {
            digit_count[c - '0']++;
        }

        for (int digit = 9; digit >= 0; digit--)
        {
            string digit_str = to_string(digit);
            if (digit_count[digit] > 1)
            {
                if (digit_str != "0" || (!half_palindrome.empty()))
                {
                    half_palindrome += string(digit_count[digit] / 2, digit_str[0]);
                }
                digit_count[digit] %= 2;
            }
            if (digit_count[digit] == 1 && middle.empty())
            {
                middle = digit_str;
                digit_count[digit]--;
            }
        }

        string palindrome = half_palindrome + middle + string(half_palindrome.rbegin(), half_palindrome.rend());

        return palindrome.empty() ? "0" : palindrome;
    }
};

int main()
{
    Solution solution;
    vector<string> test_cases = {
        "9876543210",
        "12321",
        "1111111111",
        "10001",
        "0",
        "54321",
        "1221"};

    for (const string &test_case : test_cases)
    {
        cout << "Input: " << test_case << " -> Largest Palindromic: " << solution.largestPalindromic(test_case) << endl;
    }

    return 0;
}
