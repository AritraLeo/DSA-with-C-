#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long s = 0;
        if(k <= n){
            for(int i=0; i < k; i++){
                s += happiness[i] - i > 0 ? happiness[i] - i : 0;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> happiness1 = {10, 20, 30, 40, 50};
    int k1 = 3;
    cout << "Test Case 1: " << sol.maximumHappinessSum(happiness1, k1) << endl; // Output: 120

    // Test case 2
    vector<int> happiness2 = {100, 90, 80, 70, 60};
    int k2 = 2;
    cout << "Test Case 2: " << sol.maximumHappinessSum(happiness2, k2) << endl; // Output: 190

    // Test case 3
    vector<int> happiness3 = {1, 2, 3, 4, 5};
    int k3 = 5;
    cout << "Test Case 3: " << sol.maximumHappinessSum(happiness3, k3) << endl; // Output: 15

    return 0;
}
