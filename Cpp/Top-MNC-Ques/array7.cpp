#include <iostream>

using namespace std;

/* Brute Force approach - O(n^2)  */
/*
bool pairSum(int arr[], int n, int k)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                cout << i << " " << j << endl;
                return true;
            }
        }
    }

    return false;
}

int main()
{

    int arr[] = {11, 32, 31, 41, 23, 34, 56, 45};
    int k = 43;
    int n = 8;

    int pairSumCheck = pairSum(arr, n, k);
    cout << pairSumCheck << endl;

    return 0;
}

*/

/* Optimised Approach  */

bool pairSum(int arr[], int n, int k)
{
    int low = 0;
    int high = n - 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = arr[low] + arr[high];
        if (sum == k)
        {
            cout << low + 1 << " " << high + 1 << endl;
            return true;
        }
        else if (sum < k)
        {
            low++;
        }
        else
            high--;
    }

    return false;
}

int main()
{
    int arr[] = {1, 32, 44, 46, 78, 90};
    int n = 6;
    int k = 33;

    int pairSumCheck = pairSum(arr, n, k);
    cout << pairSumCheck << endl;

    return 0;
}
