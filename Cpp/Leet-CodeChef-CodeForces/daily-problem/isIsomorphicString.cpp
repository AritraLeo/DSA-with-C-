#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, char> m;
        unordered_set<char> mappedChars; // To check if a character in 't' is already mapped

        for (int i = 0; i < s.length(); i++)
        {
            if (m.find(s[i]) != m.end())
            {
                // Check if the mapped character is correct
                if (m[s[i]] != t[i])
                    return false;
            }
            else
            {
                // Check if 't[i]' is already mapped to another character
                if (mappedChars.find(t[i]) != mappedChars.end())
                    return false;

                // Map 's[i]' to 't[i]'
                m[s[i]] = t[i];
                mappedChars.insert(t[i]);
            }
        }

        return true;
    }
};

int main()
{
    Solution solution;

    // Test cases
    string s1 = "egg";
    string t1 = "add";
    cout << "Example 1: " << solution.isIsomorphic(s1, t1) << endl;

    string s2 = "foo";
    string t2 = "bar";
    cout << "Example 2: " << solution.isIsomorphic(s2, t2) << endl;

    string s3 = "paper";
    string t3 = "title";
    cout << "Example 3: " << solution.isIsomorphic(s3, t3) << endl;

    return 0;
}
