#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        // find no of pairs and leftover ints in nums arr
        int n = nums.size();
        unordered_map<int, int> m;
        for (int a : nums)
        {
            m[a]++;
        }
        int c = 0, t = 0;
        for (auto x : m)
        {

            // cout << "X: " << x.first << " Count: " << x.second << endl;
            if (x.second == 2)
                c++;

            else if (x.second > 2)
            {
                c += x.second / 2;
                t += x.second % 2;
            }

            else if (x.second == 1)
                t++;
        }

        nums.clear();
        nums.push_back(c);
        nums.push_back(t);

        return nums;
    }
};

void runTests()
{
    Solution sol;

    vector<int> test1 = {5, 12, 53, 22, 7, 59, 41, 54, 71, 24, 91, 74, 62, 47, 20, 14, 73, 11, 82, 2, 15, 38, 38, 20, 57, 70, 86, 93, 38, 75, 94, 19, 36, 40, 28, 6, 35, 86, 38, 94, 4, 90, 18, 87, 24, 22};
    vector<int> result1 = sol.numberOfPairs(test1);
    cout << "Test 1: " << "[" << result1[0] << ", " << result1[1] << "]" << endl; // Expected: [7, 32]

    vector<int> test2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> result2 = sol.numberOfPairs(test2);
    cout << "Test 2: " << "[" << result2[0] << ", " << result2[1] << "]" << endl; // Expected: [0, 10]

    vector<int> test3 = {1, 1, 1, 1, 2, 2, 3, 3, 4, 4, 4};
    vector<int> result3 = sol.numberOfPairs(test3);
    cout << "Test 3: " << "[" << result3[0] << ", " << result3[1] << "]" << endl; // Expected: [4, 1]

    vector<int> test4 = {2, 2, 2, 2, 2, 2};
    vector<int> result4 = sol.numberOfPairs(test4);
    cout << "Test 4: " << "[" << result4[0] << ", " << result4[1] << "]" << endl; // Expected: [3, 0]

    vector<int> test5 = {7, 7, 7, 7, 7, 7, 7};
    vector<int> result5 = sol.numberOfPairs(test5);
    cout << "Test 5: " << "[" << result5[0] << ", " << result5[1] << "]" << endl; // Expected: [3, 1]
}

int main()
{
    runTests();
    return 0;
}
