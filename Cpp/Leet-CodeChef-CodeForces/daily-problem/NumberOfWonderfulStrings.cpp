/*
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long substrs = 0;
        int n = word.size();
        for(int i=0; i < n; i++){
            for(int j=0; j <= i; j++){
                if(word[j+1] != '\0' && word[j+1] != word[j]){
                    substrs++;
                }
                string s = word.substr(i, j);
                if(isWonderfulString(s)) substrs++;
                cout << "Sub str " << s << " count " << substrs << endl; 
            }
        }
        return substrs;
    }
public:
    bool isWonderfulString(string word){
        // size of v -> ascii of 97 + 10 more chars till j 
        vector<int> v(107, 0);
        // assign vector indexes as a to j like map
        for(int i=0; i < word.size(); i++){
            v[word[i]]++;
        }
        int c=0;
        for(int i='a'; i <= 'j'; i++){
            if(v[i] % 2 != 0) c++;

            if(c==2) return false;
        }
        return true;
    }
};
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long substrs = 0;
        int n = word.size();
        
        // Initialize a vector to store the count of substrings with different parities
        vector<int> count(1024, 0);
        count[0] = 1;
        
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            mask ^= 1 << (word[i] - 'a');
            substrs += count[mask];
            for (int j = 0; j < 10; ++j) {
                substrs += count[mask ^ (1 << j)];
            }
            count[mask]++;
        }
        
        return substrs;
    }
};

int main() {
    Solution sol;
    string word = "aba";
    cout << "Output: " << sol.wonderfulSubstrings(word) << endl; // Output: 4
    return 0;
}
