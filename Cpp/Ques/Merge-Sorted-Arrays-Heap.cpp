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

int main()
{
    int k;
    cin >> k;

    vector<vector<int>> a(k);

    for (int i = 0; i < k; i++)
    {
        int size;
        cin >> size;

        a[i] = vector<int>(size);

        for (int j = 0; j < size; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<int> idx(k, 0);

    // Min heap
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (int i = 0; i < k; i++)
    {
        pii p;
        p.first = a[i][0];
        p.second = i;
        pq.push({a[i][0], i});
    }

    vi ans;

    while (!pq.empty())
    {
        pii x = pq.top();
        pq.pop();

        ans.push_back(x.first);

        if (idx[x.second] + 1 < a[x.second].size())
        {
            pii p;
            p.first = a[x.second][idx[x.second] + 1];
            p.second = x.second;
            pq.push(p);

            idx[x.second] += 1;
        }
    }

    // Printing Result:
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}

/*

Input:
3
3 1 4 6
2 2 3
3 5 6 7

Output:
1
2
3
4
5
6
6
7


*/