#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // Copy vector and sort in descending order
        vector<int> cpy = score;
        sort(cpy.rbegin(), cpy.rend());

        // Map to store score-index pairs
        unordered_map<int, int> m;
        for (int i = 0; i < cpy.size(); i++) {
            m[cpy[i]] = i + 1;
        }

        // Vector to store relative ranks
        vector<string> s;

        // Assign ranks to scores
        for (int i = 0; i < score.size(); i++) {
            int rank = m[score[i]];
            if (rank == 1) {
                s.push_back("Gold Medal");
            } else if (rank == 2) {
                s.push_back("Silver Medal");
            } else if (rank == 3) {
                s.push_back("Bronze Medal");
            } else {
                s.push_back(to_string(rank));
            }
        }

        return s;
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<int> scores1 = {5, 4, 3, 2, 1};
    vector<string> result1 = sol.findRelativeRanks(scores1);
    cout << "Test Case 1: ";
    for (auto& rank : result1) {
        cout << rank << " ";
    }
    cout << endl;

    vector<int> scores2 = {10, 3, 8, 9, 4};
    vector<string> result2 = sol.findRelativeRanks(scores2);
    cout << "Test Case 2: ";
    for (auto& rank : result2) {
        cout << rank << " ";
    }
    cout << endl;

    return 0;
}
