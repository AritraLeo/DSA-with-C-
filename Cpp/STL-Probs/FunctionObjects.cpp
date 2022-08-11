#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
    // Function Objects: Function wrapped in a class so that its available like an object -
    int arr[] = {1, 23, 45, 6};
    /*  Sorts array from element to the specified element   */
    // sort(arr, arr + 3);
    /*  With functional Objects - functors   */
    sort(arr, arr + 4, greater<int>());
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}