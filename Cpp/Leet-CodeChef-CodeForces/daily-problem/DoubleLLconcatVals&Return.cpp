#include <iostream>

using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Function to double the number represented by the linked list
    ListNode* doubleIt(ListNode* head) {
        // Reverse the linked list
        ListNode* reversedList = reverseList(head);

        // Initialize variables to track carry and previous node
        int carry = 0;
        ListNode* current = reversedList, *previous = nullptr;

        // Traverse the reversed linked list
        while (current != nullptr) {
            // Calculate the new value for the current node
            int newValue = current->val * 2 + carry;
            // Update the current node's value
            current->val = newValue % 10;
            // Update carry for the next iteration
            carry = newValue / 10;
            // Move to the next node
            previous = current;
            current = current->next;
        }

        // If there's a carry after the loop, add an extra node
        if (carry != 0) {
            ListNode* extraNode = new ListNode(carry);
            previous->next = extraNode;
        }

        // Reverse the list again to get the original order
        ListNode* result = reverseList(reversedList);

        return result;
    }

    // Method to reverse the linked list
    ListNode* reverseList(ListNode* node) {
        ListNode* previous = nullptr, *current = node, *nextNode;

        // Traverse the original linked list
        while (current != nullptr) {
            // Store the next node
            nextNode = current->next;
            // Reverse the link
            current->next = previous;
            // Move to the next nodes
            previous = current;
            current = nextNode;
        }
        // Previous becomes the new head of the reversed list
        return previous;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Create a sample linked list: 1 -> 8 -> 9
    ListNode* head = new ListNode(1);
    head->next = new ListNode(8);
    head->next->next = new ListNode(9);

    Solution sol;

    cout << "Original List: ";
    printList(head);

    // Double the number represented by the linked list
    ListNode* modifiedHead = sol.doubleIt(head);

    cout << "Modified List: ";
    printList(modifiedHead);

    return 0;
}
