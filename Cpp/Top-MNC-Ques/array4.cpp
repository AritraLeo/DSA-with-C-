/*
Printing Sub Array - say: 1234
then display -
1
1 2
1 2 3
1 2 3 4
2
2 3
2 3 4
3
3 4
4

*/

#include <iostream>
#include <climits>

using namespace std;

int main()
{

    int n, subArr;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}