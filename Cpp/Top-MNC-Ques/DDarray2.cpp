/*
To find a given element in a matrix
with sorted elements both in rows and columns
with optimised method of searching while checking

*/

#include <iostream>

using namespace std;

int main()
{

    int n, m, k;
    cin >> n >> m;
    int arr[n][m];
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    cout << "Array before" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    int r = 0, c = m - 1;
    bool f = false;
    while (r < n and c >= 0)
    {
        if (arr[r][c] == k)
        {
            f = true;
            cout << r << c << endl;
            break;
        }
        else if (arr[r][c] > k)
        {
            c--;
        }
        else
        {
            r++;
        }
    }

    return 0;
}
