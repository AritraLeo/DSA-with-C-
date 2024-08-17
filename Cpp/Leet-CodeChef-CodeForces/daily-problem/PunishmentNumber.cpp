#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int punishmentNumber(int n)
    {
        int totalPunishment = 0;

        for (int i = 1; i <= n; ++i)
        {
            int square = i * i;
            if (canPartition(square, i))
            {
                totalPunishment += square;
            }
        }

        return totalPunishment;
    }

private:
    bool canPartition(int square, int target)
    {
        string squareStr = to_string(square);
        return checkPartition(squareStr, 0, target);
    }

    bool checkPartition(const string &s, int index, int target)
    {
        if (target == 0 && index == s.length())
            return true;
        if (index >= s.length())
            return false;

        int currentNum = 0;
        for (int j = index; j < s.length(); ++j)
        {
            currentNum = currentNum * 10 + (s[j] - '0'); // Build the current number
            if (currentNum > target)
                break; // No need to continue if currentNum exceeds target

            // Recursively check the next part of the string
            if (checkPartition(s, j + 1, target - currentNum))
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution solution;
    int n = 10; // Example input
    int result = solution.punishmentNumber(n);
    cout << "Punishment number for " << n << " is: " << result << endl;

    return 0;
}