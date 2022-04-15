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
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b)
    {
        if (!a)
            return b;
        if (!b)
            return a;
        ListNode* result;
        if (a->val <= b->val)
        {
            result = a;
            result->next = merge(a->next, b);
        }
        else
        {
            result = b;
            result->next = merge(a, b->next);
        }
        return result;

    }
    ListNode* getMiddle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL or head->next == NULL)
            return head;
        ListNode* mid = getMiddle(head);
        ListNode* newHead = mid->next;
        mid->next = NULL;
        return merge(sortList(head), sortList(newHead));

    }
};