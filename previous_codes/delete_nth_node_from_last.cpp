class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total = 0;
        ListNode* current = head;
        while (current != NULL)
        {
            current = current->next;
            total++;
        }
        int find = total - n;
        if (find == 0)
        {
            current == NULL;
            return current;
        }
        int count = 0;
        current = head;
        while (count < find - 1)
        {
            current = current->next;
            count++;
        }
        current->next = current->next->next;
        return head;
    }
};

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;
        for (int i = 1; i <= n; i++)
        {
            if (second->next == NULL)
            {
                if (i == n)
                {
                    head = head->next;
                }
                return head;
            }

            second = second->next;
        }
        while (second->next != NULL)
        {
            first = first->next;
            second = second->next;
        }
        first->next = first->next->next;
        return head;
    }
};

ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* first = A;
    ListNode* second = A;
    for (int i = 1; i <= B; i++)
    {
        if (second->next == NULL)
        {
            if (B >= i)
            {
                A = A->next;
            }
            return A;
        }
        second = second->next;
    }
    while (second->next != NULL)
    {
        first = first->next;
        second = second->next;
    }
    first->next = first->next->next;
    return A;
}
