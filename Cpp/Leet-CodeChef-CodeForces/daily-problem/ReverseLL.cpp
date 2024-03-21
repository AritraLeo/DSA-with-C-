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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode* reverseHead = nullptr;
    ListNode* temp;
    while (head != nullptr) {
        temp = new ListNode(head->val);
        temp->next = reverseHead;
        reverseHead = temp;
        head = head->next;
    }
    return reverseHead;
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
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);


    Solution sol;
    ListNode *result = sol.reverseList(list1);

    // Display the result
    cout << "Reversed List: ";
    displayList(result);

    // Verify if the result matches the expected output

    return 0;
}
