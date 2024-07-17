#include <iostream>

class Solution
{
public:
    int lastRemaining(int n)
    {
        return removeElements(n, 0);
    }

private:
    int removeElements(int n, int turn)
    {
        if (n == 1)
        {
            return 1;
        }

        if (turn % 2 == 0)
        {
            return 2 * removeElements(n / 2, turn + 1);
        }
        else
        {
            return n % 2 == 0 ? 2 * removeElements(n / 2, turn + 1) - 1 : 2 * removeElements(n / 2, turn + 1);
        }
    }
};

void testSolution()
{
    Solution solution;

    // Test case 1
    int result1 = solution.lastRemaining(9);
    std::cout << "Test case 1 (n = 9): Expected 6, Actual: " << result1 << std::endl;

    // Test case 2
    int result2 = solution.lastRemaining(1);
    std::cout << "Test case 2 (n = 1): Expected 1, Actual: " << result2 << std::endl;

    // Test case 3
    int result3 = solution.lastRemaining(10);
    std::cout << "Test case 3 (n = 10): Expected 2, Actual: " << result3 << std::endl;
}

int main()
{
    testSolution();
    return 0;
}