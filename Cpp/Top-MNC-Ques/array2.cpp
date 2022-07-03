/*
2. Problem
Given an array arr[] of size N. The task is to find the first repeating element in an
array of integers, i.e., an element that occurs more than once and whose index of
first occurrence is smallest.
Constraints
1 <= N <= 106
0 <= Ai <= 106
Example
Input:
7
1 5 3 4 3 5 6
Output:
2
Explanation:
5 is appearing twice and its first appearance is at index 2 which is less than 3
whose first occurring index is 3.
Solution
Base idea: To check if an element is repeating, we maintain an array idx[], which
stores the first occurrence (index) of a particular element a[i].

*/

/* Optimised Code -   TC - O(n) */

/*
#include <iostream>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int i = 0, j = 0, st = -1, en = -1, sum = 0;
    while (j < n && sum + a[j] <= s)
    {
        sum += a[j];
        j++;
    }

    if (sum == s)
    {
        cout << i + 1 << " " << j << endl;
        return 0;
    }

    while (j < n)
    {
        sum += a[j];
        while (sum > s)
        {
            sum -= a[i];
            i++;
        }

        if (sum == s)
        {
            st = i + 1;
            en = j + 1;
            break;
        }
        j++;
    }

    cout << st << " " << j << endl;

    return 0;
}
*/

/* Brute Force Method */

#include <iostream>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        int currSum = 0;
        for (int j = 0; j < n; j++)
        {
            currSum = a[i] + a[j];
            if (currSum == s)
            {
                cout << i + 1 << " " << j + 1;
                return 0;
            }
        }
    }

    return 0;
}