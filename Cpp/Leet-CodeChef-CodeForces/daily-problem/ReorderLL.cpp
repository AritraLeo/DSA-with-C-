/*
optimized code - 

void reorderList(ListNode *head)
{
    if (!head || !head->next)
        return;

    // Find the middle of the list
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    ListNode *prev = nullptr;
    ListNode *curr = slow->next;
    while (curr)
    {
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    slow->next = nullptr; // Terminate the first half of the list

    // Merge the first and reversed second halves
    ListNode *first = head;
    ListNode *second = prev;
    while (second)
    {
        ListNode *nextFirst = first->next;
        ListNode *nextSecond = second->next;
        first->next = second;
        second->next = nextFirst;
        first = nextFirst;
        second = nextSecond;
    }
}

*/

// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
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

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *reverseHead = nullptr;
        ListNode *temp;
        while (head != nullptr)
        {
            temp = new ListNode(head->val);
            temp->next = reverseHead;
            reverseHead = temp;
            head = head->next;
        }
        return reverseHead;
    }

    void reorderList(ListNode *head)
    {
        // reverseList return head that contains this sequence
        ListNode *newNode;
        ListNode *reverseHead = reverseList(head);
        while (reverseHead->val != head->val)
        {
            ListNode *temp = new ListNode(head->val);
            newNode = temp;
            ListNode *temp1 = new ListNode(reverseHead->val);
            newNode->next = temp1;
            cout << "Head: " << head->val << " Reverse Head: " << reverseHead->val << endl;
            cout << "New Node: " << newNode->val << " Next: " << newNode->next->val << endl;
            displayList(newNode);
            newNode = newNode->next;
            head = head->next;
            reverseHead = reverseHead->next;
        }
        displayList(reverseList(newNode));
    }
};

int main()
{
    // Example list1
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);

    // Display the current list
    cout << "Original List: ";
    displayList(list1);

    Solution sol;
    sol.reorderList(list1);

    // Display the re-ordered list
    cout << "Original List: ";
    displayList(list1);

    return 0;
}
