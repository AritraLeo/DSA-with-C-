#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        // Create a dummy node to handle cases where the entire list sums to zero
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Use a hashmap to store prefix sums and their corresponding nodes
        std::unordered_map<int, ListNode*> prefixSumMap;
        int prefixSum = 0;
        
        // Initialize the prefix sum map with dummy node
        prefixSumMap[0] = dummy;
        
        // Traverse the list to calculate prefix sums
        while (head != nullptr) {
            prefixSum += head->val;
            
            // If the current prefix sum exists in the map, it means there's a sublist that sums to zero
            // Remove this sublist by updating the next pointer of the previous node to skip over the sublist
            if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
                ListNode* prev = prefixSumMap[prefixSum];
                ListNode* removeStart = prev->next;
                int sumToRemove = prefixSum + removeStart->val;
                
                // Remove nodes from the map
                while (removeStart != head) {
                    sumToRemove += removeStart->val;
                    prefixSumMap.erase(sumToRemove);
                    removeStart = removeStart->next;
                }
                
                // Update next pointer of previous node to skip over the sublist
                prev->next = head->next;
            } else {
                // Store the current prefix sum and corresponding node in the map
                prefixSumMap[prefixSum] = head;
            }
            
            head = head->next;
        }
        
        return dummy->next;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Test case
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(-3);
    head->next->next->next->next = new ListNode(4);

    // Create a Solution object
    Solution sol;

    // Call the removeZeroSumSublists function and print the resulting linked list
    ListNode* result = sol.removeZeroSumSublists(head);
    cout << "Output: ";
    printList(result);

    return 0;
}
