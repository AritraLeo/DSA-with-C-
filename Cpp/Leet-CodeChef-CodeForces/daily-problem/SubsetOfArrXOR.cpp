#include <iostream>
#include <vector>

class Solution
{
public:
    int subsetXORSum(std::vector<int> &nums)
    {
        // Start the recursive process with index 0 and initial XOR value 0
        return calculateXORSum(nums, 0, 0);
    }

private:
    int calculateXORSum(const std::vector<int> &nums, int index, int currentXOR)
    {
        // Base case: If we've considered all elements, return the current XOR total
        if (index == nums.size())
        {
            return currentXOR;
        }

        // Recursive case: Calculate the sum of XOR totals
        // Option 1: Include the current element in the XOR total
        int include = calculateXORSum(nums, index + 1, currentXOR ^ nums[index]);
        // Option 2: Exclude the current element from the XOR total
        int exclude = calculateXORSum(nums, index + 1, currentXOR);

        // Return the sum of XOR totals from both options
        return include + exclude;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    std::vector<int> nums1 = {2, 5, 6};
    std::cout << "Sum of all XOR totals for [2, 5, 6]: " << solution.subsetXORSum(nums1) << std::endl;

    // Test case 2
    std::vector<int> nums2 = {1, 3};
    std::cout << "Sum of all XOR totals for [1, 3]: " << solution.subsetXORSum(nums2) << std::endl;

    // Test case 3
    std::vector<int> nums3 = {5, 1, 6};
    std::cout << "Sum of all XOR totals for [5, 1, 6]: " << solution.subsetXORSum(nums3) << std::endl;

    // Test case 4
    std::vector<int> nums4 = {1, 2, 3, 4};
    std::cout << "Sum of all XOR totals for [1, 2, 3, 4]: " << solution.subsetXORSum(nums4) << std::endl;

    return 0;
}
