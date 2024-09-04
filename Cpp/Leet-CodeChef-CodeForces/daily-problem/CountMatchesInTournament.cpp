#include <iostream>
using namespace std;

class Solution
{
public:
    int numberOfMatches(int n)
    {
        // while(temsAd > 1)
        // if(teamsAd == 1) return noM;
        // if n->even : M = n/2, teamsAd = n/2
        // if n->odd: M=n-1/2, teamsAd = n-1/(2+1)
        // noM += M;
        int noM = 0, m = 0;
        while (n >= 1)
        {
            if (n == 1)
            {
                return noM;
            }
            if (n % 2 == 0)
            {
                m = n / 2;
                n = n / 2;
            }

            else if (n % 2 != 0)
            {
                m = (n - 1) / 2;
                n = ((n - 1) / 2) + 1;
            }
            noM += m;
        }
        return 1;
    }
};

void runTests()
{
    Solution sol;

    int test1 = 7;
    int result1 = sol.numberOfMatches(test1);
    cout << "Test 1: " << result1 << endl; // Expected: 6

    int test2 = 14;
    int result2 = sol.numberOfMatches(test2);
    cout << "Test 2: " << result2 << endl; // Expected: 13

    int test3 = 1;
    int result3 = sol.numberOfMatches(test3);
    cout << "Test 3: " << result3 << endl; // Expected: 0

    int test4 = 2;
    int result4 = sol.numberOfMatches(test4);
    cout << "Test 4: " << result4 << endl; // Expected: 1

    int test5 = 1000;
    int result5 = sol.numberOfMatches(test5);
    cout << "Test 5: " << result5 << endl; // Expected: 999
}

int main()
{
    runTests();
    return 0;
}
