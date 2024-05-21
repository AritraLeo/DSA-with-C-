#include <iostream>
#include <vector>

using namespace std;

/*
Logic -

The subsets function initializes an empty result vector to store all the subsets and an empty subset vector to keep track of the current subset being generated.
It calls the backtrack function with the initial parameters: result, subset, nums, and start index 0.
In the backtrack function:
It adds the current subset to the result vector.
It iterates through the remaining elements in nums starting from the start index.
For each element, it adds the element to the subset, recursively calls backtrack with the updated start index, and then removes the element from the subset to backtrack.
The subsets function returns the result vector containing all the generated subsets.
*/

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> subset;
        backtrack(result, subset, nums, 0);
        return result;
    }

private:
    void backtrack(vector<vector<int>> &result, vector<int> &subset, vector<int> &nums, int start)
    {
        result.push_back(subset);

        for (int i = start; i < nums.size(); i++)
        {
            subset.push_back(nums[i]);
            backtrack(result, subset, nums, i + 1);
            subset.pop_back();
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = solution.subsets(nums);

    for (const auto &subset : result)
    {
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
