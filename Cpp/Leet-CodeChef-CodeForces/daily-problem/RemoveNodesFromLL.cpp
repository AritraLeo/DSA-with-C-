#include <iostream>
#include <climits>
#include <vector>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        int maxVal = INT_MIN;
        return recursiveNodeDeleter(head, maxVal);
    }

private:
    ListNode *recursiveNodeDeleter(ListNode *head, int &maxVal)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        head->next = recursiveNodeDeleter(head->next, maxVal);

        if (head->next == nullptr)
        {
            // We are at the last node, set the maxVal to this node's value
            maxVal = head->val;
        }
        else if (head->val < maxVal)
        {
            // Current node's value is less than the maxVal seen so far, delete this node
            ListNode *temp = head->next;
            delete head;
            return temp;
        }
        else
        {
            // Update maxVal
            maxVal = head->val;
        }

        return head;
    }
};

// Helper function to create a linked list from a vector
ListNode *createList(const std::vector<int> &vals)
{
    if (vals.empty())
        return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *current = head;
    for (size_t i = 1; i < vals.size(); ++i)
    {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Main function to test the implementation
int main()
{
    Solution solution;

    // Test case 1: 1 -> 2 -> 3 -> 4 -> 2
    std::vector<int> vals1 = {1, 2, 3, 4, 2};
    ListNode *head1 = createList(vals1);
    std::cout << "Original list: ";
    printList(head1);
    head1 = solution.removeNodes(head1);
    std::cout << "Modified list: ";
    printList(head1);

    // Test case 2: 5 -> 4 -> 3 -> 2 -> 1
    std::vector<int> vals2 = {5, 4, 3, 2, 1};
    ListNode *head2 = createList(vals2);
    std::cout << "Original list: ";
    printList(head2);
    head2 = solution.removeNodes(head2);
    std::cout << "Modified list: ";
    printList(head2);

    // Test case 3: 1 -> 1 -> 1 -> 1
    std::vector<int> vals3 = {1, 1, 1, 1};
    ListNode *head3 = createList(vals3);
    std::cout << "Original list: ";
    printList(head3);
    head3 = solution.removeNodes(head3);
    std::cout << "Modified list: ";
    printList(head3);

    // Test case 4: 2 -> 2 -> 3 -> 2 -> 2
    std::vector<int> vals4 = {2, 2, 3, 2, 2};
    ListNode *head4 = createList(vals4);
    std::cout << "Original list: ";
    printList(head4);
    head4 = solution.removeNodes(head4);
    std::cout << "Modified list: ";
    printList(head4);

    // Cleanup memory
    ListNode *temp;
    while (head1 != nullptr)
    {
        temp = head1;
        head1 = head1->next;
        delete temp;
    }
    while (head2 != nullptr)
    {
        temp = head2;
        head2 = head2->next;
        delete temp;
    }
    while (head3 != nullptr)
    {
        temp = head3;
        head3 = head3->next;
        delete temp;
    }
    while (head4 != nullptr)
    {
        temp = head4;
        head4 = head4->next;
        delete temp;
    }

    return 0;
}
