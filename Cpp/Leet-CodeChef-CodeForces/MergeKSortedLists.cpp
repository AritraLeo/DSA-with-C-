/*
Brute Force approach - 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        vector<int> res;
        
        // Iterate through each list and extract elements
        for (int i = 0; i < n; ++i) {
            ListNode* current = lists[i];
            while (current != nullptr) {
                res.push_back(current->val);
                current = current->next;
            }
        }
        
        // Sort the extracted elements
        sort(res.begin(), res.end());
        
        // Convert the sorted array to a linked list
        return sortedArrayToLinkedList(res);
    }
    
private:
    ListNode* sortedArrayToLinkedList(vector<int>& res) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        for (int num : res) {
            ListNode* newNode = new ListNode(num);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        return head;
    }
};

// Utility function to print the linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Test case: lists = [[]]
    vector<ListNode*> lists = {nullptr};
    
    // Create a Solution object
    Solution sol;

    // Merge the lists and convert to a linked list
    ListNode* mergedList = sol.mergeKLists(lists);

    // Print the merged linked list
    cout << "Merged Linked List: ";
    printLinkedList(mergedList);

    return 0;
}

Approach - 
The mergeKLists function iterates through each list, extracts elements, sorts them, and converts them to a linked list using the sortedArrayToLinkedList function.
The sortedArrayToLinkedList function converts a sorted vector to a linked list, handling the case of an empty list appropriately by returning nullptr.
In the main function, we test the case where lists contains a single empty list, and we print the merged linked list


*/


/*
Better Approach - 
To improve the time complexity of the solution, we can use a priority queue (min-heap) to efficiently find the minimum element among the heads of all the linked lists. Here's how we can do it:

Initialize a priority queue to store pairs of ListNode pointers and their corresponding values. The priority queue will be sorted based on the values.
Push the head of each linked list into the priority queue.
While the priority queue is not empty:
Pop the ListNode pointer with the smallest value from the priority queue.
Append the value of the popped node to the result list.
If the popped node has a next node, push the next node into the priority queue.
Return the result list.

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Comparison function for the priority queue
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min-heap based on the values
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        // Push the head of each linked list into the priority queue
        for (ListNode* head : lists) {
            if (head)
                pq.push(head);
        }
        
        ListNode dummy(0); // Dummy node to simplify the merging process
        ListNode* tail = &dummy;
        
        // Merge lists using the priority queue
        while (!pq.empty()) {
            ListNode* minNode = pq.top();
            pq.pop();
            
            tail->next = minNode;
            tail = tail->next;
            
            if (minNode->next)
                pq.push(minNode->next);
        }
        
        return dummy.next;
    }
};

// Utility function to print the linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Test case
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};

    // Create a Solution object
    Solution sol;

    // Merge the lists and convert to a linked list
    ListNode* mergedList = sol.mergeKLists(lists);

    // Print the merged linked list
    cout << "Merged Linked List: ";
    printLinkedList(mergedList);

    return 0;
}
