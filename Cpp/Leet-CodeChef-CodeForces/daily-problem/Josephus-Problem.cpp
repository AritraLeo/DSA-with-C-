#include <iostream>

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        return josephus(n, k) + 1; // Convert 0-based index to 1-based index
    }

private:
    int josephus(int n, int k)
    {
        if (n == 1)
        {
            return 0; // Base case: if there's only one person, they are the winner (0-based index)
        }
        else
        {
            // Recurrence relation: the winner of n-1 people with k steps, adjusted for the current size
            return (josephus(n - 1, k) + k) % n;
        }
    }
};

int main()
{
    Solution solution;

    // Test cases
    int n, k;

    // Test case 1
    n = 5;
    k = 2;
    std::cout << "The winner with n=5, k=2 is: " << solution.findTheWinner(n, k) << " (Expected: 3)" << std::endl;

    // Test case 2
    n = 6;
    k = 5;
    std::cout << "The winner with n=6, k=5 is: " << solution.findTheWinner(n, k) << " (Expected: 1)" << std::endl;

    // Test case 3
    n = 7;
    k = 3;
    std::cout << "The winner with n=7, k=3 is: " << solution.findTheWinner(n, k) << " (Expected: 4)" << std::endl;

    return 0;
}
