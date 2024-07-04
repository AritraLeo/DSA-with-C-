#include <iostream>

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1.0;
        double half = myPow(x, n / 2);
        if (n % 2 == 0)
        {
            return half * half;
        }
        else
        {
            if (n > 0)
            {
                return half * half * x;
            }
            else
            {
                return half * half / x;
            }
        }
    }
};

int main()
{
    Solution solution;

    // Test cases
    double x;
    int n;

    // Test case 1
    x = 2.0;
    n = 10;
    std::cout << "2.0^10 = " << solution.myPow(x, n) << " (Expected: 1024.0)" << std::endl;

    // Test case 2
    x = 2.1;
    n = 3;
    std::cout << "2.1^3 = " << solution.myPow(x, n) << " (Expected: 9.261)" << std::endl;

    // Test case 3
    x = 2.0;
    n = -2;
    std::cout << "2.0^-2 = " << solution.myPow(x, n) << " (Expected: 0.25)" << std::endl;

    // Test case 4
    x = 2.0;
    n = 0;
    std::cout << "2.0^0 = " << solution.myPow(x, n) << " (Expected: 1.0)" << std::endl;

    // Test case 5
    x = 1.0;
    n = -2147483648; // Edge case: very large negative exponent
    std::cout << "1.0^-2147483648 = " << solution.myPow(x, n) << " (Expected: 1.0)" << std::endl;

    return 0;
}
