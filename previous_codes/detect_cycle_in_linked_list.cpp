/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;

    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> s;
        while (head != NULL)
        {
            if (s.find(head->next) != s.end())
                return true;
            /* both will be true
            if (s.find(head) != s.end())
                return true;*/
            s.insert(head);
            head = head->next;
        }
        return false;

    }
};