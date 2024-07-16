#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    int countGoodNumbers(long long n)
    {
        // ans for n > 1 -> 5^n/2 * 4^n/2
        const int MOD = 1e9 + 7;
        long long evenCount = (n + 1) / 2; // count of even positions
        long long oddCount = n / 2;        // count of odd positions

        long long result = (modularExponentiation(5, evenCount, MOD) * modularExponentiation(4, oddCount, MOD)) % MOD;
        return static_cast<int>(result);
    }

private:
    long long modularExponentiation(long long base, long long exp, int mod)
    {
        long long result = 1;
        while (exp > 0)
        {
            if (exp % 2 == 1)
            {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
};

// Function to test the solution
void testCountGoodNumbers(long long n)
{
    Solution sol;
    cout << "Count of good numbers of length " << n << " is: " << sol.countGoodNumbers(n) << endl;
}

int main()
{
    testCountGoodNumbers(1);  // Output: 5
    testCountGoodNumbers(4);  // Output: 400
    testCountGoodNumbers(50); // Output: 564908303
    return 0;
}
