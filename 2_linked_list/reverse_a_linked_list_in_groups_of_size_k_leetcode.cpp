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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head)
            return NULL;
        int count = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (curr != NULL and count < k)
        {
            count++;
            curr = curr->next;
        }
        if (count < k)
            return head;
        curr = head;
        count = 0;
        while (curr != NULL and count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next)
            head->next = reverseKGroup(next, k);
        return prev;

    }
};