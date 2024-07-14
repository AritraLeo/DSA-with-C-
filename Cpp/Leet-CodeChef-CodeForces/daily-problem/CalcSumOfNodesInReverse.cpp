#include <iostream>
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

/*
Previous attempt -

// private:
//     ListNode* calcSumOfNodesInReverse(ListNode* l1, ListNode* l2, ListNode* h3, int c){

//         if(l1->next == nullptr && l2->next == nullptr){
//             return nullptr;
//         }

//         h3->next = calcSumOfNodesInReverse(
//             l1->next == nullptr ? nullptr : l1,
//             l2->next == nullptr ? nullptr : l2,
//             h3->next,
//             c
//         );

//         int s = 0;
//         while(l1->next != nullptr || l2->next != nullptr){
//             int v1 = l1 != nullptr ? l1->val : 0;
//             int v2 = l2 != nullptr ? l2->val : 0;
//             s = v1 + v2;
//             if(s > 10){
//                 s = s % 10;
//             }
//             c = 1;
//         }
//         h3->val = s;

//         return h3;
//     }

*/

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // start add in reverse order
        // recursive -> add vals of head1 and 2 and have carry
        // calc new carry if any
        // form a new LL as we add
        return calcSumOfNodesInReverse(l1, l2, 0);
    }

private:
    ListNode *calcSumOfNodesInReverse(ListNode *l1, ListNode *l2, int carry)
    {
        // Base case: if both lists are empty and no carry left
        if (!l1 && !l2 && carry == 0)
            return nullptr;

        // Calculate the sum for the current node
        int sum = carry;
        if (l1)
            sum += l1->val;
        if (l2)
            sum += l2->val;

        // Calculate the new carry
        carry = sum / 10;
        sum = sum % 10;

        // Create the new node with the calculated sum
        ListNode *newNode = new ListNode(sum);

        // Recursively calculate the next node
        newNode->next = calcSumOfNodesInReverse(
            l1 ? l1->next : nullptr,
            l2 ? l2->next : nullptr,
            carry);

        return newNode;
    }
};

// Function to create a list from a vector
ListNode *createList(const std::vector<int> &nums)
{
    ListNode *head = new ListNode(nums[0]);
    ListNode *current = head;
    for (size_t i = 1; i < nums.size(); ++i)
    {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

// Function to print a list
void printList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    Solution sol;

    // Create two linked lists
    ListNode *l1 = createList({2, 4, 3});
    ListNode *l2 = createList({5, 6, 4});

    // Add the two lists
    ListNode *result = sol.addTwoNumbers(l1, l2);

    // Print the result
    printList(result);

    return 0;
}
