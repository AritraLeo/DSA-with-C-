#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

void deleteNode(ListNode* node) {
    if (node == nullptr || node->next == nullptr) {
        cout << "Cannot delete last node or nullptr\n";
        return;
    }
    
    // Copy the data of the next node to the given node
    ListNode* nextNode = node->next;
    node->val = nextNode->val;
    
    // Delete the next node
    node->next = nextNode->next;
    delete nextNode;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    // Delete node 3 (value = 3)
    deleteNode(head->next->next);

    cout << "List after deleting node 3: ";
    printList(head);

    // Delete last node
    deleteNode(head->next->next->next->next);
    cout << "List after deleting last node: ";
    printList(head);

    // Try to delete nullptr
    ListNode* nullNode = nullptr;
    deleteNode(nullNode); // Should print "Cannot delete last node or nullptr"

    return 0;
}
