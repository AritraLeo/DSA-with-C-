#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        // n=customers.size();
        // keep window (mins -> w) l=0, r=w-1 if it's < n
        // while(r<n) -> maxSatis = max(maxSatis, getSatisVal(customers, grumpy, l, r))
        // l+=w, r+=w;
        int n = customers.size();
        int maxSatis = 0;
        if (n == 1)
            return customers[0];
        if (minutes >= n)
        {
            for (int i = 0; i < n; i++)
            {
                maxSatis += customers[i];
            }
        }

        int l = 0, r = minutes - 1;
        cout << " n :" << n << endl;
        while (r <= n - 1)
        {
            maxSatis = max(maxSatis, getSatisVal(customers, grumpy, l, r));
            cout << "l :" << l << " r :" << r << " max :" << maxSatis << endl;
            // l += minutes;
            // r += minutes;
            l++;
            r++;
        }
        /*
        l->r:
        0->2
        1->3
        2->4
        */

        return maxSatis;
    }

private:
    int getSatisVal(vector<int> &customers, vector<int> &grumpy, int l, int r)
    {
        // when l to r add all satis
        // rest check from grumpy
        int satis = 0;
        for (int i = 0; i < customers.size(); i++)
        {
            if (i == l)
            {
                for (int j = l; j <= r; j++)
                {
                    satis += customers[j];
                }
                if (r == customers.size() - 1)
                    return satis;
                i += r - l + 1;
            }

            if (grumpy[i] == 1)
                continue;

            else if (grumpy[i] == 0)
            {
                satis += customers[i];
            }
        }

        return satis;
    }
};

/* Optimized Approach

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int total_satis = 0, max_extra = 0, extra = 0;

        for (int i = 0; i < n; ++i) {
            total_satis += customers[i] * (1 - grumpy[i]);
            if (i >= minutes) {
                extra -= grumpy[i - minutes] * customers[i - minutes];
            }
            extra += grumpy[i] * customers[i];
            max_extra = max(max_extra, extra);
        }

        return total_satis + max_extra;
    }
};
*/

int main()
{
    Solution sol;

    // Test case 1
    vector<int> customers1 = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy1 = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes1 = 3;
    cout << "Test case 1 - Expected: 16, Got: " << sol.maxSatisfied(customers1, grumpy1, minutes1) << endl;

    // Test case 2
    vector<int> customers2 = {3, 8, 8, 7, 1};
    vector<int> grumpy2 = {1, 0, 1, 0, 1};
    int minutes2 = 2;
    cout << "Test case 2 - Expected: 23, Got: " << sol.maxSatisfied(customers2, grumpy2, minutes2) << endl;

    // Test case 3
    vector<int> customers3 = {4, 10, 10};
    vector<int> grumpy3 = {1, 1, 0};
    int minutes3 = 2;
    cout << "Test case 3 - Expected: 24, Got: " << sol.maxSatisfied(customers3, grumpy3, minutes3) << endl;

    // Test case 4
    vector<int> customers4 = {1};
    vector<int> grumpy4 = {1};
    int minutes4 = 1;
    cout << "Test case 4 - Expected: 1, Got: " << sol.maxSatisfied(customers4, grumpy4, minutes4) << endl;

    // Test case 5
    vector<int> customers5 = {10, 1, 7};
    vector<int> grumpy5 = {1, 0, 1};
    int minutes5 = 3;
    cout << "Test case 5 - Expected: 18, Got: " << sol.maxSatisfied(customers5, grumpy5, minutes5) << endl;

    return 0;
}