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

int maxArea(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int maxWater = 0;

    while (left < right)
    {
        int minHeight = min(height[left], height[right]);
        int width = right - left;
        int currentWater = minHeight * width;
        maxWater = max(maxWater, currentWater);

        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return maxWater;
}

int main()
{
    int n; // Length of the vectors
    cout << "Enter the length of the vectors: ";
    cin >> n;

    vector<int> vector1(n);

    cout << "Enter elements for vector: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> vector1[i];
    }

    cout << maxArea(vector1) << endl;
    return 0;
}