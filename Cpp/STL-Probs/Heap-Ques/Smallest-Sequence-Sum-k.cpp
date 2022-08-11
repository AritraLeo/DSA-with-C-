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
priority_queue<int, vi> pq;

// Brute Force approach:

int main()
{
    int n;
    cout << "Enter the length of array" << endl;
    cin >> n;
    vi a(n);
    cout << "Enter the elements of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        pq.push(a[i]);
    }

    int k;
    cout << "Enter the sum to be checked for:" << endl;
    cin >> k;
    int sum = 0, counter = 0;
    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();
        counter++;

        if (sum >= k)
        {
            break;
        }
    }
    if (sum < k)
        cout << "Didn't find the combination for sum";
    else
        cout << counter << sum << endl;

    return 0;
}
