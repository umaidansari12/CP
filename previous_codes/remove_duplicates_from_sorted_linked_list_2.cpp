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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL && head->next == NULL)
            return head;
        ListNode* current = head;
        ListNode* prev = head;
        ListNode* curr = current;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        while (current->next != NULL)
        {
            if (current->val == current->next->val)
            {
                int curr_val = current->val;
                while (current->next != NULL && current->val == curr_val)
                {
                    curr = current;
                    current = current->next;
                    delete(curr);
                }
                prev->next = current;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
        return dummy->next;
    }

};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* newhead = new ListNode(0);
    newhead->next = head;
    ListNode* prev = newhead;
    while (prev->next != NULL && prev->next->next != NULL)
    {
        if (prev->next->val == prev->next->next->val)
        {
            int dup = prev->next->val;
            while (prev->next != NULL && prev->next->val == dup)
                prev->next = prev->next->next;
        }
        else
        {
            prev = prev->next;
        }
    }
    return newhead->next;

}