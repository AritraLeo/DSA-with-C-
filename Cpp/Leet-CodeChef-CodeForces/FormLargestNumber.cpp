#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        string s;
        vector<int> new_nums;
        // extract each digit from the list like - [2, 45, 36, 9, 10] as - [2,4,5,3,6,9,1,0] {store in separate vector}
        for (size_t i = 0; i < nums.size(); i++)
        {
            // single digit
            if (nums[i] <= 9)
            {
                new_nums.push_back(nums[i]);
            }
            // multiple digit
            else
                extractDigits(nums[i], new_nums);
        }
        // arrange this in desc order -> simply concat it as string
        // arrange this in desc order -> simply concat it as string
        sort(new_nums.rbegin(), new_nums.rend());

        for (size_t i = 0; i < new_nums.size(); i++)
        {
            s += to_string(new_nums[i]);
        }
        return s;
    }

private:
    void extractDigits(int num, vector<int> &digits)
    {
        if (num == 0)
        {
            digits.push_back(0); // Special case for 0
            return;
        }

        while (num > 0)
        {
            digits.push_back(num % 10); // Extract the last digit
            num /= 10;                  // Remove the last digit
        }
    }
};

int main()
{
    // Test case
    vector<int> nums = {3,30,34,5,9};
    Solution sol;
    string result = sol.largestNumber(nums);
    cout << "Input: nums = [";
    for (size_t i = 0; i < nums.size(); ++i)
    {
        cout << nums[i];
        if (i < nums.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]" << endl;
    cout << "Output: \"" << result << "\"" << endl;

    return 0;
}
