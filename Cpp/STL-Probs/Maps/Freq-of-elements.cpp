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
    int n;
    cout << "Enter size of array:" << endl;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }

    // Making iterator and printing the elements:
    map<int, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++)
    {
        cout << it->first << "  " << it->second << " " << endl;
    }

    return 0;
}