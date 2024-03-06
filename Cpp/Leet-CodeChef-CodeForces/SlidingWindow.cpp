#include<iostream>
#include <bits/stdc++.h>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<string>
#include<climits>
#include<set>
using namespace std;
    
#define vi vector<int>
#define pii pair<int, int>
const int N = 1e3 + 2, MOD = 1e9 + 7;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n-k; i++)
    {
        set<int> res;
        for (int j = i; j < i+k; j++)
        {
            res.insert(nums[j]);
        }
        ans.push_back(*res.rbegin());
    }
    
    return ans;
}

int main()
{
    return 0;
}