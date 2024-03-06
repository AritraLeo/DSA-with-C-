#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast != nullptr && fast->next != nullptr) {
            if (slow == fast)
                return true; // Cycle detected
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return false; // No cycle detected
    }
};

int main() {
    // Test case: Create a linked list with a cycle
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Create a cycle

    // Create a Solution object
    Solution sol;

    // Check if the linked list has a cycle
    bool result = sol.hasCycle(head);

    // Print the result
    if (result)
        cout << "The linked list has a cycle." << endl;
    else
        cout << "The linked list does not have a cycle." << endl;

    return 0;
}
