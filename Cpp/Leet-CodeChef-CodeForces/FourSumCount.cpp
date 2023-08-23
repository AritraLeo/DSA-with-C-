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

/* Brute force
int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    int n = nums1.size();

    if (n == 1)
        return 1;

    set<string> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    if (nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0)
                    {
                        string s = " " + to_string(i) + ", " + to_string(j) + ", " +
                                to_string(k) + ", " + to_string(l) + " ";
                        ans.insert(s);
                    }
                }
            }
        }
    }

    return ans.size();
}
*/

int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    int n = nums1.size();

    if (n == 0)
        return 0;

    unordered_map<int, int> sumAB;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sumAB[nums1[i] + nums2[j]]++;
        }
    }

    int count = 0;

    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l < n; l++)
        {
            int target = -(nums3[k] + nums4[l]);
            count += sumAB[target];
        }
    }

    return count;
}

int main()
{
    int n; // Length of the vectors
    cout << "Enter the length of the vectors: ";
    cin >> n;

    vector<int> vector1(n);
    vector<int> vector2(n);
    vector<int> vector3(n);
    vector<int> vector4(n);

    cout << "Enter elements for vector 1: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> vector1[i];
    }

    cout << "Enter elements for vector 2: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> vector2[i];
    }

    cout << "Enter elements for vector 3: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> vector3[i];
    }

    cout << "Enter elements for vector 4: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> vector4[i];
    }

    cout << fourSumCount(vector1, vector2, vector3, vector4) << endl;
    return 0;
}