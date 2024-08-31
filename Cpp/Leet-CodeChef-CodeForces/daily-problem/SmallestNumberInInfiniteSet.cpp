#include <iostream>
#include <queue>
#include <set>

using namespace std;

/*
To implement the SmallestInfiniteSet class efficiently, we can use two main data structures:

A Min-Heap (Priority Queue): This will store the numbers that have been removed and added back to the set. The heap property ensures that the smallest element can be accessed and removed in logarithmic time.

A Set: This will keep track of the numbers that are currently available in the heap. This ensures that duplicates are not added to the heap.

Strategy:
Initialization: Start with a variable current_min initialized to 1, representing the smallest number that hasn't been removed from the infinite set.

popSmallest():

If the heap is non-empty, pop the smallest element from the heap.
If the heap is empty, return current_min and then increment current_min to reflect that the next smallest element is now available.
addBack(num):

If num is smaller than current_min and is not already in the heap, add it to the heap and record it in the set to prevent duplicates.

*/

class SmallestInfiniteSet
{
private:
    int current_min;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    set<int> added_back;

public:
    SmallestInfiniteSet() : current_min(1) {}

    int popSmallest()
    {
        if (!min_heap.empty())
        {
            int smallest = min_heap.top();
            min_heap.pop();
            added_back.erase(smallest);
            return smallest;
        }
        else
        {
            return current_min++;
        }
    }

    void addBack(int num)
    {
        if (num < current_min && added_back.find(num) == added_back.end())
        {
            min_heap.push(num);
            added_back.insert(num);
        }
    }
};

int main()
{
    SmallestInfiniteSet smallestInfiniteSet;
    smallestInfiniteSet.addBack(2);                    // No change, as 2 is still in the infinite set.
    cout << smallestInfiniteSet.popSmallest() << endl; // return 1
    cout << smallestInfiniteSet.popSmallest() << endl; // return 2
    cout << smallestInfiniteSet.popSmallest() << endl; // return 3
    smallestInfiniteSet.addBack(1);                    // 1 is added back to the set.
    cout << smallestInfiniteSet.popSmallest() << endl; // return 1
    cout << smallestInfiniteSet.popSmallest() << endl; // return 4
    cout << smallestInfiniteSet.popSmallest() << endl; // return 5

    return 0;
}
