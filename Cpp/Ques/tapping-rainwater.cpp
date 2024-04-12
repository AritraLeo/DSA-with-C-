/*

1. **Initialization**: We initialize a stack `st` to keep track of the indices of the bars, and variables `n` (the number of bars) and `ans` (the total amount of trapped water) to keep track of the current state.

2. **Iterating through each bar**: We iterate through each bar in the input array `a`.

3. **Processing bars with decreasing heights**: For each bar, we check if the stack is not empty and the height of the current bar (`a[i]`) is greater than the height of the bar at the top of the stack (`a[st.top()]`). If this condition is met, it means that the current bar forms a "valley" with the bars represented by the elements in the stack. We continue this process until the condition is no longer satisfied.

4. **Calculating trapped water**: For each bar that forms a "valley" with the bars represented by the elements in the stack, we calculate the amount of water that can be trapped between them. This is done by considering the height of the water at the current bar level (`min(a[st.top()], a[i])`) and subtracting the height of the current bar (`a[cur]`). We then multiply this difference by the length of the container (the distance between the current bar and the bar at the top of the stack minus one) to get the volume of water trapped.

5. **Updating the answer**: We update the total amount of trapped water (`ans`) by adding the volume of water trapped between each pair of bars.

6. **Pushing the current bar index onto the stack**: After processing each bar, we push its index onto the stack to consider it for potential future calculations.

7. **Returning the final answer**: Once all bars have been processed, we return the total amount of trapped water (`ans`).

*/

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