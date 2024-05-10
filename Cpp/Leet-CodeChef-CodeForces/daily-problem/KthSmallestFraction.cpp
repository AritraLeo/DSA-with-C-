#include <iostream>
#include <vector>
#include <utility>

using namespace std;

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
