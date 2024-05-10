#include <iostream>
#include <vector>
#include <utility>

using namespace std;

/*
Initialize two pointers numerator and denominator to represent the numerator and denominator of the current fraction respectively.
Start with the smallest possible fraction, where the numerator is the smallest element in the array and the denominator is the largest element in the array.
Use a two-pointer approach to iterate over all possible fractions:
Start with numerator = arr[0] and denominator = arr[n-1].
Count the number of fractions in the array that are smaller than or equal to the current fraction.
Adjust the numerator and denominator based on the count:
If the count is less than k, increase the numerator to the next greater element in the array.
If the count is greater than or equal to k, decrease the denominator to the next smaller element in the array.
Repeat this process until numerator and denominator represent the k-th smallest fraction.
Return the numerator and denominator
*/

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double lo = 0.0, hi = 1.0;
        vector<int> result(2);

        while (lo < hi) {
            double mid = (lo + hi) / 2;
            int count = 0;
            int numerator = 0, denominator = 1;

            for (int i = 0, j = 1; i < n - 1; ++i) {
                while (j < n && arr[i] >= arr[j] * mid) ++j;
                count += n - j;
                if (j < n && numerator * arr[j] < denominator * arr[i]) {
                    numerator = arr[i];
                    denominator = arr[j];
                }
            }

            if (count == k) {
                result[0] = numerator;
                result[1] = denominator;
                return result;
            } else if (count < k) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    vector<int> arr1 = {1, 2, 3, 5};
    int k1 = 3;
    vector<int> result1 = solution.kthSmallestPrimeFraction(arr1, k1);
    cout << "Test Case 1: [" << result1[0] << ", " << result1[1] << "]" << endl;

    vector<int> arr2 = {1, 7};
    int k2 = 1;
    vector<int> result2 = solution.kthSmallestPrimeFraction(arr2, k2);
    cout << "Test Case 2: [" << result2[0] << ", " << result2[1] << "]" << endl;

    vector<int> arr3 = {1, 2, 3, 4, 5, 6};
    int k3 = 3;
    vector<int> result3 = solution.kthSmallestPrimeFraction(arr3, k3);
    cout << "Test Case 3: [" << result3[0] << ", " << result3[1] << "]" << endl;

    return 0;
}
