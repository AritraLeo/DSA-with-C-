#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        // Step 2: Set the first element to 1
        arr[0] = 1;

        // Step 3: Adjust the array to satisfy the conditions
        for (int i = 1; i < arr.size(); ++i)
        {
            // Ensure that arr[i] is at most 1 more than arr[i-1]
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }

        // The largest element will be at the end of the adjusted array
        return arr.back();
    }
};

int main()
{
    Solution sol;

    vector<int> arr1 = {2, 2, 1, 2, 1};
    cout << sol.maximumElementAfterDecrementingAndRearranging(arr1) << endl; // Output: 2

    vector<int> arr2 = {100, 1, 1000};
    cout << sol.maximumElementAfterDecrementingAndRearranging(arr2) << endl; // Output: 3

    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout << sol.maximumElementAfterDecrementingAndRearranging(arr3) << endl; // Output: 5

    vector<int> arr4 = {1};
    cout << sol.maximumElementAfterDecrementingAndRearranging(arr4) << endl; // Output: 1

    vector<int> arr5 = {10, 9, 8, 7};
    cout << sol.maximumElementAfterDecrementingAndRearranging(arr5) << endl; // Output: 4

    return 0;
}
