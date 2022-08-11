#include <iostream>

using namespace std;

int getBit(int n, int pos)
{
    return (n & (1 << pos)) != 0;
}

int setBit(int n, int pos)
{
    return (n | (1 << pos));
}

int clearBit(int n, int pos)
{
    return (n & ~(1 << pos));
}

int updateBit(int n, int pos, int val)
{
    // Clear Bit then Set bit with value:
    int mask = ~(1 << pos);
    n = n & mask;
    return (n | (val << pos));
}

int main()
{
    cout << "Get Bit:" << getBit(5, 2) << endl;
    cout << "Set Bit:" << setBit(5, 1) << endl;
    cout << "Clear Bit:" << clearBit(5, 2) << endl;
    cout << "Update Bit:" << updateBit(5, 1, 1) << endl;
    return 0;
}