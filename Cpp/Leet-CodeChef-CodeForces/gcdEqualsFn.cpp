#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

int gcd(int n1, int n2)
{
    int hcf;
    // swapping variables n1 and n2 if n2 is greater than n1.
    if (n2 > n1)
    {
        int temp = n2;
        n2 = n1;
        n1 = temp;
    }

    for (int i = 1; i <= n2; ++i)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            hcf = i;
        }
    }
    return hcf;
}

int lcm(int n1, int n2)
{
    // maximum value between n1 and n2 is stored in max
    int max = (n1 > n2) ? n1 : n2;
    int lcm;
    do
    {
        if (max % n1 == 0 && max % n2 == 0)
        {
            lcm = max;
            break;
        }
        else
            ++max;
    } while (true);
    return lcm;
}

int orderedPairs(int N)
{
    int Min = INT_MAX, counter = 0;
    // pair<vector<int>, vector<pair<int, int>>> pr;
    map<int, vector<pair<int, int>>> m;
    vector<int> v;
    int a, b, gx, sum = 0;
    for (int i = 1; i < N; i++)
    {
        a = i;
        for (int j = 1; j < N; j++)
        {
            b = j;
            sum = a + b;
            if (sum == N)
            {
                gx = gcd(a, b) + lcm(a, b);
                // pr.first.push_back(gx);
                m[gx].push_back({a, b});
                if (gx == sum)
                {
                    counter++;
                }
            }
        }
    }

    /*
        // sort(v.begin(), v.end());
        // cout << v[0] << endl;
        // cout << v[1] << endl;
        map<int, vector<pair<int, int>>>::iterator it;
        // sort(m.begin(), m.end());
        for (it = m.begin(); it != m.end(); it++)
        {
            Min = min(Min, it->first);
            // for (int i = 0; i < (it->second).size(); i++)
            // {
            // }
        }
        // cout << m[Min].begin()->first << endl;
        // cout << m[Min].begin()->second << endl;
    */
    return counter;
    // cout << counter << endl;
}

int main()
{
    // your code goes here
    int N, t, counter;
    vector<int> ans;
    cin >> t;
    while (t > 0)
    {
        t--;
        cin >> N;
        counter = orderedPairs(N);
        ans.push_back(counter);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}

/*

*/
