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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* slow = head;
        ListNode* fast = head;
        for (int count = 1; count <= k - 1; count++)
        {
            curr = curr->next;
            slow = slow->next;
        }
        while (slow->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        int temp = curr->val;
        curr->val = fast->val;
        fast->val = temp;


        return head;
    }
};