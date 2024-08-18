#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>

using namespace std;

class Solution
{
public:
    long long maxEnergyBoost(vector<int> &energyDrinkA, vector<int> &energyDrinkB)
    {
        int n = energyDrinkA.size();
        vector<long long> dpA(n, 0), dpB(n, 0); // Use long long

        dpA[0] = energyDrinkA[0];
        dpB[0] = energyDrinkB[0];

        for (int i = 1; i < n; i++)
        {
            dpA[i] = energyDrinkA[i] + max(dpA[i - 1], (i > 1 ? dpB[i - 2] : 0LL)); // 0LL ensures proper comparison with long long
            dpB[i] = energyDrinkB[i] + max(dpB[i - 1], (i > 1 ? dpA[i - 2] : 0LL));
        }

        return max(dpA[n - 1], dpB[n - 1]);
    }
};

// Example usage:
int main()
{
    Solution sol;
    vector<int> energyDrinkA = {4, 1, 1};
    vector<int> energyDrinkB = {1, 1, 3};
    long long result = sol.maxEnergyBoost(energyDrinkA, energyDrinkB);
    cout << "Maximum Energy Boost: " << result << endl; // Output should be 7
    return 0;
}
