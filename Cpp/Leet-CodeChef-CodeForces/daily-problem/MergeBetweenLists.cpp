
#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/*
Initial approach

Output -
10 1 13 6 9 5
1 13 6 9 5
13 1000002
Merged List: 10 1 13 1000002

class Solution
{

public:
    void displayList(ListNode *head)
    {
        ListNode *current = head;
        while (current != nullptr)
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }

public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        // iterate and store last node of list2 => list2Last
        // iterate over list1 c=0 -> at c==a -> prev->next = list2 continue ->
        //  c==b+1 (if exists) -> list2Last->next = list1
        ListNode *list2LastNode = list2;
        ListNode *prevNode;
        ListNode* res = list1;
        while (list2LastNode->next != nullptr)
        {
            list2LastNode = list2LastNode->next;
        }

        int c = 0;
        while (list1->next != nullptr)
        {
            c++;
            prevNode = list1;
            if (c == a-1)
            {
                prevNode->next = list2;
            }
            if (list1->next != nullptr && c == b-1)
            {
                list2LastNode->next = prevNode;
            }
            list1 = list1->next;
        }
        return res;
    }
};

*/

class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        // Create a pointer to keep track of the head of the merged list
        ListNode *res = list1;

        // Find the last node of list2
        ListNode *list2LastNode = list2;
        while (list2LastNode->next != nullptr)
        {
            list2LastNode = list2LastNode->next;
        }

        // Find the node before the a-th node
        ListNode *prevNode = nullptr;
        for (int i = 0; i < a; ++i)
        {
            prevNode = list1;
            list1 = list1->next;
        }

        // Connect the node before the a-th node to the head of list2
        prevNode->next = list2;

        // Find the node after the b-th node
        for (int i = a; i <= b; ++i)
        {
            list1 = list1->next;
        }

        // Connect the last node of list2 to the node after the b-th node
        list2LastNode->next = list1;

        // Return the head of the merged list
        return res;
    }
};

void displayList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

// Test your solution
int main()
{
    // Example list1
    ListNode *list1 = new ListNode(10);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(13);
    list1->next->next->next = new ListNode(6);
    list1->next->next->next->next = new ListNode(9);
    list1->next->next->next->next->next = new ListNode(5);

    // Example list2
    ListNode *list2 = new ListNode(1000000);
    list2->next = new ListNode(1000001);
    list2->next->next = new ListNode(1000002);

    int a = 3; // Example value of a
    int b = 4; // Example value of b

    Solution sol;
    ListNode *result = sol.mergeInBetween(list1, a, b, list2);

    // Display the result
    cout << "Merged List: ";
    displayList(result);

    // Verify if the result matches the expected output

    return 0;
}
