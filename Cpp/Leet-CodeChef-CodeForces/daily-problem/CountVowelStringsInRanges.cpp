#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        // create a new arr -> v: sores the count of words that satisfy condt.
        // count here => cumulative freq as in [1, 1, 2, 3, 4] for Ex - 1
        // based on this check with query range and store in ans: v[r] - v[l-1] (if l > 0)
        vector<int> v;
        vector<int> ans;
        int c = 0;
        for (int i = 0; i < words.size(); i++)
        {
            char f = words[i][0];
            char e = words[i][words[i].length() - 1];
            if (checkVowel(f) == true && checkVowel(e) == true)
            {
                c++;
            }
            v.push_back(c);
        }

        for (auto p : queries)
        {
            int l = p[0];
            int r = p[1];
            if (l != 0)
            {
                ans.push_back(v[r] - v[l - 1]);
                // cout << " l :" << l << " r :" << r << " s :" << v[r] - v[l-1] << endl;
            }
            else if (l == 0)
            {
                // cout << " l :" << l << " r :" << r << " s :" << v[r] << endl;
                ans.push_back(v[r]);
            }
        }

        return ans;
    }

private:
    bool checkVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    vector<string> words1 = {"apple", "orange", "ice", "umbrella", "echo"};
    vector<vector<int>> queries1 = {{0, 4}, {1, 3}, {0, 2}};
    vector<int> result1 = sol.vowelStrings(words1, queries1);
    cout << "Test Case 1: ";
    for (int res : result1)
    {
        cout << res << " ";
    }
    cout << endl;

    // Test Case 2
    vector<string> words2 = {"eat", "tea", "ate", "note", "elephant"};
    vector<vector<int>> queries2 = {{0, 1}, {2, 4}, {0, 4}};
    vector<int> result2 = sol.vowelStrings(words2, queries2);
    cout << "Test Case 2: ";
    for (int res : result2)
    {
        cout << res << " ";
    }
    cout << endl;

    // Test Case 3
    vector<string> words3 = {"a", "b", "c", "d", "e"};
    vector<vector<int>> queries3 = {{0, 4}, {1, 3}};
    vector<int> result3 = sol.vowelStrings(words3, queries3);
    cout << "Test Case 3: ";
    for (int res : result3)
    {
        cout << res << " ";
    }
    cout << endl;

    // Test Case 4
    vector<string> words4 = {"aeiou", "bcd", "io", "aei"};
    vector<vector<int>> queries4 = {{0, 3}, {1, 2}};
    vector<int> result4 = sol.vowelStrings(words4, queries4);
    cout << "Test Case 4: ";
    for (int res : result4)
    {
        cout << res << " ";
    }
    cout << endl;

    // Test Case 5
    vector<string> words5 = {"u", "o", "a", "i", "e"};
    vector<vector<int>> queries5 = {{0, 4}, {2, 4}, {1, 3}};
    vector<int> result5 = sol.vowelStrings(words5, queries5);
    cout << "Test Case 5: ";
    for (int res : result5)
    {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
