/*
Optimized approach -

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};



*/

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

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;

        if (head == nullptr || head->next == nullptr)
            return head;

        int counter = 1;
        while (head->next != nullptr)
        {
            counter++;
            head = head->next;
        }

        if (counter % 2 == 0)
        {
            counter = counter / 2;
        }
        else
        {
            counter = counter / 2;
        }
        while (counter != 0)
        {
            temp = temp->next;
            counter--;
        }

        return temp;
    }
};

// Function to print the linked list
void printLinkedList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main()
{
    // Create a sample linked list
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Create a Solution object
    Solution sol;

    // Find the middle node of the linked list
    ListNode *middle = sol.middleNode(head);

    // Print the result
    cout << "Middle Node: ";
    printLinkedList(middle);

    return 0;
}
