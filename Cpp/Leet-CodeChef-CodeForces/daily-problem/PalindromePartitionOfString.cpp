#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> res;
        backtrack(ans, res, s, 0);
        return ans;
    }

private:
    void backtrack(vector<vector<string>> &ans, vector<string> &res, string s, int start)
    {
        if (start == s.length())
        {
            ans.push_back(res);
            return;
        }

        for (int i = start; i < s.length(); i++)
        {
            if (isPalindrome(s, start, i))
            {
                string substr = s.substr(start, i - start + 1);
                res.push_back(substr);
                backtrack(ans, res, s, i + 1);
                res.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string s = "aab";
    vector<vector<string>> result = solution.partition(s);

    for (const auto &partition : result)
    {
        for (const string &palindrome : partition)
        {
            cout << palindrome << " ";
        }
        cout << endl;
    }

    return 0;
}
