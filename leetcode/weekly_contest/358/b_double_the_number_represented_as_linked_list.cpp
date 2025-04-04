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
    ListNode* doubleIt(ListNode* head) {
        ListNode* cur = head;
        long long int num = 0;
        while (cur) {
            num = num * 10 + (cur->val);
            cur = cur->next;
        }
        num = num * 2;
        if (num == 0)
            return head;
        cur = head;
        while (num) {
            if (cur->next == NULL) {
                cur->next = new ListNode();
            }
            cur->val = num % 10;
            cout << cur->val << ":";
            num /= 10;
            cur = cur-> next;
        }

        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
        head = head->next;
        return head;
    }
};