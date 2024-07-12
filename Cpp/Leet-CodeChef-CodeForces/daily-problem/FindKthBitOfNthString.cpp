#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    char findKthBit(int n, int k)
    {
        string si = "0";
        string res;
        res = genStr(n, si, si);
        return res[k - 1];
    }

private:
    string genStr(int n, string s, string si)
    {
        if (n == 1)
            return s;

        string str = invert(si);
        reverse(str.begin(), str.end());
        n--;
        s = si + "1" + str;
        s = genStr(n, s, s);
        return s;
    }

    string invert(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
            {
                s[i] = '1';
            }
            else
            {
                s[i] = '0';
            }
        }
        return s;
    }
};

// Helper function for testing
void testFindKthBit(int n, int k, char expected)
{
    Solution sol;
    char result = sol.findKthBit(n, k);
    cout << "n: " << n << ", k: " << k << ", Result: " << result << ", Expected: " << expected << endl;
    cout << (result == expected ? "Test Passed" : "Test Failed") << "\n\n";
}

int main()
{
    testFindKthBit(3, 1, '0');  // S3 = "0111001", the 1st bit is '0'
    testFindKthBit(3, 3, '1');  // S3 = "0111001", the 3rd bit is '1'
    testFindKthBit(4, 11, '1'); // S4 = "011100110110001", the 11th bit is '1'
    testFindKthBit(2, 3, '1');  // S2 = "011", the 3rd bit is '1'
    return 0;
}
