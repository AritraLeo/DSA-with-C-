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
#define MapVecit(it) map<int, vector<int>>::iterator it

int main()
{
    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<int, int> cnt;

    int prefSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefSum += a[i];
        cnt[prefSum]++;
    }
    int ans = 0;
    map<int, int>::iterator it;
    for (it = cnt.begin(); it != cnt.end(); it++)
    {
        int c = it->second;

        // Choosing an element nC2 Combination formula:
        ans += (c * (c - 1)) / 2;
        if (it->first == 0)
        {
            ans += it->second;
        }
    }
    cout << ans << endl;

    return 0;
}
// Input: 1 -1 1 -1
// Output: 4 as (1, -1) then (-1, 1) then (1, -1) ends (1, -1)