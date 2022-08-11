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

vector<string> ans;



void GarlandCheck(string s)
{
    char ch, ch2, yesC = 0, NoC = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        ch = s[i];
        ch2 = s[i + 1];
        if (ch == 'R' && ch2 == 'G')
        {
            continue;
        }
        else if (ch == 'G' && ch2 == 'R')
        {
            continue;
        }
        else
        {
            NoC++;
        }
    }
    if (NoC > 0)
    {
        ans.push_back("No");
        // cout << "No" << endl;
    }
    else
    {
        ans.push_back("Yes");
        // cout << "yes" << endl;
    }
}

int main()
{
    int t;
    string s;
    cin >> t;
    while (t > 0)
    {
        t--;
        cin >> s;
        GarlandCheck(s);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}