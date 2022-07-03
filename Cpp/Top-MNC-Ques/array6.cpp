/*
Sub Array Sum of Circular Array

*/
#include <iostream>
#include <climits>

using namespace std;

int kadane(int arr[], int n)
{
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
    return maxSum;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int wrapSum, nonWrapSum;
    int totalSum = 0;
    nonWrapSum = kadane(arr, n);
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
        arr[i] = -arr[i];
    }

    // wrapSum = total - (-nonWrapSum)
    wrapSum = totalSum + nonWrapSum;

    cout << max(wrapSum, nonWrapSum) << endl;

    return 0;
}