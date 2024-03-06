/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <bits/stdc++.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Compare
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val; // Min-heap based on the values
    }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, Compare> pq;

        // Push the head of each linked list into the priority queue
        for (ListNode *head : lists)
        {
            if (head)
                pq.push(head);
        }

        ListNode dummy(0); // Dummy node to simplify the merging process
        ListNode *tail = &dummy;

        // Merge lists using the priority queue
        while (!pq.empty())
        {
            ListNode *minNode = pq.top();
            pq.pop();

            tail->next = minNode;
            tail = tail->next;

            if (minNode->next)
                pq.push(minNode->next);
        }

        return dummy.next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *temp = nullptr;

        while (fast != nullptr && fast->next != nullptr)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = nullptr;

        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);

        vector<int> lls;
        lls.push_back(l1);
        lls.push_back(l2);
        mergeKLists(lls);
    }
};