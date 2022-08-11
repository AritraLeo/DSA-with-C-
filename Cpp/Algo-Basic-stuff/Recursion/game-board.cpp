#include <iostream>

using namespace std;

int countPath(int start, int end)
{

    if (start == end)
    {
        return 1;
    }

    if (start > end)
    {
        return 0;
    }

    int count = 0;
    // Dice has 6 faces of max 6 points:
    for (int i = 1; i <= 6; i++)
    {
        count += countPath(start + i, end);
    }

    return count;
}

int main()
{
    cout << countPath(0, 3) << endl;
    return 0;
}