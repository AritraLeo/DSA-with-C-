/*
Initial slightly wrong approach -

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board[0].size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    // perform in recursively
                    // checkEles -> next itr: board of any of these isn't null
                    // indexes -> [i-1] & [i+1][j], [i][j+1] and [j-1]
                    if (checkEles(board, i, j, word, 1, ""))
                        return true;
                }
            }
        }
        return false;
    }

    bool checkEles(vector<vector<char>>& b, int i, int j, string word, int k, string res) {

        while (k < word.length() - 1) {

            if (i - 1 >= 0 && b[i - 1][j] == word[k]) {
                checkEles(b, i - 1, j, word, k + 1, res);
                res += word[k];
                // break;
            } else if (i + 1 != b[0].size() && b[i + 1][j] == word[k]) {
                checkEles(b, i + 1, j, word, k + 1, res);
                res += word[k];
                // break;

            } else if (j - 1 >= 0 && b[i][j - 1] == word[k]) {
                checkEles(b, i, j - 1, word, k + 1, res);
                res += word[k];

                // break;

            } else if (j + 1 != b[0].size() && b[i][j + 1] == word[k]) {
                checkEles(b, i, j + 1, word, k + 1, res);
                res += word[k];

                // break;

            } else {
                return false;
            }
        }
        if (res == word) {
            return true;
        }
        return false;
    }
};

*/


// Solution beats 99.8% people in term of memory (original solution)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (checkEles(board, i, j, word, 0))
                        return true;
                }
            }
        }
        return false;
    }

    bool checkEles(vector<vector<char>>& b, int i, int j, string& word, int k) {
        if (k == word.length())
            return true;

        if (i < 0 || i >= b.size() || j < 0 || j >= b[0].size() || b[i][j] != word[k])
            return false;

        char temp = b[i][j];
        b[i][j] = '#'; // Mark as visited

        bool found = checkEles(b, i - 1, j, word, k + 1) ||
                     checkEles(b, i + 1, j, word, k + 1) ||
                     checkEles(b, i, j - 1, word, k + 1) ||
                     checkEles(b, i, j + 1, word, k + 1);

        b[i][j] = temp; // Restore the original value
        return found;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {{'A','B','C','E'},
                                   {'S','F','C','S'},
                                   {'A','D','E','E'}};
    string word1 = "ABCCED";
    string word2 = "SEE";
    string word3 = "ABCB";

    cout << "Test Case 1: " << (sol.exist(board, word1) ? "Found" : "Not Found") << endl;
    cout << "Test Case 2: " << (sol.exist(board, word2) ? "Found" : "Not Found") << endl;
    cout << "Test Case 3: " << (sol.exist(board, word3) ? "Found" : "Not Found") << endl;

    return 0;
}
