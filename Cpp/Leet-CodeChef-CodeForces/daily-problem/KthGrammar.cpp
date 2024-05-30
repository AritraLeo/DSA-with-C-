/*
Working approach -


class Solution {
public:
    int kthGrammar(int n, int k) {
        string res = backtrack("0", "", 1, n);
        // cout << "Res:" << res;
        return res[k-1] - '0';
    }

    string backtrack(string prev, string rowVal, int c, int n){
        // cout << "row val  " << rowVal << " prev " << prev << endl;
        if(c == n) return prev;

        // Calc rowVal from prev
        for(int i=0; i < prev.length(); i++){
            if(prev[i] == '0') rowVal += "01";

            else rowVal += "10";
        }
        c++;
        // cout << "row val  " << rowVal << " prev " << prev << endl;

        return backtrack(rowVal, "", c, n);
    }
};

*/

#include <iostream>

using namespace std;

class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (n == 1)
            return 0; // Base case: The first row is just "0".

        // Find the parent's symbol
        int parent = kthGrammar(n - 1, (k + 1) / 2);

        // Determine the current symbol based on the parent's symbol and the position k
        if (parent == 0)
        {
            return (k % 2 == 1) ? 0 : 1; // "01" -> 0 if odd, 1 if even
        }
        else
        {
            return (k % 2 == 1) ? 1 : 0; // "10" -> 1 if odd, 0 if even
        }
    }
};

// Sample usage and test cases
int main()
{
    Solution sol;
    std::cout << sol.kthGrammar(1, 1) << std::endl;          // Output: 0
    std::cout << sol.kthGrammar(2, 1) << std::endl;          // Output: 0
    std::cout << sol.kthGrammar(2, 2) << std::endl;          // Output: 1
    std::cout << sol.kthGrammar(4, 5) << std::endl;          // Output: 1
    std::cout << sol.kthGrammar(30, 434991989) << std::endl; // Output: 0
    return 0;
}
