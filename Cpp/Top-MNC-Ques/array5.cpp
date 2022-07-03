/*
Sub Array Sum Max

*/
#include <iostream>
#include <climits>

using namespace std;

// Brute Force Method

/*
int main()
{

    int n, subArr;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            // cout << endl;
            maxSum = max(maxSum, sum);
        }
    }

    cout << "Max is:" << maxSum << endl;

    return 0;
}
*/

// Optimised approach
/*
int main()
{

    int n;
    cin >> n;
    int arr[n], currSum[n + 1];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    currSum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        currSum[i] = currSum[i - 1] + arr[i - 1];
    }
    int maxSum = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum = currSum[i] - currSum[j];
            maxSum = max(sum, maxSum);
        }
    }
    cout << maxSum << endl;

    return 0;
}
*/

// Kadane's Algo -

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int currSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum < 0)
        {
            currSum = 0;
        }
        maxSum = max(maxSum, currSum);
    }
    cout << maxSum << endl;

    return 0;
}