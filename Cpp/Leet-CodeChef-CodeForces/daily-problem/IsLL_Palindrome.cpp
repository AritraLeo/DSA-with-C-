/*

Initial appraoch -

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

    bool isPalindrome(ListNode *head)
    {
        ListNode* reversedNode = reverseList(head);
        while (head->next != nullptr)
        {
            if(head->val != reversedNode->val) return false;

            head = head->next;
            reversedNode = reversedNode->next;
        }
        return true;
    }


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
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *current = slow->next;
        ListNode *prev = nullptr;

        while (current != nullptr)
        {
            ListNode *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        while (prev != nullptr)
        {
            if (prev->val != head->val)
                return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
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

int main()
{
    // Example list1
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(2);
    list1->next->next->next->next = new ListNode(1);

    Solution sol;
    bool result = sol.isPalindrome(list1);

    // Display the result
    cout << "Is Palindrome: " << (result ? "true" : "false") << endl;

    // Display the original list
    cout << "Original List: ";
    displayList(list1);

    return 0;
}
