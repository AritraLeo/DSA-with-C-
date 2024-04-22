// class Solution {
// public:
//     int openLock(vector<string>& deadends, string target) {
//         // start from 1st char of t and turn till reached after each turn 
//         // check if turn possible != deadend
//         // when 1st matches move to 2nd and so on
//         int c = 0;
//         string s = "0000";
//         for(int i=0; i < 4; i++){
//             if(target[i] != s[i])
//                 c += reaches(target[i], i, s, deadends);
//         }
//         return c == 0 ? -1 : c;
//     }
// public:
//     int reaches(char ith, int i, string s, vector<string>& deadends){
//         int k = s[i];
//         int cith = 0;
//         for(int j=k; j <= ith; j = turn(j)){
//             s[i] = j;
//             for(int u=0; u < deadends.size(); u++){
//                 if(deadends[u] == s)
//                     j = turn(j);
//             }
//             cith++;
//             if(ith == j) break;
//         }
//         return cith;
//     }
// public:
//     int turn(int j){
//         if(j == 9)
//             return 0;
//         else 
//             return j++;
//     }
// };

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string current = q.front();
                q.pop();
                if (current == target) return level;
                if (dead.count(current)) continue;

                for (int i = 0; i < 4; ++i) {
                    for (int d = -1; d <= 1; d += 2) {
                        char digit = (current[i] - '0' + d + 10) % 10 + '0';
                        string next = current;
                        next[i] = digit;
                        if (!visited.count(next)) {
                            q.push(next);
                            visited.insert(next);
                        }
                    }
                }
            }
            ++level;
        }
        return -1;
    }
};


int main() {
    Solution sol;

    // Test case 1
    vector<string> deadends1 = {"0201","0101","0102","1212","2002"};
    string target1 = "0202";
    cout << "Test case 1: " << sol.openLock(deadends1, target1) << endl;

    // Test case 2
    vector<string> deadends2 = {"8888"};
    string target2 = "0009";
    cout << "Test case 2: " << sol.openLock(deadends2, target2) << endl;

    // Test case 3
    vector<string> deadends3 = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    string target3 = "8888";
    cout << "Test case 3: " << sol.openLock(deadends3, target3) << endl;

    // Test case 4
    vector<string> deadends4 = {"0000"};
    string target4 = "8888";
    cout << "Test case 4: " << sol.openLock(deadends4, target4) << endl;

    return 0;
}
