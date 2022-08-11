#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <string>
#include <set>

using namespace std;

#define vi vector<int>
#define pii pair<int, int>
const int N = 1e3 + 2, MOD = 1e9 + 7;
int dp[N];

int minSquare(int n)
{
    if (n == 1 || n == 2 || n == 3 || n == 0)
    {
        return n;
    }
    // int ans = MOD;
    if (dp[n] != MOD)
    {
        return dp[n];
    }

    for (int i = 1; i * i <= n; i++)
    {
        dp[n] = min(dp[n], 1 + minSquare(n - i * i));
    }

    return dp[n];
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        dp[i] = MOD;
    }

    int n;
    cin >> n;

    cout << minSquare(n) << endl;
    return 0;
}