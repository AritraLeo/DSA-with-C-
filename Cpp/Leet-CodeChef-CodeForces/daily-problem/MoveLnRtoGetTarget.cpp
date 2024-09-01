#include <iostream>
#include <string>

using namespace std;

bool canTransform(string start, string target)
{
    int n = start.length();

    // Two pointers to iterate over start and target
    int i = 0, j = 0;

    while (i < n && j < n)
    {
        // Move i to the next 'L' or 'R'
        while (i < n && start[i] == '_')
            i++;
        // Move j to the next 'L' or 'R'
        while (j < n && target[j] == '_')
            j++;

        // Check if both pointers have reached the end
        if (i == n && j == n)
            return true;
        if (i == n || j == n)
            return false;

        // If the characters at i and j are different
        if (start[i] != target[j])
            return false;

        // If we found 'L', it should only move left, so i should be >= j
        if (start[i] == 'L' && i < j)
            return false;
        // If we found 'R', it should only move right, so i should be <= j
        if (start[i] == 'R' && i > j)
            return false;

        i++;
        j++;
    }

    // After the main loop, check if there are only '_' left in both strings
    while (i < n && start[i] == '_')
        i++;
    while (j < n && target[j] == '_')
        j++;

    return i == n && j == n;
}

int main()
{
    string start = "_L__R__R_";
    string target = "L______RR";

    bool result = canTransform(start, target);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
