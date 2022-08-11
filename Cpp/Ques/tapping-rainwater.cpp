#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int rain_water(vector<int> a)
{
    stack<int> st;
    int n = a.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and a[st.top()] < a[i])
        {
            int cur = st.top();
            st.pop();
            if (st.empty())
            {
                break;
            }
            int ContainerLen = i - st.top() - 1;
            ans += (min(a[st.top()], a[i]) - a[cur]) * ContainerLen;
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    // Test case:
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // Ans - 6
    cout << rain_water(a) << endl;
    return 0;
}