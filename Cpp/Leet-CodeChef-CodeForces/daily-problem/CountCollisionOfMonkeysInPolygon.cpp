#include <cmath>
#include <iostream>

class Solution
{
public:
    int countCollisions(int n)
    {
        const int MOD = 1'000'000'007;

        // Calculate 2^n % MOD
        long long totalWays = modExp(2, n, MOD);

        // Subtract 2 and take modulo
        long long result = (totalWays - 2 + MOD) % MOD;

        return result;
    }

private:
    // Helper function to perform modular exponentiation
    long long modExp(int base, int exp, int mod)
    {
        long long result = 1;
        long long power = base % mod;
        while (exp > 0)
        {
            if (exp % 2 == 1)
            {
                result = (result * power) % mod;
            }
            power = (power * power) % mod;
            exp /= 2;
        }
        return result;
    }
};

// Test the function
int main()
{
    Solution sol;
    int n = 4; // Change this value to test with different n
    std::cout << "Number of ways with collisions for n = " << n << " is: " << sol.countCollisions(n) << std::endl;
    return 0;
}
