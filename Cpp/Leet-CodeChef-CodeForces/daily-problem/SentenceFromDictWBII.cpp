/*
Initial logic -

// map m initialize with key = wordDict words and vector<int> to
//         store indexes
//         // for every wordDict[i] try to get it's length then
//         // in s -> check for existance if true save the index in map m
//         // Now to create output -> o
//         // check if all the m's key are having list size() >= 1 else return
//         []
//         // permComb() ->
//         // find the lowest index in list of m and so on aesc order
//         // start to create strings by -> for the lowest index how many words
//         are present
//         // for 2nd lowest and so on
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

/*
wordBreak function:
This is the main function that takes the input string s and the vector of words wordDict as parameters.
It creates an unordered_set called wordSet from the wordDict vector. This allows for efficient lookup of words in the dictionary.
It initializes an empty result vector to store the final sentences.
It calls the backtrack function with the initial parameters: s, start (0), empty path, wordSet, and result.
Finally, it returns the result vector containing all possible sentences.
backtrack function:
This is a recursive helper function that generates all possible sentences.
The function takes the following parameters:
s: The input string.
start: The current starting position in the string.
path: The current sentence being constructed.
wordSet: The set of words from the dictionary.
result: The vector to store the final sentences.
The function first checks if the start position has reached the end of the string (start == s.length()). If so, it means a valid sentence has been constructed, so it adds the path to the result vector and returns.
If the start position has not reached the end, the function enters a loop that iterates through all possible substrings starting from the start position.
For each substring word = s.substr(start, end - start), it checks if the word is present in the wordSet.
If the word is found in the wordSet, the function recursively calls itself with the following updates:
If the path is empty, it calls backtrack with end as the new start and word as the new path.
If the path is not empty, it calls backtrack with end as the new start and path + " " + word as the new path.
This recursive process continues until the start position reaches the end of the string, at which point a valid sentence is added to the result vector.
*/

class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> result;
        backtrack(s, 0, "", wordSet, result);
        return result;
    }

private:
    void backtrack(string &s, int start, string path, unordered_set<string> &wordSet, vector<string> &result)
    {
        if (start == s.length())
        {
            result.push_back(path);
            return;
        }

        for (int end = start + 1; end <= s.length(); end++)
        {
            string word = s.substr(start, end - start);
            if (wordSet.count(word))
            {
                if (path.empty())
                {
                    backtrack(s, end, word, wordSet, result);
                }
                else
                {
                    backtrack(s, end, path + " " + word, wordSet, result);
                }
            }
        }
    }
};

int main()
{
    Solution solution;

    // Test case 1
    string s1 = "catsanddog";
    vector<string> wordDict1 = {"cat", "cats", "and", "sand", "dog"};
    vector<string> result1 = solution.wordBreak(s1, wordDict1);
    for (const auto &sentence : result1)
    {
        std::cout << sentence << std::endl;
    }
    std::cout << std::endl;

    // Test case 2
    string s2 = "pineapplepenapple";
    vector<string> wordDict2 = {"apple", "pen", "applepen", "pine", "pineapple"};
    vector<string> result2 = solution.wordBreak(s2, wordDict2);
    for (const auto &sentence : result2)
    {
        std::cout << sentence << std::endl;
    }
    std::cout << std::endl;

    // Test case 3
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    vector<string> result3 = solution.wordBreak(s3, wordDict3);
    for (const auto &sentence : result3)
    {
        std::cout << sentence << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
