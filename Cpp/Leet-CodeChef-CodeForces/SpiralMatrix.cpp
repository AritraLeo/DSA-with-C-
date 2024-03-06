#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <string>
#include <climits>
#include <set>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
const int N = 1e3 + 2, MOD = 1e9 + 7;

string spiralmatrix(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> ans;

    // start and end points
    int a = 0, b = n - 1, c = m - 1, d = a + 1;
    int e = n, f = m, g = n - 1, h = m - 1;

    if (a >= 0 and b > 0 and c > 0 and d > 0 and e > 0 and f > 0 and g > 0 and h > 0)
    {

        for (int i = a; i < e; i++)
        {
            ans.push_back(matrix[a][i]);
            e--;
            a++;
        }

        for (int i = b; i < f; i++)
        {
            ans.push_back(matrix[i][b]);
            b--;
            f--;
        }

        for (int i = c; i >= g; i--)
        {
            ans.push_back(matrix[c][i]);
            g--;
            c--;
        }

        for (int i = h; i >= d; i--)
        {
            ans.push_back(matrix[i][d]);
            d--;
            h++;
        }
    }

    string s = "";
    for (int i = 0; i < ans.size(); i++)
    {
        s = " " + ans[i];
    }
    return s;
}

int main()
{
    int m, n;
    cout << "Enter m and n" << endl;
    cin >> m >> n;
    vector<vector<int>> v;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    cout << spiralmatrix(v) << endl;

    return 0;
}